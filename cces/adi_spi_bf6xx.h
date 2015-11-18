/*********************************************************************************

Copyright(c) 2010 Analog Devices, Inc. All Rights Reserved.

This software is proprietary and confidential.  By using this software you agree
to the terms of the associated Analog Devices License Agreement.

*********************************************************************************/

/*!
* @file      adi_spi_bf6xx.h
*
* @brief     SPI driver API Header file
*
* @details
*            Header File for the SPI driver API functions and definitions
*/

/** @addtogroup SPI_Driver SPI Device Driver
*  @{
*/

#ifndef _ADI_SPI_BF6XX_H_
#define _ADI_SPI_BF6XX_H_

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

#if defined(__ADSPBF609_FAMILY__)
#include <services/int/adi_sec.h>
#endif
#include <services/int/adi_int.h>
#include <services/dma/adi_dma.h>


/*==============  D E F I N E S  ===============*/

/*! The amount of application supplied memory (in bytes) required by
    one SPI device instance operated in interrupt mode */
#if defined(__ECC__)
#define ADI_SPI_INT_MEMORY_SIZE 	172u
#elif defined(__ICCARM__)
#define ADI_SPI_INT_MEMORY_SIZE 	160u
#elif defined(__ADSPGCC__)
#define ADI_SPI_INT_MEMORY_SIZE 	160u
#else
#error "Unknown compiler type"
#endif

/*! The amount of application supplied memory (in bytes) required by
    one SPI device instance operated in DMA mode */
#define ADI_SPI_DMA_MEMORY_SIZE 	(ADI_SPI_INT_MEMORY_SIZE + (ADI_DMA_CHANNEL_REQ_MEMORY * 2u))

/*! SPI Device handle */
typedef void* ADI_SPI_HANDLE;

/*! Enumeration for the SPI events
 *  The SPI uses several mechanisms to indicate that an SPI event has occurred.  The mechanism used depends on the SPI's mode of operation.
 *
 *  In callback mode, an ADI_SPI_HW_ERR event is passed back via the a callback function.  The application can determine the specific nature
 *  of this ADI_SPI_HW_ERR by calling adi_spi_GetHWErrorStatus to determine what error bits are active.
 *
 *  In blocking mode, when a ADI_SPI_HW_ERROR return code is returned after calling adi_spi_ReadWrite, this signifies that a hardware error event has occurred.
 *  The application can determine the specific nature of this return code error by calling adi_spi_GetHWErrorStatus to determine what error bits are active.
 *
 *  In non-blocking mode with no callbacks, when adi_spi_SubmitBuffer is called followed adi_spi_GetBuffer, if a return code of ADI_SPI_HW_ERROR
 *  is returned, this signifies that a hardware error event has occurred.  The application can determine the specific nature of this return code error by calling
 *  adi_spi_GetHWErrorStatus to determine what error bits are active.
 *
 */
typedef enum
{
    ADI_SPI_HW_ERR_NONE                 = 0,                    /*!< No event                                                               */
    ADI_SPI_HW_ERR_RX_OVERUN            = ENUM_SPI_STAT_ROR_HI, /*!< SPI rx over-run error                                                  */
    ADI_SPI_HW_ERR_TX_UNDERRUN          = ENUM_SPI_STAT_TUR_HI, /*!< SPI tx under-run error                                                 */
    ADI_SPI_HW_ERR_TX_COLLISION         = ENUM_SPI_STAT_TC_HI,  /*!< SPI tx collision error                                                 */
    ADI_SPI_HW_ERR_MODE                 = ENUM_SPI_STAT_MF_HI,  /*!< SPI fault error mode                                                   */
    ADI_SPI_HW_ERR_RX_START             = ENUM_SPI_STAT_RS_HI,  /*!< SPI rx start                                                           */
    ADI_SPI_HW_ERR_TX_START             = ENUM_SPI_STAT_TS_HI,  /*!< SPI tx start                                                           */
    ADI_SPI_HW_ERR_RX_FINISH            = ENUM_SPI_STAT_RF_HI,  /*!< SPI rx finish                                                          */
    ADI_SPI_HW_ERR_TX_FINISH            = ENUM_SPI_STAT_TF_HI,  /*!< SPI tx finish                                                          */
    ADI_SPI_HW_ERR                      = 0xFFFFFFCu,           /*!< SPI hardware error has occurred, use adi_spi_GetHWErrorStatus          */
    ADI_SPI_TRANSCEIVER_PROCESSED       = 0xFFFFFFEu            /*!< SPI transceiver buffer has been processed by either  DMA or interrupt  */
} ADI_SPI_EVENT;


/*! Enumeration for the SPI return codes */
typedef enum
{
    ADI_SPI_SUCCESS = 0,                                       /*!< A generic success                           */
    ADI_SPI_FAILURE,                                           /*!< A generic failure                           */
    ADI_SPI_INVALID_DEVICE_NUM,                                /*!< SPI number is invalid                       */
    ADI_SPI_INVALID_HANDLE,                                    /*!< SPI handle is invalid                       */
    ADI_SPI_INVALID_POINTER,                                   /*!< SPI transceiver pointer is invalid          */
    ADI_SPI_INSUFFICIENT_MEMORY,                               /*!< Insufficient SPI driver memory              */
    ADI_SPI_CONFIGURATION_ERROR,                               /*!< There is a configuration conflict           */
    ADI_SPI_IN_USE,                                            /*!< SPI resource is already in use              */
    ADI_SPI_BAD_PARAMETER,                                     /*!< The parameter passed is invalid             */
    ADI_SPI_SIZE_ERROR,                                        /*!< Invalid transceiver buffer size             */
    ADI_SPI_QUEUE_FULL,                                        /*!< Transceiver queue is full                   */
    ADI_SPI_DMA_ERROR,                                         /*!< SPI DMA error                               */
    ADI_SPI_DMA_OPEN_FAILED,                                   /*!< SPI DMA failed to open                      */
    ADI_SPI_DMA_CLOSE_FAILED,                                  /*!< SPI DMA failed to close                     */
    ADI_SPI_DMA_TRANSCEIVER_ERROR,                             /*!< SPI DMA transceiver has an error            */
    ADI_SPI_MODE_NONBLOCKING_FAILED,                           /*!< SPI non-blocking mode failure               */
    ADI_SPI_MODE_BLOCKING_FAILED,                              /*!< SPI blocking mode failure                   */
    ADI_SPI_SEMAPHORE_PEND_FAILED,                             /*!< SPI semaphore pending problem               */
    ADI_SPI_SEMAPHORE_FAILED,                                  /*!< SPI semaphore problem                       */
    ADI_SPI_INTERRUPT_FAILED,                                  /*!< SPI interrupt problem                       */
    ADI_SPI_CLOSE_FAILED,                                      /*!< SPI closure problem                         */
    ADI_SPI_SLAVE_SELECT_FAILED,                               /*!< SPI slave select problem                    */
    ADI_SPI_HW_ERROR,                                          /*!< Hardware error detected in status register  */
    ADI_SPI_TRANSCEIVER_ERROR,                                 /*!< invalid transceiver buffer                  */
    ADI_SPI_TRANSCEIVER_PROLOGUE_ERROR,                        /*!< invalid transceiver buffer                  */
    ADI_SPI_TRANSCEIVER_TX_ERROR,                              /*!< invalid transceiver buffer                  */
    ADI_SPI_TRANSCEIVER_RX_ERROR,                              /*!< invalid transceiver buffer                  */
    ADI_SPI_TRANSCEIVER_QUEUE_FULL,                            /*!< transceiver queue is full                   */
    ADI_SPI_TRANSCEIVER_DMA_ERROR,                             /*!< transceiver queue is full                   */
    ADI_SPI_WATERMARK_CONFLICT                                 /*!< watermark levels overlap                    */
}ADI_SPI_RESULT;


/*! Enumeration for the SPI fields of the ADI_SPI_SSEL (enable bits) register
 * Allows designation of an external SPI slave device chip select pin to be driven
 * by the SPI controller. Multiple external slave SPI devices may be present on
 * a shared SPI bus, and the chip select pin allows each of them to be assigned
 * dedicated selects.
 */
typedef enum
{
    ADI_SPI_SSEL_ENABLE1        = ENUM_SPI_SLVSEL_SSEL1_EN,    /*!< SPI slave select1 enable                   */
    ADI_SPI_SSEL_ENABLE2        = ENUM_SPI_SLVSEL_SSEL2_EN,    /*!< SPI slave select2 enable                   */
    ADI_SPI_SSEL_ENABLE3        = ENUM_SPI_SLVSEL_SSEL3_EN,    /*!< SPI slave select3 enable                   */
    ADI_SPI_SSEL_ENABLE4        = ENUM_SPI_SLVSEL_SSEL4_EN,    /*!< SPI slave select4 enable                   */
    ADI_SPI_SSEL_ENABLE5        = ENUM_SPI_SLVSEL_SSEL5_EN,    /*!< SPI slave select5 enable                   */
    ADI_SPI_SSEL_ENABLE6        = ENUM_SPI_SLVSEL_SSEL6_EN,    /*!< SPI slave select6 enable                   */
    ADI_SPI_SSEL_ENABLE7        = ENUM_SPI_SLVSEL_SSEL7_EN,    /*!< SPI slave select7 enable                   */
    ADI_SPI_SSEL_DISABLE        = 0
} ADI_SPI_SSENABLE;


/*!
 *  Enumeration for the SPI transceiver mode.
 *  The SPI can be configured to operate in numerous modes that determine the SPI data direction and also the
 *  width of the SPI serial data bus.  The width of the SPI serial data bus can be set to single, dual or
 *  quad i/o mode.  In single i/o mode, the traditional standard SPI mode, data is sent and received via the
 *  MOSI and MISO serial data lines.  In dual i/o, the SPI serial data lines can be configured as either
 *  2 tx serial lines or 2 rx serial lines.  In quad i/o, the SPI serial data lines can be  configured as either
 *  4 tx serial lines or 4 rx serial lines.
 *
 */
typedef enum
{
    ADI_SPI_TX_MODE,                                           /*!< Not implemented                             */
    ADI_SPI_RX_MODE,                                           /*!< Not implemented                             */
    ADI_SPI_TXRX_MODE,                                         /*!< SPI with MOSI and MISO, single i/o mode     */
    ADI_SPI_TX_DIOM_MODE,                                      /*!< Tx Dual I/O, dual i/o mode                  */
    ADI_SPI_RX_DIOM_MODE,                                      /*!< Rx Dual I/O, dual i/o mode                  */
    ADI_SPI_TX_QSPI_MODE,                                      /*!< Tx Quad SPI, quad i/o mode                  */
    ADI_SPI_RX_QSPI_MODE,                                      /*!< Tx Quad SPI, quad i/o mode                  */
    ADI_SPI_FAST_MODE,                                         /*!< Not implemented                             */
    ADI_SPI_DISABLE_TX,                                        /*!< Not implemented                             */
    ADI_SPI_DISABLE_RX,                                        /*!< Not implemented                             */
    ADI_SPI_DISABLE_ALL                                        /*!< Not implemented                             */
}ADI_SPI_TRANSCEIVER_MODE;

/*! Enumeration for the SPI flow control mode */
typedef enum
{
    ADI_SPI_FLOWCONTROL_MASTER,                                /*!< if master flow control, FCCH and FCPL n/a   */
    ADI_SPI_FLOWCONTROL_TXBUFFER_ACTIVELOW,                    /*!< active lo flow control tx buf slave mode    */
    ADI_SPI_FLOWCONTROL_TXBUFFER_ACTIVEHIGH,                   /*!< active hi flow control tx buf slave mode    */
    ADI_SPI_FLOWCONTROL_RXBUFFER_ACTIVELOW,                    /*!< active lo flow control rx buf slave mode    */
    ADI_SPI_FLOWCONTROL_RXBUFFER_ACTIVEHIGH,                   /*!< active hi flow control rx buf slave mode    */
    ADI_SPI_FLOWCONTROL_DISABLE                                /*!< disable flow control                        */
}ADI_SPI_FLOWCONTROL_MODE;

/*! Enumeration for the SPI watermark levels
 *  The SPI watermark levels are used to measure the fullness the SPI Transmit/Receive FIFO which are 8 bytes deep.
 *  The watermark levels are used to generate interrupts or initiate DMA fetches everytime the watermark level is breached.
 *  The level of the watermark has a bearing on how frequently the SPI data interrupts or DMA data fetches
 *  are initiated.
 */
typedef enum
{
    ADI_SPI_WATERMARK_0,                                        /*!<   0 % watermark level                      */
    ADI_SPI_WATERMARK_25,                                       /*!<  25 % watermark level                      */
    ADI_SPI_WATERMARK_50,                                       /*!<  50 % watermark level                      */
    ADI_SPI_WATERMARK_75,                                       /*!<  75 % watermark level                      */
    ADI_SPI_WATERMARK_100,                                      /*!< 100 % watermark level                      */
    ADI_SPI_WATERMARK_NOT_FULL,                                 /*!< not full watermark                         */
    ADI_SPI_WATERMARK_NOT_EMPTY,                                /*!< not empty watermark                        */
    ADI_SPI_WATERMARK_DISABLE                                   /*!< disable watermarks                         */
}ADI_SPI_WATERMARK;

/*! Enumeration for the SPI word transfer size */
typedef enum
{
    ADI_SPI_TRANSFER_8BIT       = ENUM_SPI_CTL_SIZE08,          /*!<   8 bit transfer size                      */
    ADI_SPI_TRANSFER_16BIT      = ENUM_SPI_CTL_SIZE16,          /*!<  16 bit transfer size                      */
    ADI_SPI_TRANSFER_32BIT      = ENUM_SPI_CTL_SIZE32           /*!<  32 bit transfer size                      */
}ADI_SPI_TRANSFER_SIZE;

/*! Enumeration for the SPI DMA word transfer size */
typedef enum
{
    ADI_SPI_DMA_TRANSFER_8BIT,                                 /*!<   8  bit transfer size                      */
    ADI_SPI_DMA_TRANSFER_16BIT,                                /*!<  16  bit transfer size                      */
    ADI_SPI_DMA_TRANSFER_32BIT,                                /*!<  32  bit transfer size                      */
    ADI_SPI_DMA_TRANSFER_64BIT,                                /*!<  64  bit transfer size                      */
    ADI_SPI_DMA_TRANSFER_128BIT,                               /*!<  128 bit transfer size                      */
    ADI_SPI_DMA_TRANSFER_256BIT                                /*!<  256 bit transfer size                      */
}ADI_SPI_DMA_TRANSFER_SIZE;

/*! Enumeration for the SPI word transfer size */
typedef enum
{
    ADI_SPI_TX_INITIATE,                                        /*!<  the tx initiates transfer                 */
    ADI_SPI_RX_INITIATE,                                        /*!<  the rx initiates transfer                 */
    ADI_SPI_TX_INITIATE_DISABLE,                                /*!<  disable tx transfer initiate              */
    ADI_SPI_RX_INITIATE_DISABLE                                 /*!<  disable rx transfer initiate              */
}ADI_SPI_TRANSFER_INITIATE_MODE;

/*! SPI transceiver structure contains the functional elements used to implement the SPI transceiver model.
 *  The SPI driver uses a transceiver model to transmit and receive data across the SPI.  This model provides
 *  some flexibility as to how an application may want to send and receive data packets between a master and slave
 *  SPI device.
 *  The transceiver model includes an optional prologue buffer which proceeds an optional an transmit or
 *  receiver buffer.  The prologue buffer may be used to transmit opcode commands, addressing or mode fields to
 *  a slave SPI.  The transmit or receiver buffers can be used to either write or read data packets to/from the SPI
 *  slave device.
 */
typedef struct
{
    uint8_t  *pPrologue;                                        /*!< Pointer to prologue buffer structure       */
    uint32_t PrologueBytes;                                     /*!< Prologue buffer size in bytes              */
    uint8_t  *pTransmitter;                                     /*!< Pointer to transmit buffer structure       */
    uint32_t TransmitterBytes;                                  /*!< Transmit buffer size in bytes              */
    uint8_t  *pReceiver;                                        /*!< Pointer to receiver buffer structure       */
    uint32_t ReceiverBytes;                                     /*!< Receiver buffer size in bytes              */
} ADI_SPI_TRANSCEIVER;

/*! Enumeration of conditions on which an SPI device can issue an outgoing Trigger
 */
typedef enum
{
    ADI_SPI_TRIGGER_OUT_NONE        = ADI_DMA_TRIGGER_OUT_NONE,         /*!< No trigger (default)               */
    ADI_SPI_TRIGGER_OUT_DMA_DONE    = ADI_DMA_TRIGGER_OUT_XCNT_EXPIRY   /*!< Generate trigger when DMA is done. */
} ADI_SPI_TRIGGER_OUT;

/*************************************
  SPI API
*************************************/
ADI_SPI_RESULT adi_spi_Open(
    uint32_t        DeviceNumber,
    void            *pDeviceMemory,
    uint32_t        MemorySize,
    ADI_SPI_HANDLE  *phDevice
);

ADI_SPI_RESULT adi_spi_Close(
    ADI_SPI_HANDLE       const hDevice
);

/************************************/
/* Enable DMA  mode                 */
/************************************/
ADI_SPI_RESULT adi_spi_EnableDmaMode(
    ADI_SPI_HANDLE      const hDevice,
    bool                bDMAEnable
);

ADI_SPI_RESULT adi_spi_SetDmaTransferSize(
    ADI_SPI_HANDLE              const hDevice,
    ADI_SPI_DMA_TRANSFER_SIZE   eDMASize
);

/************************************/
/* SPI callback registration        */
/************************************/
ADI_SPI_RESULT adi_spi_RegisterCallback (
        ADI_SPI_HANDLE const        hDevice,
    ADI_CALLBACK     pfCallback,
    void *           const  pCBParam
);

/************************************/
/* SPI transceiver submit buffers   */
/************************************/
ADI_SPI_RESULT adi_spi_SubmitBuffer(
    ADI_SPI_HANDLE const    hDevice,
    ADI_SPI_TRANSCEIVER     *pTransceiver
);

/************************************/
/* SPI transceiver read/write       */
/************************************/
ADI_SPI_RESULT adi_spi_ReadWrite(
    ADI_SPI_HANDLE const    hDevice,
    ADI_SPI_TRANSCEIVER     *pTransceiver
);

/************************************/
/* SPI get transceiver buffers      */
/************************************/
ADI_SPI_RESULT adi_spi_GetBuffer(
    ADI_SPI_HANDLE const    hDevice,
    ADI_SPI_TRANSCEIVER     **pTransceiver
);

/*******************************************/
/* SPI get transceiver buffer availability */
/*******************************************/
ADI_SPI_RESULT adi_spi_IsBufferAvailable(
    ADI_SPI_HANDLE const    hDevice,
    bool                    *pbAvailable
);

/************************************/
/* Tx Trigger routing                  */
/************************************/
ADI_SPI_RESULT  adi_spi_ConfigTxTriggerIn (
    ADI_SPI_HANDLE const        hDevice,
    bool                        bTriggerWait,
    bool                        bTriggerOvError
);

ADI_SPI_RESULT  adi_spi_ConfigTxTriggerOut (
    ADI_SPI_HANDLE const       hDevice,
    ADI_SPI_TRIGGER_OUT        eSpiTrigger
);

/************************************/
/* Rx Trigger routing                  */
/************************************/
ADI_SPI_RESULT  adi_spi_ConfigRxTriggerIn (
    ADI_SPI_HANDLE const        hDevice,
    bool                        bTriggerWait,
    bool                        bTriggerOvError
);

ADI_SPI_RESULT  adi_spi_ConfigRxTriggerOut (
    ADI_SPI_HANDLE const       hDevice,
    ADI_SPI_TRIGGER_OUT        eSpiTrigger
);

/************************************/
/* Watermark control API            */
/************************************/

/* This function sets the watermarks levels of the tx fifo in DMA and non-DMA modes */
ADI_SPI_RESULT adi_spi_SetTxWatermark(
    ADI_SPI_HANDLE     const hDevice,
    ADI_SPI_WATERMARK  eRegularWatermark,
    ADI_SPI_WATERMARK  eDMAUrgentWatermarkAssert,
    ADI_SPI_WATERMARK  eDMAUrgentWatermarkDeassert
);

/* This function sets the watermarks levels of the rx fifo in DMA and non-DMA modes */
ADI_SPI_RESULT adi_spi_SetRxWatermark(
    ADI_SPI_HANDLE     const hDevice,
    ADI_SPI_WATERMARK  eRegularWatermark,
    ADI_SPI_WATERMARK  eDMAUrgentWatermarkAssert,
    ADI_SPI_WATERMARK  eDMAUrgentWatermarkDeassert
);

/************************************/
/* Physical operational modes       */
/************************************/
/* This function sets the physical interface of the SPI */
ADI_SPI_RESULT adi_spi_SetTransceiverMode(
    ADI_SPI_HANDLE              const hDevice,
    ADI_SPI_TRANSCEIVER_MODE    eTransceiverMode
);

/************************************/
/* Flow control mode                */
/************************************/
/* This function configures the SPI with flow control */
ADI_SPI_RESULT adi_spi_SetFlowControl(
    ADI_SPI_HANDLE              const hDevice,
    ADI_SPI_FLOWCONTROL_MODE    eFlowControlMode,
    ADI_SPI_WATERMARK           eFlowControlWatermark
);

/************************************/
/* Transfer word count mode         */
/************************************/

/* This function sets the SPI to tx word count (TWC) mode. */
ADI_SPI_RESULT adi_spi_SetTxWordCount(
    ADI_SPI_HANDLE      const hDevice,
    uint32_t            TxWordCount,
    uint32_t            TxWordCountReload
);

/* This function sets the SPI to rx word count (TWC) mode. */
ADI_SPI_RESULT adi_spi_SetRxWordCount(
    ADI_SPI_HANDLE      const hDevice,
    uint32_t            RxWordCount,
    uint32_t            RxWordCountReload
);

/************************************/
/* Transfer Initiate mode           */
/************************************/
/* This function configures the SPI for transfer initiate control */
ADI_SPI_RESULT adi_spi_SetTransferInitiateMode(
    ADI_SPI_HANDLE                  const hDevice,
    ADI_SPI_TRANSFER_INITIATE_MODE  eTransferInitiateMode
);

/************************************/
/* SPI slave select control API     */
/************************************/
/* This function enables the slave select of the SPI */
ADI_SPI_RESULT adi_spi_SetSlaveSelect(
    ADI_SPI_HANDLE      const hDevice,
    ADI_SPI_SSENABLE    eSlaveSelect
);

/* This function enables / disables the hardware to control the slave select of the SPI */
ADI_SPI_RESULT adi_spi_SetHwSlaveSelect(
    ADI_SPI_HANDLE      const hDevice,
    bool                bHWSlaveSel
);

/************************************/
/* Interrupt mode                   */
/************************************/
/* This function enables/disables the interrupts for SPI events */
ADI_SPI_RESULT adi_spi_SetInterruptMode(
    ADI_SPI_HANDLE      const hDevice,
    ADI_SPI_EVENT       eInterruptEvent,
    bool                bEnable
);

/************************************/
/* Configuration                    */
/************************************/
ADI_SPI_RESULT adi_spi_SetMaster(
    ADI_SPI_HANDLE      const hDevice,
    bool                bMaster
);

ADI_SPI_RESULT adi_spi_SetClock(
    ADI_SPI_HANDLE      const hDevice,
    uint16_t            Clock
);

ADI_SPI_RESULT adi_spi_SetClockPolarity(
    ADI_SPI_HANDLE      const hDevice,
    bool                bActiveHigh
);

ADI_SPI_RESULT adi_spi_SetClockPhase(
    ADI_SPI_HANDLE      const hDevice,
    bool                bRisingEdge
);

/* This function sets the order in which data bytes are clocked */
ADI_SPI_RESULT adi_spi_SetLsbFirst(
    ADI_SPI_HANDLE      const hDevice,
    bool                bLsbFirst
);

/* This function sets tword transfer size, 8, 16 or 32 bit */
ADI_SPI_RESULT adi_spi_SetWordSize(
    ADI_SPI_HANDLE          const hDevice,
    ADI_SPI_TRANSFER_SIZE   eTransferSize
);

/* This function set the SPI's transmitter for under-flow mode */
ADI_SPI_RESULT adi_spi_SetTransmitUnderflow(
    ADI_SPI_HANDLE      const hDevice,
    bool                bSendZero
);

/* This function set the SPI's receiver for over-flow mode */

ADI_SPI_RESULT adi_spi_SetReceiveOverflow(
    ADI_SPI_HANDLE      const hDevice,
    bool                bOverwrite
);

/* This function adds delays to the slave select of the SPI */
ADI_SPI_RESULT adi_spi_SetSlaveSelectDelay(
    ADI_SPI_HANDLE      const hDevice,
    bool                bLead,
    bool                bLag,
    uint8_t             Delay
);

/* This function determines which serial bit is most significant for dual/quad modes. */
ADI_SPI_RESULT adi_spi_StartOnMosi(
        ADI_SPI_HANDLE  const hDevice,
        bool            bMosi
);

/************************************/
/* SPI get hardware error status    */
/************************************/
ADI_SPI_RESULT adi_spi_GetHWErrorStatus (
    ADI_SPI_HANDLE  const hDevice,
    uint32_t *      const pError,
    void *          const pArg
);

/* This function set the SPI's slave select to manual override */
ADI_SPI_RESULT adi_spi_ManualSlaveSelect(
    ADI_SPI_HANDLE      const hDevice,
    bool                bManual
);

/* This function asserts/de-asset's the SPI's slave select */
ADI_SPI_RESULT adi_spi_SlaveSelect(
    ADI_SPI_HANDLE      const hDevice,
    bool                bEnable
);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#ifdef _MISRA_RULES
#pragma diag(pop)
#endif /* _MISRA_RULES */

#endif /* _ADI_SPI_BF6XX_H_ */
