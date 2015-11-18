/*********************************************************************************

Copyright(c) 2010 Analog Devices, Inc. All Rights Reserved.

This software is proprietary and confidential.  By using this software you agree
to the terms of the associated Analog Devices License Agreement.

*********************************************************************************/

/*!
* @file      adi_spi_5xx.h
*
* @brief     SPI driver defintions API Header file
*
* @details
*            Header File for the SPI driver API functions and definitions
*/

/** @addtogroup SPI_Driver SPI Device Driver
*  @{
*/

#ifndef __ADI_SPI_5XX_H__
#define __ADI_SPI_5XX_H__

#ifndef  __ADI_SPI_H__
#error "This file may not be directly included. The file <drivers/spi/adi_spi.h> should be included instead"
#endif

/* disable misra diagnostics as necessary */
#ifdef _MISRA_RULES
#pragma diag(push)
#pragma diag(suppress:misra_rule_5_1:"Identifiers shall not rely on the significance of more than 31 characters")
#endif /* _MISRA_RULES */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <services/int/adi_int.h>
#include <services/dma/adi_dma.h>

/*==============  D E F I N E S  ===============*/

/*! The amount of application supplied memory (in bytes) required by
    one SPI device instance operated in interrupt mode */
#define ADI_SPI_INT_MEMORY_SIZE     156u

/*! The amount of application supplied memory (in bytes) required by
    one SPI device instance operated in DMA mode */
#define ADI_SPI_DMA_MEMORY_SIZE     (ADI_SPI_INT_MEMORY_SIZE + ADI_DMA_CHANNEL_REQ_MEMORY)

/*! SPI Device handle */
typedef void* ADI_SPI_HANDLE;

/*! Enumeration for the SPI events */
typedef enum
{
	ADI_SPI_HW_ERR_NONE				= 0, 		           		/*!< No event             						 */
    ADI_SPI_HW_ERR_MODE 			= ENUM_SPI_MF_HI,	       	/*!< SPI fault error mode                        */
    ADI_SPI_HW_ERR_TX_UNDERRUN      = ENUM_SPI_TUR_HI,			/*!< SPI tx under-run error                      */
    ADI_SPI_HW_ERR_RX_OVERRUN       = ENUM_SPI_ROR_HI,			/*!< SPI rx over-run error                       */
    ADI_SPI_HW_ERR_TX_COLLISION     = ENUM_SPI_TC_HI,			/*!< SPI tx collision error                      */
    ADI_SPI_HW_ERR					= 0xFFFCu,					/*!< SPI hardware error							 */
    ADI_SPI_TRANSCEIVER_PROCESSED   = 0xFFFFu                	/*!< SPI transceiver buffers processed           */
} ADI_SPI_EVENT;

/*! Enumeration for the SPI return codes */
typedef enum
{
    ADI_SPI_SUCCESS = 0,                                       /*!< A generic success                           */
    ADI_SPI_FAILURE,                                           /*!< A generic failure                           */
    ADI_SPI_INVALID_DEVICE_NUM,                                /*!< SPI number is invalid                       */
    ADI_SPI_INVALID_HANDLE,                                    /*!< SPI handle is invalid                       */
    ADI_SPI_INVALID_POINTER,                                   /*!< SPI transceiver pointer is invalid          */
    ADI_SPI_INSUFFICIENT_MEMORY,                               /*!< Insufficient SPI driver memory          	*/
    ADI_SPI_CONFIGURATION_ERROR,                               /*!< There is a configuration conflict           */
    ADI_SPI_IN_USE,                                            /*!< SPI resource is already in use              */
    ADI_SPI_BAD_PARAMETER,                                     /*!< The parameter passed is invalid             */
    ADI_SPI_SIZE_ERROR,                                        /*!< Invalid transceiver buffer size             */
    ADI_SPI_QUEUE_FULL,                                        /*!< Transceiver queue is full                   */
    ADI_SPI_DMA_ERROR,                            			   /*!< SPI DMA error                    			*/
    ADI_SPI_DMA_OPEN_FAILED,								   /*!< SPI DMA failed to open             			*/
    ADI_SPI_DMA_CLOSE_FAILED,   							   /*!< SPI DMA failed to close            			*/
    ADI_SPI_DMA_TRANSCEIVER_ERROR,							   /*!< SPI DMA transceiver has an error   			*/
    ADI_SPI_MODE_NONBLOCKING_FAILED,					       /*!< SPI non-blocking mode failure      			*/
    ADI_SPI_MODE_BLOCKING_FAILED,						       /*!< SPI blocking mode failure      			    */
    ADI_SPI_SEMAPHORE_PEND_FAILED,							   /*!< SPI semaphore pending problem      			*/
    ADI_SPI_SEMAPHORE_FAILED,       						   /*!< SPI semaphore problem    					*/
    ADI_SPI_INTERRUPT_FAILED,       						   /*!< SPI interrupt problem    					*/
    ADI_SPI_CLOSE_FAILED,            						   /*!< SPI closure problem    						*/
    ADI_SPI_SLAVE_SELECT_FAILED,           					   /*!< SPI slave select problem					*/
    ADI_SPI_HW_ERROR             			                   /*!< Hardware error detected in status register 	*/
}ADI_SPI_RESULT;

/*! Enumeration for the SPI fields of the ADI_SPI_SSEL (enable bits) register */
typedef enum
{
    ADI_SPI_SSEL_ENABLE1            = ENUM_SPI_SSE1_EN,        /*!< SPI slave select1 enable                    */
    ADI_SPI_SSEL_ENABLE2            = ENUM_SPI_SSE2_EN,        /*!< SPI slave select2 enable                    */
    ADI_SPI_SSEL_ENABLE3            = ENUM_SPI_SSE3_EN,        /*!< SPI slave select3 enable                    */
    ADI_SPI_SSEL_ENABLE4            = ENUM_SPI_SSE4_EN,        /*!< SPI slave select4 enable                    */
    ADI_SPI_SSEL_ENABLE5            = ENUM_SPI_SSE5_EN,        /*!< SPI slave select5 enable                    */
    ADI_SPI_SSEL_ENABLE6            = ENUM_SPI_SSE6_EN,        /*!< SPI slave select6 enable                    */
    ADI_SPI_SSEL_ENABLE7            = ENUM_SPI_SSE7_EN,        /*!< SPI slave select7 enable                    */
    ADI_SPI_SSEL_DISABLE            = 0
} ADI_SPI_SSENABLE;

/*! Enumeration for the SPI word transfer size */
typedef enum
{
    ADI_SPI_TRANSFER_8BIT       	= ENUM_SPI_CTL_SIZE08,     /*!<   8 bit transfer size                      */
    ADI_SPI_TRANSFER_16BIT     		= ENUM_SPI_CTL_SIZE16      /*!<  16 bit transfer size                      */
}ADI_SPI_TRANSFER_SIZE;

/*! Enumeration for the SPI DMA word transfer size */
typedef enum
{
    ADI_SPI_DMA_TRANSFER_8BIT,       						   /*!<   8 bit transfer size                      */
    ADI_SPI_DMA_TRANSFER_16BIT,    							   /*!<  16 bit transfer size                      */
    ADI_SPI_DMA_TRANSFER_32BIT     							   /*!<  32 bit transfer size                      */
}ADI_SPI_DMA_TRANSFER_SIZE;

/*! Enumeration for the SPI word transfer size */
typedef enum
{
    ADI_SPI_RX_INITIATE_INTERRUPT 	= ENUM_SPI_CTL_TIMOD00,    /*!<  the rx initiates transfer via interrupts  */
    ADI_SPI_TX_INITIATE_INTERRUPT 	= ENUM_SPI_CTL_TIMOD01,    /*!<  the tx initiates transfer via interrupts  */
    ADI_SPI_RX_INITIATE_DMA       	= ENUM_SPI_CTL_TIMOD10,    /*!<  the rx initiates transfer via dma         */
    ADI_SPI_TX_INITIATE_DMA       	= ENUM_SPI_CTL_TIMOD11     /*!<  the tx initiates transfer via dma         */
}ADI_SPI_TRANSFER_INITIATE_MODE;

/*! SPI transceiver structure */
typedef struct
{
    uint8_t  *pPrologue;                            		    /*!< Pointer to prologue buffer structure       */
    uint32_t PrologueBytes;                                     /*!< Prologue buffer size in bytes              */
    uint8_t  *pTransmitter;                         		    /*!< Pointer to transmit buffer structure       */
    uint32_t TransmitterBytes;                                  /*!< Transmit buffer size in bytes              */
    uint8_t  *pReceiver;                            		    /*!< Pointer to receiver buffer structure       */
    uint32_t ReceiverBytes;                                     /*!< Receiver buffer size in bytes              */
} ADI_SPI_TRANSCEIVER;

/*************************************
  SPI API
*************************************/
ADI_SPI_RESULT adi_spi_Open(
    uint32_t        const DeviceNumber,
    void            *const pDeviceMemory,
	uint32_t		MemorySize,
    ADI_SPI_HANDLE  *phDevice
);

ADI_SPI_RESULT adi_spi_Close(
    ADI_SPI_HANDLE	const hDevice
);

/************************************/
/* Enable DMA  mode                 */
/************************************/
ADI_SPI_RESULT adi_spi_EnableDmaMode(
    ADI_SPI_HANDLE      const hDevice,
    bool                bDMAEnable
);

ADI_SPI_RESULT adi_spi_SetDmaTransferSize(
    ADI_SPI_HANDLE      		const hDevice,
    ADI_SPI_DMA_TRANSFER_SIZE   eDMASize
);

/************************************/
/* SPI callback registration        */
/************************************/
ADI_SPI_RESULT adi_spi_RegisterCallback (
	ADI_SPI_HANDLE   const hDevice,
    ADI_CALLBACK     pfCallback,
    void *           const  pCBParam
);

/************************************/
/* SPI transceiver submit buffers   */
/************************************/
ADI_SPI_RESULT adi_spi_SubmitBuffer(
    ADI_SPI_HANDLE const	hDevice,
    ADI_SPI_TRANSCEIVER     *pTransceiver
);

/************************************/
/* SPI transceiver read/write       */
/************************************/
ADI_SPI_RESULT adi_spi_ReadWrite(
	ADI_SPI_HANDLE const	hDevice,
    ADI_SPI_TRANSCEIVER     *pTransceiver
);

/************************************/
/* SPI get transceiver buffers   	*/
/************************************/
ADI_SPI_RESULT adi_spi_GetBuffer(
    ADI_SPI_HANDLE const	hDevice,
    ADI_SPI_TRANSCEIVER     **pTransceiver
);

/*******************************************/
/* SPI get transceiver buffer availability */
/*******************************************/
ADI_SPI_RESULT adi_spi_IsBufferAvailable(
    ADI_SPI_HANDLE const	hDevice,
    bool     	   			*pbAvailable
);

/************************************/
/* Transfer Initiate mode           */
/************************************/
ADI_SPI_RESULT adi_spi_SetTransferInitiateMode(
    ADI_SPI_HANDLE                  const hDevice,
    ADI_SPI_TRANSFER_INITIATE_MODE  eTransferInitiateMode
);

/************************************/
/* SPI slave select control API     */
/************************************/
ADI_SPI_RESULT adi_spi_SetSlaveSelect(
    ADI_SPI_HANDLE      const hDevice,
    ADI_SPI_SSENABLE    eSlaveSelect
);

ADI_SPI_RESULT adi_spi_SetHwSlaveSelect(
    ADI_SPI_HANDLE      const hDevice,
    bool                bHWSlaveSel
);

/************************************/
/* Configuration                    */
/************************************/
ADI_SPI_RESULT adi_spi_SetClock(
    ADI_SPI_HANDLE      const hDevice,
    uint16_t            Clock
);

ADI_SPI_RESULT adi_spi_SetMaster(
    ADI_SPI_HANDLE      const hDevice,
    bool                bMaster
);

ADI_SPI_RESULT adi_spi_SetClockPolarity(
    ADI_SPI_HANDLE      const hDevice,
    bool                bActiveHigh
);

ADI_SPI_RESULT adi_spi_SetLsbFirst(
    ADI_SPI_HANDLE      const hDevice,
    bool                bLsbFirst
);

ADI_SPI_RESULT adi_spi_SetWordSize(
    ADI_SPI_HANDLE          const hDevice,
    ADI_SPI_TRANSFER_SIZE   eTransferSize
);

ADI_SPI_RESULT adi_spi_SetTransmitUnderflow(
    ADI_SPI_HANDLE      const hDevice,
    bool                bSendZero
);

ADI_SPI_RESULT adi_spi_SetReceiveOverflow(
    ADI_SPI_HANDLE      const hDevice,
    bool                bOverwrite
);

/************************************/
/* Get status                       */
/************************************/
ADI_SPI_RESULT adi_spi_GetHWErrorStatus (
    ADI_SPI_HANDLE  const hDevice,
    uint32_t        *pHwError,
    void            *const pArg
);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#ifdef _MISRA_RULES
#pragma diag(pop)
#endif /* _MISRA_RULES */

#endif /* __ADI_SPI_5XX_H__ */

