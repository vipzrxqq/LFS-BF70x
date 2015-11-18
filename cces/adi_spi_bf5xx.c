/* $Id: adi_spi_bf5xx.c 20137 2014-11-24 19:03:45Z lgarber $ */
/*********************************************************************************

 Copyright(c) 2010 Analog Devices, Inc. All Rights Reserved.

 This software is proprietary and confidential.  By using this software you agree
 to the terms of the associated Analog Devices License Agreement.

 *********************************************************************************/
/*!
 * @file      adi_spi_bf5xx.c
 *
 * @brief     SPI driver global API implementation
 *
 * @details
 *            This is a source file which contains the implementation of global
 *            API functions of the SPI device.
 */

/** @addtogroup SPI_Driver SPI Device Driver
 *  @{
 */


/* disable misra diagnostics as necessary */
#ifdef _MISRA_RULES
#pragma diag(push)
#pragma diag(suppress:misra_rule_5_1:"Identifiers shall not rely on the significance of more than 31 characters")
#pragma diag(suppress:misra_rule_8_5:"There shall be no definitions of objects or functions in a header file.")
#pragma diag(suppress:misra_rule_8_7: "Objects shall be defined at block scope if they are only accessed from within a single function.")
#pragma diag(suppress:misra_rule_13_7:"Allow to add asserts for memory size macros")
#pragma diag(suppress:misra_rule_14_7:"A function shall have a single point of exit at the end of the function.")
#pragma diag(suppress:misra_rule_17_4:"Array indexing shall be the only allowed form of pointer arithmetic.")
#endif /* _MISRA_RULES */

#include "adi_spi_data_bf5xx.c"
#include <assert.h>

#define ENUM_SPI_HW_ERROR  		(ADI_SPI_HW_ERR_MODE | ADI_SPI_HW_ERR_TX_UNDERRUN | ADI_SPI_HW_ERR_RX_OVERRUN | ADI_SPI_HW_ERR_TX_COLLISION)

/* Function declarations */
/* Submit transceiver buffer functions for interrupt and DMA driven */
static ADI_SPI_RESULT adi_spi_SubmitIntBuffer(ADI_SPI_HANDLE const hDevice, ADI_SPI_TRANSCEIVER *pTransceiver);
static ADI_SPI_RESULT adi_spi_SubmitDmaBuffer(ADI_SPI_HANDLE const hDevice, ADI_SPI_TRANSCEIVER *pTransceiver);
/* SPI close functions for interrupt and DMA driven */
static ADI_SPI_RESULT adi_spi_CloseInt(ADI_SPI_HANDLE const hDevice);
static ADI_SPI_RESULT adi_spi_CloseDma(ADI_SPI_HANDLE const hDevice);
static ADI_SPI_RESULT Update_SID_DMAChannelID(ADI_SPI * const pDevice);
static ADI_SPI_RESULT ValidateSpiHandle(ADI_SPI_HANDLE * const hDevice);
static ADI_SPI_RESULT ValidateTransceiver(ADI_SPI * const pDevice, ADI_SPI_TRANSCEIVER *pTransceiver);
static void SwitchTxTransceiver(ADI_SPI * const pDevice);
static void SwitchRxTransceiver(ADI_SPI * const pDevice);
static void CheckForTransferCompletion(ADI_SPI * const pDevice);
static void PostTransceiverCompleted(ADI_SPI * const pDevice, void *pBuf);
static void UpdateQueue(ADI_SPI * const pDevice, bool bFreePrimaryOrSecondary);
static void ResetTransfer(ADI_SPI * const pDevice);
static void LoadTxFifo(ADI_SPI * const pDevice);
static void LoadRxBuffer(ADI_SPI * const pDevice, uint16_t RxData);
static void DisableTransceiver(ADI_SPI * const pDevice);
/* status interrupt handler */
static void Spi_Error_Interrupt_Handler(uint32_t SID, void *pCBParam);
static void Spi_Data_Interrupt_Handler(uint32_t SID, void *pCBParam);
/* SPI DMA callback */
static void SpiDma_Callback(void *pCBParam, uint32_t Event, void *pArg);



/*!
 * @brief       The adi_spi_Open API opens a specified SPI device.
 *
 * @param[in]   DeviceNumber    The SPI device instance number to be opened.
 * @param[in]   pDeviceMemory   The pointer to the SPI memory passed by application.
 * @param[in]   MemorySize      The memory size passed by application.
 * @param[out]  phDevice        The pointer to a location where the handle to the opened device is written. 
 *
 * @return      Status
 *              - #ADI_SPI_SUCCESS                The device is successfully opened for the given instance.
 *              - #ADI_SPI_FAILURE                A generalised API failure.
 *              - #ADI_SPI_IN_USE                 The specified device has already been initialised.
 *              - #ADI_SPI_INSUFFICIENT_MEMORY   Not enough memory for DMA mode
 *              - #ADI_SPI_INVALID_DEVICE_NUM [D] The given device number is greater than the number of SPI devices.
 *              - #ADI_SPI_INVALID_HANDLE [D]     The pointer to the SPI device handle is NULL.
 *              - #ADI_SPI_SEMAPHORE_FAILED       The driver's semaphore failed.
 *              - #ADI_SPI_INTERRUPT_FAILED       The driver's interrupt failed.
 *
 * No other SPI APIs may be called until the device open function is called.
 *
 * Opens a specified SPI device and passed back to the application a handle.  It initialises the device's
 * default data parameters.  The device is opened, by default,  in interrupt mode.  The SPI however can be
 * configured to operate in DMA or a combination of DMA and interrupt mode. The Open API also specifies an
 * optional callback function and callback parameter.
 *
 * @sa          adi_spi_Close().
 */

ADI_SPI_RESULT adi_spi_Open(uint32_t const DeviceNumber,
                            void *const pDeviceMemory,
                            uint32_t MemorySize,
                            ADI_SPI_HANDLE *phDevice)
{
    /* assume a return code */
    ADI_SPI_RESULT Result = ADI_SPI_SUCCESS;
    /* SPI Device */
    ADI_SPI *pDevice;

    /* debug build only */
#if defined (ADI_DEBUG)
    /* check if device ID is invalid */
    if (DeviceNumber >= ADI_SPI_NUM_DEVICES) {
        /* Bad Device Number */
        return (ADI_SPI_INVALID_DEVICE_NUM);
    }

    /* Check if the given pointer to device handle is valid */
    if (phDevice == NULL) 
    {
        return ADI_SPI_INVALID_HANDLE;
    }
#endif

    /* get SPI device instance */
    pDevice = &aSpiDevice[DeviceNumber];

    /* check if device is not in use) */
    if (pDevice->pDevData != NULL)
    {
        return ADI_SPI_IN_USE;
    }
    else
    {
        /* initialise the memory for SPI parameters */
        pDevice->pDevData = (ADI_SPI_DEV_DATA *) pDeviceMemory;
    }
    
    /* Clear the given memory */
    memset(pDeviceMemory, 0, MemorySize);    

    /* assume only enough memory for interrupt mode */
    pDevice->pDevData->bDmaSupported = false;
    /* assume DMA not supported */
    pDevice->pDevData->pSpiDMAMemory = NULL;

    if(MemorySize < (uint32_t)ADI_SPI_INT_MEMORY_SIZE)
    {
    	return ADI_SPI_INSUFFICIENT_MEMORY;
    }

    if(MemorySize >= (uint32_t)ADI_SPI_DMA_MEMORY_SIZE)
    {
        pDevice->pDevData->bDmaSupported = false;
        pDevice->pDevData->pSpiDMAMemory = (uint8_t *)pDevice->pDevData + sizeof(ADI_SPI_DEV_DATA );
    }

    /* asserts to validate the memory size macros */
    assert(ADI_SPI_INT_MEMORY_SIZE == sizeof(ADI_SPI_DEV_DATA));
    assert(ADI_SPI_DMA_MEMORY_SIZE == (ADI_SPI_INT_MEMORY_SIZE + ADI_DMA_CHANNEL_REQ_MEMORY));

    /******************************************/
    /* save parameters for device instance    */
    /******************************************/

    /* by default there is no callbacks */
    pDevice->pDevData->pfCallback = NULL;
    pDevice->pDevData->pCBParam = NULL;

    /* interrupt mode */
    pDevice->pDevData->bDmaMode = false;
    /* reset accumulated status events to none */
    pDevice->pDevData->SpiStatusEvent = 0u;
    /* software slave select configuration by default*/
    pDevice->pDevData->SpiSWSlaveSelectEnable = true;
    pDevice->pDevData->SpiSlaveSelect = ADI_SPI_SSEL_DISABLE;
    /* default operation mode configuration */
    pDevice->pDevData->SpiTransferSize = 1u;
    /* set transceiver pointers to NULL */
    pDevice->pDevData->pActiveTransceiver = NULL;
    pDevice->pDevData->pPrimaryTransceiver = NULL;
    pDevice->pDevData->pActiveTransceiver = NULL;
    pDevice->pDevData->hSemHandle = NULL;
    pDevice->pDevData->bPrimaryProcessed = false;
    pDevice->pDevData->bSecondaryProcessed = false;

    /* operating mode of spi is set to default, none */
    pDevice->pDevData->SpiMode = ADI_SPI_MODE_NONE;
    /* initialise spi registers to their default values */
    pDevice->pRegs->SPI_REG_CONTROL = (uint16_t) ADI_SPI_REG_CONTROL_DEFAULT;
    pDevice->pRegs->SPI_REG_FLAG    = (uint16_t) ADI_SPI_REG_FLAG_DEFAULT;
    pDevice->pRegs->SPI_REG_BAUD    = (uint16_t) ADI_SPI_REG_BAUD_DEFAULT;

    /* by default set the transceiver submission function to an interrupt driven function */
    pDevice->pDevData->FuncTable.pfSpiSubmitBuffer = &adi_spi_SubmitIntBuffer;
    /* by default set the spi close function to an interrupt closure function */
    pDevice->pDevData->FuncTable.pfSpiClose = &adi_spi_CloseInt;
    /* create static semaphore */
    if (adi_osal_SemCreateStatic(&pDevice->pDevData->SpiSemMemory[0],
                                 ADI_OSAL_MAX_SEM_SIZE_CHAR,
                                 &pDevice->pDevData->hSemHandle,
                                 0u) != ADI_OSAL_SUCCESS)
    {
        return  ADI_SPI_SEMAPHORE_FAILED;
    }


    /* Register the SPI error status interrupt handler */
    if (adi_int_InstallHandler((uint32_t)pDevice->SPIStatusSID, Spi_Error_Interrupt_Handler, pDevice, true)   != ADI_INT_SUCCESS)
    {
        return ADI_SPI_INTERRUPT_FAILED;
    }
    /* Update the spi SID and DMA channel ID before installing the interrupt handler */
    if (Update_SID_DMAChannelID(pDevice) != ADI_SPI_SUCCESS)
    {
        return ADI_SPI_INTERRUPT_FAILED;
    }
    /* Register the SPI data status interrupt handler */
    if (adi_int_InstallHandler((uint32_t)pDevice->pDevData->SPIDataSID, Spi_Data_Interrupt_Handler, pDevice, true) != ADI_INT_SUCCESS)
    {
        return ADI_SPI_INTERRUPT_FAILED;
    }
    /* pass SPI Device handle to client */
    *phDevice = (ADI_SPI_HANDLE) pDevice;
    /* return */
    return Result;
}

/*!
 * @brief       The adi_spi_Close API closes a specified SPI device.
 *
 * @param[in]   hDevice     The handle of the SPI device.
 *
 * @return      Status
 *              - #ADI_SPI_SUCCESS              The device is successfully opened for the given instance.
 *              - #ADI_SPI_FAILURE              A generalised API failure.
 *              - #ADI_SPI_INVALID_HANDLE [D]   An invalid device handle.
 *              - #ADI_SPI_SEMAPHORE_FAILED       The driver's semaphore failed.
 *              - #ADI_SPI_INTERRUPT_FAILED       The driver's interrupt failed.
 *
 * Closes a specified SPI device by disabling interrupts unregistering interrupt handlers and , closing DMA
 * channels if they are open.
 *
 * @sa          adi_spi_Open().
 */

ADI_SPI_RESULT adi_spi_Close(ADI_SPI_HANDLE const hDevice)
{
    /* assume a return code */
    ADI_SPI_RESULT Result = ADI_SPI_SUCCESS;
    /* Pointer to device instance */
    ADI_SPI *pDevice;

    /* debug build only */
#if defined (ADI_DEBUG)

    /* validate the given handle */
    if(ValidateSpiHandle(hDevice) != ADI_SPI_SUCCESS)
    {
        return ADI_SPI_INVALID_HANDLE;
    }
#endif /* ADI_DEBUG */

    /* device handle */
    pDevice = (ADI_SPI *) hDevice;

    /* close the spi's the DMA or the data interrupt depending on the function pointer */
    Result = pDevice->pDevData->FuncTable.pfSpiClose(pDevice);
    if (Result != ADI_SPI_SUCCESS)
    {
        return Result;
    }
#if !defined (__ADSPBF537_FAMILY__)
    /* Disable spi status interrupt handler */
    if (adi_int_EnableInt((uint32_t)pDevice->SPIStatusSID, false) != ADI_INT_SUCCESS)
    {
        return ADI_SPI_CLOSE_FAILED;
    }
#endif
    /* Unregister the spi status interrupt handler */
    if (adi_int_UninstallHandler((uint32_t)pDevice->SPIStatusSID) != ADI_INT_SUCCESS)
    {
        return ADI_SPI_CLOSE_FAILED;
    }

    /* destroy semaphore only if it is there is one already created */
    if (pDevice->pDevData->hSemHandle != NULL)
    {
        /* destroy semaphore */
        if (adi_osal_SemDestroyStatic(pDevice->pDevData->hSemHandle) != ADI_OSAL_SUCCESS)
        {
            return ADI_SPI_CLOSE_FAILED;
        }
    }

    /* free device memory */
    pDevice->pDevData = NULL;

    /* return */
    return Result;
}

/*!
 * @brief  The adi_spi_EnableDmaMode API sets the SPI controller in DMA or interrupt driven mode.
 *
 * @param[in]    hDevice      Handle of the SPI adi_spi_EnableDmaModedevice.
 * @param[in]    bDMAEnable   Flag to manage the DMA or interrupt driven mode.
 *               - true       DMA driven mode.
 *               - false      Interrupt driven mode.
 *
 * @return      Status
 *              - #ADI_SPI_SUCCESS              The device is successfully opened for the given instance.
 *              - #ADI_SPI_FAILURE              A generalised API failure.
 *              - #ADI_SPI_INVALID_HANDLE [D]   An invalid device handle.
 *
 */

ADI_SPI_RESULT adi_spi_EnableDmaMode(ADI_SPI_HANDLE const hDevice, bool bDMAEnable)
{
    /* assume a return code */
    ADI_SPI_RESULT Result = ADI_SPI_SUCCESS;
    /* Pointer to device instance */
    ADI_SPI *pDevice;

    /* debug build only */
#if defined (ADI_DEBUG)

    /* validate the given handle */
    if (ValidateSpiHandle(hDevice) != ADI_SPI_SUCCESS)
    {
        return ADI_SPI_INVALID_HANDLE;
    }
#endif /* ADI_DEBUG */

    pDevice = (ADI_SPI *) hDevice;

    if(bDMAEnable == true)
    {
        /* Return DMA not supported */
        Result = ADI_SPI_FAILURE;       
    }            

    return Result;

}

/*!
 * @brief   The adi_spi_SetDmaTransferSize API sets the size of SPI DMA data transfer.
 *
 * @param[in]    hDevice        Handle of the SPI device
 * @param[in]    eDMASize  		Enumeration for the size of the DMA data transfer.
 *                - #ADI_SPI_DMA_TRANSFER_8BIT  8 bit data transfer.
 *                - #ADI_SPI_DMA_TRANSFER_16BIT 16 bit data transfer.
 *                - #ADI_SPI_DMA_TRANSFER_32BIT 16 bit data transfer. 
 *
 * @return      Status
 *              - #ADI_SPI_SUCCESS              The device is successfully opened for the given instance.
 *              - #ADI_SPI_FAILURE              A generalised API failure.
 *              - #ADI_SPI_INVALID_HANDLE [D]   An invalid device handle.
 *              - #ADI_SPI_BAD_PARAMETER        Parameter is out of range.
 *
 * Sets the size of data that is transferred via DMA.
 */

ADI_SPI_RESULT adi_spi_SetDmaTransferSize(ADI_SPI_HANDLE const hDevice, ADI_SPI_DMA_TRANSFER_SIZE eDMASize)
{

    /* assume a return code */
    ADI_SPI_RESULT Result = ADI_SPI_SUCCESS;
    /* Pointer to device instance */
    ADI_SPI *pDevice;
    ADI_DMA_MSIZE eMSize;

    /* debug build only */
#if defined (ADI_DEBUG)

    /* validate the given handle */
    if (ValidateSpiHandle(hDevice) != ADI_SPI_SUCCESS)
    {
        return ADI_SPI_INVALID_HANDLE;
    }
#endif

    pDevice = (ADI_SPI *) hDevice;

    /* Return DMA not supported */
    return ADI_SPI_FAILURE;
}


/*!
 * @brief       The adi_spi_RegisterCallback API registers an optional callback function
 *              for the SPI device.
 *

 * @param[in]   hDevice     The handle of the SPI device.
 * @param[in]   pfCallback      The application supplied callback which will be called to notify device
 *                              related events.
 * @param[in]   pCBParam        The application supplied callback parameter which can be passed back in
 *                              the callback function.
 *
 * @return      Status
 *              - #ADI_SPI_SUCCESS              The device is successfully opened for the given instance.
 *              - #ADI_SPI_FAILURE              A generalised API failure.
 *              - #ADI_SPI_INVALID_HANDLE [D]   An invalid device handle.
 */

ADI_SPI_RESULT adi_spi_RegisterCallback(ADI_SPI_HANDLE const hDevice,
                                        ADI_CALLBACK pfCallback,
                                        void * const pCBParam)

{
    /* assume a return code */
    ADI_SPI_RESULT Result = ADI_SPI_SUCCESS;
    /* Pointer to device instance */
    ADI_SPI *pDevice;

    /* debug build only */
#if defined (ADI_DEBUG)

    /* validate the given handle */
    if (ValidateSpiHandle(hDevice) != ADI_SPI_SUCCESS)
    {
        return ADI_SPI_INVALID_HANDLE;
    }
#endif /* ADI_DEBUG */

    /* device handle */
    pDevice = (ADI_SPI *) hDevice;
    /* register the callback */
    pDevice->pDevData->pfCallback = pfCallback;
    pDevice->pDevData->pCBParam = pCBParam;
    
    if(pfCallback !=NULL)
    {	
    	/* store the callback mode parameter */
    	pDevice->pDevData->SpiMode = ADI_SPI_MODE_CALLBACK;
    }
    else
    {
    	/* store the callback mode parameter */
    	pDevice->pDevData->SpiMode = ADI_SPI_MODE_NONE;    	
    }    
    
    /* return */
    return (Result);
}


/*!
 * @brief       The adi_spi_SubmitBuffer API submits transceiver buffers that transfers non-blocking SPI data
 *              via either interrupts or the DMA controller depending on the state bDmaMode.
 *
 * @param[in]   hDevice                 The handle of the SPI device.
 * @param[in]   pTransceiver            The pointer to the SPI's transceiver data.
 *
 * @return  Status
 *          - #ADI_SPI_SUCCESS              The device is successfully opened for the given instance.
 *          - #ADI_SPI_FAILURE              A generalised API failure.
 *          - #ADI_SPI_INVALID_HANDLE [D]   An invalid device handle.
 *          - #ADI_SPI_QUEUE_FULL           The submitted transceiver failed, the queue is full.
 *          - #ADI_SPI_SIZE_ERROR           Buffer size is not a multiple of the transfer word size
 *          - #ADI_SPI_INVALID_POINTER      Transceiver pointer error
 *          - #ADI_SPI_MODE_NONBLOCKING_FAILED  Spi non-blocking mode has failed
 *
 * This function submits transceiver buffers under interrupt control or DMA control depending on the
 * configuration of bDMAMode parameter.  bDMAMode is configurable via the adi_spi_EnableDmaMode API.
 * The transceiver is transferred via a non-blocking mechanism.
 * The transceiver includes a prologue buffer and size, a transmit buffer and size and a receive buffer and size.
 * The transmission / reception of each of these buffers is optional.
 *
 * The prologue buffer is optional (set to NULL with a zero size if not required) and can be used
 * to send common SPI header or protocol fields.
 *
 * The transmit buffer is optional (set to NULL with a zero size if not required) and defines the
 * transmit buffer and its size in bytes.
 *
 * The receive buffer is optional (set to NULL with a zero size if not required) and defines the
 * receive buffer and its size in bytes.
 *
 * @sa          adi_spi_ReadWrite.
 * @sa          adi_spi_EnableDmaMode
 */

ADI_SPI_RESULT adi_spi_SubmitBuffer(ADI_SPI_HANDLE const hDevice, ADI_SPI_TRANSCEIVER *pTransceiver)
{
    /* assume a return code */
    ADI_SPI_RESULT Result = ADI_SPI_SUCCESS;
    /* Pointer to device instance */
    ADI_SPI *pDevice;

    /* debug build only */
#if defined (ADI_DEBUG)

    /* validate the given handle */
    if (ValidateSpiHandle(hDevice) != ADI_SPI_SUCCESS)
    {
        return ADI_SPI_INVALID_HANDLE;
    }
#endif /* ADI_DEBUG */

    pDevice = (ADI_SPI *) hDevice;

    /* debug build only */
#if defined (ADI_DEBUG)

    /* validate the transceiver and its buffers */
    Result = ValidateTransceiver(pDevice, pTransceiver);
    if (Result != ADI_SPI_SUCCESS)
    {
        return (ADI_SPI_INVALID_HANDLE);
    }
#endif
    /* check that mode is not blocking*/
    if(pDevice->pDevData->SpiMode == ADI_SPI_MODE_BLOCKING)
    {
        return(ADI_SPI_MODE_NONBLOCKING_FAILED);
    }
    /* MISA 14.10 else if(pDevice->pDevData->SpiMode == ADI_SPI_MODE_NONE) */
    if(pDevice->pDevData->SpiMode == ADI_SPI_MODE_NONE)
    {
        pDevice->pDevData->SpiMode = ADI_SPI_MODE_NONBLOCKING;
    }

    /* if there is no primary transceiver, prepare for DMA transfer */
    if (pDevice->pDevData->pPrimaryTransceiver == NULL)
    {
    	adi_osal_EnterCriticalRegion();
        /* add submitted transceiver to primary transceiver */
    	pDevice->pDevData->pActiveTransceiver = pTransceiver;
        pDevice->pDevData->pPrimaryTransceiver = pTransceiver;
        pDevice->pDevData->pSecondaryTransceiver = NULL;
        pDevice->pDevData->bPrimaryProcessed = false;
        pDevice->pDevData->bSecondaryProcessed = false;
        adi_osal_ExitCriticalRegion();

        /* either submit DMA driven or interrupt driven transceiver buffer, */
        /* based on adi_spi_EnableDmaMode configuration                     */
        Result = pDevice->pDevData->FuncTable.pfSpiSubmitBuffer(pDevice, pTransceiver);
        if (Result != ADI_SPI_SUCCESS)
        {
            return Result;
        }

    }
    /* if there is no secondary */
    else if(pDevice->pDevData->pSecondaryTransceiver == NULL)
    {
    	adi_osal_EnterCriticalRegion();
        /* add submitted transceiver to secondary transceiver */
        pDevice->pDevData->pSecondaryTransceiver = pTransceiver;
        pDevice->pDevData->bSecondaryProcessed = false;
        adi_osal_ExitCriticalRegion();

        /* in DMA mode submit to DMA queue, else it handled in the spi queue */
        if(pDevice->pDevData->bDmaMode == true)
        {
            Result = pDevice->pDevData->FuncTable.pfSpiSubmitBuffer(pDevice, pTransceiver);
            if (Result != ADI_SPI_SUCCESS)
            {
                return Result;
            }
        }
    }
    /* if there is already a primary and secondary transceiver, queue is full */
    else
    {
        return ADI_SPI_QUEUE_FULL;
    }

    /* Return */
    return Result;
}

/*!
 * @brief       The adi_spi_ReadWrite API submits transceiver buffers that transfers blocking SPI data
 *              via either interrupts or the DMA controller depending on the state bDmaMode.
 *
 * @param [in]   hDevice                 The handle of the SPI device.
 * @param [in]   pTransceiver            The pointer to the SPI's transceiver data.
 *
 * @return  Status
 *          - #ADI_SPI_SUCCESS              The device is successfully opened for the given instance.
 *          - #ADI_SPI_FAILURE              A generalised API failure.
 *          - #ADI_SPI_INVALID_HANDLE [D]   An invalid device handle.
 *          - #ADI_SPI_QUEUE_FULL           The submitted transceiver failed, the queue is full.
 *          - #ADI_SPI_SIZE_ERROR           Buffer size is not a multiple of the transfer word size
 *          - #ADI_SPI_INVALID_POINTER      Transceiver pointer error
 *          - #ADI_SPI_MODE_BLOCKING_FAILED    The blocking mode of spi has failed
 *          - #ADI_SPI_SEMAPHORE_PEND_FAILED    The spi semaphore pend has failed
 *
 * This function read/writes a transceiver under interrupt control or DMA control depending on the
 * configuration of bDMAMode parameter.  bDMAMode is configurable via the adi_spi_EnableDmaMode API.
 * The transceiver transfer takes place via a blocking mechanism.
 * The transceiver includes a prologue buffer and size, a transmit buffer and size and a receive buffer and size.
 * The transmission / reception of each of these buffers is optional.
 *
 * The prologue buffer is optional (set to NULL with a zero size if not required) and can be used
 * to send common SPI header or protocol fields.
 *
 * The transmit buffer is optional (set to NULL with a zero size if not required) and defines the
 * transmit buffer and its size in bytes.
 *
 * The receive buffer is optional (set to NULL with a zero size if not required) and defines the
 * receive buffer and its size in bytes.
 *
 * @sa          adi_spi_SubmitBuffers.
 * @sa          adi_spi_EnableDmaMode
 */

ADI_SPI_RESULT adi_spi_ReadWrite(ADI_SPI_HANDLE const hDevice, ADI_SPI_TRANSCEIVER *pTransceiver)
{
    /* assume a return code */
    ADI_SPI_RESULT Result = ADI_SPI_SUCCESS;
    /* Pointer to device instance */
    ADI_SPI *pDevice;

    /* debug build only */
#if defined (ADI_DEBUG)

    /* validate the given handle */
    if (ValidateSpiHandle(hDevice) != ADI_SPI_SUCCESS)
    {
        return ADI_SPI_INVALID_HANDLE;
    }
#endif /* ADI_DEBUG */

    pDevice = (ADI_SPI *) hDevice;

    /* debug build only */
#if defined (ADI_DEBUG)

    /* validate the transceiver and its buffers */
    Result = ValidateTransceiver(pDevice, pTransceiver);
    if (Result != ADI_SPI_SUCCESS)
    {
        return Result;
    }
#endif

    /* check that mode is not blocking*/
    if(pDevice->pDevData->SpiMode != ADI_SPI_MODE_NONE)
    {
        return(ADI_SPI_MODE_BLOCKING_FAILED);
    }
    else
    {
        pDevice->pDevData->SpiMode = ADI_SPI_MODE_BLOCKING;
    }

    Result = pDevice->pDevData->FuncTable.pfSpiSubmitBuffer(pDevice,pTransceiver);
    if (Result != ADI_SPI_SUCCESS)
    {
        return Result;
    }

    if (adi_osal_SemPend(pDevice->pDevData->hSemHandle, ADI_OSAL_TIMEOUT_FOREVER) != ADI_OSAL_SUCCESS)
    {
        return ADI_SPI_SEMAPHORE_PEND_FAILED;
    }

    pDevice->pDevData->SpiMode = ADI_SPI_MODE_NONE;

    if(pDevice->pDevData->SpiStatusEvent != (uint16_t) ADI_SPI_HW_ERR_NONE)
    {
    	return ADI_SPI_HW_ERROR;
    }

    /* Return */
    return Result;
}

/**
 * @brief   adi_spi_GetBuffer
 *          This function gets a pointer to the transceivers buffers that have been processed.
 *
 * @param   [in]  hDevice                       Handle of the SPI device
 * @param   [out] pTransceiver                  Pointer to store transceiver
 *
 * @return  Status
 *          - #ADI_SPI_SUCCESS                  The device is successfully opened for the given instance.
 *          - #ADI_SPI_FAILURE                  A generalised API failure.
 *          - #ADI_SPI_INVALID_HANDLE [D]       An invalid device handle.
 *          - #ADI_SPI_SEMAPHORE_PEND_FAILED    The spi semaphore pend has failed.
 *          - #ADI_SPI_MODE_NONBLOCKING_FAILED  The spi non-blocking mode failed.
 *
 */
ADI_SPI_RESULT adi_spi_GetBuffer(ADI_SPI_HANDLE const hDevice,  ADI_SPI_TRANSCEIVER **pTransceiver)
{
    /* assume a return code */
    ADI_SPI_RESULT Result = ADI_SPI_SUCCESS;
    /* Pointer to device instance */
    ADI_SPI *pDevice;

    /* debug build only */
#if defined (ADI_DEBUG)

    /* validate the given handle */
    if (ValidateSpiHandle(hDevice) != ADI_SPI_SUCCESS)
    {
        return ADI_SPI_INVALID_HANDLE;
    }
#endif /* ADI_DEBUG */

    pDevice = (ADI_SPI *) hDevice;

    /* check that mode is non-blocking */
    if(pDevice->pDevData->SpiMode != ADI_SPI_MODE_NONBLOCKING)
    {
        /* operational mode error */
        return(ADI_SPI_MODE_NONBLOCKING_FAILED);
    }
    else
    {
        /* pend on semaphore */
        if (adi_osal_SemPend(pDevice->pDevData->hSemHandle, ADI_OSAL_TIMEOUT_FOREVER) != ADI_OSAL_SUCCESS)
        {
            return ADI_SPI_SEMAPHORE_PEND_FAILED;
        }
        /* store the returned transceiver, always the primary */
        *pTransceiver = pDevice->pDevData->pPrimaryTransceiver;
        /* update the primary transceiver, make the secondary the primary, make secondary NULL */
        pDevice->pDevData->pPrimaryTransceiver = pDevice->pDevData->pSecondaryTransceiver;
        pDevice->pDevData->pSecondaryTransceiver = NULL;
        pDevice->pDevData->bPrimaryProcessed = pDevice->pDevData->bSecondaryProcessed;
        pDevice->pDevData->bSecondaryProcessed = false;

        if(pDevice->pDevData->pPrimaryTransceiver == NULL)
        {
        	pDevice->pDevData->SpiMode = ADI_SPI_MODE_NONE;
        }
        if(pDevice->pDevData->SpiStatusEvent != (uint16_t) ADI_SPI_HW_ERR_NONE)
        {
        	return ADI_SPI_HW_ERROR;
        }
    }
    return Result;
}

/**
 * @brief   adi_spi_IsBufferAvailable
 *          This function gets a pointer to a flag that indicates whether there is a
 *          processed transceiver buffer available.
 *
 * @param[in]  hDevice                          Handle of the SPI device
 * @param[out] pbAvailable                      Pointer to flag that indicates
 *                - true                        transceiver is available
 *                - false                       transceiver is not available
 *
 * @return      Status
 *              - #ADI_SPI_SUCCESS              The device is successfully opened for the given instance.
 *              - #ADI_SPI_FAILURE              A generalised API failure.
 *              - #ADI_SPI_INVALID_HANDLE [D]   An invalid device handle.
 *
 */
ADI_SPI_RESULT adi_spi_IsBufferAvailable(ADI_SPI_HANDLE const hDevice,  bool *pbAvailable)
{
    /* assume a return code */
    ADI_SPI_RESULT Result = ADI_SPI_SUCCESS;
    /* Pointer to device instance */
    ADI_SPI *pDevice;

    /* debug build only */
#if defined (ADI_DEBUG)

    /* validate the given handle */
    if (ValidateSpiHandle(hDevice) != ADI_SPI_SUCCESS)
    {
        return ADI_SPI_INVALID_HANDLE;
    }
#endif /* ADI_DEBUG */

    pDevice = (ADI_SPI *) hDevice;

    /* check if there is a free buffer in the transceiver queue */
    if(pDevice->pDevData->bPrimaryProcessed == true)
    {
        *pbAvailable = true;
    }
    else if(pDevice->pDevData->bSecondaryProcessed == true)
    {
        *pbAvailable = true;
    }
    else
    {
        *pbAvailable = false;
    }
    return Result;
}

/*!
 * @brief       The adi_spi_SetTransferInitiate API sets the mode in which a SPI transfer is initiated.
 *
 * @param[in]   hDevice                 Handle of the SPI device.
 * @param[in]   eTransferInitiateMode   Enumeration for the transfer intitiate mode.

 * @return      Status
 *              - #ADI_SPI_SUCCESS              The device is successfully opened for the given instance.
 *              - #ADI_SPI_FAILURE              A generalised API failure.
 *              - #ADI_SPI_INVALID_HANDLE [D]   An invalid device handle.
 *
 * The transfer initiation mode is dependent on whether the SPI device is in interrupt mode or DMA mode.
 *
 * The enumeration ADI_SPI_RX_INITIATE_INTERRUPT configures the SPI to start a transfer upon reading the
 * Rx Fifo and subsequent interrupts are activated when the Rx Fifo is full.
 *
 * The enumeration ADI_SPI_TX_INITIATE_INTERRUPT configures the SPI to start transfers upon writing to the
 * Tx Fifo and subsequent interrupts are activated when the Tx Fifo is empty.
 *
 * The enumeration ADI_SPI_RX_INITIATE_DMA configures the SPI to starts transfer upon reading the
 * Rx Fifo and subsequent DMA reads are requested when the Rx Fifo is not empty.
 *
 * The enumeration ADI_SPI_TX_INITIATE_DMA configures the SPI to starts transfer upon writing to the
 * Tx Fifo and subsequent DMA writes are requested when the Tx Fifo is not full.
 *
 */
ADI_SPI_RESULT adi_spi_SetTransferInitiateMode(ADI_SPI_HANDLE const hDevice,
                                               ADI_SPI_TRANSFER_INITIATE_MODE eTransferInitiateMode)
{
    /* assume a return code */
    ADI_SPI_RESULT Result = ADI_SPI_SUCCESS;
    /* Pointer to device instance */
    ADI_SPI *pDevice;
    /* register value */
    uint16_t RegValue;

    /* debug build only */
#if defined (ADI_DEBUG)

    /* validate the given handle */
    if (ValidateSpiHandle(hDevice) != ADI_SPI_SUCCESS)
    {
        return ADI_SPI_INVALID_HANDLE;
    }
#endif /* ADI_DEBUG */

    pDevice = (ADI_SPI *) hDevice;

    /* read and clear register field bits */
    RegValue = pDevice->pRegs->SPI_REG_CONTROL;
    RegValue &= (uint16_t) ~(BITM_SPI_CTL_TIMOD);
    /* update register */
    pDevice->pRegs->SPI_REG_CONTROL = ((uint16_t) eTransferInitiateMode | RegValue);

    /* Return */
    return Result;
}

/*!
 * @brief       The adi_spi_SetClock API sets the SPI clocking rate.
 *
 * @param[in]   hDevice     Handle of the SPI device.
 * @param[in]   Clock       SPI clock rate parameter

 * @return      Status
 *              - #ADI_SPI_SUCCESS              The device is successfully opened for the given instance.
 *              - #ADI_SPI_FAILURE              A generalised API failure.
 *              - #ADI_SPI_INVALID_HANDLE [D]   An invalid device handle.
 *
 *
 * @note        The frequency of the SPI clock is calculated by SCLK / 2* Baud
 */

ADI_SPI_RESULT adi_spi_SetClock(ADI_SPI_HANDLE const hDevice, uint16_t Clock)
{
    /* assume a return code */
    ADI_SPI_RESULT Result = ADI_SPI_SUCCESS;
    /* Pointer to device instance */
    ADI_SPI *pDevice;

    uint16_t Range;

    /* debug build only */
#if defined (ADI_DEBUG)

    /* validate the given handle */
    if (ValidateSpiHandle(hDevice) != ADI_SPI_SUCCESS)
    {
        return ADI_SPI_INVALID_HANDLE;
    }

#endif /* ADI_DEBUG */
    /* range check of clock */
    if((uint32_t)Clock > (uint32_t)BITM_SPI_CLK_BAUD)
    {
        return ADI_SPI_BAD_PARAMETER;
    }
    pDevice = (ADI_SPI *) hDevice;

    /* write to register */
    pDevice->pRegs->SPI_REG_BAUD = Clock;

    /* Return */
    return Result;
}

/*!
 * @brief  The adi_spi_SetClockPolarity API sets the SPI clock polarity.
 *
 * @param[in]    hDevice      Handle of the SPI device.
 * @param[in]    bActiveHigh  Flag to manage the polarity of the serial data clock.
 *               - true       Active high clock.
 *               - false      Active low clock.
 *
 * @return      Status
 *              - #ADI_SPI_SUCCESS              The device is successfully opened for the given instance.
 *              - #ADI_SPI_FAILURE              A generalised API failure.
 *              - #ADI_SPI_INVALID_HANDLE [D]   An invalid device handle.
 *
 *
 * @sa        adi_spi_SetClockPhase().
 */
ADI_SPI_RESULT adi_spi_SetClockPolarity(ADI_SPI_HANDLE const hDevice, bool bActiveHigh)
{
    /* assume a return code */
    ADI_SPI_RESULT Result = ADI_SPI_SUCCESS;
    /* Pointer to device instance */
    ADI_SPI *pDevice;

    /* debug build only */
#if defined (ADI_DEBUG)

    /* validate the given handle */
    if (ValidateSpiHandle(hDevice) != ADI_SPI_SUCCESS)
    {
        return ADI_SPI_INVALID_HANDLE;
    }
#endif

    pDevice = (ADI_SPI *) hDevice;

    if (bActiveHigh == true)
    {
        /* set SPI clock polarity to active high */
        pDevice->pRegs->SPI_REG_CONTROL &= (uint16_t) ~(ENUM_SPI_CTL_SCKLO);
    }
    else
    {
        /* set SPI clock polarity to active high */
        pDevice->pRegs->SPI_REG_CONTROL |= (uint16_t) ENUM_SPI_CTL_SCKLO;
    }
    /* Return */
    return (Result);
}

/*!
 * @brief   The adi_spi_SetMaster API sets the SPI in master or slave mode.
 *
 * @param[in]    hDevice      Handle of the SPI device.
 * @param[in]    bMaster      Flag to manage master or slave mode.
 *               - true       For LSB first.
 *               - false      For MSB first.
 *
 * @return      Status
 *              - #ADI_SPI_SUCCESS              The device is successfully opened for the given instance.
 *              - #ADI_SPI_FAILURE              A generalised API failure.
 *              - #ADI_SPI_INVALID_HANDLE [D]   An invalid device handle.
 *
 * Configures SPI controller in master or slave mode.
 */

ADI_SPI_RESULT adi_spi_SetMaster(ADI_SPI_HANDLE const hDevice, bool bMaster)
{
    /* assume a return code */
    ADI_SPI_RESULT Result = ADI_SPI_SUCCESS;
    /* Pointer to device instance */
    ADI_SPI *pDevice;
    /* register value */
    uint16_t RegValue;

    /* debug build only */
#if defined (ADI_DEBUG)

    /* validate the given handle */
    if (ValidateSpiHandle(hDevice) != ADI_SPI_SUCCESS)
    {
        return ADI_SPI_INVALID_HANDLE;
    }
#endif

    pDevice = (ADI_SPI *) hDevice;

    /* read and clear register field bits */
    RegValue = pDevice->pRegs->SPI_REG_CONTROL;
    RegValue &= ~((uint16_t) BITM_SPI_CTL_MSTR | (uint16_t) BITM_SPI_CTL_PSSE | (uint16_t) BITM_SPI_CTL_EMISO);

    if (bMaster == true)
    {
        /* set SPI in master mode       */
        /* disable slave select enable  */
        /* enable MISO                  */
        RegValue |= ((uint16_t) ENUM_SPI_CTL_MASTER | (uint16_t) ENUM_SPI_CTL_PSSE_DIS | (uint16_t) ENUM_SPI_CTL_MISO_EN);

    }
    else
    {
        /* set SPI in slave mode        */
        /* enable slave select enable   */
        /* enable MISO                  */
        RegValue |= ((uint16_t) ENUM_SPI_CTL_SLAVE | (uint16_t) ENUM_SPI_CTL_PSSE_EN | (uint16_t) ENUM_SPI_CTL_MISO_EN);
    }

    /* update register */
    pDevice->pRegs->SPI_REG_CONTROL = RegValue;

    /* Return */
    return Result;
}

/*!
 * @brief   The adi_spi_SetLsbFirst API sets the SPI LSB or MSB first transfer mode.
 *
 * @param[in]    hDevice      Handle of the SPI device.
 * @param[in]    bLsbFirst    Flag to manage LSB or MSB transfers.
 *               - true       For LSB first.
 *               - false      For MSB first.
 *
 * @return      Status
 *              - #ADI_SPI_SUCCESS              The device is successfully opened for the given instance.
 *              - #ADI_SPI_FAILURE              A generalised API failure.
 *              - #ADI_SPI_INVALID_HANDLE [D]   An invalid device handle.
 *
 * Configures whether data is transferred as LSB first or MSB first.
 */

ADI_SPI_RESULT adi_spi_SetLsbFirst(ADI_SPI_HANDLE const hDevice, bool bLsbFirst)
{
    /* assume a return code */
    ADI_SPI_RESULT Result = ADI_SPI_SUCCESS;
    /* Pointer to device instance */
    ADI_SPI *pDevice;

    /* debug build only */
#if defined (ADI_DEBUG)

    /* validate the given handle */
    if (ValidateSpiHandle(hDevice) != ADI_SPI_SUCCESS)
    {
        return ADI_SPI_INVALID_HANDLE;
    }
#endif

    pDevice = (ADI_SPI *) hDevice;

    if (bLsbFirst == true)
    {
        /* set SPI to LSB sent/received first */
        pDevice->pRegs->SPI_REG_CONTROL |= (uint16_t) ENUM_SPI_CTL_LSB_FIRST;
    }
    else
    {
        /* set SPI to MSB sent/received first */
        pDevice->pRegs->SPI_REG_CONTROL &= (uint16_t) ~(ENUM_SPI_CTL_LSB_FIRST);
    }

    /* Return */
    return Result;
}

/*!
 * @brief  The adi_spi_SetTransmitUnderflow API sets the SPI transmit FIFO underflow mode.
 *
 * @param[in]    hDevice      Handle of the SPI device
 * @param[in]    bSendZero    Flag to manage data transmission when FIFO is underflowing.
 *               - true       Send zeroes on transmit FIFO underflow.
 *               - false      Resend last data on transmit FIFO underflow.
 *
 * @return      Status
 *              - #ADI_SPI_SUCCESS              The device is successfully opened for the given instance.
 *              - #ADI_SPI_FAILURE              A generalised API failure.
 *              - #ADI_SPI_INVALID_HANDLE [D]   An invalid device handle.
 *
 * Controls what to transmit when lacking valid data because the transmit FIFO is empty.
 * Either zeros or the last valid data are transmitted.  Set transmit FIFO underflow mode to send zeros.
 * Clear it to resend the last transmitted data.
 *
 * @sa        adi_spi_SetReceiveOverflow().
 */
ADI_SPI_RESULT adi_spi_SetTransmitUnderflow(ADI_SPI_HANDLE const hDevice, bool bSendZero)
{
    /* assume a return code */
    ADI_SPI_RESULT Result = ADI_SPI_SUCCESS;
    /* Pointer to device instance */
    ADI_SPI *pDevice;

    /* debug build only */
#if defined (ADI_DEBUG)

    /* validate the given handle */
    if (ValidateSpiHandle(hDevice) != ADI_SPI_SUCCESS)
    {
        return ADI_SPI_INVALID_HANDLE;
    }
#endif

    pDevice = (ADI_SPI *) hDevice;
    if (bSendZero == true)
    {
        /* enable tx under-run condition to send zeros when empty */
        pDevice->pRegs->SPI_REG_CONTROL |= (uint16_t) ENUM_SPI_CTL_ZERO;
    }
    else
    {
        /* enable tx under-run condition to send last word when empty */
        pDevice->pRegs->SPI_REG_CONTROL &= (uint16_t) ~(ENUM_SPI_CTL_ZERO);
    }

    /* Return */
    return Result;
}

/*!
 * @brief   The adi_spi_SetReceiveOverflow API sets the SPI receive overflow condition.
 *
 * @param[in]    hDevice      Handle of the SPI device
 * @param[in]    bOverwrite   Flag to manage how the recieve FIFO overflows.
 *               - true       Overwrite old data on receive FIFO overflow.
 *               - false      Discard incoming data on receive FIFO overflow.
 *
 * @return      Status
 *              - #ADI_SPI_SUCCESS              The device is successfully opened for the given instance.
 *              - #ADI_SPI_FAILURE              A generalised API failure.
 *              - #ADI_SPI_INVALID_HANDLE [D]   An invalid device handle.
 *
 * Controls what to do with excess incoming data when the receive FIFO becomes full.
 * Either the new data or the old data is discarded.  Set the receive FIFO overflow mode
 * to replace data in the RX register (top of receive FIFO) with the incoming new data.
 * Clear it to discard incoming new data and preserve old undead data.
 *
 * @sa        adi_SPI_SetTransmitUnderflow().
 */

ADI_SPI_RESULT adi_spi_SetReceiveOverflow(ADI_SPI_HANDLE const hDevice, bool bOverwrite)
{
    /* assume a return code */
    ADI_SPI_RESULT Result = ADI_SPI_SUCCESS;
    /* Pointer to device instance */
    ADI_SPI *pDevice;

    /* debug build only */
#if defined (ADI_DEBUG)

    /* validate the given handle */
    if (ValidateSpiHandle(hDevice) != ADI_SPI_SUCCESS)
    {
        return ADI_SPI_INVALID_HANDLE;
    }
#endif

    pDevice = (ADI_SPI *) hDevice;

    if (bOverwrite == true)
    {
        /* enable rx over-run to overwrite data when full*/
        pDevice->pRegs->SPI_REG_CONTROL |= (uint16_t) ENUM_SPI_CTL_OVERWRITE;
    }
    else
    {
        /* enable rx over-run to discard data when full */
        pDevice->pRegs->SPI_REG_CONTROL &= (uint16_t) ~(ENUM_SPI_CTL_OVERWRITE);
    }

    /* Return */
    return Result;

}

/*!
 * @brief   The adi_spi_SetWordSize API sets the size of SPI data transfer.
 *
 * @param[in]    hDevice        Handle of the SPI device
 * @param[in]    eTransferSize  Enumeration for the size of the data transfer.
 *                - #ADI_SPI_TRANSFER_8BIT  8 bit data transfer.
 *                - #ADI_SPI_TRANSFER_16BIT 16 bit data transfer.
 *
 * @return      Status
 *              - #ADI_SPI_SUCCESS              The device is successfully opened for the given instance.
 *              - #ADI_SPI_FAILURE              A generalised API failure.
 *              - #ADI_SPI_INVALID_HANDLE [D]   An invalid device handle.
 *              - #ADI_SPI_BAD_PARAMETER        Parameter is out of range.
 *
 * Sets the size of data that is passed through the FIFO during an SPI transfer.
 */

ADI_SPI_RESULT adi_spi_SetWordSize(ADI_SPI_HANDLE const hDevice, ADI_SPI_TRANSFER_SIZE eTransferSize)
{

    /* assume a return code */
    ADI_SPI_RESULT Result = ADI_SPI_SUCCESS;
    /* Pointer to device instance */
    ADI_SPI *pDevice;
    /* register value */
    uint16_t RegValue;

    /* debug build only */
#if defined (ADI_DEBUG)

    /* validate the given handle */
    if (ValidateSpiHandle(hDevice) != ADI_SPI_SUCCESS)
    {
        return ADI_SPI_INVALID_HANDLE;
    }
#endif

    pDevice = (ADI_SPI *) hDevice;

    /* determine the number of bytes in the word transfer size */
    switch (eTransferSize)
    {
        case ADI_SPI_TRANSFER_8BIT:
            pDevice->pDevData->SpiTransferSize = 1u;
            break;
        case ADI_SPI_TRANSFER_16BIT:
            pDevice->pDevData->SpiTransferSize = 2u;
            break;

        default:
            Result =  ADI_SPI_BAD_PARAMETER;
            break;
    }

    /* read and clear register field bits */
    RegValue = pDevice->pRegs->SPI_REG_CONTROL;
    RegValue &= (uint16_t) ~(BITM_SPI_CTL_SIZE);
    /* update register */
    pDevice->pRegs->SPI_REG_CONTROL = ((uint16_t) eTransferSize | RegValue);

    /* Return */
    return Result;
}

/*!
 * @brief   The adi_spi_SetSlaveSelect API sets the slave select number for the SPI.
 *
 * @param[in]    hDevice        Handle of the SPI device
 * @param[in]    eSlaveSelect   Enumeration for the SPI slave select number
 *                              #ADI_SPI_SSEL_ENABLE1..7
 *
 * @return      Status
 *              - #ADI_SPI_SUCCESS              The device is successfully opened for the given instance.
 *              - #ADI_SPI_FAILURE              A generalised API failure.
 *              - #ADI_SPI_INVALID_HANDLE [D]   An invalid device handle.
 *              - #ADI_SPI_CONFIGURATION_ERROR  When slave select is configured whilst not in SPI master mode.
 *
 * Sets the the slave select number for the SPI.  Is does not assert the slave select signal, just enables it.
 */

ADI_SPI_RESULT adi_spi_SetSlaveSelect(ADI_SPI_HANDLE const hDevice, ADI_SPI_SSENABLE eSlaveSelect)
{
    /* assume a return code */
    ADI_SPI_RESULT Result = ADI_SPI_SUCCESS;
    /* Pointer to device instance */
    ADI_SPI *pDevice;
    /* register value */
    uint16_t RegValue;

    /* debug build only */
#if defined (ADI_DEBUG)

    /* validate the given handle */
    if (ValidateSpiHandle(hDevice) != ADI_SPI_SUCCESS)
    {
        return ADI_SPI_INVALID_HANDLE;
    }
#endif

    pDevice = (ADI_SPI *) hDevice;

    /* debug build only */
#if defined (ADI_DEBUG)
    /* check if device is configured as master */
    if ((pDevice->pRegs->SPI_REG_CONTROL & (uint16_t) ENUM_SPI_CTL_MASTER) == 0u)
    {
        /* device is not set as master */
        return ADI_SPI_CONFIGURATION_ERROR;
    }
#endif

    /* read and clear register field bits */
    RegValue = pDevice->pRegs->SPI_REG_FLAG & (uint16_t) ~(BITM_SPI_SSE);
    /* enable the slave select */
    pDevice->pRegs->SPI_REG_FLAG = ((uint16_t) eSlaveSelect | RegValue);
    /* store the slave select enable number as the ENUM for slave select value */
    pDevice->pDevData->SpiSlaveSelect = eSlaveSelect;

    /* Return */
    return Result;
}

/*!
 * @brief   The adi_spi_SetHwSlaveSelect API sets the SPI hardware to control the slave select.
 *
 * @param[in]    hDevice      Handle of the SPI device
 * @param[in]    bHWSlaveSel  Flag to manage hardware or software slave selection control.
 *               - true       Slave select controlled by hardware.
 *               - false      Slave select controlled by software.
 *
 * @return      Status
 *              - #ADI_SPI_SUCCESS              The device is successfully opened for the given instance.
 *              - #ADI_SPI_FAILURE              A generalised API failure.
 *              - #ADI_SPI_INVALID_HANDLE [D]   An invalid device handle.
 *
 * Configures the SPI to control the assertion / de-assertion of the slave select signals.  Typically
 * the SPI software drivers controls slave select but in this mode the hardware does.
 *
 * @sa        adi_spi_SetSlaveSelect().
 */
ADI_SPI_RESULT adi_spi_SetHwSlaveSelect(ADI_SPI_HANDLE const hDevice, bool bHWSlaveSel)
{
    /* assume a return code */
    ADI_SPI_RESULT Result = ADI_SPI_SUCCESS;
    /* Pointer to device instance */
    ADI_SPI *pDevice;

    /* debug build only */
#if defined (ADI_DEBUG)

    /* validate the given handle */
    if (ValidateSpiHandle(hDevice) != ADI_SPI_SUCCESS)
    {
        return ADI_SPI_INVALID_HANDLE;
    }
#endif

    pDevice = (ADI_SPI *) hDevice;

    if (bHWSlaveSel ==true)
    {
        /* enable the hardware controlled slave select */
        /* this control bit is the same as the clock phase */
        pDevice->pRegs->SPI_REG_CONTROL &= (uint16_t) ~(ENUM_SPI_CTL_SCKBEG);
        /* clear software slave select flag */
        pDevice->pDevData->SpiSWSlaveSelectEnable = false;
    }
    else
    {
        /* disable hardware controlled slave select enable */
        /* this control bit is the same as the clock phase */
        pDevice->pRegs->SPI_REG_CONTROL |= (uint16_t) ENUM_SPI_CTL_SCKBEG;
        /* set software slave select flag */
        pDevice->pDevData->SpiSWSlaveSelectEnable = true;
    }

    /* Return */
    return Result;
}

/**
 * @brief   adi_spi_GetHWErrorStatus
 *          This function gets the Hardware error(s) encountered by the specified device.
 *
 * @param   [in]  hDevice   Handle of the SPI device
 * @param   [in]  pHwError  Pointer to  a variable of  "ADI_SPI_HW_ERROR" where the error event to be written.
 * @param   [in]  pArg      Additional parameter passed to the user. For SPI device it is NULL.
 *
* @return      Status
 *              - #ADI_SPI_SUCCESS          The device is successfully opened for the given instance.
 *              - #ADI_SPI_FAILURE          A generalised API failure.
 *              - #ADI_SPI_INVALID_HANDLE   An invalid device handle.
 *
*/
ADI_SPI_RESULT adi_spi_GetHWErrorStatus (ADI_SPI_HANDLE const hDevice,
                                         uint32_t *pHwError,
                                         void *const pArg)
{
    /* assume a return code */
    ADI_SPI_RESULT Result = ADI_SPI_SUCCESS;

    /* Pointer to device instance */
    ADI_SPI *pDevice;
    
/* debug build only */
#if defined (ADI_DEBUG)

    /* validate the given handle */
    if(ValidateSpiHandle(hDevice) != ADI_SPI_SUCCESS)
    {
        return ADI_SPI_INVALID_HANDLE;
    }
#endif

    pDevice = (ADI_SPI *)hDevice;

    *pHwError = pDevice->pDevData->SpiStatusEvent;
    pDevice->pDevData->SpiStatusEvent  = (uint16_t) ADI_SPI_HW_ERR_NONE;
    return(ADI_SPI_SUCCESS);
}





/*********************************************************************

 Internal Functions

 *********************************************************************/

/*!
 * @brief       The adi_spi_SubmitIntBuffer API submits a transceiver buffer
 *              that transfers SPI data via either interrupts.
 *
 * @param[in]   hDevice                 The handle of the SPI device.
 * @param[in]   pTransceiver            The pointer to the SPI's transceiver data.
 *
 * @return      Status
 *              - #ADI_SPI_SUCCESS              The device is successfully opened for the given instance.
 *              - #ADI_SPI_FAILURE              A generalised API failure.
 *              - #ADI_SPI_INVALID_HANDLE [D]   An invalid device handle.
 *              - #ADI_SPI_QUEUE_FULL           The submitted transceiver failed, the queue is full.
 *              - #ADI_SPI_SIZE_ERROR           Buffer size is not a multiple of the transfer word size
 *              - #ADI_SPI_INVALID_POINTER      Transceiver pointer error
 *              - #ADI_SPI_SLAVE_SELECT_FAILED  The slave select line failed to be asserted
 *              - #ADI_SPI_CONFIGURATION_ERROR  The SPI has been configured in an illegal state
 *
 * This function submits a transceiver under interrupt control. The transceiver includes a
 * prologue buffer and size, a transmit buffer and size and a receive buffer and size. The transmission / reception
 * of each of these buffers is optional.
 *
 * The prologue buffer is optional (set to NULL with a zero size if not required) and can be used
 * to send common SPI header or protocol fields.
 *
 * The transmit buffer is optional (set to NULL with a zero size if not required) and defines the
 * transmit buffer and its size in bytes.
 *
 * The receive buffer is optional (set to NULL with a zero size if not required) and defines the
 * receive buffer and its size in bytes.
 *
 * @sa          adi_spi_DmaTransceiver.
 * @sa          adi_spi_EnableDmaMode
 */

static ADI_SPI_RESULT adi_spi_SubmitIntBuffer(ADI_SPI_HANDLE const hDevice, ADI_SPI_TRANSCEIVER *pTransceiver)
{
    /* assume a return code */
    ADI_SPI_RESULT Result = ADI_SPI_SUCCESS;
    /* Pointer to device instance */
    ADI_SPI *pDevice;
    uint16_t Data;

    pDevice = (ADI_SPI *) hDevice;

    /* if DMA mode, wrong configuration as this is a interrupt driven SPI transceiver */
    if (pDevice->pDevData->bDmaMode)
    {
        return ADI_SPI_CONFIGURATION_ERROR;
    }

    /* set to receive initiate interrupt mode */
    Data = pDevice->pRegs->SPI_REG_CONTROL;
    Data &= (uint16_t) ~(BITM_SPI_CTL_TIMOD);
    pDevice->pRegs->SPI_REG_CONTROL = ((uint16_t) ENUM_SPI_CTL_TIMOD00 | Data);

    adi_osal_EnterCriticalRegion();
    /* load the primary transceiver with submitted transceiver  */
    /* secondary must be NULL                                   */
    /* dont' make primary active just yet, special case         */
    /* activated in SwitchTxTransceiver                         */
    pDevice->pDevData->pPrimaryTransceiver = pTransceiver;
    pDevice->pDevData->pActiveTransceiver = NULL;
    pDevice->pDevData->pSecondaryTransceiver = NULL;

    /* reset transfer data */
    ResetTransfer(pDevice);
    /* switch over tx transceiver to default primary transceiver */
    SwitchTxTransceiver(pDevice);
    /* switch over rx transceiver to default primary transceiver */
    SwitchRxTransceiver(pDevice);

    /* the submitted transceiver always is the active at this point */
    pDevice->pDevData->pActiveTransceiver =pTransceiver;

    /* enable the global SPI                                                                */
    /* tx and/or tx enable should already be set accordingly to SetTransceiverMode          */
    /* SPI data flow will be driven be the assertion / de-assetion of the slave select line */
    pDevice->pRegs->SPI_REG_CONTROL |= (uint16_t)ENUM_SPI_CTL_EN;

    /* initial loading of tx fifo, if there is transmit data in the active transceiver */
    if ((pDevice->pDevData->pActiveTransceiver->pPrologue != NULL) ||
        (pDevice->pDevData->pActiveTransceiver->pTransmitter != NULL))
    {
        /* load tx fifo */
        LoadTxFifo(pDevice);
    }
    CheckForTransferCompletion(pDevice);

    adi_osal_ExitCriticalRegion();


    /* Assert SPI select line */
    /* if software slave select is enabled, asset slave select */
    if (pDevice->pDevData->SpiSWSlaveSelectEnable)
    {
        /* if valid slave select */
        if (pDevice->pDevData->SpiSlaveSelect != ADI_SPI_SSEL_DISABLE)
        {
            /* Assert the slave select, assertion active low */
        	pDevice->pRegs->SPI_REG_FLAG &= ~(uint16_t)((uint16_t)pDevice->pDevData->SpiSlaveSelect << 8u);
        }
        else
        {
        	return ADI_SPI_SLAVE_SELECT_FAILED;
        }
    }

    /* this read is a dummy read and initiates the SPI transfer */
    Data = pDevice->pRegs->SPI_REG_RDBR;

    /* Return */
    return Result;
}


/*!
 * @brief       The adi_spi_SubmitDmaBuffer API submits a transceiver buffer to the SPI
 *              for DMA data transfer.
 *
 * @param[in]   hDevice                 The handle of the SPI device.
 * @param[in]   pTransceiver            The pointer to the SPI's transceiver data.
 *
 * @return      Status
 *              - #ADI_SPI_SUCCESS                  The device is successfully opened for the given instance.
 *              - #ADI_SPI_FAILURE                  A generalised API failure.
 *              - #ADI_SPI_INVALID_HANDLE [D]       An invalid device handle.
 *              - #ADI_SPI_QUEUE_FULL               The submitted transceiver queue is full.
 *              - #ADI_SPI_SIZE_ERROR               Buffer size is not a multiple of the transfer word size
 *              - #ADI_SPI_INVALID_POINTER          Transceiver pointer error
 *              - #ADI_SPI_DMA_OPEN_FAILED          SPI DMA open failure
 *              - #ADI_SPI_DMA_ERROR                DMA SPI configuration error
 *              - #ADI_SPI_DMA_TRANSCEIVER_ERROR    DMA transceiver has an error
 *
 * This function submits a transceiver to the SPI for data transfer via DMA. The DMA transceiver
 * is uni-directional and performs either a read once or write once DMA.  Consequently there is
 * no need for DMA descriptors. The transceiver buffers are simply processed one at a time by the
 * DMA controller.
 *
 * DMA control is enabled via the adi_spi_EnableDmaMode API. When using adi_spi_SubmitDmaTransceiver,
 * data flow is unidirectional and primarily used for bulk data transfers, the consequently the
 * following restrictions apply:
 * The transceivers prologue buffer must always be set to NULL.
 *
 * Since the transceiver in DMA mode is unidirection only either transmit buffer or receive buffer can
 * be configured at any one time.
 *
 * @sa          adi_spi_DmaTransceiver.
 * @sa          adi_spi_EnableDmaMode
 */
static ADI_SPI_RESULT adi_spi_SubmitDmaBuffer(ADI_SPI_HANDLE const hDevice, ADI_SPI_TRANSCEIVER *pTransceiver)
{
    /* assume a return code */
    ADI_SPI_RESULT Result = ADI_SPI_SUCCESS;
    ADI_DMA_RESULT ResultDMA ;
    uint16_t Data;

    /* Pointer to device instance */
    ADI_SPI *pDevice;
    /* dma transfer size */
    ADI_DMA_MSIZE eDmaSize;
    pDevice = (ADI_SPI *) hDevice;

    /* debug build only */
#if defined (ADI_DEBUG) /* must be in DMA mode */
    if (!pDevice->pDevData->bDmaMode)
    {
        return (ADI_SPI_DMA_ERROR);
    }
    if ((pTransceiver->pTransmitter != NULL) && (pTransceiver->pReceiver != NULL))
    {
        /* Spi DMA transceiver is unidirectional, only tx or rx direction not both */
        return (ADI_SPI_DMA_TRANSCEIVER_ERROR);
    }
    if (pTransceiver->pPrologue != NULL)
    {
        /* Spi DMA transceiver cannot have prologue data, bulk data transfer only */
        return (ADI_SPI_DMA_TRANSCEIVER_ERROR);
    }
#endif

    /* enable outbound dma */
    if (pTransceiver->pTransmitter != NULL)
    {

        /* set to transmit initiate DMA mode */
        Data = pDevice->pRegs->SPI_REG_CONTROL;
        Data &= (uint16_t) ~(BITM_SPI_CTL_TIMOD);
        pDevice->pRegs->SPI_REG_CONTROL = ((uint16_t) ENUM_SPI_CTL_TIMOD11 | Data);

        /* initiate a peripheral dma write to spi */
    	ResultDMA = adi_pdma_PeripheralWrite(pDevice->pDevData->hDMAChannel,
                                             pTransceiver->pTransmitter,
                                             (uint16_t) (pTransceiver->TransmitterBytes / pDevice->pDevData->BytesPerDMATransfer),
                                             (int16_t)pDevice->pDevData->BytesPerDMATransfer,
                                             0u,
                                             0);
    	if(ResultDMA == ADI_DMA_WORK_UNIT_FULL)
        {
     	   return ADI_SPI_QUEUE_FULL;
        }
    	else if(ResultDMA != ADI_DMA_SUCCESS)
    	{
    		return ADI_SPI_DMA_ERROR;
    	}
    	else
    	{
    		Result = ADI_SPI_SUCCESS;
    	}
    }
    /* enable inbound dma */
    /* MISA 14.10 else if (pTransceiver->pReceiver != NULL) */
    else
    {
        /* set to receive initiate DMA mode */
        Data = pDevice->pRegs->SPI_REG_CONTROL;
        Data &= (uint16_t) ~(BITM_SPI_CTL_TIMOD);
        pDevice->pRegs->SPI_REG_CONTROL = ((uint16_t) ENUM_SPI_CTL_TIMOD10 | Data);

        /* initiate a peripheral dma read of the spi */
    	ResultDMA = adi_pdma_PeripheralRead(pDevice->pDevData->hDMAChannel,
    			                            pTransceiver->pReceiver,
                                            (uint16_t)(pTransceiver->ReceiverBytes / pDevice->pDevData->BytesPerDMATransfer),
                                            (int16_t)pDevice->pDevData->BytesPerDMATransfer,
                                            0u,
                                            0);
    	if(ResultDMA == ADI_DMA_WORK_UNIT_FULL)
        {
     	   return ADI_SPI_QUEUE_FULL;
        }
    	else if(ResultDMA != ADI_DMA_SUCCESS)
    	{
    		return ADI_SPI_DMA_ERROR;
    	}
    	else
    	{
    		Result = ADI_SPI_SUCCESS;
    	}
    }

    /* enable dma transfer */
    if (adi_pdma_EnableXfer(pDevice->pDevData->hDMAChannel) != ADI_DMA_SUCCESS)
    {
        return ADI_SPI_DMA_ERROR;
    }
    /* Assert SPI select line */
    /* if software slave select is enabled, asset slave select */
    if (pDevice->pDevData->SpiSWSlaveSelectEnable)
    {
        /* if valid slave select */
        if (pDevice->pDevData->SpiSlaveSelect != ADI_SPI_SSEL_DISABLE)
        {
            /* Assert the slave select, assertion active low */
        	pDevice->pRegs->SPI_REG_FLAG &= ~(uint16_t)((uint16_t)pDevice->pDevData->SpiSlaveSelect << 8u);
        }
        else
        {
        	return ADI_SPI_CONFIGURATION_ERROR;
        }
    }

    /* enable the global SPI  */
    pDevice->pRegs->SPI_REG_CONTROL |= (uint16_t) ENUM_SPI_CTL_EN;

    /* Return */
    return Result;
}

/*!
 * @brief       The adi_spi_Close API closes a specified SPI device when in interrupt mode.
 *
 * @param[in]   hDevice     The handle of the SPI device.
 *
 * @return      Status
 *              - #ADI_SPI_SUCCESS              The device is successfully opened for the given instance.
 *              - #ADI_SPI_CLOSE_FAILED         The device has failed to close.
 */

static ADI_SPI_RESULT adi_spi_CloseInt(ADI_SPI_HANDLE const hDevice)
{
    /* assume a return code */
    ADI_SPI_RESULT Result = ADI_SPI_SUCCESS;
    /* Pointer to device instance */
    ADI_SPI *pDevice;
    /* device handle */
    pDevice = (ADI_SPI *) hDevice;

    /* Disable spi data interrupt handler */
    if (adi_int_EnableInt(pDevice->pDevData->SPIDataSID, false) != ADI_INT_SUCCESS)
    {
        return ADI_SPI_CLOSE_FAILED;
    }

    /* Unregister the spi data interrupt handler */
    if (adi_int_UninstallHandler(pDevice->pDevData->SPIDataSID) != ADI_INT_SUCCESS)
    {
        return ADI_SPI_CLOSE_FAILED;
    }

    /* return */
    return Result;
}

/*!
 * @brief       The adi_spi_Close API closes a specified SPI device when in DMA mode.
 *
 * @param[in]   hDevice     The handle of the SPI device.
 *
 * @return      Status
 *              - #ADI_SPI_SUCCESS              The device is successfully opened for the given instance.
 *              - #ADI_SPI_DMA_CLOSE_FAILED     A spi DMA closure failure.
 *
 */

static ADI_SPI_RESULT adi_spi_CloseDma(ADI_SPI_HANDLE const hDevice) {
    /* assume a return code */
    ADI_SPI_RESULT Result = ADI_SPI_SUCCESS;

    /* Pointer to device instance */
    ADI_SPI *pDevice;

    /* device handle */
    pDevice = (ADI_SPI *) hDevice;

    /* disable SIC SPI status interrupt */
    if (adi_pdma_DisableXfer(pDevice->pDevData->hDMAChannel) != ADI_DMA_SUCCESS)
    {
        return ADI_SPI_DMA_CLOSE_FAILED;
    }
    /* close dma channel/s */
    if (adi_pdma_Close(pDevice->pDevData->hDMAChannel, false) != ADI_DMA_SUCCESS)
    {
        return ADI_SPI_DMA_CLOSE_FAILED;
    }

    /* return */
    return Result;
}

/*********************************************************************
 Function:       ValidateSpiHandle

 Description:    This function validates the SPI handle.
 *********************************************************************/
static ADI_SPI_RESULT ValidateSpiHandle(ADI_SPI_HANDLE * const hDevice)
{
    /* index counter */
    uint8_t i;
    /* return code */
    ADI_SPI_RESULT Result = ADI_SPI_INVALID_HANDLE;

    /* all SPI device instances */
    for (i = 0u; i < (uint8_t) ADI_SPI_NUM_DEVICES; i++)
    {
        if (hDevice == (ADI_SPI_HANDLE) &aSpiDevice[i])
        {
            Result = ADI_SPI_SUCCESS; /* Found a valid device */
            break;
        }
    }

    /* Return */
    return Result;
}

/*********************************************************************
 Function:       ValidateTransceiver

 Description:    This function validates the parameters of a
 transceiver.  Prologue, transmit and receive buffers
 must have bytes counts that are a multiple of
 the SPI's data transfer size.
 *********************************************************************/
static ADI_SPI_RESULT ValidateTransceiver(ADI_SPI * const pDevice,  ADI_SPI_TRANSCEIVER *pTransceiver)
{
    /* return code */
    ADI_SPI_RESULT Result = ADI_SPI_SUCCESS;

    /* check pointer to transceiver */
    if (pTransceiver == NULL)
    {
        return (ADI_SPI_INVALID_POINTER);
    }

    /* there must be at least a prologue, or transmitter or receiver to process, otherwise transceiver error */
    if ((pTransceiver->pPrologue == NULL) && (pTransceiver->pTransmitter == NULL) && (pTransceiver->pReceiver == NULL))
    {
        return (ADI_SPI_INVALID_POINTER);
    }

    /* validate prologue only if there is one */
    if (pTransceiver->pPrologue != NULL)
    {
        /* check the buffer size is a multiple of the transfer size */
        if (pTransceiver->PrologueBytes % pDevice->pDevData->SpiTransferSize != 0u)
        {
            return (ADI_SPI_SIZE_ERROR);
        }
    }
    /* validate transmitter only if there is one */
    if (pTransceiver->pTransmitter != NULL)
    {
        /* check the buffer size is a multiple of the transfer size */
        if (pTransceiver->TransmitterBytes % pDevice->pDevData->SpiTransferSize != 0u)
        {
            return (ADI_SPI_SIZE_ERROR);
        }
    }
    /* validate receiver only if there is one */
    if (pTransceiver->pReceiver != NULL)
    {
        /* check the buffer size is a multiple of the transfer size */
        if (pTransceiver->ReceiverBytes % pDevice->pDevData->SpiTransferSize != 0u)
        {
            return (ADI_SPI_SIZE_ERROR);
        }
    }

    /* Return */
    return Result;
}

/*********************************************************************
 Function:       Update_SID_DMAChannelID

 Description:    This function queries the DMA manager for the SPI's
                 SID and DMA channel ID. This is necessary because the
                 allocation maybe changed.
 *********************************************************************/
static ADI_SPI_RESULT Update_SID_DMAChannelID(ADI_SPI * const pDevice)
{
    /* return code */
    ADI_SPI_RESULT Result = ADI_SPI_SUCCESS;
    ADI_DMA_CHANNEL_ID DMAChannelID;

    /* get the dma channel ID */
    if (adi_pdma_GetPeripheralMapping(pDevice->ePeripheralMapID, &pDevice->pDevData->DMAChannelID) != ADI_DMA_SUCCESS)
    {
        return ADI_SPI_DMA_OPEN_FAILED;
    }
    /* get the dma channel ID */
    if (adi_pdma_GetSID(pDevice->pDevData->DMAChannelID, &pDevice->pDevData->SPIDataSID) != ADI_DMA_SUCCESS)
    {
        return ADI_SPI_DMA_OPEN_FAILED;
    }

    /* Return */
    return Result;
}

/*********************************************************************
 Function:       SwitchTxTransceiver

 Description:    This function performs a switch over of the transmit
 transceiver. The parameters of transmit transfer instance
 (tx pointer and tx byte count) are switched between the primary and
 secondary transceivers.
 *********************************************************************/
static void SwitchTxTransceiver(ADI_SPI * const pDevice)
{
    ADI_SPI_TRANSCEIVER *pTransceiver;

    /* always reset transmit */
    pDevice->pDevData->Transfer.pTxData = NULL;
    pDevice->pDevData->Transfer.TxBytesToEmpty = 0u;

    /* special case, initial submission */
    if (pDevice->pDevData->pActiveTransceiver == NULL)
    {
        pTransceiver = pDevice->pDevData->pPrimaryTransceiver;
    }

    /* if active transceiver is primary, set secondary transceiver */
    else if (pDevice->pDevData->pActiveTransceiver == pDevice->pDevData->pPrimaryTransceiver)
    {
        pTransceiver = pDevice->pDevData->pSecondaryTransceiver;
    }
    /* if active transceiver is secondary, set primary transceiver */
    /* MISA 14.10 else if (pDevice->pDevData->pActiveTransceiver == pDevice->pDevData->pSecondaryTransceiver) */
    else
    {
        pTransceiver = pDevice->pDevData->pPrimaryTransceiver;
    }

    /* is there a pending prologue */
    if (pTransceiver->pPrologue != NULL)
    {
        /* set transmit transfer with prologue data */
        pDevice->pDevData->Transfer.pTxData = pTransceiver->pPrologue;
        pDevice->pDevData->Transfer.TxBytesToEmpty = pTransceiver->PrologueBytes;
    }
    /* is there a pending transmit */
    /* MISA 14.10 else if (pTransceiver->pTransmitter != NULL) */
    else
    {
        /* set transmit transfer with transmit data */
        pDevice->pDevData->Transfer.pTxData = pTransceiver->pTransmitter;
        pDevice->pDevData->Transfer.TxBytesToEmpty = pTransceiver->TransmitterBytes;
        /* set prologue flag as done */
        pDevice->pDevData->Transfer.bIsPrologueCompleted = true;
    }

}

/*********************************************************************
 Function:       SwitchRxTransceiver

 Description:    This function performs a switch over of the receive
 transceiver. The parameters of receive transfer instance
 (rx pointer and rx byte count) are switched between the primary and
 secondary transceivers.
 *********************************************************************/
static void SwitchRxTransceiver(ADI_SPI * const pDevice)
{
    ADI_SPI_TRANSCEIVER *pTransceiver;

    /* always reset receive */
    pDevice->pDevData->Transfer.pRxData = NULL;
    pDevice->pDevData->Transfer.RxBytesToFill = 0u;

    /* special case, initial submission */
    if (pDevice->pDevData->pActiveTransceiver == NULL)
    {
        pTransceiver = pDevice->pDevData->pPrimaryTransceiver;
    }

    /* if active transceiver is primary, set secondary transceiver */
    else if (pDevice->pDevData->pActiveTransceiver == pDevice->pDevData->pPrimaryTransceiver)
    {
        pTransceiver = pDevice->pDevData->pSecondaryTransceiver;
    }
    /* if active transceiver is secondary, set primary transceiver */
    /* MISA 14.10 else if (pDevice->pDevData->pActiveTransceiver == pDevice->pDevData->pSecondaryTransceiver) */
    else
    {
        pTransceiver = pDevice->pDevData->pPrimaryTransceiver;
    }


    /* set receive transfer with receive data only if there is data and no prologue */
    /* cannot receive until prologue has completed                                  */
    if ((pTransceiver->pReceiver != NULL) && (pTransceiver->pPrologue == NULL))
    {
        /* set receive transfer with receive data */
        pDevice->pDevData->Transfer.pRxData = pTransceiver->pReceiver;
        pDevice->pDevData->Transfer.RxBytesToFill = pTransceiver->ReceiverBytes;
        /* there is no prologue, set flag as done */
        pDevice->pDevData->Transfer.bIsPrologueCompleted = true;
    }
}

/*********************************************************************
 Function:       PostTransceiverCompleted

 Description:    This function is responsible for posting either
 callbacks or semaphores that signify the completion of a transceiver
 transfer.  It also updates the transceiver queue by updating the active
 transceiver to either the primary or secondary transceiver as well as
 free'ing up any transceiver that has been processed
 *********************************************************************/
static void PostTransceiverCompleted(ADI_SPI * const pDevice, void *pBuf)
{

    /* non-blocking mode */
    if(pDevice->pDevData->SpiMode == ADI_SPI_MODE_NONBLOCKING)
    {
        if (adi_osal_SemPost(pDevice->pDevData->hSemHandle) != ADI_OSAL_SUCCESS)
        {
            return;
        }

        /* In non-blocking mode                                         */
        /* Processed transceiver are not freed until adi_spi_GetBuffer  */
        /* bFreePrimaryOrSecondary (FALSE)                              */
        UpdateQueue(pDevice, false);
    }

    /* callbacks mode */
    if(pDevice->pDevData->SpiMode == ADI_SPI_MODE_CALLBACK)
    {
        /* if spi is in non-blocking mode, post callback with transceiver processed event */
        (pDevice->pDevData->pfCallback)(pDevice->pDevData->pCBParam,
        								(uint32_t) ADI_SPI_TRANSCEIVER_PROCESSED,
                                        pBuf);

        /* In callback mode                                             */
        /* Processed transceiver is freed immediately                   */
        /* bFreePrimaryOrSecondary (TRUE)                               */
        UpdateQueue(pDevice, true);
    }

    /* blocking mode  */
    if(pDevice->pDevData->SpiMode == ADI_SPI_MODE_BLOCKING)
    {
        if (adi_osal_SemPost(pDevice->pDevData->hSemHandle) != ADI_OSAL_SUCCESS)
        {
            return;
        }
        /* In blocking mode                                             */
        /* Processed transceiver is freed immediately                   */
        /*    bFreePrimaryOrSecondary (TRUE)                            */
        UpdateQueue(pDevice, true);

    }

    /* reset transfer data */
    pDevice->pDevData->Transfer.bIsPrologueCompleted = false;
    pDevice->pDevData->Transfer.bIsTransceiverCompleted = false;

    /* if active transceiver has no prologue, set prologue complete flag */
    if ((pDevice->pDevData->pActiveTransceiver != NULL) && (pDevice->pDevData->pActiveTransceiver->pPrologue == NULL))
    {
        pDevice->pDevData->Transfer.bIsPrologueCompleted = true;
    }

}

/*********************************************************************
 Function:       UpdateQueue

 Description:   This function updates the transceiver queue
 according the the spi mode of operation.  The boolean determine
 if a processed transceiver should be freed.  The function also updates
 the state of the active transceiver.

 Blocking mode freeing is immediate
 Non-blocking mode freeing is via the adi_spi_GetBuffer
 Callback mode freeing is immediate
 *********************************************************************/
static void UpdateQueue(ADI_SPI * const pDevice, bool bFreePrimaryOrSecondary)
{
    /* IF there is a primary and secondary transceiver, make the secondary active and free it, but then make it the primary */
    if((pDevice->pDevData->pPrimaryTransceiver != NULL) && (pDevice->pDevData->pSecondaryTransceiver != NULL))
    {
        pDevice->pDevData->pActiveTransceiver = pDevice->pDevData->pSecondaryTransceiver;
        /* IF bFreePrimaryOrSecondary TRUE free transceiver                     */
        if(bFreePrimaryOrSecondary == true)
        {
            /* make the secondary the primary */
            pDevice->pDevData->pPrimaryTransceiver = pDevice->pDevData->pSecondaryTransceiver;
            pDevice->pDevData->bPrimaryProcessed = pDevice->pDevData->bSecondaryProcessed;
            /* free up transceiver */
            pDevice->pDevData->pSecondaryTransceiver = NULL;
            pDevice->pDevData->bSecondaryProcessed = false;

        }
    }

    /* if there is only a primary, there is no next transceiver to activate, so free the primary */
    /* MISA 14.10 else((pDevice->pDevData->pPrimaryTransceiver != NULL) && (pDevice->pDevData->pSecondaryTransceiver == NULL)) */
    else
    {
        pDevice->pDevData->pActiveTransceiver = NULL;
        /* IF bFreePrimaryOrSecondary TRUE free transceiver */
        if( bFreePrimaryOrSecondary == true)
        {
        	/* free up transceiver */
            pDevice->pDevData->pPrimaryTransceiver = NULL;
            pDevice->pDevData->bPrimaryProcessed = false;
            pDevice->pDevData->bSecondaryProcessed = false;
        }
    }
}

/*********************************************************************
 Function:       ResetTransfer

 Description:    This function resets the parameters of the Transfer
 instance.
 *********************************************************************/
static void ResetTransfer(ADI_SPI * const pDevice)
{

    /* reset transfer data */
    pDevice->pDevData->Transfer.bIsPrologueCompleted = false;
    pDevice->pDevData->Transfer.bIsTransceiverCompleted = false;
    pDevice->pDevData->Transfer.pTxData = NULL;
    pDevice->pDevData->Transfer.pRxData = NULL;
    pDevice->pDevData->Transfer.TxBytesToEmpty = 0u;
    pDevice->pDevData->Transfer.RxBytesToFill = 0u;

}

/*********************************************************************
 Function:       LoadTxFifo

 Description:    This function loads the SPI transmit fifio
 with data from the transceiver's transmit buffer.
 The data can be either 8 bits or 16 bits in size.
 *********************************************************************/
static void LoadTxFifo(ADI_SPI * const pDevice)
{

    /* SPI tx data */
    uint16_t TxData;

    /* if valid pointer, else do nothing fall through */
    if (pDevice->pDevData->Transfer.pTxData != NULL)
    {

        /* fetch 2 bytes of data from tx buffer if transfer size is 2 */
        if (pDevice->pDevData->SpiTransferSize == 2u)
        {
            TxData = *(uint16_t *) pDevice->pDevData->Transfer.pTxData;
        }
        else
        {
            /* fetch 1 byte of data from tx buffer if transfer size is 1 */
            TxData = *pDevice->pDevData->Transfer.pTxData;
        }
        /* adjust transceiver tx buffer pointer */
        pDevice->pDevData->Transfer.pTxData += pDevice->pDevData->SpiTransferSize;
        /* decrement bytes in tranceiver's tx buffer by the no. bytes of the transfer size */
        pDevice->pDevData->Transfer.TxBytesToEmpty -= (uint32_t) pDevice->pDevData->SpiTransferSize;
        /* 16 bit write to tx fifo, some bytes may be ignored if transfer size is 8bit */
        pDevice->pRegs->SPI_REG_TDBR = TxData;
    }
}
/*********************************************************************
 Function:       LoadRxBuffer

 Description:    This function loads the transceiver with SPI
 receive data as long as there is a valid receive
 buffer pointer.  The data can be either 8 bits or
 16 bits in size.
 *********************************************************************/
static void LoadRxBuffer(ADI_SPI * const pDevice, uint16_t RxData)
{
    /* if valid pointer, else do nothing fall through */
    if (pDevice->pDevData->Transfer.pRxData != NULL)
    {
        /* write to rx buffer allowing for 2 byte transfer from rx fifo */
        if (pDevice->pDevData->SpiTransferSize == 2u)
        {
            *(uint16_t *) pDevice->pDevData->Transfer.pRxData = (uint16_t) RxData;
        }
        /* write to rx buffer allowing for 1 byte transfer from rx fifo */
        else
        {
            /* 1 byte transfers */
            *pDevice->pDevData->Transfer.pRxData = (uint8_t) RxData;
        }
        /* adjust rx buffer pointer */
        pDevice->pDevData->Transfer.pRxData += pDevice->pDevData->SpiTransferSize;
        /* decrement the number of empty bytes left in the rx buffer */
        pDevice->pDevData->Transfer.RxBytesToFill -= (uint32_t) pDevice->pDevData->SpiTransferSize;
    }
    /* when prologue is finished, load receiver */
    else
    {
        if (pDevice->pDevData->Transfer.bIsPrologueCompleted)
        {
            /* load receive data for transmit transfer */
            pDevice->pDevData->Transfer.pRxData = pDevice->pDevData->pActiveTransceiver->pReceiver;
            pDevice->pDevData->Transfer.RxBytesToFill = pDevice->pDevData->pActiveTransceiver->ReceiverBytes;
        }
    }
}

/*********************************************************************
 Function:       CheckForTransferCompletion

 Description:    This function checks to see if the data transfer
 of the transceiver is complete.  Completion is
 signalled by bIsTransceiverCompleted and can occur
 when;
 1. The prologue is completed AND either the transmitter
 or receiver byte count is processed.
 2. If the prologue has finished and there is no
 subsequent tx and rx data for process.
 *********************************************************************/
static void CheckForTransferCompletion(ADI_SPI * const pDevice)
{

    /* flag transceiver complete if either the tx or rx counts are empty when they are valid */
    if (((pDevice->pDevData->Transfer.TxBytesToEmpty == (uint32_t) 0) &&
         (pDevice->pDevData->Transfer.pTxData != NULL)) ||
        ((pDevice->pDevData->Transfer.RxBytesToFill == pDevice->pDevData->SpiTransferSize) &&
         (pDevice->pDevData->Transfer.pRxData != NULL)))
    {
        /* check case where prologue data and payload data is complete */
        if (pDevice->pDevData->Transfer.bIsPrologueCompleted)
        {
            /* set transceiver transfer complete flag */
            pDevice->pDevData->Transfer.bIsTransceiverCompleted = true;
        }
        /* only the prologue is complete */
        else
        {
            /* set prologue transfer complete flag to true */
            pDevice->pDevData->Transfer.bIsPrologueCompleted = true;
            /* load transmit data for transmit transfer */
            pDevice->pDevData->Transfer.pTxData = pDevice->pDevData->pActiveTransceiver->pTransmitter;
            pDevice->pDevData->Transfer.TxBytesToEmpty = pDevice->pDevData->pActiveTransceiver->TransmitterBytes;

            /* if there is neither tx or rx data, flag completion */
            if ((pDevice->pDevData->pActiveTransceiver->pTransmitter == NULL) &&
                (pDevice->pDevData->pActiveTransceiver->pReceiver == NULL))
            {
                /* set transceiver transfer complete flag */
                pDevice->pDevData->Transfer.bIsTransceiverCompleted = true;
            }
        }
    }
}

/*********************************************************************
 Function:       DisableTransceiver

 Description:    This function disables SPI upon data completion of
 the transceiver.
 *********************************************************************/
static void DisableTransceiver(ADI_SPI * const pDevice)
{


    /* De-assert SPI select line */
    /* if software slave select is enabled, asset slave select */
    if (pDevice->pDevData->SpiSWSlaveSelectEnable)
    {
        /* if valid slave select */
        if (pDevice->pDevData->SpiSlaveSelect != ADI_SPI_SSEL_DISABLE)
        {
            /* De-assert the slave select, de-assertion active high, assertion active low */
            pDevice->pRegs->SPI_REG_FLAG |=  ((uint16_t) pDevice->pDevData->SpiSlaveSelect  << 8u);
        }
    }

    /* disable the global SPI */
    pDevice->pRegs->SPI_REG_CONTROL &= (uint16_t) ~(ENUM_SPI_CTL_EN);

}

/*********************************************************************
 Function:       Spi_Data_Interrupt_Handler

 Description:    This is the SPI data interrupt handler.
 *********************************************************************/

static void Spi_Data_Interrupt_Handler(uint32_t SID, void *pCBParam)
{
    /* status register */
    uint16_t Status;
    /* Pointer to device instance */
    ADI_SPI *pDevice = (ADI_SPI *) pCBParam;

#ifdef ADI_DEBUG
    /*  check device */
    if(pDevice == NULL)
    {
        return;
    }
#endif /* ADI_DEBUG */

    /* Get the SPI Status register value */
    Status = pDevice->pRegs->SPI_REG_STATUS;

    /* Non-DMA mode */
    if (pDevice->pDevData->bDmaMode == false)
    {
        /* if transceiver is processing, not flagged as completed */
        if (pDevice->pDevData->Transfer.bIsTransceiverCompleted != true)
        {
            /* load tx fifo with tx transceiver data */
            LoadTxFifo(pDevice);
            /* always read receiver fifo, regardless if there is a valid receive buffer in transceiver  */
            LoadRxBuffer(pDevice, pDevice->pRegs->SPI_REG_RDBR);
            /* check for transfer completion cases */
            CheckForTransferCompletion(pDevice);
        }
        /* transceiver flagged as completed */
        else
        {

        	/* either the primary or secondary has been processed at this point, flag it */
        	if(pDevice->pDevData->bPrimaryProcessed == false)
        	{
        		pDevice->pDevData->bPrimaryProcessed = true;
        	}
        	else if(pDevice->pDevData->bSecondaryProcessed == false)
        	{
        		pDevice->pDevData->bSecondaryProcessed = true;
        	}
        	else
        	{
        		pDevice->pDevData->bPrimaryProcessed = true;
        		pDevice->pDevData->bSecondaryProcessed = true;
        	}

            /* switch over tx and/or rx transceiver buffer if there is one that is unprocessed */
            if(((pDevice->pDevData->pPrimaryTransceiver != NULL) && (pDevice->pDevData->bPrimaryProcessed == false)) ||
               ((pDevice->pDevData->pSecondaryTransceiver != NULL) && (pDevice->pDevData->bSecondaryProcessed == false)))

            {
                /* switch to next tx transceiver */
                SwitchTxTransceiver(pDevice);
                /* load tx fifo with tx transceiver data */
                LoadTxFifo(pDevice);
                /* read the last rx data from the current rx transceiver */
                LoadRxBuffer(pDevice, pDevice->pRegs->SPI_REG_RDBR);
                /* switch to the next rx transceiver */
                SwitchRxTransceiver(pDevice);
            }
            /* switch transceiver to start a new transceiver transfer on the secondary */
            else
            {
                /* disable transceiver, don't want to initiate another SPI transfer by reading SPI_REG_RDBR */
                DisableTransceiver(pDevice);

                /* read the last rx data and load it into the  current rx transceiver   */
                LoadRxBuffer(pDevice, pDevice->pRegs->SPI_REG_RDBR);
                /* reset the transceiver transfer parameters */
                ResetTransfer(pDevice);
            }
            /* post transceiver completed via semaphore or callback */
            PostTransceiverCompleted(pDevice, pDevice->pDevData->pActiveTransceiver);
        }
    }
    /* DMA mode */
    else
    {
        /* should not get here */
    }

    /* clear status */
    pDevice->pRegs->SPI_REG_STATUS = (Status & (uint16_t)ADI_SPI_STATUS_DATA_MASK);
}

/*********************************************************************
 Function:       Spi_Error_Interrupt_Handler

 Description:    This is the SPI error interrupt handler.
 *********************************************************************/
static void Spi_Error_Interrupt_Handler(uint32_t SID, void *pCBParam)
{
    /* status register value */
    uint16_t     Status;
    uint16_t i;

    /* Pointer to device instance */
    ADI_SPI *pDevice = (ADI_SPI *) pCBParam;

    ADI_SPI_EVENT Event;

#ifdef ADI_DEBUG
    /*  check device */
    if(pDevice == NULL)
    {
        return;
    }
#endif /* ADI_DEBUG */

    /* Get the SPI Status register value */
    Status = pDevice->pRegs->SPI_REG_STATUS;
    /* clear the status register */
    pDevice->pRegs->SPI_REG_STATUS = (uint16_t)ENUM_SPI_HW_ERROR;

    /* check if any hardware errors have occurred */
    if((Status & (uint16_t)ENUM_SPI_HW_ERROR) != 0u)
    {
        /* accumulate status events, these events are passed to application following a GetBuffer */
        pDevice->pDevData->SpiStatusEvent |= Status;

            /* post a callback */
            if(pDevice->pDevData->SpiMode == ADI_SPI_MODE_CALLBACK)
            {
            (pDevice->pDevData->pfCallback)(pDevice->pDevData->pCBParam, (uint32_t)ADI_SPI_HW_ERR, NULL);
        }
    }

    return;
}

/*********************************************************************
 Function:       adi_spi_DMACallback

 Description:    This function handles any callback initiated from
 the DMA controller.
 *********************************************************************/
static void SpiDma_Callback(void *pCBParam, uint32_t Event, void *pArg)
{

    /* Pointer to device instance */
    ADI_SPI *pDevice = (ADI_SPI *) pCBParam;

#ifdef ADI_DEBUG
    /*  check device */
    if(pDevice == NULL)
    {
        return;
    }
#endif /* ADI_DEBUG */

    switch ((ADI_SPI_EVENT) Event)
    {
        /* The given buffer processed */
        case (ADI_SPI_EVENT) ADI_DMA_EVENT_BUFFER_PROCESSED:

            /* tx spi DMA mode requires a specific transfer completion sequence */
            if(pDevice->pDevData->pActiveTransceiver->pTransmitter !=NULL)
            {
                /* refer to ADSP-BF533 hardware reference manual                */
                /* must flush spi dma fifo (4 words deep) before disabling spi  */
                /* poll for two consecutive low transistions of txs status      */
                /* then check spif status is complete before spi is disabled    */
                while(!(pDevice->pRegs->SPI_REG_STATUS & (uint16_t) ENUM_SPI_TXS_FULL))
                {
                	;
                }
                while( (pDevice->pRegs->SPI_REG_STATUS & (uint16_t) ENUM_SPI_TXS_FULL))
                {
                	;
                }
                while(!(pDevice->pRegs->SPI_REG_STATUS & (uint16_t) ENUM_SPI_TXS_FULL))
                {
                	;
                }
                /*while( (pDevice->pRegs->SPI_REG_STATUS && ENUM_SPI_TXS_FULL));*/
                while(!(pDevice->pRegs->SPI_REG_STATUS & (uint16_t) ENUM_SPI_SPIF_HI))
                {
                	;
                }
            }
            /* if rx spi dma mode */
            /* MISA 14.10 else if(pDevice->pDevData->pActiveTransceiver->pReceiver !=NULL) */
            else
            {
            	/* in receive mode, check for completion */
            	while(!(pDevice->pRegs->SPI_REG_STATUS & (uint16_t) ENUM_SPI_SPIF_HI))
            	{
            		;
            	}
            }

			/* set the transceiver processed flag */
        	if(pDevice->pDevData->bPrimaryProcessed == false)
        	{
        		pDevice->pDevData->bPrimaryProcessed = true;
        	}
        	/* MISA 14.10 else if(pDevice->pDevData->bSecondaryProcessed == false) */
        	else
        	{
        		pDevice->pDevData->bSecondaryProcessed = true;
        	}
        	/* disable ppi and dma if there is no secondary transceiver, or 					*/
        	/* if there is a processed secondary yet to be de-queued with a adi_spi_GetBuffer 	*/

        	if((pDevice->pDevData->pSecondaryTransceiver == NULL) ||
        	   ((pDevice->pDevData->pSecondaryTransceiver != NULL) && (pDevice->pDevData->bSecondaryProcessed == true)))
            {
                /* disable spi and post processed transceiver */
                DisableTransceiver(pDevice);

                /* disable DMA */
                if (adi_pdma_DisableXfer(pDevice->pDevData->hDMAChannel) != ADI_DMA_SUCCESS)
                {
                    break;
                }
        		/* reset the transceiver transfer parameters */
                ResetTransfer(pDevice);

            }
            /* post transceiver completed via semaphore or callback */
            PostTransceiverCompleted(pDevice, pDevice->pDevData->pActiveTransceiver);

            break;
        default:
            /* don't care about other events */
            break;
    }
    return;
}


/*@}*/

#ifdef _MISRA_RULES
#pragma diag(pop)
#endif /* _MISRA_RULES */
