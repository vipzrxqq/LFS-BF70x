
/* $Id: adi_spi_bf6xx.c 21389 2015-03-10 18:20:47Z sfernan $ */
/*********************************************************************************

Copyright(c) 2010-2014 Analog Devices, Inc. All Rights Reserved.

This software is proprietary and confidential.  By using this software you agree
to the terms of the associated Analog Devices License Agreement.

*********************************************************************************/
/*!
* @file      adi_spi_bf6xx.c
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
#pragma diag(suppress:misra_rule_8_5:"There shall be no definitions of objects or functions in a header file.")
#pragma diag(suppress:misra_rule_5_1:"Allow identifiers to be longer than 31 characters.")
#pragma diag(suppress:misra_rule_8_7:"Allow Objects to be defined at block scope if they are only accessed from within a single function.")
#pragma diag(suppress:misra_rule_13_7:"Allow to add asserts for memory size macros")
#pragma diag(suppress:misra_rule_14_7:"A function shall have a single point of exit at the end of the function.")
#pragma diag(suppress:misra_rule_17_4:"Array indexing shall be the only allowed form of pointer arithmetic.")
#pragma diag(suppress:misra_rule_19_14:"The defined preprocessor operator shall only be used in one of the two standard forms.")
#endif /* _MISRA_RULES */

#if defined(ADI_CODE_IN_ROM)
#include "../rom/adi_rom_def.h"
#else
#define CONST const
#endif


#include "adi_spi_data_bf6xx.c"
#include <assert.h>

/* Tx and Rx Fifo has 5 watermark levels, at 0% 25%, 50%, 75%, 100%, making each watermark block 2 bytes in size */
#define ADI_SPI_WATERMARKBYTESIZE  	(2u)
#define ENUM_SPI_HW_ERROR  		  	(ADI_SPI_HW_ERR_RX_OVERUN | ADI_SPI_HW_ERR_TX_UNDERRUN | ADI_SPI_HW_ERR_TX_COLLISION | ADI_SPI_HW_ERR_MODE)

/* Function declarations */
/* Interrupt handlers */
static void Spi_Error_Interrupt_Handler(uint32_t ID, void *pCBParam);
static void Spi_TxData_Interrupt_Handler(uint32_t SID, void *pCBParam);
static void Spi_RxData_Interrupt_Handler(uint32_t SID, void *pCBParam);
/* SPI DMA callbacks */
static void SpiTxDma_Callback(void *pCBParam, uint32_t Event, void *pArg);
static void SpiRxDma_Callback(void *pCBParam, uint32_t Event, void *pArg);
/* Submit transceiver buffer functions for interrupt and DMA driven */
static ADI_SPI_RESULT adi_spi_SubmitIntBuffer(ADI_SPI_HANDLE const hDevice, ADI_SPI_TRANSCEIVER *pTransceiver);
static ADI_SPI_RESULT adi_spi_SubmitDmaBuffer(ADI_SPI_HANDLE const hDevice, ADI_SPI_TRANSCEIVER *pTransceiver);
/* SPI close functions for interrupt and DMA driven */
static ADI_SPI_RESULT adi_spi_CloseInt(ADI_SPI_HANDLE const hDevice);
static ADI_SPI_RESULT adi_spi_CloseDma(ADI_SPI_HANDLE const hDevice);

#if defined (ADI_DEBUG)
static ADI_SPI_RESULT ValidateSpiHandle(ADI_SPI_HANDLE * const hDevice);
static ADI_SPI_RESULT ValidateTransceiver(ADI_SPI * const pDevice, ADI_SPI_TRANSCEIVER *pTransceiver);
#endif
static ADI_SPI_RESULT StartInterruptTransceiver(ADI_SPI *const pDevice);
static void LoadTxFifo(ADI_SPI *const pDevice, uint32_t Status);
static void LoadRxBuffer(ADI_SPI *const pDevice, uint32_t Status);
static void PostTransceiverCompleted(ADI_SPI * const pDevice, void *pBuf, ADI_SPI_EVENT Event);
static void UpdateQueue(ADI_SPI * const pDevice, bool bFreePrimaryOrSecondary);

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

ADI_SPI_RESULT adi_spi_Open(uint32_t        DeviceNumber,
                            void            *pDeviceMemory,
                            uint32_t        MemorySize,
                            ADI_SPI_HANDLE  *phDevice)
{
    /* assume a return code */
    ADI_SPI_RESULT Result = ADI_SPI_SUCCESS;
    /* SPI device */
    ADI_SPI    *pDevice;
    /* debug build only */
#if defined (ADI_DEBUG)
    /* check if device ID is invalid */
    if(DeviceNumber >= (uint32_t)ADI_SPI_NUM_DEVICES)
    {
        /* Bad Device Number */
        return ADI_SPI_INVALID_DEVICE_NUM;
    }
    /* Check if the given pointer to device handle is valid */
    if(phDevice == NULL)
    {
        return ADI_SPI_INVALID_POINTER;
    }
#endif

    /* get SPI device instance */
#if !defined(ADI_CODE_IN_ROM)
    pDevice = &aSpiDevice[DeviceNumber];
#else
    pDevice = &pram_for_rom_Code->aSpiDevice[DeviceNumber];
#endif

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
        pDevice->pDevData->bDmaSupported = true;
        /* DMA for tx and rx */
        pDevice->pDevData->pSpiDMAMemory = (uint8_t *)pDevice->pDevData + sizeof(ADI_SPI_DEV_DATA );
    }

    /* asserts to validate the memory size macros */
    assert(ADI_SPI_INT_MEMORY_SIZE == sizeof(ADI_SPI_DEV_DATA));
    assert(ADI_SPI_DMA_MEMORY_SIZE == (ADI_SPI_INT_MEMORY_SIZE + (ADI_DMA_CHANNEL_REQ_MEMORY * 2u)));

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
    pDevice->pDevData->bManualSlaveSelect = false;
    pDevice->pDevData->eMode = ADI_SPI_TXRX_MODE;
    /* default operation mode configuration */
    pDevice->pDevData->SpiTransferSize = 1u;
    pDevice->pDevData->hSemHandle = NULL;
    /* set transceiver pointers to NULL */
    pDevice->pDevData->pActiveTransceiver = NULL;
    pDevice->pDevData->pPrimaryTransceiver = NULL;
    pDevice->pDevData->pActiveTransceiver = NULL;
    pDevice->pDevData->bPrimaryProcessed = false;
    pDevice->pDevData->bSecondaryProcessed = false;
    /* operating mode of spi is set to default, none */
    pDevice->pDevData->SpiMode = ADI_SPI_MODE_NONE;
    /* initialise spi registers to their default values */
    pDevice->pRegs->SPI_CONTROL   = 0x00000050u;
    pDevice->pRegs->SPI_RXCONTROL = 0x00000000u;
    pDevice->pRegs->SPI_TXCONTROL = 0x00000000u;
    pDevice->pRegs->SPI_CLOCK     = 0x00000000u;
    pDevice->pRegs->SPI_DELAY     = 0x00000301u;
    pDevice->pRegs->SPI_SSEL      = 0x0000FE00u;
#if defined (WA_19000038) && WA_19000038   
    pDevice->pRegs->SPI_SSEL      = 0x0000FE00u;
#endif
    pDevice->pRegs->SPI_RWC       = 0x00000000u;
    pDevice->pRegs->SPI_RWCR      = 0x00000000u;
    pDevice->pRegs->SPI_TWC       = 0x00000000u;
    pDevice->pRegs->SPI_TWCR      = 0x00000000u;

    /* by default set the transceiver submission function to an interrupt driven function */
    pDevice->pDevData->FuncTable.pfSpiSubmitBuffer = &adi_spi_SubmitIntBuffer;
    /* by default set the spi close function to an interrupt closure function */
    pDevice->pDevData->FuncTable.pfSpiClose = &adi_spi_CloseInt;

    /* create static semaphore */
    if (adi_osal_SemCreateStatic(&pDevice->pDevData->SpiSemMemory,
                                 ADI_OSAL_MAX_SEM_SIZE_CHAR,
                                 &pDevice->pDevData->hSemHandle,
                                 0u) != ADI_OSAL_SUCCESS)
    {
        return  ADI_SPI_SEMAPHORE_FAILED;
    }

    /* register the spi error status interrupt handler with SEC */
    if(adi_int_InstallHandler(pDevice->SpiStatusSID,
    		                  Spi_Error_Interrupt_Handler,
    		                  pDevice,
                              true)
                              != ADI_INT_SUCCESS)
    {
    	return ADI_SPI_INTERRUPT_FAILED;
    }
    /* register the spi tx data interrupt handler with SEC */
    if(adi_int_InstallHandler(pDevice->SpiTransmitterSID,
    		                  Spi_TxData_Interrupt_Handler,
    		                  pDevice,
                              true)
                              != ADI_INT_SUCCESS)
    {
    	return ADI_SPI_INTERRUPT_FAILED;
    }
    /* register the spi rx data interrupt handler with SEC */
    if(adi_int_InstallHandler(pDevice->SpiReceiverSID,
    		                  Spi_RxData_Interrupt_Handler,
    		                  pDevice,
                              true)
                              != ADI_INT_SUCCESS)
    {
    	return ADI_SPI_INTERRUPT_FAILED;
    }
    /* Pass SPI Device handle to client */
    *phDevice = (ADI_SPI_HANDLE)pDevice;
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
    if ( ValidateSpiHandle(hDevice) != ADI_SPI_SUCCESS)
    {
        return ADI_SPI_INVALID_HANDLE;
    }
#endif /* ADI_DEBUG */
    /* device handle */
    pDevice = (ADI_SPI *)hDevice;
    /* close the spi's the DMA or the data interrupt depending on the function pointer */
    Result = pDevice->pDevData->FuncTable.pfSpiClose(pDevice);
    if (Result != ADI_SPI_SUCCESS)
    {
        return Result;
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
    pDevice->pDevData->hTxDMAChannel = NULL;
    pDevice->pDevData->hRxDMAChannel = NULL;
    pDevice->pDevData->hSemHandle = NULL;
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
    if ( ValidateSpiHandle(hDevice) != ADI_SPI_SUCCESS)
    {
        return ADI_SPI_INVALID_HANDLE;
    }
#endif /* ADI_DEBUG */

    pDevice = (ADI_SPI *) hDevice;

    /* make sure this API only toggles the state of the DMA mode            */
    /* we should never enable/disable DMA if it is already enabled/disabled */
    if (bDMAEnable == pDevice->pDevData->bDmaMode)
    {
        return Result;
    }
    if(pDevice->pDevData->bDmaSupported == false)
    {
    	return ADI_SPI_INSUFFICIENT_MEMORY;
    }
    /* enable the interrupt */
    if (bDMAEnable == true)
    {
        /* check that the DMA channel is not already opened */
        if (!pDevice->pDevData->bDmaMode)
        {
            /* set DMA mode flag */
            pDevice->pDevData->bDmaMode = true;
            /* set the transceiver submission function to a dma driven function */
            pDevice->pDevData->FuncTable.pfSpiSubmitBuffer = &adi_spi_SubmitDmaBuffer;
            /* set the spi close function to a spi dma closure function */
            pDevice->pDevData->FuncTable.pfSpiClose = &adi_spi_CloseDma;
        }
        if(adi_int_EnableInt(pDevice->SpiTransmitterSID, false) != ADI_INT_SUCCESS)
        {
        	return ADI_SPI_INTERRUPT_FAILED;
        }
        if(adi_int_EnableInt(pDevice->SpiReceiverSID, false) != ADI_INT_SUCCESS)
        {
        	return ADI_SPI_INTERRUPT_FAILED;
        }
        if(adi_int_UninstallHandler(pDevice->SpiTransmitterSID) != ADI_INT_SUCCESS)
        {
             return ADI_SPI_CLOSE_FAILED;
        }
        if(adi_int_UninstallHandler(pDevice->SpiReceiverSID) != ADI_INT_SUCCESS)
        {
             return ADI_SPI_CLOSE_FAILED;
        }
        /* open dma channel/s */
        if (adi_pdma_Open(pDevice->eDMATxChannelID,
                          pDevice->pDevData->pSpiDMAMemory,
                          &pDevice->pDevData->hTxDMAChannel,
                          SpiTxDma_Callback,
                          pDevice) != ADI_DMA_SUCCESS)
        {
            return ADI_SPI_DMA_OPEN_FAILED;
        }
        /* open dma channel/s */
        if (adi_pdma_Open(pDevice->eDMARxChannelID,
                          pDevice->pDevData->pSpiDMAMemory + ADI_DMA_CHANNEL_REQ_MEMORY,
                          &pDevice->pDevData->hRxDMAChannel,
                          SpiRxDma_Callback,
                          pDevice) != ADI_DMA_SUCCESS)
        {
            return ADI_SPI_DMA_OPEN_FAILED;
        }
        /* set default DMA transfer sizes, DMA PSize, DMA MSize for Tx/Rx*/
        pDevice->pDevData->BytesPerDMATransfer = 1u;
        if(adi_pdma_SetPSize(pDevice->pDevData->hTxDMAChannel, ADI_DMA_PSIZE_1BYTE) != ADI_DMA_SUCCESS)
        {
            return ADI_SPI_DMA_ERROR;
        }
        if(adi_pdma_SetMSize(pDevice->pDevData->hTxDMAChannel, ADI_DMA_MSIZE_1BYTE) != ADI_DMA_SUCCESS)
        {
            return ADI_SPI_DMA_ERROR;
        }
        if(adi_pdma_SetPSize(pDevice->pDevData->hRxDMAChannel, ADI_DMA_PSIZE_1BYTE) != ADI_DMA_SUCCESS)
        {
            return ADI_SPI_DMA_ERROR;
        }
        if(adi_pdma_SetMSize(pDevice->pDevData->hRxDMAChannel, ADI_DMA_MSIZE_1BYTE) != ADI_DMA_SUCCESS)
        {
            return ADI_SPI_DMA_ERROR;
        }

        /* enable DMA sync bit for tx and rx */
        if(adi_pdma_SetSync(pDevice->pDevData->hTxDMAChannel, true) != ADI_DMA_SUCCESS)
        {
            return ADI_SPI_DMA_ERROR;
        }
        if(adi_pdma_SetSync(pDevice->pDevData->hRxDMAChannel, true) != ADI_DMA_SUCCESS)
        {
            return ADI_SPI_DMA_ERROR;
        }
    }
    else
    {
        /* if in DMA mode close channel */
        if (pDevice->pDevData->bDmaMode == true)
        {
            /* set DMA mode flag */
            pDevice->pDevData->bDmaMode = false;

            /* set the transceiver submission function to an interrupt driven function */
            pDevice->pDevData->FuncTable.pfSpiSubmitBuffer = &adi_spi_SubmitIntBuffer;

            /* set the spi close function to a spi dma closure function */
            pDevice->pDevData->FuncTable.pfSpiClose = &adi_spi_CloseInt;

            /* disable and close both SPI DMA channels */
            if (adi_pdma_DisableXfer(pDevice->pDevData->hTxDMAChannel) != ADI_DMA_SUCCESS)
            {
                return ADI_SPI_DMA_CLOSE_FAILED;
            }
            if (adi_pdma_Close(pDevice->pDevData->hTxDMAChannel, false) != ADI_DMA_SUCCESS)
            {
                return ADI_SPI_DMA_CLOSE_FAILED;
            }
            if (adi_pdma_DisableXfer(pDevice->pDevData->hRxDMAChannel) != ADI_DMA_SUCCESS)
            {
                return ADI_SPI_DMA_CLOSE_FAILED;
            }
            if (adi_pdma_Close(pDevice->pDevData->hRxDMAChannel, false) != ADI_DMA_SUCCESS)
            {
                return ADI_SPI_DMA_CLOSE_FAILED;
            }
            /* register the spi tx data interrupt handler with SEC */
            if(adi_int_InstallHandler(pDevice->SpiTransmitterSID,
            		                  Spi_TxData_Interrupt_Handler,
            		                  pDevice,
                                      true)
                                      != ADI_INT_SUCCESS)
            {
            	return ADI_SPI_INTERRUPT_FAILED;
            }
            /* register the spi rx data interrupt handler with SEC */
            if(adi_int_InstallHandler(pDevice->SpiReceiverSID,
            		                  Spi_RxData_Interrupt_Handler,
            		                  pDevice,
                                      true)
                                      != ADI_INT_SUCCESS)
            {
            	return ADI_SPI_INTERRUPT_FAILED;
            }
        }
    }
    /* Return */
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
 *              - #ADI_SPI_CONFIGURATION_ERROR  Must be in DMA mode.
 *
 * Sets the size of data that is transferred via DMA. The DMA transfer occurs between memory and the
 * SPI's Tx/Rx fifo.  If this API is not called and the SPI is in DMA mode, the default setting is
 * ADI_SPI_DMA_TRANSFER_8BIT. The DMA transfer size cannot be larger than the SPI's word transfer
 * size set via adi_spi_SetWordSize (default ADI_SPI_TRANSFER_8BIT).  To set the DMA transfer size
 * greater than the default of ADI_SPI_DMA_TRANSFER_8BIT, adi_spi_SetWordSize must be called first,
 * to ensure the SPI word size is greater or equal to the DMA transfer size , followed by a call to
 * adi_spi_SetDmaTransferSize.
 *
 * @sa          adi_spi_SetWordSize().
 */

ADI_SPI_RESULT adi_spi_SetDmaTransferSize(ADI_SPI_HANDLE const hDevice, ADI_SPI_DMA_TRANSFER_SIZE eDMASize)
{
    /* assume a return code */
    ADI_SPI_RESULT Result = ADI_SPI_SUCCESS;
    /* Pointer to device instance */
    ADI_SPI *pDevice;
    ADI_DMA_PSIZE ePSize;
    ADI_DMA_MSIZE eMSize;
    uint8_t StoreBytesPerDMATransfer;
    /* debug build only */
#if defined (ADI_DEBUG)

    /* validate the given handle */
    if ( ValidateSpiHandle(hDevice) != ADI_SPI_SUCCESS)
    {
        return ADI_SPI_INVALID_HANDLE;
    }
#endif
    pDevice = (ADI_SPI *) hDevice;

    /* can only do this if DMA mode is enabled */
    if(pDevice->pDevData->bDmaMode ==  false)
    {
    	return ADI_SPI_CONFIGURATION_ERROR;
    }
    /* temporarily store BytesPerDMATransfer in case of error */
    StoreBytesPerDMATransfer = pDevice->pDevData->BytesPerDMATransfer;

    /* determine the number of bytes in the word transfer size */
    switch (eDMASize)
    {
        case ADI_SPI_DMA_TRANSFER_8BIT:
            pDevice->pDevData->BytesPerDMATransfer = 1u;
            eMSize = ADI_DMA_MSIZE_1BYTE;
            ePSize = ADI_DMA_PSIZE_1BYTE;
            break;
        case ADI_SPI_DMA_TRANSFER_16BIT:
            pDevice->pDevData->BytesPerDMATransfer = 2u;
            eMSize = ADI_DMA_MSIZE_2BYTES;
            ePSize = ADI_DMA_PSIZE_2BYTES;
            break;
        case ADI_SPI_DMA_TRANSFER_32BIT:
            pDevice->pDevData->BytesPerDMATransfer = 4u;
            eMSize = ADI_DMA_MSIZE_4BYTES;
            ePSize = ADI_DMA_PSIZE_4BYTES;
            break;
        default:
            Result = ADI_SPI_BAD_PARAMETER;
            break;
    }

    if (Result == ADI_SPI_SUCCESS)
    {
		/* DMA transfer size can never be greater than SPI word transfer size */
		if(pDevice->pDevData->BytesPerDMATransfer > pDevice->pDevData->SpiTransferSize)
		{
			/* restore BytesPerDMATransfer */
			pDevice->pDevData->BytesPerDMATransfer = StoreBytesPerDMATransfer;
			return ADI_SPI_CONFIGURATION_ERROR;
		}

		/* Set the PSize, MSize for Tx/Rx DMA */
		if(adi_pdma_SetPSize(pDevice->pDevData->hTxDMAChannel, ePSize) != ADI_DMA_SUCCESS)
		{
			return ADI_SPI_DMA_ERROR;
		}
		if(adi_pdma_SetMSize(pDevice->pDevData->hTxDMAChannel, eMSize) != ADI_DMA_SUCCESS)
		{
			return ADI_SPI_DMA_ERROR;
		}
		if(adi_pdma_SetPSize(pDevice->pDevData->hRxDMAChannel, ePSize) != ADI_DMA_SUCCESS)
		{
			return ADI_SPI_DMA_ERROR;
		}
		if(adi_pdma_SetMSize(pDevice->pDevData->hRxDMAChannel, eMSize) != ADI_DMA_SUCCESS)
		{
			return ADI_SPI_DMA_ERROR;
		}
    }

    /* Return */
    return Result;
}


/*!
 * @brief       The adi_spi_RegisterCallback API registers an optional callback function
 *              for the SPI device.
 *

 * @param[in]   hDevice     The handle of the SPI device.
 * @param[in]   pfCallback  The application supplied callback which will be called to notify device
 *                          related events.
 * @param[in]   pCBParam    The application supplied callback parameter which can be passed back in
 *                          the callback function.
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
    pDevice = (ADI_SPI *)hDevice;
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
    return Result;
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

    pDevice = (ADI_SPI *)hDevice;

/* debug build only */
#if defined (ADI_DEBUG)

    /* validate the transceiver and its buffers */
    Result = ValidateTransceiver(pDevice, pTransceiver);
    if(Result != ADI_SPI_SUCCESS)
    {
        return ADI_SPI_INVALID_HANDLE;
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
    /* if there is no secondary, only in interrupt mode                                     */
    /* DMA mode does not use secondary because prologue and tx/rx buffer fill the DMA queue */
    else if((pDevice->pDevData->pSecondaryTransceiver == NULL) && (pDevice->pDevData->bDmaMode != true))
    {
        adi_osal_EnterCriticalRegion();
        /* add submitted transceiver to secondary transceiver */
        pDevice->pDevData->pSecondaryTransceiver = pTransceiver;
        pDevice->pDevData->bSecondaryProcessed = false;
        adi_osal_ExitCriticalRegion();
        /* non-blocking race condition, where primary is processed but not freed and secondary is submitted */
        if((pDevice->pDevData->pPrimaryTransceiver != NULL) && (pDevice->pDevData->pActiveTransceiver == NULL))
        {
            adi_osal_EnterCriticalRegion();
            pDevice->pDevData->pActiveTransceiver = pTransceiver;
            adi_osal_ExitCriticalRegion();
            /* either submit DMA driven or interrupt driven transceiver buffer, */
            /* based on adi_spi_EnableDmaMode configuration                     */
            Result = pDevice->pDevData->FuncTable.pfSpiSubmitBuffer(pDevice, pTransceiver);
            if (Result != ADI_SPI_SUCCESS)
            {
                return Result;
            }
        }
    }
    /* if there is already a primary and secondary transceiver, queue is full */
    /*  or DMA mode has no queue because prologue buffer & tx/rx buffer fill the DMA queue */
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
    uint32_t Data;

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
    adi_osal_EnterCriticalRegion();
    /* add submitted transceiver to primary transceiver */
	pDevice->pDevData->pActiveTransceiver = pTransceiver;
    pDevice->pDevData->pPrimaryTransceiver = pTransceiver;
    pDevice->pDevData->pSecondaryTransceiver = NULL;
    pDevice->pDevData->bPrimaryProcessed = false;
    pDevice->pDevData->bSecondaryProcessed = false;
    adi_osal_ExitCriticalRegion();

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

    if(pDevice->pDevData->SpiStatusEvent != (uint32_t)ADI_SPI_HW_ERR_NONE)
    {
    	return ADI_SPI_HW_ERROR;
    }

	Data = pDevice->pRegs->SPI_TXCONTROL;
	Data &= (uint32_t)~(BITM_SPI_TXCTL_TTI | BITM_SPI_TXCTL_TEN);
	pDevice->pRegs->SPI_TXCONTROL = (uint32_t)Data;

	Data = pDevice->pRegs->SPI_RXCONTROL;
	Data &= (uint32_t)~(BITM_SPI_RXCTL_RTI | BITM_SPI_RXCTL_REN);
	pDevice->pRegs->SPI_RXCONTROL = (uint32_t)Data;

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
        adi_osal_EnterCriticalRegion();
        /* store the returned transceiver, always the primary */
        *pTransceiver = pDevice->pDevData->pPrimaryTransceiver;
        /* update the primary transceiver, make the secondary the primary, make secondary NULL */
        pDevice->pDevData->pPrimaryTransceiver = pDevice->pDevData->pSecondaryTransceiver;
        pDevice->pDevData->pSecondaryTransceiver = NULL;
        pDevice->pDevData->bPrimaryProcessed = pDevice->pDevData->bSecondaryProcessed;
        pDevice->pDevData->bSecondaryProcessed = false;
        adi_osal_ExitCriticalRegion();

        if(pDevice->pDevData->pPrimaryTransceiver == NULL)
        {
        	pDevice->pDevData->SpiMode = ADI_SPI_MODE_NONE;
        }
        if(pDevice->pDevData->SpiStatusEvent != (uint32_t)ADI_SPI_HW_ERR_NONE)
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

/**
 * @brief Configures Trigger Input settings for an SPI Tx DMA channel.
 *
 * This API is applicable only in DMA mode. Calling this API in interrupt mode will result in an error.
 *
 * The SPI buffer processing can be configured to wait for an external trigger. The trigger to be used
 * for starting the buffer processing should be configured by application using the Trigger Routing
 * Unit API adi_tru_TriggerRoute.
 *
 * @param [in]  hDevice          SPI device handle to configure.
 *
 * @param [in]  bTriggerWait     Flag which indicates whether to wait for an incomming trigger to process the given buffer.
 *
 *                               'true' - Wait for an incoming trigger.
 *                               'false'- Ignore incoming trigger and process the buffer automatically.
 *
 * @param [in]  bTriggerOvError  Flag which indicates whether to generate an error when a trigger overrun occurs.
 *                               A trigger overrun occurs when a trigger is recieved before processing the buffer
 *                               which was initiated by a previous trigger.
 *
 *                               'true' to enable and report trigger overrun error.
 *                               'false' to disable trigger overrun error.
 *
 * @return  Status
 *  - #ADI_SPI_SUCCESS                     Successfully configured Trigger input.
 *  - #ADI_SPI_INVALID_HANDLE          [D] If the given SPI handle is invalid.
 *  - #ADI_SPI_DMA_ERROR                   If failed to configure the DMA service for trigger input.
 *  - #ADI_SPI_CONFIGURATION_ERROR     [D] If configuring the trigger input in interrupt mode.
 */
ADI_SPI_RESULT  adi_spi_ConfigTxTriggerIn (
    ADI_SPI_HANDLE const       hDevice,
    bool                       bTriggerWait,
    bool                       bTriggerOvError)
{
    /* Pointer to SPI device instance */
	ADI_SPI *pDevice;

#ifdef ADI_DEBUG

    /* validate the given handle */
    if (ValidateSpiHandle(hDevice) != ADI_SPI_SUCCESS)
    {
        return ADI_SPI_INVALID_HANDLE;
    }
#endif /* ADI_DEBUG */

    pDevice = (ADI_SPI *) hDevice;

    /* Don't allow to configure the trigger in interrupt mode.*/
    if(pDevice->pDevData->bDmaMode == false)
    {
        return ADI_SPI_CONFIGURATION_ERROR;
    }

    /* Call the DMA service to configure the trigger input */
    if(adi_dma_ConfigTriggerIn (pDevice->pDevData->hTxDMAChannel,
                                bTriggerWait,
                                bTriggerOvError) != ADI_DMA_SUCCESS)
    {
        return ADI_SPI_DMA_ERROR;
    }

    return ADI_SPI_SUCCESS;
}

/**
 * @brief Configures Trigger Output settings for an SPI Tx DMA channel.
 *
 * A trigger can be generated after the completion of the SPI buffer
 * processing. The trigger can be used to syncronize other processing
 * in the system.
 *
 * The Trigger Routing Unit should be seperately configured by the
 * application to route the outgoing SPI trigger by calling the API
 * adi_tru_TriggerRoute.
 *
 * This API is only valid in DMA mode. Calling this API in interrupt
 * mode will result in an error.
 *
 * @param [in]  hDevice         SPI device handle to configure.
 * @param [in]  eSpiTrigger     Condition to generate an outgoing trigger.
 *
 * @return  Status
 *  - #ADI_SPI_INVALID_HANDLE          [D] If the given SPI handle is invalid.
 *  - #ADI_SPI_DMA_ERROR                   If failed to configure the DMA service for trigger output.
 *  - #ADI_SPI_CONFIGURATION_ERROR     [D] If configuring the trigger input in interrupt mode.
 */
ADI_SPI_RESULT  adi_spi_ConfigTxTriggerOut (
    ADI_SPI_HANDLE const       hDevice,
    ADI_SPI_TRIGGER_OUT        eSpiTrigger)
{
    /* Pointer to SPI device instance */
	ADI_SPI *pDevice;

#ifdef ADI_DEBUG

    /* validate the given handle */
    if (ValidateSpiHandle(hDevice) != ADI_SPI_SUCCESS)
    {
        return ADI_SPI_INVALID_HANDLE;
    }
#endif /* ADI_DEBUG */

    pDevice = (ADI_SPI *) hDevice;

    /* Don't allow to configure the trigger in interrupt mode.*/
    if(pDevice->pDevData->bDmaMode == false)
    {
        return ADI_SPI_CONFIGURATION_ERROR;
    }

    /* Call the DMA service to configure the trigger output */
    if(adi_dma_ConfigTriggerOut (pDevice->pDevData->hTxDMAChannel,
                                 (ADI_DMA_TRIGGER_OUT) eSpiTrigger) != ADI_DMA_SUCCESS)
    {
        return ADI_SPI_DMA_ERROR;
    }

    return ADI_SPI_SUCCESS;
}

/**
 * @brief Configures Trigger Input settings for an SPI Rx DMA channel.
 *
 * This API is applicable only in DMA mode. Calling this API in interrupt mode will result in an error.
 *
 * The SPI buffer processing can be configured to wait for an external trigger. The trigger to be used
 * for starting the buffer processing should be configured by application using the Trigger Routing
 * Unit API adi_tru_TriggerRoute.
 *
 * @param [in]  hDevice          SPI device handle to configure.
 *
 * @param [in]  bTriggerWait     Flag which indicates whether to wait for an incomming trigger to process the given buffer.
 *
 *                               'true' - Wait for an incoming trigger.
 *                               'false'- Ignore incoming trigger and process the buffer automatically.
 *
 * @param [in]  bTriggerOvError  Flag which indicates whether to generate an error when a trigger overrun occurs.
 *                               A trigger overrun occurs when a trigger is recieved before processing the buffer
 *                               which was initiated by a previous trigger.
 *
 *                               'true' to enable and report trigger overrun error.
 *                               'false' to disable trigger overrun error.
 *
 * @return  Status
 *  - #ADI_SPI_SUCCESS                     Successfully configured Trigger input.
 *  - #ADI_SPI_INVALID_HANDLE          [D] If the given SPI handle is invalid.
 *  - #ADI_SPI_DMA_ERROR                   If failed to configure the DMA service for trigger input.
 *  - #ADI_SPI_CONFIGURATION_ERROR     [D] If configuring the trigger input in interrupt mode.
 */
ADI_SPI_RESULT  adi_spi_ConfigRxTriggerIn (
    ADI_SPI_HANDLE const       hDevice,
    bool                       bTriggerWait,
    bool                       bTriggerOvError)
{
    /* Pointer to SPI device instance */
	ADI_SPI *pDevice;

#ifdef ADI_DEBUG

    /* validate the given handle */
    if (ValidateSpiHandle(hDevice) != ADI_SPI_SUCCESS)
    {
        return ADI_SPI_INVALID_HANDLE;
    }

#endif /* ADI_DEBUG */

    pDevice = (ADI_SPI *) hDevice;

    /* Don't allow to configure the trigger in interrupt mode.*/
    if(pDevice->pDevData->bDmaMode == false)
    {
        return ADI_SPI_CONFIGURATION_ERROR;
    }

    /* Call the DMA service to configure the trigger input */
    if(adi_dma_ConfigTriggerIn (pDevice->pDevData->hRxDMAChannel,
                                bTriggerWait,
                                bTriggerOvError) != ADI_DMA_SUCCESS)
    {
        return ADI_SPI_DMA_ERROR;
    }

    return ADI_SPI_SUCCESS;
}

/**
 * @brief Configures Trigger Output settings for an SPI Rx DMA channel.
 *
 * A trigger can be generated after the completion of the SPI buffer
 * processing. The trigger can be used to syncronize other processing
 * in the system.
 *
 * The Trigger Routing Unit should be seperately configured by the
 * application to route the outgoing SPI trigger by calling the API
 * adi_tru_TriggerRoute.
 *
 * This API is only valid in DMA mode. Calling this API in interrupt
 * mode will result in an error.
 *
 * @param [in]  hDevice         SPI device handle to configure.
 * @param [in]  eSpiTrigger     Condition to generate an outgoing trigger.
 *
 * @return  Status
 *  - #ADI_SPI_INVALID_HANDLE          [D] If the given SPI handle is invalid.
 *  - #ADI_SPI_DMA_ERROR                   If failed to configure the DMA service for trigger output.
 *  - #ADI_SPI_CONFIGURATION_ERROR     [D] If configuring the trigger input in interrupt mode.
 */
ADI_SPI_RESULT  adi_spi_ConfigRxTriggerOut (
    ADI_SPI_HANDLE const       hDevice,
    ADI_SPI_TRIGGER_OUT        eSpiTrigger)
{
    /* Pointer to SPI device instance */
	ADI_SPI *pDevice;

#ifdef ADI_DEBUG

    /* validate the given handle */
    if (ValidateSpiHandle(hDevice) != ADI_SPI_SUCCESS)
    {
        return ADI_SPI_INVALID_HANDLE;
    }

#endif /* ADI_DEBUG */

    pDevice = (ADI_SPI *) hDevice;

    /* Don't allow to configure the trigger in interrupt mode.*/
    if(pDevice->pDevData->bDmaMode == false)
    {
        return ADI_SPI_CONFIGURATION_ERROR;
    }

    /* Call the DMA service to configure the trigger output */
    if(adi_dma_ConfigTriggerOut (pDevice->pDevData->hRxDMAChannel,
                                 (ADI_DMA_TRIGGER_OUT) eSpiTrigger) != ADI_DMA_SUCCESS)
    {
        return ADI_SPI_DMA_ERROR;
    }

    return ADI_SPI_SUCCESS;
}

/*!
 * @brief   The adi_spi_ManualSlaveSelect API enables/disables the manual control of the SPI slave select.
 *          The applicable has the ability to manually control the assertion/de-assertion of the slave select
 *          or have the SPI driver control it automatically.  Manual control is sometimes necessary
 *          when the SPI operational mode requires a configuration change in the middle of a transceiver data
 *          transfer.  Typical scenarios where this is necessary include changing from single/dual/quad io mode.
 *          Some SPI slave device that support multiple I/O mode require opcodes/addresses to be sent in
 *          single I/O mode whilst the bulk of the data read/write operates in dual/quad I/O mode.  Such cases
 *          require manual control of the slave select because the operational mode needs to be change during the
 *          transceiver transaction.
 *
 * @param[in]    hDevice      Handle of the SPI device
 * @param[in]    bManual      Flag to manage enabling/disabling of manual control of slave selection.
 *               - true       Manual slave select control.
 *               - false      Slave select controlled within driver.
 *
 * @return      Status
 *              - #ADI_SPI_SUCCESS              The device is successfully opened for the given instance.
 *              - #ADI_SPI_FAILURE              A generalised API failure.
 *              - #ADI_SPI_INVALID_HANDLE [D]   An invalid device handle.
 *
 * @sa          adi_spi_SlaveSelect().
 */
ADI_SPI_RESULT adi_spi_ManualSlaveSelect(ADI_SPI_HANDLE const hDevice, bool bManual)
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
    pDevice = (ADI_SPI *) hDevice;
    if (bManual == true)
    {
        /* manual slave select */
        pDevice->pDevData->bManualSlaveSelect = true;
    }
    else
    {
        /* driver slave select */
        pDevice->pDevData->bManualSlaveSelect = false;
    }
    /* Return */
    return Result;
}

/*!
 * @brief   The adi_spi_SlaveSelect API enables/disables the slave select line.
 *          The API is only required when adi_spi_ManualSlaveSelect is set to true.
 *          Otherwise the SPI driver automatically controls the assertion / de-assertion
 *          of the slave select line.
 *
 * @param[in]    hDevice      Handle of the SPI device
 * @param[in]    bEnable      Flag to manage slave selection.
 *               - true       Assert slave select.
 *               - false      De-assert slave select.
 *
 * @return      Status
 *              - #ADI_SPI_SUCCESS              The device is successfully opened for the given instance.
 *              - #ADI_SPI_FAILURE              A generalised API failure.
 *              - #ADI_SPI_INVALID_HANDLE [D]   An invalid device handle.
 *
 * @sa          adi_spi_ManualSlaveSelect().
 */
ADI_SPI_RESULT adi_spi_SlaveSelect(ADI_SPI_HANDLE const hDevice, bool bEnable)
{
    /* assume a return code */
    ADI_SPI_RESULT Result = ADI_SPI_SUCCESS;
    /* Pointer to device instance */
    ADI_SPI *pDevice;

    uint32_t nSlaveSel;
    /* debug build only */
#if defined (ADI_DEBUG)
    /* validate the given handle */
    if(ValidateSpiHandle(hDevice) != ADI_SPI_SUCCESS)
    {
        return ADI_SPI_INVALID_HANDLE;
    }
#endif

    pDevice = (ADI_SPI *) hDevice;
    if (pDevice->pDevData->bManualSlaveSelect == false)
    {
        /* manual slave select must be enabled for this API*/
        return ADI_SPI_CONFIGURATION_ERROR;
    }

	/* disable the spi receiver */
	pDevice->pRegs->SPI_RXCONTROL &= (uint32_t)~(ENUM_SPI_RXCTL_RX_EN);
	pDevice->pRegs->SPI_TXCONTROL &= (uint32_t)~(ENUM_SPI_TXCTL_TX_EN);



	/* enable uni-directional SPI */
    if (bEnable == true)
    {
        /* Assert the slave select */
    	nSlaveSel = pDevice->pRegs->SPI_SSEL &~((uint32_t)pDevice->pDevData->SpiSlaveSelect  << (uint32_t)8);
        /* enable the global SPI */
        pDevice->pRegs->SPI_CONTROL |= (uint32_t)ENUM_SPI_CTL_EN;
    }
    /* disable uni-directional SPI */
    else
    {
        /* disable SPI */
    	pDevice->pRegs->SPI_CONTROL &= (uint32_t)~(ENUM_SPI_CTL_EN);
        /* De-assert the slave select */
    	nSlaveSel = pDevice->pRegs->SPI_SSEL | ((uint32_t)pDevice->pDevData->SpiSlaveSelect  << (uint32_t)8);
    }
    
    pDevice->pRegs->SPI_SSEL = nSlaveSel;
#if defined (WA_19000038) && WA_19000038   
    pDevice->pRegs->SPI_SSEL = nSlaveSel;
#endif        

    /* Return */
    return Result;
}


/*!
 * @brief   The adi_spi_StartOnMosi API determines which serial bit is most significant for dual/quad modes.
 *
 * @param[in]    hDevice      Handle of the SPI device
 * @param[in]    bMosi        Flag to manage which serial bit is most significant for dual/quad modes.
 *               - true       Most significant bit is MOSI for dual mode, SPIQ3 for quad mode
 *               - false      Most significant bit is MISO for dual and quad modes
 *
 * @return      Status
 *              - #ADI_SPI_SUCCESS              The device is successfully opened for the given instance.
 *              - #ADI_SPI_FAILURE              A generalised API failure.
 *              - #ADI_SPI_INVALID_HANDLE [D]   An invalid device handle.
 *
 */
ADI_SPI_RESULT adi_spi_StartOnMosi(ADI_SPI_HANDLE const hDevice, bool bMosi)
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
    pDevice = (ADI_SPI *) hDevice;
    if (bMosi == true)
    {
        /* MOSI/SPIQ3  most significant */
    	pDevice->pRegs->SPI_CONTROL |= (uint32_t)(ENUM_SPI_CTL_STMOSI);
    }
    else
    {
        /* MIS0 most significant */
    	pDevice->pRegs->SPI_CONTROL &= (uint32_t)~(ENUM_SPI_CTL_STMOSI);
    }
    /* Return */
    return Result;
}

/*!
 * @brief       The adi_spi_SetTransferInitiate API sets the mode in which a SPI transfer is initiated.
 *              When data is transferred via either adi_spi_SubmitBuffer or adi_spi_ReadWrite, this API
 *              should not be used as transfer initiate is determined by adi_spi_SetTransceiverMode.
 *
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
 * The enumeration ADI_SPI_TX_INITIATE configures the SPI to start a transfer upon writing to the
 * Tx Fifo and subsequent transfers interrupts / DMA requests are activated when the Tx Fifo reaches
 * its watermark level.
 *
 * The enumeration ADI_SPI_RX_INITIATE configures the SPI to start a transfer upon reading the
 * Rx Fifo and subsequent transfers interrupts / DMA requests are activated when the Rx Fifo reaches
 * its watermark level.
 *
 * The enumeration ADI_SPI_TX_INITIATE_DISABLE configures the SPI to disable all tx transfer initiates
 *
 * The enumeration ADI_SPI_RX_INITIATE_DISABLE configures the SPI to disable all rx transfer initiates
 */
ADI_SPI_RESULT adi_spi_SetTransferInitiateMode(ADI_SPI_HANDLE const hDevice,
                                               ADI_SPI_TRANSFER_INITIATE_MODE eTransferInitiateMode)
{
    /* assume a return code */
    ADI_SPI_RESULT Result = ADI_SPI_SUCCESS;
    /* Pointer to device instance */
    ADI_SPI *pDevice;
    /* register value */
    uint32_t RegValue;
    uint32_t RegValue1;

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
    RegValue   = pDevice->pRegs->SPI_TXCONTROL;
    RegValue  &= (uint32_t)~(BITM_SPI_TXCTL_TTI);
    RegValue1  = pDevice->pRegs->SPI_RXCONTROL;
    RegValue1 &= (uint32_t)~(BITM_SPI_RXCTL_RTI);

    /* determine the transfer initiate mode */
    switch(eTransferInitiateMode)
    {
        case ADI_SPI_TX_INITIATE:
            pDevice->pRegs->SPI_TXCONTROL = ((uint32_t)ENUM_SPI_TXCTL_TTI_EN | RegValue);
            break;
        case ADI_SPI_RX_INITIATE:
            pDevice->pRegs->SPI_RXCONTROL = ((uint32_t)ENUM_SPI_RXCTL_RTI_EN | RegValue1);
            break;
        case ADI_SPI_TX_INITIATE_DISABLE:
            pDevice->pRegs->SPI_TXCONTROL = ((uint32_t)ENUM_SPI_TXCTL_TTI_DIS | RegValue);
            break;
        case ADI_SPI_RX_INITIATE_DISABLE:
            pDevice->pRegs->SPI_RXCONTROL = ((uint32_t)ENUM_SPI_RXCTL_RTI_DIS | RegValue1);
            break;
        default:
            Result = ADI_SPI_BAD_PARAMETER;
            break;
    }
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
 * @note        The frequency of the SPI clock is calculated by SCLK / Clock + 1
 */

ADI_SPI_RESULT adi_spi_SetClock(ADI_SPI_HANDLE const hDevice, uint16_t Clock)
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
    pDevice = (ADI_SPI *)hDevice;
    /* write to register */
    pDevice->pRegs->SPI_CLOCK = Clock;

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
 * @sa        adi_spi_SetClockPhase
 */
ADI_SPI_RESULT adi_spi_SetClockPolarity(ADI_SPI_HANDLE const hDevice, bool bActiveHigh)
{
    /* assume a return code */
    ADI_SPI_RESULT Result = ADI_SPI_SUCCESS;
    /* Pointer to device instance */
    ADI_SPI *pDevice;

/* debug build only */
#if defined (ADI_DEBUG)
    /* validate device handle */
    if(ValidateSpiHandle(hDevice) != ADI_SPI_SUCCESS)
    {
        return ADI_SPI_INVALID_HANDLE;
    }
#endif
    pDevice = (ADI_SPI *)hDevice;
    if(bActiveHigh)
    {
        /* set SPI clock polarity to active high */
        pDevice->pRegs->SPI_CONTROL &= (uint32_t)~(ENUM_SPI_CTL_SCKLO);
    }
    else
    {
        /* set SPI clock polarity to active low */
        pDevice->pRegs->SPI_CONTROL |= (uint32_t)ENUM_SPI_CTL_SCKLO;
    }
    /* Return */
    return Result;
}


/**
 * @brief   The adi_spi_SetClockPhase API sets clock phase of the SPI
 *
 * @param[in]    hDevice      Handle of the SPI device.
 * @param[in]    bRisingEdge  Flag to manage the polarity of the serial data clock.
 *               - true       Data transitions on the rising edge of the clock.
 *               - false      Data transitions on the falling edge of the clock.
 *
 * @return      Status
 *              - #ADI_SPI_SUCCESS              The device is successfully opened for the given instance.
 *              - #ADI_SPI_FAILURE              A generalised API failure.
 *              - #ADI_SPI_INVALID_HANDLE [D]   An invalid device handle.
 *
 *
 * @sa        adi_spi_SetClockPolarity.
 */

ADI_SPI_RESULT adi_spi_SetClockPhase(ADI_SPI_HANDLE const hDevice, bool bRisingEdge)
{
    /* assume a return code */
    ADI_SPI_RESULT Result = ADI_SPI_SUCCESS;
    /* Pointer to device instance */
    ADI_SPI *pDevice;

/* debug build only */
#if defined (ADI_DEBUG)

    /* validate device handle */
    if(ValidateSpiHandle(hDevice) != ADI_SPI_SUCCESS)
    {
        return ADI_SPI_INVALID_HANDLE;
    }
#endif
    pDevice = (ADI_SPI *)hDevice;
    if(bRisingEdge)
    {
        /* rising edge of SPI clock has data transition */
        pDevice->pRegs->SPI_CONTROL |= (uint32_t)ENUM_SPI_CTL_SCKBEG;
    }
    else
    {
        /* falling edge of SPI clock has data transition */
        pDevice->pRegs->SPI_CONTROL &= (uint32_t)~(ENUM_SPI_CTL_SCKBEG);
    }
    /* Return */
    return Result;
}

/**
 * @brief       adi_spi_SetTransceiverMode
 *
 * @details     This function sets the transceiver mode and writes the configurations to
 *              the control, txcontrol and rxcontrol registers accordingly. Modes supported include
 *              single, dual or quad i/o modes. Refer to ADI_SPI_TRANSCEIVER_MODE defintions.
 *              All transceiver modes can run in DMA or interrupt mode, using callbacks or blocking,
 *              or non-blocking API functions.
 *
 *
 * @param [in]  hDevice                     Handle to the SPI.
 * @param [in]  eTransceiverMode            Transceiver modes
 *
 * @return      Status
 *              - #ADI_SPI_SUCCESS              The device is successfully opened for the given instance.
 *              - #ADI_SPI_FAILURE              A generalised API failure.
 *              - #ADI_SPI_INVALID_HANDLE [D]   An invalid device handle.
 *
 * *
 */
ADI_SPI_RESULT adi_spi_SetTransceiverMode(ADI_SPI_HANDLE             const hDevice,
                                          ADI_SPI_TRANSCEIVER_MODE   eTransceiverMode)
{
    /* assume a return code */
    ADI_SPI_RESULT Result = ADI_SPI_SUCCESS;
    /* Pointer to device instance */
    ADI_SPI *pDevice;
/* debug build only */
#if defined (ADI_DEBUG)
    /* validate device handle */
    if(ValidateSpiHandle(hDevice) != ADI_SPI_SUCCESS)
    {
        return ADI_SPI_INVALID_HANDLE;
    }
#endif

    pDevice = (ADI_SPI *)hDevice;

    /* clear MIOM fields */
    pDevice->pRegs->SPI_CONTROL  &= (uint32_t)~(BITM_SPI_CTL_MIOM);

    /* set control register fields */
    switch(eTransceiverMode)
    {
        /* SPI master mode only */
        case ADI_SPI_TX_MODE:
        case ADI_SPI_RX_MODE:
        case ADI_SPI_FAST_MODE:
        case ADI_SPI_DISABLE_TX:
        case ADI_SPI_DISABLE_RX:
        case ADI_SPI_DISABLE_ALL:
        	 Result = ADI_SPI_CONFIGURATION_ERROR;
        	 break;
         case ADI_SPI_TXRX_MODE:
        	 pDevice->pRegs->SPI_CONTROL  &= (uint32_t)~(BITM_SPI_CTL_MIOM);
         	 break;
         case ADI_SPI_RX_QSPI_MODE:
         case ADI_SPI_TX_QSPI_MODE:
        	 pDevice->pRegs->SPI_CONTROL  |= (uint32_t)(ENUM_SPI_CTL_MIO_QUAD);
        	 break;
         case ADI_SPI_TX_DIOM_MODE:
         case ADI_SPI_RX_DIOM_MODE:
        	 pDevice->pRegs->SPI_CONTROL  |= (uint32_t)(ENUM_SPI_CTL_MIO_DUAL);
            break;
        default:
            break;
    }


    pDevice->pDevData->eMode = eTransceiverMode;
    /* return */
    return Result;
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
    uint32_t RegValue;
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
    RegValue = pDevice->pRegs->SPI_CONTROL;
    RegValue &= (uint32_t)~(BITM_SPI_CTL_MSTR | BITM_SPI_CTL_PSSE );
    if (bMaster == true)
    {
        /* set SPI in master mode       */
        /* disable slave select enable  */
        /* enable MISO                  */
        RegValue |= (uint32_t)(ENUM_SPI_CTL_MASTER | ENUM_SPI_CTL_PSSE_DIS);

    }
    else
    {
        /* set SPI in slave mode        */
        /* enable slave select enable   */
        /* enable MISO                  */
        RegValue |= (uint32_t)(ENUM_SPI_CTL_SLAVE | ENUM_SPI_CTL_PSSE_EN | ENUM_SPI_CTL_MISO_EN);
    }
    /* update register */
    pDevice->pRegs->SPI_CONTROL = RegValue;
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
        pDevice->pRegs->SPI_CONTROL |= (uint32_t)ENUM_SPI_CTL_LSB_FIRST;
    }
    else
    {
        /* set SPI to MSB sent/received first */
        pDevice->pRegs->SPI_CONTROL &= (uint32_t)~(ENUM_SPI_CTL_LSB_FIRST);
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
    if(ValidateSpiHandle(hDevice) != ADI_SPI_SUCCESS)
    {
        return ADI_SPI_INVALID_HANDLE;
    }
#endif
    pDevice = (ADI_SPI *) hDevice;
    if (bSendZero == true)
    {
        /* enable tx under-run */
        pDevice->pRegs->SPI_TXCONTROL |= (uint32_t)ENUM_SPI_TXCTL_ZERO;
    }
    else
    {
        /* disable tx under-run */
        pDevice->pRegs->SPI_TXCONTROL &= (uint32_t)~(ENUM_SPI_TXCTL_ZERO);
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
    if(ValidateSpiHandle(hDevice) != ADI_SPI_SUCCESS)
    {
        return ADI_SPI_INVALID_HANDLE;
    }
#endif
    pDevice = (ADI_SPI *) hDevice;
    if (bOverwrite == true)
    {
        /* enable rx over-run */
        pDevice->pRegs->SPI_RXCONTROL |= (uint32_t)ENUM_SPI_RXCTL_OVERWRITE;
    }
    else
    {
        /* disable rx over-run */
        pDevice->pRegs->SPI_RXCONTROL &= (uint32_t)~(ENUM_SPI_RXCTL_OVERWRITE);
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
 *                - #ADI_SPI_TRANSFER_32BIT 32 bit data transfer.
 *
 * @return      Status
 *              - #ADI_SPI_SUCCESS              The device is successfully opened for the given instance.
 *              - #ADI_SPI_FAILURE              A generalised API failure.
 *              - #ADI_SPI_INVALID_HANDLE [D]   An invalid device handle.
 *              - #ADI_SPI_BAD_PARAMETER        Parameter is out of range.
 *
 * Sets the number of bits clocked out/in of the Tx/Rx fifo during each data transfer to/from the SPI bus.
 * The default setting is ADI_SPI_TRANSFER_8BIT.  In DMA mode, this API also sets the DMA transfer size,
 * in which case both the SPI word transfer size and DMA transfer size are set to the same value,
 * for example, ADI_SPI_TRANSFER_8BIT and ADI_SPI_DMA_TRANSFER_8BIT. In DMA mode it is not possible to
 * set the SPI word size to a smaller value than the DMA transfer size.  It is however possible to set
 * the DMA transfer size to a smaller value then the SPI word size via adi_spi_SetDmaTransferSize.  However
 * this should only be done by calling adi_spi_SetWordSize first followed by  adi_spi_SetDmaTransferSize.
 * Should adi_spi_SetDmaTransferSize be called first followed by adi_spi_SetWordSize then the SPI word size and
 * DMA transfer size will be set to the same value as defined by the call to adi_spi_SetWordSize.
 *
 * @sa          adi_spi_SetDmaTransferSize().
 */

ADI_SPI_RESULT adi_spi_SetWordSize(ADI_SPI_HANDLE const hDevice, ADI_SPI_TRANSFER_SIZE eTransferSize)
{

    /* assume a return code */
    ADI_SPI_RESULT Result = ADI_SPI_SUCCESS;
    /* Pointer to device instance */
    ADI_SPI *pDevice;
    /* register value */
    uint32_t RegValue;
    ADI_DMA_PSIZE ePSize;
    ADI_DMA_MSIZE eMSize;
    /* debug build only */
#if defined (ADI_DEBUG)

    /* validate the given handle */
    if(ValidateSpiHandle(hDevice) != ADI_SPI_SUCCESS) {
        return ADI_SPI_INVALID_HANDLE;
    }
#endif
    pDevice = (ADI_SPI *) hDevice;
    /* determine the number of bytes in the word transfer size */
    switch (eTransferSize)
    {
        case ADI_SPI_TRANSFER_8BIT:
            pDevice->pDevData->SpiTransferSize = 1u;
            pDevice->pDevData->BytesPerDMATransfer = 1u;
            eMSize = ADI_DMA_MSIZE_1BYTE;
            ePSize = ADI_DMA_PSIZE_1BYTE;
            break;
        case ADI_SPI_TRANSFER_16BIT:
            pDevice->pDevData->SpiTransferSize = 2u;
            pDevice->pDevData->BytesPerDMATransfer = 2u;
            eMSize = ADI_DMA_MSIZE_2BYTES;
            ePSize = ADI_DMA_PSIZE_2BYTES;
            break;
        case ADI_SPI_TRANSFER_32BIT:
            pDevice->pDevData->SpiTransferSize = 4u;
            pDevice->pDevData->BytesPerDMATransfer = 4u;
            eMSize = ADI_DMA_MSIZE_4BYTES;
            ePSize = ADI_DMA_PSIZE_4BYTES;
            break;

        default:
            Result = ADI_SPI_BAD_PARAMETER;
            break;
    }
    if(Result != ADI_SPI_SUCCESS)
    {
    	return Result;
    }
    /* read and clear register field bits */
    RegValue = pDevice->pRegs->SPI_CONTROL;
    RegValue &= (uint32_t)~(BITM_SPI_CTL_SIZE);
    /* update register */
    pDevice->pRegs->SPI_CONTROL = ((uint32_t)eTransferSize | RegValue);

    /* can only do this if DMA mode is enabled */
    if(pDevice->pDevData->bDmaMode ==  true)
    {
    	/* Set the PSize, MSize for Tx/Rx DMA */
    	if(adi_pdma_SetPSize(pDevice->pDevData->hTxDMAChannel, ePSize) != ADI_DMA_SUCCESS)
    	{
    		return ADI_SPI_DMA_ERROR;
    	}
    	if(adi_pdma_SetMSize(pDevice->pDevData->hTxDMAChannel, eMSize) != ADI_DMA_SUCCESS)
    	{
    		return ADI_SPI_DMA_ERROR;
    	}
    	if(adi_pdma_SetPSize(pDevice->pDevData->hRxDMAChannel, ePSize) != ADI_DMA_SUCCESS)
    	{
    		return ADI_SPI_DMA_ERROR;
    	}
    	if(adi_pdma_SetMSize(pDevice->pDevData->hRxDMAChannel, eMSize) != ADI_DMA_SUCCESS)
    	{
    		return ADI_SPI_DMA_ERROR;
    	}
    }
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
    uint32_t RegValue;

    /* debug build only */
#if defined (ADI_DEBUG)
    /* validate the given handle */
    if(ValidateSpiHandle(hDevice) != ADI_SPI_SUCCESS)
    {
        return ADI_SPI_INVALID_HANDLE;
    }
#endif
    pDevice = (ADI_SPI *) hDevice;
    /* debug build only */
#if defined (ADI_DEBUG)
    /* check if device is configured as master */
    if ((pDevice->pRegs->SPI_CONTROL & (uint32_t)ENUM_SPI_CTL_MASTER) != (uint32_t)ENUM_SPI_CTL_MASTER)
    {
        /* device is not set as master */
        return ADI_SPI_CONFIGURATION_ERROR;
    }
#endif
    /* read and clear register field bits */
    RegValue = (pDevice->pRegs->SPI_SSEL & ~(uint32_t)(0x000000FE))|((uint32_t)eSlaveSelect);
    /* enable the slave select */
    pDevice->pRegs->SPI_SSEL = RegValue;

#if defined (WA_19000038) && WA_19000038
    pDevice->pRegs->SPI_SSEL =  RegValue;
#endif
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
    if(ValidateSpiHandle(hDevice) != ADI_SPI_SUCCESS)
    {
        return ADI_SPI_INVALID_HANDLE;
    }
#endif
    pDevice = (ADI_SPI *) hDevice;
    if (bHWSlaveSel == true)
    {
        /* enable the hardware controlled slave select */
        pDevice->pRegs->SPI_CONTROL |= (uint32_t)ENUM_SPI_CTL_HW_SSEL;
        /* clear software slave select flag */
        pDevice->pDevData->SpiSWSlaveSelectEnable = false;
    }
    else
    {
        /* disable hardware controlled slave select enable */
        pDevice->pRegs->SPI_CONTROL &= (uint32_t)~(ENUM_SPI_CTL_HW_SSEL);
        /* set software slave select flag */
        pDevice->pDevData->SpiSWSlaveSelectEnable = true;
    }
    /* Return */
    return Result;
}

/**
 * @brief       adi_spi_SetFlowControl
 *
 * @details     This function configures the control register for flow control.
 *              Flow control with the SPI as master means that the flow control is driven by the
 *              slave the the master accepts a FCS signal as an input.
 *              As master the FCCH, FCPL and FCWM fields are not applicable.
 *
 *              Flow control with SPI as slave means that the flow control is regulated by the FCS
 *              output signal whose functionality is configurable via the following control register
 *              fields, FCCH, FCPL and FCWM.
 *
 * @param [in]  hDevice                     Handle to the SPI.
 * @param [in]  eFlowControlMode            Flow control modes
 * @param [in]  eFlowControlWatermark       Sets the flow control watermark level
 *
 * @return      Status
 *              - #ADI_SPI_SUCCESS              The device is successfully opened for the given instance.
 *              - #ADI_SPI_FAILURE              A generalised API failure.
 *              - #ADI_SPI_INVALID_HANDLE [D]   An invalid device handle.
 * *
 */
ADI_SPI_RESULT adi_spi_SetFlowControl(ADI_SPI_HANDLE            const hDevice,
                                      ADI_SPI_FLOWCONTROL_MODE  eFlowControlMode,
                                      ADI_SPI_WATERMARK         eFlowControlWatermark)
{
    /* assume a return code */
    ADI_SPI_RESULT Result = ADI_SPI_SUCCESS;
    /* Pointer to device instance */
    ADI_SPI *pDevice;
    uint32_t RegValueCtl;

/* debug build only */
#if defined (ADI_DEBUG)

    /* validate device handle */
    if(ValidateSpiHandle(hDevice) != ADI_SPI_SUCCESS)
    {
        return ADI_SPI_INVALID_HANDLE;
    }
#endif
    pDevice = (ADI_SPI *)hDevice;
    /* read control register */
    RegValueCtl   = pDevice->pRegs->SPI_CONTROL;
    /* clear flow control fields of the control register */
    RegValueCtl &= (uint32_t)~(BITM_SPI_CTL_MSTR |
                               BITM_SPI_CTL_FCEN |
                               BITM_SPI_CTL_FCCH |
                               BITM_SPI_CTL_FCPL |
                               BITM_SPI_CTL_FCWM );
    switch(eFlowControlMode)
    {
        /* SPI master flow control, FCCH and FCPL n/a tx transfer count mode */
        case ADI_SPI_FLOWCONTROL_MASTER:
            RegValueCtl |= (uint32_t)(ENUM_SPI_CTL_MASTER  |
                                      ENUM_SPI_CTL_FLOW_EN |
                                      ENUM_SPI_CTL_FLOW_RX |
                                      ENUM_SPI_CTL_FLOW_LO);
            break;
        /* SPI rx transfer count mode */
        case ADI_SPI_FLOWCONTROL_TXBUFFER_ACTIVELOW:
            RegValueCtl |= (uint32_t)(ENUM_SPI_CTL_SLAVE   |
                                      ENUM_SPI_CTL_FLOW_EN |
                                      ENUM_SPI_CTL_FLOW_TX |
                                      ENUM_SPI_CTL_FLOW_LO);
            break;
        /* SPI tx and rx transfer count mode */
        case ADI_SPI_FLOWCONTROL_TXBUFFER_ACTIVEHIGH:
            RegValueCtl |= (uint32_t)(ENUM_SPI_CTL_SLAVE   |
                                      ENUM_SPI_CTL_FLOW_EN |
                                      ENUM_SPI_CTL_FLOW_TX |
                                      ENUM_SPI_CTL_FLOW_HI);
            break;
        /* SPI tx and rx transfer count mode */
        case ADI_SPI_FLOWCONTROL_RXBUFFER_ACTIVELOW:
            RegValueCtl |= (uint32_t)(ENUM_SPI_CTL_SLAVE   |
                                      ENUM_SPI_CTL_FLOW_EN |
                                      ENUM_SPI_CTL_FLOW_RX |
                                      ENUM_SPI_CTL_FLOW_LO);
            break;
        /* SPI tx and rx transfer count mode */
        case ADI_SPI_FLOWCONTROL_RXBUFFER_ACTIVEHIGH:
            RegValueCtl |= (uint32_t)(ENUM_SPI_CTL_SLAVE   |
                                      ENUM_SPI_CTL_FLOW_EN |
                                      ENUM_SPI_CTL_FLOW_RX |
                                      ENUM_SPI_CTL_FLOW_HI);
            break;
        /* SPI disable tx and rx transfer count mode */
        case ADI_SPI_FLOWCONTROL_DISABLE:
            RegValueCtl |= (uint32_t)(ENUM_SPI_CTL_SLAVE    |
                                      ENUM_SPI_CTL_FLOW_DIS |
                                      ENUM_SPI_CTL_FLOW_RX  |
                                      ENUM_SPI_CTL_FLOW_LO);
            break;
        default:

            break;
    }
    /* set flow control fields of the control register */
    pDevice->pRegs->SPI_CONTROL = (RegValueCtl | (uint32_t)eFlowControlWatermark);
    /* return */
    return(Result);
}

/**
 * @brief       adi_spi_SetTxWordCount
 *
 * @details     This function sets the SPI to tx word count (TWC) mode.
 *              In this mode the transmission of data is controlled via two tx word counters.
 *              nTxWordCount is loaded with the number of words to be transmitted before a
 *              transfer finished (TF) interrupt is triggered.
 *              nTxWordCountReload is optional and can be loaded with the number of words to
 *              be automatically re-loaded upon entering a TF condition.
 *
 *              When data is transferred via either adi_spi_SubmitBuffer or adi_spi_ReadWrite, this API
 *              should not be used as word counts are automatically set based on byte count parameters
 *              passed in via the parameter ADI_SPI_TRANSCEIVER.
 *
 * @param [in]  hDevice                     Handle to the SPI.
 * @param [in]  TxWordCount                 tx word counter
 * @param [in]  TxWordCountReload           tx reload word counter
 *
 * @return      Status
 *              - #ADI_SPI_SUCCESS              The device is successfully opened for the given instance.
 *              - #ADI_SPI_FAILURE              A generalised API failure.
 *              - #ADI_SPI_INVALID_HANDLE [D]   An invalid device handle.
 * *
 */

ADI_SPI_RESULT adi_spi_SetTxWordCount(ADI_SPI_HANDLE const hDevice,
                                      uint32_t       TxWordCount,
                                      uint32_t       TxWordCountReload)

{
    /* assume a return code */
    ADI_SPI_RESULT Result = ADI_SPI_SUCCESS;
    /* Pointer to device instance */
    ADI_SPI *pDevice;
/* debug build only */
#if defined (ADI_DEBUG)

    /* validate device handle */
    if(ValidateSpiHandle(hDevice) != ADI_SPI_SUCCESS)
    {
        return ADI_SPI_INVALID_HANDLE;
    }
#endif
    pDevice = (ADI_SPI *)hDevice;
    if(TxWordCount != 0u)
    {
        /* enable the tx word counter */
        pDevice->pRegs->SPI_TXCONTROL |= (uint32_t)ENUM_SPI_TXCTL_TWC_EN;
        pDevice->pRegs->SPI_TWC  = TxWordCount;
        pDevice->pRegs->SPI_TWCR = TxWordCountReload;

        /* set the transmit start and transmit finish interrupt mask */
        pDevice->pRegs->SPI_EMASKST = (uint32_t)ENUM_SPI_TF_HI;
    }
    else
    {
        /* disable the tx word counter */
        pDevice->pRegs->SPI_TXCONTROL &= (uint32_t)~(ENUM_SPI_TXCTL_TWC_EN);
        pDevice->pRegs->SPI_TWC  = 0u;
        pDevice->pRegs->SPI_TWCR = 0u;

        /* clear the transmit start and transmit finish interrupt mask */
        pDevice->pRegs->SPI_EMASKCL = (uint32_t)ENUM_SPI_TF_HI;
    }
    /* return */
    return(Result);
}

/**
 * @brief       adi_spi_SetRxWordCount
 *
 * @details    This function sets the SPI to rx word count (RWC) mode.
 *              In this mode the reception of data is controlled via two rx word counters.
 *              nRxWordCount is loaded with the number of words to be received before a
 *              transfer finished (RF) interrupt is triggered.
 *              nRxWordCountReload is optional and can be loaded with the number of words to
 *              be automatically re-loaded upon entering a RF condition.
 *
 *              When data is transferred via either adi_spi_SubmitBuffer or adi_spi_ReadWrite, this API
 *              should not be used as word counts are automatically set based on byte count parameters
 *              passed in via the parameter ADI_SPI_TRANSCEIVER.
 *
 * @param [in]  hDevice                     Handle to the SPI.
 * @param [in]  RxWordCount                 rx word counter
 * @param [in]  RxWordCountReload           rx reload word counter
 *
 * @return      Status
 *              - #ADI_SPI_SUCCESS              The device is successfully opened for the given instance.
 *              - #ADI_SPI_FAILURE              A generalised API failure.
 *              - #ADI_SPI_INVALID_HANDLE [D]   An invalid device handle.
 * *
 */
ADI_SPI_RESULT adi_spi_SetRxWordCount(ADI_SPI_HANDLE const hDevice,
                                      uint32_t       RxWordCount,
                                      uint32_t       RxWordCountReload)
{
    /* assume a return code */
    ADI_SPI_RESULT Result = ADI_SPI_SUCCESS;
    /* Pointer to device instance */
    ADI_SPI *pDevice;
/* debug build only */
#if defined (ADI_DEBUG)

    /* validate device handle */
    if(ValidateSpiHandle(hDevice) != ADI_SPI_SUCCESS)
    {
        return ADI_SPI_INVALID_HANDLE;
    }
#endif
    pDevice = (ADI_SPI *)hDevice;
    if(RxWordCount != 0u)
    {
        /* enable the rx word counter */
        pDevice->pRegs->SPI_RXCONTROL |= (uint32_t)ENUM_SPI_RXCTL_RWC_EN;
        pDevice->pRegs->SPI_RWC  = RxWordCount;
        pDevice->pRegs->SPI_RWCR = RxWordCountReload;

        /* set the receive start and receive finish interrupt mask */
        pDevice->pRegs->SPI_EMASKST = (uint32_t)ENUM_SPI_RF_HI;
    }
    else
    {
        /* disable the rx word counter */
        pDevice->pRegs->SPI_RXCONTROL &= (uint32_t)~(ENUM_SPI_RXCTL_RWC_EN);
        pDevice->pRegs->SPI_RWC  = 0u;
        pDevice->pRegs->SPI_RWCR = 0u;

        /* clear the receive start and receive finish interrupt mask */
        pDevice->pRegs->SPI_EMASKCL = (uint32_t)ENUM_SPI_RF_HI;
    }
    /* return */
    return Result;
}

/**
 * @brief   adi_spi_SetInterruptMode
 *
 * @details This function sets the mask for a SPI interrupt
 *
 * @param   [in]  hDevice                   Handle of the SPI device
 * @param   [in]  eInterruptEvent           The SPI interrupt mask bit
 * @param   [in]  bEnable                   Flag to manage the enabling/disbaling of the interrupt.
 *                                          - true       Enable interrupt.
 *                                          - false      Disable interrupt.
 *
 * @return      Status
 *              - #ADI_SPI_SUCCESS              The device is successfully opened for the given instance.
 *              - #ADI_SPI_FAILURE              A generalised API failure.
 *              - #ADI_SPI_INVALID_HANDLE [D]   An invalid device handle.
 *
 */
ADI_SPI_RESULT adi_spi_SetInterruptMode(ADI_SPI_HANDLE const hDevice, ADI_SPI_EVENT eInterruptEvent, bool bEnable)
{
    /* assume a return code */
    ADI_SPI_RESULT Result = ADI_SPI_SUCCESS;
    /* Pointer to device instance */
    ADI_SPI *pDevice;
/* debug build only */
#if defined (ADI_DEBUG)

    /* validate device handle */
    if(ValidateSpiHandle(hDevice) != ADI_SPI_SUCCESS)
    {
        return ADI_SPI_INVALID_HANDLE;
    }
#endif
    pDevice = (ADI_SPI *)hDevice;
    /* enable the interrupt */
    if(bEnable)
    {
        /* mask the interrupt by writing a '1' to the EMASKST register */
        pDevice->pRegs->SPI_EMASKST  |=  (uint32_t)eInterruptEvent;
    }
    else
    {
        /* disable the interrupt by writing a '1' to the EMASKCL register */
        pDevice->pRegs->SPI_EMASKCL  |=  (uint32_t)eInterruptEvent;
    }
    /* Return */
    return Result;
}

/**
 * @brief   adi_spi_SetSlaveSelectDelay
 *
 * @details This function adds delays to the slave select of the SPI
 *          bLead adds 1 cycle between the last clock edge and de-assertion of slave select
 *          bLag adds 1 cycle between the first clock edge and assertion of slave select
 *          nDelay adds nDelay cycles between slave selects
 *
 * @param   [in]  hDevice                   Handle of the SPI device
 * @param   [in]  bLead                     adds 1 cycle between the last clock edge and de-assertion of slave select
 * @param   [in]  bLag                      adds 1 cycle between the first clock edge and assertion of slave select
 * @param   [in]  Delay                     adds nDelay cycles between slave selects
 *
 * @return      Status
 *              - #ADI_SPI_SUCCESS              The device is successfully opened for the given instance.
 *              - #ADI_SPI_FAILURE              A generalised API failure.
 *              - #ADI_SPI_INVALID_HANDLE [D]   An invalid device handle.
 *
 */
ADI_SPI_RESULT adi_spi_SetSlaveSelectDelay(ADI_SPI_HANDLE   const hDevice,
                                           bool             bLead,
                                           bool             bLag,
                                           uint8_t          Delay)
{
    /* assume a return code */
    ADI_SPI_RESULT Result = ADI_SPI_SUCCESS;
    /* Pointer to device instance */
    ADI_SPI *pDevice;
    uint32_t RegValue;
#if defined (ADI_DEBUG)
    uint8_t  Data;
#endif
/* debug build only */
#if defined (ADI_DEBUG)

    /* validate device handle */
    if(ValidateSpiHandle(hDevice) != ADI_SPI_SUCCESS)
    {
        return ADI_SPI_INVALID_HANDLE;
    }
#endif
    pDevice = (ADI_SPI *)hDevice;
#if defined (ADI_DEBUG)
    Data = (uint8_t)(BITM_SPI_DLY_STOP >> BITP_SPI_DLY_STOP);
    /* calculate the maximum range value of the delay */
    if(Delay > Data)
    {
        /* field value is out of range */
        return ADI_SPI_BAD_PARAMETER;
    }
#endif
    RegValue = pDevice->pRegs->SPI_DELAY;
    /* clear all the delay fields */
    RegValue &= (uint32_t)~(BITM_SPI_DLY_LEADX | BITM_SPI_DLY_LAGX | BITM_SPI_DLY_STOP);

    if(bLead)
    {
        RegValue |= (uint32_t)(BITM_SPI_DLY_LEADX);
    }
    else
    {
        RegValue |= 0u;
    }

    if(bLag)
    {
        RegValue |= (uint32_t)BITM_SPI_DLY_LAGX;
    }
    else
    {
        RegValue |= 0u;
    }
    /* shift the delay value into position */
    RegValue |= ((uint32_t)Delay << (uint32_t)BITP_SPI_DLY_STOP);
    /* write the stop delay value and lead/lag extension */
    pDevice->pRegs->SPI_DELAY = RegValue;
    /* Return */
    return Result;
}


/**
 * @brief       adi_spi_SetTxWatermark
 *
 * @details     This function sets the watermarks levels of the tx fifo in DMA and non-DMA modes
 *
 *              In DMA mode
 *              - eRegularWatermark sets the watermark at which a regular DMA request made
 *              - eDMAUrgentWatermarkAssert sets the watermark at which an urgent DMA request is asserted
 *              - eDMAUrgentWatermarkDeassert sets the watermark at which an urgent DMA request stops and regular DMA requests start
 *
 *              In non-DMA
 *              - eRegularWatermark sets the watermark at which tx fifo interrupt is raised
 *              - eDMAUrgentWatermarkAssert and  eDMAUrgentWatermarkDeassert not used, set to NULL
 *
 *
 * @param [in]  hDevice                      Handle to the SPI.
 * @param [in]  eRegularWatermark            Regular watermark level for the tx fifo
 * @param [in]  eDMAUrgentWatermarkAssert    The urgent assertion request watermark level for the tx fifo
 * @param [in]  eDMAUrgentWatermarkDeassert  The urgent de-assertion request watermark level for the tx fifo
 *
 * @return      Status
 *              - #ADI_SPI_SUCCESS              The device is successfully opened for the given instance.
 *              - #ADI_SPI_FAILURE              A generalised API failure.
 *              - #ADI_SPI_INVALID_HANDLE [D]   An invalid device handle.
 *              - #ADI_SPI_BAD_PARAMETER        SPI configuration attempt with invalid parameter
 *              - #ADI_SPI_WATERMARK_CONFLICT   SPI fifo watermark overlap conflict
 *
 */


ADI_SPI_RESULT adi_spi_SetTxWatermark(ADI_SPI_HANDLE     const hDevice,
                                      ADI_SPI_WATERMARK  eRegularWatermark,
                                      ADI_SPI_WATERMARK  eDMAUrgentWatermarkAssert,
                                      ADI_SPI_WATERMARK  eDMAUrgentWatermarkDeassert)
{
    /* assume a return code */
    ADI_SPI_RESULT Result = ADI_SPI_SUCCESS;
    /* pointer to device instance */
    ADI_SPI *pDevice;
    /* register value */
    uint32_t RegValue;
    /* watermarks */
    uint32_t RegularWatermark;
    uint32_t UrgentWatermarkAssert;
    uint32_t UrgentWatermarkDeAssert;

/* debug build only */
#if defined (ADI_DEBUG)

    /* validate device handle */
    if(ValidateSpiHandle(hDevice) != ADI_SPI_SUCCESS)
    {
        return ADI_SPI_INVALID_HANDLE;
    }
#endif

    pDevice = (ADI_SPI *)hDevice;
    /* determine the regular watermark level */
    switch(eRegularWatermark)
    {
        case ADI_SPI_WATERMARK_0:
            RegularWatermark = (uint32_t)ENUM_SPI_TXCTL_TDR_EMPTY;
            break;
        case ADI_SPI_WATERMARK_25:
            RegularWatermark = (uint32_t)ENUM_SPI_TXCTL_TDR_75;
            break;
        case ADI_SPI_WATERMARK_50:
            RegularWatermark = (uint32_t)ENUM_SPI_TXCTL_TDR_50;
            break;
        case ADI_SPI_WATERMARK_75:
            RegularWatermark = (uint32_t)ENUM_SPI_TXCTL_TDR_25;
            break;
        case ADI_SPI_WATERMARK_NOT_FULL:
            RegularWatermark = (uint32_t)ENUM_SPI_TXCTL_TDR_NF;
            break;
        case ADI_SPI_WATERMARK_DISABLE:
            RegularWatermark = (uint32_t)ENUM_SPI_TXCTL_TDR_DIS;
            break;
        default:
            Result = ADI_SPI_BAD_PARAMETER;
            break;
    }
    /* check if the wtermarks are valid */
    if(Result != ADI_SPI_SUCCESS)
    {
        return Result;
    }
    /* modify regular watermark */
    /* read register */
    RegValue = pDevice->pRegs->SPI_TXCONTROL;
    /* clear field bits from register */
    RegValue &= (uint32_t)~(BITM_SPI_TXCTL_TDR);
    /* update field bits from register */
    RegValue |= RegularWatermark;
    /* save the tx watermark level becasue this needs to be disbaled/enabled during tx/rx data ISRs */
    pDevice->pDevData->TxWatermark = RegularWatermark;

    /* only urgent watermarks are only set when in DMA mode */
    if(pDevice->pDevData->bDmaMode)
    {
        /* determine the assertion level of urgent watermark */
        switch(eDMAUrgentWatermarkAssert)
        {
            case ADI_SPI_WATERMARK_0:
                UrgentWatermarkAssert = (uint32_t)ENUM_SPI_TXCTL_UWM_EMPTY;
                break;
            case ADI_SPI_WATERMARK_25:
                UrgentWatermarkAssert = (uint32_t)ENUM_SPI_TXCTL_UWM_75;
                break;
            case ADI_SPI_WATERMARK_50:
                UrgentWatermarkAssert = (uint32_t)ENUM_SPI_TXCTL_UWM_50;
                break;
            case ADI_SPI_WATERMARK_75:
                UrgentWatermarkAssert = (uint32_t)ENUM_SPI_TXCTL_UWM_25;
                break;
            case ADI_SPI_WATERMARK_DISABLE:
                UrgentWatermarkAssert = (uint32_t)ENUM_SPI_TXCTL_UWM_DIS;
                break;
            default:
                UrgentWatermarkAssert = (uint32_t) -1;
                Result = ADI_SPI_BAD_PARAMETER;
                break;
        }
        /* determine the de-assertion level of urgent watermark */
        switch(eDMAUrgentWatermarkDeassert)
        {
            case ADI_SPI_WATERMARK_25:
                UrgentWatermarkDeAssert = (uint32_t)ENUM_SPI_TXCTL_RWM_75;
                break;
            case ADI_SPI_WATERMARK_50:
                UrgentWatermarkDeAssert = (uint32_t)ENUM_SPI_TXCTL_RWM_50;
                break;
            case ADI_SPI_WATERMARK_75:
                UrgentWatermarkDeAssert = (uint32_t)ENUM_SPI_TXCTL_RWM_25;
                break;
            case ADI_SPI_WATERMARK_100:
                UrgentWatermarkDeAssert = (uint32_t)ENUM_SPI_TXCTL_RWM_FULL;
                break;
            case ADI_SPI_WATERMARK_DISABLE:
                /* there is no disable parameter for this field, so set it to the default */
                UrgentWatermarkDeAssert = (uint32_t)ENUM_SPI_TXCTL_RWM_FULL;
                break;
            default:
                UrgentWatermarkDeAssert = (uint32_t) -1;
                Result = ADI_SPI_BAD_PARAMETER;
                break;
        }
        /* check if the wtermarks are valid */
        if(Result != ADI_SPI_SUCCESS)
        {
        	return Result;
        }
        /* if urgent watermark is enabled, must check that the watermark levels do not overlap each other   */
        /* - urgent assert must be set lower than urgent de-assert                                          */
        /* - normal must be set higher or equal to than urgent de-assert                                    */
        if(UrgentWatermarkAssert != (uint32_t)ENUM_SPI_TXCTL_UWM_DIS)
        {
            if(UrgentWatermarkAssert >= UrgentWatermarkDeAssert)
            {
                return ADI_SPI_WATERMARK_CONFLICT;
            }
            if(UrgentWatermarkDeAssert > RegularWatermark)
            {
                return ADI_SPI_WATERMARK_CONFLICT;
            }
        }
        /* set assertion / de-assetion urgent watermarks */
        /* clear field bits from register */
        RegValue &= (uint32_t)(~(BITM_SPI_TXCTL_TUWM | BITM_SPI_TXCTL_TRWM));
        /* update field bits from register */
        RegValue |= (UrgentWatermarkAssert | UrgentWatermarkDeAssert);

        /* Check is urgent watermark is disabled */
        if(eDMAUrgentWatermarkAssert == ADI_SPI_WATERMARK_DISABLE)
        {
            /* clear TUWM interrupt mask in the SPI_EMASK register */
            pDevice->pRegs->SPI_EMASKCL |= (uint32_t)BITM_SPI_IMSK_TUWM;
        }
        /* if urgent tx fifo watermark is enabled, set the TWUM interrupt mask */
        else
        {
            /* set TUWM interrupt mask in the SPI_EMASK register */
            pDevice->pRegs->SPI_EMASKST |= (uint32_t)BITM_SPI_IMSK_TUWM;
        }
    }
    /* write watermarks to register */
    pDevice->pRegs->SPI_TXCONTROL = RegValue;
    /* return */
    return(Result);
}

/**
 * @brief       adi_spi_SetRxWatermark
 *
 * @details     This function sets the watermarks levels of the rx fifo in DMA and non-DMA modes
 *
 *              In DMA mode
 *              - eRegularWatermark sets the watermark at which a regular DMA request made
 *              - eDMAUrgentWatermarkAssert sets the watermark at which an urgent DMA request is asserted
 *              - eDMAUrgentWatermarkDeassert sets the watermark at which an urgent DMA request stops and regular DMA requests start
 *
 *              In non-DMA
 *              - eRegularWatermark sets the watermark at which rx fifo interrupt is raised
 *              - eDMAUrgentWatermarkAssert and  eDMAUrgentWatermarkDeassert not used, set to NULL
 *
 * @param [in]  hDevice                      Handle to the SPI.
 * @param [in]  eRegularWatermark            Regular watermark level for the rx fifo
 * @param [in]  eDMAUrgentWatermarkAssert    The urgent assertion request watermark level for the rx fifo
 * @param [in]  eDMAUrgentWatermarkDeassert  The urgent de-assertion request watermark level for the rx fifo
 *
 * @return      Status
 *              - #ADI_SPI_SUCCESS              The device is successfully opened for the given instance.
 *              - #ADI_SPI_FAILURE              A generalised API failure.
 *              - #ADI_SPI_INVALID_HANDLE [D]   An invalid device handle.
 *              - #ADI_SPI_BAD_PARAMETER        SPI configuration attempt with invalid parameter
 *              - #ADI_SPI_WATERMARK_CONFLICT   SPI fifo watermark overlap conflict
 * *
 */


ADI_SPI_RESULT adi_spi_SetRxWatermark(ADI_SPI_HANDLE     const hDevice,
                                      ADI_SPI_WATERMARK  eRegularWatermark,
                                      ADI_SPI_WATERMARK  eDMAUrgentWatermarkAssert,
                                      ADI_SPI_WATERMARK  eDMAUrgentWatermarkDeassert)
{
    /* assume a return code */
    ADI_SPI_RESULT Result = ADI_SPI_SUCCESS;

    /* Pointer to device instance */
    ADI_SPI *pDevice;
    /* register value */
    uint32_t RegValue;
    uint32_t RegularWatermark = 0u;
    uint32_t UrgentWatermarkAssert = 0u;
    uint32_t UrgentWatermarkDeAssert = 0u;

/* debug build only */
#if defined (ADI_DEBUG)

    /* validate device handle */
    if(ValidateSpiHandle(hDevice) != ADI_SPI_SUCCESS)
    {
        return ADI_SPI_INVALID_HANDLE;
    }
#endif

    pDevice = (ADI_SPI *)hDevice;
    /* determine the regular watermark level */
    switch(eRegularWatermark)
    {
        case ADI_SPI_WATERMARK_25:
            RegularWatermark = (uint32_t)ENUM_SPI_RXCTL_RDR_25;
            break;
        case ADI_SPI_WATERMARK_50:
            RegularWatermark = (uint32_t)ENUM_SPI_RXCTL_RDR_50;
            break;
        case ADI_SPI_WATERMARK_75:
            RegularWatermark = (uint32_t)ENUM_SPI_RXCTL_RDR_75;
            break;
        case ADI_SPI_WATERMARK_100:
            RegularWatermark = (uint32_t)ENUM_SPI_RXCTL_RDR_FULL;
            break;
        case ADI_SPI_WATERMARK_NOT_FULL:
            RegularWatermark = (uint32_t)ENUM_SPI_RXCTL_RDR_NE;
            break;
        case ADI_SPI_WATERMARK_DISABLE:
            RegularWatermark = (uint32_t)ENUM_SPI_RXCTL_RDR_DIS;
            break;
        default:
            Result = ADI_SPI_BAD_PARAMETER;
            break;
    }
    if(Result != ADI_SPI_SUCCESS)
    {
    	return Result;
    }
    /* modify regular watermark */
    /* read register */
    RegValue = pDevice->pRegs->SPI_RXCONTROL;
    /* clear field bits from register */
    RegValue &= (uint32_t)~(BITM_SPI_RXCTL_RDR);
    /* update field bits from register */
    RegValue |= RegularWatermark;
    /* only urgent watermarks are only set when in DMA mode */
    if(pDevice->pDevData->bDmaMode)
    {
        /* determine the assertion level of urgent watermark */
        switch(eDMAUrgentWatermarkAssert)
        {
            case ADI_SPI_WATERMARK_25:
                UrgentWatermarkAssert = (uint32_t)ENUM_SPI_RXCTL_UWM_25;
                break;
            case ADI_SPI_WATERMARK_50:
                UrgentWatermarkAssert = (uint32_t)ENUM_SPI_RXCTL_UWM_50;
                break;
            case ADI_SPI_WATERMARK_75:
                UrgentWatermarkAssert = (uint32_t)ENUM_SPI_RXCTL_UWM_75;
                break;
            case ADI_SPI_WATERMARK_100:
                UrgentWatermarkAssert = (uint32_t)ENUM_SPI_RXCTL_UWM_FULL;
                break;
            case ADI_SPI_WATERMARK_DISABLE:
                UrgentWatermarkAssert = (uint32_t)ENUM_SPI_RXCTL_UWM_DIS;
                break;
            default:
                Result = ADI_SPI_BAD_PARAMETER;
                break;
        }
        /* determine the assertion level of urgent watermark */
        switch(eDMAUrgentWatermarkDeassert)
        {
            case ADI_SPI_WATERMARK_0:
                UrgentWatermarkDeAssert = (uint32_t)ENUM_SPI_RXCTL_RWM_0;
                break;
            case ADI_SPI_WATERMARK_25:
                UrgentWatermarkDeAssert = (uint32_t)ENUM_SPI_RXCTL_RWM_25;
                break;
            case ADI_SPI_WATERMARK_50:
                UrgentWatermarkDeAssert = (uint32_t)ENUM_SPI_RXCTL_RWM_50;
                break;
            case ADI_SPI_WATERMARK_75:
                UrgentWatermarkDeAssert = (uint32_t)ENUM_SPI_RXCTL_RWM_75;
                break;
            case ADI_SPI_WATERMARK_DISABLE:
                /* there is no disable parameter for this field, so set it to the default */
                UrgentWatermarkDeAssert = (uint32_t)ENUM_SPI_RXCTL_RWM_0;
                break;
            default:
                Result = ADI_SPI_BAD_PARAMETER;
                break;
        }
        /* check if the wtermarks are valid */
        if(Result != ADI_SPI_SUCCESS)
        {
        	return Result;
        }
        /* if urgent watermark is enabled, must check that the watermark levels do not overlap each other   */
        /* - urgent assert must be set lower than urgent de-assert                                          */
        /* - normal must be set higher or equal to than urgent de-assert                                    */
        if(UrgentWatermarkAssert != (uint32_t)ENUM_SPI_RXCTL_UWM_DIS)
        {
            if(UrgentWatermarkAssert <= UrgentWatermarkDeAssert)
            {
                return ADI_SPI_WATERMARK_CONFLICT ;
            }
            if(UrgentWatermarkDeAssert < RegularWatermark)
            {
                return ADI_SPI_WATERMARK_CONFLICT;
            }
        }
        /* set assertion / de-assetion urgent watermarks */
        /* clear field bits from register */
        RegValue &= (uint32_t)(~(BITM_SPI_RXCTL_RUWM | BITM_SPI_RXCTL_RRWM));
        /* update field bits from register */
        RegValue |= (UrgentWatermarkAssert | UrgentWatermarkDeAssert);
        /* Check is urgent watermark is disabled */
        if(eDMAUrgentWatermarkAssert == ADI_SPI_WATERMARK_DISABLE)
        {
            /* clear RUWM interrupt mask in the SPI_EMASK register */
            pDevice->pRegs->SPI_EMASKCL |= (uint32_t)BITM_SPI_IMSK_RUWM;
        }
        /* if urgent tx fifo watermark is enabled, set the TWUM interrupt mask */
        else
        {
            /* set RUWM interrupt mask in the SPI_EMASK register */
            pDevice->pRegs->SPI_EMASKST |= (uint32_t)BITM_SPI_IMSK_RUWM;
        }
    }
    /* write watermarks to register */
    pDevice->pRegs->SPI_RXCONTROL = RegValue;

    /* return */
    return(Result);
}

/**
 * @brief   adi_spi_GetHWErrorStatus
 *          This function gets the SPI's accumulated hardware error(s) ( effectively the SPI status register).
 *          pError contains the field bits of the SPI status register as defined in ADI_SPI_EVENT
 *          and represented by the defintions ADI_SPI_HW_ERR_XXX.
 *
 * @param   [in]  hDevice   Handle of the SPI device
 * @param   [in]  pError    Pointer to a variable containing the SPI HW error.
 * @param   [in]  pArg      Additional parameter passed to the user. For SPI device it is NULL.
 *
* @return      Status
 *              - #ADI_SPI_SUCCESS          The device is successfully opened for the given instance.
 *              - #ADI_SPI_FAILURE          A generalised API failure.
 *              - #ADI_SPI_INVALID_HANDLE   An invalid device handle.
 *
*/
ADI_SPI_RESULT adi_spi_GetHWErrorStatus (ADI_SPI_HANDLE const hDevice,
                                         uint32_t * const pError,
                                         void * const pArg)
{
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

    *pError = pDevice->pDevData->SpiStatusEvent;
    pDevice->pDevData->SpiStatusEvent  = (uint32_t) ADI_SPI_HW_ERR_NONE;
    return(ADI_SPI_SUCCESS);
}

/*********************************************************************
 Function:       ValidateSpiHandle

 Description:    This function validates the SPI handle.
 *********************************************************************/
#ifdef ADI_DEBUG
static ADI_SPI_RESULT ValidateSpiHandle(ADI_SPI_HANDLE * const hDevice)
{
    /* index counter */
    uint8_t i;
    /* return code */
    ADI_SPI_RESULT Result = ADI_SPI_INVALID_HANDLE;

    /* all SPI device instances */
    for (i = 0u; i < (uint8_t)ADI_SPI_NUM_DEVICES; i++)
    {
#if !defined(ADI_CODE_IN_ROM)
    	if (hDevice == (ADI_SPI_HANDLE) &aSpiDevice[i])
#else
      	if (hDevice == (ADI_SPI_HANDLE) &pram_for_rom_Code->aSpiDevice[i])
#endif

        {
            Result = ADI_SPI_SUCCESS; /* Found a valid device */
            break;
        }
    }
    /* Return */
    return Result;
}
#endif

/*********************************************************************
 Function:       ValidateTransceiver

 Description:    This function validates the parameters of a
 transceiver.  Prologue, transmit and receive buffers
 must have bytes counts that are a multiple of
 the SPI's data transfer size.
 *********************************************************************/
#if defined (ADI_DEBUG)
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
        if (pTransceiver->PrologueBytes % (uint32_t)pDevice->pDevData->SpiTransferSize != 0u)
        {
            return (ADI_SPI_SIZE_ERROR);
        }
    }
    /* validate transmitter only if there is one */
    if (pTransceiver->pTransmitter != NULL)
    {
        /* check the buffer size is a multiple of the transfer size */
        if (pTransceiver->TransmitterBytes % (uint32_t)pDevice->pDevData->SpiTransferSize != 0u)
        {
            return (ADI_SPI_SIZE_ERROR);
        }
    }
    /* validate receiver only if there is one */
    if (pTransceiver->pReceiver != NULL)
    {
        /* check the buffer size is a multiple of the transfer size */
        if (pTransceiver->ReceiverBytes % (uint32_t)pDevice->pDevData->SpiTransferSize != 0u)
        {
            return (ADI_SPI_SIZE_ERROR);
        }
    }
    /* Return */
    return Result;
}
#endif
/*********************************************************************
 Function:       PostTransceiverCompleted

 Description:    This function is responsible for posting either
 callbacks or semaphores that signify the completion of a transceiver
 transfer.  It also updates the transceiver queue by updating the active
 transceiver to either the primary or secondary transceiver as well as
 free'ing up any transceiver that has been processed
 *********************************************************************/
static void PostTransceiverCompleted(ADI_SPI * const pDevice, void *pBuf, ADI_SPI_EVENT Event)
{

    /* non-blocking mode */
    if(pDevice->pDevData->SpiMode == ADI_SPI_MODE_NONBLOCKING)
    {
        if (adi_osal_SemPost(pDevice->pDevData->hSemHandle) != ADI_OSAL_SUCCESS)
        {
            return;
        }
        /* In non-blocking mode, processed transceiver are not freed until adi_spi_GetBuffer, bFreePrimaryOrSecondary (FALSE) */
        UpdateQueue(pDevice, false);
    }

    /* callbacks mode */
    if(pDevice->pDevData->SpiMode == ADI_SPI_MODE_CALLBACK)
    {
        /* In callback mode, processed transceiver is freed immediately, bFreePrimaryOrSecondary (TRUE) */
        /* CCES-10114: update queue status BEFORE issuing callback,
           so callback handler can submit a new buffer successfully */
        UpdateQueue(pDevice, true);

        /* if we have a regietered callback... post a callback with transceiver processed event */
        if (pDevice->pDevData->pfCallback) {
			(pDevice->pDevData->pfCallback)(pDevice->pDevData->pCBParam, (uint32_t)Event, pBuf);
		}
    }

    /* blocking mode  */
    if(pDevice->pDevData->SpiMode == ADI_SPI_MODE_BLOCKING)
    {
        if (adi_osal_SemPost(pDevice->pDevData->hSemHandle) != ADI_OSAL_SUCCESS)
        {
            return;
        }
        /* In blocking mode, processed transceiver is freed immediately, bFreePrimaryOrSecondary (TRUE) */
        UpdateQueue(pDevice, true);
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
    if(((pDevice->pDevData->pPrimaryTransceiver != NULL) && (pDevice->pDevData->pSecondaryTransceiver != NULL)) &&
       (pDevice->pDevData->pActiveTransceiver != pDevice->pDevData->pSecondaryTransceiver))
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
        /* start the transceiver again because there is a queued transceiver */
	    StartInterruptTransceiver(pDevice);
    }
    /* if there is only a primary, there is no next transceiver to activate, so free the primary */
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
    	/* disable the spi receiver */
    	pDevice->pRegs->SPI_RXCONTROL &= (uint32_t)~(ENUM_SPI_RXCTL_RX_EN | ENUM_SPI_RXCTL_RTI_EN);
    	pDevice->pRegs->SPI_TXCONTROL &= (uint32_t)~(ENUM_SPI_TXCTL_TX_EN | ENUM_SPI_TXCTL_TTI_EN);
    }
}

/*********************************************************************
 Function:       LoadTxFifo

 Description:    This function loads the SPI transmit fifio
 with data from the transceiver's transmit buffer. The data can be either
 8, 16 or 32 bits in size.
 *********************************************************************/
static void LoadTxFifo(ADI_SPI *const pDevice, uint32_t Status)
{
    /* SPI tx data */
    uint32_t i, TxData;
    /* watermark level */
    uint32_t Watermark;

    uint32_t RegValue;


    /* check the tx watermark level of tx fifo, 8 bytes deep, watermark 0, 25%, 50%, 75%, 100% full*/
    Watermark = (Status & (uint32_t)BITM_SPI_STAT_TFS)  >> (uint32_t)BITP_SPI_STAT_TFS;

    /* calculate watermark level in bytes */
    Watermark <<= (uint32_t)(ADI_SPI_WATERMARKBYTESIZE-1u);

    /* calculate the number write cycles that can be made to the tx fifo taking into account the spi transfer size */
    if(pDevice->pDevData->Transfer.TxBytesToEmpty < Watermark)
    {
    	/* calculate the number of write cycles for the last data segment, dependant on bytes remaining and transfer size */
    	/* more efficient to use lookup table than to calculate */
    	Watermark = AccessFifo[pDevice->pDevData->SpiTransferSize][pDevice->pDevData->Transfer.TxBytesToEmpty];

    	if(!((pDevice->pDevData->eMode == ADI_SPI_TX_DIOM_MODE) || (pDevice->pDevData->eMode == ADI_SPI_TX_QSPI_MODE)))
    	{
    	/* at this point we do not want any more tx data watermark interrupts to occur, disable them */
    	RegValue = pDevice->pRegs->SPI_TXCONTROL;
    	/* clear field bits from register */
    	RegValue &= (uint32_t)~(BITM_SPI_TXCTL_TDR);
    	/* update field bits from register */
    	RegValue |= (uint32_t)ENUM_SPI_TXCTL_TDR_DIS;
        /* write watermarks to register */
        pDevice->pRegs->SPI_TXCONTROL = RegValue;
    	}
    }
    else
    {
    	/* calculate number of write cycles need to fill tx fifo to the watermark level */
        Watermark >>= ((uint32_t)pDevice->pDevData->SpiTransferSize >> (uint32_t)1);
    }
    /* perform write to tx fifo from tx buffer */
    for(i = 0u; i < Watermark; i++)
    {
    	/* if there is tx data to send */
    	if(pDevice->pDevData->Transfer.pTxData != NULL)
    	{
    		/* fetch 4 bytes of data from tx buffer if transfer size is 4 */
    		if(pDevice->pDevData->SpiTransferSize == 4u)
    		{
    			TxData   = *(uint32_t *)pDevice->pDevData->Transfer.pTxData;
    		}
    		/* fetch 2 bytes of data from tx buffer if transfer size is 2 */
    		else if(pDevice->pDevData->SpiTransferSize == 2u)
    		{
    			TxData   = *(uint16_t *)pDevice->pDevData->Transfer.pTxData;
    		}
    		else
    		{
    			/* fetch 1 byte of data from tx buffer if transfer size is 1 */
    			TxData = *pDevice->pDevData->Transfer.pTxData;
    		}
            /* adjust transceiver tx buffer pointer */
            pDevice->pDevData->Transfer.pTxData += pDevice->pDevData->SpiTransferSize;
            /* decrement bytes in tranceiver's tx buffer by the no. bytes of the transfer size */
            pDevice->pDevData->Transfer.TxBytesToEmpty -= (uint32_t)pDevice->pDevData->SpiTransferSize;

    	}
    	/* dummy tx data */
    	else
    	{
    	   		TxData = 0u;
    	 }

        /* 32 bit write to tx fifo, some bytes may be ignored if transfer size is 8bit or 16 bit */
        pDevice->pRegs->SPI_TFIFO = TxData;

        /* check for condition where we may need to switch from prologue to transmit buffer */
    	if(pDevice->pDevData->Transfer.TxBytesToEmpty == pDevice->pDevData->pActiveTransceiver->TransmitterBytes)
    	{
            /* prime tx buffer pointer */
            pDevice->pDevData->Transfer.pTxData = pDevice->pDevData->pActiveTransceiver->pTransmitter;
    	}
    }
}

/*********************************************************************
 Function:       LoadRxBuffer

 Description:    This function reads the SPI receive. The data can be either
 8, 16 or 32 bits in size.
 *********************************************************************/
static void LoadRxBuffer(ADI_SPI *const pDevice, uint32_t Status)
{
	uint32_t i;
    /* SPI rx data */
    uint32_t RxData;
    /* Spi status rx fifo watermark level */
    uint32_t Watermark;

    /* check the rx watermark level of rx fifo, 8 bytes deep, watermark 0, 25%, 50%, 75%, 100% full*/
    Watermark = (Status & (uint32_t)BITM_SPI_STAT_RFS)  >> (uint32_t)BITP_SPI_STAT_RFS;

    /* calculate the watermark level in bytes that can be read from the rx fifo*/
    Watermark <<= (uint32_t)(ADI_SPI_WATERMARKBYTESIZE-1u);
    /* calculate the number read cycles needed to empty the rx fifo to the watermark */
    if(pDevice->pDevData->Transfer.RxBytesToFill < Watermark)
    {
    	/* calculate the number of read cycles for the last data segment, dependant on bytes remaining and transfer size */
    	/* more efficient to use lookup table than to calculate */
    	Watermark = AccessFifo[pDevice->pDevData->SpiTransferSize][pDevice->pDevData->Transfer.RxBytesToFill];
    }
    else
    {
    	/* calculate number of read cycles need to empty rx fifo to the watermark level */
        Watermark >>= ((uint32_t)pDevice->pDevData->SpiTransferSize >> (uint32_t)1);
    	/* allow for special case where transfer size is 1, still want to do 1 cycle read from rx fifo */
        if((pDevice->pDevData->SpiTransferSize == 1u) && (pDevice->pDevData->Transfer.RxBytesToFill == 1u))
    	{
    		Watermark = 1u;
    	}
    }
    /* perform 32 bit transfers from rx fifo to rx buffer */
    for(i=0u; i < Watermark; i++)
    {
    	/* beginning loading rx buffer when prologue is finished */
    	if(pDevice->pDevData->Transfer.RxBytesToFill == pDevice->pDevData->pActiveTransceiver->ReceiverBytes)
    	{
            /* prime rx buffer pointer */
            pDevice->pDevData->Transfer.pRxData = pDevice->pDevData->pActiveTransceiver->pReceiver;
    	}
        /* read from SPI rx fifo register, with anomaly 1600030 correction */
    	RxData = ADI_ANOM_16000030_READ32(&pDevice->pRegs->SPI_RFIFO);
        /* only load rx buffer if there is a valid buffer 												  */
        /* don't load rx buffer when rx interrupt is generated by prologue, just do dummy read of rx fifo */
    	if(pDevice->pDevData->Transfer.pRxData != NULL)
    	{
        	/* write to rx buffer allowing for 4 byte transfer from rx fifo */
        	if(pDevice->pDevData->SpiTransferSize == 4u)
        	{
        	       *(uint32_t *)pDevice->pDevData->Transfer.pRxData = RxData;
        	    }
        	/* write to rx buffer allowing for 2 byte transfer from rx fifo */
        	else if(pDevice->pDevData->SpiTransferSize == 2u)
        	{
        	       *(uint16_t *)pDevice->pDevData->Transfer.pRxData = (uint16_t)RxData;
        	    }
        	/* write to rx buffer allowing for 1 byte transfer from rx fifo */
        	else
        	{
        	    /* 1 byte transfers */
        	    *pDevice->pDevData->Transfer.pRxData = (uint8_t)RxData;
        	}

        	/* adjust rx buffer pointer */
        	pDevice->pDevData->Transfer.pRxData += pDevice->pDevData->SpiTransferSize;
        }
    	/* decrement the number of empty bytes left in the rx buffer */
    	pDevice->pDevData->Transfer.RxBytesToFill -= (uint32_t)pDevice->pDevData->SpiTransferSize;
    	/* load pointer to rx buffer in the case where it was proceeded by a prologue buffer */
        if (pDevice->pDevData->Transfer.RxBytesToFill == pDevice->pDevData->pActiveTransceiver->ReceiverBytes)
        {
            /* load receive data for transmit transfer */
            pDevice->pDevData->Transfer.pRxData = pDevice->pDevData->pActiveTransceiver->pReceiver;
        }
    }
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

    /* disable interrupt */
    if(adi_int_EnableInt(pDevice->SpiStatusSID, false) != ADI_INT_SUCCESS)
    {
    	return ADI_SPI_INTERRUPT_FAILED;
    }
    if(adi_int_EnableInt(pDevice->SpiTransmitterSID, false) != ADI_INT_SUCCESS)
    {
    	return ADI_SPI_INTERRUPT_FAILED;
    }
    if(adi_int_EnableInt(pDevice->SpiReceiverSID, false) != ADI_INT_SUCCESS)
    {
    	return ADI_SPI_INTERRUPT_FAILED;
    }
    if(adi_int_UninstallHandler(pDevice->SpiTransmitterSID) != ADI_INT_SUCCESS)
    {
         return ADI_SPI_CLOSE_FAILED;
    }
    if(adi_int_UninstallHandler(pDevice->SpiReceiverSID) != ADI_INT_SUCCESS)
    {
         return ADI_SPI_CLOSE_FAILED;
    }
    if(adi_int_UninstallHandler(pDevice->SpiStatusSID) != ADI_INT_SUCCESS)
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
    /* disable interrupt */
    if(adi_int_EnableInt(pDevice->SpiStatusSID, false) != ADI_INT_SUCCESS)
    {
    	return ADI_SPI_INTERRUPT_FAILED;
    }
    if(adi_int_UninstallHandler(pDevice->SpiStatusSID) != ADI_INT_SUCCESS)
    {
         return ADI_SPI_CLOSE_FAILED;
    }
    /* disable tx DMA */
    if (adi_pdma_DisableXfer(pDevice->pDevData->hTxDMAChannel) != ADI_DMA_SUCCESS)
    {
        return ADI_SPI_DMA_CLOSE_FAILED;
    }
    /* disable tx DMA */
    if (adi_pdma_DisableXfer(pDevice->pDevData->hRxDMAChannel) != ADI_DMA_SUCCESS)
    {
        return ADI_SPI_DMA_CLOSE_FAILED;
    }

    /* close tx dma channel */
    if (adi_pdma_Close(pDevice->pDevData->hTxDMAChannel, false) != ADI_DMA_SUCCESS)
    {
        return ADI_SPI_DMA_CLOSE_FAILED;
    }
    /* close tx dma channel */
    if (adi_pdma_Close(pDevice->pDevData->hRxDMAChannel, false) != ADI_DMA_SUCCESS)
    {
        return ADI_SPI_DMA_CLOSE_FAILED;
    }
    /* return */
    return Result;
}

static ADI_SPI_RESULT StartInterruptTransceiver(ADI_SPI *const pDevice)
{
    /* assume a return code */
    ADI_SPI_RESULT Result = ADI_SPI_SUCCESS;
    uint32_t Bytes;
    uint32_t Status;
    uint32_t Data;
    uint32_t nSlaveSel; 
    adi_osal_EnterCriticalRegion();

    /* PLEASE NOTE !!!! */
    /* the tx and rx interrupts must always process the same number of spi transfers regardless of whether there are	*/
    /* null pointers set for the prologue, transmit or receiver buffers.  This means that the data interrupts 	        */
    /* maybe loading/unloading dummy data to/from the fifo's when the transceiver has NULL pointers             		*/
    /* if the transmit pointer is null make the byte count of the receive and transmit the same */
    if(pDevice->pDevData->pActiveTransceiver->pTransmitter == NULL)
    {
    	pDevice->pDevData->pActiveTransceiver->TransmitterBytes = pDevice->pDevData->pActiveTransceiver->ReceiverBytes;
    }
    /* if the receive pointer is null make the bytes count of the receive and transmit the same	*/
    if(pDevice->pDevData->pActiveTransceiver->pReceiver == NULL)
    {
    	pDevice->pDevData->pActiveTransceiver->ReceiverBytes = pDevice->pDevData->pActiveTransceiver->TransmitterBytes;
    }
    /* load the default transceiver, prologue data followed by tx and rx data */
    pDevice->pDevData->Transfer.pTxData        = pDevice->pDevData->pActiveTransceiver->pPrologue;
    pDevice->pDevData->Transfer.pRxData        = NULL;
    pDevice->pDevData->Transfer.TxBytesToEmpty = pDevice->pDevData->pActiveTransceiver->PrologueBytes + pDevice->pDevData->pActiveTransceiver->TransmitterBytes;
    pDevice->pDevData->Transfer.RxBytesToFill  = pDevice->pDevData->pActiveTransceiver->PrologueBytes + pDevice->pDevData->pActiveTransceiver->ReceiverBytes;

    /* if there is no prologue data load transceiver with only tx and/or rx data */
    if(pDevice->pDevData->pActiveTransceiver->pPrologue == NULL)
    {
    	pDevice->pDevData->Transfer.pTxData = pDevice->pDevData->pActiveTransceiver->pTransmitter;
    	pDevice->pDevData->Transfer.pRxData = pDevice->pDevData->pActiveTransceiver->pReceiver;
    }
    /* initial load of tx fifo */
    Status = pDevice->pRegs->SPI_STATUS;
    LoadTxFifo(pDevice, Status);

    adi_osal_ExitCriticalRegion();
    if(pDevice->pDevData->bManualSlaveSelect == false)
    {
    /* Assert SPI select line */
    /* if software slave select is enabled, asset slave select */
    if (pDevice->pDevData->SpiSWSlaveSelectEnable)
    {
        /* if valid slave select */
        if (pDevice->pDevData->SpiSlaveSelect != ADI_SPI_SSEL_DISABLE)
        {
            /* Assert the slave select, de-assertion active high, assertion active low */
            nSlaveSel = (pDevice->pRegs->SPI_SSEL) & (~((uint32_t)pDevice->pDevData->SpiSlaveSelect  << (uint32_t)8));
            pDevice->pRegs->SPI_SSEL = nSlaveSel;            
#if defined (WA_19000038) && WA_19000038
            pDevice->pRegs->SPI_SSEL = nSlaveSel;
#endif
        }
        else
        {
        	return ADI_SPI_SLAVE_SELECT_FAILED;
        }
    }
}
    /* tx word count must be set the the maximum of either (prologue bytes + tx bytes) or (prologue bytes + rx bytes) */
    /* tx and rx spi must always be synchronised, i.e transfer the same number of bytes regardless of the number of bytes in the prologue, rx and tx buffers */
    if(pDevice->pDevData->pActiveTransceiver->TransmitterBytes > pDevice->pDevData->pActiveTransceiver->ReceiverBytes)
    {
    	Bytes = pDevice->pDevData->pActiveTransceiver->PrologueBytes + pDevice->pDevData->pActiveTransceiver->TransmitterBytes;
    }
    else
    {
    	Bytes = pDevice->pDevData->pActiveTransceiver->PrologueBytes + pDevice->pDevData->pActiveTransceiver->ReceiverBytes;
    }

	/* enable tx SPI */
    if((pDevice->pDevData->eMode == ADI_SPI_TX_DIOM_MODE) || (pDevice->pDevData->eMode == ADI_SPI_TX_QSPI_MODE) || (pDevice->pDevData->eMode == ADI_SPI_TXRX_MODE))
    {
    /* enable tx word count, needed so that we know when the last bytes are flushed out of the tx fifo */
    if(adi_spi_SetTxWordCount(pDevice, Bytes>>(pDevice->pDevData->SpiTransferSize>>1), 0u) != ADI_SPI_SUCCESS)
    {
    	return ADI_SPI_FAILURE;
    }

    	Data = pDevice->pRegs->SPI_TXCONTROL;
    	Data &= (uint32_t)~(BITM_SPI_TXCTL_TTI | BITM_SPI_TXCTL_TEN);
    	pDevice->pRegs->SPI_TXCONTROL = ((uint32_t)ENUM_SPI_TXCTL_TTI_EN |  (uint32_t)ENUM_SPI_TXCTL_TX_EN | Data);
    }

	/* enable rx SPI */
    if((pDevice->pDevData->eMode == ADI_SPI_RX_DIOM_MODE) || (pDevice->pDevData->eMode == ADI_SPI_RX_QSPI_MODE) || (pDevice->pDevData->eMode == ADI_SPI_TXRX_MODE))
    {
    /* enable rx word count */
    if(adi_spi_SetRxWordCount(pDevice, Bytes>>(pDevice->pDevData->SpiTransferSize>>1), 0u) != ADI_SPI_SUCCESS)
    {
    	return ADI_SPI_FAILURE;
    }

    Data = pDevice->pRegs->SPI_RXCONTROL;
    Data &= (uint32_t)~(BITM_SPI_RXCTL_RTI | BITM_SPI_RXCTL_REN);
    pDevice->pRegs->SPI_RXCONTROL = ((uint32_t)ENUM_SPI_RXCTL_RTI_EN | (uint32_t)ENUM_SPI_RXCTL_RX_EN | Data);

    }

    if(pDevice->pDevData->bManualSlaveSelect == false)
    {
    /* enable the global SPI                                                                */
    pDevice->pRegs->SPI_CONTROL |= (uint32_t)ENUM_SPI_CTL_EN;
    }

    return Result;
}

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
static ADI_SPI_RESULT adi_spi_SubmitIntBuffer(ADI_SPI_HANDLE const      hDevice,
                                              ADI_SPI_TRANSCEIVER       *pTransceiver)
{
    /* assume a return code */
    ADI_SPI_RESULT Result = ADI_SPI_SUCCESS;
    /* Pointer to device instance */
    ADI_SPI *pDevice;

    pDevice = (ADI_SPI *)hDevice;

    /* if DMA mode, wrong configuration as this is a interrupt driven SPI transceiver */
    if(pDevice->pDevData->bDmaMode)
    {
        return(ADI_SPI_CONFIGURATION_ERROR);
    }
    StartInterruptTransceiver(pDevice);

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
 * can be bi-directional and performs a DMA read and/or write. There is no queue for SubmitDMABuffer because the transceiver
 * uses the 1st place in the queue for submission of prologue buffers and the 2nd place in the queue for submissions of
 * tx and/or rx buffers.
 *
 * There are 7 transceiver configurations
 * 1. Transmission of a prologue buffer only
 * 2. Transmission of a transmit buffer only
 * 3. Transmission of a prologue buffer followed by a transmit buffer
 * 4. Reception of a receive buffer only
 * 5. Transmission of a prologue buffer followed by the reception of a receive buffer
 * 6. Transmission/reception of transmit and receive buffers
 * 7. Transmission of a prologue buffer followed by the transmission/reception of transmit and receive buffers
 *
 * Configurations 5 and 7 require submission of dummy buffers in order to synchronise the tx and rx SPI controllers.
 * A dummy rx prologue buffer and/or dummy tx buffer are used to support these configurations.
 *
 * @sa          adi_spi_DmaTransceiver.
 * @sa          adi_spi_EnableDmaMode
 */
static ADI_SPI_RESULT adi_spi_SubmitDmaBuffer(ADI_SPI_HANDLE const hDevice, ADI_SPI_TRANSCEIVER *pTransceiver)
{
    /* assume a return code */
    ADI_SPI_RESULT Result = ADI_SPI_SUCCESS;
    ADI_DMA_RESULT ResultDMA ;
    uint32_t Data;
    uint32_t nSlaveSel;

    /* Pointer to device instance */
    ADI_SPI *pDevice;

    /* reset DMA write write parameters */
    uint8_t *pTx1      = NULL; /* pointer holder for prologue buffer       */
    uint8_t *pRx1      = NULL; /* pointer holder for dummy prologue buffer */
    uint8_t *pTx2      = NULL; /* pointer holder for tx/tx dummy buffer    */
    uint8_t *pRx2      = NULL; /* pointer holder for rx buffer             */
    int32_t Rx1Modify  = 0;    /* rx buffer DMA modify holder              */
    int32_t Tx2Modify  = 0;    /* tx buffer DMA modify holder              */
    uint32_t Tx2Count  = 0u;   /* tx buffer DMA count holder               */
    uint32_t WordCount = 0u;   /* transceiver word count holder            */

    pDevice = (ADI_SPI *) hDevice;

    /* clear the receive start and receive finish interrupt mask */
    pDevice->pRegs->SPI_EMASKCL = (uint32_t)ENUM_SPI_RF_HI;
    pDevice->pRegs->SPI_EMASKCL = (uint32_t)ENUM_SPI_TF_HI;


    /* debug build only */
#if defined (ADI_DEBUG) /* must be in DMA mode */
    if (!pDevice->pDevData->bDmaMode)
    {
        return (ADI_SPI_DMA_ERROR);
    }
#endif

    /* check that the spi is free, there is effectively no queue in DMA mode      */
    /* a single transceiver DMA submission fills the DMA queue. Therefore if the  */
    /* spi is already enabled the DMA is in process and is full				      */
    if((pDevice->pRegs->SPI_RXCONTROL & (uint32_t)ENUM_SPI_RXCTL_RX_EN) == (uint32_t)ENUM_SPI_RXCTL_RX_EN)
    {
    	return ADI_SPI_QUEUE_FULL;
    }
    if((pDevice->pRegs->SPI_TXCONTROL & (uint32_t)ENUM_SPI_TXCTL_TX_EN) == (uint32_t)ENUM_SPI_TXCTL_TX_EN)
    {
    	return ADI_SPI_QUEUE_FULL;
    }

	/* configure default DMA read/write parameters */
	pTx1      = pTransceiver->pPrologue;
	pTx2      = pTransceiver->pTransmitter;		        			/* parameter is modified to point to dummy tx buffer when required           */
	Tx2Count  = pTransceiver->TransmitterBytes;	        			/* parameter is modified to ReceiverBytes when a dummy tx buffer is required */
	Tx2Modify = (int32_t)pDevice->pDevData->BytesPerDMATransfer;	/* parameter is modified to 0 when a dummy tx buffer is required             */
	pRx1      = NULL;							        			/* parameter is modified to point to dummy rx prologue buffer when required  */
	Rx1Modify = (int32_t)pDevice->pDevData->BytesPerDMATransfer;	/* parameter is modified to 0 when a dummy rx prologue buffer is required    */
	pRx2      = pTransceiver->pReceiver;

	/* reset the transceiver transfer finish mask to 0 */
	pDevice->pDevData->TransferFinishMask = 0u;

	/* set the DMA read/write word count */
	if(pTransceiver->TransmitterBytes > pTransceiver->ReceiverBytes)
	{
		WordCount   = (pTransceiver->PrologueBytes + pTransceiver->TransmitterBytes) >>(pDevice->pDevData->SpiTransferSize>>1);
	}
	else
	{
		WordCount   = (pTransceiver->PrologueBytes + pTransceiver->ReceiverBytes) >>(pDevice->pDevData->SpiTransferSize>>1);
	}
	/* two exception of the transceiver configuration where dummy buffers need to be submitted         */
	/* 1. prologue buffer followed by a rx buffer, submit dummy rx prologue buffer and dummy tx buffer */
	/* 2. prologue buffer followed by tx and rx buffers, submit dummy rx prologue buffer               */
	if((pTransceiver->pPrologue != NULL) && (pTransceiver->pReceiver != NULL))
	{
		/* load dummy rx prologue parameters for DMA read */
		pRx1        = (uint8_t *)&pDevice->pDevData->pDummyRxPrologue;
		Rx1Modify   = 0;
	}

	if((pTransceiver->pPrologue != NULL) && (pTransceiver->pTransmitter == NULL) && (pTransceiver->pReceiver != NULL))
	{
		/* load dummy tx buffer parameters for DMA write */
		pTx2        = (uint8_t *)&pDevice->pDevData->pDummyTx;
		Tx2Count    = pTransceiver->ReceiverBytes;
		Tx2Modify   = 0;
	}
	/* first DMA read/write is for the tx prologue buffer and/or dummy rx prologue buffer if required */
	if(pTx1 != NULL)
	{
    	ResultDMA = adi_pdma_PeripheralWrite(pDevice->pDevData->hTxDMAChannel,
    										 pTx1,
                                             pTransceiver->PrologueBytes / pDevice->pDevData->BytesPerDMATransfer,
                                             (int32_t)pDevice->pDevData->BytesPerDMATransfer,
                                             0u,
                                             0);
    	if(ResultDMA == ADI_DMA_WORK_UNIT_FULL)
        {
     	   return ADI_SPI_QUEUE_FULL;
        }
    	if(ResultDMA != ADI_DMA_SUCCESS)
    	{
    		return ADI_SPI_DMA_ERROR;
    	}
	}
	if(pRx1 != NULL)
	{
	    /* initiate a peripheral dma read of the spi */
		ResultDMA = adi_pdma_PeripheralRead(pDevice->pDevData->hRxDMAChannel,
				                            pRx1,
	                                        pTransceiver->PrologueBytes / pDevice->pDevData->BytesPerDMATransfer,
	                                        Rx1Modify,
	                                        0u,
	                                        0);
		if(ResultDMA == ADI_DMA_WORK_UNIT_FULL)
	    {
	 	   return ADI_SPI_QUEUE_FULL;
	    }
		if(ResultDMA != ADI_DMA_SUCCESS)
		{
			return ADI_SPI_DMA_ERROR;
		}
	}
	/* second DMA read/write is for the tx buffer/tx dummy buffer and/or rx buffer if required */
	if(pTx2 != NULL)
	{
    	ResultDMA = adi_pdma_PeripheralWrite(pDevice->pDevData->hTxDMAChannel,
    										 pTx2,
                                             Tx2Count / pDevice->pDevData->BytesPerDMATransfer,
                                             Tx2Modify,
                                             0u,
                                             0);
    	if(ResultDMA == ADI_DMA_WORK_UNIT_FULL)
        {
     	   return ADI_SPI_QUEUE_FULL;
        }
    	if(ResultDMA != ADI_DMA_SUCCESS)
    	{
    		return ADI_SPI_DMA_ERROR;
    	}
	}
	if(pRx2 != NULL)
	{
	    /* initiate a peripheral dma read of the spi */
		ResultDMA = adi_pdma_PeripheralRead(pDevice->pDevData->hRxDMAChannel,
				                            pRx2,
	                                        pTransceiver->ReceiverBytes / pDevice->pDevData->BytesPerDMATransfer,
	                                        (int32_t)pDevice->pDevData->BytesPerDMATransfer,
	                                        0u,
	                                        0);
		if(ResultDMA == ADI_DMA_WORK_UNIT_FULL)
	    {
	 	   return ADI_SPI_QUEUE_FULL;
	    }
		if(ResultDMA != ADI_DMA_SUCCESS)
		{
			return ADI_SPI_DMA_ERROR;
		}
	}
	/* enable rx spi controller if required */
	if((pRx1 != NULL) || (pRx2 != NULL))
	{
        /* set the rx wordcount value, used to generate a rx spi finish interrupt */
        if(adi_spi_SetRxWordCount(pDevice, WordCount, 0u) != ADI_SPI_SUCCESS)
        {
        	return ADI_SPI_FAILURE;
        }

        /* always use the RF mask bit to terminate transceiver, if rx spi is used */
    	pDevice->pDevData->TransferFinishMask |= (uint32_t)ENUM_SPI_STAT_RF_HI;

		/* enable dma transfer */
		if (adi_pdma_EnableXfer(pDevice->pDevData->hRxDMAChannel) != ADI_DMA_SUCCESS)
		{
			return ADI_SPI_DMA_ERROR;
		}
    	/* set to receive initiate mode and enable spi receiver */
    	Data = pDevice->pRegs->SPI_RXCONTROL;
    	Data &= (uint32_t)~(BITM_SPI_RXCTL_RTI | BITM_SPI_RXCTL_REN);
    	pDevice->pRegs->SPI_RXCONTROL = ((uint32_t)ENUM_SPI_RXCTL_RTI_EN | (uint32_t)ENUM_SPI_RXCTL_RX_EN | Data);
	}
	/* enable tx spi controller if required */
	if((pTx1 != NULL) || (pTx2 != NULL))
	{
		/* set the tx wordcount value, used to generate a tx spi finish interrupt */
        if(adi_spi_SetTxWordCount(pDevice, WordCount, 0u) != ADI_SPI_SUCCESS)
        {
        	return ADI_SPI_FAILURE;
        }

        /* only use the TF mask bit to terminate transceiver, if the RF mask bit is not set */
        /* otherwise only the RF mask bit will be used to terminate the spi				    */
        if(pDevice->pDevData->TransferFinishMask == 0u)
        {
        	/* set the TF mask bit needed in Spi_Error_Interrupt_Handler which disables the spi */
        	pDevice->pDevData->TransferFinishMask |= (uint32_t)ENUM_SPI_STAT_TF_HI;
        }

		/* enable dma transfer */
		if (adi_pdma_EnableXfer(pDevice->pDevData->hTxDMAChannel) != ADI_DMA_SUCCESS)
		{
			return ADI_SPI_DMA_ERROR;
		}

    	/* set to transmit initiate mode and enable spi receiver */
    	Data = pDevice->pRegs->SPI_TXCONTROL;
    	Data &= (uint32_t)~(BITM_SPI_TXCTL_TTI | BITM_SPI_TXCTL_TEN);
    	pDevice->pRegs->SPI_TXCONTROL = ((uint32_t)ENUM_SPI_TXCTL_TTI_EN | (uint32_t)ENUM_SPI_TXCTL_TX_EN | Data);
	}
    /* Assert SPI select line */
    /* if software slave select is enabled, asset slave select */
    if (pDevice->pDevData->SpiSWSlaveSelectEnable)
    {
        /* if valid slave select */
        if (pDevice->pDevData->SpiSlaveSelect != ADI_SPI_SSEL_DISABLE)
        {
            /* De-assert the slave select, de-assertion active high, assertion active low */
            nSlaveSel = (pDevice->pRegs->SPI_SSEL) & (~((uint32_t)pDevice->pDevData->SpiSlaveSelect  << (uint32_t)8));
            pDevice->pRegs->SPI_SSEL = nSlaveSel;            
#if defined (WA_19000038) && WA_19000038
            pDevice->pRegs->SPI_SSEL = nSlaveSel;            
#endif
        }
        else
        {
        	return ADI_SPI_CONFIGURATION_ERROR;
        }
    }
    /* enable the global SPI  */
    pDevice->pRegs->SPI_CONTROL |= (uint32_t)ENUM_SPI_CTL_EN;

    /* Return */
    return Result;
}


/*********************************************************************
 Function:       Spi_Error_Interrupt_Handler

 Description:    This is the SPI error interrupt handler.
 *********************************************************************/
static void Spi_Error_Interrupt_Handler(uint32_t ID, void *pCBParam)
{
    /* status register value */
    uint32_t     Status;
    /* Pointer to device instance */
    ADI_SPI *pDevice = (ADI_SPI *) pCBParam;
    
    uint32_t nSlaveSel;

#ifdef ADI_DEBUG
    /*  check device */
    if(pDevice == NULL)
    {
        return;
    }
#endif /* ADI_DEBUG */

    /* Get the SPI Status register value */
    Status = pDevice->pRegs->SPI_STATUS;

	/* in DMA mode the TF and RF status bits determine when the spi transceiver should be disabled */
    if(pDevice->pDevData->bDmaMode == true)
    {
    	/* the configuration of the submitted transceiver determines whether the TF and/or RF bit masks need to be set before the spi is disabled */
    	if((Status & pDevice->pDevData->TransferFinishMask) == pDevice->pDevData->TransferFinishMask)
    	{
    		/* disable tx/rx spi */
			pDevice->pRegs->SPI_TXCONTROL &= (uint32_t)~(ENUM_SPI_TXCTL_TX_EN | ENUM_SPI_TXCTL_TTI_EN);
			pDevice->pRegs->SPI_RXCONTROL &= (uint32_t)~(ENUM_SPI_RXCTL_RX_EN | ENUM_SPI_RXCTL_RTI_EN);

			/* de-assert slave select */
		    if(pDevice->pDevData->SpiSWSlaveSelectEnable)
		    {
		        /* if valid slave select */
		        if (pDevice->pDevData->SpiSlaveSelect != ADI_SPI_SSEL_DISABLE)
		        {
		            /* De-assert the slave select, de-assertion active high, assertion active low */
		            nSlaveSel = (pDevice->pRegs->SPI_SSEL) |(((uint32_t)pDevice->pDevData->SpiSlaveSelect  << (uint32_t)8));
                    pDevice->pRegs->SPI_SSEL = nSlaveSel;                                
#if defined (WA_19000038) && WA_19000038
                    pDevice->pRegs->SPI_SSEL = nSlaveSel;                                
#endif
		        }
		    }
		    /* flag the transceiver has been processed, for non-blocking mode */
		    pDevice->pDevData->bPrimaryProcessed = true;
		    /* disable the global SPI */
		    pDevice->pRegs->SPI_CONTROL &= (uint32_t)~(ENUM_SPI_CTL_EN);
		    /* post that the transceiver is completed */
		    PostTransceiverCompleted(pDevice, pDevice->pDevData->pActiveTransceiver, ADI_SPI_TRANSCEIVER_PROCESSED);
    	}
    }
    /* check if any hardware errors have occurred */
    if((Status & (uint32_t)ENUM_SPI_HW_ERROR) != 0u)
    {
        /* accumulate status events, these events are passed to application following a GetBuffer */
        pDevice->pDevData->SpiStatusEvent |= Status;

		/* post a callback */
		if (pDevice->pDevData->SpiMode == ADI_SPI_MODE_CALLBACK)
		{
			/* if we have a regietered callback... post a callback with a HW error event */
			if (pDevice->pDevData->pfCallback) {
				(pDevice->pDevData->pfCallback)(pDevice->pDevData->pCBParam, (uint32_t) ADI_SPI_HW_ERR, NULL);
			}
        }
    }
    /* clear the status register */
    pDevice->pRegs->SPI_STATUS =  Status;

    return;

}

/*********************************************************************
 Function:       Spi_TxData_Interrupt_Handler

 Description:    This is the SPI tx data interrupt handler.
 *********************************************************************/
static void Spi_TxData_Interrupt_Handler(uint32_t SID, void *pCBParam)
{
	uint32_t Status;
    /* Pointer to device instance */
    ADI_SPI *pDevice = (ADI_SPI *) pCBParam;

    /* Status register to be read only once during the ISR */
    Status = pDevice->pRegs->SPI_STATUS;

#ifdef ADI_DEBUG
    /*  check device */
    if(pDevice == NULL)
    {
        return;
    }
#endif /* ADI_DEBUG */

    /* check for the condition where the transmit is finished, tx word count is 0 */
    /* if so disable the transmit SPI */
    if((Status & (uint32_t)ENUM_SPI_STAT_TF_HI) != 0u)
    {
            pDevice->pRegs->SPI_TXCONTROL &= (uint32_t)~(ENUM_SPI_TXCTL_TX_EN | ENUM_SPI_TXCTL_TTI_EN);
		/* clear the transmit finish bit */
	    pDevice->pRegs->SPI_STATUS &= (uint32_t)ENUM_SPI_STAT_TF_HI;

	    /* only when SPI is in uni-direction Tx mode does the transmitter post the completion condition, otherwise always the receiver */
	    if((pDevice->pDevData->eMode == ADI_SPI_TX_DIOM_MODE) || (pDevice->pDevData->eMode == ADI_SPI_TX_QSPI_MODE))
	    {
	    	/* either the primary or secondary has been processed at this point, flag it */
	    	if(pDevice->pDevData->bPrimaryProcessed == false)
	    	{
	    		pDevice->pDevData->bPrimaryProcessed = true;
	    	}
	    	else
	    	{
	    		pDevice->pDevData->bSecondaryProcessed = true;
	    	}
	    	/* post the transceiver processed event */
	    	PostTransceiverCompleted(pDevice, pDevice->pDevData->pActiveTransceiver, ADI_SPI_TRANSCEIVER_PROCESSED);
	    }
    }
    /* load tx fifo with tx transceiver data */
    LoadTxFifo(pDevice, Status);

}

/*********************************************************************
 Function:       Spi_RxData_Interrupt_Handler

 Description:    This is the SPI rx data interrupt handler.
 *********************************************************************/
static void Spi_RxData_Interrupt_Handler(uint32_t SID, void *pCBParam)
{
    /* Pointer to device instance */
    ADI_SPI *pDevice = (ADI_SPI *)pCBParam;
    uint32_t Status;
    uint32_t RegValue;
    /* Status register to be read only once during the ISR */
    Status = pDevice->pRegs->SPI_STATUS;
#ifdef ADI_DEBUG
    /*  check device */
    if(pDevice == NULL)
    {
        return;
    }
#endif /* ADI_DEBUG */
    /* Unload rx fifo with rx transceiver data */
    LoadRxBuffer(pDevice, Status);
    /* check for the completion of transceiver condition */
    if(pDevice->pDevData->Transfer.RxBytesToFill == 0u)
    {
    	if(pDevice->pDevData->bManualSlaveSelect == false)
    	{
    	/* disable the spi receiver */
		pDevice->pRegs->SPI_RXCONTROL &= (uint32_t)~(ENUM_SPI_RXCTL_RX_EN | ENUM_SPI_RXCTL_RTI_EN);

		/* de-assert slave select */
	    if(pDevice->pDevData->SpiSWSlaveSelectEnable)
	    {
	        /* if valid slave select */
	        if (pDevice->pDevData->SpiSlaveSelect != ADI_SPI_SSEL_DISABLE)
	        {
	            /* De-assert the slave select, de-assertion active high, assertion active low */
	            RegValue = (pDevice->pRegs->SPI_SSEL) | (((uint32_t)pDevice->pDevData->SpiSlaveSelect  << (uint32_t)8));
                pDevice->pRegs->SPI_SSEL = RegValue;
#if defined (WA_19000038) && WA_19000038
	            pDevice->pRegs->SPI_SSEL = RegValue;
#endif
	        }
	    }
	    /* disable the global SPI */
	    pDevice->pRegs->SPI_CONTROL &= (uint32_t)~(ENUM_SPI_CTL_EN);
    	}
        /* either the primary or secondary has been processed at this point, flag it */
        if(pDevice->pDevData->bPrimaryProcessed == false)
        {
        	pDevice->pDevData->bPrimaryProcessed = true;
        }
        else
        {
        	pDevice->pDevData->bSecondaryProcessed = true;
        }
        /* post the transceiver processed event */
        PostTransceiverCompleted(pDevice, pDevice->pDevData->pActiveTransceiver, ADI_SPI_TRANSCEIVER_PROCESSED);
        /* need to restore the tx data watermark level interrupt because it was disabled when the last bytes in tx fifo were emptied */
    	RegValue = pDevice->pRegs->SPI_TXCONTROL;
    	/* clear field bits from register */
    	RegValue &= (uint32_t)~(BITM_SPI_TXCTL_TDR);
    	/* restore the tx fifo watermark level interrupt */
    	RegValue |= (uint32_t)pDevice->pDevData->TxWatermark;
        /* write watermarks to register */
        pDevice->pRegs->SPI_TXCONTROL = RegValue;
    }
}


/*********************************************************************
 Function:       adi_spi_TxDmaCallback

 Description:    This function handles any callback initiated from
 the Tx DMA controller.
 *********************************************************************/
static void SpiTxDma_Callback(void *pCBParam, uint32_t Event, void *pArg)
{
#ifdef ADI_DEBUG
    /* Pointer to device instance */
    ADI_SPI *pDevice = (ADI_SPI *) pCBParam;

    /*  check device */
    if(pDevice == NULL)
    {
        return;
    }
#endif /* ADI_DEBUG */

    return;
}

/*********************************************************************
 Function:       adi_spi_RxDmaCallback

 Description:    This function handles any callback initiated from
 the Rx DMA controller.
 *********************************************************************/
static void SpiRxDma_Callback(void *pCBParam, uint32_t Event, void *pArg)
{
#ifdef ADI_DEBUG
    /* Pointer to device instance */
    ADI_SPI *pDevice = (ADI_SPI *) pCBParam;

    /*  check device */
    if(pDevice == NULL)
    {
        return;
    }
#endif /* ADI_DEBUG */

    return;
}



/*@}*/

#ifdef _MISRA_RULES
#pragma diag(pop)
#endif /* _MISRA_RULES */
