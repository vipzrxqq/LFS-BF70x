/* =========================================================================

     Project      :   ADSP-BF706
     File         :   cdefBF706.h
     Description  :   C register and bitfield definitions

     Date         :   03-03-2015
     

     Copyright (c) 2011-2015 Analog Devices, Inc.  All Rights Reserved.
     This software is proprietary and confidential to Analog Devices, Inc. and
     its licensors.

     This file was auto-generated. Do not make local changes to this file.

   ========================================================================= */
#ifndef _CDEF_BF706_H
#define _CDEF_BF706_H

#include <stdint.h>
#include <defBF706.h>

#ifdef _MISRA_RULES
#pragma diag(push)
#pragma diag(suppress:misra_rule_5_7:"ADI header will re-use identifiers")
#pragma diag(suppress:misra_rule_6_3:"ADI header allows use of basic types")
#endif /* _MISRA_RULES */



/* =========================================================================
       L1DM
   ========================================================================= */
#define pREG_L1DM_SRAM_BASE_ADDR         ((void * volatile *)REG_L1DM_SRAM_BASE_ADDR)            /* L1DM SRAM Base Address Register */
#define pREG_L1DM_DCTL                   ((volatile uint32_t *)REG_L1DM_DCTL)                    /* L1DM Data Memory Control Register */
#define pREG_L1DM_DSTAT                  ((volatile uint32_t *)REG_L1DM_DSTAT)                   /* L1DM Data Memory CPLB Status Register */
#define pREG_L1DM_DCPLB_FAULT_ADDR       ((void * volatile *)REG_L1DM_DCPLB_FAULT_ADDR)          /* L1DM Data Memory CPLB Fault Address Register */
#define pREG_L1DM_DCPLB_DFLT             ((volatile uint32_t *)REG_L1DM_DCPLB_DFLT)              /* L1DM Data Memory CPLB Default Settings Register */
#define pREG_L1DM_DPERR_STAT             ((volatile uint32_t *)REG_L1DM_DPERR_STAT)              /* L1DM Data Memory Parity Error Status Register */
#define pREG_L1DM_DCPLB_ADDR0            ((void * volatile *)REG_L1DM_DCPLB_ADDR0)               /* L1DM Data Memory CPLB Address Registers */
#define pREG_L1DM_DCPLB_ADDR1            ((void * volatile *)REG_L1DM_DCPLB_ADDR1)               /* L1DM Data Memory CPLB Address Registers */
#define pREG_L1DM_DCPLB_ADDR2            ((void * volatile *)REG_L1DM_DCPLB_ADDR2)               /* L1DM Data Memory CPLB Address Registers */
#define pREG_L1DM_DCPLB_ADDR3            ((void * volatile *)REG_L1DM_DCPLB_ADDR3)               /* L1DM Data Memory CPLB Address Registers */
#define pREG_L1DM_DCPLB_ADDR4            ((void * volatile *)REG_L1DM_DCPLB_ADDR4)               /* L1DM Data Memory CPLB Address Registers */
#define pREG_L1DM_DCPLB_ADDR5            ((void * volatile *)REG_L1DM_DCPLB_ADDR5)               /* L1DM Data Memory CPLB Address Registers */
#define pREG_L1DM_DCPLB_ADDR6            ((void * volatile *)REG_L1DM_DCPLB_ADDR6)               /* L1DM Data Memory CPLB Address Registers */
#define pREG_L1DM_DCPLB_ADDR7            ((void * volatile *)REG_L1DM_DCPLB_ADDR7)               /* L1DM Data Memory CPLB Address Registers */
#define pREG_L1DM_DCPLB_ADDR8            ((void * volatile *)REG_L1DM_DCPLB_ADDR8)               /* L1DM Data Memory CPLB Address Registers */
#define pREG_L1DM_DCPLB_ADDR9            ((void * volatile *)REG_L1DM_DCPLB_ADDR9)               /* L1DM Data Memory CPLB Address Registers */
#define pREG_L1DM_DCPLB_ADDR10           ((void * volatile *)REG_L1DM_DCPLB_ADDR10)              /* L1DM Data Memory CPLB Address Registers */
#define pREG_L1DM_DCPLB_ADDR11           ((void * volatile *)REG_L1DM_DCPLB_ADDR11)              /* L1DM Data Memory CPLB Address Registers */
#define pREG_L1DM_DCPLB_ADDR12           ((void * volatile *)REG_L1DM_DCPLB_ADDR12)              /* L1DM Data Memory CPLB Address Registers */
#define pREG_L1DM_DCPLB_ADDR13           ((void * volatile *)REG_L1DM_DCPLB_ADDR13)              /* L1DM Data Memory CPLB Address Registers */
#define pREG_L1DM_DCPLB_ADDR14           ((void * volatile *)REG_L1DM_DCPLB_ADDR14)              /* L1DM Data Memory CPLB Address Registers */
#define pREG_L1DM_DCPLB_ADDR15           ((void * volatile *)REG_L1DM_DCPLB_ADDR15)              /* L1DM Data Memory CPLB Address Registers */
#define pREG_L1DM_DCPLB_DATA0            ((volatile uint32_t *)REG_L1DM_DCPLB_DATA0)             /* L1DM Data Memory CPLB Data Registers */
#define pREG_L1DM_DCPLB_DATA1            ((volatile uint32_t *)REG_L1DM_DCPLB_DATA1)             /* L1DM Data Memory CPLB Data Registers */
#define pREG_L1DM_DCPLB_DATA2            ((volatile uint32_t *)REG_L1DM_DCPLB_DATA2)             /* L1DM Data Memory CPLB Data Registers */
#define pREG_L1DM_DCPLB_DATA3            ((volatile uint32_t *)REG_L1DM_DCPLB_DATA3)             /* L1DM Data Memory CPLB Data Registers */
#define pREG_L1DM_DCPLB_DATA4            ((volatile uint32_t *)REG_L1DM_DCPLB_DATA4)             /* L1DM Data Memory CPLB Data Registers */
#define pREG_L1DM_DCPLB_DATA5            ((volatile uint32_t *)REG_L1DM_DCPLB_DATA5)             /* L1DM Data Memory CPLB Data Registers */
#define pREG_L1DM_DCPLB_DATA6            ((volatile uint32_t *)REG_L1DM_DCPLB_DATA6)             /* L1DM Data Memory CPLB Data Registers */
#define pREG_L1DM_DCPLB_DATA7            ((volatile uint32_t *)REG_L1DM_DCPLB_DATA7)             /* L1DM Data Memory CPLB Data Registers */
#define pREG_L1DM_DCPLB_DATA8            ((volatile uint32_t *)REG_L1DM_DCPLB_DATA8)             /* L1DM Data Memory CPLB Data Registers */
#define pREG_L1DM_DCPLB_DATA9            ((volatile uint32_t *)REG_L1DM_DCPLB_DATA9)             /* L1DM Data Memory CPLB Data Registers */
#define pREG_L1DM_DCPLB_DATA10           ((volatile uint32_t *)REG_L1DM_DCPLB_DATA10)            /* L1DM Data Memory CPLB Data Registers */
#define pREG_L1DM_DCPLB_DATA11           ((volatile uint32_t *)REG_L1DM_DCPLB_DATA11)            /* L1DM Data Memory CPLB Data Registers */
#define pREG_L1DM_DCPLB_DATA12           ((volatile uint32_t *)REG_L1DM_DCPLB_DATA12)            /* L1DM Data Memory CPLB Data Registers */
#define pREG_L1DM_DCPLB_DATA13           ((volatile uint32_t *)REG_L1DM_DCPLB_DATA13)            /* L1DM Data Memory CPLB Data Registers */
#define pREG_L1DM_DCPLB_DATA14           ((volatile uint32_t *)REG_L1DM_DCPLB_DATA14)            /* L1DM Data Memory CPLB Data Registers */
#define pREG_L1DM_DCPLB_DATA15           ((volatile uint32_t *)REG_L1DM_DCPLB_DATA15)            /* L1DM Data Memory CPLB Data Registers */


/* =========================================================================
       L1IM
   ========================================================================= */
#define pREG_L1IM_ICTL                   ((volatile uint32_t *)REG_L1IM_ICTL)                    /* L1IM Instruction Memory Control Register */
#define pREG_L1IM_ISTAT                  ((volatile uint32_t *)REG_L1IM_ISTAT)                   /* L1IM Instruction Memory CPLB Status Register */
#define pREG_L1IM_ICPLB_FAULT_ADDR       ((void * volatile *)REG_L1IM_ICPLB_FAULT_ADDR)          /* L1IM Instruction Memory CPLB Fault Address Register */
#define pREG_L1IM_ICPLB_DFLT             ((volatile uint32_t *)REG_L1IM_ICPLB_DFLT)              /* L1IM Instruction Memory CPLB Default Settings Register */
#define pREG_L1IM_IPERR_STAT             ((volatile uint32_t *)REG_L1IM_IPERR_STAT)              /* L1IM Instruction Parity Error Status Register */
#define pREG_L1IM_ICPLB_ADDR0            ((void * volatile *)REG_L1IM_ICPLB_ADDR0)               /* L1IM Instruction Memory CPLB Address Registers */
#define pREG_L1IM_ICPLB_ADDR1            ((void * volatile *)REG_L1IM_ICPLB_ADDR1)               /* L1IM Instruction Memory CPLB Address Registers */
#define pREG_L1IM_ICPLB_ADDR2            ((void * volatile *)REG_L1IM_ICPLB_ADDR2)               /* L1IM Instruction Memory CPLB Address Registers */
#define pREG_L1IM_ICPLB_ADDR3            ((void * volatile *)REG_L1IM_ICPLB_ADDR3)               /* L1IM Instruction Memory CPLB Address Registers */
#define pREG_L1IM_ICPLB_ADDR4            ((void * volatile *)REG_L1IM_ICPLB_ADDR4)               /* L1IM Instruction Memory CPLB Address Registers */
#define pREG_L1IM_ICPLB_ADDR5            ((void * volatile *)REG_L1IM_ICPLB_ADDR5)               /* L1IM Instruction Memory CPLB Address Registers */
#define pREG_L1IM_ICPLB_ADDR6            ((void * volatile *)REG_L1IM_ICPLB_ADDR6)               /* L1IM Instruction Memory CPLB Address Registers */
#define pREG_L1IM_ICPLB_ADDR7            ((void * volatile *)REG_L1IM_ICPLB_ADDR7)               /* L1IM Instruction Memory CPLB Address Registers */
#define pREG_L1IM_ICPLB_ADDR8            ((void * volatile *)REG_L1IM_ICPLB_ADDR8)               /* L1IM Instruction Memory CPLB Address Registers */
#define pREG_L1IM_ICPLB_ADDR9            ((void * volatile *)REG_L1IM_ICPLB_ADDR9)               /* L1IM Instruction Memory CPLB Address Registers */
#define pREG_L1IM_ICPLB_ADDR10           ((void * volatile *)REG_L1IM_ICPLB_ADDR10)              /* L1IM Instruction Memory CPLB Address Registers */
#define pREG_L1IM_ICPLB_ADDR11           ((void * volatile *)REG_L1IM_ICPLB_ADDR11)              /* L1IM Instruction Memory CPLB Address Registers */
#define pREG_L1IM_ICPLB_ADDR12           ((void * volatile *)REG_L1IM_ICPLB_ADDR12)              /* L1IM Instruction Memory CPLB Address Registers */
#define pREG_L1IM_ICPLB_ADDR13           ((void * volatile *)REG_L1IM_ICPLB_ADDR13)              /* L1IM Instruction Memory CPLB Address Registers */
#define pREG_L1IM_ICPLB_ADDR14           ((void * volatile *)REG_L1IM_ICPLB_ADDR14)              /* L1IM Instruction Memory CPLB Address Registers */
#define pREG_L1IM_ICPLB_ADDR15           ((void * volatile *)REG_L1IM_ICPLB_ADDR15)              /* L1IM Instruction Memory CPLB Address Registers */
#define pREG_L1IM_ICPLB_DATA0            ((volatile uint32_t *)REG_L1IM_ICPLB_DATA0)             /* L1IM Instruction Memory CPLB Data Registers */
#define pREG_L1IM_ICPLB_DATA1            ((volatile uint32_t *)REG_L1IM_ICPLB_DATA1)             /* L1IM Instruction Memory CPLB Data Registers */
#define pREG_L1IM_ICPLB_DATA2            ((volatile uint32_t *)REG_L1IM_ICPLB_DATA2)             /* L1IM Instruction Memory CPLB Data Registers */
#define pREG_L1IM_ICPLB_DATA3            ((volatile uint32_t *)REG_L1IM_ICPLB_DATA3)             /* L1IM Instruction Memory CPLB Data Registers */
#define pREG_L1IM_ICPLB_DATA4            ((volatile uint32_t *)REG_L1IM_ICPLB_DATA4)             /* L1IM Instruction Memory CPLB Data Registers */
#define pREG_L1IM_ICPLB_DATA5            ((volatile uint32_t *)REG_L1IM_ICPLB_DATA5)             /* L1IM Instruction Memory CPLB Data Registers */
#define pREG_L1IM_ICPLB_DATA6            ((volatile uint32_t *)REG_L1IM_ICPLB_DATA6)             /* L1IM Instruction Memory CPLB Data Registers */
#define pREG_L1IM_ICPLB_DATA7            ((volatile uint32_t *)REG_L1IM_ICPLB_DATA7)             /* L1IM Instruction Memory CPLB Data Registers */
#define pREG_L1IM_ICPLB_DATA8            ((volatile uint32_t *)REG_L1IM_ICPLB_DATA8)             /* L1IM Instruction Memory CPLB Data Registers */
#define pREG_L1IM_ICPLB_DATA9            ((volatile uint32_t *)REG_L1IM_ICPLB_DATA9)             /* L1IM Instruction Memory CPLB Data Registers */
#define pREG_L1IM_ICPLB_DATA10           ((volatile uint32_t *)REG_L1IM_ICPLB_DATA10)            /* L1IM Instruction Memory CPLB Data Registers */
#define pREG_L1IM_ICPLB_DATA11           ((volatile uint32_t *)REG_L1IM_ICPLB_DATA11)            /* L1IM Instruction Memory CPLB Data Registers */
#define pREG_L1IM_ICPLB_DATA12           ((volatile uint32_t *)REG_L1IM_ICPLB_DATA12)            /* L1IM Instruction Memory CPLB Data Registers */
#define pREG_L1IM_ICPLB_DATA13           ((volatile uint32_t *)REG_L1IM_ICPLB_DATA13)            /* L1IM Instruction Memory CPLB Data Registers */
#define pREG_L1IM_ICPLB_DATA14           ((volatile uint32_t *)REG_L1IM_ICPLB_DATA14)            /* L1IM Instruction Memory CPLB Data Registers */
#define pREG_L1IM_ICPLB_DATA15           ((volatile uint32_t *)REG_L1IM_ICPLB_DATA15)            /* L1IM Instruction Memory CPLB Data Registers */


/* =========================================================================
       ICU
   ========================================================================= */
#define pEVT0                            ((void * volatile *)EVT0)                               /* Event Vector Table Registers */
#define pEVT1                            ((void * volatile *)EVT1)                               /* Event Vector Table Registers */
#define pEVT2                            ((void * volatile *)EVT2)                               /* Event Vector Table Registers */
#define pEVT3                            ((void * volatile *)EVT3)                               /* Event Vector Table Registers */
#define pEVT4                            ((void * volatile *)EVT4)                               /* Event Vector Table Registers */
#define pEVT5                            ((void * volatile *)EVT5)                               /* Event Vector Table Registers */
#define pEVT6                            ((void * volatile *)EVT6)                               /* Event Vector Table Registers */
#define pEVT7                            ((void * volatile *)EVT7)                               /* Event Vector Table Registers */
#define pEVT8                            ((void * volatile *)EVT8)                               /* Event Vector Table Registers */
#define pEVT9                            ((void * volatile *)EVT9)                               /* Event Vector Table Registers */
#define pEVT10                           ((void * volatile *)EVT10)                              /* Event Vector Table Registers */
#define pEVT11                           ((void * volatile *)EVT11)                              /* Event Vector Table Registers */
#define pEVT12                           ((void * volatile *)EVT12)                              /* Event Vector Table Registers */
#define pEVT13                           ((void * volatile *)EVT13)                              /* Event Vector Table Registers */
#define pEVT14                           ((void * volatile *)EVT14)                              /* Event Vector Table Registers */
#define pEVT15                           ((void * volatile *)EVT15)                              /* Event Vector Table Registers */
#define pEVT_OVERRIDE                    ((volatile uint32_t *)EVT_OVERRIDE)                     /* Event Vector Table Override Register */
#define pIMASK                           ((volatile uint32_t *)IMASK)                            /* Interrupt Mask Register */
#define pIPEND                           ((volatile uint32_t *)IPEND)                            /* Interrupt Pending Register */
#define pILAT                            ((volatile uint32_t *)ILAT)                             /* Interrupt Latch Register */
#define pREG_ICU_CID                     ((volatile uint32_t *)REG_ICU_CID)                      /* ICU Context ID Register */
#define pCEC_SID                         ((volatile uint32_t *)CEC_SID)                          /* System ID Register */


/* =========================================================================
       TMR
   ========================================================================= */
#define pTCNTL                           ((volatile uint32_t *)TCNTL)                            /* Timer Control Register */
#define pTPERIOD                         ((volatile uint32_t *)TPERIOD)                          /* Timer Period Register */
#define pTSCALE                          ((volatile uint32_t *)TSCALE)                           /* Timer Scale Register */
#define pTCOUNT                          ((volatile uint32_t *)TCOUNT)                           /* Timer Count Register */


/* =========================================================================
       DBG
   ========================================================================= */
#define pDSPID                           ((volatile uint32_t *)DSPID)                            /* DSP Identification Register */


/* =========================================================================
       WP
   ========================================================================= */
#define pWPIACTL                         ((volatile uint32_t *)WPIACTL)                          /* Watchpoint Instruction Address Control Register 01 */
#define pWPIA0                           ((void * volatile *)WPIA0)                              /* Watchpoint Instruction Address Register */
#define pWPIA1                           ((void * volatile *)WPIA1)                              /* Watchpoint Instruction Address Register */
#define pWPIA2                           ((void * volatile *)WPIA2)                              /* Watchpoint Instruction Address Register */
#define pWPIA3                           ((void * volatile *)WPIA3)                              /* Watchpoint Instruction Address Register */
#define pWPIA4                           ((void * volatile *)WPIA4)                              /* Watchpoint Instruction Address Register */
#define pWPIA5                           ((void * volatile *)WPIA5)                              /* Watchpoint Instruction Address Register */
#define pWPIACNT0                        ((volatile uint32_t *)WPIACNT0)                         /* Watchpoint Instruction Address Count Register */
#define pWPIACNT1                        ((volatile uint32_t *)WPIACNT1)                         /* Watchpoint Instruction Address Count Register */
#define pWPIACNT2                        ((volatile uint32_t *)WPIACNT2)                         /* Watchpoint Instruction Address Count Register */
#define pWPIACNT3                        ((volatile uint32_t *)WPIACNT3)                         /* Watchpoint Instruction Address Count Register */
#define pWPIACNT4                        ((volatile uint32_t *)WPIACNT4)                         /* Watchpoint Instruction Address Count Register */
#define pWPIACNT5                        ((volatile uint32_t *)WPIACNT5)                         /* Watchpoint Instruction Address Count Register */
#define pWPDACTL                         ((volatile uint32_t *)WPDACTL)                          /* Watchpoint Data Address Control Register */
#define pWPDA0                           ((void * volatile *)WPDA0)                              /* Watchpoint Data Address Register */
#define pWPDA1                           ((void * volatile *)WPDA1)                              /* Watchpoint Data Address Register */
#define pWPDACNT0                        ((volatile uint32_t *)WPDACNT0)                         /* Watchpoint Data Address Count Value Register */
#define pWPDACNT1                        ((volatile uint32_t *)WPDACNT1)                         /* Watchpoint Data Address Count Value Register */
#define pWPSTAT                          ((volatile uint32_t *)WPSTAT)                           /* Watchpoint Status Register */


/* =========================================================================
       PF
   ========================================================================= */
#define pPFCTL                           ((volatile uint32_t *)PFCTL)                            /* Control Register */
#define pPFCNTR0                         ((volatile uint32_t *)PFCNTR0)                          /* Counter 0 Register */
#define pPFCNTR1                         ((volatile uint32_t *)PFCNTR1)                          /* Counter 1 Register */


/* =========================================================================
       OPT
   ========================================================================= */
#define pREG_OPT_FEATURE0                ((volatile uint32_t *)REG_OPT_FEATURE0)                 /* OPT Feature Core 0  Register */


/* =========================================================================
       BP
   ========================================================================= */
#define pREG_BP_CFG                      ((volatile uint32_t *)REG_BP_CFG)                       /* BP Configuration Register */
#define pREG_BP_STAT                     ((volatile uint32_t *)REG_BP_STAT)                      /* BP Status Register */


/* =========================================================================
       RCU0
   ========================================================================= */
#define pREG_RCU0_CTL                    ((volatile uint32_t *)REG_RCU0_CTL)                     /* RCU0 Control Register */
#define pREG_RCU0_STAT                   ((volatile uint32_t *)REG_RCU0_STAT)                    /* RCU0 Status Register */
#define pREG_RCU0_CRCTL                  ((volatile uint32_t *)REG_RCU0_CRCTL)                   /* RCU0 Core Reset Control Register */
#define pREG_RCU0_CRSTAT                 ((volatile uint32_t *)REG_RCU0_CRSTAT)                  /* RCU0 Core Reset Status Register */
#define pREG_RCU0_SIDIS                  ((volatile uint32_t *)REG_RCU0_SIDIS)                   /* RCU0 System Interface Disable Register */
#define pREG_RCU0_SISTAT                 ((volatile uint32_t *)REG_RCU0_SISTAT)                  /* RCU0 System Interface Status Register */
#define pREG_RCU0_SVECT_LCK              ((volatile uint32_t *)REG_RCU0_SVECT_LCK)               /* RCU0 SVECT Lock Register */
#define pREG_RCU0_BCODE                  ((volatile uint32_t *)REG_RCU0_BCODE)                   /* RCU0 Boot Code Register */
#define pREG_RCU0_SVECT0                 ((volatile uint32_t *)REG_RCU0_SVECT0)                  /* RCU0 Software Vector Register 0 */
#define pREG_RCU0_MSG                    ((volatile uint32_t *)REG_RCU0_MSG)                     /* RCU0 Message Register */
#define pREG_RCU0_MSG_SET                ((volatile uint32_t *)REG_RCU0_MSG_SET)                 /* RCU0 Message Set Bits Register */
#define pREG_RCU0_MSG_CLR                ((volatile uint32_t *)REG_RCU0_MSG_CLR)                 /* RCU0 Message Clear Bits Register */
#define pREG_RCU0_REVID                  ((volatile uint32_t *)REG_RCU0_REVID)                   /* RCU0 Revision ID Register */


/* =========================================================================
       TRU0
   ========================================================================= */
#define pREG_TRU0_SSR0                   ((volatile uint32_t *)REG_TRU0_SSR0)                    /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR1                   ((volatile uint32_t *)REG_TRU0_SSR1)                    /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR2                   ((volatile uint32_t *)REG_TRU0_SSR2)                    /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR3                   ((volatile uint32_t *)REG_TRU0_SSR3)                    /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR4                   ((volatile uint32_t *)REG_TRU0_SSR4)                    /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR5                   ((volatile uint32_t *)REG_TRU0_SSR5)                    /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR6                   ((volatile uint32_t *)REG_TRU0_SSR6)                    /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR7                   ((volatile uint32_t *)REG_TRU0_SSR7)                    /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR8                   ((volatile uint32_t *)REG_TRU0_SSR8)                    /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR9                   ((volatile uint32_t *)REG_TRU0_SSR9)                    /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR10                  ((volatile uint32_t *)REG_TRU0_SSR10)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR11                  ((volatile uint32_t *)REG_TRU0_SSR11)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR12                  ((volatile uint32_t *)REG_TRU0_SSR12)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR13                  ((volatile uint32_t *)REG_TRU0_SSR13)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR14                  ((volatile uint32_t *)REG_TRU0_SSR14)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR15                  ((volatile uint32_t *)REG_TRU0_SSR15)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR16                  ((volatile uint32_t *)REG_TRU0_SSR16)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR17                  ((volatile uint32_t *)REG_TRU0_SSR17)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR18                  ((volatile uint32_t *)REG_TRU0_SSR18)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR19                  ((volatile uint32_t *)REG_TRU0_SSR19)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR20                  ((volatile uint32_t *)REG_TRU0_SSR20)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR21                  ((volatile uint32_t *)REG_TRU0_SSR21)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR22                  ((volatile uint32_t *)REG_TRU0_SSR22)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR23                  ((volatile uint32_t *)REG_TRU0_SSR23)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR24                  ((volatile uint32_t *)REG_TRU0_SSR24)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR25                  ((volatile uint32_t *)REG_TRU0_SSR25)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR26                  ((volatile uint32_t *)REG_TRU0_SSR26)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR27                  ((volatile uint32_t *)REG_TRU0_SSR27)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR28                  ((volatile uint32_t *)REG_TRU0_SSR28)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR29                  ((volatile uint32_t *)REG_TRU0_SSR29)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR30                  ((volatile uint32_t *)REG_TRU0_SSR30)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR31                  ((volatile uint32_t *)REG_TRU0_SSR31)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR32                  ((volatile uint32_t *)REG_TRU0_SSR32)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR33                  ((volatile uint32_t *)REG_TRU0_SSR33)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR34                  ((volatile uint32_t *)REG_TRU0_SSR34)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR35                  ((volatile uint32_t *)REG_TRU0_SSR35)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR36                  ((volatile uint32_t *)REG_TRU0_SSR36)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR37                  ((volatile uint32_t *)REG_TRU0_SSR37)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR38                  ((volatile uint32_t *)REG_TRU0_SSR38)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR39                  ((volatile uint32_t *)REG_TRU0_SSR39)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR40                  ((volatile uint32_t *)REG_TRU0_SSR40)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR41                  ((volatile uint32_t *)REG_TRU0_SSR41)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR42                  ((volatile uint32_t *)REG_TRU0_SSR42)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR43                  ((volatile uint32_t *)REG_TRU0_SSR43)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR44                  ((volatile uint32_t *)REG_TRU0_SSR44)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR45                  ((volatile uint32_t *)REG_TRU0_SSR45)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR46                  ((volatile uint32_t *)REG_TRU0_SSR46)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR47                  ((volatile uint32_t *)REG_TRU0_SSR47)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR48                  ((volatile uint32_t *)REG_TRU0_SSR48)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR49                  ((volatile uint32_t *)REG_TRU0_SSR49)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR50                  ((volatile uint32_t *)REG_TRU0_SSR50)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR51                  ((volatile uint32_t *)REG_TRU0_SSR51)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR52                  ((volatile uint32_t *)REG_TRU0_SSR52)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR53                  ((volatile uint32_t *)REG_TRU0_SSR53)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR54                  ((volatile uint32_t *)REG_TRU0_SSR54)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR55                  ((volatile uint32_t *)REG_TRU0_SSR55)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR56                  ((volatile uint32_t *)REG_TRU0_SSR56)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR57                  ((volatile uint32_t *)REG_TRU0_SSR57)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR58                  ((volatile uint32_t *)REG_TRU0_SSR58)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR59                  ((volatile uint32_t *)REG_TRU0_SSR59)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR60                  ((volatile uint32_t *)REG_TRU0_SSR60)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR61                  ((volatile uint32_t *)REG_TRU0_SSR61)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR62                  ((volatile uint32_t *)REG_TRU0_SSR62)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR63                  ((volatile uint32_t *)REG_TRU0_SSR63)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR64                  ((volatile uint32_t *)REG_TRU0_SSR64)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR65                  ((volatile uint32_t *)REG_TRU0_SSR65)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR66                  ((volatile uint32_t *)REG_TRU0_SSR66)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR67                  ((volatile uint32_t *)REG_TRU0_SSR67)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR68                  ((volatile uint32_t *)REG_TRU0_SSR68)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR69                  ((volatile uint32_t *)REG_TRU0_SSR69)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR70                  ((volatile uint32_t *)REG_TRU0_SSR70)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR71                  ((volatile uint32_t *)REG_TRU0_SSR71)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR72                  ((volatile uint32_t *)REG_TRU0_SSR72)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR73                  ((volatile uint32_t *)REG_TRU0_SSR73)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR74                  ((volatile uint32_t *)REG_TRU0_SSR74)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR75                  ((volatile uint32_t *)REG_TRU0_SSR75)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR76                  ((volatile uint32_t *)REG_TRU0_SSR76)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR77                  ((volatile uint32_t *)REG_TRU0_SSR77)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR78                  ((volatile uint32_t *)REG_TRU0_SSR78)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR79                  ((volatile uint32_t *)REG_TRU0_SSR79)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR80                  ((volatile uint32_t *)REG_TRU0_SSR80)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR81                  ((volatile uint32_t *)REG_TRU0_SSR81)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR82                  ((volatile uint32_t *)REG_TRU0_SSR82)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR83                  ((volatile uint32_t *)REG_TRU0_SSR83)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR84                  ((volatile uint32_t *)REG_TRU0_SSR84)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR85                  ((volatile uint32_t *)REG_TRU0_SSR85)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR86                  ((volatile uint32_t *)REG_TRU0_SSR86)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR87                  ((volatile uint32_t *)REG_TRU0_SSR87)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR88                  ((volatile uint32_t *)REG_TRU0_SSR88)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR89                  ((volatile uint32_t *)REG_TRU0_SSR89)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR90                  ((volatile uint32_t *)REG_TRU0_SSR90)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR91                  ((volatile uint32_t *)REG_TRU0_SSR91)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR92                  ((volatile uint32_t *)REG_TRU0_SSR92)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR93                  ((volatile uint32_t *)REG_TRU0_SSR93)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR94                  ((volatile uint32_t *)REG_TRU0_SSR94)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR95                  ((volatile uint32_t *)REG_TRU0_SSR95)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR96                  ((volatile uint32_t *)REG_TRU0_SSR96)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR97                  ((volatile uint32_t *)REG_TRU0_SSR97)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR98                  ((volatile uint32_t *)REG_TRU0_SSR98)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR99                  ((volatile uint32_t *)REG_TRU0_SSR99)                   /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR100                 ((volatile uint32_t *)REG_TRU0_SSR100)                  /* TRU0 Slave Select Register */
#define pREG_TRU0_SSR101                 ((volatile uint32_t *)REG_TRU0_SSR101)                  /* TRU0 Slave Select Register */
#define pREG_TRU0_MTR                    ((volatile uint32_t *)REG_TRU0_MTR)                     /* TRU0 Master Trigger Register */
#define pREG_TRU0_ERRADDR                ((volatile uint32_t *)REG_TRU0_ERRADDR)                 /* TRU0 Error Address Register */
#define pREG_TRU0_STAT                   ((volatile uint32_t *)REG_TRU0_STAT)                    /* TRU0 Status Information Register */
#define pREG_TRU0_GCTL                   ((volatile uint32_t *)REG_TRU0_GCTL)                    /* TRU0 Global Control Register */


/* =========================================================================
       CGU0
   ========================================================================= */
#define pREG_CGU0_CTL                    ((volatile uint32_t *)REG_CGU0_CTL)                     /* CGU0 Control Register */
#define pREG_CGU0_PLLCTL                 ((volatile uint32_t *)REG_CGU0_PLLCTL)                  /* CGU0 PLL Control Register */
#define pREG_CGU0_STAT                   ((volatile uint32_t *)REG_CGU0_STAT)                    /* CGU0 Status Register */
#define pREG_CGU0_DIV                    ((volatile uint32_t *)REG_CGU0_DIV)                     /* CGU0 Clocks Divisor Register */
#define pREG_CGU0_CLKOUTSEL              ((volatile uint32_t *)REG_CGU0_CLKOUTSEL)               /* CGU0 CLKOUT Select Register */
#define pREG_CGU0_TSCTL                  ((volatile uint32_t *)REG_CGU0_TSCTL)                   /* CGU0 Timestamp Control Register */
#define pREG_CGU0_TSVALUE0               ((volatile uint32_t *)REG_CGU0_TSVALUE0)                /* CGU0 Timestamp Counter Initial 32 LSB Value Register */
#define pREG_CGU0_TSVALUE1               ((volatile uint32_t *)REG_CGU0_TSVALUE1)                /* CGU0 Timestamp Counter Initial MSB Value Register */
#define pREG_CGU0_TSCOUNT0               ((volatile uint32_t *)REG_CGU0_TSCOUNT0)                /* CGU0 Timestamp Counter 32 LSB */
#define pREG_CGU0_TSCOUNT1               ((volatile uint32_t *)REG_CGU0_TSCOUNT1)                /* CGU0 Timestamp Counter 32 MSB Register */
#define pREG_CGU0_CCBF_DIS               ((volatile uint32_t *)REG_CGU0_CCBF_DIS)                /* CGU0 Core Clock Buffer Disable Register */
#define pREG_CGU0_CCBF_STAT              ((volatile uint32_t *)REG_CGU0_CCBF_STAT)               /* CGU0 Core Clock Buffer Status Register */
#define pREG_CGU0_SCBF_DIS               ((volatile uint32_t *)REG_CGU0_SCBF_DIS)                /* CGU0 System Clock Buffer Disable Register */
#define pREG_CGU0_SCBF_STAT              ((volatile uint32_t *)REG_CGU0_SCBF_STAT)               /* CGU0 System Clock Buffer Status Register */
#define pREG_CGU0_REVID                  ((volatile uint32_t *)REG_CGU0_REVID)                   /* CGU0 Revision ID Register */


/* =========================================================================
       DPM0
   ========================================================================= */
#define pREG_DPM0_CTL                    ((volatile uint32_t *)REG_DPM0_CTL)                     /* DPM0 Control Register */
#define pREG_DPM0_STAT                   ((volatile uint32_t *)REG_DPM0_STAT)                    /* DPM0 Status Register */
#define pREG_DPM0_WAKE_EN                ((volatile uint32_t *)REG_DPM0_WAKE_EN)                 /* DPM0 Wakeup Enable Register */
#define pREG_DPM0_WAKE_POL               ((volatile uint32_t *)REG_DPM0_WAKE_POL)                /* DPM0 Wakeup Polarity Register */
#define pREG_DPM0_WAKE_STAT              ((volatile uint32_t *)REG_DPM0_WAKE_STAT)               /* DPM0 Wakeup Status Register */
#define pREG_DPM0_HIB_DIS                ((volatile uint32_t *)REG_DPM0_HIB_DIS)                 /* DPM0 Hibernate Disable Register */
#define pREG_DPM0_PGCNTR                 ((volatile uint32_t *)REG_DPM0_PGCNTR)                  /* DPM0 Power Good Counter Register */
#define pREG_DPM0_RESTORE0               ((volatile uint32_t *)REG_DPM0_RESTORE0)                /* DPM0 Restore Registers */
#define pREG_DPM0_RESTORE1               ((volatile uint32_t *)REG_DPM0_RESTORE1)                /* DPM0 Restore Registers */
#define pREG_DPM0_RESTORE2               ((volatile uint32_t *)REG_DPM0_RESTORE2)                /* DPM0 Restore Registers */
#define pREG_DPM0_RESTORE3               ((volatile uint32_t *)REG_DPM0_RESTORE3)                /* DPM0 Restore Registers */
#define pREG_DPM0_RESTORE4               ((volatile uint32_t *)REG_DPM0_RESTORE4)                /* DPM0 Restore Registers */
#define pREG_DPM0_RESTORE5               ((volatile uint32_t *)REG_DPM0_RESTORE5)                /* DPM0 Restore Registers */
#define pREG_DPM0_RESTORE6               ((volatile uint32_t *)REG_DPM0_RESTORE6)                /* DPM0 Restore Registers */
#define pREG_DPM0_RESTORE7               ((volatile uint32_t *)REG_DPM0_RESTORE7)                /* DPM0 Restore Registers */
#define pREG_DPM0_RESTORE8               ((volatile uint32_t *)REG_DPM0_RESTORE8)                /* DPM0 Restore Registers */
#define pREG_DPM0_RESTORE9               ((volatile uint32_t *)REG_DPM0_RESTORE9)                /* DPM0 Restore Registers */
#define pREG_DPM0_RESTORE10              ((volatile uint32_t *)REG_DPM0_RESTORE10)               /* DPM0 Restore Registers */
#define pREG_DPM0_RESTORE11              ((volatile uint32_t *)REG_DPM0_RESTORE11)               /* DPM0 Restore Registers */
#define pREG_DPM0_RESTORE12              ((volatile uint32_t *)REG_DPM0_RESTORE12)               /* DPM0 Restore Registers */
#define pREG_DPM0_RESTORE13              ((volatile uint32_t *)REG_DPM0_RESTORE13)               /* DPM0 Restore Registers */
#define pREG_DPM0_RESTORE14              ((volatile uint32_t *)REG_DPM0_RESTORE14)               /* DPM0 Restore Registers */
#define pREG_DPM0_RESTORE15              ((volatile uint32_t *)REG_DPM0_RESTORE15)               /* DPM0 Restore Registers */
#define pREG_DPM0_REVID                  ((volatile uint32_t *)REG_DPM0_REVID)                   /* DPM0 Revision ID */


/* =========================================================================
       SEC0
   ========================================================================= */

/*    SEC Core Interface (SCI) Registers    */
#define pREG_SEC0_CCTL0                  ((volatile uint32_t *)REG_SEC0_CCTL0)                   /* SEC0 SCI Control Register n */
#define pREG_SEC0_CSTAT0                 ((volatile uint32_t *)REG_SEC0_CSTAT0)                  /* SEC0 SCI Status Register n */
#define pREG_SEC0_CPND0                  ((volatile uint32_t *)REG_SEC0_CPND0)                   /* SEC0 Core Pending Register n */
#define pREG_SEC0_CACT0                  ((volatile uint32_t *)REG_SEC0_CACT0)                   /* SEC0 SCI Active Register n */
#define pREG_SEC0_CPMSK0                 ((volatile uint32_t *)REG_SEC0_CPMSK0)                  /* SEC0 SCI Priority Mask Register n */
#define pREG_SEC0_CGMSK0                 ((volatile uint32_t *)REG_SEC0_CGMSK0)                  /* SEC0 SCI Group Mask Register n */
#define pREG_SEC0_CPLVL0                 ((volatile uint32_t *)REG_SEC0_CPLVL0)                  /* SEC0 SCI Priority Level Register n */
#define pREG_SEC0_CSID0                  ((volatile uint32_t *)REG_SEC0_CSID0)                   /* SEC0 SCI Source ID Register n */

/*    SEC Fault Management Interface (SFI) Registers    */
#define pREG_SEC0_FCTL                   ((volatile uint32_t *)REG_SEC0_FCTL)                    /* SEC0 Fault Control Register */
#define pREG_SEC0_FSTAT                  ((volatile uint32_t *)REG_SEC0_FSTAT)                   /* SEC0 Fault Status Register */
#define pREG_SEC0_FSID                   ((volatile uint32_t *)REG_SEC0_FSID)                    /* SEC0 Fault Source ID Register */
#define pREG_SEC0_FEND                   ((volatile uint32_t *)REG_SEC0_FEND)                    /* SEC0 Fault End Register */
#define pREG_SEC0_FDLY                   ((volatile uint32_t *)REG_SEC0_FDLY)                    /* SEC0 Fault Delay Register */
#define pREG_SEC0_FDLY_CUR               ((volatile uint32_t *)REG_SEC0_FDLY_CUR)                /* SEC0 Fault Delay Current Register */
#define pREG_SEC0_FSRDLY                 ((volatile uint32_t *)REG_SEC0_FSRDLY)                  /* SEC0 Fault System Reset Delay Register */
#define pREG_SEC0_FSRDLY_CUR             ((volatile uint32_t *)REG_SEC0_FSRDLY_CUR)              /* SEC0 Fault System Reset Delay Current Register */
#define pREG_SEC0_FCOPP                  ((volatile uint32_t *)REG_SEC0_FCOPP)                   /* SEC0 Fault COP Period Register */
#define pREG_SEC0_FCOPP_CUR              ((volatile uint32_t *)REG_SEC0_FCOPP_CUR)               /* SEC0 Fault COP Period Current Register */

/*    SEC Global Registers    */
#define pREG_SEC0_GCTL                   ((volatile uint32_t *)REG_SEC0_GCTL)                    /* SEC0 Global Control Register */
#define pREG_SEC0_GSTAT                  ((volatile uint32_t *)REG_SEC0_GSTAT)                   /* SEC0 Global Status Register */
#define pREG_SEC0_RAISE                  ((volatile uint32_t *)REG_SEC0_RAISE)                   /* SEC0 Global Raise Register */
#define pREG_SEC0_END                    ((volatile uint32_t *)REG_SEC0_END)                     /* SEC0 Global End Register */

/*    SEC Source Interface (SSI) Registers    */
#define pREG_SEC0_SCTL0                  ((volatile uint32_t *)REG_SEC0_SCTL0)                   /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL1                  ((volatile uint32_t *)REG_SEC0_SCTL1)                   /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL2                  ((volatile uint32_t *)REG_SEC0_SCTL2)                   /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL3                  ((volatile uint32_t *)REG_SEC0_SCTL3)                   /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL4                  ((volatile uint32_t *)REG_SEC0_SCTL4)                   /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL5                  ((volatile uint32_t *)REG_SEC0_SCTL5)                   /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL6                  ((volatile uint32_t *)REG_SEC0_SCTL6)                   /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL7                  ((volatile uint32_t *)REG_SEC0_SCTL7)                   /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL8                  ((volatile uint32_t *)REG_SEC0_SCTL8)                   /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL9                  ((volatile uint32_t *)REG_SEC0_SCTL9)                   /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL10                 ((volatile uint32_t *)REG_SEC0_SCTL10)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL11                 ((volatile uint32_t *)REG_SEC0_SCTL11)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL12                 ((volatile uint32_t *)REG_SEC0_SCTL12)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL13                 ((volatile uint32_t *)REG_SEC0_SCTL13)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL14                 ((volatile uint32_t *)REG_SEC0_SCTL14)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL15                 ((volatile uint32_t *)REG_SEC0_SCTL15)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL16                 ((volatile uint32_t *)REG_SEC0_SCTL16)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL17                 ((volatile uint32_t *)REG_SEC0_SCTL17)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL18                 ((volatile uint32_t *)REG_SEC0_SCTL18)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL19                 ((volatile uint32_t *)REG_SEC0_SCTL19)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL20                 ((volatile uint32_t *)REG_SEC0_SCTL20)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL21                 ((volatile uint32_t *)REG_SEC0_SCTL21)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL22                 ((volatile uint32_t *)REG_SEC0_SCTL22)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL23                 ((volatile uint32_t *)REG_SEC0_SCTL23)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL24                 ((volatile uint32_t *)REG_SEC0_SCTL24)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL25                 ((volatile uint32_t *)REG_SEC0_SCTL25)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL26                 ((volatile uint32_t *)REG_SEC0_SCTL26)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL27                 ((volatile uint32_t *)REG_SEC0_SCTL27)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL28                 ((volatile uint32_t *)REG_SEC0_SCTL28)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL29                 ((volatile uint32_t *)REG_SEC0_SCTL29)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL30                 ((volatile uint32_t *)REG_SEC0_SCTL30)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL31                 ((volatile uint32_t *)REG_SEC0_SCTL31)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL32                 ((volatile uint32_t *)REG_SEC0_SCTL32)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL33                 ((volatile uint32_t *)REG_SEC0_SCTL33)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL34                 ((volatile uint32_t *)REG_SEC0_SCTL34)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL35                 ((volatile uint32_t *)REG_SEC0_SCTL35)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL36                 ((volatile uint32_t *)REG_SEC0_SCTL36)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL37                 ((volatile uint32_t *)REG_SEC0_SCTL37)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL38                 ((volatile uint32_t *)REG_SEC0_SCTL38)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL39                 ((volatile uint32_t *)REG_SEC0_SCTL39)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL40                 ((volatile uint32_t *)REG_SEC0_SCTL40)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL41                 ((volatile uint32_t *)REG_SEC0_SCTL41)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL42                 ((volatile uint32_t *)REG_SEC0_SCTL42)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL43                 ((volatile uint32_t *)REG_SEC0_SCTL43)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL44                 ((volatile uint32_t *)REG_SEC0_SCTL44)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL45                 ((volatile uint32_t *)REG_SEC0_SCTL45)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL46                 ((volatile uint32_t *)REG_SEC0_SCTL46)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL47                 ((volatile uint32_t *)REG_SEC0_SCTL47)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL48                 ((volatile uint32_t *)REG_SEC0_SCTL48)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL49                 ((volatile uint32_t *)REG_SEC0_SCTL49)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL50                 ((volatile uint32_t *)REG_SEC0_SCTL50)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL51                 ((volatile uint32_t *)REG_SEC0_SCTL51)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL52                 ((volatile uint32_t *)REG_SEC0_SCTL52)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL53                 ((volatile uint32_t *)REG_SEC0_SCTL53)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL54                 ((volatile uint32_t *)REG_SEC0_SCTL54)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL55                 ((volatile uint32_t *)REG_SEC0_SCTL55)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL56                 ((volatile uint32_t *)REG_SEC0_SCTL56)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL57                 ((volatile uint32_t *)REG_SEC0_SCTL57)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL58                 ((volatile uint32_t *)REG_SEC0_SCTL58)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL59                 ((volatile uint32_t *)REG_SEC0_SCTL59)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL60                 ((volatile uint32_t *)REG_SEC0_SCTL60)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL61                 ((volatile uint32_t *)REG_SEC0_SCTL61)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL62                 ((volatile uint32_t *)REG_SEC0_SCTL62)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL63                 ((volatile uint32_t *)REG_SEC0_SCTL63)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL64                 ((volatile uint32_t *)REG_SEC0_SCTL64)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL65                 ((volatile uint32_t *)REG_SEC0_SCTL65)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL66                 ((volatile uint32_t *)REG_SEC0_SCTL66)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL67                 ((volatile uint32_t *)REG_SEC0_SCTL67)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL68                 ((volatile uint32_t *)REG_SEC0_SCTL68)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL69                 ((volatile uint32_t *)REG_SEC0_SCTL69)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL70                 ((volatile uint32_t *)REG_SEC0_SCTL70)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL71                 ((volatile uint32_t *)REG_SEC0_SCTL71)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL72                 ((volatile uint32_t *)REG_SEC0_SCTL72)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL73                 ((volatile uint32_t *)REG_SEC0_SCTL73)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL74                 ((volatile uint32_t *)REG_SEC0_SCTL74)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL75                 ((volatile uint32_t *)REG_SEC0_SCTL75)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL76                 ((volatile uint32_t *)REG_SEC0_SCTL76)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL77                 ((volatile uint32_t *)REG_SEC0_SCTL77)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL78                 ((volatile uint32_t *)REG_SEC0_SCTL78)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL79                 ((volatile uint32_t *)REG_SEC0_SCTL79)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL80                 ((volatile uint32_t *)REG_SEC0_SCTL80)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL81                 ((volatile uint32_t *)REG_SEC0_SCTL81)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL82                 ((volatile uint32_t *)REG_SEC0_SCTL82)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL83                 ((volatile uint32_t *)REG_SEC0_SCTL83)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL84                 ((volatile uint32_t *)REG_SEC0_SCTL84)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL85                 ((volatile uint32_t *)REG_SEC0_SCTL85)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL86                 ((volatile uint32_t *)REG_SEC0_SCTL86)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL87                 ((volatile uint32_t *)REG_SEC0_SCTL87)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL88                 ((volatile uint32_t *)REG_SEC0_SCTL88)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL89                 ((volatile uint32_t *)REG_SEC0_SCTL89)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL90                 ((volatile uint32_t *)REG_SEC0_SCTL90)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL91                 ((volatile uint32_t *)REG_SEC0_SCTL91)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL92                 ((volatile uint32_t *)REG_SEC0_SCTL92)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL93                 ((volatile uint32_t *)REG_SEC0_SCTL93)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL94                 ((volatile uint32_t *)REG_SEC0_SCTL94)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL95                 ((volatile uint32_t *)REG_SEC0_SCTL95)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL96                 ((volatile uint32_t *)REG_SEC0_SCTL96)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL97                 ((volatile uint32_t *)REG_SEC0_SCTL97)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL98                 ((volatile uint32_t *)REG_SEC0_SCTL98)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL99                 ((volatile uint32_t *)REG_SEC0_SCTL99)                  /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL100                ((volatile uint32_t *)REG_SEC0_SCTL100)                 /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL101                ((volatile uint32_t *)REG_SEC0_SCTL101)                 /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL102                ((volatile uint32_t *)REG_SEC0_SCTL102)                 /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL103                ((volatile uint32_t *)REG_SEC0_SCTL103)                 /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL104                ((volatile uint32_t *)REG_SEC0_SCTL104)                 /* SEC0 Source Control Register n */
#define pREG_SEC0_SCTL105                ((volatile uint32_t *)REG_SEC0_SCTL105)                 /* SEC0 Source Control Register n */
#define pREG_SEC0_SSTAT0                 ((volatile uint32_t *)REG_SEC0_SSTAT0)                  /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT1                 ((volatile uint32_t *)REG_SEC0_SSTAT1)                  /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT2                 ((volatile uint32_t *)REG_SEC0_SSTAT2)                  /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT3                 ((volatile uint32_t *)REG_SEC0_SSTAT3)                  /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT4                 ((volatile uint32_t *)REG_SEC0_SSTAT4)                  /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT5                 ((volatile uint32_t *)REG_SEC0_SSTAT5)                  /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT6                 ((volatile uint32_t *)REG_SEC0_SSTAT6)                  /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT7                 ((volatile uint32_t *)REG_SEC0_SSTAT7)                  /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT8                 ((volatile uint32_t *)REG_SEC0_SSTAT8)                  /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT9                 ((volatile uint32_t *)REG_SEC0_SSTAT9)                  /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT10                ((volatile uint32_t *)REG_SEC0_SSTAT10)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT11                ((volatile uint32_t *)REG_SEC0_SSTAT11)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT12                ((volatile uint32_t *)REG_SEC0_SSTAT12)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT13                ((volatile uint32_t *)REG_SEC0_SSTAT13)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT14                ((volatile uint32_t *)REG_SEC0_SSTAT14)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT15                ((volatile uint32_t *)REG_SEC0_SSTAT15)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT16                ((volatile uint32_t *)REG_SEC0_SSTAT16)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT17                ((volatile uint32_t *)REG_SEC0_SSTAT17)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT18                ((volatile uint32_t *)REG_SEC0_SSTAT18)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT19                ((volatile uint32_t *)REG_SEC0_SSTAT19)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT20                ((volatile uint32_t *)REG_SEC0_SSTAT20)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT21                ((volatile uint32_t *)REG_SEC0_SSTAT21)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT22                ((volatile uint32_t *)REG_SEC0_SSTAT22)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT23                ((volatile uint32_t *)REG_SEC0_SSTAT23)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT24                ((volatile uint32_t *)REG_SEC0_SSTAT24)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT25                ((volatile uint32_t *)REG_SEC0_SSTAT25)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT26                ((volatile uint32_t *)REG_SEC0_SSTAT26)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT27                ((volatile uint32_t *)REG_SEC0_SSTAT27)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT28                ((volatile uint32_t *)REG_SEC0_SSTAT28)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT29                ((volatile uint32_t *)REG_SEC0_SSTAT29)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT30                ((volatile uint32_t *)REG_SEC0_SSTAT30)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT31                ((volatile uint32_t *)REG_SEC0_SSTAT31)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT32                ((volatile uint32_t *)REG_SEC0_SSTAT32)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT33                ((volatile uint32_t *)REG_SEC0_SSTAT33)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT34                ((volatile uint32_t *)REG_SEC0_SSTAT34)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT35                ((volatile uint32_t *)REG_SEC0_SSTAT35)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT36                ((volatile uint32_t *)REG_SEC0_SSTAT36)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT37                ((volatile uint32_t *)REG_SEC0_SSTAT37)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT38                ((volatile uint32_t *)REG_SEC0_SSTAT38)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT39                ((volatile uint32_t *)REG_SEC0_SSTAT39)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT40                ((volatile uint32_t *)REG_SEC0_SSTAT40)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT41                ((volatile uint32_t *)REG_SEC0_SSTAT41)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT42                ((volatile uint32_t *)REG_SEC0_SSTAT42)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT43                ((volatile uint32_t *)REG_SEC0_SSTAT43)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT44                ((volatile uint32_t *)REG_SEC0_SSTAT44)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT45                ((volatile uint32_t *)REG_SEC0_SSTAT45)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT46                ((volatile uint32_t *)REG_SEC0_SSTAT46)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT47                ((volatile uint32_t *)REG_SEC0_SSTAT47)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT48                ((volatile uint32_t *)REG_SEC0_SSTAT48)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT49                ((volatile uint32_t *)REG_SEC0_SSTAT49)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT50                ((volatile uint32_t *)REG_SEC0_SSTAT50)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT51                ((volatile uint32_t *)REG_SEC0_SSTAT51)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT52                ((volatile uint32_t *)REG_SEC0_SSTAT52)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT53                ((volatile uint32_t *)REG_SEC0_SSTAT53)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT54                ((volatile uint32_t *)REG_SEC0_SSTAT54)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT55                ((volatile uint32_t *)REG_SEC0_SSTAT55)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT56                ((volatile uint32_t *)REG_SEC0_SSTAT56)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT57                ((volatile uint32_t *)REG_SEC0_SSTAT57)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT58                ((volatile uint32_t *)REG_SEC0_SSTAT58)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT59                ((volatile uint32_t *)REG_SEC0_SSTAT59)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT60                ((volatile uint32_t *)REG_SEC0_SSTAT60)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT61                ((volatile uint32_t *)REG_SEC0_SSTAT61)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT62                ((volatile uint32_t *)REG_SEC0_SSTAT62)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT63                ((volatile uint32_t *)REG_SEC0_SSTAT63)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT64                ((volatile uint32_t *)REG_SEC0_SSTAT64)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT65                ((volatile uint32_t *)REG_SEC0_SSTAT65)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT66                ((volatile uint32_t *)REG_SEC0_SSTAT66)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT67                ((volatile uint32_t *)REG_SEC0_SSTAT67)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT68                ((volatile uint32_t *)REG_SEC0_SSTAT68)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT69                ((volatile uint32_t *)REG_SEC0_SSTAT69)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT70                ((volatile uint32_t *)REG_SEC0_SSTAT70)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT71                ((volatile uint32_t *)REG_SEC0_SSTAT71)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT72                ((volatile uint32_t *)REG_SEC0_SSTAT72)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT73                ((volatile uint32_t *)REG_SEC0_SSTAT73)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT74                ((volatile uint32_t *)REG_SEC0_SSTAT74)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT75                ((volatile uint32_t *)REG_SEC0_SSTAT75)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT76                ((volatile uint32_t *)REG_SEC0_SSTAT76)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT77                ((volatile uint32_t *)REG_SEC0_SSTAT77)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT78                ((volatile uint32_t *)REG_SEC0_SSTAT78)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT79                ((volatile uint32_t *)REG_SEC0_SSTAT79)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT80                ((volatile uint32_t *)REG_SEC0_SSTAT80)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT81                ((volatile uint32_t *)REG_SEC0_SSTAT81)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT82                ((volatile uint32_t *)REG_SEC0_SSTAT82)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT83                ((volatile uint32_t *)REG_SEC0_SSTAT83)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT84                ((volatile uint32_t *)REG_SEC0_SSTAT84)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT85                ((volatile uint32_t *)REG_SEC0_SSTAT85)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT86                ((volatile uint32_t *)REG_SEC0_SSTAT86)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT87                ((volatile uint32_t *)REG_SEC0_SSTAT87)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT88                ((volatile uint32_t *)REG_SEC0_SSTAT88)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT89                ((volatile uint32_t *)REG_SEC0_SSTAT89)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT90                ((volatile uint32_t *)REG_SEC0_SSTAT90)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT91                ((volatile uint32_t *)REG_SEC0_SSTAT91)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT92                ((volatile uint32_t *)REG_SEC0_SSTAT92)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT93                ((volatile uint32_t *)REG_SEC0_SSTAT93)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT94                ((volatile uint32_t *)REG_SEC0_SSTAT94)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT95                ((volatile uint32_t *)REG_SEC0_SSTAT95)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT96                ((volatile uint32_t *)REG_SEC0_SSTAT96)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT97                ((volatile uint32_t *)REG_SEC0_SSTAT97)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT98                ((volatile uint32_t *)REG_SEC0_SSTAT98)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT99                ((volatile uint32_t *)REG_SEC0_SSTAT99)                 /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT100               ((volatile uint32_t *)REG_SEC0_SSTAT100)                /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT101               ((volatile uint32_t *)REG_SEC0_SSTAT101)                /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT102               ((volatile uint32_t *)REG_SEC0_SSTAT102)                /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT103               ((volatile uint32_t *)REG_SEC0_SSTAT103)                /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT104               ((volatile uint32_t *)REG_SEC0_SSTAT104)                /* SEC0 Source Status Register n */
#define pREG_SEC0_SSTAT105               ((volatile uint32_t *)REG_SEC0_SSTAT105)                /* SEC0 Source Status Register n */


/* =========================================================================
       SPU0
   ========================================================================= */
#define pREG_SPU0_CTL                    ((volatile uint32_t *)REG_SPU0_CTL)                     /* SPU0 Control Register */
#define pREG_SPU0_STAT                   ((volatile uint32_t *)REG_SPU0_STAT)                    /* SPU0 Status Register */
#define pREG_SPU0_WP0                    ((volatile uint32_t *)REG_SPU0_WP0)                     /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP1                    ((volatile uint32_t *)REG_SPU0_WP1)                     /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP2                    ((volatile uint32_t *)REG_SPU0_WP2)                     /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP3                    ((volatile uint32_t *)REG_SPU0_WP3)                     /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP4                    ((volatile uint32_t *)REG_SPU0_WP4)                     /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP5                    ((volatile uint32_t *)REG_SPU0_WP5)                     /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP6                    ((volatile uint32_t *)REG_SPU0_WP6)                     /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP7                    ((volatile uint32_t *)REG_SPU0_WP7)                     /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP8                    ((volatile uint32_t *)REG_SPU0_WP8)                     /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP9                    ((volatile uint32_t *)REG_SPU0_WP9)                     /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP10                   ((volatile uint32_t *)REG_SPU0_WP10)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP11                   ((volatile uint32_t *)REG_SPU0_WP11)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP12                   ((volatile uint32_t *)REG_SPU0_WP12)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP13                   ((volatile uint32_t *)REG_SPU0_WP13)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP14                   ((volatile uint32_t *)REG_SPU0_WP14)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP15                   ((volatile uint32_t *)REG_SPU0_WP15)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP16                   ((volatile uint32_t *)REG_SPU0_WP16)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP17                   ((volatile uint32_t *)REG_SPU0_WP17)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP18                   ((volatile uint32_t *)REG_SPU0_WP18)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP19                   ((volatile uint32_t *)REG_SPU0_WP19)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP20                   ((volatile uint32_t *)REG_SPU0_WP20)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP21                   ((volatile uint32_t *)REG_SPU0_WP21)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP22                   ((volatile uint32_t *)REG_SPU0_WP22)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP23                   ((volatile uint32_t *)REG_SPU0_WP23)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP24                   ((volatile uint32_t *)REG_SPU0_WP24)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP25                   ((volatile uint32_t *)REG_SPU0_WP25)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP26                   ((volatile uint32_t *)REG_SPU0_WP26)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP27                   ((volatile uint32_t *)REG_SPU0_WP27)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP28                   ((volatile uint32_t *)REG_SPU0_WP28)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP29                   ((volatile uint32_t *)REG_SPU0_WP29)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP30                   ((volatile uint32_t *)REG_SPU0_WP30)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP31                   ((volatile uint32_t *)REG_SPU0_WP31)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP32                   ((volatile uint32_t *)REG_SPU0_WP32)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP33                   ((volatile uint32_t *)REG_SPU0_WP33)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP34                   ((volatile uint32_t *)REG_SPU0_WP34)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP35                   ((volatile uint32_t *)REG_SPU0_WP35)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP36                   ((volatile uint32_t *)REG_SPU0_WP36)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP37                   ((volatile uint32_t *)REG_SPU0_WP37)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP38                   ((volatile uint32_t *)REG_SPU0_WP38)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP39                   ((volatile uint32_t *)REG_SPU0_WP39)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP40                   ((volatile uint32_t *)REG_SPU0_WP40)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP41                   ((volatile uint32_t *)REG_SPU0_WP41)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP42                   ((volatile uint32_t *)REG_SPU0_WP42)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP43                   ((volatile uint32_t *)REG_SPU0_WP43)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP44                   ((volatile uint32_t *)REG_SPU0_WP44)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP45                   ((volatile uint32_t *)REG_SPU0_WP45)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP46                   ((volatile uint32_t *)REG_SPU0_WP46)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP47                   ((volatile uint32_t *)REG_SPU0_WP47)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP48                   ((volatile uint32_t *)REG_SPU0_WP48)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP49                   ((volatile uint32_t *)REG_SPU0_WP49)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP50                   ((volatile uint32_t *)REG_SPU0_WP50)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP51                   ((volatile uint32_t *)REG_SPU0_WP51)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP52                   ((volatile uint32_t *)REG_SPU0_WP52)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP53                   ((volatile uint32_t *)REG_SPU0_WP53)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP54                   ((volatile uint32_t *)REG_SPU0_WP54)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP55                   ((volatile uint32_t *)REG_SPU0_WP55)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP56                   ((volatile uint32_t *)REG_SPU0_WP56)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP57                   ((volatile uint32_t *)REG_SPU0_WP57)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP58                   ((volatile uint32_t *)REG_SPU0_WP58)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP59                   ((volatile uint32_t *)REG_SPU0_WP59)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP60                   ((volatile uint32_t *)REG_SPU0_WP60)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP61                   ((volatile uint32_t *)REG_SPU0_WP61)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP62                   ((volatile uint32_t *)REG_SPU0_WP62)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP63                   ((volatile uint32_t *)REG_SPU0_WP63)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP64                   ((volatile uint32_t *)REG_SPU0_WP64)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP65                   ((volatile uint32_t *)REG_SPU0_WP65)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP66                   ((volatile uint32_t *)REG_SPU0_WP66)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP67                   ((volatile uint32_t *)REG_SPU0_WP67)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP68                   ((volatile uint32_t *)REG_SPU0_WP68)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP69                   ((volatile uint32_t *)REG_SPU0_WP69)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP70                   ((volatile uint32_t *)REG_SPU0_WP70)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP71                   ((volatile uint32_t *)REG_SPU0_WP71)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP72                   ((volatile uint32_t *)REG_SPU0_WP72)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP73                   ((volatile uint32_t *)REG_SPU0_WP73)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP74                   ((volatile uint32_t *)REG_SPU0_WP74)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP75                   ((volatile uint32_t *)REG_SPU0_WP75)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP76                   ((volatile uint32_t *)REG_SPU0_WP76)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_WP77                   ((volatile uint32_t *)REG_SPU0_WP77)                    /* SPU0 Write Protect Register n */
#define pREG_SPU0_SECURECTL              ((volatile uint32_t *)REG_SPU0_SECURECTL)               /* SPU0 Secure Control Register */
#define pREG_SPU0_SECURECHK              ((volatile uint32_t *)REG_SPU0_SECURECHK)               /* SPU0 Secure Check Register */
#define pREG_SPU0_SECUREC0               ((volatile uint32_t *)REG_SPU0_SECUREC0)                /* SPU0 Secure Core Registers */
#define pREG_SPU0_SECUREP0               ((volatile uint32_t *)REG_SPU0_SECUREP0)                /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP1               ((volatile uint32_t *)REG_SPU0_SECUREP1)                /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP2               ((volatile uint32_t *)REG_SPU0_SECUREP2)                /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP3               ((volatile uint32_t *)REG_SPU0_SECUREP3)                /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP4               ((volatile uint32_t *)REG_SPU0_SECUREP4)                /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP5               ((volatile uint32_t *)REG_SPU0_SECUREP5)                /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP6               ((volatile uint32_t *)REG_SPU0_SECUREP6)                /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP7               ((volatile uint32_t *)REG_SPU0_SECUREP7)                /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP8               ((volatile uint32_t *)REG_SPU0_SECUREP8)                /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP9               ((volatile uint32_t *)REG_SPU0_SECUREP9)                /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP10              ((volatile uint32_t *)REG_SPU0_SECUREP10)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP11              ((volatile uint32_t *)REG_SPU0_SECUREP11)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP12              ((volatile uint32_t *)REG_SPU0_SECUREP12)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP13              ((volatile uint32_t *)REG_SPU0_SECUREP13)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP14              ((volatile uint32_t *)REG_SPU0_SECUREP14)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP15              ((volatile uint32_t *)REG_SPU0_SECUREP15)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP16              ((volatile uint32_t *)REG_SPU0_SECUREP16)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP17              ((volatile uint32_t *)REG_SPU0_SECUREP17)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP18              ((volatile uint32_t *)REG_SPU0_SECUREP18)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP19              ((volatile uint32_t *)REG_SPU0_SECUREP19)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP20              ((volatile uint32_t *)REG_SPU0_SECUREP20)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP21              ((volatile uint32_t *)REG_SPU0_SECUREP21)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP22              ((volatile uint32_t *)REG_SPU0_SECUREP22)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP23              ((volatile uint32_t *)REG_SPU0_SECUREP23)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP24              ((volatile uint32_t *)REG_SPU0_SECUREP24)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP25              ((volatile uint32_t *)REG_SPU0_SECUREP25)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP26              ((volatile uint32_t *)REG_SPU0_SECUREP26)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP27              ((volatile uint32_t *)REG_SPU0_SECUREP27)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP28              ((volatile uint32_t *)REG_SPU0_SECUREP28)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP29              ((volatile uint32_t *)REG_SPU0_SECUREP29)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP30              ((volatile uint32_t *)REG_SPU0_SECUREP30)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP31              ((volatile uint32_t *)REG_SPU0_SECUREP31)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP32              ((volatile uint32_t *)REG_SPU0_SECUREP32)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP33              ((volatile uint32_t *)REG_SPU0_SECUREP33)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP34              ((volatile uint32_t *)REG_SPU0_SECUREP34)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP35              ((volatile uint32_t *)REG_SPU0_SECUREP35)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP36              ((volatile uint32_t *)REG_SPU0_SECUREP36)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP37              ((volatile uint32_t *)REG_SPU0_SECUREP37)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP38              ((volatile uint32_t *)REG_SPU0_SECUREP38)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP39              ((volatile uint32_t *)REG_SPU0_SECUREP39)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP40              ((volatile uint32_t *)REG_SPU0_SECUREP40)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP41              ((volatile uint32_t *)REG_SPU0_SECUREP41)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP42              ((volatile uint32_t *)REG_SPU0_SECUREP42)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP43              ((volatile uint32_t *)REG_SPU0_SECUREP43)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP44              ((volatile uint32_t *)REG_SPU0_SECUREP44)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP45              ((volatile uint32_t *)REG_SPU0_SECUREP45)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP46              ((volatile uint32_t *)REG_SPU0_SECUREP46)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP47              ((volatile uint32_t *)REG_SPU0_SECUREP47)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP48              ((volatile uint32_t *)REG_SPU0_SECUREP48)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP49              ((volatile uint32_t *)REG_SPU0_SECUREP49)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP50              ((volatile uint32_t *)REG_SPU0_SECUREP50)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP51              ((volatile uint32_t *)REG_SPU0_SECUREP51)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP52              ((volatile uint32_t *)REG_SPU0_SECUREP52)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP53              ((volatile uint32_t *)REG_SPU0_SECUREP53)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP54              ((volatile uint32_t *)REG_SPU0_SECUREP54)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP55              ((volatile uint32_t *)REG_SPU0_SECUREP55)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP56              ((volatile uint32_t *)REG_SPU0_SECUREP56)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP57              ((volatile uint32_t *)REG_SPU0_SECUREP57)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP58              ((volatile uint32_t *)REG_SPU0_SECUREP58)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP59              ((volatile uint32_t *)REG_SPU0_SECUREP59)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP60              ((volatile uint32_t *)REG_SPU0_SECUREP60)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP61              ((volatile uint32_t *)REG_SPU0_SECUREP61)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP62              ((volatile uint32_t *)REG_SPU0_SECUREP62)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP63              ((volatile uint32_t *)REG_SPU0_SECUREP63)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP64              ((volatile uint32_t *)REG_SPU0_SECUREP64)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP65              ((volatile uint32_t *)REG_SPU0_SECUREP65)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP66              ((volatile uint32_t *)REG_SPU0_SECUREP66)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP67              ((volatile uint32_t *)REG_SPU0_SECUREP67)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP68              ((volatile uint32_t *)REG_SPU0_SECUREP68)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP69              ((volatile uint32_t *)REG_SPU0_SECUREP69)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP70              ((volatile uint32_t *)REG_SPU0_SECUREP70)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP71              ((volatile uint32_t *)REG_SPU0_SECUREP71)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP72              ((volatile uint32_t *)REG_SPU0_SECUREP72)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP73              ((volatile uint32_t *)REG_SPU0_SECUREP73)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP74              ((volatile uint32_t *)REG_SPU0_SECUREP74)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP75              ((volatile uint32_t *)REG_SPU0_SECUREP75)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP76              ((volatile uint32_t *)REG_SPU0_SECUREP76)               /* SPU0 Secure Peripheral Register */
#define pREG_SPU0_SECUREP77              ((volatile uint32_t *)REG_SPU0_SECUREP77)               /* SPU0 Secure Peripheral Register */


/* =========================================================================
       SMPU0
   ========================================================================= */
#define pREG_SMPU0_CTL                   ((volatile uint32_t *)REG_SMPU0_CTL)                    /* SMPU0 SMPU Control */
#define pREG_SMPU0_STAT                  ((volatile uint32_t *)REG_SMPU0_STAT)                   /* SMPU0 SMPU Status */
#define pREG_SMPU0_IADDR                 ((volatile uint32_t *)REG_SMPU0_IADDR)                  /* SMPU0 Interrupt Address */
#define pREG_SMPU0_IDTLS                 ((volatile uint32_t *)REG_SMPU0_IDTLS)                  /* SMPU0 Interrupt Details */
#define pREG_SMPU0_BADDR                 ((volatile uint32_t *)REG_SMPU0_BADDR)                  /* SMPU0 Bus Error Address */
#define pREG_SMPU0_BDTLS                 ((volatile uint32_t *)REG_SMPU0_BDTLS)                  /* SMPU0 Bus Error Details */
#define pREG_SMPU0_RCTL0                 ((volatile uint32_t *)REG_SMPU0_RCTL0)                  /* SMPU0 Region n Control */
#define pREG_SMPU0_RCTL1                 ((volatile uint32_t *)REG_SMPU0_RCTL1)                  /* SMPU0 Region n Control */
#define pREG_SMPU0_RCTL2                 ((volatile uint32_t *)REG_SMPU0_RCTL2)                  /* SMPU0 Region n Control */
#define pREG_SMPU0_RCTL3                 ((volatile uint32_t *)REG_SMPU0_RCTL3)                  /* SMPU0 Region n Control */
#define pREG_SMPU0_RADDR0                ((volatile uint32_t *)REG_SMPU0_RADDR0)                 /* SMPU0 Region n Address */
#define pREG_SMPU0_RADDR1                ((volatile uint32_t *)REG_SMPU0_RADDR1)                 /* SMPU0 Region n Address */
#define pREG_SMPU0_RADDR2                ((volatile uint32_t *)REG_SMPU0_RADDR2)                 /* SMPU0 Region n Address */
#define pREG_SMPU0_RADDR3                ((volatile uint32_t *)REG_SMPU0_RADDR3)                 /* SMPU0 Region n Address */
#define pREG_SMPU0_RIDA0                 ((volatile uint32_t *)REG_SMPU0_RIDA0)                  /* SMPU0 Region n ID Register A */
#define pREG_SMPU0_RIDA1                 ((volatile uint32_t *)REG_SMPU0_RIDA1)                  /* SMPU0 Region n ID Register A */
#define pREG_SMPU0_RIDA2                 ((volatile uint32_t *)REG_SMPU0_RIDA2)                  /* SMPU0 Region n ID Register A */
#define pREG_SMPU0_RIDA3                 ((volatile uint32_t *)REG_SMPU0_RIDA3)                  /* SMPU0 Region n ID Register A */
#define pREG_SMPU0_RIDMSKA0              ((volatile uint32_t *)REG_SMPU0_RIDMSKA0)               /* SMPU0 Region n ID Mask Register A */
#define pREG_SMPU0_RIDMSKA1              ((volatile uint32_t *)REG_SMPU0_RIDMSKA1)               /* SMPU0 Region n ID Mask Register A */
#define pREG_SMPU0_RIDMSKA2              ((volatile uint32_t *)REG_SMPU0_RIDMSKA2)               /* SMPU0 Region n ID Mask Register A */
#define pREG_SMPU0_RIDMSKA3              ((volatile uint32_t *)REG_SMPU0_RIDMSKA3)               /* SMPU0 Region n ID Mask Register A */
#define pREG_SMPU0_RIDB0                 ((volatile uint32_t *)REG_SMPU0_RIDB0)                  /* SMPU0 Region n ID Register B */
#define pREG_SMPU0_RIDB1                 ((volatile uint32_t *)REG_SMPU0_RIDB1)                  /* SMPU0 Region n ID Register B */
#define pREG_SMPU0_RIDB2                 ((volatile uint32_t *)REG_SMPU0_RIDB2)                  /* SMPU0 Region n ID Register B */
#define pREG_SMPU0_RIDB3                 ((volatile uint32_t *)REG_SMPU0_RIDB3)                  /* SMPU0 Region n ID Register B */
#define pREG_SMPU0_RIDMSKB0              ((volatile uint32_t *)REG_SMPU0_RIDMSKB0)               /* SMPU0 Region n ID Mask Register B */
#define pREG_SMPU0_RIDMSKB1              ((volatile uint32_t *)REG_SMPU0_RIDMSKB1)               /* SMPU0 Region n ID Mask Register B */
#define pREG_SMPU0_RIDMSKB2              ((volatile uint32_t *)REG_SMPU0_RIDMSKB2)               /* SMPU0 Region n ID Mask Register B */
#define pREG_SMPU0_RIDMSKB3              ((volatile uint32_t *)REG_SMPU0_RIDMSKB3)               /* SMPU0 Region n ID Mask Register B */
#define pREG_SMPU0_REVID                 ((volatile uint32_t *)REG_SMPU0_REVID)                  /* SMPU0 SMPU Revision ID */
#define pREG_SMPU0_SECURECTL             ((volatile uint32_t *)REG_SMPU0_SECURECTL)              /* SMPU0 SMPU Control Secure Accesses */
#define pREG_SMPU0_SECURERCTL0           ((volatile uint32_t *)REG_SMPU0_SECURERCTL0)            /* SMPU0 Region n Control Secure Accesses */
#define pREG_SMPU0_SECURERCTL1           ((volatile uint32_t *)REG_SMPU0_SECURERCTL1)            /* SMPU0 Region n Control Secure Accesses */
#define pREG_SMPU0_SECURERCTL2           ((volatile uint32_t *)REG_SMPU0_SECURERCTL2)            /* SMPU0 Region n Control Secure Accesses */
#define pREG_SMPU0_SECURERCTL3           ((volatile uint32_t *)REG_SMPU0_SECURERCTL3)            /* SMPU0 Region n Control Secure Accesses */

/* =========================================================================
       SMPU1
   ========================================================================= */
#define pREG_SMPU1_CTL                   ((volatile uint32_t *)REG_SMPU1_CTL)                    /* SMPU1 SMPU Control */
#define pREG_SMPU1_STAT                  ((volatile uint32_t *)REG_SMPU1_STAT)                   /* SMPU1 SMPU Status */
#define pREG_SMPU1_IADDR                 ((volatile uint32_t *)REG_SMPU1_IADDR)                  /* SMPU1 Interrupt Address */
#define pREG_SMPU1_IDTLS                 ((volatile uint32_t *)REG_SMPU1_IDTLS)                  /* SMPU1 Interrupt Details */
#define pREG_SMPU1_BADDR                 ((volatile uint32_t *)REG_SMPU1_BADDR)                  /* SMPU1 Bus Error Address */
#define pREG_SMPU1_BDTLS                 ((volatile uint32_t *)REG_SMPU1_BDTLS)                  /* SMPU1 Bus Error Details */
#define pREG_SMPU1_RCTL0                 ((volatile uint32_t *)REG_SMPU1_RCTL0)                  /* SMPU1 Region n Control */
#define pREG_SMPU1_RCTL1                 ((volatile uint32_t *)REG_SMPU1_RCTL1)                  /* SMPU1 Region n Control */
#define pREG_SMPU1_RCTL2                 ((volatile uint32_t *)REG_SMPU1_RCTL2)                  /* SMPU1 Region n Control */
#define pREG_SMPU1_RCTL3                 ((volatile uint32_t *)REG_SMPU1_RCTL3)                  /* SMPU1 Region n Control */
#define pREG_SMPU1_RCTL4                 ((volatile uint32_t *)REG_SMPU1_RCTL4)                  /* SMPU1 Region n Control */
#define pREG_SMPU1_RCTL5                 ((volatile uint32_t *)REG_SMPU1_RCTL5)                  /* SMPU1 Region n Control */
#define pREG_SMPU1_RCTL6                 ((volatile uint32_t *)REG_SMPU1_RCTL6)                  /* SMPU1 Region n Control */
#define pREG_SMPU1_RCTL7                 ((volatile uint32_t *)REG_SMPU1_RCTL7)                  /* SMPU1 Region n Control */
#define pREG_SMPU1_RADDR0                ((volatile uint32_t *)REG_SMPU1_RADDR0)                 /* SMPU1 Region n Address */
#define pREG_SMPU1_RADDR1                ((volatile uint32_t *)REG_SMPU1_RADDR1)                 /* SMPU1 Region n Address */
#define pREG_SMPU1_RADDR2                ((volatile uint32_t *)REG_SMPU1_RADDR2)                 /* SMPU1 Region n Address */
#define pREG_SMPU1_RADDR3                ((volatile uint32_t *)REG_SMPU1_RADDR3)                 /* SMPU1 Region n Address */
#define pREG_SMPU1_RADDR4                ((volatile uint32_t *)REG_SMPU1_RADDR4)                 /* SMPU1 Region n Address */
#define pREG_SMPU1_RADDR5                ((volatile uint32_t *)REG_SMPU1_RADDR5)                 /* SMPU1 Region n Address */
#define pREG_SMPU1_RADDR6                ((volatile uint32_t *)REG_SMPU1_RADDR6)                 /* SMPU1 Region n Address */
#define pREG_SMPU1_RADDR7                ((volatile uint32_t *)REG_SMPU1_RADDR7)                 /* SMPU1 Region n Address */
#define pREG_SMPU1_RIDA0                 ((volatile uint32_t *)REG_SMPU1_RIDA0)                  /* SMPU1 Region n ID Register A */
#define pREG_SMPU1_RIDA1                 ((volatile uint32_t *)REG_SMPU1_RIDA1)                  /* SMPU1 Region n ID Register A */
#define pREG_SMPU1_RIDA2                 ((volatile uint32_t *)REG_SMPU1_RIDA2)                  /* SMPU1 Region n ID Register A */
#define pREG_SMPU1_RIDA3                 ((volatile uint32_t *)REG_SMPU1_RIDA3)                  /* SMPU1 Region n ID Register A */
#define pREG_SMPU1_RIDA4                 ((volatile uint32_t *)REG_SMPU1_RIDA4)                  /* SMPU1 Region n ID Register A */
#define pREG_SMPU1_RIDA5                 ((volatile uint32_t *)REG_SMPU1_RIDA5)                  /* SMPU1 Region n ID Register A */
#define pREG_SMPU1_RIDA6                 ((volatile uint32_t *)REG_SMPU1_RIDA6)                  /* SMPU1 Region n ID Register A */
#define pREG_SMPU1_RIDA7                 ((volatile uint32_t *)REG_SMPU1_RIDA7)                  /* SMPU1 Region n ID Register A */
#define pREG_SMPU1_RIDMSKA0              ((volatile uint32_t *)REG_SMPU1_RIDMSKA0)               /* SMPU1 Region n ID Mask Register A */
#define pREG_SMPU1_RIDMSKA1              ((volatile uint32_t *)REG_SMPU1_RIDMSKA1)               /* SMPU1 Region n ID Mask Register A */
#define pREG_SMPU1_RIDMSKA2              ((volatile uint32_t *)REG_SMPU1_RIDMSKA2)               /* SMPU1 Region n ID Mask Register A */
#define pREG_SMPU1_RIDMSKA3              ((volatile uint32_t *)REG_SMPU1_RIDMSKA3)               /* SMPU1 Region n ID Mask Register A */
#define pREG_SMPU1_RIDMSKA4              ((volatile uint32_t *)REG_SMPU1_RIDMSKA4)               /* SMPU1 Region n ID Mask Register A */
#define pREG_SMPU1_RIDMSKA5              ((volatile uint32_t *)REG_SMPU1_RIDMSKA5)               /* SMPU1 Region n ID Mask Register A */
#define pREG_SMPU1_RIDMSKA6              ((volatile uint32_t *)REG_SMPU1_RIDMSKA6)               /* SMPU1 Region n ID Mask Register A */
#define pREG_SMPU1_RIDMSKA7              ((volatile uint32_t *)REG_SMPU1_RIDMSKA7)               /* SMPU1 Region n ID Mask Register A */
#define pREG_SMPU1_RIDB0                 ((volatile uint32_t *)REG_SMPU1_RIDB0)                  /* SMPU1 Region n ID Register B */
#define pREG_SMPU1_RIDB1                 ((volatile uint32_t *)REG_SMPU1_RIDB1)                  /* SMPU1 Region n ID Register B */
#define pREG_SMPU1_RIDB2                 ((volatile uint32_t *)REG_SMPU1_RIDB2)                  /* SMPU1 Region n ID Register B */
#define pREG_SMPU1_RIDB3                 ((volatile uint32_t *)REG_SMPU1_RIDB3)                  /* SMPU1 Region n ID Register B */
#define pREG_SMPU1_RIDB4                 ((volatile uint32_t *)REG_SMPU1_RIDB4)                  /* SMPU1 Region n ID Register B */
#define pREG_SMPU1_RIDB5                 ((volatile uint32_t *)REG_SMPU1_RIDB5)                  /* SMPU1 Region n ID Register B */
#define pREG_SMPU1_RIDB6                 ((volatile uint32_t *)REG_SMPU1_RIDB6)                  /* SMPU1 Region n ID Register B */
#define pREG_SMPU1_RIDB7                 ((volatile uint32_t *)REG_SMPU1_RIDB7)                  /* SMPU1 Region n ID Register B */
#define pREG_SMPU1_RIDMSKB0              ((volatile uint32_t *)REG_SMPU1_RIDMSKB0)               /* SMPU1 Region n ID Mask Register B */
#define pREG_SMPU1_RIDMSKB1              ((volatile uint32_t *)REG_SMPU1_RIDMSKB1)               /* SMPU1 Region n ID Mask Register B */
#define pREG_SMPU1_RIDMSKB2              ((volatile uint32_t *)REG_SMPU1_RIDMSKB2)               /* SMPU1 Region n ID Mask Register B */
#define pREG_SMPU1_RIDMSKB3              ((volatile uint32_t *)REG_SMPU1_RIDMSKB3)               /* SMPU1 Region n ID Mask Register B */
#define pREG_SMPU1_RIDMSKB4              ((volatile uint32_t *)REG_SMPU1_RIDMSKB4)               /* SMPU1 Region n ID Mask Register B */
#define pREG_SMPU1_RIDMSKB5              ((volatile uint32_t *)REG_SMPU1_RIDMSKB5)               /* SMPU1 Region n ID Mask Register B */
#define pREG_SMPU1_RIDMSKB6              ((volatile uint32_t *)REG_SMPU1_RIDMSKB6)               /* SMPU1 Region n ID Mask Register B */
#define pREG_SMPU1_RIDMSKB7              ((volatile uint32_t *)REG_SMPU1_RIDMSKB7)               /* SMPU1 Region n ID Mask Register B */
#define pREG_SMPU1_REVID                 ((volatile uint32_t *)REG_SMPU1_REVID)                  /* SMPU1 SMPU Revision ID */
#define pREG_SMPU1_SECURECTL             ((volatile uint32_t *)REG_SMPU1_SECURECTL)              /* SMPU1 SMPU Control Secure Accesses */
#define pREG_SMPU1_SECURERCTL0           ((volatile uint32_t *)REG_SMPU1_SECURERCTL0)            /* SMPU1 Region n Control Secure Accesses */
#define pREG_SMPU1_SECURERCTL1           ((volatile uint32_t *)REG_SMPU1_SECURERCTL1)            /* SMPU1 Region n Control Secure Accesses */
#define pREG_SMPU1_SECURERCTL2           ((volatile uint32_t *)REG_SMPU1_SECURERCTL2)            /* SMPU1 Region n Control Secure Accesses */
#define pREG_SMPU1_SECURERCTL3           ((volatile uint32_t *)REG_SMPU1_SECURERCTL3)            /* SMPU1 Region n Control Secure Accesses */
#define pREG_SMPU1_SECURERCTL4           ((volatile uint32_t *)REG_SMPU1_SECURERCTL4)            /* SMPU1 Region n Control Secure Accesses */
#define pREG_SMPU1_SECURERCTL5           ((volatile uint32_t *)REG_SMPU1_SECURERCTL5)            /* SMPU1 Region n Control Secure Accesses */
#define pREG_SMPU1_SECURERCTL6           ((volatile uint32_t *)REG_SMPU1_SECURERCTL6)            /* SMPU1 Region n Control Secure Accesses */
#define pREG_SMPU1_SECURERCTL7           ((volatile uint32_t *)REG_SMPU1_SECURERCTL7)            /* SMPU1 Region n Control Secure Accesses */


/* =========================================================================
       L2CTL0
   ========================================================================= */
#define pREG_L2CTL0_CTL                  ((volatile uint32_t *)REG_L2CTL0_CTL)                   /* L2CTL0 Control Register */
#define pREG_L2CTL0_ACTL_C0              ((volatile uint32_t *)REG_L2CTL0_ACTL_C0)               /* L2CTL0 Access Control Core 0 Register */
#define pREG_L2CTL0_ACTL_SYS             ((volatile uint32_t *)REG_L2CTL0_ACTL_SYS)              /* L2CTL0 Access Control System Register */
#define pREG_L2CTL0_STAT                 ((volatile uint32_t *)REG_L2CTL0_STAT)                  /* L2CTL0 Status Register */
#define pREG_L2CTL0_RPCR                 ((volatile uint32_t *)REG_L2CTL0_RPCR)                  /* L2CTL0 Read Priority Count Register */
#define pREG_L2CTL0_WPCR                 ((volatile uint32_t *)REG_L2CTL0_WPCR)                  /* L2CTL0 Write Priority Count Register */
#define pREG_L2CTL0_INIT                 ((volatile uint32_t *)REG_L2CTL0_INIT)                  /* L2CTL0 Initialization Register */
#define pREG_L2CTL0_ISTAT                ((volatile uint32_t *)REG_L2CTL0_ISTAT)                 /* L2CTL0 Initialization Status Register */
#define pREG_L2CTL0_PCTL                 ((volatile uint32_t *)REG_L2CTL0_PCTL)                  /* L2CTL0 Power Control Register */
#define pREG_L2CTL0_ERRADDR0             ((void * volatile *)REG_L2CTL0_ERRADDR0)                /* L2CTL0 ECC Error Address 0 Register */
#define pREG_L2CTL0_ERRADDR1             ((void * volatile *)REG_L2CTL0_ERRADDR1)                /* L2CTL0 ECC Error Address 1 Register */
#define pREG_L2CTL0_ERRADDR2             ((void * volatile *)REG_L2CTL0_ERRADDR2)                /* L2CTL0 ECC Error Address 2 Register */
#define pREG_L2CTL0_ERRADDR3             ((void * volatile *)REG_L2CTL0_ERRADDR3)                /* L2CTL0 ECC Error Address 3 Register */
#define pREG_L2CTL0_ERRADDR4             ((void * volatile *)REG_L2CTL0_ERRADDR4)                /* L2CTL0 ECC Error Address 4 Register */
#define pREG_L2CTL0_ERRADDR5             ((void * volatile *)REG_L2CTL0_ERRADDR5)                /* L2CTL0 ECC Error Address 5 Register */
#define pREG_L2CTL0_ERRADDR6             ((void * volatile *)REG_L2CTL0_ERRADDR6)                /* L2CTL0 ECC Error Address 6 Register */
#define pREG_L2CTL0_ERRADDR7             ((void * volatile *)REG_L2CTL0_ERRADDR7)                /* L2CTL0 ECC Error Address 7 Register */
#define pREG_L2CTL0_ERRADDR8             ((void * volatile *)REG_L2CTL0_ERRADDR8)                /* L2CTL0 ECC Error Address 8 Register */
#define pREG_L2CTL0_ET0                  ((volatile uint32_t *)REG_L2CTL0_ET0)                   /* L2CTL0 Error Type 0 Register */
#define pREG_L2CTL0_EADDR0               ((void * volatile *)REG_L2CTL0_EADDR0)                  /* L2CTL0 Error Type 0 Address Register */
#define pREG_L2CTL0_ET1                  ((volatile uint32_t *)REG_L2CTL0_ET1)                   /* L2CTL0 Error Type 1 Register */
#define pREG_L2CTL0_EADDR1               ((void * volatile *)REG_L2CTL0_EADDR1)                  /* L2CTL0 Error Type 1 Address Register */
#define pREG_L2CTL0_SCTL                 ((volatile uint32_t *)REG_L2CTL0_SCTL)                  /* L2CTL0 Scrub Control Register */
#define pREG_L2CTL0_SADR                 ((void * volatile *)REG_L2CTL0_SADR)                    /* L2CTL0 Scrub Start Address Register */
#define pREG_L2CTL0_SCNT                 ((volatile uint32_t *)REG_L2CTL0_SCNT)                  /* L2CTL0 Scrub Count Register */
#define pREG_L2CTL0_REVID                ((volatile uint32_t *)REG_L2CTL0_REVID)                 /* L2CTL0 Revision ID Register */


/* =========================================================================
       SWU0
   ========================================================================= */
#define pREG_SWU0_GCTL                   ((volatile uint32_t *)REG_SWU0_GCTL)                    /* SWU0 Global Control Register */
#define pREG_SWU0_GSTAT                  ((volatile uint32_t *)REG_SWU0_GSTAT)                   /* SWU0 Global Status Register */
#define pREG_SWU0_CTL0                   ((volatile uint32_t *)REG_SWU0_CTL0)                    /* SWU0 Control Register n */
#define pREG_SWU0_CTL1                   ((volatile uint32_t *)REG_SWU0_CTL1)                    /* SWU0 Control Register n */
#define pREG_SWU0_CTL2                   ((volatile uint32_t *)REG_SWU0_CTL2)                    /* SWU0 Control Register n */
#define pREG_SWU0_CTL3                   ((volatile uint32_t *)REG_SWU0_CTL3)                    /* SWU0 Control Register n */
#define pREG_SWU0_LA0                    ((void * volatile *)REG_SWU0_LA0)                       /* SWU0 Lower Address Register n */
#define pREG_SWU0_LA1                    ((void * volatile *)REG_SWU0_LA1)                       /* SWU0 Lower Address Register n */
#define pREG_SWU0_LA2                    ((void * volatile *)REG_SWU0_LA2)                       /* SWU0 Lower Address Register n */
#define pREG_SWU0_LA3                    ((void * volatile *)REG_SWU0_LA3)                       /* SWU0 Lower Address Register n */
#define pREG_SWU0_UA0                    ((void * volatile *)REG_SWU0_UA0)                       /* SWU0 Upper Address Register n */
#define pREG_SWU0_UA1                    ((void * volatile *)REG_SWU0_UA1)                       /* SWU0 Upper Address Register n */
#define pREG_SWU0_UA2                    ((void * volatile *)REG_SWU0_UA2)                       /* SWU0 Upper Address Register n */
#define pREG_SWU0_UA3                    ((void * volatile *)REG_SWU0_UA3)                       /* SWU0 Upper Address Register n */
#define pREG_SWU0_ID0                    ((volatile uint32_t *)REG_SWU0_ID0)                     /* SWU0 ID Register n */
#define pREG_SWU0_ID1                    ((volatile uint32_t *)REG_SWU0_ID1)                     /* SWU0 ID Register n */
#define pREG_SWU0_ID2                    ((volatile uint32_t *)REG_SWU0_ID2)                     /* SWU0 ID Register n */
#define pREG_SWU0_ID3                    ((volatile uint32_t *)REG_SWU0_ID3)                     /* SWU0 ID Register n */
#define pREG_SWU0_CNT0                   ((volatile uint32_t *)REG_SWU0_CNT0)                    /* SWU0 Count Register n */
#define pREG_SWU0_CNT1                   ((volatile uint32_t *)REG_SWU0_CNT1)                    /* SWU0 Count Register n */
#define pREG_SWU0_CNT2                   ((volatile uint32_t *)REG_SWU0_CNT2)                    /* SWU0 Count Register n */
#define pREG_SWU0_CNT3                   ((volatile uint32_t *)REG_SWU0_CNT3)                    /* SWU0 Count Register n */
#define pREG_SWU0_TARG0                  ((volatile uint32_t *)REG_SWU0_TARG0)                   /* SWU0 Target Register n */
#define pREG_SWU0_TARG1                  ((volatile uint32_t *)REG_SWU0_TARG1)                   /* SWU0 Target Register n */
#define pREG_SWU0_TARG2                  ((volatile uint32_t *)REG_SWU0_TARG2)                   /* SWU0 Target Register n */
#define pREG_SWU0_TARG3                  ((volatile uint32_t *)REG_SWU0_TARG3)                   /* SWU0 Target Register n */
#define pREG_SWU0_HIST0                  ((volatile uint32_t *)REG_SWU0_HIST0)                   /* SWU0 Bandwidth History Register n */
#define pREG_SWU0_HIST1                  ((volatile uint32_t *)REG_SWU0_HIST1)                   /* SWU0 Bandwidth History Register n */
#define pREG_SWU0_HIST2                  ((volatile uint32_t *)REG_SWU0_HIST2)                   /* SWU0 Bandwidth History Register n */
#define pREG_SWU0_HIST3                  ((volatile uint32_t *)REG_SWU0_HIST3)                   /* SWU0 Bandwidth History Register n */
#define pREG_SWU0_CUR0                   ((volatile uint32_t *)REG_SWU0_CUR0)                    /* SWU0 Current Register n */
#define pREG_SWU0_CUR1                   ((volatile uint32_t *)REG_SWU0_CUR1)                    /* SWU0 Current Register n */
#define pREG_SWU0_CUR2                   ((volatile uint32_t *)REG_SWU0_CUR2)                    /* SWU0 Current Register n */
#define pREG_SWU0_CUR3                   ((volatile uint32_t *)REG_SWU0_CUR3)                    /* SWU0 Current Register n */

/* =========================================================================
       SWU1
   ========================================================================= */
#define pREG_SWU1_GCTL                   ((volatile uint32_t *)REG_SWU1_GCTL)                    /* SWU1 Global Control Register */
#define pREG_SWU1_GSTAT                  ((volatile uint32_t *)REG_SWU1_GSTAT)                   /* SWU1 Global Status Register */
#define pREG_SWU1_CTL0                   ((volatile uint32_t *)REG_SWU1_CTL0)                    /* SWU1 Control Register n */
#define pREG_SWU1_CTL1                   ((volatile uint32_t *)REG_SWU1_CTL1)                    /* SWU1 Control Register n */
#define pREG_SWU1_CTL2                   ((volatile uint32_t *)REG_SWU1_CTL2)                    /* SWU1 Control Register n */
#define pREG_SWU1_CTL3                   ((volatile uint32_t *)REG_SWU1_CTL3)                    /* SWU1 Control Register n */
#define pREG_SWU1_LA0                    ((void * volatile *)REG_SWU1_LA0)                       /* SWU1 Lower Address Register n */
#define pREG_SWU1_LA1                    ((void * volatile *)REG_SWU1_LA1)                       /* SWU1 Lower Address Register n */
#define pREG_SWU1_LA2                    ((void * volatile *)REG_SWU1_LA2)                       /* SWU1 Lower Address Register n */
#define pREG_SWU1_LA3                    ((void * volatile *)REG_SWU1_LA3)                       /* SWU1 Lower Address Register n */
#define pREG_SWU1_UA0                    ((void * volatile *)REG_SWU1_UA0)                       /* SWU1 Upper Address Register n */
#define pREG_SWU1_UA1                    ((void * volatile *)REG_SWU1_UA1)                       /* SWU1 Upper Address Register n */
#define pREG_SWU1_UA2                    ((void * volatile *)REG_SWU1_UA2)                       /* SWU1 Upper Address Register n */
#define pREG_SWU1_UA3                    ((void * volatile *)REG_SWU1_UA3)                       /* SWU1 Upper Address Register n */
#define pREG_SWU1_ID0                    ((volatile uint32_t *)REG_SWU1_ID0)                     /* SWU1 ID Register n */
#define pREG_SWU1_ID1                    ((volatile uint32_t *)REG_SWU1_ID1)                     /* SWU1 ID Register n */
#define pREG_SWU1_ID2                    ((volatile uint32_t *)REG_SWU1_ID2)                     /* SWU1 ID Register n */
#define pREG_SWU1_ID3                    ((volatile uint32_t *)REG_SWU1_ID3)                     /* SWU1 ID Register n */
#define pREG_SWU1_CNT0                   ((volatile uint32_t *)REG_SWU1_CNT0)                    /* SWU1 Count Register n */
#define pREG_SWU1_CNT1                   ((volatile uint32_t *)REG_SWU1_CNT1)                    /* SWU1 Count Register n */
#define pREG_SWU1_CNT2                   ((volatile uint32_t *)REG_SWU1_CNT2)                    /* SWU1 Count Register n */
#define pREG_SWU1_CNT3                   ((volatile uint32_t *)REG_SWU1_CNT3)                    /* SWU1 Count Register n */
#define pREG_SWU1_TARG0                  ((volatile uint32_t *)REG_SWU1_TARG0)                   /* SWU1 Target Register n */
#define pREG_SWU1_TARG1                  ((volatile uint32_t *)REG_SWU1_TARG1)                   /* SWU1 Target Register n */
#define pREG_SWU1_TARG2                  ((volatile uint32_t *)REG_SWU1_TARG2)                   /* SWU1 Target Register n */
#define pREG_SWU1_TARG3                  ((volatile uint32_t *)REG_SWU1_TARG3)                   /* SWU1 Target Register n */
#define pREG_SWU1_HIST0                  ((volatile uint32_t *)REG_SWU1_HIST0)                   /* SWU1 Bandwidth History Register n */
#define pREG_SWU1_HIST1                  ((volatile uint32_t *)REG_SWU1_HIST1)                   /* SWU1 Bandwidth History Register n */
#define pREG_SWU1_HIST2                  ((volatile uint32_t *)REG_SWU1_HIST2)                   /* SWU1 Bandwidth History Register n */
#define pREG_SWU1_HIST3                  ((volatile uint32_t *)REG_SWU1_HIST3)                   /* SWU1 Bandwidth History Register n */
#define pREG_SWU1_CUR0                   ((volatile uint32_t *)REG_SWU1_CUR0)                    /* SWU1 Current Register n */
#define pREG_SWU1_CUR1                   ((volatile uint32_t *)REG_SWU1_CUR1)                    /* SWU1 Current Register n */
#define pREG_SWU1_CUR2                   ((volatile uint32_t *)REG_SWU1_CUR2)                    /* SWU1 Current Register n */
#define pREG_SWU1_CUR3                   ((volatile uint32_t *)REG_SWU1_CUR3)                    /* SWU1 Current Register n */

/* =========================================================================
       SWU2
   ========================================================================= */
#define pREG_SWU2_GCTL                   ((volatile uint32_t *)REG_SWU2_GCTL)                    /* SWU2 Global Control Register */
#define pREG_SWU2_GSTAT                  ((volatile uint32_t *)REG_SWU2_GSTAT)                   /* SWU2 Global Status Register */
#define pREG_SWU2_CTL0                   ((volatile uint32_t *)REG_SWU2_CTL0)                    /* SWU2 Control Register n */
#define pREG_SWU2_CTL1                   ((volatile uint32_t *)REG_SWU2_CTL1)                    /* SWU2 Control Register n */
#define pREG_SWU2_CTL2                   ((volatile uint32_t *)REG_SWU2_CTL2)                    /* SWU2 Control Register n */
#define pREG_SWU2_CTL3                   ((volatile uint32_t *)REG_SWU2_CTL3)                    /* SWU2 Control Register n */
#define pREG_SWU2_LA0                    ((void * volatile *)REG_SWU2_LA0)                       /* SWU2 Lower Address Register n */
#define pREG_SWU2_LA1                    ((void * volatile *)REG_SWU2_LA1)                       /* SWU2 Lower Address Register n */
#define pREG_SWU2_LA2                    ((void * volatile *)REG_SWU2_LA2)                       /* SWU2 Lower Address Register n */
#define pREG_SWU2_LA3                    ((void * volatile *)REG_SWU2_LA3)                       /* SWU2 Lower Address Register n */
#define pREG_SWU2_UA0                    ((void * volatile *)REG_SWU2_UA0)                       /* SWU2 Upper Address Register n */
#define pREG_SWU2_UA1                    ((void * volatile *)REG_SWU2_UA1)                       /* SWU2 Upper Address Register n */
#define pREG_SWU2_UA2                    ((void * volatile *)REG_SWU2_UA2)                       /* SWU2 Upper Address Register n */
#define pREG_SWU2_UA3                    ((void * volatile *)REG_SWU2_UA3)                       /* SWU2 Upper Address Register n */
#define pREG_SWU2_ID0                    ((volatile uint32_t *)REG_SWU2_ID0)                     /* SWU2 ID Register n */
#define pREG_SWU2_ID1                    ((volatile uint32_t *)REG_SWU2_ID1)                     /* SWU2 ID Register n */
#define pREG_SWU2_ID2                    ((volatile uint32_t *)REG_SWU2_ID2)                     /* SWU2 ID Register n */
#define pREG_SWU2_ID3                    ((volatile uint32_t *)REG_SWU2_ID3)                     /* SWU2 ID Register n */
#define pREG_SWU2_CNT0                   ((volatile uint32_t *)REG_SWU2_CNT0)                    /* SWU2 Count Register n */
#define pREG_SWU2_CNT1                   ((volatile uint32_t *)REG_SWU2_CNT1)                    /* SWU2 Count Register n */
#define pREG_SWU2_CNT2                   ((volatile uint32_t *)REG_SWU2_CNT2)                    /* SWU2 Count Register n */
#define pREG_SWU2_CNT3                   ((volatile uint32_t *)REG_SWU2_CNT3)                    /* SWU2 Count Register n */
#define pREG_SWU2_TARG0                  ((volatile uint32_t *)REG_SWU2_TARG0)                   /* SWU2 Target Register n */
#define pREG_SWU2_TARG1                  ((volatile uint32_t *)REG_SWU2_TARG1)                   /* SWU2 Target Register n */
#define pREG_SWU2_TARG2                  ((volatile uint32_t *)REG_SWU2_TARG2)                   /* SWU2 Target Register n */
#define pREG_SWU2_TARG3                  ((volatile uint32_t *)REG_SWU2_TARG3)                   /* SWU2 Target Register n */
#define pREG_SWU2_HIST0                  ((volatile uint32_t *)REG_SWU2_HIST0)                   /* SWU2 Bandwidth History Register n */
#define pREG_SWU2_HIST1                  ((volatile uint32_t *)REG_SWU2_HIST1)                   /* SWU2 Bandwidth History Register n */
#define pREG_SWU2_HIST2                  ((volatile uint32_t *)REG_SWU2_HIST2)                   /* SWU2 Bandwidth History Register n */
#define pREG_SWU2_HIST3                  ((volatile uint32_t *)REG_SWU2_HIST3)                   /* SWU2 Bandwidth History Register n */
#define pREG_SWU2_CUR0                   ((volatile uint32_t *)REG_SWU2_CUR0)                    /* SWU2 Current Register n */
#define pREG_SWU2_CUR1                   ((volatile uint32_t *)REG_SWU2_CUR1)                    /* SWU2 Current Register n */
#define pREG_SWU2_CUR2                   ((volatile uint32_t *)REG_SWU2_CUR2)                    /* SWU2 Current Register n */
#define pREG_SWU2_CUR3                   ((volatile uint32_t *)REG_SWU2_CUR3)                    /* SWU2 Current Register n */

/* =========================================================================
       SWU3
   ========================================================================= */
#define pREG_SWU3_GCTL                   ((volatile uint32_t *)REG_SWU3_GCTL)                    /* SWU3 Global Control Register */
#define pREG_SWU3_GSTAT                  ((volatile uint32_t *)REG_SWU3_GSTAT)                   /* SWU3 Global Status Register */
#define pREG_SWU3_CTL0                   ((volatile uint32_t *)REG_SWU3_CTL0)                    /* SWU3 Control Register n */
#define pREG_SWU3_CTL1                   ((volatile uint32_t *)REG_SWU3_CTL1)                    /* SWU3 Control Register n */
#define pREG_SWU3_CTL2                   ((volatile uint32_t *)REG_SWU3_CTL2)                    /* SWU3 Control Register n */
#define pREG_SWU3_CTL3                   ((volatile uint32_t *)REG_SWU3_CTL3)                    /* SWU3 Control Register n */
#define pREG_SWU3_LA0                    ((void * volatile *)REG_SWU3_LA0)                       /* SWU3 Lower Address Register n */
#define pREG_SWU3_LA1                    ((void * volatile *)REG_SWU3_LA1)                       /* SWU3 Lower Address Register n */
#define pREG_SWU3_LA2                    ((void * volatile *)REG_SWU3_LA2)                       /* SWU3 Lower Address Register n */
#define pREG_SWU3_LA3                    ((void * volatile *)REG_SWU3_LA3)                       /* SWU3 Lower Address Register n */
#define pREG_SWU3_UA0                    ((void * volatile *)REG_SWU3_UA0)                       /* SWU3 Upper Address Register n */
#define pREG_SWU3_UA1                    ((void * volatile *)REG_SWU3_UA1)                       /* SWU3 Upper Address Register n */
#define pREG_SWU3_UA2                    ((void * volatile *)REG_SWU3_UA2)                       /* SWU3 Upper Address Register n */
#define pREG_SWU3_UA3                    ((void * volatile *)REG_SWU3_UA3)                       /* SWU3 Upper Address Register n */
#define pREG_SWU3_ID0                    ((volatile uint32_t *)REG_SWU3_ID0)                     /* SWU3 ID Register n */
#define pREG_SWU3_ID1                    ((volatile uint32_t *)REG_SWU3_ID1)                     /* SWU3 ID Register n */
#define pREG_SWU3_ID2                    ((volatile uint32_t *)REG_SWU3_ID2)                     /* SWU3 ID Register n */
#define pREG_SWU3_ID3                    ((volatile uint32_t *)REG_SWU3_ID3)                     /* SWU3 ID Register n */
#define pREG_SWU3_CNT0                   ((volatile uint32_t *)REG_SWU3_CNT0)                    /* SWU3 Count Register n */
#define pREG_SWU3_CNT1                   ((volatile uint32_t *)REG_SWU3_CNT1)                    /* SWU3 Count Register n */
#define pREG_SWU3_CNT2                   ((volatile uint32_t *)REG_SWU3_CNT2)                    /* SWU3 Count Register n */
#define pREG_SWU3_CNT3                   ((volatile uint32_t *)REG_SWU3_CNT3)                    /* SWU3 Count Register n */
#define pREG_SWU3_TARG0                  ((volatile uint32_t *)REG_SWU3_TARG0)                   /* SWU3 Target Register n */
#define pREG_SWU3_TARG1                  ((volatile uint32_t *)REG_SWU3_TARG1)                   /* SWU3 Target Register n */
#define pREG_SWU3_TARG2                  ((volatile uint32_t *)REG_SWU3_TARG2)                   /* SWU3 Target Register n */
#define pREG_SWU3_TARG3                  ((volatile uint32_t *)REG_SWU3_TARG3)                   /* SWU3 Target Register n */
#define pREG_SWU3_HIST0                  ((volatile uint32_t *)REG_SWU3_HIST0)                   /* SWU3 Bandwidth History Register n */
#define pREG_SWU3_HIST1                  ((volatile uint32_t *)REG_SWU3_HIST1)                   /* SWU3 Bandwidth History Register n */
#define pREG_SWU3_HIST2                  ((volatile uint32_t *)REG_SWU3_HIST2)                   /* SWU3 Bandwidth History Register n */
#define pREG_SWU3_HIST3                  ((volatile uint32_t *)REG_SWU3_HIST3)                   /* SWU3 Bandwidth History Register n */
#define pREG_SWU3_CUR0                   ((volatile uint32_t *)REG_SWU3_CUR0)                    /* SWU3 Current Register n */
#define pREG_SWU3_CUR1                   ((volatile uint32_t *)REG_SWU3_CUR1)                    /* SWU3 Current Register n */
#define pREG_SWU3_CUR2                   ((volatile uint32_t *)REG_SWU3_CUR2)                    /* SWU3 Current Register n */
#define pREG_SWU3_CUR3                   ((volatile uint32_t *)REG_SWU3_CUR3)                    /* SWU3 Current Register n */

/* =========================================================================
       SWU4
   ========================================================================= */
#define pREG_SWU4_GCTL                   ((volatile uint32_t *)REG_SWU4_GCTL)                    /* SWU4 Global Control Register */
#define pREG_SWU4_GSTAT                  ((volatile uint32_t *)REG_SWU4_GSTAT)                   /* SWU4 Global Status Register */
#define pREG_SWU4_CTL0                   ((volatile uint32_t *)REG_SWU4_CTL0)                    /* SWU4 Control Register n */
#define pREG_SWU4_CTL1                   ((volatile uint32_t *)REG_SWU4_CTL1)                    /* SWU4 Control Register n */
#define pREG_SWU4_CTL2                   ((volatile uint32_t *)REG_SWU4_CTL2)                    /* SWU4 Control Register n */
#define pREG_SWU4_CTL3                   ((volatile uint32_t *)REG_SWU4_CTL3)                    /* SWU4 Control Register n */
#define pREG_SWU4_LA0                    ((void * volatile *)REG_SWU4_LA0)                       /* SWU4 Lower Address Register n */
#define pREG_SWU4_LA1                    ((void * volatile *)REG_SWU4_LA1)                       /* SWU4 Lower Address Register n */
#define pREG_SWU4_LA2                    ((void * volatile *)REG_SWU4_LA2)                       /* SWU4 Lower Address Register n */
#define pREG_SWU4_LA3                    ((void * volatile *)REG_SWU4_LA3)                       /* SWU4 Lower Address Register n */
#define pREG_SWU4_UA0                    ((void * volatile *)REG_SWU4_UA0)                       /* SWU4 Upper Address Register n */
#define pREG_SWU4_UA1                    ((void * volatile *)REG_SWU4_UA1)                       /* SWU4 Upper Address Register n */
#define pREG_SWU4_UA2                    ((void * volatile *)REG_SWU4_UA2)                       /* SWU4 Upper Address Register n */
#define pREG_SWU4_UA3                    ((void * volatile *)REG_SWU4_UA3)                       /* SWU4 Upper Address Register n */
#define pREG_SWU4_ID0                    ((volatile uint32_t *)REG_SWU4_ID0)                     /* SWU4 ID Register n */
#define pREG_SWU4_ID1                    ((volatile uint32_t *)REG_SWU4_ID1)                     /* SWU4 ID Register n */
#define pREG_SWU4_ID2                    ((volatile uint32_t *)REG_SWU4_ID2)                     /* SWU4 ID Register n */
#define pREG_SWU4_ID3                    ((volatile uint32_t *)REG_SWU4_ID3)                     /* SWU4 ID Register n */
#define pREG_SWU4_CNT0                   ((volatile uint32_t *)REG_SWU4_CNT0)                    /* SWU4 Count Register n */
#define pREG_SWU4_CNT1                   ((volatile uint32_t *)REG_SWU4_CNT1)                    /* SWU4 Count Register n */
#define pREG_SWU4_CNT2                   ((volatile uint32_t *)REG_SWU4_CNT2)                    /* SWU4 Count Register n */
#define pREG_SWU4_CNT3                   ((volatile uint32_t *)REG_SWU4_CNT3)                    /* SWU4 Count Register n */
#define pREG_SWU4_TARG0                  ((volatile uint32_t *)REG_SWU4_TARG0)                   /* SWU4 Target Register n */
#define pREG_SWU4_TARG1                  ((volatile uint32_t *)REG_SWU4_TARG1)                   /* SWU4 Target Register n */
#define pREG_SWU4_TARG2                  ((volatile uint32_t *)REG_SWU4_TARG2)                   /* SWU4 Target Register n */
#define pREG_SWU4_TARG3                  ((volatile uint32_t *)REG_SWU4_TARG3)                   /* SWU4 Target Register n */
#define pREG_SWU4_HIST0                  ((volatile uint32_t *)REG_SWU4_HIST0)                   /* SWU4 Bandwidth History Register n */
#define pREG_SWU4_HIST1                  ((volatile uint32_t *)REG_SWU4_HIST1)                   /* SWU4 Bandwidth History Register n */
#define pREG_SWU4_HIST2                  ((volatile uint32_t *)REG_SWU4_HIST2)                   /* SWU4 Bandwidth History Register n */
#define pREG_SWU4_HIST3                  ((volatile uint32_t *)REG_SWU4_HIST3)                   /* SWU4 Bandwidth History Register n */
#define pREG_SWU4_CUR0                   ((volatile uint32_t *)REG_SWU4_CUR0)                    /* SWU4 Current Register n */
#define pREG_SWU4_CUR1                   ((volatile uint32_t *)REG_SWU4_CUR1)                    /* SWU4 Current Register n */
#define pREG_SWU4_CUR2                   ((volatile uint32_t *)REG_SWU4_CUR2)                    /* SWU4 Current Register n */
#define pREG_SWU4_CUR3                   ((volatile uint32_t *)REG_SWU4_CUR3)                    /* SWU4 Current Register n */

/* =========================================================================
       SWU5
   ========================================================================= */
#define pREG_SWU5_GCTL                   ((volatile uint32_t *)REG_SWU5_GCTL)                    /* SWU5 Global Control Register */
#define pREG_SWU5_GSTAT                  ((volatile uint32_t *)REG_SWU5_GSTAT)                   /* SWU5 Global Status Register */
#define pREG_SWU5_CTL0                   ((volatile uint32_t *)REG_SWU5_CTL0)                    /* SWU5 Control Register n */
#define pREG_SWU5_CTL1                   ((volatile uint32_t *)REG_SWU5_CTL1)                    /* SWU5 Control Register n */
#define pREG_SWU5_CTL2                   ((volatile uint32_t *)REG_SWU5_CTL2)                    /* SWU5 Control Register n */
#define pREG_SWU5_CTL3                   ((volatile uint32_t *)REG_SWU5_CTL3)                    /* SWU5 Control Register n */
#define pREG_SWU5_LA0                    ((void * volatile *)REG_SWU5_LA0)                       /* SWU5 Lower Address Register n */
#define pREG_SWU5_LA1                    ((void * volatile *)REG_SWU5_LA1)                       /* SWU5 Lower Address Register n */
#define pREG_SWU5_LA2                    ((void * volatile *)REG_SWU5_LA2)                       /* SWU5 Lower Address Register n */
#define pREG_SWU5_LA3                    ((void * volatile *)REG_SWU5_LA3)                       /* SWU5 Lower Address Register n */
#define pREG_SWU5_UA0                    ((void * volatile *)REG_SWU5_UA0)                       /* SWU5 Upper Address Register n */
#define pREG_SWU5_UA1                    ((void * volatile *)REG_SWU5_UA1)                       /* SWU5 Upper Address Register n */
#define pREG_SWU5_UA2                    ((void * volatile *)REG_SWU5_UA2)                       /* SWU5 Upper Address Register n */
#define pREG_SWU5_UA3                    ((void * volatile *)REG_SWU5_UA3)                       /* SWU5 Upper Address Register n */
#define pREG_SWU5_ID0                    ((volatile uint32_t *)REG_SWU5_ID0)                     /* SWU5 ID Register n */
#define pREG_SWU5_ID1                    ((volatile uint32_t *)REG_SWU5_ID1)                     /* SWU5 ID Register n */
#define pREG_SWU5_ID2                    ((volatile uint32_t *)REG_SWU5_ID2)                     /* SWU5 ID Register n */
#define pREG_SWU5_ID3                    ((volatile uint32_t *)REG_SWU5_ID3)                     /* SWU5 ID Register n */
#define pREG_SWU5_CNT0                   ((volatile uint32_t *)REG_SWU5_CNT0)                    /* SWU5 Count Register n */
#define pREG_SWU5_CNT1                   ((volatile uint32_t *)REG_SWU5_CNT1)                    /* SWU5 Count Register n */
#define pREG_SWU5_CNT2                   ((volatile uint32_t *)REG_SWU5_CNT2)                    /* SWU5 Count Register n */
#define pREG_SWU5_CNT3                   ((volatile uint32_t *)REG_SWU5_CNT3)                    /* SWU5 Count Register n */
#define pREG_SWU5_TARG0                  ((volatile uint32_t *)REG_SWU5_TARG0)                   /* SWU5 Target Register n */
#define pREG_SWU5_TARG1                  ((volatile uint32_t *)REG_SWU5_TARG1)                   /* SWU5 Target Register n */
#define pREG_SWU5_TARG2                  ((volatile uint32_t *)REG_SWU5_TARG2)                   /* SWU5 Target Register n */
#define pREG_SWU5_TARG3                  ((volatile uint32_t *)REG_SWU5_TARG3)                   /* SWU5 Target Register n */
#define pREG_SWU5_HIST0                  ((volatile uint32_t *)REG_SWU5_HIST0)                   /* SWU5 Bandwidth History Register n */
#define pREG_SWU5_HIST1                  ((volatile uint32_t *)REG_SWU5_HIST1)                   /* SWU5 Bandwidth History Register n */
#define pREG_SWU5_HIST2                  ((volatile uint32_t *)REG_SWU5_HIST2)                   /* SWU5 Bandwidth History Register n */
#define pREG_SWU5_HIST3                  ((volatile uint32_t *)REG_SWU5_HIST3)                   /* SWU5 Bandwidth History Register n */
#define pREG_SWU5_CUR0                   ((volatile uint32_t *)REG_SWU5_CUR0)                    /* SWU5 Current Register n */
#define pREG_SWU5_CUR1                   ((volatile uint32_t *)REG_SWU5_CUR1)                    /* SWU5 Current Register n */
#define pREG_SWU5_CUR2                   ((volatile uint32_t *)REG_SWU5_CUR2)                    /* SWU5 Current Register n */
#define pREG_SWU5_CUR3                   ((volatile uint32_t *)REG_SWU5_CUR3)                    /* SWU5 Current Register n */

/* =========================================================================
       SWU6
   ========================================================================= */
#define pREG_SWU6_GCTL                   ((volatile uint32_t *)REG_SWU6_GCTL)                    /* SWU6 Global Control Register */
#define pREG_SWU6_GSTAT                  ((volatile uint32_t *)REG_SWU6_GSTAT)                   /* SWU6 Global Status Register */
#define pREG_SWU6_CTL0                   ((volatile uint32_t *)REG_SWU6_CTL0)                    /* SWU6 Control Register n */
#define pREG_SWU6_CTL1                   ((volatile uint32_t *)REG_SWU6_CTL1)                    /* SWU6 Control Register n */
#define pREG_SWU6_CTL2                   ((volatile uint32_t *)REG_SWU6_CTL2)                    /* SWU6 Control Register n */
#define pREG_SWU6_CTL3                   ((volatile uint32_t *)REG_SWU6_CTL3)                    /* SWU6 Control Register n */
#define pREG_SWU6_LA0                    ((void * volatile *)REG_SWU6_LA0)                       /* SWU6 Lower Address Register n */
#define pREG_SWU6_LA1                    ((void * volatile *)REG_SWU6_LA1)                       /* SWU6 Lower Address Register n */
#define pREG_SWU6_LA2                    ((void * volatile *)REG_SWU6_LA2)                       /* SWU6 Lower Address Register n */
#define pREG_SWU6_LA3                    ((void * volatile *)REG_SWU6_LA3)                       /* SWU6 Lower Address Register n */
#define pREG_SWU6_UA0                    ((void * volatile *)REG_SWU6_UA0)                       /* SWU6 Upper Address Register n */
#define pREG_SWU6_UA1                    ((void * volatile *)REG_SWU6_UA1)                       /* SWU6 Upper Address Register n */
#define pREG_SWU6_UA2                    ((void * volatile *)REG_SWU6_UA2)                       /* SWU6 Upper Address Register n */
#define pREG_SWU6_UA3                    ((void * volatile *)REG_SWU6_UA3)                       /* SWU6 Upper Address Register n */
#define pREG_SWU6_ID0                    ((volatile uint32_t *)REG_SWU6_ID0)                     /* SWU6 ID Register n */
#define pREG_SWU6_ID1                    ((volatile uint32_t *)REG_SWU6_ID1)                     /* SWU6 ID Register n */
#define pREG_SWU6_ID2                    ((volatile uint32_t *)REG_SWU6_ID2)                     /* SWU6 ID Register n */
#define pREG_SWU6_ID3                    ((volatile uint32_t *)REG_SWU6_ID3)                     /* SWU6 ID Register n */
#define pREG_SWU6_CNT0                   ((volatile uint32_t *)REG_SWU6_CNT0)                    /* SWU6 Count Register n */
#define pREG_SWU6_CNT1                   ((volatile uint32_t *)REG_SWU6_CNT1)                    /* SWU6 Count Register n */
#define pREG_SWU6_CNT2                   ((volatile uint32_t *)REG_SWU6_CNT2)                    /* SWU6 Count Register n */
#define pREG_SWU6_CNT3                   ((volatile uint32_t *)REG_SWU6_CNT3)                    /* SWU6 Count Register n */
#define pREG_SWU6_TARG0                  ((volatile uint32_t *)REG_SWU6_TARG0)                   /* SWU6 Target Register n */
#define pREG_SWU6_TARG1                  ((volatile uint32_t *)REG_SWU6_TARG1)                   /* SWU6 Target Register n */
#define pREG_SWU6_TARG2                  ((volatile uint32_t *)REG_SWU6_TARG2)                   /* SWU6 Target Register n */
#define pREG_SWU6_TARG3                  ((volatile uint32_t *)REG_SWU6_TARG3)                   /* SWU6 Target Register n */
#define pREG_SWU6_HIST0                  ((volatile uint32_t *)REG_SWU6_HIST0)                   /* SWU6 Bandwidth History Register n */
#define pREG_SWU6_HIST1                  ((volatile uint32_t *)REG_SWU6_HIST1)                   /* SWU6 Bandwidth History Register n */
#define pREG_SWU6_HIST2                  ((volatile uint32_t *)REG_SWU6_HIST2)                   /* SWU6 Bandwidth History Register n */
#define pREG_SWU6_HIST3                  ((volatile uint32_t *)REG_SWU6_HIST3)                   /* SWU6 Bandwidth History Register n */
#define pREG_SWU6_CUR0                   ((volatile uint32_t *)REG_SWU6_CUR0)                    /* SWU6 Current Register n */
#define pREG_SWU6_CUR1                   ((volatile uint32_t *)REG_SWU6_CUR1)                    /* SWU6 Current Register n */
#define pREG_SWU6_CUR2                   ((volatile uint32_t *)REG_SWU6_CUR2)                    /* SWU6 Current Register n */
#define pREG_SWU6_CUR3                   ((volatile uint32_t *)REG_SWU6_CUR3)                    /* SWU6 Current Register n */

/* =========================================================================
       SWU7
   ========================================================================= */
#define pREG_SWU7_GCTL                   ((volatile uint32_t *)REG_SWU7_GCTL)                    /* SWU7 Global Control Register */
#define pREG_SWU7_GSTAT                  ((volatile uint32_t *)REG_SWU7_GSTAT)                   /* SWU7 Global Status Register */
#define pREG_SWU7_CTL0                   ((volatile uint32_t *)REG_SWU7_CTL0)                    /* SWU7 Control Register n */
#define pREG_SWU7_CTL1                   ((volatile uint32_t *)REG_SWU7_CTL1)                    /* SWU7 Control Register n */
#define pREG_SWU7_CTL2                   ((volatile uint32_t *)REG_SWU7_CTL2)                    /* SWU7 Control Register n */
#define pREG_SWU7_CTL3                   ((volatile uint32_t *)REG_SWU7_CTL3)                    /* SWU7 Control Register n */
#define pREG_SWU7_LA0                    ((void * volatile *)REG_SWU7_LA0)                       /* SWU7 Lower Address Register n */
#define pREG_SWU7_LA1                    ((void * volatile *)REG_SWU7_LA1)                       /* SWU7 Lower Address Register n */
#define pREG_SWU7_LA2                    ((void * volatile *)REG_SWU7_LA2)                       /* SWU7 Lower Address Register n */
#define pREG_SWU7_LA3                    ((void * volatile *)REG_SWU7_LA3)                       /* SWU7 Lower Address Register n */
#define pREG_SWU7_UA0                    ((void * volatile *)REG_SWU7_UA0)                       /* SWU7 Upper Address Register n */
#define pREG_SWU7_UA1                    ((void * volatile *)REG_SWU7_UA1)                       /* SWU7 Upper Address Register n */
#define pREG_SWU7_UA2                    ((void * volatile *)REG_SWU7_UA2)                       /* SWU7 Upper Address Register n */
#define pREG_SWU7_UA3                    ((void * volatile *)REG_SWU7_UA3)                       /* SWU7 Upper Address Register n */
#define pREG_SWU7_ID0                    ((volatile uint32_t *)REG_SWU7_ID0)                     /* SWU7 ID Register n */
#define pREG_SWU7_ID1                    ((volatile uint32_t *)REG_SWU7_ID1)                     /* SWU7 ID Register n */
#define pREG_SWU7_ID2                    ((volatile uint32_t *)REG_SWU7_ID2)                     /* SWU7 ID Register n */
#define pREG_SWU7_ID3                    ((volatile uint32_t *)REG_SWU7_ID3)                     /* SWU7 ID Register n */
#define pREG_SWU7_CNT0                   ((volatile uint32_t *)REG_SWU7_CNT0)                    /* SWU7 Count Register n */
#define pREG_SWU7_CNT1                   ((volatile uint32_t *)REG_SWU7_CNT1)                    /* SWU7 Count Register n */
#define pREG_SWU7_CNT2                   ((volatile uint32_t *)REG_SWU7_CNT2)                    /* SWU7 Count Register n */
#define pREG_SWU7_CNT3                   ((volatile uint32_t *)REG_SWU7_CNT3)                    /* SWU7 Count Register n */
#define pREG_SWU7_TARG0                  ((volatile uint32_t *)REG_SWU7_TARG0)                   /* SWU7 Target Register n */
#define pREG_SWU7_TARG1                  ((volatile uint32_t *)REG_SWU7_TARG1)                   /* SWU7 Target Register n */
#define pREG_SWU7_TARG2                  ((volatile uint32_t *)REG_SWU7_TARG2)                   /* SWU7 Target Register n */
#define pREG_SWU7_TARG3                  ((volatile uint32_t *)REG_SWU7_TARG3)                   /* SWU7 Target Register n */
#define pREG_SWU7_HIST0                  ((volatile uint32_t *)REG_SWU7_HIST0)                   /* SWU7 Bandwidth History Register n */
#define pREG_SWU7_HIST1                  ((volatile uint32_t *)REG_SWU7_HIST1)                   /* SWU7 Bandwidth History Register n */
#define pREG_SWU7_HIST2                  ((volatile uint32_t *)REG_SWU7_HIST2)                   /* SWU7 Bandwidth History Register n */
#define pREG_SWU7_HIST3                  ((volatile uint32_t *)REG_SWU7_HIST3)                   /* SWU7 Bandwidth History Register n */
#define pREG_SWU7_CUR0                   ((volatile uint32_t *)REG_SWU7_CUR0)                    /* SWU7 Current Register n */
#define pREG_SWU7_CUR1                   ((volatile uint32_t *)REG_SWU7_CUR1)                    /* SWU7 Current Register n */
#define pREG_SWU7_CUR2                   ((volatile uint32_t *)REG_SWU7_CUR2)                    /* SWU7 Current Register n */
#define pREG_SWU7_CUR3                   ((volatile uint32_t *)REG_SWU7_CUR3)                    /* SWU7 Current Register n */

/* =========================================================================
       PORTA
   ========================================================================= */
#define pREG_PORTA_FER                   ((volatile uint32_t *)REG_PORTA_FER)                    /* PORTA Port x Function Enable Register */
#define pREG_PORTA_FER_SET               ((volatile uint32_t *)REG_PORTA_FER_SET)                /* PORTA Port x Function Enable Set Register */
#define pREG_PORTA_FER_CLR               ((volatile uint32_t *)REG_PORTA_FER_CLR)                /* PORTA Port x Function Enable Clear Register */
#define pREG_PORTA_DATA                  ((volatile uint32_t *)REG_PORTA_DATA)                   /* PORTA Port x GPIO Data Register */
#define pREG_PORTA_DATA_SET              ((volatile uint32_t *)REG_PORTA_DATA_SET)               /* PORTA Port x GPIO Data Set Register */
#define pREG_PORTA_DATA_CLR              ((volatile uint32_t *)REG_PORTA_DATA_CLR)               /* PORTA Port x GPIO Data Clear Register */
#define pREG_PORTA_DIR                   ((volatile uint32_t *)REG_PORTA_DIR)                    /* PORTA Port x GPIO Direction Register */
#define pREG_PORTA_DIR_SET               ((volatile uint32_t *)REG_PORTA_DIR_SET)                /* PORTA Port x GPIO Direction Set Register */
#define pREG_PORTA_DIR_CLR               ((volatile uint32_t *)REG_PORTA_DIR_CLR)                /* PORTA Port x GPIO Direction Clear Register */
#define pREG_PORTA_INEN                  ((volatile uint32_t *)REG_PORTA_INEN)                   /* PORTA Port x GPIO Input Enable Register */
#define pREG_PORTA_INEN_SET              ((volatile uint32_t *)REG_PORTA_INEN_SET)               /* PORTA Port x GPIO Input Enable Set Register */
#define pREG_PORTA_INEN_CLR              ((volatile uint32_t *)REG_PORTA_INEN_CLR)               /* PORTA Port x GPIO Input Enable Clear Register */
#define pREG_PORTA_MUX                   ((volatile uint32_t *)REG_PORTA_MUX)                    /* PORTA Port x Multiplexer Control Register */
#define pREG_PORTA_DATA_TGL              ((volatile uint32_t *)REG_PORTA_DATA_TGL)               /* PORTA Port x GPIO Input Enable Toggle Register */
#define pREG_PORTA_POL                   ((volatile uint32_t *)REG_PORTA_POL)                    /* PORTA Port x GPIO Polarity Invert Register */
#define pREG_PORTA_POL_SET               ((volatile uint32_t *)REG_PORTA_POL_SET)                /* PORTA Port x GPIO Polarity Invert Set Register */
#define pREG_PORTA_POL_CLR               ((volatile uint32_t *)REG_PORTA_POL_CLR)                /* PORTA Port x GPIO Polarity Invert Clear Register */
#define pREG_PORTA_LOCK                  ((volatile uint32_t *)REG_PORTA_LOCK)                   /* PORTA Port x GPIO Lock Register */
#define pREG_PORTA_TRIG_TGL              ((volatile uint32_t *)REG_PORTA_TRIG_TGL)               /* PORTA Port x GPIO Trigger Toggle Register */

/* =========================================================================
       PORTB
   ========================================================================= */
#define pREG_PORTB_FER                   ((volatile uint32_t *)REG_PORTB_FER)                    /* PORTB Port x Function Enable Register */
#define pREG_PORTB_FER_SET               ((volatile uint32_t *)REG_PORTB_FER_SET)                /* PORTB Port x Function Enable Set Register */
#define pREG_PORTB_FER_CLR               ((volatile uint32_t *)REG_PORTB_FER_CLR)                /* PORTB Port x Function Enable Clear Register */
#define pREG_PORTB_DATA                  ((volatile uint32_t *)REG_PORTB_DATA)                   /* PORTB Port x GPIO Data Register */
#define pREG_PORTB_DATA_SET              ((volatile uint32_t *)REG_PORTB_DATA_SET)               /* PORTB Port x GPIO Data Set Register */
#define pREG_PORTB_DATA_CLR              ((volatile uint32_t *)REG_PORTB_DATA_CLR)               /* PORTB Port x GPIO Data Clear Register */
#define pREG_PORTB_DIR                   ((volatile uint32_t *)REG_PORTB_DIR)                    /* PORTB Port x GPIO Direction Register */
#define pREG_PORTB_DIR_SET               ((volatile uint32_t *)REG_PORTB_DIR_SET)                /* PORTB Port x GPIO Direction Set Register */
#define pREG_PORTB_DIR_CLR               ((volatile uint32_t *)REG_PORTB_DIR_CLR)                /* PORTB Port x GPIO Direction Clear Register */
#define pREG_PORTB_INEN                  ((volatile uint32_t *)REG_PORTB_INEN)                   /* PORTB Port x GPIO Input Enable Register */
#define pREG_PORTB_INEN_SET              ((volatile uint32_t *)REG_PORTB_INEN_SET)               /* PORTB Port x GPIO Input Enable Set Register */
#define pREG_PORTB_INEN_CLR              ((volatile uint32_t *)REG_PORTB_INEN_CLR)               /* PORTB Port x GPIO Input Enable Clear Register */
#define pREG_PORTB_MUX                   ((volatile uint32_t *)REG_PORTB_MUX)                    /* PORTB Port x Multiplexer Control Register */
#define pREG_PORTB_DATA_TGL              ((volatile uint32_t *)REG_PORTB_DATA_TGL)               /* PORTB Port x GPIO Input Enable Toggle Register */
#define pREG_PORTB_POL                   ((volatile uint32_t *)REG_PORTB_POL)                    /* PORTB Port x GPIO Polarity Invert Register */
#define pREG_PORTB_POL_SET               ((volatile uint32_t *)REG_PORTB_POL_SET)                /* PORTB Port x GPIO Polarity Invert Set Register */
#define pREG_PORTB_POL_CLR               ((volatile uint32_t *)REG_PORTB_POL_CLR)                /* PORTB Port x GPIO Polarity Invert Clear Register */
#define pREG_PORTB_LOCK                  ((volatile uint32_t *)REG_PORTB_LOCK)                   /* PORTB Port x GPIO Lock Register */
#define pREG_PORTB_TRIG_TGL              ((volatile uint32_t *)REG_PORTB_TRIG_TGL)               /* PORTB Port x GPIO Trigger Toggle Register */

/* =========================================================================
       PORTC
   ========================================================================= */
#define pREG_PORTC_FER                   ((volatile uint32_t *)REG_PORTC_FER)                    /* PORTC Port x Function Enable Register */
#define pREG_PORTC_FER_SET               ((volatile uint32_t *)REG_PORTC_FER_SET)                /* PORTC Port x Function Enable Set Register */
#define pREG_PORTC_FER_CLR               ((volatile uint32_t *)REG_PORTC_FER_CLR)                /* PORTC Port x Function Enable Clear Register */
#define pREG_PORTC_DATA                  ((volatile uint32_t *)REG_PORTC_DATA)                   /* PORTC Port x GPIO Data Register */
#define pREG_PORTC_DATA_SET              ((volatile uint32_t *)REG_PORTC_DATA_SET)               /* PORTC Port x GPIO Data Set Register */
#define pREG_PORTC_DATA_CLR              ((volatile uint32_t *)REG_PORTC_DATA_CLR)               /* PORTC Port x GPIO Data Clear Register */
#define pREG_PORTC_DIR                   ((volatile uint32_t *)REG_PORTC_DIR)                    /* PORTC Port x GPIO Direction Register */
#define pREG_PORTC_DIR_SET               ((volatile uint32_t *)REG_PORTC_DIR_SET)                /* PORTC Port x GPIO Direction Set Register */
#define pREG_PORTC_DIR_CLR               ((volatile uint32_t *)REG_PORTC_DIR_CLR)                /* PORTC Port x GPIO Direction Clear Register */
#define pREG_PORTC_INEN                  ((volatile uint32_t *)REG_PORTC_INEN)                   /* PORTC Port x GPIO Input Enable Register */
#define pREG_PORTC_INEN_SET              ((volatile uint32_t *)REG_PORTC_INEN_SET)               /* PORTC Port x GPIO Input Enable Set Register */
#define pREG_PORTC_INEN_CLR              ((volatile uint32_t *)REG_PORTC_INEN_CLR)               /* PORTC Port x GPIO Input Enable Clear Register */
#define pREG_PORTC_MUX                   ((volatile uint32_t *)REG_PORTC_MUX)                    /* PORTC Port x Multiplexer Control Register */
#define pREG_PORTC_DATA_TGL              ((volatile uint32_t *)REG_PORTC_DATA_TGL)               /* PORTC Port x GPIO Input Enable Toggle Register */
#define pREG_PORTC_POL                   ((volatile uint32_t *)REG_PORTC_POL)                    /* PORTC Port x GPIO Polarity Invert Register */
#define pREG_PORTC_POL_SET               ((volatile uint32_t *)REG_PORTC_POL_SET)                /* PORTC Port x GPIO Polarity Invert Set Register */
#define pREG_PORTC_POL_CLR               ((volatile uint32_t *)REG_PORTC_POL_CLR)                /* PORTC Port x GPIO Polarity Invert Clear Register */
#define pREG_PORTC_LOCK                  ((volatile uint32_t *)REG_PORTC_LOCK)                   /* PORTC Port x GPIO Lock Register */
#define pREG_PORTC_TRIG_TGL              ((volatile uint32_t *)REG_PORTC_TRIG_TGL)               /* PORTC Port x GPIO Trigger Toggle Register */


/* =========================================================================
       PADS0
   ========================================================================= */
#define pREG_PADS0_PCFG0                 ((volatile uint32_t *)REG_PADS0_PCFG0)                  /* PADS0 Peripheral Configuration0 Register */



/* =========================================================================
       PINT0
   ========================================================================= */
#define pREG_PINT0_MSK_SET               ((volatile uint32_t *)REG_PINT0_MSK_SET)                /* PINT0 Pint Mask Set Register */
#define pREG_PINT0_MSK_CLR               ((volatile uint32_t *)REG_PINT0_MSK_CLR)                /* PINT0 Pint Mask Clear Register */
#define pREG_PINT0_REQ                   ((volatile uint32_t *)REG_PINT0_REQ)                    /* PINT0 Pint Request Register */
#define pREG_PINT0_ASSIGN                ((volatile uint32_t *)REG_PINT0_ASSIGN)                 /* PINT0 Pint Assign Register */
#define pREG_PINT0_EDGE_SET              ((volatile uint32_t *)REG_PINT0_EDGE_SET)               /* PINT0 Pint Edge Set Register */
#define pREG_PINT0_EDGE_CLR              ((volatile uint32_t *)REG_PINT0_EDGE_CLR)               /* PINT0 Pint Edge Clear Register */
#define pREG_PINT0_INV_SET               ((volatile uint32_t *)REG_PINT0_INV_SET)                /* PINT0 Pint Invert Set Register */
#define pREG_PINT0_INV_CLR               ((volatile uint32_t *)REG_PINT0_INV_CLR)                /* PINT0 Pint Invert Clear Register */
#define pREG_PINT0_PINSTATE              ((volatile uint32_t *)REG_PINT0_PINSTATE)               /* PINT0 Pint Pinstate Register */
#define pREG_PINT0_LATCH                 ((volatile uint32_t *)REG_PINT0_LATCH)                  /* PINT0 Pint Latch Register */

/* =========================================================================
       PINT1
   ========================================================================= */
#define pREG_PINT1_MSK_SET               ((volatile uint32_t *)REG_PINT1_MSK_SET)                /* PINT1 Pint Mask Set Register */
#define pREG_PINT1_MSK_CLR               ((volatile uint32_t *)REG_PINT1_MSK_CLR)                /* PINT1 Pint Mask Clear Register */
#define pREG_PINT1_REQ                   ((volatile uint32_t *)REG_PINT1_REQ)                    /* PINT1 Pint Request Register */
#define pREG_PINT1_ASSIGN                ((volatile uint32_t *)REG_PINT1_ASSIGN)                 /* PINT1 Pint Assign Register */
#define pREG_PINT1_EDGE_SET              ((volatile uint32_t *)REG_PINT1_EDGE_SET)               /* PINT1 Pint Edge Set Register */
#define pREG_PINT1_EDGE_CLR              ((volatile uint32_t *)REG_PINT1_EDGE_CLR)               /* PINT1 Pint Edge Clear Register */
#define pREG_PINT1_INV_SET               ((volatile uint32_t *)REG_PINT1_INV_SET)                /* PINT1 Pint Invert Set Register */
#define pREG_PINT1_INV_CLR               ((volatile uint32_t *)REG_PINT1_INV_CLR)                /* PINT1 Pint Invert Clear Register */
#define pREG_PINT1_PINSTATE              ((volatile uint32_t *)REG_PINT1_PINSTATE)               /* PINT1 Pint Pinstate Register */
#define pREG_PINT1_LATCH                 ((volatile uint32_t *)REG_PINT1_LATCH)                  /* PINT1 Pint Latch Register */

/* =========================================================================
       PINT2
   ========================================================================= */
#define pREG_PINT2_MSK_SET               ((volatile uint32_t *)REG_PINT2_MSK_SET)                /* PINT2 Pint Mask Set Register */
#define pREG_PINT2_MSK_CLR               ((volatile uint32_t *)REG_PINT2_MSK_CLR)                /* PINT2 Pint Mask Clear Register */
#define pREG_PINT2_REQ                   ((volatile uint32_t *)REG_PINT2_REQ)                    /* PINT2 Pint Request Register */
#define pREG_PINT2_ASSIGN                ((volatile uint32_t *)REG_PINT2_ASSIGN)                 /* PINT2 Pint Assign Register */
#define pREG_PINT2_EDGE_SET              ((volatile uint32_t *)REG_PINT2_EDGE_SET)               /* PINT2 Pint Edge Set Register */
#define pREG_PINT2_EDGE_CLR              ((volatile uint32_t *)REG_PINT2_EDGE_CLR)               /* PINT2 Pint Edge Clear Register */
#define pREG_PINT2_INV_SET               ((volatile uint32_t *)REG_PINT2_INV_SET)                /* PINT2 Pint Invert Set Register */
#define pREG_PINT2_INV_CLR               ((volatile uint32_t *)REG_PINT2_INV_CLR)                /* PINT2 Pint Invert Clear Register */
#define pREG_PINT2_PINSTATE              ((volatile uint32_t *)REG_PINT2_PINSTATE)               /* PINT2 Pint Pinstate Register */
#define pREG_PINT2_LATCH                 ((volatile uint32_t *)REG_PINT2_LATCH)                  /* PINT2 Pint Latch Register */


/* =========================================================================
       TIMER0
   ========================================================================= */
#define pREG_TIMER0_RUN                  ((volatile uint32_t *)REG_TIMER0_RUN)                   /* TIMER0 Run Register */
#define pREG_TIMER0_RUN_SET              ((volatile uint32_t *)REG_TIMER0_RUN_SET)               /* TIMER0 Run Set Register */
#define pREG_TIMER0_RUN_CLR              ((volatile uint32_t *)REG_TIMER0_RUN_CLR)               /* TIMER0 Run Clear Register */
#define pREG_TIMER0_STOP_CFG             ((volatile uint32_t *)REG_TIMER0_STOP_CFG)              /* TIMER0 Stop Configuration Register */
#define pREG_TIMER0_STOP_CFG_SET         ((volatile uint32_t *)REG_TIMER0_STOP_CFG_SET)          /* TIMER0 Stop Configuration Set Register */
#define pREG_TIMER0_STOP_CFG_CLR         ((volatile uint32_t *)REG_TIMER0_STOP_CFG_CLR)          /* TIMER0 Stop Configuration Clear Register */
#define pREG_TIMER0_DATA_IMSK            ((volatile uint32_t *)REG_TIMER0_DATA_IMSK)             /* TIMER0 Data Interrupt Mask Register */
#define pREG_TIMER0_STAT_IMSK            ((volatile uint32_t *)REG_TIMER0_STAT_IMSK)             /* TIMER0 Status Interrupt Mask Register */
#define pREG_TIMER0_TRG_MSK              ((volatile uint32_t *)REG_TIMER0_TRG_MSK)               /* TIMER0 Trigger Master Mask Register */
#define pREG_TIMER0_TRG_IE               ((volatile uint32_t *)REG_TIMER0_TRG_IE)                /* TIMER0 Trigger Slave Enable Register */
#define pREG_TIMER0_DATA_ILAT            ((volatile uint32_t *)REG_TIMER0_DATA_ILAT)             /* TIMER0 Data Interrupt Latch Register */
#define pREG_TIMER0_STAT_ILAT            ((volatile uint32_t *)REG_TIMER0_STAT_ILAT)             /* TIMER0 Status Interrupt Latch Register */
#define pREG_TIMER0_ERR_TYPE             ((volatile uint32_t *)REG_TIMER0_ERR_TYPE)              /* TIMER0 Error Type Status Register */
#define pREG_TIMER0_BCAST_PER            ((volatile uint32_t *)REG_TIMER0_BCAST_PER)             /* TIMER0 Broadcast Period Register */
#define pREG_TIMER0_BCAST_WID            ((volatile uint32_t *)REG_TIMER0_BCAST_WID)             /* TIMER0 Broadcast Width Register */
#define pREG_TIMER0_BCAST_DLY            ((volatile uint32_t *)REG_TIMER0_BCAST_DLY)             /* TIMER0 Broadcast Delay Register */
#define pREG_TIMER0_TMR0_CFG             ((volatile uint32_t *)REG_TIMER0_TMR0_CFG)              /* TIMER0 Timer n Configuration Register */
#define pREG_TIMER0_TMR1_CFG             ((volatile uint32_t *)REG_TIMER0_TMR1_CFG)              /* TIMER0 Timer n Configuration Register */
#define pREG_TIMER0_TMR2_CFG             ((volatile uint32_t *)REG_TIMER0_TMR2_CFG)              /* TIMER0 Timer n Configuration Register */
#define pREG_TIMER0_TMR3_CFG             ((volatile uint32_t *)REG_TIMER0_TMR3_CFG)              /* TIMER0 Timer n Configuration Register */
#define pREG_TIMER0_TMR4_CFG             ((volatile uint32_t *)REG_TIMER0_TMR4_CFG)              /* TIMER0 Timer n Configuration Register */
#define pREG_TIMER0_TMR5_CFG             ((volatile uint32_t *)REG_TIMER0_TMR5_CFG)              /* TIMER0 Timer n Configuration Register */
#define pREG_TIMER0_TMR6_CFG             ((volatile uint32_t *)REG_TIMER0_TMR6_CFG)              /* TIMER0 Timer n Configuration Register */
#define pREG_TIMER0_TMR7_CFG             ((volatile uint32_t *)REG_TIMER0_TMR7_CFG)              /* TIMER0 Timer n Configuration Register */
#define pREG_TIMER0_TMR0_CNT             ((volatile uint32_t *)REG_TIMER0_TMR0_CNT)              /* TIMER0 Timer n Counter Register */
#define pREG_TIMER0_TMR1_CNT             ((volatile uint32_t *)REG_TIMER0_TMR1_CNT)              /* TIMER0 Timer n Counter Register */
#define pREG_TIMER0_TMR2_CNT             ((volatile uint32_t *)REG_TIMER0_TMR2_CNT)              /* TIMER0 Timer n Counter Register */
#define pREG_TIMER0_TMR3_CNT             ((volatile uint32_t *)REG_TIMER0_TMR3_CNT)              /* TIMER0 Timer n Counter Register */
#define pREG_TIMER0_TMR4_CNT             ((volatile uint32_t *)REG_TIMER0_TMR4_CNT)              /* TIMER0 Timer n Counter Register */
#define pREG_TIMER0_TMR5_CNT             ((volatile uint32_t *)REG_TIMER0_TMR5_CNT)              /* TIMER0 Timer n Counter Register */
#define pREG_TIMER0_TMR6_CNT             ((volatile uint32_t *)REG_TIMER0_TMR6_CNT)              /* TIMER0 Timer n Counter Register */
#define pREG_TIMER0_TMR7_CNT             ((volatile uint32_t *)REG_TIMER0_TMR7_CNT)              /* TIMER0 Timer n Counter Register */
#define pREG_TIMER0_TMR0_PER             ((volatile uint32_t *)REG_TIMER0_TMR0_PER)              /* TIMER0 Timer n Period Register */
#define pREG_TIMER0_TMR1_PER             ((volatile uint32_t *)REG_TIMER0_TMR1_PER)              /* TIMER0 Timer n Period Register */
#define pREG_TIMER0_TMR2_PER             ((volatile uint32_t *)REG_TIMER0_TMR2_PER)              /* TIMER0 Timer n Period Register */
#define pREG_TIMER0_TMR3_PER             ((volatile uint32_t *)REG_TIMER0_TMR3_PER)              /* TIMER0 Timer n Period Register */
#define pREG_TIMER0_TMR4_PER             ((volatile uint32_t *)REG_TIMER0_TMR4_PER)              /* TIMER0 Timer n Period Register */
#define pREG_TIMER0_TMR5_PER             ((volatile uint32_t *)REG_TIMER0_TMR5_PER)              /* TIMER0 Timer n Period Register */
#define pREG_TIMER0_TMR6_PER             ((volatile uint32_t *)REG_TIMER0_TMR6_PER)              /* TIMER0 Timer n Period Register */
#define pREG_TIMER0_TMR7_PER             ((volatile uint32_t *)REG_TIMER0_TMR7_PER)              /* TIMER0 Timer n Period Register */
#define pREG_TIMER0_TMR0_WID             ((volatile uint32_t *)REG_TIMER0_TMR0_WID)              /* TIMER0 Timer n Width Register */
#define pREG_TIMER0_TMR1_WID             ((volatile uint32_t *)REG_TIMER0_TMR1_WID)              /* TIMER0 Timer n Width Register */
#define pREG_TIMER0_TMR2_WID             ((volatile uint32_t *)REG_TIMER0_TMR2_WID)              /* TIMER0 Timer n Width Register */
#define pREG_TIMER0_TMR3_WID             ((volatile uint32_t *)REG_TIMER0_TMR3_WID)              /* TIMER0 Timer n Width Register */
#define pREG_TIMER0_TMR4_WID             ((volatile uint32_t *)REG_TIMER0_TMR4_WID)              /* TIMER0 Timer n Width Register */
#define pREG_TIMER0_TMR5_WID             ((volatile uint32_t *)REG_TIMER0_TMR5_WID)              /* TIMER0 Timer n Width Register */
#define pREG_TIMER0_TMR6_WID             ((volatile uint32_t *)REG_TIMER0_TMR6_WID)              /* TIMER0 Timer n Width Register */
#define pREG_TIMER0_TMR7_WID             ((volatile uint32_t *)REG_TIMER0_TMR7_WID)              /* TIMER0 Timer n Width Register */
#define pREG_TIMER0_TMR0_DLY             ((volatile uint32_t *)REG_TIMER0_TMR0_DLY)              /* TIMER0 Timer n Delay Register */
#define pREG_TIMER0_TMR1_DLY             ((volatile uint32_t *)REG_TIMER0_TMR1_DLY)              /* TIMER0 Timer n Delay Register */
#define pREG_TIMER0_TMR2_DLY             ((volatile uint32_t *)REG_TIMER0_TMR2_DLY)              /* TIMER0 Timer n Delay Register */
#define pREG_TIMER0_TMR3_DLY             ((volatile uint32_t *)REG_TIMER0_TMR3_DLY)              /* TIMER0 Timer n Delay Register */
#define pREG_TIMER0_TMR4_DLY             ((volatile uint32_t *)REG_TIMER0_TMR4_DLY)              /* TIMER0 Timer n Delay Register */
#define pREG_TIMER0_TMR5_DLY             ((volatile uint32_t *)REG_TIMER0_TMR5_DLY)              /* TIMER0 Timer n Delay Register */
#define pREG_TIMER0_TMR6_DLY             ((volatile uint32_t *)REG_TIMER0_TMR6_DLY)              /* TIMER0 Timer n Delay Register */
#define pREG_TIMER0_TMR7_DLY             ((volatile uint32_t *)REG_TIMER0_TMR7_DLY)              /* TIMER0 Timer n Delay Register */


/* =========================================================================
       WDOG0
   ========================================================================= */
#define pREG_WDOG0_CTL                   ((volatile uint32_t *)REG_WDOG0_CTL)                    /* WDOG0 Control Register */
#define pREG_WDOG0_CNT                   ((volatile uint32_t *)REG_WDOG0_CNT)                    /* WDOG0 Count Register */
#define pREG_WDOG0_STAT                  ((volatile uint32_t *)REG_WDOG0_STAT)                   /* WDOG0 Watchdog Timer Status Register */


/* =========================================================================
       TAPC0
   ========================================================================= */
#define pREG_TAPC0_IDCODE                ((volatile uint32_t *)REG_TAPC0_IDCODE)                 /* TAPC0 IDCODE Register */
#define pREG_TAPC0_USERCODE              ((volatile uint32_t *)REG_TAPC0_USERCODE)               /* TAPC0 USERCODE Register */
#define pREG_TAPC0_SDBGKEY_CTL           ((volatile uint32_t *)REG_TAPC0_SDBGKEY_CTL)            /* TAPC0 Secure Debug Control Register */
#define pREG_TAPC0_SDBGKEY_STAT          ((volatile uint32_t *)REG_TAPC0_SDBGKEY_STAT)           /* TAPC0 Secure Debug Key Status Register */
#define pREG_TAPC0_SDBGKEY0              ((volatile uint32_t *)REG_TAPC0_SDBGKEY0)               /* TAPC0 Secure Debug Key 0 Register */
#define pREG_TAPC0_SDBGKEY1              ((volatile uint32_t *)REG_TAPC0_SDBGKEY1)               /* TAPC0 Secure Debug Key 1 Register */
#define pREG_TAPC0_SDBGKEY2              ((volatile uint32_t *)REG_TAPC0_SDBGKEY2)               /* TAPC0 Secure Debug Key 2 Register */
#define pREG_TAPC0_SDBGKEY3              ((volatile uint32_t *)REG_TAPC0_SDBGKEY3)               /* TAPC0 Secure Debug Key 3 Register */
#define pREG_TAPC0_DBGCTL                ((volatile uint32_t *)REG_TAPC0_DBGCTL)                 /* TAPC0 Debug Control Register */


/* =========================================================================
       TWI0
   ========================================================================= */
#define pREG_TWI0_CLKDIV                 ((volatile uint32_t *)REG_TWI0_CLKDIV)                  /* TWI0 SCL Clock Divider Register */
#define pREG_TWI0_CTL                    ((volatile uint32_t *)REG_TWI0_CTL)                     /* TWI0 Control Register */
#define pREG_TWI0_SLVCTL                 ((volatile uint32_t *)REG_TWI0_SLVCTL)                  /* TWI0 Slave Mode Control Register */
#define pREG_TWI0_SLVSTAT                ((volatile uint32_t *)REG_TWI0_SLVSTAT)                 /* TWI0 Slave Mode Status Register */
#define pREG_TWI0_SLVADDR                ((volatile uint32_t *)REG_TWI0_SLVADDR)                 /* TWI0 Slave Mode Address Register */
#define pREG_TWI0_MSTRCTL                ((volatile uint32_t *)REG_TWI0_MSTRCTL)                 /* TWI0 Master Mode Control Registers */
#define pREG_TWI0_MSTRSTAT               ((volatile uint32_t *)REG_TWI0_MSTRSTAT)                /* TWI0 Master Mode Status Register */
#define pREG_TWI0_MSTRADDR               ((volatile uint32_t *)REG_TWI0_MSTRADDR)                /* TWI0 Master Mode Address Register */
#define pREG_TWI0_ISTAT                  ((volatile uint32_t *)REG_TWI0_ISTAT)                   /* TWI0 Interrupt Status Register */
#define pREG_TWI0_IMSK                   ((volatile uint32_t *)REG_TWI0_IMSK)                    /* TWI0 Interrupt Mask Register */
#define pREG_TWI0_FIFOCTL                ((volatile uint32_t *)REG_TWI0_FIFOCTL)                 /* TWI0 FIFO Control Register */
#define pREG_TWI0_FIFOSTAT               ((volatile uint32_t *)REG_TWI0_FIFOSTAT)                /* TWI0 FIFO Status Register */
#define pREG_TWI0_TXDATA8                ((volatile uint32_t *)REG_TWI0_TXDATA8)                 /* TWI0 Tx Data Single-Byte Register */
#define pREG_TWI0_TXDATA16               ((volatile uint32_t *)REG_TWI0_TXDATA16)                /* TWI0 Tx Data Double-Byte Register */
#define pREG_TWI0_RXDATA8                ((volatile uint32_t *)REG_TWI0_RXDATA8)                 /* TWI0 Rx Data Single-Byte Register */
#define pREG_TWI0_RXDATA16               ((volatile uint32_t *)REG_TWI0_RXDATA16)                /* TWI0 Rx Data Double-Byte Register */


/* =========================================================================
       SPORT0
   ========================================================================= */
#define pREG_SPORT0_CTL_A                ((volatile uint32_t *)REG_SPORT0_CTL_A)                 /* SPORT0 Half SPORT 'A' Control Register */
#define pREG_SPORT0_DIV_A                ((volatile uint32_t *)REG_SPORT0_DIV_A)                 /* SPORT0 Half SPORT 'A' Divisor Register */
#define pREG_SPORT0_MCTL_A               ((volatile uint32_t *)REG_SPORT0_MCTL_A)                /* SPORT0 Half SPORT 'A' Multi-channel Control Register */
#define pREG_SPORT0_CS0_A                ((volatile uint32_t *)REG_SPORT0_CS0_A)                 /* SPORT0 Half SPORT 'A' Multi-channel 0-31 Select Register */
#define pREG_SPORT0_CS1_A                ((volatile uint32_t *)REG_SPORT0_CS1_A)                 /* SPORT0 Half SPORT 'A' Multi-channel 32-63 Select Register */
#define pREG_SPORT0_CS2_A                ((volatile uint32_t *)REG_SPORT0_CS2_A)                 /* SPORT0 Half SPORT 'A' Multi-channel 64-95 Select Register */
#define pREG_SPORT0_CS3_A                ((volatile uint32_t *)REG_SPORT0_CS3_A)                 /* SPORT0 Half SPORT 'A' Multi-channel 96-127 Select Register */
#define pREG_SPORT0_ERR_A                ((volatile uint32_t *)REG_SPORT0_ERR_A)                 /* SPORT0 Half SPORT 'A' Error Register */
#define pREG_SPORT0_MSTAT_A              ((volatile uint32_t *)REG_SPORT0_MSTAT_A)               /* SPORT0 Half SPORT 'A' Multi-channel Status Register */
#define pREG_SPORT0_CTL2_A               ((volatile uint32_t *)REG_SPORT0_CTL2_A)                /* SPORT0 Half SPORT 'A' Control 2 Register */
#define pREG_SPORT0_TXPRI_A              ((volatile uint32_t *)REG_SPORT0_TXPRI_A)               /* SPORT0 Half SPORT 'A' Tx Buffer (Primary) Register */
#define pREG_SPORT0_RXPRI_A              ((volatile uint32_t *)REG_SPORT0_RXPRI_A)               /* SPORT0 Half SPORT 'A' Rx Buffer (Primary) Register */
#define pREG_SPORT0_TXSEC_A              ((volatile uint32_t *)REG_SPORT0_TXSEC_A)               /* SPORT0 Half SPORT 'A' Tx Buffer (Secondary) Register */
#define pREG_SPORT0_RXSEC_A              ((volatile uint32_t *)REG_SPORT0_RXSEC_A)               /* SPORT0 Half SPORT 'A' Rx Buffer (Secondary) Register */
#define pREG_SPORT0_CTL_B                ((volatile uint32_t *)REG_SPORT0_CTL_B)                 /* SPORT0 Half SPORT 'B' Control Register */
#define pREG_SPORT0_DIV_B                ((volatile uint32_t *)REG_SPORT0_DIV_B)                 /* SPORT0 Half SPORT 'B' Divisor Register */
#define pREG_SPORT0_MCTL_B               ((volatile uint32_t *)REG_SPORT0_MCTL_B)                /* SPORT0 Half SPORT 'B' Multi-channel Control Register */
#define pREG_SPORT0_CS0_B                ((volatile uint32_t *)REG_SPORT0_CS0_B)                 /* SPORT0 Half SPORT 'B' Multi-channel 0-31 Select Register */
#define pREG_SPORT0_CS1_B                ((volatile uint32_t *)REG_SPORT0_CS1_B)                 /* SPORT0 Half SPORT 'B' Multi-channel 32-63 Select Register */
#define pREG_SPORT0_CS2_B                ((volatile uint32_t *)REG_SPORT0_CS2_B)                 /* SPORT0 Half SPORT 'B' Multichannel 64-95 Select Register */
#define pREG_SPORT0_CS3_B                ((volatile uint32_t *)REG_SPORT0_CS3_B)                 /* SPORT0 Half SPORT 'B' Multichannel 96-127 Select Register */
#define pREG_SPORT0_ERR_B                ((volatile uint32_t *)REG_SPORT0_ERR_B)                 /* SPORT0 Half SPORT 'B' Error Register */
#define pREG_SPORT0_MSTAT_B              ((volatile uint32_t *)REG_SPORT0_MSTAT_B)               /* SPORT0 Half SPORT 'B' Multi-channel Status Register */
#define pREG_SPORT0_CTL2_B               ((volatile uint32_t *)REG_SPORT0_CTL2_B)                /* SPORT0 Half SPORT 'B' Control 2 Register */
#define pREG_SPORT0_TXPRI_B              ((volatile uint32_t *)REG_SPORT0_TXPRI_B)               /* SPORT0 Half SPORT 'B' Tx Buffer (Primary) Register */
#define pREG_SPORT0_RXPRI_B              ((volatile uint32_t *)REG_SPORT0_RXPRI_B)               /* SPORT0 Half SPORT 'B' Rx Buffer (Primary) Register */
#define pREG_SPORT0_TXSEC_B              ((volatile uint32_t *)REG_SPORT0_TXSEC_B)               /* SPORT0 Half SPORT 'B' Tx Buffer (Secondary) Register */
#define pREG_SPORT0_RXSEC_B              ((volatile uint32_t *)REG_SPORT0_RXSEC_B)               /* SPORT0 Half SPORT 'B' Rx Buffer (Secondary) Register */

/* =========================================================================
       SPORT1
   ========================================================================= */
#define pREG_SPORT1_CTL_A                ((volatile uint32_t *)REG_SPORT1_CTL_A)                 /* SPORT1 Half SPORT 'A' Control Register */
#define pREG_SPORT1_DIV_A                ((volatile uint32_t *)REG_SPORT1_DIV_A)                 /* SPORT1 Half SPORT 'A' Divisor Register */
#define pREG_SPORT1_MCTL_A               ((volatile uint32_t *)REG_SPORT1_MCTL_A)                /* SPORT1 Half SPORT 'A' Multi-channel Control Register */
#define pREG_SPORT1_CS0_A                ((volatile uint32_t *)REG_SPORT1_CS0_A)                 /* SPORT1 Half SPORT 'A' Multi-channel 0-31 Select Register */
#define pREG_SPORT1_CS1_A                ((volatile uint32_t *)REG_SPORT1_CS1_A)                 /* SPORT1 Half SPORT 'A' Multi-channel 32-63 Select Register */
#define pREG_SPORT1_CS2_A                ((volatile uint32_t *)REG_SPORT1_CS2_A)                 /* SPORT1 Half SPORT 'A' Multi-channel 64-95 Select Register */
#define pREG_SPORT1_CS3_A                ((volatile uint32_t *)REG_SPORT1_CS3_A)                 /* SPORT1 Half SPORT 'A' Multi-channel 96-127 Select Register */
#define pREG_SPORT1_ERR_A                ((volatile uint32_t *)REG_SPORT1_ERR_A)                 /* SPORT1 Half SPORT 'A' Error Register */
#define pREG_SPORT1_MSTAT_A              ((volatile uint32_t *)REG_SPORT1_MSTAT_A)               /* SPORT1 Half SPORT 'A' Multi-channel Status Register */
#define pREG_SPORT1_CTL2_A               ((volatile uint32_t *)REG_SPORT1_CTL2_A)                /* SPORT1 Half SPORT 'A' Control 2 Register */
#define pREG_SPORT1_TXPRI_A              ((volatile uint32_t *)REG_SPORT1_TXPRI_A)               /* SPORT1 Half SPORT 'A' Tx Buffer (Primary) Register */
#define pREG_SPORT1_RXPRI_A              ((volatile uint32_t *)REG_SPORT1_RXPRI_A)               /* SPORT1 Half SPORT 'A' Rx Buffer (Primary) Register */
#define pREG_SPORT1_TXSEC_A              ((volatile uint32_t *)REG_SPORT1_TXSEC_A)               /* SPORT1 Half SPORT 'A' Tx Buffer (Secondary) Register */
#define pREG_SPORT1_RXSEC_A              ((volatile uint32_t *)REG_SPORT1_RXSEC_A)               /* SPORT1 Half SPORT 'A' Rx Buffer (Secondary) Register */
#define pREG_SPORT1_CTL_B                ((volatile uint32_t *)REG_SPORT1_CTL_B)                 /* SPORT1 Half SPORT 'B' Control Register */
#define pREG_SPORT1_DIV_B                ((volatile uint32_t *)REG_SPORT1_DIV_B)                 /* SPORT1 Half SPORT 'B' Divisor Register */
#define pREG_SPORT1_MCTL_B               ((volatile uint32_t *)REG_SPORT1_MCTL_B)                /* SPORT1 Half SPORT 'B' Multi-channel Control Register */
#define pREG_SPORT1_CS0_B                ((volatile uint32_t *)REG_SPORT1_CS0_B)                 /* SPORT1 Half SPORT 'B' Multi-channel 0-31 Select Register */
#define pREG_SPORT1_CS1_B                ((volatile uint32_t *)REG_SPORT1_CS1_B)                 /* SPORT1 Half SPORT 'B' Multi-channel 32-63 Select Register */
#define pREG_SPORT1_CS2_B                ((volatile uint32_t *)REG_SPORT1_CS2_B)                 /* SPORT1 Half SPORT 'B' Multichannel 64-95 Select Register */
#define pREG_SPORT1_CS3_B                ((volatile uint32_t *)REG_SPORT1_CS3_B)                 /* SPORT1 Half SPORT 'B' Multichannel 96-127 Select Register */
#define pREG_SPORT1_ERR_B                ((volatile uint32_t *)REG_SPORT1_ERR_B)                 /* SPORT1 Half SPORT 'B' Error Register */
#define pREG_SPORT1_MSTAT_B              ((volatile uint32_t *)REG_SPORT1_MSTAT_B)               /* SPORT1 Half SPORT 'B' Multi-channel Status Register */
#define pREG_SPORT1_CTL2_B               ((volatile uint32_t *)REG_SPORT1_CTL2_B)                /* SPORT1 Half SPORT 'B' Control 2 Register */
#define pREG_SPORT1_TXPRI_B              ((volatile uint32_t *)REG_SPORT1_TXPRI_B)               /* SPORT1 Half SPORT 'B' Tx Buffer (Primary) Register */
#define pREG_SPORT1_RXPRI_B              ((volatile uint32_t *)REG_SPORT1_RXPRI_B)               /* SPORT1 Half SPORT 'B' Rx Buffer (Primary) Register */
#define pREG_SPORT1_TXSEC_B              ((volatile uint32_t *)REG_SPORT1_TXSEC_B)               /* SPORT1 Half SPORT 'B' Tx Buffer (Secondary) Register */
#define pREG_SPORT1_RXSEC_B              ((volatile uint32_t *)REG_SPORT1_RXSEC_B)               /* SPORT1 Half SPORT 'B' Rx Buffer (Secondary) Register */


/* =========================================================================
       SPI0
   ========================================================================= */
#define pREG_SPI0_CTL                    ((volatile uint32_t *)REG_SPI0_CTL)                     /* SPI0 Control Register */
#define pREG_SPI0_RXCTL                  ((volatile uint32_t *)REG_SPI0_RXCTL)                   /* SPI0 Receive Control Register */
#define pREG_SPI0_TXCTL                  ((volatile uint32_t *)REG_SPI0_TXCTL)                   /* SPI0 Transmit Control Register */
#define pREG_SPI0_CLK                    ((volatile uint32_t *)REG_SPI0_CLK)                     /* SPI0 Clock Rate Register */
#define pREG_SPI0_DLY                    ((volatile uint32_t *)REG_SPI0_DLY)                     /* SPI0 Delay Register */
#define pREG_SPI0_SLVSEL                 ((volatile uint32_t *)REG_SPI0_SLVSEL)                  /* SPI0 Slave Select Register */
#define pREG_SPI0_RWC                    ((volatile uint32_t *)REG_SPI0_RWC)                     /* SPI0 Received Word Count Register */
#define pREG_SPI0_RWCR                   ((volatile uint32_t *)REG_SPI0_RWCR)                    /* SPI0 Received Word Count Reload Register */
#define pREG_SPI0_TWC                    ((volatile uint32_t *)REG_SPI0_TWC)                     /* SPI0 Transmitted Word Count Register */
#define pREG_SPI0_TWCR                   ((volatile uint32_t *)REG_SPI0_TWCR)                    /* SPI0 Transmitted Word Count Reload Register */
#define pREG_SPI0_IMSK                   ((volatile uint32_t *)REG_SPI0_IMSK)                    /* SPI0 Interrupt Mask Register */
#define pREG_SPI0_IMSK_CLR               ((volatile uint32_t *)REG_SPI0_IMSK_CLR)                /* SPI0 Interrupt Mask Clear Register */
#define pREG_SPI0_IMSK_SET               ((volatile uint32_t *)REG_SPI0_IMSK_SET)                /* SPI0 Interrupt Mask Set Register */
#define pREG_SPI0_STAT                   ((volatile uint32_t *)REG_SPI0_STAT)                    /* SPI0 Status Register */
#define pREG_SPI0_ILAT                   ((volatile uint32_t *)REG_SPI0_ILAT)                    /* SPI0 Masked Interrupt Condition Register */
#define pREG_SPI0_ILAT_CLR               ((volatile uint32_t *)REG_SPI0_ILAT_CLR)                /* SPI0 Masked Interrupt Clear Register */
#define pREG_SPI0_RFIFO                  ((volatile uint32_t *)REG_SPI0_RFIFO)                   /* SPI0 Receive FIFO Data Register */
#define pREG_SPI0_TFIFO                  ((volatile uint32_t *)REG_SPI0_TFIFO)                   /* SPI0 Transmit FIFO Data Register */
#define pREG_SPI0_MMRDH                  ((volatile uint32_t *)REG_SPI0_MMRDH)                   /* SPI0 Memory Mapped Read Header */
#define pREG_SPI0_MMTOP                  ((volatile uint32_t *)REG_SPI0_MMTOP)                   /* SPI0 SPI Memory Top Address */

/* =========================================================================
       SPI1
   ========================================================================= */
#define pREG_SPI1_CTL                    ((volatile uint32_t *)REG_SPI1_CTL)                     /* SPI1 Control Register */
#define pREG_SPI1_RXCTL                  ((volatile uint32_t *)REG_SPI1_RXCTL)                   /* SPI1 Receive Control Register */
#define pREG_SPI1_TXCTL                  ((volatile uint32_t *)REG_SPI1_TXCTL)                   /* SPI1 Transmit Control Register */
#define pREG_SPI1_CLK                    ((volatile uint32_t *)REG_SPI1_CLK)                     /* SPI1 Clock Rate Register */
#define pREG_SPI1_DLY                    ((volatile uint32_t *)REG_SPI1_DLY)                     /* SPI1 Delay Register */
#define pREG_SPI1_SLVSEL                 ((volatile uint32_t *)REG_SPI1_SLVSEL)                  /* SPI1 Slave Select Register */
#define pREG_SPI1_RWC                    ((volatile uint32_t *)REG_SPI1_RWC)                     /* SPI1 Received Word Count Register */
#define pREG_SPI1_RWCR                   ((volatile uint32_t *)REG_SPI1_RWCR)                    /* SPI1 Received Word Count Reload Register */
#define pREG_SPI1_TWC                    ((volatile uint32_t *)REG_SPI1_TWC)                     /* SPI1 Transmitted Word Count Register */
#define pREG_SPI1_TWCR                   ((volatile uint32_t *)REG_SPI1_TWCR)                    /* SPI1 Transmitted Word Count Reload Register */
#define pREG_SPI1_IMSK                   ((volatile uint32_t *)REG_SPI1_IMSK)                    /* SPI1 Interrupt Mask Register */
#define pREG_SPI1_IMSK_CLR               ((volatile uint32_t *)REG_SPI1_IMSK_CLR)                /* SPI1 Interrupt Mask Clear Register */
#define pREG_SPI1_IMSK_SET               ((volatile uint32_t *)REG_SPI1_IMSK_SET)                /* SPI1 Interrupt Mask Set Register */
#define pREG_SPI1_STAT                   ((volatile uint32_t *)REG_SPI1_STAT)                    /* SPI1 Status Register */
#define pREG_SPI1_ILAT                   ((volatile uint32_t *)REG_SPI1_ILAT)                    /* SPI1 Masked Interrupt Condition Register */
#define pREG_SPI1_ILAT_CLR               ((volatile uint32_t *)REG_SPI1_ILAT_CLR)                /* SPI1 Masked Interrupt Clear Register */
#define pREG_SPI1_RFIFO                  ((volatile uint32_t *)REG_SPI1_RFIFO)                   /* SPI1 Receive FIFO Data Register */
#define pREG_SPI1_TFIFO                  ((volatile uint32_t *)REG_SPI1_TFIFO)                   /* SPI1 Transmit FIFO Data Register */
#define pREG_SPI1_MMRDH                  ((volatile uint32_t *)REG_SPI1_MMRDH)                   /* SPI1 Memory Mapped Read Header */
#define pREG_SPI1_MMTOP                  ((volatile uint32_t *)REG_SPI1_MMTOP)                   /* SPI1 SPI Memory Top Address */

/* =========================================================================
       SPI2
   ========================================================================= */
#define pREG_SPI2_CTL                    ((volatile uint32_t *)REG_SPI2_CTL)                     /* SPI2 Control Register */
#define pREG_SPI2_RXCTL                  ((volatile uint32_t *)REG_SPI2_RXCTL)                   /* SPI2 Receive Control Register */
#define pREG_SPI2_TXCTL                  ((volatile uint32_t *)REG_SPI2_TXCTL)                   /* SPI2 Transmit Control Register */
#define pREG_SPI2_CLK                    ((volatile uint32_t *)REG_SPI2_CLK)                     /* SPI2 Clock Rate Register */
#define pREG_SPI2_DLY                    ((volatile uint32_t *)REG_SPI2_DLY)                     /* SPI2 Delay Register */
#define pREG_SPI2_SLVSEL                 ((volatile uint32_t *)REG_SPI2_SLVSEL)                  /* SPI2 Slave Select Register */
#define pREG_SPI2_RWC                    ((volatile uint32_t *)REG_SPI2_RWC)                     /* SPI2 Received Word Count Register */
#define pREG_SPI2_RWCR                   ((volatile uint32_t *)REG_SPI2_RWCR)                    /* SPI2 Received Word Count Reload Register */
#define pREG_SPI2_TWC                    ((volatile uint32_t *)REG_SPI2_TWC)                     /* SPI2 Transmitted Word Count Register */
#define pREG_SPI2_TWCR                   ((volatile uint32_t *)REG_SPI2_TWCR)                    /* SPI2 Transmitted Word Count Reload Register */
#define pREG_SPI2_IMSK                   ((volatile uint32_t *)REG_SPI2_IMSK)                    /* SPI2 Interrupt Mask Register */
#define pREG_SPI2_IMSK_CLR               ((volatile uint32_t *)REG_SPI2_IMSK_CLR)                /* SPI2 Interrupt Mask Clear Register */
#define pREG_SPI2_IMSK_SET               ((volatile uint32_t *)REG_SPI2_IMSK_SET)                /* SPI2 Interrupt Mask Set Register */
#define pREG_SPI2_STAT                   ((volatile uint32_t *)REG_SPI2_STAT)                    /* SPI2 Status Register */
#define pREG_SPI2_ILAT                   ((volatile uint32_t *)REG_SPI2_ILAT)                    /* SPI2 Masked Interrupt Condition Register */
#define pREG_SPI2_ILAT_CLR               ((volatile uint32_t *)REG_SPI2_ILAT_CLR)                /* SPI2 Masked Interrupt Clear Register */
#define pREG_SPI2_RFIFO                  ((volatile uint32_t *)REG_SPI2_RFIFO)                   /* SPI2 Receive FIFO Data Register */
#define pREG_SPI2_TFIFO                  ((volatile uint32_t *)REG_SPI2_TFIFO)                   /* SPI2 Transmit FIFO Data Register */
#define pREG_SPI2_MMRDH                  ((volatile uint32_t *)REG_SPI2_MMRDH)                   /* SPI2 Memory Mapped Read Header */
#define pREG_SPI2_MMTOP                  ((volatile uint32_t *)REG_SPI2_MMTOP)                   /* SPI2 SPI Memory Top Address */


/* =========================================================================
       SPIHP0
   ========================================================================= */
#define pREG_SPIHP0_CTL                  ((volatile uint32_t *)REG_SPIHP0_CTL)                   /* SPIHP0 Control Register */
#define pREG_SPIHP0_STAT                 ((volatile uint32_t *)REG_SPIHP0_STAT)                  /* SPIHP0 Status Register */
#define pREG_SPIHP0_RDPF                 ((volatile uint32_t *)REG_SPIHP0_RDPF)                  /* SPIHP0 Read Prefetch Register */
#define pREG_SPIHP0_BAR0                 ((volatile uint32_t *)REG_SPIHP0_BAR0)                  /* SPIHP0 Base Address Register */
#define pREG_SPIHP0_BAR1                 ((volatile uint32_t *)REG_SPIHP0_BAR1)                  /* SPIHP0 Base Address Register */
#define pREG_SPIHP0_BAR2                 ((volatile uint32_t *)REG_SPIHP0_BAR2)                  /* SPIHP0 Base Address Register */
#define pREG_SPIHP0_BAR3                 ((volatile uint32_t *)REG_SPIHP0_BAR3)                  /* SPIHP0 Base Address Register */
#define pREG_SPIHP0_BAR4                 ((volatile uint32_t *)REG_SPIHP0_BAR4)                  /* SPIHP0 Base Address Register */
#define pREG_SPIHP0_BAR5                 ((volatile uint32_t *)REG_SPIHP0_BAR5)                  /* SPIHP0 Base Address Register */
#define pREG_SPIHP0_BAR6                 ((volatile uint32_t *)REG_SPIHP0_BAR6)                  /* SPIHP0 Base Address Register */
#define pREG_SPIHP0_BAR7                 ((volatile uint32_t *)REG_SPIHP0_BAR7)                  /* SPIHP0 Base Address Register */
#define pREG_SPIHP0_BAR8                 ((volatile uint32_t *)REG_SPIHP0_BAR8)                  /* SPIHP0 Base Address Register */
#define pREG_SPIHP0_BAR9                 ((volatile uint32_t *)REG_SPIHP0_BAR9)                  /* SPIHP0 Base Address Register */
#define pREG_SPIHP0_BAR10                ((volatile uint32_t *)REG_SPIHP0_BAR10)                 /* SPIHP0 Base Address Register */
#define pREG_SPIHP0_BAR11                ((volatile uint32_t *)REG_SPIHP0_BAR11)                 /* SPIHP0 Base Address Register */
#define pREG_SPIHP0_BAR12                ((volatile uint32_t *)REG_SPIHP0_BAR12)                 /* SPIHP0 Base Address Register */
#define pREG_SPIHP0_BAR13                ((volatile uint32_t *)REG_SPIHP0_BAR13)                 /* SPIHP0 Base Address Register */
#define pREG_SPIHP0_BAR14                ((volatile uint32_t *)REG_SPIHP0_BAR14)                 /* SPIHP0 Base Address Register */
#define pREG_SPIHP0_BAR15                ((volatile uint32_t *)REG_SPIHP0_BAR15)                 /* SPIHP0 Base Address Register */
#define pREG_SPIHP0_AUX0                 ((volatile uint32_t *)REG_SPIHP0_AUX0)                  /* SPIHP0 Auxiliary Register */
#define pREG_SPIHP0_AUX1                 ((volatile uint32_t *)REG_SPIHP0_AUX1)                  /* SPIHP0 Auxiliary Register */
#define pREG_SPIHP0_AUX2                 ((volatile uint32_t *)REG_SPIHP0_AUX2)                  /* SPIHP0 Auxiliary Register */
#define pREG_SPIHP0_AUX3                 ((volatile uint32_t *)REG_SPIHP0_AUX3)                  /* SPIHP0 Auxiliary Register */


/* =========================================================================
       SMC0
   ========================================================================= */
#define pREG_SMC0_B0CTL                  ((volatile uint32_t *)REG_SMC0_B0CTL)                   /* SMC0 Bank 0 Control Register */
#define pREG_SMC0_B0TIM                  ((volatile uint32_t *)REG_SMC0_B0TIM)                   /* SMC0 Bank 0 Timing Register */
#define pREG_SMC0_B0ETIM                 ((volatile uint32_t *)REG_SMC0_B0ETIM)                  /* SMC0 Bank 0 Extended Timing Register */
#define pREG_SMC0_B1CTL                  ((volatile uint32_t *)REG_SMC0_B1CTL)                   /* SMC0 Bank 1 Control Register */
#define pREG_SMC0_B1TIM                  ((volatile uint32_t *)REG_SMC0_B1TIM)                   /* SMC0 Bank 1 Timing Register */
#define pREG_SMC0_B1ETIM                 ((volatile uint32_t *)REG_SMC0_B1ETIM)                  /* SMC0 Bank 1 Extended Timing Register */
#define pREG_SMC0_B2CTL                  ((volatile uint32_t *)REG_SMC0_B2CTL)                   /* SMC0 Bank 2 Control Register */
#define pREG_SMC0_B2TIM                  ((volatile uint32_t *)REG_SMC0_B2TIM)                   /* SMC0 Bank 2 Timing Register */
#define pREG_SMC0_B2ETIM                 ((volatile uint32_t *)REG_SMC0_B2ETIM)                  /* SMC0 Bank 2 Extended Timing Register */
#define pREG_SMC0_B3CTL                  ((volatile uint32_t *)REG_SMC0_B3CTL)                   /* SMC0 Bank 3 Control Register */
#define pREG_SMC0_B3TIM                  ((volatile uint32_t *)REG_SMC0_B3TIM)                   /* SMC0 Bank 3 Timing Register */
#define pREG_SMC0_B3ETIM                 ((volatile uint32_t *)REG_SMC0_B3ETIM)                  /* SMC0 Bank 3 Extended Timing Register */


/* =========================================================================
       UART0
   ========================================================================= */
#define pREG_UART0_CTL                   ((volatile uint32_t *)REG_UART0_CTL)                    /* UART0 Control Register */
#define pREG_UART0_STAT                  ((volatile uint32_t *)REG_UART0_STAT)                   /* UART0 Status Register */
#define pREG_UART0_SCR                   ((volatile uint32_t *)REG_UART0_SCR)                    /* UART0 Scratch Register */
#define pREG_UART0_CLK                   ((volatile uint32_t *)REG_UART0_CLK)                    /* UART0 Clock Rate Register */
#define pREG_UART0_IMSK                  ((volatile uint32_t *)REG_UART0_IMSK)                   /* UART0 Interrupt Mask Register */
#define pREG_UART0_IMSK_SET              ((volatile uint32_t *)REG_UART0_IMSK_SET)               /* UART0 Interrupt Mask Set Register */
#define pREG_UART0_IMSK_CLR              ((volatile uint32_t *)REG_UART0_IMSK_CLR)               /* UART0 Interrupt Mask Clear Register */
#define pREG_UART0_RBR                   ((volatile uint32_t *)REG_UART0_RBR)                    /* UART0 Receive Buffer Register */
#define pREG_UART0_THR                   ((volatile uint32_t *)REG_UART0_THR)                    /* UART0 Transmit Hold Register */
#define pREG_UART0_TAIP                  ((volatile uint32_t *)REG_UART0_TAIP)                   /* UART0 Transmit Address/Insert Pulse Register */
#define pREG_UART0_TSR                   ((volatile uint32_t *)REG_UART0_TSR)                    /* UART0 Transmit Shift Register */
#define pREG_UART0_RSR                   ((volatile uint32_t *)REG_UART0_RSR)                    /* UART0 Receive Shift Register */
#define pREG_UART0_TXCNT                 ((volatile uint32_t *)REG_UART0_TXCNT)                  /* UART0 Transmit Counter Register */
#define pREG_UART0_RXCNT                 ((volatile uint32_t *)REG_UART0_RXCNT)                  /* UART0 Receive Counter Register */

/* =========================================================================
       UART1
   ========================================================================= */
#define pREG_UART1_CTL                   ((volatile uint32_t *)REG_UART1_CTL)                    /* UART1 Control Register */
#define pREG_UART1_STAT                  ((volatile uint32_t *)REG_UART1_STAT)                   /* UART1 Status Register */
#define pREG_UART1_SCR                   ((volatile uint32_t *)REG_UART1_SCR)                    /* UART1 Scratch Register */
#define pREG_UART1_CLK                   ((volatile uint32_t *)REG_UART1_CLK)                    /* UART1 Clock Rate Register */
#define pREG_UART1_IMSK                  ((volatile uint32_t *)REG_UART1_IMSK)                   /* UART1 Interrupt Mask Register */
#define pREG_UART1_IMSK_SET              ((volatile uint32_t *)REG_UART1_IMSK_SET)               /* UART1 Interrupt Mask Set Register */
#define pREG_UART1_IMSK_CLR              ((volatile uint32_t *)REG_UART1_IMSK_CLR)               /* UART1 Interrupt Mask Clear Register */
#define pREG_UART1_RBR                   ((volatile uint32_t *)REG_UART1_RBR)                    /* UART1 Receive Buffer Register */
#define pREG_UART1_THR                   ((volatile uint32_t *)REG_UART1_THR)                    /* UART1 Transmit Hold Register */
#define pREG_UART1_TAIP                  ((volatile uint32_t *)REG_UART1_TAIP)                   /* UART1 Transmit Address/Insert Pulse Register */
#define pREG_UART1_TSR                   ((volatile uint32_t *)REG_UART1_TSR)                    /* UART1 Transmit Shift Register */
#define pREG_UART1_RSR                   ((volatile uint32_t *)REG_UART1_RSR)                    /* UART1 Receive Shift Register */
#define pREG_UART1_TXCNT                 ((volatile uint32_t *)REG_UART1_TXCNT)                  /* UART1 Transmit Counter Register */
#define pREG_UART1_RXCNT                 ((volatile uint32_t *)REG_UART1_RXCNT)                  /* UART1 Receive Counter Register */


/* =========================================================================
       EPPI0
   ========================================================================= */
#define pREG_EPPI0_STAT                  ((volatile uint32_t *)REG_EPPI0_STAT)                   /* EPPI0 Status Register */
#define pREG_EPPI0_HCNT                  ((volatile uint32_t *)REG_EPPI0_HCNT)                   /* EPPI0 Horizontal Transfer Count Register */
#define pREG_EPPI0_HDLY                  ((volatile uint32_t *)REG_EPPI0_HDLY)                   /* EPPI0 Horizontal Delay Count Register */
#define pREG_EPPI0_VCNT                  ((volatile uint32_t *)REG_EPPI0_VCNT)                   /* EPPI0 Vertical Transfer Count Register */
#define pREG_EPPI0_VDLY                  ((volatile uint32_t *)REG_EPPI0_VDLY)                   /* EPPI0 Vertical Delay Count Register */
#define pREG_EPPI0_FRAME                 ((volatile uint32_t *)REG_EPPI0_FRAME)                  /* EPPI0 Lines Per Frame Register */
#define pREG_EPPI0_LINE                  ((volatile uint32_t *)REG_EPPI0_LINE)                   /* EPPI0 Samples Per Line Register */
#define pREG_EPPI0_CLKDIV                ((volatile uint32_t *)REG_EPPI0_CLKDIV)                 /* EPPI0 Clock Divide Register */
#define pREG_EPPI0_CTL                   ((volatile uint32_t *)REG_EPPI0_CTL)                    /* EPPI0 Control Register */
#define pREG_EPPI0_FS1_WLHB              ((volatile uint32_t *)REG_EPPI0_FS1_WLHB)               /* EPPI0 FS1 Width Register / EPPI Horizontal Blanking Samples Per Line Register */
#define pREG_EPPI0_FS1_PASPL             ((volatile uint32_t *)REG_EPPI0_FS1_PASPL)              /* EPPI0 FS1 Period Register / EPPI Active Samples Per Line Register */
#define pREG_EPPI0_FS2_WLVB              ((volatile uint32_t *)REG_EPPI0_FS2_WLVB)               /* EPPI0 FS2 Width Register / EPPI Lines Of Vertical Blanking Register */
#define pREG_EPPI0_FS2_PALPF             ((volatile uint32_t *)REG_EPPI0_FS2_PALPF)              /* EPPI0 FS2 Period Register / EPPI Active Lines Per Field Register */
#define pREG_EPPI0_IMSK                  ((volatile uint32_t *)REG_EPPI0_IMSK)                   /* EPPI0 Interrupt Mask Register */
#define pREG_EPPI0_ODDCLIP               ((volatile uint32_t *)REG_EPPI0_ODDCLIP)                /* EPPI0 Clipping Register for ODD (Chroma) Data */
#define pREG_EPPI0_EVENCLIP              ((volatile uint32_t *)REG_EPPI0_EVENCLIP)               /* EPPI0 Clipping Register for EVEN (Luma) Data */
#define pREG_EPPI0_FS1_DLY               ((volatile uint32_t *)REG_EPPI0_FS1_DLY)                /* EPPI0 Frame Sync 1 Delay Value */
#define pREG_EPPI0_FS2_DLY               ((volatile uint32_t *)REG_EPPI0_FS2_DLY)                /* EPPI0 Frame Sync 2 Delay Value */
#define pREG_EPPI0_CTL2                  ((volatile uint32_t *)REG_EPPI0_CTL2)                   /* EPPI0 Control Register 2 */


/* =========================================================================
       CAN0
   ========================================================================= */
#define pREG_CAN0_MC1                    ((volatile uint32_t *)REG_CAN0_MC1)                     /* CAN0 Mailbox Configuration 1 Register */
#define pREG_CAN0_MD1                    ((volatile uint32_t *)REG_CAN0_MD1)                     /* CAN0 Mailbox Direction 1 Register */
#define pREG_CAN0_TRS1                   ((volatile uint32_t *)REG_CAN0_TRS1)                    /* CAN0 Transmission Request Set 1 Register */
#define pREG_CAN0_TRR1                   ((volatile uint32_t *)REG_CAN0_TRR1)                    /* CAN0 Transmission Request Reset 1 Register */
#define pREG_CAN0_TA1                    ((volatile uint32_t *)REG_CAN0_TA1)                     /* CAN0 Transmission Acknowledge 1 Register */
#define pREG_CAN0_AA1                    ((volatile uint32_t *)REG_CAN0_AA1)                     /* CAN0 Abort Acknowledge 1 Register */
#define pREG_CAN0_RMP1                   ((volatile uint32_t *)REG_CAN0_RMP1)                    /* CAN0 Receive Message Pending 1 Register */
#define pREG_CAN0_RML1                   ((volatile uint32_t *)REG_CAN0_RML1)                    /* CAN0 Receive Message Lost 1 Register */
#define pREG_CAN0_MBTIF1                 ((volatile uint32_t *)REG_CAN0_MBTIF1)                  /* CAN0 Mailbox Transmit Interrupt Flag 1 Register */
#define pREG_CAN0_MBRIF1                 ((volatile uint32_t *)REG_CAN0_MBRIF1)                  /* CAN0 Mailbox Receive Interrupt Flag 1 Register */
#define pREG_CAN0_MBIM1                  ((volatile uint32_t *)REG_CAN0_MBIM1)                   /* CAN0 Mailbox Interrupt Mask 1 Register */
#define pREG_CAN0_RFH1                   ((volatile uint32_t *)REG_CAN0_RFH1)                    /* CAN0 Remote Frame Handling 1 Register */
#define pREG_CAN0_OPSS1                  ((volatile uint32_t *)REG_CAN0_OPSS1)                   /* CAN0 Overwrite Protection/Single Shot Transmission 1 Register */
#define pREG_CAN0_MC2                    ((volatile uint32_t *)REG_CAN0_MC2)                     /* CAN0 Mailbox Configuration 2 Register */
#define pREG_CAN0_MD2                    ((volatile uint32_t *)REG_CAN0_MD2)                     /* CAN0 Mailbox Direction 2 Register */
#define pREG_CAN0_TRS2                   ((volatile uint32_t *)REG_CAN0_TRS2)                    /* CAN0 Transmission Request Set 2 Register */
#define pREG_CAN0_TRR2                   ((volatile uint32_t *)REG_CAN0_TRR2)                    /* CAN0 Transmission Request Reset 2 Register */
#define pREG_CAN0_TA2                    ((volatile uint32_t *)REG_CAN0_TA2)                     /* CAN0 Transmission Acknowledge 2 Register */
#define pREG_CAN0_AA2                    ((volatile uint32_t *)REG_CAN0_AA2)                     /* CAN0 Abort Acknowledge 2 Register */
#define pREG_CAN0_RMP2                   ((volatile uint32_t *)REG_CAN0_RMP2)                    /* CAN0 Receive Message Pending 2 Register */
#define pREG_CAN0_RML2                   ((volatile uint32_t *)REG_CAN0_RML2)                    /* CAN0 Receive Message Lost 2 Register */
#define pREG_CAN0_MBTIF2                 ((volatile uint32_t *)REG_CAN0_MBTIF2)                  /* CAN0 Mailbox Transmit Interrupt Flag 2 Register */
#define pREG_CAN0_MBRIF2                 ((volatile uint32_t *)REG_CAN0_MBRIF2)                  /* CAN0 Mailbox Receive Interrupt Flag 2 Register */
#define pREG_CAN0_MBIM2                  ((volatile uint32_t *)REG_CAN0_MBIM2)                   /* CAN0 Mailbox Interrupt Mask 2 Register */
#define pREG_CAN0_RFH2                   ((volatile uint32_t *)REG_CAN0_RFH2)                    /* CAN0 Remote Frame Handling 2 Register */
#define pREG_CAN0_OPSS2                  ((volatile uint32_t *)REG_CAN0_OPSS2)                   /* CAN0 Overwrite Protection/Single Shot Transmission 2 Register */
#define pREG_CAN0_CLK                    ((volatile uint32_t *)REG_CAN0_CLK)                     /* CAN0 Clock Register */
#define pREG_CAN0_TIMING                 ((volatile uint32_t *)REG_CAN0_TIMING)                  /* CAN0 Timing Register */
#define pREG_CAN0_DBG                    ((volatile uint32_t *)REG_CAN0_DBG)                     /* CAN0 Debug Register */
#define pREG_CAN0_STAT                   ((volatile uint32_t *)REG_CAN0_STAT)                    /* CAN0 Status Register */
#define pREG_CAN0_CEC                    ((volatile uint32_t *)REG_CAN0_CEC)                     /* CAN0 Error Counter Register */
#define pREG_CAN0_GIS                    ((volatile uint32_t *)REG_CAN0_GIS)                     /* CAN0 Global CAN Interrupt Status Register */
#define pREG_CAN0_GIM                    ((volatile uint32_t *)REG_CAN0_GIM)                     /* CAN0 Global CAN Interrupt Mask Register */
#define pREG_CAN0_GIF                    ((volatile uint32_t *)REG_CAN0_GIF)                     /* CAN0 Global CAN Interrupt Flag Register */
#define pREG_CAN0_CTL                    ((volatile uint32_t *)REG_CAN0_CTL)                     /* CAN0 CAN Master Control Register */
#define pREG_CAN0_INT                    ((volatile uint32_t *)REG_CAN0_INT)                     /* CAN0 Interrupt Pending Register */
#define pREG_CAN0_MBTD                   ((volatile uint32_t *)REG_CAN0_MBTD)                    /* CAN0 Temporary Mailbox Disable Register */
#define pREG_CAN0_EWR                    ((volatile uint32_t *)REG_CAN0_EWR)                     /* CAN0 Error Counter Warning Level Register */
#define pREG_CAN0_ESR                    ((volatile uint32_t *)REG_CAN0_ESR)                     /* CAN0 Error Status Register */
#define pREG_CAN0_UCCNT                  ((volatile uint32_t *)REG_CAN0_UCCNT)                   /* CAN0 Universal Counter Register */
#define pREG_CAN0_UCRC                   ((volatile uint32_t *)REG_CAN0_UCRC)                    /* CAN0 Universal Counter Reload/Capture Register */
#define pREG_CAN0_UCCNF                  ((volatile uint32_t *)REG_CAN0_UCCNF)                   /* CAN0 Universal Counter Configuration Mode Register */
#define pREG_CAN0_AM00L                  ((volatile uint32_t *)REG_CAN0_AM00L)                   /* CAN0 Acceptance Mask (L) Register */
#define pREG_CAN0_AM01L                  ((volatile uint32_t *)REG_CAN0_AM01L)                   /* CAN0 Acceptance Mask (L) Register */
#define pREG_CAN0_AM02L                  ((volatile uint32_t *)REG_CAN0_AM02L)                   /* CAN0 Acceptance Mask (L) Register */
#define pREG_CAN0_AM03L                  ((volatile uint32_t *)REG_CAN0_AM03L)                   /* CAN0 Acceptance Mask (L) Register */
#define pREG_CAN0_AM04L                  ((volatile uint32_t *)REG_CAN0_AM04L)                   /* CAN0 Acceptance Mask (L) Register */
#define pREG_CAN0_AM05L                  ((volatile uint32_t *)REG_CAN0_AM05L)                   /* CAN0 Acceptance Mask (L) Register */
#define pREG_CAN0_AM06L                  ((volatile uint32_t *)REG_CAN0_AM06L)                   /* CAN0 Acceptance Mask (L) Register */
#define pREG_CAN0_AM07L                  ((volatile uint32_t *)REG_CAN0_AM07L)                   /* CAN0 Acceptance Mask (L) Register */
#define pREG_CAN0_AM08L                  ((volatile uint32_t *)REG_CAN0_AM08L)                   /* CAN0 Acceptance Mask (L) Register */
#define pREG_CAN0_AM09L                  ((volatile uint32_t *)REG_CAN0_AM09L)                   /* CAN0 Acceptance Mask (L) Register */
#define pREG_CAN0_AM10L                  ((volatile uint32_t *)REG_CAN0_AM10L)                   /* CAN0 Acceptance Mask (L) Register */
#define pREG_CAN0_AM11L                  ((volatile uint32_t *)REG_CAN0_AM11L)                   /* CAN0 Acceptance Mask (L) Register */
#define pREG_CAN0_AM12L                  ((volatile uint32_t *)REG_CAN0_AM12L)                   /* CAN0 Acceptance Mask (L) Register */
#define pREG_CAN0_AM13L                  ((volatile uint32_t *)REG_CAN0_AM13L)                   /* CAN0 Acceptance Mask (L) Register */
#define pREG_CAN0_AM14L                  ((volatile uint32_t *)REG_CAN0_AM14L)                   /* CAN0 Acceptance Mask (L) Register */
#define pREG_CAN0_AM15L                  ((volatile uint32_t *)REG_CAN0_AM15L)                   /* CAN0 Acceptance Mask (L) Register */
#define pREG_CAN0_AM16L                  ((volatile uint32_t *)REG_CAN0_AM16L)                   /* CAN0 Acceptance Mask (L) Register */
#define pREG_CAN0_AM17L                  ((volatile uint32_t *)REG_CAN0_AM17L)                   /* CAN0 Acceptance Mask (L) Register */
#define pREG_CAN0_AM18L                  ((volatile uint32_t *)REG_CAN0_AM18L)                   /* CAN0 Acceptance Mask (L) Register */
#define pREG_CAN0_AM19L                  ((volatile uint32_t *)REG_CAN0_AM19L)                   /* CAN0 Acceptance Mask (L) Register */
#define pREG_CAN0_AM20L                  ((volatile uint32_t *)REG_CAN0_AM20L)                   /* CAN0 Acceptance Mask (L) Register */
#define pREG_CAN0_AM21L                  ((volatile uint32_t *)REG_CAN0_AM21L)                   /* CAN0 Acceptance Mask (L) Register */
#define pREG_CAN0_AM22L                  ((volatile uint32_t *)REG_CAN0_AM22L)                   /* CAN0 Acceptance Mask (L) Register */
#define pREG_CAN0_AM23L                  ((volatile uint32_t *)REG_CAN0_AM23L)                   /* CAN0 Acceptance Mask (L) Register */
#define pREG_CAN0_AM24L                  ((volatile uint32_t *)REG_CAN0_AM24L)                   /* CAN0 Acceptance Mask (L) Register */
#define pREG_CAN0_AM25L                  ((volatile uint32_t *)REG_CAN0_AM25L)                   /* CAN0 Acceptance Mask (L) Register */
#define pREG_CAN0_AM26L                  ((volatile uint32_t *)REG_CAN0_AM26L)                   /* CAN0 Acceptance Mask (L) Register */
#define pREG_CAN0_AM27L                  ((volatile uint32_t *)REG_CAN0_AM27L)                   /* CAN0 Acceptance Mask (L) Register */
#define pREG_CAN0_AM28L                  ((volatile uint32_t *)REG_CAN0_AM28L)                   /* CAN0 Acceptance Mask (L) Register */
#define pREG_CAN0_AM29L                  ((volatile uint32_t *)REG_CAN0_AM29L)                   /* CAN0 Acceptance Mask (L) Register */
#define pREG_CAN0_AM30L                  ((volatile uint32_t *)REG_CAN0_AM30L)                   /* CAN0 Acceptance Mask (L) Register */
#define pREG_CAN0_AM31L                  ((volatile uint32_t *)REG_CAN0_AM31L)                   /* CAN0 Acceptance Mask (L) Register */
#define pREG_CAN0_AM00H                  ((volatile uint32_t *)REG_CAN0_AM00H)                   /* CAN0 Acceptance Mask (H) Register */
#define pREG_CAN0_AM01H                  ((volatile uint32_t *)REG_CAN0_AM01H)                   /* CAN0 Acceptance Mask (H) Register */
#define pREG_CAN0_AM02H                  ((volatile uint32_t *)REG_CAN0_AM02H)                   /* CAN0 Acceptance Mask (H) Register */
#define pREG_CAN0_AM03H                  ((volatile uint32_t *)REG_CAN0_AM03H)                   /* CAN0 Acceptance Mask (H) Register */
#define pREG_CAN0_AM04H                  ((volatile uint32_t *)REG_CAN0_AM04H)                   /* CAN0 Acceptance Mask (H) Register */
#define pREG_CAN0_AM05H                  ((volatile uint32_t *)REG_CAN0_AM05H)                   /* CAN0 Acceptance Mask (H) Register */
#define pREG_CAN0_AM06H                  ((volatile uint32_t *)REG_CAN0_AM06H)                   /* CAN0 Acceptance Mask (H) Register */
#define pREG_CAN0_AM07H                  ((volatile uint32_t *)REG_CAN0_AM07H)                   /* CAN0 Acceptance Mask (H) Register */
#define pREG_CAN0_AM08H                  ((volatile uint32_t *)REG_CAN0_AM08H)                   /* CAN0 Acceptance Mask (H) Register */
#define pREG_CAN0_AM09H                  ((volatile uint32_t *)REG_CAN0_AM09H)                   /* CAN0 Acceptance Mask (H) Register */
#define pREG_CAN0_AM10H                  ((volatile uint32_t *)REG_CAN0_AM10H)                   /* CAN0 Acceptance Mask (H) Register */
#define pREG_CAN0_AM11H                  ((volatile uint32_t *)REG_CAN0_AM11H)                   /* CAN0 Acceptance Mask (H) Register */
#define pREG_CAN0_AM12H                  ((volatile uint32_t *)REG_CAN0_AM12H)                   /* CAN0 Acceptance Mask (H) Register */
#define pREG_CAN0_AM13H                  ((volatile uint32_t *)REG_CAN0_AM13H)                   /* CAN0 Acceptance Mask (H) Register */
#define pREG_CAN0_AM14H                  ((volatile uint32_t *)REG_CAN0_AM14H)                   /* CAN0 Acceptance Mask (H) Register */
#define pREG_CAN0_AM15H                  ((volatile uint32_t *)REG_CAN0_AM15H)                   /* CAN0 Acceptance Mask (H) Register */
#define pREG_CAN0_AM16H                  ((volatile uint32_t *)REG_CAN0_AM16H)                   /* CAN0 Acceptance Mask (H) Register */
#define pREG_CAN0_AM17H                  ((volatile uint32_t *)REG_CAN0_AM17H)                   /* CAN0 Acceptance Mask (H) Register */
#define pREG_CAN0_AM18H                  ((volatile uint32_t *)REG_CAN0_AM18H)                   /* CAN0 Acceptance Mask (H) Register */
#define pREG_CAN0_AM19H                  ((volatile uint32_t *)REG_CAN0_AM19H)                   /* CAN0 Acceptance Mask (H) Register */
#define pREG_CAN0_AM20H                  ((volatile uint32_t *)REG_CAN0_AM20H)                   /* CAN0 Acceptance Mask (H) Register */
#define pREG_CAN0_AM21H                  ((volatile uint32_t *)REG_CAN0_AM21H)                   /* CAN0 Acceptance Mask (H) Register */
#define pREG_CAN0_AM22H                  ((volatile uint32_t *)REG_CAN0_AM22H)                   /* CAN0 Acceptance Mask (H) Register */
#define pREG_CAN0_AM23H                  ((volatile uint32_t *)REG_CAN0_AM23H)                   /* CAN0 Acceptance Mask (H) Register */
#define pREG_CAN0_AM24H                  ((volatile uint32_t *)REG_CAN0_AM24H)                   /* CAN0 Acceptance Mask (H) Register */
#define pREG_CAN0_AM25H                  ((volatile uint32_t *)REG_CAN0_AM25H)                   /* CAN0 Acceptance Mask (H) Register */
#define pREG_CAN0_AM26H                  ((volatile uint32_t *)REG_CAN0_AM26H)                   /* CAN0 Acceptance Mask (H) Register */
#define pREG_CAN0_AM27H                  ((volatile uint32_t *)REG_CAN0_AM27H)                   /* CAN0 Acceptance Mask (H) Register */
#define pREG_CAN0_AM28H                  ((volatile uint32_t *)REG_CAN0_AM28H)                   /* CAN0 Acceptance Mask (H) Register */
#define pREG_CAN0_AM29H                  ((volatile uint32_t *)REG_CAN0_AM29H)                   /* CAN0 Acceptance Mask (H) Register */
#define pREG_CAN0_AM30H                  ((volatile uint32_t *)REG_CAN0_AM30H)                   /* CAN0 Acceptance Mask (H) Register */
#define pREG_CAN0_AM31H                  ((volatile uint32_t *)REG_CAN0_AM31H)                   /* CAN0 Acceptance Mask (H) Register */
#define pREG_CAN0_MB00_DATA0             ((volatile uint32_t *)REG_CAN0_MB00_DATA0)              /* CAN0 Mailbox Word 0 Register */
#define pREG_CAN0_MB01_DATA0             ((volatile uint32_t *)REG_CAN0_MB01_DATA0)              /* CAN0 Mailbox Word 0 Register */
#define pREG_CAN0_MB02_DATA0             ((volatile uint32_t *)REG_CAN0_MB02_DATA0)              /* CAN0 Mailbox Word 0 Register */
#define pREG_CAN0_MB03_DATA0             ((volatile uint32_t *)REG_CAN0_MB03_DATA0)              /* CAN0 Mailbox Word 0 Register */
#define pREG_CAN0_MB04_DATA0             ((volatile uint32_t *)REG_CAN0_MB04_DATA0)              /* CAN0 Mailbox Word 0 Register */
#define pREG_CAN0_MB05_DATA0             ((volatile uint32_t *)REG_CAN0_MB05_DATA0)              /* CAN0 Mailbox Word 0 Register */
#define pREG_CAN0_MB06_DATA0             ((volatile uint32_t *)REG_CAN0_MB06_DATA0)              /* CAN0 Mailbox Word 0 Register */
#define pREG_CAN0_MB07_DATA0             ((volatile uint32_t *)REG_CAN0_MB07_DATA0)              /* CAN0 Mailbox Word 0 Register */
#define pREG_CAN0_MB08_DATA0             ((volatile uint32_t *)REG_CAN0_MB08_DATA0)              /* CAN0 Mailbox Word 0 Register */
#define pREG_CAN0_MB09_DATA0             ((volatile uint32_t *)REG_CAN0_MB09_DATA0)              /* CAN0 Mailbox Word 0 Register */
#define pREG_CAN0_MB10_DATA0             ((volatile uint32_t *)REG_CAN0_MB10_DATA0)              /* CAN0 Mailbox Word 0 Register */
#define pREG_CAN0_MB11_DATA0             ((volatile uint32_t *)REG_CAN0_MB11_DATA0)              /* CAN0 Mailbox Word 0 Register */
#define pREG_CAN0_MB12_DATA0             ((volatile uint32_t *)REG_CAN0_MB12_DATA0)              /* CAN0 Mailbox Word 0 Register */
#define pREG_CAN0_MB13_DATA0             ((volatile uint32_t *)REG_CAN0_MB13_DATA0)              /* CAN0 Mailbox Word 0 Register */
#define pREG_CAN0_MB14_DATA0             ((volatile uint32_t *)REG_CAN0_MB14_DATA0)              /* CAN0 Mailbox Word 0 Register */
#define pREG_CAN0_MB15_DATA0             ((volatile uint32_t *)REG_CAN0_MB15_DATA0)              /* CAN0 Mailbox Word 0 Register */
#define pREG_CAN0_MB16_DATA0             ((volatile uint32_t *)REG_CAN0_MB16_DATA0)              /* CAN0 Mailbox Word 0 Register */
#define pREG_CAN0_MB17_DATA0             ((volatile uint32_t *)REG_CAN0_MB17_DATA0)              /* CAN0 Mailbox Word 0 Register */
#define pREG_CAN0_MB18_DATA0             ((volatile uint32_t *)REG_CAN0_MB18_DATA0)              /* CAN0 Mailbox Word 0 Register */
#define pREG_CAN0_MB19_DATA0             ((volatile uint32_t *)REG_CAN0_MB19_DATA0)              /* CAN0 Mailbox Word 0 Register */
#define pREG_CAN0_MB20_DATA0             ((volatile uint32_t *)REG_CAN0_MB20_DATA0)              /* CAN0 Mailbox Word 0 Register */
#define pREG_CAN0_MB21_DATA0             ((volatile uint32_t *)REG_CAN0_MB21_DATA0)              /* CAN0 Mailbox Word 0 Register */
#define pREG_CAN0_MB22_DATA0             ((volatile uint32_t *)REG_CAN0_MB22_DATA0)              /* CAN0 Mailbox Word 0 Register */
#define pREG_CAN0_MB23_DATA0             ((volatile uint32_t *)REG_CAN0_MB23_DATA0)              /* CAN0 Mailbox Word 0 Register */
#define pREG_CAN0_MB24_DATA0             ((volatile uint32_t *)REG_CAN0_MB24_DATA0)              /* CAN0 Mailbox Word 0 Register */
#define pREG_CAN0_MB25_DATA0             ((volatile uint32_t *)REG_CAN0_MB25_DATA0)              /* CAN0 Mailbox Word 0 Register */
#define pREG_CAN0_MB26_DATA0             ((volatile uint32_t *)REG_CAN0_MB26_DATA0)              /* CAN0 Mailbox Word 0 Register */
#define pREG_CAN0_MB27_DATA0             ((volatile uint32_t *)REG_CAN0_MB27_DATA0)              /* CAN0 Mailbox Word 0 Register */
#define pREG_CAN0_MB28_DATA0             ((volatile uint32_t *)REG_CAN0_MB28_DATA0)              /* CAN0 Mailbox Word 0 Register */
#define pREG_CAN0_MB29_DATA0             ((volatile uint32_t *)REG_CAN0_MB29_DATA0)              /* CAN0 Mailbox Word 0 Register */
#define pREG_CAN0_MB30_DATA0             ((volatile uint32_t *)REG_CAN0_MB30_DATA0)              /* CAN0 Mailbox Word 0 Register */
#define pREG_CAN0_MB31_DATA0             ((volatile uint32_t *)REG_CAN0_MB31_DATA0)              /* CAN0 Mailbox Word 0 Register */
#define pREG_CAN0_MB00_DATA1             ((volatile uint32_t *)REG_CAN0_MB00_DATA1)              /* CAN0 Mailbox Word 1 Register */
#define pREG_CAN0_MB01_DATA1             ((volatile uint32_t *)REG_CAN0_MB01_DATA1)              /* CAN0 Mailbox Word 1 Register */
#define pREG_CAN0_MB02_DATA1             ((volatile uint32_t *)REG_CAN0_MB02_DATA1)              /* CAN0 Mailbox Word 1 Register */
#define pREG_CAN0_MB03_DATA1             ((volatile uint32_t *)REG_CAN0_MB03_DATA1)              /* CAN0 Mailbox Word 1 Register */
#define pREG_CAN0_MB04_DATA1             ((volatile uint32_t *)REG_CAN0_MB04_DATA1)              /* CAN0 Mailbox Word 1 Register */
#define pREG_CAN0_MB05_DATA1             ((volatile uint32_t *)REG_CAN0_MB05_DATA1)              /* CAN0 Mailbox Word 1 Register */
#define pREG_CAN0_MB06_DATA1             ((volatile uint32_t *)REG_CAN0_MB06_DATA1)              /* CAN0 Mailbox Word 1 Register */
#define pREG_CAN0_MB07_DATA1             ((volatile uint32_t *)REG_CAN0_MB07_DATA1)              /* CAN0 Mailbox Word 1 Register */
#define pREG_CAN0_MB08_DATA1             ((volatile uint32_t *)REG_CAN0_MB08_DATA1)              /* CAN0 Mailbox Word 1 Register */
#define pREG_CAN0_MB09_DATA1             ((volatile uint32_t *)REG_CAN0_MB09_DATA1)              /* CAN0 Mailbox Word 1 Register */
#define pREG_CAN0_MB10_DATA1             ((volatile uint32_t *)REG_CAN0_MB10_DATA1)              /* CAN0 Mailbox Word 1 Register */
#define pREG_CAN0_MB11_DATA1             ((volatile uint32_t *)REG_CAN0_MB11_DATA1)              /* CAN0 Mailbox Word 1 Register */
#define pREG_CAN0_MB12_DATA1             ((volatile uint32_t *)REG_CAN0_MB12_DATA1)              /* CAN0 Mailbox Word 1 Register */
#define pREG_CAN0_MB13_DATA1             ((volatile uint32_t *)REG_CAN0_MB13_DATA1)              /* CAN0 Mailbox Word 1 Register */
#define pREG_CAN0_MB14_DATA1             ((volatile uint32_t *)REG_CAN0_MB14_DATA1)              /* CAN0 Mailbox Word 1 Register */
#define pREG_CAN0_MB15_DATA1             ((volatile uint32_t *)REG_CAN0_MB15_DATA1)              /* CAN0 Mailbox Word 1 Register */
#define pREG_CAN0_MB16_DATA1             ((volatile uint32_t *)REG_CAN0_MB16_DATA1)              /* CAN0 Mailbox Word 1 Register */
#define pREG_CAN0_MB17_DATA1             ((volatile uint32_t *)REG_CAN0_MB17_DATA1)              /* CAN0 Mailbox Word 1 Register */
#define pREG_CAN0_MB18_DATA1             ((volatile uint32_t *)REG_CAN0_MB18_DATA1)              /* CAN0 Mailbox Word 1 Register */
#define pREG_CAN0_MB19_DATA1             ((volatile uint32_t *)REG_CAN0_MB19_DATA1)              /* CAN0 Mailbox Word 1 Register */
#define pREG_CAN0_MB20_DATA1             ((volatile uint32_t *)REG_CAN0_MB20_DATA1)              /* CAN0 Mailbox Word 1 Register */
#define pREG_CAN0_MB21_DATA1             ((volatile uint32_t *)REG_CAN0_MB21_DATA1)              /* CAN0 Mailbox Word 1 Register */
#define pREG_CAN0_MB22_DATA1             ((volatile uint32_t *)REG_CAN0_MB22_DATA1)              /* CAN0 Mailbox Word 1 Register */
#define pREG_CAN0_MB23_DATA1             ((volatile uint32_t *)REG_CAN0_MB23_DATA1)              /* CAN0 Mailbox Word 1 Register */
#define pREG_CAN0_MB24_DATA1             ((volatile uint32_t *)REG_CAN0_MB24_DATA1)              /* CAN0 Mailbox Word 1 Register */
#define pREG_CAN0_MB25_DATA1             ((volatile uint32_t *)REG_CAN0_MB25_DATA1)              /* CAN0 Mailbox Word 1 Register */
#define pREG_CAN0_MB26_DATA1             ((volatile uint32_t *)REG_CAN0_MB26_DATA1)              /* CAN0 Mailbox Word 1 Register */
#define pREG_CAN0_MB27_DATA1             ((volatile uint32_t *)REG_CAN0_MB27_DATA1)              /* CAN0 Mailbox Word 1 Register */
#define pREG_CAN0_MB28_DATA1             ((volatile uint32_t *)REG_CAN0_MB28_DATA1)              /* CAN0 Mailbox Word 1 Register */
#define pREG_CAN0_MB29_DATA1             ((volatile uint32_t *)REG_CAN0_MB29_DATA1)              /* CAN0 Mailbox Word 1 Register */
#define pREG_CAN0_MB30_DATA1             ((volatile uint32_t *)REG_CAN0_MB30_DATA1)              /* CAN0 Mailbox Word 1 Register */
#define pREG_CAN0_MB31_DATA1             ((volatile uint32_t *)REG_CAN0_MB31_DATA1)              /* CAN0 Mailbox Word 1 Register */
#define pREG_CAN0_MB00_DATA2             ((volatile uint32_t *)REG_CAN0_MB00_DATA2)              /* CAN0 Mailbox Word 2 Register */
#define pREG_CAN0_MB01_DATA2             ((volatile uint32_t *)REG_CAN0_MB01_DATA2)              /* CAN0 Mailbox Word 2 Register */
#define pREG_CAN0_MB02_DATA2             ((volatile uint32_t *)REG_CAN0_MB02_DATA2)              /* CAN0 Mailbox Word 2 Register */
#define pREG_CAN0_MB03_DATA2             ((volatile uint32_t *)REG_CAN0_MB03_DATA2)              /* CAN0 Mailbox Word 2 Register */
#define pREG_CAN0_MB04_DATA2             ((volatile uint32_t *)REG_CAN0_MB04_DATA2)              /* CAN0 Mailbox Word 2 Register */
#define pREG_CAN0_MB05_DATA2             ((volatile uint32_t *)REG_CAN0_MB05_DATA2)              /* CAN0 Mailbox Word 2 Register */
#define pREG_CAN0_MB06_DATA2             ((volatile uint32_t *)REG_CAN0_MB06_DATA2)              /* CAN0 Mailbox Word 2 Register */
#define pREG_CAN0_MB07_DATA2             ((volatile uint32_t *)REG_CAN0_MB07_DATA2)              /* CAN0 Mailbox Word 2 Register */
#define pREG_CAN0_MB08_DATA2             ((volatile uint32_t *)REG_CAN0_MB08_DATA2)              /* CAN0 Mailbox Word 2 Register */
#define pREG_CAN0_MB09_DATA2             ((volatile uint32_t *)REG_CAN0_MB09_DATA2)              /* CAN0 Mailbox Word 2 Register */
#define pREG_CAN0_MB10_DATA2             ((volatile uint32_t *)REG_CAN0_MB10_DATA2)              /* CAN0 Mailbox Word 2 Register */
#define pREG_CAN0_MB11_DATA2             ((volatile uint32_t *)REG_CAN0_MB11_DATA2)              /* CAN0 Mailbox Word 2 Register */
#define pREG_CAN0_MB12_DATA2             ((volatile uint32_t *)REG_CAN0_MB12_DATA2)              /* CAN0 Mailbox Word 2 Register */
#define pREG_CAN0_MB13_DATA2             ((volatile uint32_t *)REG_CAN0_MB13_DATA2)              /* CAN0 Mailbox Word 2 Register */
#define pREG_CAN0_MB14_DATA2             ((volatile uint32_t *)REG_CAN0_MB14_DATA2)              /* CAN0 Mailbox Word 2 Register */
#define pREG_CAN0_MB15_DATA2             ((volatile uint32_t *)REG_CAN0_MB15_DATA2)              /* CAN0 Mailbox Word 2 Register */
#define pREG_CAN0_MB16_DATA2             ((volatile uint32_t *)REG_CAN0_MB16_DATA2)              /* CAN0 Mailbox Word 2 Register */
#define pREG_CAN0_MB17_DATA2             ((volatile uint32_t *)REG_CAN0_MB17_DATA2)              /* CAN0 Mailbox Word 2 Register */
#define pREG_CAN0_MB18_DATA2             ((volatile uint32_t *)REG_CAN0_MB18_DATA2)              /* CAN0 Mailbox Word 2 Register */
#define pREG_CAN0_MB19_DATA2             ((volatile uint32_t *)REG_CAN0_MB19_DATA2)              /* CAN0 Mailbox Word 2 Register */
#define pREG_CAN0_MB20_DATA2             ((volatile uint32_t *)REG_CAN0_MB20_DATA2)              /* CAN0 Mailbox Word 2 Register */
#define pREG_CAN0_MB21_DATA2             ((volatile uint32_t *)REG_CAN0_MB21_DATA2)              /* CAN0 Mailbox Word 2 Register */
#define pREG_CAN0_MB22_DATA2             ((volatile uint32_t *)REG_CAN0_MB22_DATA2)              /* CAN0 Mailbox Word 2 Register */
#define pREG_CAN0_MB23_DATA2             ((volatile uint32_t *)REG_CAN0_MB23_DATA2)              /* CAN0 Mailbox Word 2 Register */
#define pREG_CAN0_MB24_DATA2             ((volatile uint32_t *)REG_CAN0_MB24_DATA2)              /* CAN0 Mailbox Word 2 Register */
#define pREG_CAN0_MB25_DATA2             ((volatile uint32_t *)REG_CAN0_MB25_DATA2)              /* CAN0 Mailbox Word 2 Register */
#define pREG_CAN0_MB26_DATA2             ((volatile uint32_t *)REG_CAN0_MB26_DATA2)              /* CAN0 Mailbox Word 2 Register */
#define pREG_CAN0_MB27_DATA2             ((volatile uint32_t *)REG_CAN0_MB27_DATA2)              /* CAN0 Mailbox Word 2 Register */
#define pREG_CAN0_MB28_DATA2             ((volatile uint32_t *)REG_CAN0_MB28_DATA2)              /* CAN0 Mailbox Word 2 Register */
#define pREG_CAN0_MB29_DATA2             ((volatile uint32_t *)REG_CAN0_MB29_DATA2)              /* CAN0 Mailbox Word 2 Register */
#define pREG_CAN0_MB30_DATA2             ((volatile uint32_t *)REG_CAN0_MB30_DATA2)              /* CAN0 Mailbox Word 2 Register */
#define pREG_CAN0_MB31_DATA2             ((volatile uint32_t *)REG_CAN0_MB31_DATA2)              /* CAN0 Mailbox Word 2 Register */
#define pREG_CAN0_MB00_DATA3             ((volatile uint32_t *)REG_CAN0_MB00_DATA3)              /* CAN0 Mailbox Word 3 Register */
#define pREG_CAN0_MB01_DATA3             ((volatile uint32_t *)REG_CAN0_MB01_DATA3)              /* CAN0 Mailbox Word 3 Register */
#define pREG_CAN0_MB02_DATA3             ((volatile uint32_t *)REG_CAN0_MB02_DATA3)              /* CAN0 Mailbox Word 3 Register */
#define pREG_CAN0_MB03_DATA3             ((volatile uint32_t *)REG_CAN0_MB03_DATA3)              /* CAN0 Mailbox Word 3 Register */
#define pREG_CAN0_MB04_DATA3             ((volatile uint32_t *)REG_CAN0_MB04_DATA3)              /* CAN0 Mailbox Word 3 Register */
#define pREG_CAN0_MB05_DATA3             ((volatile uint32_t *)REG_CAN0_MB05_DATA3)              /* CAN0 Mailbox Word 3 Register */
#define pREG_CAN0_MB06_DATA3             ((volatile uint32_t *)REG_CAN0_MB06_DATA3)              /* CAN0 Mailbox Word 3 Register */
#define pREG_CAN0_MB07_DATA3             ((volatile uint32_t *)REG_CAN0_MB07_DATA3)              /* CAN0 Mailbox Word 3 Register */
#define pREG_CAN0_MB08_DATA3             ((volatile uint32_t *)REG_CAN0_MB08_DATA3)              /* CAN0 Mailbox Word 3 Register */
#define pREG_CAN0_MB09_DATA3             ((volatile uint32_t *)REG_CAN0_MB09_DATA3)              /* CAN0 Mailbox Word 3 Register */
#define pREG_CAN0_MB10_DATA3             ((volatile uint32_t *)REG_CAN0_MB10_DATA3)              /* CAN0 Mailbox Word 3 Register */
#define pREG_CAN0_MB11_DATA3             ((volatile uint32_t *)REG_CAN0_MB11_DATA3)              /* CAN0 Mailbox Word 3 Register */
#define pREG_CAN0_MB12_DATA3             ((volatile uint32_t *)REG_CAN0_MB12_DATA3)              /* CAN0 Mailbox Word 3 Register */
#define pREG_CAN0_MB13_DATA3             ((volatile uint32_t *)REG_CAN0_MB13_DATA3)              /* CAN0 Mailbox Word 3 Register */
#define pREG_CAN0_MB14_DATA3             ((volatile uint32_t *)REG_CAN0_MB14_DATA3)              /* CAN0 Mailbox Word 3 Register */
#define pREG_CAN0_MB15_DATA3             ((volatile uint32_t *)REG_CAN0_MB15_DATA3)              /* CAN0 Mailbox Word 3 Register */
#define pREG_CAN0_MB16_DATA3             ((volatile uint32_t *)REG_CAN0_MB16_DATA3)              /* CAN0 Mailbox Word 3 Register */
#define pREG_CAN0_MB17_DATA3             ((volatile uint32_t *)REG_CAN0_MB17_DATA3)              /* CAN0 Mailbox Word 3 Register */
#define pREG_CAN0_MB18_DATA3             ((volatile uint32_t *)REG_CAN0_MB18_DATA3)              /* CAN0 Mailbox Word 3 Register */
#define pREG_CAN0_MB19_DATA3             ((volatile uint32_t *)REG_CAN0_MB19_DATA3)              /* CAN0 Mailbox Word 3 Register */
#define pREG_CAN0_MB20_DATA3             ((volatile uint32_t *)REG_CAN0_MB20_DATA3)              /* CAN0 Mailbox Word 3 Register */
#define pREG_CAN0_MB21_DATA3             ((volatile uint32_t *)REG_CAN0_MB21_DATA3)              /* CAN0 Mailbox Word 3 Register */
#define pREG_CAN0_MB22_DATA3             ((volatile uint32_t *)REG_CAN0_MB22_DATA3)              /* CAN0 Mailbox Word 3 Register */
#define pREG_CAN0_MB23_DATA3             ((volatile uint32_t *)REG_CAN0_MB23_DATA3)              /* CAN0 Mailbox Word 3 Register */
#define pREG_CAN0_MB24_DATA3             ((volatile uint32_t *)REG_CAN0_MB24_DATA3)              /* CAN0 Mailbox Word 3 Register */
#define pREG_CAN0_MB25_DATA3             ((volatile uint32_t *)REG_CAN0_MB25_DATA3)              /* CAN0 Mailbox Word 3 Register */
#define pREG_CAN0_MB26_DATA3             ((volatile uint32_t *)REG_CAN0_MB26_DATA3)              /* CAN0 Mailbox Word 3 Register */
#define pREG_CAN0_MB27_DATA3             ((volatile uint32_t *)REG_CAN0_MB27_DATA3)              /* CAN0 Mailbox Word 3 Register */
#define pREG_CAN0_MB28_DATA3             ((volatile uint32_t *)REG_CAN0_MB28_DATA3)              /* CAN0 Mailbox Word 3 Register */
#define pREG_CAN0_MB29_DATA3             ((volatile uint32_t *)REG_CAN0_MB29_DATA3)              /* CAN0 Mailbox Word 3 Register */
#define pREG_CAN0_MB30_DATA3             ((volatile uint32_t *)REG_CAN0_MB30_DATA3)              /* CAN0 Mailbox Word 3 Register */
#define pREG_CAN0_MB31_DATA3             ((volatile uint32_t *)REG_CAN0_MB31_DATA3)              /* CAN0 Mailbox Word 3 Register */
#define pREG_CAN0_MB00_LENGTH            ((volatile uint32_t *)REG_CAN0_MB00_LENGTH)             /* CAN0 Mailbox Length Register */
#define pREG_CAN0_MB01_LENGTH            ((volatile uint32_t *)REG_CAN0_MB01_LENGTH)             /* CAN0 Mailbox Length Register */
#define pREG_CAN0_MB02_LENGTH            ((volatile uint32_t *)REG_CAN0_MB02_LENGTH)             /* CAN0 Mailbox Length Register */
#define pREG_CAN0_MB03_LENGTH            ((volatile uint32_t *)REG_CAN0_MB03_LENGTH)             /* CAN0 Mailbox Length Register */
#define pREG_CAN0_MB04_LENGTH            ((volatile uint32_t *)REG_CAN0_MB04_LENGTH)             /* CAN0 Mailbox Length Register */
#define pREG_CAN0_MB05_LENGTH            ((volatile uint32_t *)REG_CAN0_MB05_LENGTH)             /* CAN0 Mailbox Length Register */
#define pREG_CAN0_MB06_LENGTH            ((volatile uint32_t *)REG_CAN0_MB06_LENGTH)             /* CAN0 Mailbox Length Register */
#define pREG_CAN0_MB07_LENGTH            ((volatile uint32_t *)REG_CAN0_MB07_LENGTH)             /* CAN0 Mailbox Length Register */
#define pREG_CAN0_MB08_LENGTH            ((volatile uint32_t *)REG_CAN0_MB08_LENGTH)             /* CAN0 Mailbox Length Register */
#define pREG_CAN0_MB09_LENGTH            ((volatile uint32_t *)REG_CAN0_MB09_LENGTH)             /* CAN0 Mailbox Length Register */
#define pREG_CAN0_MB10_LENGTH            ((volatile uint32_t *)REG_CAN0_MB10_LENGTH)             /* CAN0 Mailbox Length Register */
#define pREG_CAN0_MB11_LENGTH            ((volatile uint32_t *)REG_CAN0_MB11_LENGTH)             /* CAN0 Mailbox Length Register */
#define pREG_CAN0_MB12_LENGTH            ((volatile uint32_t *)REG_CAN0_MB12_LENGTH)             /* CAN0 Mailbox Length Register */
#define pREG_CAN0_MB13_LENGTH            ((volatile uint32_t *)REG_CAN0_MB13_LENGTH)             /* CAN0 Mailbox Length Register */
#define pREG_CAN0_MB14_LENGTH            ((volatile uint32_t *)REG_CAN0_MB14_LENGTH)             /* CAN0 Mailbox Length Register */
#define pREG_CAN0_MB15_LENGTH            ((volatile uint32_t *)REG_CAN0_MB15_LENGTH)             /* CAN0 Mailbox Length Register */
#define pREG_CAN0_MB16_LENGTH            ((volatile uint32_t *)REG_CAN0_MB16_LENGTH)             /* CAN0 Mailbox Length Register */
#define pREG_CAN0_MB17_LENGTH            ((volatile uint32_t *)REG_CAN0_MB17_LENGTH)             /* CAN0 Mailbox Length Register */
#define pREG_CAN0_MB18_LENGTH            ((volatile uint32_t *)REG_CAN0_MB18_LENGTH)             /* CAN0 Mailbox Length Register */
#define pREG_CAN0_MB19_LENGTH            ((volatile uint32_t *)REG_CAN0_MB19_LENGTH)             /* CAN0 Mailbox Length Register */
#define pREG_CAN0_MB20_LENGTH            ((volatile uint32_t *)REG_CAN0_MB20_LENGTH)             /* CAN0 Mailbox Length Register */
#define pREG_CAN0_MB21_LENGTH            ((volatile uint32_t *)REG_CAN0_MB21_LENGTH)             /* CAN0 Mailbox Length Register */
#define pREG_CAN0_MB22_LENGTH            ((volatile uint32_t *)REG_CAN0_MB22_LENGTH)             /* CAN0 Mailbox Length Register */
#define pREG_CAN0_MB23_LENGTH            ((volatile uint32_t *)REG_CAN0_MB23_LENGTH)             /* CAN0 Mailbox Length Register */
#define pREG_CAN0_MB24_LENGTH            ((volatile uint32_t *)REG_CAN0_MB24_LENGTH)             /* CAN0 Mailbox Length Register */
#define pREG_CAN0_MB25_LENGTH            ((volatile uint32_t *)REG_CAN0_MB25_LENGTH)             /* CAN0 Mailbox Length Register */
#define pREG_CAN0_MB26_LENGTH            ((volatile uint32_t *)REG_CAN0_MB26_LENGTH)             /* CAN0 Mailbox Length Register */
#define pREG_CAN0_MB27_LENGTH            ((volatile uint32_t *)REG_CAN0_MB27_LENGTH)             /* CAN0 Mailbox Length Register */
#define pREG_CAN0_MB28_LENGTH            ((volatile uint32_t *)REG_CAN0_MB28_LENGTH)             /* CAN0 Mailbox Length Register */
#define pREG_CAN0_MB29_LENGTH            ((volatile uint32_t *)REG_CAN0_MB29_LENGTH)             /* CAN0 Mailbox Length Register */
#define pREG_CAN0_MB30_LENGTH            ((volatile uint32_t *)REG_CAN0_MB30_LENGTH)             /* CAN0 Mailbox Length Register */
#define pREG_CAN0_MB31_LENGTH            ((volatile uint32_t *)REG_CAN0_MB31_LENGTH)             /* CAN0 Mailbox Length Register */
#define pREG_CAN0_MB00_TIMESTAMP         ((volatile uint32_t *)REG_CAN0_MB00_TIMESTAMP)          /* CAN0 Mailbox Timestamp Register */
#define pREG_CAN0_MB01_TIMESTAMP         ((volatile uint32_t *)REG_CAN0_MB01_TIMESTAMP)          /* CAN0 Mailbox Timestamp Register */
#define pREG_CAN0_MB02_TIMESTAMP         ((volatile uint32_t *)REG_CAN0_MB02_TIMESTAMP)          /* CAN0 Mailbox Timestamp Register */
#define pREG_CAN0_MB03_TIMESTAMP         ((volatile uint32_t *)REG_CAN0_MB03_TIMESTAMP)          /* CAN0 Mailbox Timestamp Register */
#define pREG_CAN0_MB04_TIMESTAMP         ((volatile uint32_t *)REG_CAN0_MB04_TIMESTAMP)          /* CAN0 Mailbox Timestamp Register */
#define pREG_CAN0_MB05_TIMESTAMP         ((volatile uint32_t *)REG_CAN0_MB05_TIMESTAMP)          /* CAN0 Mailbox Timestamp Register */
#define pREG_CAN0_MB06_TIMESTAMP         ((volatile uint32_t *)REG_CAN0_MB06_TIMESTAMP)          /* CAN0 Mailbox Timestamp Register */
#define pREG_CAN0_MB07_TIMESTAMP         ((volatile uint32_t *)REG_CAN0_MB07_TIMESTAMP)          /* CAN0 Mailbox Timestamp Register */
#define pREG_CAN0_MB08_TIMESTAMP         ((volatile uint32_t *)REG_CAN0_MB08_TIMESTAMP)          /* CAN0 Mailbox Timestamp Register */
#define pREG_CAN0_MB09_TIMESTAMP         ((volatile uint32_t *)REG_CAN0_MB09_TIMESTAMP)          /* CAN0 Mailbox Timestamp Register */
#define pREG_CAN0_MB10_TIMESTAMP         ((volatile uint32_t *)REG_CAN0_MB10_TIMESTAMP)          /* CAN0 Mailbox Timestamp Register */
#define pREG_CAN0_MB11_TIMESTAMP         ((volatile uint32_t *)REG_CAN0_MB11_TIMESTAMP)          /* CAN0 Mailbox Timestamp Register */
#define pREG_CAN0_MB12_TIMESTAMP         ((volatile uint32_t *)REG_CAN0_MB12_TIMESTAMP)          /* CAN0 Mailbox Timestamp Register */
#define pREG_CAN0_MB13_TIMESTAMP         ((volatile uint32_t *)REG_CAN0_MB13_TIMESTAMP)          /* CAN0 Mailbox Timestamp Register */
#define pREG_CAN0_MB14_TIMESTAMP         ((volatile uint32_t *)REG_CAN0_MB14_TIMESTAMP)          /* CAN0 Mailbox Timestamp Register */
#define pREG_CAN0_MB15_TIMESTAMP         ((volatile uint32_t *)REG_CAN0_MB15_TIMESTAMP)          /* CAN0 Mailbox Timestamp Register */
#define pREG_CAN0_MB16_TIMESTAMP         ((volatile uint32_t *)REG_CAN0_MB16_TIMESTAMP)          /* CAN0 Mailbox Timestamp Register */
#define pREG_CAN0_MB17_TIMESTAMP         ((volatile uint32_t *)REG_CAN0_MB17_TIMESTAMP)          /* CAN0 Mailbox Timestamp Register */
#define pREG_CAN0_MB18_TIMESTAMP         ((volatile uint32_t *)REG_CAN0_MB18_TIMESTAMP)          /* CAN0 Mailbox Timestamp Register */
#define pREG_CAN0_MB19_TIMESTAMP         ((volatile uint32_t *)REG_CAN0_MB19_TIMESTAMP)          /* CAN0 Mailbox Timestamp Register */
#define pREG_CAN0_MB20_TIMESTAMP         ((volatile uint32_t *)REG_CAN0_MB20_TIMESTAMP)          /* CAN0 Mailbox Timestamp Register */
#define pREG_CAN0_MB21_TIMESTAMP         ((volatile uint32_t *)REG_CAN0_MB21_TIMESTAMP)          /* CAN0 Mailbox Timestamp Register */
#define pREG_CAN0_MB22_TIMESTAMP         ((volatile uint32_t *)REG_CAN0_MB22_TIMESTAMP)          /* CAN0 Mailbox Timestamp Register */
#define pREG_CAN0_MB23_TIMESTAMP         ((volatile uint32_t *)REG_CAN0_MB23_TIMESTAMP)          /* CAN0 Mailbox Timestamp Register */
#define pREG_CAN0_MB24_TIMESTAMP         ((volatile uint32_t *)REG_CAN0_MB24_TIMESTAMP)          /* CAN0 Mailbox Timestamp Register */
#define pREG_CAN0_MB25_TIMESTAMP         ((volatile uint32_t *)REG_CAN0_MB25_TIMESTAMP)          /* CAN0 Mailbox Timestamp Register */
#define pREG_CAN0_MB26_TIMESTAMP         ((volatile uint32_t *)REG_CAN0_MB26_TIMESTAMP)          /* CAN0 Mailbox Timestamp Register */
#define pREG_CAN0_MB27_TIMESTAMP         ((volatile uint32_t *)REG_CAN0_MB27_TIMESTAMP)          /* CAN0 Mailbox Timestamp Register */
#define pREG_CAN0_MB28_TIMESTAMP         ((volatile uint32_t *)REG_CAN0_MB28_TIMESTAMP)          /* CAN0 Mailbox Timestamp Register */
#define pREG_CAN0_MB29_TIMESTAMP         ((volatile uint32_t *)REG_CAN0_MB29_TIMESTAMP)          /* CAN0 Mailbox Timestamp Register */
#define pREG_CAN0_MB30_TIMESTAMP         ((volatile uint32_t *)REG_CAN0_MB30_TIMESTAMP)          /* CAN0 Mailbox Timestamp Register */
#define pREG_CAN0_MB31_TIMESTAMP         ((volatile uint32_t *)REG_CAN0_MB31_TIMESTAMP)          /* CAN0 Mailbox Timestamp Register */
#define pREG_CAN0_MB00_ID0               ((volatile uint32_t *)REG_CAN0_MB00_ID0)                /* CAN0 Mailbox ID 0 Register */
#define pREG_CAN0_MB01_ID0               ((volatile uint32_t *)REG_CAN0_MB01_ID0)                /* CAN0 Mailbox ID 0 Register */
#define pREG_CAN0_MB02_ID0               ((volatile uint32_t *)REG_CAN0_MB02_ID0)                /* CAN0 Mailbox ID 0 Register */
#define pREG_CAN0_MB03_ID0               ((volatile uint32_t *)REG_CAN0_MB03_ID0)                /* CAN0 Mailbox ID 0 Register */
#define pREG_CAN0_MB04_ID0               ((volatile uint32_t *)REG_CAN0_MB04_ID0)                /* CAN0 Mailbox ID 0 Register */
#define pREG_CAN0_MB05_ID0               ((volatile uint32_t *)REG_CAN0_MB05_ID0)                /* CAN0 Mailbox ID 0 Register */
#define pREG_CAN0_MB06_ID0               ((volatile uint32_t *)REG_CAN0_MB06_ID0)                /* CAN0 Mailbox ID 0 Register */
#define pREG_CAN0_MB07_ID0               ((volatile uint32_t *)REG_CAN0_MB07_ID0)                /* CAN0 Mailbox ID 0 Register */
#define pREG_CAN0_MB08_ID0               ((volatile uint32_t *)REG_CAN0_MB08_ID0)                /* CAN0 Mailbox ID 0 Register */
#define pREG_CAN0_MB09_ID0               ((volatile uint32_t *)REG_CAN0_MB09_ID0)                /* CAN0 Mailbox ID 0 Register */
#define pREG_CAN0_MB10_ID0               ((volatile uint32_t *)REG_CAN0_MB10_ID0)                /* CAN0 Mailbox ID 0 Register */
#define pREG_CAN0_MB11_ID0               ((volatile uint32_t *)REG_CAN0_MB11_ID0)                /* CAN0 Mailbox ID 0 Register */
#define pREG_CAN0_MB12_ID0               ((volatile uint32_t *)REG_CAN0_MB12_ID0)                /* CAN0 Mailbox ID 0 Register */
#define pREG_CAN0_MB13_ID0               ((volatile uint32_t *)REG_CAN0_MB13_ID0)                /* CAN0 Mailbox ID 0 Register */
#define pREG_CAN0_MB14_ID0               ((volatile uint32_t *)REG_CAN0_MB14_ID0)                /* CAN0 Mailbox ID 0 Register */
#define pREG_CAN0_MB15_ID0               ((volatile uint32_t *)REG_CAN0_MB15_ID0)                /* CAN0 Mailbox ID 0 Register */
#define pREG_CAN0_MB16_ID0               ((volatile uint32_t *)REG_CAN0_MB16_ID0)                /* CAN0 Mailbox ID 0 Register */
#define pREG_CAN0_MB17_ID0               ((volatile uint32_t *)REG_CAN0_MB17_ID0)                /* CAN0 Mailbox ID 0 Register */
#define pREG_CAN0_MB18_ID0               ((volatile uint32_t *)REG_CAN0_MB18_ID0)                /* CAN0 Mailbox ID 0 Register */
#define pREG_CAN0_MB19_ID0               ((volatile uint32_t *)REG_CAN0_MB19_ID0)                /* CAN0 Mailbox ID 0 Register */
#define pREG_CAN0_MB20_ID0               ((volatile uint32_t *)REG_CAN0_MB20_ID0)                /* CAN0 Mailbox ID 0 Register */
#define pREG_CAN0_MB21_ID0               ((volatile uint32_t *)REG_CAN0_MB21_ID0)                /* CAN0 Mailbox ID 0 Register */
#define pREG_CAN0_MB22_ID0               ((volatile uint32_t *)REG_CAN0_MB22_ID0)                /* CAN0 Mailbox ID 0 Register */
#define pREG_CAN0_MB23_ID0               ((volatile uint32_t *)REG_CAN0_MB23_ID0)                /* CAN0 Mailbox ID 0 Register */
#define pREG_CAN0_MB24_ID0               ((volatile uint32_t *)REG_CAN0_MB24_ID0)                /* CAN0 Mailbox ID 0 Register */
#define pREG_CAN0_MB25_ID0               ((volatile uint32_t *)REG_CAN0_MB25_ID0)                /* CAN0 Mailbox ID 0 Register */
#define pREG_CAN0_MB26_ID0               ((volatile uint32_t *)REG_CAN0_MB26_ID0)                /* CAN0 Mailbox ID 0 Register */
#define pREG_CAN0_MB27_ID0               ((volatile uint32_t *)REG_CAN0_MB27_ID0)                /* CAN0 Mailbox ID 0 Register */
#define pREG_CAN0_MB28_ID0               ((volatile uint32_t *)REG_CAN0_MB28_ID0)                /* CAN0 Mailbox ID 0 Register */
#define pREG_CAN0_MB29_ID0               ((volatile uint32_t *)REG_CAN0_MB29_ID0)                /* CAN0 Mailbox ID 0 Register */
#define pREG_CAN0_MB30_ID0               ((volatile uint32_t *)REG_CAN0_MB30_ID0)                /* CAN0 Mailbox ID 0 Register */
#define pREG_CAN0_MB31_ID0               ((volatile uint32_t *)REG_CAN0_MB31_ID0)                /* CAN0 Mailbox ID 0 Register */
#define pREG_CAN0_MB00_ID1               ((volatile uint32_t *)REG_CAN0_MB00_ID1)                /* CAN0 Mailbox ID 1 Register */
#define pREG_CAN0_MB01_ID1               ((volatile uint32_t *)REG_CAN0_MB01_ID1)                /* CAN0 Mailbox ID 1 Register */
#define pREG_CAN0_MB02_ID1               ((volatile uint32_t *)REG_CAN0_MB02_ID1)                /* CAN0 Mailbox ID 1 Register */
#define pREG_CAN0_MB03_ID1               ((volatile uint32_t *)REG_CAN0_MB03_ID1)                /* CAN0 Mailbox ID 1 Register */
#define pREG_CAN0_MB04_ID1               ((volatile uint32_t *)REG_CAN0_MB04_ID1)                /* CAN0 Mailbox ID 1 Register */
#define pREG_CAN0_MB05_ID1               ((volatile uint32_t *)REG_CAN0_MB05_ID1)                /* CAN0 Mailbox ID 1 Register */
#define pREG_CAN0_MB06_ID1               ((volatile uint32_t *)REG_CAN0_MB06_ID1)                /* CAN0 Mailbox ID 1 Register */
#define pREG_CAN0_MB07_ID1               ((volatile uint32_t *)REG_CAN0_MB07_ID1)                /* CAN0 Mailbox ID 1 Register */
#define pREG_CAN0_MB08_ID1               ((volatile uint32_t *)REG_CAN0_MB08_ID1)                /* CAN0 Mailbox ID 1 Register */
#define pREG_CAN0_MB09_ID1               ((volatile uint32_t *)REG_CAN0_MB09_ID1)                /* CAN0 Mailbox ID 1 Register */
#define pREG_CAN0_MB10_ID1               ((volatile uint32_t *)REG_CAN0_MB10_ID1)                /* CAN0 Mailbox ID 1 Register */
#define pREG_CAN0_MB11_ID1               ((volatile uint32_t *)REG_CAN0_MB11_ID1)                /* CAN0 Mailbox ID 1 Register */
#define pREG_CAN0_MB12_ID1               ((volatile uint32_t *)REG_CAN0_MB12_ID1)                /* CAN0 Mailbox ID 1 Register */
#define pREG_CAN0_MB13_ID1               ((volatile uint32_t *)REG_CAN0_MB13_ID1)                /* CAN0 Mailbox ID 1 Register */
#define pREG_CAN0_MB14_ID1               ((volatile uint32_t *)REG_CAN0_MB14_ID1)                /* CAN0 Mailbox ID 1 Register */
#define pREG_CAN0_MB15_ID1               ((volatile uint32_t *)REG_CAN0_MB15_ID1)                /* CAN0 Mailbox ID 1 Register */
#define pREG_CAN0_MB16_ID1               ((volatile uint32_t *)REG_CAN0_MB16_ID1)                /* CAN0 Mailbox ID 1 Register */
#define pREG_CAN0_MB17_ID1               ((volatile uint32_t *)REG_CAN0_MB17_ID1)                /* CAN0 Mailbox ID 1 Register */
#define pREG_CAN0_MB18_ID1               ((volatile uint32_t *)REG_CAN0_MB18_ID1)                /* CAN0 Mailbox ID 1 Register */
#define pREG_CAN0_MB19_ID1               ((volatile uint32_t *)REG_CAN0_MB19_ID1)                /* CAN0 Mailbox ID 1 Register */
#define pREG_CAN0_MB20_ID1               ((volatile uint32_t *)REG_CAN0_MB20_ID1)                /* CAN0 Mailbox ID 1 Register */
#define pREG_CAN0_MB21_ID1               ((volatile uint32_t *)REG_CAN0_MB21_ID1)                /* CAN0 Mailbox ID 1 Register */
#define pREG_CAN0_MB22_ID1               ((volatile uint32_t *)REG_CAN0_MB22_ID1)                /* CAN0 Mailbox ID 1 Register */
#define pREG_CAN0_MB23_ID1               ((volatile uint32_t *)REG_CAN0_MB23_ID1)                /* CAN0 Mailbox ID 1 Register */
#define pREG_CAN0_MB24_ID1               ((volatile uint32_t *)REG_CAN0_MB24_ID1)                /* CAN0 Mailbox ID 1 Register */
#define pREG_CAN0_MB25_ID1               ((volatile uint32_t *)REG_CAN0_MB25_ID1)                /* CAN0 Mailbox ID 1 Register */
#define pREG_CAN0_MB26_ID1               ((volatile uint32_t *)REG_CAN0_MB26_ID1)                /* CAN0 Mailbox ID 1 Register */
#define pREG_CAN0_MB27_ID1               ((volatile uint32_t *)REG_CAN0_MB27_ID1)                /* CAN0 Mailbox ID 1 Register */
#define pREG_CAN0_MB28_ID1               ((volatile uint32_t *)REG_CAN0_MB28_ID1)                /* CAN0 Mailbox ID 1 Register */
#define pREG_CAN0_MB29_ID1               ((volatile uint32_t *)REG_CAN0_MB29_ID1)                /* CAN0 Mailbox ID 1 Register */
#define pREG_CAN0_MB30_ID1               ((volatile uint32_t *)REG_CAN0_MB30_ID1)                /* CAN0 Mailbox ID 1 Register */
#define pREG_CAN0_MB31_ID1               ((volatile uint32_t *)REG_CAN0_MB31_ID1)                /* CAN0 Mailbox ID 1 Register */

/* =========================================================================
       CAN1
   ========================================================================= */
#define pREG_CAN1_MC1                    ((volatile uint32_t *)REG_CAN1_MC1)                     /* CAN1 Mailbox Configuration 1 Register */
#define pREG_CAN1_MD1                    ((volatile uint32_t *)REG_CAN1_MD1)                     /* CAN1 Mailbox Direction 1 Register */
#define pREG_CAN1_TRS1                   ((volatile uint32_t *)REG_CAN1_TRS1)                    /* CAN1 Transmission Request Set 1 Register */
#define pREG_CAN1_TRR1                   ((volatile uint32_t *)REG_CAN1_TRR1)                    /* CAN1 Transmission Request Reset 1 Register */
#define pREG_CAN1_TA1                    ((volatile uint32_t *)REG_CAN1_TA1)                     /* CAN1 Transmission Acknowledge 1 Register */
#define pREG_CAN1_AA1                    ((volatile uint32_t *)REG_CAN1_AA1)                     /* CAN1 Abort Acknowledge 1 Register */
#define pREG_CAN1_RMP1                   ((volatile uint32_t *)REG_CAN1_RMP1)                    /* CAN1 Receive Message Pending 1 Register */
#define pREG_CAN1_RML1                   ((volatile uint32_t *)REG_CAN1_RML1)                    /* CAN1 Receive Message Lost 1 Register */
#define pREG_CAN1_MBTIF1                 ((volatile uint32_t *)REG_CAN1_MBTIF1)                  /* CAN1 Mailbox Transmit Interrupt Flag 1 Register */
#define pREG_CAN1_MBRIF1                 ((volatile uint32_t *)REG_CAN1_MBRIF1)                  /* CAN1 Mailbox Receive Interrupt Flag 1 Register */
#define pREG_CAN1_MBIM1                  ((volatile uint32_t *)REG_CAN1_MBIM1)                   /* CAN1 Mailbox Interrupt Mask 1 Register */
#define pREG_CAN1_RFH1                   ((volatile uint32_t *)REG_CAN1_RFH1)                    /* CAN1 Remote Frame Handling 1 Register */
#define pREG_CAN1_OPSS1                  ((volatile uint32_t *)REG_CAN1_OPSS1)                   /* CAN1 Overwrite Protection/Single Shot Transmission 1 Register */
#define pREG_CAN1_MC2                    ((volatile uint32_t *)REG_CAN1_MC2)                     /* CAN1 Mailbox Configuration 2 Register */
#define pREG_CAN1_MD2                    ((volatile uint32_t *)REG_CAN1_MD2)                     /* CAN1 Mailbox Direction 2 Register */
#define pREG_CAN1_TRS2                   ((volatile uint32_t *)REG_CAN1_TRS2)                    /* CAN1 Transmission Request Set 2 Register */
#define pREG_CAN1_TRR2                   ((volatile uint32_t *)REG_CAN1_TRR2)                    /* CAN1 Transmission Request Reset 2 Register */
#define pREG_CAN1_TA2                    ((volatile uint32_t *)REG_CAN1_TA2)                     /* CAN1 Transmission Acknowledge 2 Register */
#define pREG_CAN1_AA2                    ((volatile uint32_t *)REG_CAN1_AA2)                     /* CAN1 Abort Acknowledge 2 Register */
#define pREG_CAN1_RMP2                   ((volatile uint32_t *)REG_CAN1_RMP2)                    /* CAN1 Receive Message Pending 2 Register */
#define pREG_CAN1_RML2                   ((volatile uint32_t *)REG_CAN1_RML2)                    /* CAN1 Receive Message Lost 2 Register */
#define pREG_CAN1_MBTIF2                 ((volatile uint32_t *)REG_CAN1_MBTIF2)                  /* CAN1 Mailbox Transmit Interrupt Flag 2 Register */
#define pREG_CAN1_MBRIF2                 ((volatile uint32_t *)REG_CAN1_MBRIF2)                  /* CAN1 Mailbox Receive Interrupt Flag 2 Register */
#define pREG_CAN1_MBIM2                  ((volatile uint32_t *)REG_CAN1_MBIM2)                   /* CAN1 Mailbox Interrupt Mask 2 Register */
#define pREG_CAN1_RFH2                   ((volatile uint32_t *)REG_CAN1_RFH2)                    /* CAN1 Remote Frame Handling 2 Register */
#define pREG_CAN1_OPSS2                  ((volatile uint32_t *)REG_CAN1_OPSS2)                   /* CAN1 Overwrite Protection/Single Shot Transmission 2 Register */
#define pREG_CAN1_CLK                    ((volatile uint32_t *)REG_CAN1_CLK)                     /* CAN1 Clock Register */
#define pREG_CAN1_TIMING                 ((volatile uint32_t *)REG_CAN1_TIMING)                  /* CAN1 Timing Register */
#define pREG_CAN1_DBG                    ((volatile uint32_t *)REG_CAN1_DBG)                     /* CAN1 Debug Register */
#define pREG_CAN1_STAT                   ((volatile uint32_t *)REG_CAN1_STAT)                    /* CAN1 Status Register */
#define pREG_CAN1_CEC                    ((volatile uint32_t *)REG_CAN1_CEC)                     /* CAN1 Error Counter Register */
#define pREG_CAN1_GIS                    ((volatile uint32_t *)REG_CAN1_GIS)                     /* CAN1 Global CAN Interrupt Status Register */
#define pREG_CAN1_GIM                    ((volatile uint32_t *)REG_CAN1_GIM)                     /* CAN1 Global CAN Interrupt Mask Register */
#define pREG_CAN1_GIF                    ((volatile uint32_t *)REG_CAN1_GIF)                     /* CAN1 Global CAN Interrupt Flag Register */
#define pREG_CAN1_CTL                    ((volatile uint32_t *)REG_CAN1_CTL)                     /* CAN1 CAN Master Control Register */
#define pREG_CAN1_INT                    ((volatile uint32_t *)REG_CAN1_INT)                     /* CAN1 Interrupt Pending Register */
#define pREG_CAN1_MBTD                   ((volatile uint32_t *)REG_CAN1_MBTD)                    /* CAN1 Temporary Mailbox Disable Register */
#define pREG_CAN1_EWR                    ((volatile uint32_t *)REG_CAN1_EWR)                     /* CAN1 Error Counter Warning Level Register */
#define pREG_CAN1_ESR                    ((volatile uint32_t *)REG_CAN1_ESR)                     /* CAN1 Error Status Register */
#define pREG_CAN1_UCCNT                  ((volatile uint32_t *)REG_CAN1_UCCNT)                   /* CAN1 Universal Counter Register */
#define pREG_CAN1_UCRC                   ((volatile uint32_t *)REG_CAN1_UCRC)                    /* CAN1 Universal Counter Reload/Capture Register */
#define pREG_CAN1_UCCNF                  ((volatile uint32_t *)REG_CAN1_UCCNF)                   /* CAN1 Universal Counter Configuration Mode Register */
#define pREG_CAN1_AM00L                  ((volatile uint32_t *)REG_CAN1_AM00L)                   /* CAN1 Acceptance Mask (L) Register */
#define pREG_CAN1_AM01L                  ((volatile uint32_t *)REG_CAN1_AM01L)                   /* CAN1 Acceptance Mask (L) Register */
#define pREG_CAN1_AM02L                  ((volatile uint32_t *)REG_CAN1_AM02L)                   /* CAN1 Acceptance Mask (L) Register */
#define pREG_CAN1_AM03L                  ((volatile uint32_t *)REG_CAN1_AM03L)                   /* CAN1 Acceptance Mask (L) Register */
#define pREG_CAN1_AM04L                  ((volatile uint32_t *)REG_CAN1_AM04L)                   /* CAN1 Acceptance Mask (L) Register */
#define pREG_CAN1_AM05L                  ((volatile uint32_t *)REG_CAN1_AM05L)                   /* CAN1 Acceptance Mask (L) Register */
#define pREG_CAN1_AM06L                  ((volatile uint32_t *)REG_CAN1_AM06L)                   /* CAN1 Acceptance Mask (L) Register */
#define pREG_CAN1_AM07L                  ((volatile uint32_t *)REG_CAN1_AM07L)                   /* CAN1 Acceptance Mask (L) Register */
#define pREG_CAN1_AM08L                  ((volatile uint32_t *)REG_CAN1_AM08L)                   /* CAN1 Acceptance Mask (L) Register */
#define pREG_CAN1_AM09L                  ((volatile uint32_t *)REG_CAN1_AM09L)                   /* CAN1 Acceptance Mask (L) Register */
#define pREG_CAN1_AM10L                  ((volatile uint32_t *)REG_CAN1_AM10L)                   /* CAN1 Acceptance Mask (L) Register */
#define pREG_CAN1_AM11L                  ((volatile uint32_t *)REG_CAN1_AM11L)                   /* CAN1 Acceptance Mask (L) Register */
#define pREG_CAN1_AM12L                  ((volatile uint32_t *)REG_CAN1_AM12L)                   /* CAN1 Acceptance Mask (L) Register */
#define pREG_CAN1_AM13L                  ((volatile uint32_t *)REG_CAN1_AM13L)                   /* CAN1 Acceptance Mask (L) Register */
#define pREG_CAN1_AM14L                  ((volatile uint32_t *)REG_CAN1_AM14L)                   /* CAN1 Acceptance Mask (L) Register */
#define pREG_CAN1_AM15L                  ((volatile uint32_t *)REG_CAN1_AM15L)                   /* CAN1 Acceptance Mask (L) Register */
#define pREG_CAN1_AM16L                  ((volatile uint32_t *)REG_CAN1_AM16L)                   /* CAN1 Acceptance Mask (L) Register */
#define pREG_CAN1_AM17L                  ((volatile uint32_t *)REG_CAN1_AM17L)                   /* CAN1 Acceptance Mask (L) Register */
#define pREG_CAN1_AM18L                  ((volatile uint32_t *)REG_CAN1_AM18L)                   /* CAN1 Acceptance Mask (L) Register */
#define pREG_CAN1_AM19L                  ((volatile uint32_t *)REG_CAN1_AM19L)                   /* CAN1 Acceptance Mask (L) Register */
#define pREG_CAN1_AM20L                  ((volatile uint32_t *)REG_CAN1_AM20L)                   /* CAN1 Acceptance Mask (L) Register */
#define pREG_CAN1_AM21L                  ((volatile uint32_t *)REG_CAN1_AM21L)                   /* CAN1 Acceptance Mask (L) Register */
#define pREG_CAN1_AM22L                  ((volatile uint32_t *)REG_CAN1_AM22L)                   /* CAN1 Acceptance Mask (L) Register */
#define pREG_CAN1_AM23L                  ((volatile uint32_t *)REG_CAN1_AM23L)                   /* CAN1 Acceptance Mask (L) Register */
#define pREG_CAN1_AM24L                  ((volatile uint32_t *)REG_CAN1_AM24L)                   /* CAN1 Acceptance Mask (L) Register */
#define pREG_CAN1_AM25L                  ((volatile uint32_t *)REG_CAN1_AM25L)                   /* CAN1 Acceptance Mask (L) Register */
#define pREG_CAN1_AM26L                  ((volatile uint32_t *)REG_CAN1_AM26L)                   /* CAN1 Acceptance Mask (L) Register */
#define pREG_CAN1_AM27L                  ((volatile uint32_t *)REG_CAN1_AM27L)                   /* CAN1 Acceptance Mask (L) Register */
#define pREG_CAN1_AM28L                  ((volatile uint32_t *)REG_CAN1_AM28L)                   /* CAN1 Acceptance Mask (L) Register */
#define pREG_CAN1_AM29L                  ((volatile uint32_t *)REG_CAN1_AM29L)                   /* CAN1 Acceptance Mask (L) Register */
#define pREG_CAN1_AM30L                  ((volatile uint32_t *)REG_CAN1_AM30L)                   /* CAN1 Acceptance Mask (L) Register */
#define pREG_CAN1_AM31L                  ((volatile uint32_t *)REG_CAN1_AM31L)                   /* CAN1 Acceptance Mask (L) Register */
#define pREG_CAN1_AM00H                  ((volatile uint32_t *)REG_CAN1_AM00H)                   /* CAN1 Acceptance Mask (H) Register */
#define pREG_CAN1_AM01H                  ((volatile uint32_t *)REG_CAN1_AM01H)                   /* CAN1 Acceptance Mask (H) Register */
#define pREG_CAN1_AM02H                  ((volatile uint32_t *)REG_CAN1_AM02H)                   /* CAN1 Acceptance Mask (H) Register */
#define pREG_CAN1_AM03H                  ((volatile uint32_t *)REG_CAN1_AM03H)                   /* CAN1 Acceptance Mask (H) Register */
#define pREG_CAN1_AM04H                  ((volatile uint32_t *)REG_CAN1_AM04H)                   /* CAN1 Acceptance Mask (H) Register */
#define pREG_CAN1_AM05H                  ((volatile uint32_t *)REG_CAN1_AM05H)                   /* CAN1 Acceptance Mask (H) Register */
#define pREG_CAN1_AM06H                  ((volatile uint32_t *)REG_CAN1_AM06H)                   /* CAN1 Acceptance Mask (H) Register */
#define pREG_CAN1_AM07H                  ((volatile uint32_t *)REG_CAN1_AM07H)                   /* CAN1 Acceptance Mask (H) Register */
#define pREG_CAN1_AM08H                  ((volatile uint32_t *)REG_CAN1_AM08H)                   /* CAN1 Acceptance Mask (H) Register */
#define pREG_CAN1_AM09H                  ((volatile uint32_t *)REG_CAN1_AM09H)                   /* CAN1 Acceptance Mask (H) Register */
#define pREG_CAN1_AM10H                  ((volatile uint32_t *)REG_CAN1_AM10H)                   /* CAN1 Acceptance Mask (H) Register */
#define pREG_CAN1_AM11H                  ((volatile uint32_t *)REG_CAN1_AM11H)                   /* CAN1 Acceptance Mask (H) Register */
#define pREG_CAN1_AM12H                  ((volatile uint32_t *)REG_CAN1_AM12H)                   /* CAN1 Acceptance Mask (H) Register */
#define pREG_CAN1_AM13H                  ((volatile uint32_t *)REG_CAN1_AM13H)                   /* CAN1 Acceptance Mask (H) Register */
#define pREG_CAN1_AM14H                  ((volatile uint32_t *)REG_CAN1_AM14H)                   /* CAN1 Acceptance Mask (H) Register */
#define pREG_CAN1_AM15H                  ((volatile uint32_t *)REG_CAN1_AM15H)                   /* CAN1 Acceptance Mask (H) Register */
#define pREG_CAN1_AM16H                  ((volatile uint32_t *)REG_CAN1_AM16H)                   /* CAN1 Acceptance Mask (H) Register */
#define pREG_CAN1_AM17H                  ((volatile uint32_t *)REG_CAN1_AM17H)                   /* CAN1 Acceptance Mask (H) Register */
#define pREG_CAN1_AM18H                  ((volatile uint32_t *)REG_CAN1_AM18H)                   /* CAN1 Acceptance Mask (H) Register */
#define pREG_CAN1_AM19H                  ((volatile uint32_t *)REG_CAN1_AM19H)                   /* CAN1 Acceptance Mask (H) Register */
#define pREG_CAN1_AM20H                  ((volatile uint32_t *)REG_CAN1_AM20H)                   /* CAN1 Acceptance Mask (H) Register */
#define pREG_CAN1_AM21H                  ((volatile uint32_t *)REG_CAN1_AM21H)                   /* CAN1 Acceptance Mask (H) Register */
#define pREG_CAN1_AM22H                  ((volatile uint32_t *)REG_CAN1_AM22H)                   /* CAN1 Acceptance Mask (H) Register */
#define pREG_CAN1_AM23H                  ((volatile uint32_t *)REG_CAN1_AM23H)                   /* CAN1 Acceptance Mask (H) Register */
#define pREG_CAN1_AM24H                  ((volatile uint32_t *)REG_CAN1_AM24H)                   /* CAN1 Acceptance Mask (H) Register */
#define pREG_CAN1_AM25H                  ((volatile uint32_t *)REG_CAN1_AM25H)                   /* CAN1 Acceptance Mask (H) Register */
#define pREG_CAN1_AM26H                  ((volatile uint32_t *)REG_CAN1_AM26H)                   /* CAN1 Acceptance Mask (H) Register */
#define pREG_CAN1_AM27H                  ((volatile uint32_t *)REG_CAN1_AM27H)                   /* CAN1 Acceptance Mask (H) Register */
#define pREG_CAN1_AM28H                  ((volatile uint32_t *)REG_CAN1_AM28H)                   /* CAN1 Acceptance Mask (H) Register */
#define pREG_CAN1_AM29H                  ((volatile uint32_t *)REG_CAN1_AM29H)                   /* CAN1 Acceptance Mask (H) Register */
#define pREG_CAN1_AM30H                  ((volatile uint32_t *)REG_CAN1_AM30H)                   /* CAN1 Acceptance Mask (H) Register */
#define pREG_CAN1_AM31H                  ((volatile uint32_t *)REG_CAN1_AM31H)                   /* CAN1 Acceptance Mask (H) Register */
#define pREG_CAN1_MB00_DATA0             ((volatile uint32_t *)REG_CAN1_MB00_DATA0)              /* CAN1 Mailbox Word 0 Register */
#define pREG_CAN1_MB01_DATA0             ((volatile uint32_t *)REG_CAN1_MB01_DATA0)              /* CAN1 Mailbox Word 0 Register */
#define pREG_CAN1_MB02_DATA0             ((volatile uint32_t *)REG_CAN1_MB02_DATA0)              /* CAN1 Mailbox Word 0 Register */
#define pREG_CAN1_MB03_DATA0             ((volatile uint32_t *)REG_CAN1_MB03_DATA0)              /* CAN1 Mailbox Word 0 Register */
#define pREG_CAN1_MB04_DATA0             ((volatile uint32_t *)REG_CAN1_MB04_DATA0)              /* CAN1 Mailbox Word 0 Register */
#define pREG_CAN1_MB05_DATA0             ((volatile uint32_t *)REG_CAN1_MB05_DATA0)              /* CAN1 Mailbox Word 0 Register */
#define pREG_CAN1_MB06_DATA0             ((volatile uint32_t *)REG_CAN1_MB06_DATA0)              /* CAN1 Mailbox Word 0 Register */
#define pREG_CAN1_MB07_DATA0             ((volatile uint32_t *)REG_CAN1_MB07_DATA0)              /* CAN1 Mailbox Word 0 Register */
#define pREG_CAN1_MB08_DATA0             ((volatile uint32_t *)REG_CAN1_MB08_DATA0)              /* CAN1 Mailbox Word 0 Register */
#define pREG_CAN1_MB09_DATA0             ((volatile uint32_t *)REG_CAN1_MB09_DATA0)              /* CAN1 Mailbox Word 0 Register */
#define pREG_CAN1_MB10_DATA0             ((volatile uint32_t *)REG_CAN1_MB10_DATA0)              /* CAN1 Mailbox Word 0 Register */
#define pREG_CAN1_MB11_DATA0             ((volatile uint32_t *)REG_CAN1_MB11_DATA0)              /* CAN1 Mailbox Word 0 Register */
#define pREG_CAN1_MB12_DATA0             ((volatile uint32_t *)REG_CAN1_MB12_DATA0)              /* CAN1 Mailbox Word 0 Register */
#define pREG_CAN1_MB13_DATA0             ((volatile uint32_t *)REG_CAN1_MB13_DATA0)              /* CAN1 Mailbox Word 0 Register */
#define pREG_CAN1_MB14_DATA0             ((volatile uint32_t *)REG_CAN1_MB14_DATA0)              /* CAN1 Mailbox Word 0 Register */
#define pREG_CAN1_MB15_DATA0             ((volatile uint32_t *)REG_CAN1_MB15_DATA0)              /* CAN1 Mailbox Word 0 Register */
#define pREG_CAN1_MB16_DATA0             ((volatile uint32_t *)REG_CAN1_MB16_DATA0)              /* CAN1 Mailbox Word 0 Register */
#define pREG_CAN1_MB17_DATA0             ((volatile uint32_t *)REG_CAN1_MB17_DATA0)              /* CAN1 Mailbox Word 0 Register */
#define pREG_CAN1_MB18_DATA0             ((volatile uint32_t *)REG_CAN1_MB18_DATA0)              /* CAN1 Mailbox Word 0 Register */
#define pREG_CAN1_MB19_DATA0             ((volatile uint32_t *)REG_CAN1_MB19_DATA0)              /* CAN1 Mailbox Word 0 Register */
#define pREG_CAN1_MB20_DATA0             ((volatile uint32_t *)REG_CAN1_MB20_DATA0)              /* CAN1 Mailbox Word 0 Register */
#define pREG_CAN1_MB21_DATA0             ((volatile uint32_t *)REG_CAN1_MB21_DATA0)              /* CAN1 Mailbox Word 0 Register */
#define pREG_CAN1_MB22_DATA0             ((volatile uint32_t *)REG_CAN1_MB22_DATA0)              /* CAN1 Mailbox Word 0 Register */
#define pREG_CAN1_MB23_DATA0             ((volatile uint32_t *)REG_CAN1_MB23_DATA0)              /* CAN1 Mailbox Word 0 Register */
#define pREG_CAN1_MB24_DATA0             ((volatile uint32_t *)REG_CAN1_MB24_DATA0)              /* CAN1 Mailbox Word 0 Register */
#define pREG_CAN1_MB25_DATA0             ((volatile uint32_t *)REG_CAN1_MB25_DATA0)              /* CAN1 Mailbox Word 0 Register */
#define pREG_CAN1_MB26_DATA0             ((volatile uint32_t *)REG_CAN1_MB26_DATA0)              /* CAN1 Mailbox Word 0 Register */
#define pREG_CAN1_MB27_DATA0             ((volatile uint32_t *)REG_CAN1_MB27_DATA0)              /* CAN1 Mailbox Word 0 Register */
#define pREG_CAN1_MB28_DATA0             ((volatile uint32_t *)REG_CAN1_MB28_DATA0)              /* CAN1 Mailbox Word 0 Register */
#define pREG_CAN1_MB29_DATA0             ((volatile uint32_t *)REG_CAN1_MB29_DATA0)              /* CAN1 Mailbox Word 0 Register */
#define pREG_CAN1_MB30_DATA0             ((volatile uint32_t *)REG_CAN1_MB30_DATA0)              /* CAN1 Mailbox Word 0 Register */
#define pREG_CAN1_MB31_DATA0             ((volatile uint32_t *)REG_CAN1_MB31_DATA0)              /* CAN1 Mailbox Word 0 Register */
#define pREG_CAN1_MB00_DATA1             ((volatile uint32_t *)REG_CAN1_MB00_DATA1)              /* CAN1 Mailbox Word 1 Register */
#define pREG_CAN1_MB01_DATA1             ((volatile uint32_t *)REG_CAN1_MB01_DATA1)              /* CAN1 Mailbox Word 1 Register */
#define pREG_CAN1_MB02_DATA1             ((volatile uint32_t *)REG_CAN1_MB02_DATA1)              /* CAN1 Mailbox Word 1 Register */
#define pREG_CAN1_MB03_DATA1             ((volatile uint32_t *)REG_CAN1_MB03_DATA1)              /* CAN1 Mailbox Word 1 Register */
#define pREG_CAN1_MB04_DATA1             ((volatile uint32_t *)REG_CAN1_MB04_DATA1)              /* CAN1 Mailbox Word 1 Register */
#define pREG_CAN1_MB05_DATA1             ((volatile uint32_t *)REG_CAN1_MB05_DATA1)              /* CAN1 Mailbox Word 1 Register */
#define pREG_CAN1_MB06_DATA1             ((volatile uint32_t *)REG_CAN1_MB06_DATA1)              /* CAN1 Mailbox Word 1 Register */
#define pREG_CAN1_MB07_DATA1             ((volatile uint32_t *)REG_CAN1_MB07_DATA1)              /* CAN1 Mailbox Word 1 Register */
#define pREG_CAN1_MB08_DATA1             ((volatile uint32_t *)REG_CAN1_MB08_DATA1)              /* CAN1 Mailbox Word 1 Register */
#define pREG_CAN1_MB09_DATA1             ((volatile uint32_t *)REG_CAN1_MB09_DATA1)              /* CAN1 Mailbox Word 1 Register */
#define pREG_CAN1_MB10_DATA1             ((volatile uint32_t *)REG_CAN1_MB10_DATA1)              /* CAN1 Mailbox Word 1 Register */
#define pREG_CAN1_MB11_DATA1             ((volatile uint32_t *)REG_CAN1_MB11_DATA1)              /* CAN1 Mailbox Word 1 Register */
#define pREG_CAN1_MB12_DATA1             ((volatile uint32_t *)REG_CAN1_MB12_DATA1)              /* CAN1 Mailbox Word 1 Register */
#define pREG_CAN1_MB13_DATA1             ((volatile uint32_t *)REG_CAN1_MB13_DATA1)              /* CAN1 Mailbox Word 1 Register */
#define pREG_CAN1_MB14_DATA1             ((volatile uint32_t *)REG_CAN1_MB14_DATA1)              /* CAN1 Mailbox Word 1 Register */
#define pREG_CAN1_MB15_DATA1             ((volatile uint32_t *)REG_CAN1_MB15_DATA1)              /* CAN1 Mailbox Word 1 Register */
#define pREG_CAN1_MB16_DATA1             ((volatile uint32_t *)REG_CAN1_MB16_DATA1)              /* CAN1 Mailbox Word 1 Register */
#define pREG_CAN1_MB17_DATA1             ((volatile uint32_t *)REG_CAN1_MB17_DATA1)              /* CAN1 Mailbox Word 1 Register */
#define pREG_CAN1_MB18_DATA1             ((volatile uint32_t *)REG_CAN1_MB18_DATA1)              /* CAN1 Mailbox Word 1 Register */
#define pREG_CAN1_MB19_DATA1             ((volatile uint32_t *)REG_CAN1_MB19_DATA1)              /* CAN1 Mailbox Word 1 Register */
#define pREG_CAN1_MB20_DATA1             ((volatile uint32_t *)REG_CAN1_MB20_DATA1)              /* CAN1 Mailbox Word 1 Register */
#define pREG_CAN1_MB21_DATA1             ((volatile uint32_t *)REG_CAN1_MB21_DATA1)              /* CAN1 Mailbox Word 1 Register */
#define pREG_CAN1_MB22_DATA1             ((volatile uint32_t *)REG_CAN1_MB22_DATA1)              /* CAN1 Mailbox Word 1 Register */
#define pREG_CAN1_MB23_DATA1             ((volatile uint32_t *)REG_CAN1_MB23_DATA1)              /* CAN1 Mailbox Word 1 Register */
#define pREG_CAN1_MB24_DATA1             ((volatile uint32_t *)REG_CAN1_MB24_DATA1)              /* CAN1 Mailbox Word 1 Register */
#define pREG_CAN1_MB25_DATA1             ((volatile uint32_t *)REG_CAN1_MB25_DATA1)              /* CAN1 Mailbox Word 1 Register */
#define pREG_CAN1_MB26_DATA1             ((volatile uint32_t *)REG_CAN1_MB26_DATA1)              /* CAN1 Mailbox Word 1 Register */
#define pREG_CAN1_MB27_DATA1             ((volatile uint32_t *)REG_CAN1_MB27_DATA1)              /* CAN1 Mailbox Word 1 Register */
#define pREG_CAN1_MB28_DATA1             ((volatile uint32_t *)REG_CAN1_MB28_DATA1)              /* CAN1 Mailbox Word 1 Register */
#define pREG_CAN1_MB29_DATA1             ((volatile uint32_t *)REG_CAN1_MB29_DATA1)              /* CAN1 Mailbox Word 1 Register */
#define pREG_CAN1_MB30_DATA1             ((volatile uint32_t *)REG_CAN1_MB30_DATA1)              /* CAN1 Mailbox Word 1 Register */
#define pREG_CAN1_MB31_DATA1             ((volatile uint32_t *)REG_CAN1_MB31_DATA1)              /* CAN1 Mailbox Word 1 Register */
#define pREG_CAN1_MB00_DATA2             ((volatile uint32_t *)REG_CAN1_MB00_DATA2)              /* CAN1 Mailbox Word 2 Register */
#define pREG_CAN1_MB01_DATA2             ((volatile uint32_t *)REG_CAN1_MB01_DATA2)              /* CAN1 Mailbox Word 2 Register */
#define pREG_CAN1_MB02_DATA2             ((volatile uint32_t *)REG_CAN1_MB02_DATA2)              /* CAN1 Mailbox Word 2 Register */
#define pREG_CAN1_MB03_DATA2             ((volatile uint32_t *)REG_CAN1_MB03_DATA2)              /* CAN1 Mailbox Word 2 Register */
#define pREG_CAN1_MB04_DATA2             ((volatile uint32_t *)REG_CAN1_MB04_DATA2)              /* CAN1 Mailbox Word 2 Register */
#define pREG_CAN1_MB05_DATA2             ((volatile uint32_t *)REG_CAN1_MB05_DATA2)              /* CAN1 Mailbox Word 2 Register */
#define pREG_CAN1_MB06_DATA2             ((volatile uint32_t *)REG_CAN1_MB06_DATA2)              /* CAN1 Mailbox Word 2 Register */
#define pREG_CAN1_MB07_DATA2             ((volatile uint32_t *)REG_CAN1_MB07_DATA2)              /* CAN1 Mailbox Word 2 Register */
#define pREG_CAN1_MB08_DATA2             ((volatile uint32_t *)REG_CAN1_MB08_DATA2)              /* CAN1 Mailbox Word 2 Register */
#define pREG_CAN1_MB09_DATA2             ((volatile uint32_t *)REG_CAN1_MB09_DATA2)              /* CAN1 Mailbox Word 2 Register */
#define pREG_CAN1_MB10_DATA2             ((volatile uint32_t *)REG_CAN1_MB10_DATA2)              /* CAN1 Mailbox Word 2 Register */
#define pREG_CAN1_MB11_DATA2             ((volatile uint32_t *)REG_CAN1_MB11_DATA2)              /* CAN1 Mailbox Word 2 Register */
#define pREG_CAN1_MB12_DATA2             ((volatile uint32_t *)REG_CAN1_MB12_DATA2)              /* CAN1 Mailbox Word 2 Register */
#define pREG_CAN1_MB13_DATA2             ((volatile uint32_t *)REG_CAN1_MB13_DATA2)              /* CAN1 Mailbox Word 2 Register */
#define pREG_CAN1_MB14_DATA2             ((volatile uint32_t *)REG_CAN1_MB14_DATA2)              /* CAN1 Mailbox Word 2 Register */
#define pREG_CAN1_MB15_DATA2             ((volatile uint32_t *)REG_CAN1_MB15_DATA2)              /* CAN1 Mailbox Word 2 Register */
#define pREG_CAN1_MB16_DATA2             ((volatile uint32_t *)REG_CAN1_MB16_DATA2)              /* CAN1 Mailbox Word 2 Register */
#define pREG_CAN1_MB17_DATA2             ((volatile uint32_t *)REG_CAN1_MB17_DATA2)              /* CAN1 Mailbox Word 2 Register */
#define pREG_CAN1_MB18_DATA2             ((volatile uint32_t *)REG_CAN1_MB18_DATA2)              /* CAN1 Mailbox Word 2 Register */
#define pREG_CAN1_MB19_DATA2             ((volatile uint32_t *)REG_CAN1_MB19_DATA2)              /* CAN1 Mailbox Word 2 Register */
#define pREG_CAN1_MB20_DATA2             ((volatile uint32_t *)REG_CAN1_MB20_DATA2)              /* CAN1 Mailbox Word 2 Register */
#define pREG_CAN1_MB21_DATA2             ((volatile uint32_t *)REG_CAN1_MB21_DATA2)              /* CAN1 Mailbox Word 2 Register */
#define pREG_CAN1_MB22_DATA2             ((volatile uint32_t *)REG_CAN1_MB22_DATA2)              /* CAN1 Mailbox Word 2 Register */
#define pREG_CAN1_MB23_DATA2             ((volatile uint32_t *)REG_CAN1_MB23_DATA2)              /* CAN1 Mailbox Word 2 Register */
#define pREG_CAN1_MB24_DATA2             ((volatile uint32_t *)REG_CAN1_MB24_DATA2)              /* CAN1 Mailbox Word 2 Register */
#define pREG_CAN1_MB25_DATA2             ((volatile uint32_t *)REG_CAN1_MB25_DATA2)              /* CAN1 Mailbox Word 2 Register */
#define pREG_CAN1_MB26_DATA2             ((volatile uint32_t *)REG_CAN1_MB26_DATA2)              /* CAN1 Mailbox Word 2 Register */
#define pREG_CAN1_MB27_DATA2             ((volatile uint32_t *)REG_CAN1_MB27_DATA2)              /* CAN1 Mailbox Word 2 Register */
#define pREG_CAN1_MB28_DATA2             ((volatile uint32_t *)REG_CAN1_MB28_DATA2)              /* CAN1 Mailbox Word 2 Register */
#define pREG_CAN1_MB29_DATA2             ((volatile uint32_t *)REG_CAN1_MB29_DATA2)              /* CAN1 Mailbox Word 2 Register */
#define pREG_CAN1_MB30_DATA2             ((volatile uint32_t *)REG_CAN1_MB30_DATA2)              /* CAN1 Mailbox Word 2 Register */
#define pREG_CAN1_MB31_DATA2             ((volatile uint32_t *)REG_CAN1_MB31_DATA2)              /* CAN1 Mailbox Word 2 Register */
#define pREG_CAN1_MB00_DATA3             ((volatile uint32_t *)REG_CAN1_MB00_DATA3)              /* CAN1 Mailbox Word 3 Register */
#define pREG_CAN1_MB01_DATA3             ((volatile uint32_t *)REG_CAN1_MB01_DATA3)              /* CAN1 Mailbox Word 3 Register */
#define pREG_CAN1_MB02_DATA3             ((volatile uint32_t *)REG_CAN1_MB02_DATA3)              /* CAN1 Mailbox Word 3 Register */
#define pREG_CAN1_MB03_DATA3             ((volatile uint32_t *)REG_CAN1_MB03_DATA3)              /* CAN1 Mailbox Word 3 Register */
#define pREG_CAN1_MB04_DATA3             ((volatile uint32_t *)REG_CAN1_MB04_DATA3)              /* CAN1 Mailbox Word 3 Register */
#define pREG_CAN1_MB05_DATA3             ((volatile uint32_t *)REG_CAN1_MB05_DATA3)              /* CAN1 Mailbox Word 3 Register */
#define pREG_CAN1_MB06_DATA3             ((volatile uint32_t *)REG_CAN1_MB06_DATA3)              /* CAN1 Mailbox Word 3 Register */
#define pREG_CAN1_MB07_DATA3             ((volatile uint32_t *)REG_CAN1_MB07_DATA3)              /* CAN1 Mailbox Word 3 Register */
#define pREG_CAN1_MB08_DATA3             ((volatile uint32_t *)REG_CAN1_MB08_DATA3)              /* CAN1 Mailbox Word 3 Register */
#define pREG_CAN1_MB09_DATA3             ((volatile uint32_t *)REG_CAN1_MB09_DATA3)              /* CAN1 Mailbox Word 3 Register */
#define pREG_CAN1_MB10_DATA3             ((volatile uint32_t *)REG_CAN1_MB10_DATA3)              /* CAN1 Mailbox Word 3 Register */
#define pREG_CAN1_MB11_DATA3             ((volatile uint32_t *)REG_CAN1_MB11_DATA3)              /* CAN1 Mailbox Word 3 Register */
#define pREG_CAN1_MB12_DATA3             ((volatile uint32_t *)REG_CAN1_MB12_DATA3)              /* CAN1 Mailbox Word 3 Register */
#define pREG_CAN1_MB13_DATA3             ((volatile uint32_t *)REG_CAN1_MB13_DATA3)              /* CAN1 Mailbox Word 3 Register */
#define pREG_CAN1_MB14_DATA3             ((volatile uint32_t *)REG_CAN1_MB14_DATA3)              /* CAN1 Mailbox Word 3 Register */
#define pREG_CAN1_MB15_DATA3             ((volatile uint32_t *)REG_CAN1_MB15_DATA3)              /* CAN1 Mailbox Word 3 Register */
#define pREG_CAN1_MB16_DATA3             ((volatile uint32_t *)REG_CAN1_MB16_DATA3)              /* CAN1 Mailbox Word 3 Register */
#define pREG_CAN1_MB17_DATA3             ((volatile uint32_t *)REG_CAN1_MB17_DATA3)              /* CAN1 Mailbox Word 3 Register */
#define pREG_CAN1_MB18_DATA3             ((volatile uint32_t *)REG_CAN1_MB18_DATA3)              /* CAN1 Mailbox Word 3 Register */
#define pREG_CAN1_MB19_DATA3             ((volatile uint32_t *)REG_CAN1_MB19_DATA3)              /* CAN1 Mailbox Word 3 Register */
#define pREG_CAN1_MB20_DATA3             ((volatile uint32_t *)REG_CAN1_MB20_DATA3)              /* CAN1 Mailbox Word 3 Register */
#define pREG_CAN1_MB21_DATA3             ((volatile uint32_t *)REG_CAN1_MB21_DATA3)              /* CAN1 Mailbox Word 3 Register */
#define pREG_CAN1_MB22_DATA3             ((volatile uint32_t *)REG_CAN1_MB22_DATA3)              /* CAN1 Mailbox Word 3 Register */
#define pREG_CAN1_MB23_DATA3             ((volatile uint32_t *)REG_CAN1_MB23_DATA3)              /* CAN1 Mailbox Word 3 Register */
#define pREG_CAN1_MB24_DATA3             ((volatile uint32_t *)REG_CAN1_MB24_DATA3)              /* CAN1 Mailbox Word 3 Register */
#define pREG_CAN1_MB25_DATA3             ((volatile uint32_t *)REG_CAN1_MB25_DATA3)              /* CAN1 Mailbox Word 3 Register */
#define pREG_CAN1_MB26_DATA3             ((volatile uint32_t *)REG_CAN1_MB26_DATA3)              /* CAN1 Mailbox Word 3 Register */
#define pREG_CAN1_MB27_DATA3             ((volatile uint32_t *)REG_CAN1_MB27_DATA3)              /* CAN1 Mailbox Word 3 Register */
#define pREG_CAN1_MB28_DATA3             ((volatile uint32_t *)REG_CAN1_MB28_DATA3)              /* CAN1 Mailbox Word 3 Register */
#define pREG_CAN1_MB29_DATA3             ((volatile uint32_t *)REG_CAN1_MB29_DATA3)              /* CAN1 Mailbox Word 3 Register */
#define pREG_CAN1_MB30_DATA3             ((volatile uint32_t *)REG_CAN1_MB30_DATA3)              /* CAN1 Mailbox Word 3 Register */
#define pREG_CAN1_MB31_DATA3             ((volatile uint32_t *)REG_CAN1_MB31_DATA3)              /* CAN1 Mailbox Word 3 Register */
#define pREG_CAN1_MB00_LENGTH            ((volatile uint32_t *)REG_CAN1_MB00_LENGTH)             /* CAN1 Mailbox Length Register */
#define pREG_CAN1_MB01_LENGTH            ((volatile uint32_t *)REG_CAN1_MB01_LENGTH)             /* CAN1 Mailbox Length Register */
#define pREG_CAN1_MB02_LENGTH            ((volatile uint32_t *)REG_CAN1_MB02_LENGTH)             /* CAN1 Mailbox Length Register */
#define pREG_CAN1_MB03_LENGTH            ((volatile uint32_t *)REG_CAN1_MB03_LENGTH)             /* CAN1 Mailbox Length Register */
#define pREG_CAN1_MB04_LENGTH            ((volatile uint32_t *)REG_CAN1_MB04_LENGTH)             /* CAN1 Mailbox Length Register */
#define pREG_CAN1_MB05_LENGTH            ((volatile uint32_t *)REG_CAN1_MB05_LENGTH)             /* CAN1 Mailbox Length Register */
#define pREG_CAN1_MB06_LENGTH            ((volatile uint32_t *)REG_CAN1_MB06_LENGTH)             /* CAN1 Mailbox Length Register */
#define pREG_CAN1_MB07_LENGTH            ((volatile uint32_t *)REG_CAN1_MB07_LENGTH)             /* CAN1 Mailbox Length Register */
#define pREG_CAN1_MB08_LENGTH            ((volatile uint32_t *)REG_CAN1_MB08_LENGTH)             /* CAN1 Mailbox Length Register */
#define pREG_CAN1_MB09_LENGTH            ((volatile uint32_t *)REG_CAN1_MB09_LENGTH)             /* CAN1 Mailbox Length Register */
#define pREG_CAN1_MB10_LENGTH            ((volatile uint32_t *)REG_CAN1_MB10_LENGTH)             /* CAN1 Mailbox Length Register */
#define pREG_CAN1_MB11_LENGTH            ((volatile uint32_t *)REG_CAN1_MB11_LENGTH)             /* CAN1 Mailbox Length Register */
#define pREG_CAN1_MB12_LENGTH            ((volatile uint32_t *)REG_CAN1_MB12_LENGTH)             /* CAN1 Mailbox Length Register */
#define pREG_CAN1_MB13_LENGTH            ((volatile uint32_t *)REG_CAN1_MB13_LENGTH)             /* CAN1 Mailbox Length Register */
#define pREG_CAN1_MB14_LENGTH            ((volatile uint32_t *)REG_CAN1_MB14_LENGTH)             /* CAN1 Mailbox Length Register */
#define pREG_CAN1_MB15_LENGTH            ((volatile uint32_t *)REG_CAN1_MB15_LENGTH)             /* CAN1 Mailbox Length Register */
#define pREG_CAN1_MB16_LENGTH            ((volatile uint32_t *)REG_CAN1_MB16_LENGTH)             /* CAN1 Mailbox Length Register */
#define pREG_CAN1_MB17_LENGTH            ((volatile uint32_t *)REG_CAN1_MB17_LENGTH)             /* CAN1 Mailbox Length Register */
#define pREG_CAN1_MB18_LENGTH            ((volatile uint32_t *)REG_CAN1_MB18_LENGTH)             /* CAN1 Mailbox Length Register */
#define pREG_CAN1_MB19_LENGTH            ((volatile uint32_t *)REG_CAN1_MB19_LENGTH)             /* CAN1 Mailbox Length Register */
#define pREG_CAN1_MB20_LENGTH            ((volatile uint32_t *)REG_CAN1_MB20_LENGTH)             /* CAN1 Mailbox Length Register */
#define pREG_CAN1_MB21_LENGTH            ((volatile uint32_t *)REG_CAN1_MB21_LENGTH)             /* CAN1 Mailbox Length Register */
#define pREG_CAN1_MB22_LENGTH            ((volatile uint32_t *)REG_CAN1_MB22_LENGTH)             /* CAN1 Mailbox Length Register */
#define pREG_CAN1_MB23_LENGTH            ((volatile uint32_t *)REG_CAN1_MB23_LENGTH)             /* CAN1 Mailbox Length Register */
#define pREG_CAN1_MB24_LENGTH            ((volatile uint32_t *)REG_CAN1_MB24_LENGTH)             /* CAN1 Mailbox Length Register */
#define pREG_CAN1_MB25_LENGTH            ((volatile uint32_t *)REG_CAN1_MB25_LENGTH)             /* CAN1 Mailbox Length Register */
#define pREG_CAN1_MB26_LENGTH            ((volatile uint32_t *)REG_CAN1_MB26_LENGTH)             /* CAN1 Mailbox Length Register */
#define pREG_CAN1_MB27_LENGTH            ((volatile uint32_t *)REG_CAN1_MB27_LENGTH)             /* CAN1 Mailbox Length Register */
#define pREG_CAN1_MB28_LENGTH            ((volatile uint32_t *)REG_CAN1_MB28_LENGTH)             /* CAN1 Mailbox Length Register */
#define pREG_CAN1_MB29_LENGTH            ((volatile uint32_t *)REG_CAN1_MB29_LENGTH)             /* CAN1 Mailbox Length Register */
#define pREG_CAN1_MB30_LENGTH            ((volatile uint32_t *)REG_CAN1_MB30_LENGTH)             /* CAN1 Mailbox Length Register */
#define pREG_CAN1_MB31_LENGTH            ((volatile uint32_t *)REG_CAN1_MB31_LENGTH)             /* CAN1 Mailbox Length Register */
#define pREG_CAN1_MB00_TIMESTAMP         ((volatile uint32_t *)REG_CAN1_MB00_TIMESTAMP)          /* CAN1 Mailbox Timestamp Register */
#define pREG_CAN1_MB01_TIMESTAMP         ((volatile uint32_t *)REG_CAN1_MB01_TIMESTAMP)          /* CAN1 Mailbox Timestamp Register */
#define pREG_CAN1_MB02_TIMESTAMP         ((volatile uint32_t *)REG_CAN1_MB02_TIMESTAMP)          /* CAN1 Mailbox Timestamp Register */
#define pREG_CAN1_MB03_TIMESTAMP         ((volatile uint32_t *)REG_CAN1_MB03_TIMESTAMP)          /* CAN1 Mailbox Timestamp Register */
#define pREG_CAN1_MB04_TIMESTAMP         ((volatile uint32_t *)REG_CAN1_MB04_TIMESTAMP)          /* CAN1 Mailbox Timestamp Register */
#define pREG_CAN1_MB05_TIMESTAMP         ((volatile uint32_t *)REG_CAN1_MB05_TIMESTAMP)          /* CAN1 Mailbox Timestamp Register */
#define pREG_CAN1_MB06_TIMESTAMP         ((volatile uint32_t *)REG_CAN1_MB06_TIMESTAMP)          /* CAN1 Mailbox Timestamp Register */
#define pREG_CAN1_MB07_TIMESTAMP         ((volatile uint32_t *)REG_CAN1_MB07_TIMESTAMP)          /* CAN1 Mailbox Timestamp Register */
#define pREG_CAN1_MB08_TIMESTAMP         ((volatile uint32_t *)REG_CAN1_MB08_TIMESTAMP)          /* CAN1 Mailbox Timestamp Register */
#define pREG_CAN1_MB09_TIMESTAMP         ((volatile uint32_t *)REG_CAN1_MB09_TIMESTAMP)          /* CAN1 Mailbox Timestamp Register */
#define pREG_CAN1_MB10_TIMESTAMP         ((volatile uint32_t *)REG_CAN1_MB10_TIMESTAMP)          /* CAN1 Mailbox Timestamp Register */
#define pREG_CAN1_MB11_TIMESTAMP         ((volatile uint32_t *)REG_CAN1_MB11_TIMESTAMP)          /* CAN1 Mailbox Timestamp Register */
#define pREG_CAN1_MB12_TIMESTAMP         ((volatile uint32_t *)REG_CAN1_MB12_TIMESTAMP)          /* CAN1 Mailbox Timestamp Register */
#define pREG_CAN1_MB13_TIMESTAMP         ((volatile uint32_t *)REG_CAN1_MB13_TIMESTAMP)          /* CAN1 Mailbox Timestamp Register */
#define pREG_CAN1_MB14_TIMESTAMP         ((volatile uint32_t *)REG_CAN1_MB14_TIMESTAMP)          /* CAN1 Mailbox Timestamp Register */
#define pREG_CAN1_MB15_TIMESTAMP         ((volatile uint32_t *)REG_CAN1_MB15_TIMESTAMP)          /* CAN1 Mailbox Timestamp Register */
#define pREG_CAN1_MB16_TIMESTAMP         ((volatile uint32_t *)REG_CAN1_MB16_TIMESTAMP)          /* CAN1 Mailbox Timestamp Register */
#define pREG_CAN1_MB17_TIMESTAMP         ((volatile uint32_t *)REG_CAN1_MB17_TIMESTAMP)          /* CAN1 Mailbox Timestamp Register */
#define pREG_CAN1_MB18_TIMESTAMP         ((volatile uint32_t *)REG_CAN1_MB18_TIMESTAMP)          /* CAN1 Mailbox Timestamp Register */
#define pREG_CAN1_MB19_TIMESTAMP         ((volatile uint32_t *)REG_CAN1_MB19_TIMESTAMP)          /* CAN1 Mailbox Timestamp Register */
#define pREG_CAN1_MB20_TIMESTAMP         ((volatile uint32_t *)REG_CAN1_MB20_TIMESTAMP)          /* CAN1 Mailbox Timestamp Register */
#define pREG_CAN1_MB21_TIMESTAMP         ((volatile uint32_t *)REG_CAN1_MB21_TIMESTAMP)          /* CAN1 Mailbox Timestamp Register */
#define pREG_CAN1_MB22_TIMESTAMP         ((volatile uint32_t *)REG_CAN1_MB22_TIMESTAMP)          /* CAN1 Mailbox Timestamp Register */
#define pREG_CAN1_MB23_TIMESTAMP         ((volatile uint32_t *)REG_CAN1_MB23_TIMESTAMP)          /* CAN1 Mailbox Timestamp Register */
#define pREG_CAN1_MB24_TIMESTAMP         ((volatile uint32_t *)REG_CAN1_MB24_TIMESTAMP)          /* CAN1 Mailbox Timestamp Register */
#define pREG_CAN1_MB25_TIMESTAMP         ((volatile uint32_t *)REG_CAN1_MB25_TIMESTAMP)          /* CAN1 Mailbox Timestamp Register */
#define pREG_CAN1_MB26_TIMESTAMP         ((volatile uint32_t *)REG_CAN1_MB26_TIMESTAMP)          /* CAN1 Mailbox Timestamp Register */
#define pREG_CAN1_MB27_TIMESTAMP         ((volatile uint32_t *)REG_CAN1_MB27_TIMESTAMP)          /* CAN1 Mailbox Timestamp Register */
#define pREG_CAN1_MB28_TIMESTAMP         ((volatile uint32_t *)REG_CAN1_MB28_TIMESTAMP)          /* CAN1 Mailbox Timestamp Register */
#define pREG_CAN1_MB29_TIMESTAMP         ((volatile uint32_t *)REG_CAN1_MB29_TIMESTAMP)          /* CAN1 Mailbox Timestamp Register */
#define pREG_CAN1_MB30_TIMESTAMP         ((volatile uint32_t *)REG_CAN1_MB30_TIMESTAMP)          /* CAN1 Mailbox Timestamp Register */
#define pREG_CAN1_MB31_TIMESTAMP         ((volatile uint32_t *)REG_CAN1_MB31_TIMESTAMP)          /* CAN1 Mailbox Timestamp Register */
#define pREG_CAN1_MB00_ID0               ((volatile uint32_t *)REG_CAN1_MB00_ID0)                /* CAN1 Mailbox ID 0 Register */
#define pREG_CAN1_MB01_ID0               ((volatile uint32_t *)REG_CAN1_MB01_ID0)                /* CAN1 Mailbox ID 0 Register */
#define pREG_CAN1_MB02_ID0               ((volatile uint32_t *)REG_CAN1_MB02_ID0)                /* CAN1 Mailbox ID 0 Register */
#define pREG_CAN1_MB03_ID0               ((volatile uint32_t *)REG_CAN1_MB03_ID0)                /* CAN1 Mailbox ID 0 Register */
#define pREG_CAN1_MB04_ID0               ((volatile uint32_t *)REG_CAN1_MB04_ID0)                /* CAN1 Mailbox ID 0 Register */
#define pREG_CAN1_MB05_ID0               ((volatile uint32_t *)REG_CAN1_MB05_ID0)                /* CAN1 Mailbox ID 0 Register */
#define pREG_CAN1_MB06_ID0               ((volatile uint32_t *)REG_CAN1_MB06_ID0)                /* CAN1 Mailbox ID 0 Register */
#define pREG_CAN1_MB07_ID0               ((volatile uint32_t *)REG_CAN1_MB07_ID0)                /* CAN1 Mailbox ID 0 Register */
#define pREG_CAN1_MB08_ID0               ((volatile uint32_t *)REG_CAN1_MB08_ID0)                /* CAN1 Mailbox ID 0 Register */
#define pREG_CAN1_MB09_ID0               ((volatile uint32_t *)REG_CAN1_MB09_ID0)                /* CAN1 Mailbox ID 0 Register */
#define pREG_CAN1_MB10_ID0               ((volatile uint32_t *)REG_CAN1_MB10_ID0)                /* CAN1 Mailbox ID 0 Register */
#define pREG_CAN1_MB11_ID0               ((volatile uint32_t *)REG_CAN1_MB11_ID0)                /* CAN1 Mailbox ID 0 Register */
#define pREG_CAN1_MB12_ID0               ((volatile uint32_t *)REG_CAN1_MB12_ID0)                /* CAN1 Mailbox ID 0 Register */
#define pREG_CAN1_MB13_ID0               ((volatile uint32_t *)REG_CAN1_MB13_ID0)                /* CAN1 Mailbox ID 0 Register */
#define pREG_CAN1_MB14_ID0               ((volatile uint32_t *)REG_CAN1_MB14_ID0)                /* CAN1 Mailbox ID 0 Register */
#define pREG_CAN1_MB15_ID0               ((volatile uint32_t *)REG_CAN1_MB15_ID0)                /* CAN1 Mailbox ID 0 Register */
#define pREG_CAN1_MB16_ID0               ((volatile uint32_t *)REG_CAN1_MB16_ID0)                /* CAN1 Mailbox ID 0 Register */
#define pREG_CAN1_MB17_ID0               ((volatile uint32_t *)REG_CAN1_MB17_ID0)                /* CAN1 Mailbox ID 0 Register */
#define pREG_CAN1_MB18_ID0               ((volatile uint32_t *)REG_CAN1_MB18_ID0)                /* CAN1 Mailbox ID 0 Register */
#define pREG_CAN1_MB19_ID0               ((volatile uint32_t *)REG_CAN1_MB19_ID0)                /* CAN1 Mailbox ID 0 Register */
#define pREG_CAN1_MB20_ID0               ((volatile uint32_t *)REG_CAN1_MB20_ID0)                /* CAN1 Mailbox ID 0 Register */
#define pREG_CAN1_MB21_ID0               ((volatile uint32_t *)REG_CAN1_MB21_ID0)                /* CAN1 Mailbox ID 0 Register */
#define pREG_CAN1_MB22_ID0               ((volatile uint32_t *)REG_CAN1_MB22_ID0)                /* CAN1 Mailbox ID 0 Register */
#define pREG_CAN1_MB23_ID0               ((volatile uint32_t *)REG_CAN1_MB23_ID0)                /* CAN1 Mailbox ID 0 Register */
#define pREG_CAN1_MB24_ID0               ((volatile uint32_t *)REG_CAN1_MB24_ID0)                /* CAN1 Mailbox ID 0 Register */
#define pREG_CAN1_MB25_ID0               ((volatile uint32_t *)REG_CAN1_MB25_ID0)                /* CAN1 Mailbox ID 0 Register */
#define pREG_CAN1_MB26_ID0               ((volatile uint32_t *)REG_CAN1_MB26_ID0)                /* CAN1 Mailbox ID 0 Register */
#define pREG_CAN1_MB27_ID0               ((volatile uint32_t *)REG_CAN1_MB27_ID0)                /* CAN1 Mailbox ID 0 Register */
#define pREG_CAN1_MB28_ID0               ((volatile uint32_t *)REG_CAN1_MB28_ID0)                /* CAN1 Mailbox ID 0 Register */
#define pREG_CAN1_MB29_ID0               ((volatile uint32_t *)REG_CAN1_MB29_ID0)                /* CAN1 Mailbox ID 0 Register */
#define pREG_CAN1_MB30_ID0               ((volatile uint32_t *)REG_CAN1_MB30_ID0)                /* CAN1 Mailbox ID 0 Register */
#define pREG_CAN1_MB31_ID0               ((volatile uint32_t *)REG_CAN1_MB31_ID0)                /* CAN1 Mailbox ID 0 Register */
#define pREG_CAN1_MB00_ID1               ((volatile uint32_t *)REG_CAN1_MB00_ID1)                /* CAN1 Mailbox ID 1 Register */
#define pREG_CAN1_MB01_ID1               ((volatile uint32_t *)REG_CAN1_MB01_ID1)                /* CAN1 Mailbox ID 1 Register */
#define pREG_CAN1_MB02_ID1               ((volatile uint32_t *)REG_CAN1_MB02_ID1)                /* CAN1 Mailbox ID 1 Register */
#define pREG_CAN1_MB03_ID1               ((volatile uint32_t *)REG_CAN1_MB03_ID1)                /* CAN1 Mailbox ID 1 Register */
#define pREG_CAN1_MB04_ID1               ((volatile uint32_t *)REG_CAN1_MB04_ID1)                /* CAN1 Mailbox ID 1 Register */
#define pREG_CAN1_MB05_ID1               ((volatile uint32_t *)REG_CAN1_MB05_ID1)                /* CAN1 Mailbox ID 1 Register */
#define pREG_CAN1_MB06_ID1               ((volatile uint32_t *)REG_CAN1_MB06_ID1)                /* CAN1 Mailbox ID 1 Register */
#define pREG_CAN1_MB07_ID1               ((volatile uint32_t *)REG_CAN1_MB07_ID1)                /* CAN1 Mailbox ID 1 Register */
#define pREG_CAN1_MB08_ID1               ((volatile uint32_t *)REG_CAN1_MB08_ID1)                /* CAN1 Mailbox ID 1 Register */
#define pREG_CAN1_MB09_ID1               ((volatile uint32_t *)REG_CAN1_MB09_ID1)                /* CAN1 Mailbox ID 1 Register */
#define pREG_CAN1_MB10_ID1               ((volatile uint32_t *)REG_CAN1_MB10_ID1)                /* CAN1 Mailbox ID 1 Register */
#define pREG_CAN1_MB11_ID1               ((volatile uint32_t *)REG_CAN1_MB11_ID1)                /* CAN1 Mailbox ID 1 Register */
#define pREG_CAN1_MB12_ID1               ((volatile uint32_t *)REG_CAN1_MB12_ID1)                /* CAN1 Mailbox ID 1 Register */
#define pREG_CAN1_MB13_ID1               ((volatile uint32_t *)REG_CAN1_MB13_ID1)                /* CAN1 Mailbox ID 1 Register */
#define pREG_CAN1_MB14_ID1               ((volatile uint32_t *)REG_CAN1_MB14_ID1)                /* CAN1 Mailbox ID 1 Register */
#define pREG_CAN1_MB15_ID1               ((volatile uint32_t *)REG_CAN1_MB15_ID1)                /* CAN1 Mailbox ID 1 Register */
#define pREG_CAN1_MB16_ID1               ((volatile uint32_t *)REG_CAN1_MB16_ID1)                /* CAN1 Mailbox ID 1 Register */
#define pREG_CAN1_MB17_ID1               ((volatile uint32_t *)REG_CAN1_MB17_ID1)                /* CAN1 Mailbox ID 1 Register */
#define pREG_CAN1_MB18_ID1               ((volatile uint32_t *)REG_CAN1_MB18_ID1)                /* CAN1 Mailbox ID 1 Register */
#define pREG_CAN1_MB19_ID1               ((volatile uint32_t *)REG_CAN1_MB19_ID1)                /* CAN1 Mailbox ID 1 Register */
#define pREG_CAN1_MB20_ID1               ((volatile uint32_t *)REG_CAN1_MB20_ID1)                /* CAN1 Mailbox ID 1 Register */
#define pREG_CAN1_MB21_ID1               ((volatile uint32_t *)REG_CAN1_MB21_ID1)                /* CAN1 Mailbox ID 1 Register */
#define pREG_CAN1_MB22_ID1               ((volatile uint32_t *)REG_CAN1_MB22_ID1)                /* CAN1 Mailbox ID 1 Register */
#define pREG_CAN1_MB23_ID1               ((volatile uint32_t *)REG_CAN1_MB23_ID1)                /* CAN1 Mailbox ID 1 Register */
#define pREG_CAN1_MB24_ID1               ((volatile uint32_t *)REG_CAN1_MB24_ID1)                /* CAN1 Mailbox ID 1 Register */
#define pREG_CAN1_MB25_ID1               ((volatile uint32_t *)REG_CAN1_MB25_ID1)                /* CAN1 Mailbox ID 1 Register */
#define pREG_CAN1_MB26_ID1               ((volatile uint32_t *)REG_CAN1_MB26_ID1)                /* CAN1 Mailbox ID 1 Register */
#define pREG_CAN1_MB27_ID1               ((volatile uint32_t *)REG_CAN1_MB27_ID1)                /* CAN1 Mailbox ID 1 Register */
#define pREG_CAN1_MB28_ID1               ((volatile uint32_t *)REG_CAN1_MB28_ID1)                /* CAN1 Mailbox ID 1 Register */
#define pREG_CAN1_MB29_ID1               ((volatile uint32_t *)REG_CAN1_MB29_ID1)                /* CAN1 Mailbox ID 1 Register */
#define pREG_CAN1_MB30_ID1               ((volatile uint32_t *)REG_CAN1_MB30_ID1)                /* CAN1 Mailbox ID 1 Register */
#define pREG_CAN1_MB31_ID1               ((volatile uint32_t *)REG_CAN1_MB31_ID1)                /* CAN1 Mailbox ID 1 Register */


/* =========================================================================
       CNT0
   ========================================================================= */
#define pREG_CNT0_CFG                    ((volatile uint32_t *)REG_CNT0_CFG)                     /* CNT0 Configuration Register */
#define pREG_CNT0_IMSK                   ((volatile uint32_t *)REG_CNT0_IMSK)                    /* CNT0 Interrupt Mask Register */
#define pREG_CNT0_STAT                   ((volatile uint32_t *)REG_CNT0_STAT)                    /* CNT0 Status Register */
#define pREG_CNT0_CMD                    ((volatile uint32_t *)REG_CNT0_CMD)                     /* CNT0 Command Register */
#define pREG_CNT0_DEBNCE                 ((volatile uint32_t *)REG_CNT0_DEBNCE)                  /* CNT0 Debounce Register */
#define pREG_CNT0_CNTR                   ((volatile uint32_t *)REG_CNT0_CNTR)                    /* CNT0 Counter Register */
#define pREG_CNT0_MAX                    ((volatile uint32_t *)REG_CNT0_MAX)                     /* CNT0 Maximum Count Register */
#define pREG_CNT0_MIN                    ((volatile uint32_t *)REG_CNT0_MIN)                     /* CNT0 Minimum Count Register */


/* =========================================================================
       OTPC0
   ========================================================================= */
#define pREG_OTPC0_CTL                   ((volatile uint32_t *)REG_OTPC0_CTL)                    /* OTPC0 OTPCTL control register */
#define pREG_OTPC0_STAT                  ((volatile uint32_t *)REG_OTPC0_STAT)                   /* OTPC0 OTPCTL status register */
#define pREG_OTPC0_TIMING                ((volatile uint32_t *)REG_OTPC0_TIMING)                 /* OTPC0 Timing register for OTP controller read timings */
#define pREG_OTPC0_BOOT_SR3              ((volatile uint32_t *)REG_OTPC0_BOOT_SR3)               /* OTPC0 BOOT SR[123:96] Register */
#define pREG_OTPC0_BOOT_RR0              ((volatile uint32_t *)REG_OTPC0_BOOT_RR0)               /* OTPC0 BOOT RR[31:0] Register */
#define pREG_OTPC0_BOOT_RR1              ((volatile uint32_t *)REG_OTPC0_BOOT_RR1)               /* OTPC0 BOOT RR[63:32] Register */
#define pREG_OTPC0_SECU_STATE            ((volatile uint32_t *)REG_OTPC0_SECU_STATE)             /* OTPC0 OTP Security State Register */
#define pREG_OTPC0_DAP_DR                ((volatile uint32_t *)REG_OTPC0_DAP_DR)                 /* OTPC0 OTP Data register */
#define pREG_OTPC0_DAP_OAR               ((volatile uint32_t *)REG_OTPC0_DAP_OAR)                /* OTPC0 OTP Address register */
#define pREG_OTPC0_PMC_INST              ((volatile uint32_t *)REG_OTPC0_PMC_INST)               /* OTPC0 Instruction register for PMC */
#define pREG_OTPC0_PMC_CTL               ((volatile uint32_t *)REG_OTPC0_PMC_CTL)                /* OTPC0 PMC control register */
#define pREG_OTPC0_PMC_STAT              ((volatile uint32_t *)REG_OTPC0_PMC_STAT)               /* OTPC0 PMC status register */
#define pREG_OTPC0_PMC_MODE0             ((volatile uint32_t *)REG_OTPC0_PMC_MODE0)              /* OTPC0 PMC Mode 0 register */
#define pREG_OTPC0_PMC_MODE1             ((volatile uint32_t *)REG_OTPC0_PMC_MODE1)              /* OTPC0 PMC Mode 1 register */
#define pREG_OTPC0_PMC_MODE2             ((volatile uint32_t *)REG_OTPC0_PMC_MODE2)              /* OTPC0 PMC Mode 2 register */
#define pREG_OTPC0_PMC_MODE3             ((volatile uint32_t *)REG_OTPC0_PMC_MODE3)              /* OTPC0 PMC Mode 3 register for PROGRAM */
#define pREG_OTPC0_PMC_PGM_TMG0          ((volatile uint32_t *)REG_OTPC0_PMC_PGM_TMG0)           /* OTPC0 PMC PROGRAM Timing Control 0 register */
#define pREG_OTPC0_PMC_PGM_TMG1          ((volatile uint32_t *)REG_OTPC0_PMC_PGM_TMG1)           /* OTPC0 PMC PROGRAM Timing Control 1 register */
#define pREG_OTPC0_PMC_PGM_TMG2          ((volatile uint32_t *)REG_OTPC0_PMC_PGM_TMG2)           /* OTPC0 PMC Timing Control 2 register for PROGRAM */
#define pREG_OTPC0_PMC_DAP_ADDR          ((volatile uint32_t *)REG_OTPC0_PMC_DAP_ADDR)           /* OTPC0 PMC - Target DAP ID Address */
#define pREG_OTPC0_PMC_PGM_CQ            ((volatile uint32_t *)REG_OTPC0_PMC_PGM_CQ)             /* OTPC0 PMC FSM Control register for PROGRAM */
#define pREG_OTPC0_DAP_RFMR              ((volatile uint32_t *)REG_OTPC0_DAP_RFMR)               /* OTPC0 DAP Read mode select register */
#define pREG_OTPC0_DAP_VRMR              ((volatile uint32_t *)REG_OTPC0_DAP_VRMR)               /* OTPC0 DAP Read voltage level register */
#define pREG_OTPC0_DAP_OVLR              ((volatile uint32_t *)REG_OTPC0_DAP_OVLR)               /* OTPC0 DAP Programming voltage level register */
#define pREG_OTPC0_DAP_IPCR              ((volatile uint32_t *)REG_OTPC0_DAP_IPCR)               /* OTPC0 DAP IPS Test Mode control register */
#define pREG_OTPC0_DAP_ORCR              ((volatile uint32_t *)REG_OTPC0_DAP_ORCR)               /* OTPC0 DAP OTP Test mode control register */
#define pREG_OTPC0_DAP_ODCR              ((volatile uint32_t *)REG_OTPC0_DAP_ODCR)               /* OTPC0 DAP Read Timing control register */
#define pREG_OTPC0_DAP_IPCR2             ((volatile uint32_t *)REG_OTPC0_DAP_IPCR2)              /* OTPC0 DAP IPS Band Gap Control register */
#define pREG_OTPC0_DAP_OCER              ((volatile uint32_t *)REG_OTPC0_DAP_OCER)               /* OTPC0 DAP PD and SEL control register */
#define pREG_OTPC0_DAP_DPCR              ((volatile uint32_t *)REG_OTPC0_DAP_DPCR)               /* OTPC0 DAP Data Path Control Register */
#define pREG_OTPC0_DAP_DPCR2             ((volatile uint32_t *)REG_OTPC0_DAP_DPCR2)              /* OTPC0 DAP Data Path Control Register (Multi-bit Programming) */


/* =========================================================================
       MSI0
   ========================================================================= */
#define pREG_MSI0_CTL                    ((volatile uint32_t *)REG_MSI0_CTL)                     /* MSI0 Contorl register */
#define pREG_MSI0_PWREN                  ((volatile uint32_t *)REG_MSI0_PWREN)                   /* MSI0 Power Enable Register */
#define pREG_MSI0_CLKDIV                 ((volatile uint32_t *)REG_MSI0_CLKDIV)                  /* MSI0 Clock Divider Register */
#define pREG_MSI0_CLKEN                  ((volatile uint32_t *)REG_MSI0_CLKEN)                   /* MSI0 Clock Enable Register */
#define pREG_MSI0_TMOUT                  ((volatile uint32_t *)REG_MSI0_TMOUT)                   /* MSI0 Timeout Register */
#define pREG_MSI0_CTYPE                  ((volatile uint32_t *)REG_MSI0_CTYPE)                   /* MSI0 Card Type Register */
#define pREG_MSI0_BLKSIZ                 ((volatile uint32_t *)REG_MSI0_BLKSIZ)                  /* MSI0 Block Size Register */
#define pREG_MSI0_BYTCNT                 ((volatile uint32_t *)REG_MSI0_BYTCNT)                  /* MSI0 Byte Count Register */
#define pREG_MSI0_IMSK                   ((volatile uint32_t *)REG_MSI0_IMSK)                    /* MSI0 Interrupt Mask Register */
#define pREG_MSI0_CMDARG                 ((volatile uint32_t *)REG_MSI0_CMDARG)                  /* MSI0 Command Argument Register */
#define pREG_MSI0_CMD                    ((volatile uint32_t *)REG_MSI0_CMD)                     /* MSI0 Command Register */
#define pREG_MSI0_RESP0                  ((volatile uint32_t *)REG_MSI0_RESP0)                   /* MSI0 Response Register 0 */
#define pREG_MSI0_RESP1                  ((volatile uint32_t *)REG_MSI0_RESP1)                   /* MSI0 Response Register 1 */
#define pREG_MSI0_RESP2                  ((volatile uint32_t *)REG_MSI0_RESP2)                   /* MSI0 Response Register 2 */
#define pREG_MSI0_RESP3                  ((volatile uint32_t *)REG_MSI0_RESP3)                   /* MSI0 Response Register 3 */
#define pREG_MSI0_MSKISTAT               ((volatile uint32_t *)REG_MSI0_MSKISTAT)                /* MSI0 Masked Interrupt Status Register */
#define pREG_MSI0_ISTAT                  ((volatile uint32_t *)REG_MSI0_ISTAT)                   /* MSI0 Raw Interrupt Status Register */
#define pREG_MSI0_STAT                   ((volatile uint32_t *)REG_MSI0_STAT)                    /* MSI0 Status Register */
#define pREG_MSI0_FIFOTH                 ((volatile uint32_t *)REG_MSI0_FIFOTH)                  /* MSI0 FIFO Threshold Watermark Register */
#define pREG_MSI0_CDETECT                ((volatile uint32_t *)REG_MSI0_CDETECT)                 /* MSI0 Card Detect Register */
#define pREG_MSI0_TCBCNT                 ((volatile uint32_t *)REG_MSI0_TCBCNT)                  /* MSI0 Transferred CIU Card Byte Count Register */
#define pREG_MSI0_TBBCNT                 ((volatile uint32_t *)REG_MSI0_TBBCNT)                  /* MSI0 Transferred Host to BIU-FIFO Byte Count Register */
#define pREG_MSI0_DEBNCE                 ((volatile uint32_t *)REG_MSI0_DEBNCE)                  /* MSI0 Debounce Count Register */
#define pREG_MSI0_USRID                  ((volatile uint32_t *)REG_MSI0_USRID)                   /* MSI0 User ID Register */
#define pREG_MSI0_VERID                  ((volatile uint32_t *)REG_MSI0_VERID)                   /* MSI0 Version ID Register */
#define pREG_MSI0_HWCFG                  ((volatile uint32_t *)REG_MSI0_HWCFG)                   /* MSI0 Hardware Configuration Register */
#define pREG_MSI0_BUSMODE                ((volatile uint32_t *)REG_MSI0_BUSMODE)                 /* MSI0 Bus Mode Register */
#define pREG_MSI0_PLDMND                 ((volatile uint32_t *)REG_MSI0_PLDMND)                  /* MSI0 Poll Demand Register */
#define pREG_MSI0_DBADDR                 ((volatile uint32_t *)REG_MSI0_DBADDR)                  /* MSI0 Descriptor List Base Address Register */
#define pREG_MSI0_IDSTS                  ((volatile uint32_t *)REG_MSI0_IDSTS)                   /* MSI0 Internal DMA Status Register */
#define pREG_MSI0_IDINTEN                ((volatile uint32_t *)REG_MSI0_IDINTEN)                 /* MSI0 Internal DMA Interrupt Enable Register */
#define pREG_MSI0_DSCADDR                ((volatile uint32_t *)REG_MSI0_DSCADDR)                 /* MSI0 Current Host Descriptor Address Register */
#define pREG_MSI0_BUFADDR                ((volatile uint32_t *)REG_MSI0_BUFADDR)                 /* MSI0 Current Buffer Descriptor Address Register */
#define pREG_MSI0_CDTHRCTL               ((volatile uint32_t *)REG_MSI0_CDTHRCTL)                /* MSI0 Card Threshold Control Register */
#define pREG_MSI0_ENSHIFT                ((volatile uint32_t *)REG_MSI0_ENSHIFT)                 /* MSI0 Register to control the amount of shift on enables */


/* =========================================================================
       DMA0
   ========================================================================= */
#define pREG_DMA0_DSCPTR_NXT             ((void * volatile *)REG_DMA0_DSCPTR_NXT)                /* DMA0 Pointer to Next Initial Descriptor */
#define pREG_DMA0_ADDRSTART              ((void * volatile *)REG_DMA0_ADDRSTART)                 /* DMA0 Start Address of Current Buffer */
#define pREG_DMA0_CFG                    ((volatile uint32_t *)REG_DMA0_CFG)                     /* DMA0 Configuration Register */
#define pREG_DMA0_XCNT                   ((volatile uint32_t *)REG_DMA0_XCNT)                    /* DMA0 Inner Loop Count Start Value */
#define pREG_DMA0_XMOD                   ((volatile  int32_t *)REG_DMA0_XMOD)                    /* DMA0 Inner Loop Address Increment */
#define pREG_DMA0_YCNT                   ((volatile uint32_t *)REG_DMA0_YCNT)                    /* DMA0 Outer Loop Count Start Value (2D only) */
#define pREG_DMA0_YMOD                   ((volatile  int32_t *)REG_DMA0_YMOD)                    /* DMA0 Outer Loop Address Increment (2D only) */
#define pREG_DMA0_DSCPTR_CUR             ((void * volatile *)REG_DMA0_DSCPTR_CUR)                /* DMA0 Current Descriptor Pointer */
#define pREG_DMA0_DSCPTR_PRV             ((void * volatile *)REG_DMA0_DSCPTR_PRV)                /* DMA0 Previous Initial Descriptor Pointer */
#define pREG_DMA0_ADDR_CUR               ((void * volatile *)REG_DMA0_ADDR_CUR)                  /* DMA0 Current Address */
#define pREG_DMA0_STAT                   ((volatile uint32_t *)REG_DMA0_STAT)                    /* DMA0 Status Register */
#define pREG_DMA0_XCNT_CUR               ((volatile uint32_t *)REG_DMA0_XCNT_CUR)                /* DMA0 Current Count(1D) or intra-row XCNT (2D) */
#define pREG_DMA0_YCNT_CUR               ((volatile uint32_t *)REG_DMA0_YCNT_CUR)                /* DMA0 Current Row Count (2D only) */

/* =========================================================================
       DMA1
   ========================================================================= */
#define pREG_DMA1_DSCPTR_NXT             ((void * volatile *)REG_DMA1_DSCPTR_NXT)                /* DMA1 Pointer to Next Initial Descriptor */
#define pREG_DMA1_ADDRSTART              ((void * volatile *)REG_DMA1_ADDRSTART)                 /* DMA1 Start Address of Current Buffer */
#define pREG_DMA1_CFG                    ((volatile uint32_t *)REG_DMA1_CFG)                     /* DMA1 Configuration Register */
#define pREG_DMA1_XCNT                   ((volatile uint32_t *)REG_DMA1_XCNT)                    /* DMA1 Inner Loop Count Start Value */
#define pREG_DMA1_XMOD                   ((volatile  int32_t *)REG_DMA1_XMOD)                    /* DMA1 Inner Loop Address Increment */
#define pREG_DMA1_YCNT                   ((volatile uint32_t *)REG_DMA1_YCNT)                    /* DMA1 Outer Loop Count Start Value (2D only) */
#define pREG_DMA1_YMOD                   ((volatile  int32_t *)REG_DMA1_YMOD)                    /* DMA1 Outer Loop Address Increment (2D only) */
#define pREG_DMA1_DSCPTR_CUR             ((void * volatile *)REG_DMA1_DSCPTR_CUR)                /* DMA1 Current Descriptor Pointer */
#define pREG_DMA1_DSCPTR_PRV             ((void * volatile *)REG_DMA1_DSCPTR_PRV)                /* DMA1 Previous Initial Descriptor Pointer */
#define pREG_DMA1_ADDR_CUR               ((void * volatile *)REG_DMA1_ADDR_CUR)                  /* DMA1 Current Address */
#define pREG_DMA1_STAT                   ((volatile uint32_t *)REG_DMA1_STAT)                    /* DMA1 Status Register */
#define pREG_DMA1_XCNT_CUR               ((volatile uint32_t *)REG_DMA1_XCNT_CUR)                /* DMA1 Current Count(1D) or intra-row XCNT (2D) */
#define pREG_DMA1_YCNT_CUR               ((volatile uint32_t *)REG_DMA1_YCNT_CUR)                /* DMA1 Current Row Count (2D only) */

/* =========================================================================
       DMA2
   ========================================================================= */
#define pREG_DMA2_DSCPTR_NXT             ((void * volatile *)REG_DMA2_DSCPTR_NXT)                /* DMA2 Pointer to Next Initial Descriptor */
#define pREG_DMA2_ADDRSTART              ((void * volatile *)REG_DMA2_ADDRSTART)                 /* DMA2 Start Address of Current Buffer */
#define pREG_DMA2_CFG                    ((volatile uint32_t *)REG_DMA2_CFG)                     /* DMA2 Configuration Register */
#define pREG_DMA2_XCNT                   ((volatile uint32_t *)REG_DMA2_XCNT)                    /* DMA2 Inner Loop Count Start Value */
#define pREG_DMA2_XMOD                   ((volatile  int32_t *)REG_DMA2_XMOD)                    /* DMA2 Inner Loop Address Increment */
#define pREG_DMA2_YCNT                   ((volatile uint32_t *)REG_DMA2_YCNT)                    /* DMA2 Outer Loop Count Start Value (2D only) */
#define pREG_DMA2_YMOD                   ((volatile  int32_t *)REG_DMA2_YMOD)                    /* DMA2 Outer Loop Address Increment (2D only) */
#define pREG_DMA2_DSCPTR_CUR             ((void * volatile *)REG_DMA2_DSCPTR_CUR)                /* DMA2 Current Descriptor Pointer */
#define pREG_DMA2_DSCPTR_PRV             ((void * volatile *)REG_DMA2_DSCPTR_PRV)                /* DMA2 Previous Initial Descriptor Pointer */
#define pREG_DMA2_ADDR_CUR               ((void * volatile *)REG_DMA2_ADDR_CUR)                  /* DMA2 Current Address */
#define pREG_DMA2_STAT                   ((volatile uint32_t *)REG_DMA2_STAT)                    /* DMA2 Status Register */
#define pREG_DMA2_XCNT_CUR               ((volatile uint32_t *)REG_DMA2_XCNT_CUR)                /* DMA2 Current Count(1D) or intra-row XCNT (2D) */
#define pREG_DMA2_YCNT_CUR               ((volatile uint32_t *)REG_DMA2_YCNT_CUR)                /* DMA2 Current Row Count (2D only) */

/* =========================================================================
       DMA3
   ========================================================================= */
#define pREG_DMA3_DSCPTR_NXT             ((void * volatile *)REG_DMA3_DSCPTR_NXT)                /* DMA3 Pointer to Next Initial Descriptor */
#define pREG_DMA3_ADDRSTART              ((void * volatile *)REG_DMA3_ADDRSTART)                 /* DMA3 Start Address of Current Buffer */
#define pREG_DMA3_CFG                    ((volatile uint32_t *)REG_DMA3_CFG)                     /* DMA3 Configuration Register */
#define pREG_DMA3_XCNT                   ((volatile uint32_t *)REG_DMA3_XCNT)                    /* DMA3 Inner Loop Count Start Value */
#define pREG_DMA3_XMOD                   ((volatile  int32_t *)REG_DMA3_XMOD)                    /* DMA3 Inner Loop Address Increment */
#define pREG_DMA3_YCNT                   ((volatile uint32_t *)REG_DMA3_YCNT)                    /* DMA3 Outer Loop Count Start Value (2D only) */
#define pREG_DMA3_YMOD                   ((volatile  int32_t *)REG_DMA3_YMOD)                    /* DMA3 Outer Loop Address Increment (2D only) */
#define pREG_DMA3_DSCPTR_CUR             ((void * volatile *)REG_DMA3_DSCPTR_CUR)                /* DMA3 Current Descriptor Pointer */
#define pREG_DMA3_DSCPTR_PRV             ((void * volatile *)REG_DMA3_DSCPTR_PRV)                /* DMA3 Previous Initial Descriptor Pointer */
#define pREG_DMA3_ADDR_CUR               ((void * volatile *)REG_DMA3_ADDR_CUR)                  /* DMA3 Current Address */
#define pREG_DMA3_STAT                   ((volatile uint32_t *)REG_DMA3_STAT)                    /* DMA3 Status Register */
#define pREG_DMA3_XCNT_CUR               ((volatile uint32_t *)REG_DMA3_XCNT_CUR)                /* DMA3 Current Count(1D) or intra-row XCNT (2D) */
#define pREG_DMA3_YCNT_CUR               ((volatile uint32_t *)REG_DMA3_YCNT_CUR)                /* DMA3 Current Row Count (2D only) */

/* =========================================================================
       DMA4
   ========================================================================= */
#define pREG_DMA4_DSCPTR_NXT             ((void * volatile *)REG_DMA4_DSCPTR_NXT)                /* DMA4 Pointer to Next Initial Descriptor */
#define pREG_DMA4_ADDRSTART              ((void * volatile *)REG_DMA4_ADDRSTART)                 /* DMA4 Start Address of Current Buffer */
#define pREG_DMA4_CFG                    ((volatile uint32_t *)REG_DMA4_CFG)                     /* DMA4 Configuration Register */
#define pREG_DMA4_XCNT                   ((volatile uint32_t *)REG_DMA4_XCNT)                    /* DMA4 Inner Loop Count Start Value */
#define pREG_DMA4_XMOD                   ((volatile  int32_t *)REG_DMA4_XMOD)                    /* DMA4 Inner Loop Address Increment */
#define pREG_DMA4_YCNT                   ((volatile uint32_t *)REG_DMA4_YCNT)                    /* DMA4 Outer Loop Count Start Value (2D only) */
#define pREG_DMA4_YMOD                   ((volatile  int32_t *)REG_DMA4_YMOD)                    /* DMA4 Outer Loop Address Increment (2D only) */
#define pREG_DMA4_DSCPTR_CUR             ((void * volatile *)REG_DMA4_DSCPTR_CUR)                /* DMA4 Current Descriptor Pointer */
#define pREG_DMA4_DSCPTR_PRV             ((void * volatile *)REG_DMA4_DSCPTR_PRV)                /* DMA4 Previous Initial Descriptor Pointer */
#define pREG_DMA4_ADDR_CUR               ((void * volatile *)REG_DMA4_ADDR_CUR)                  /* DMA4 Current Address */
#define pREG_DMA4_STAT                   ((volatile uint32_t *)REG_DMA4_STAT)                    /* DMA4 Status Register */
#define pREG_DMA4_XCNT_CUR               ((volatile uint32_t *)REG_DMA4_XCNT_CUR)                /* DMA4 Current Count(1D) or intra-row XCNT (2D) */
#define pREG_DMA4_YCNT_CUR               ((volatile uint32_t *)REG_DMA4_YCNT_CUR)                /* DMA4 Current Row Count (2D only) */

/* =========================================================================
       DMA5
   ========================================================================= */
#define pREG_DMA5_DSCPTR_NXT             ((void * volatile *)REG_DMA5_DSCPTR_NXT)                /* DMA5 Pointer to Next Initial Descriptor */
#define pREG_DMA5_ADDRSTART              ((void * volatile *)REG_DMA5_ADDRSTART)                 /* DMA5 Start Address of Current Buffer */
#define pREG_DMA5_CFG                    ((volatile uint32_t *)REG_DMA5_CFG)                     /* DMA5 Configuration Register */
#define pREG_DMA5_XCNT                   ((volatile uint32_t *)REG_DMA5_XCNT)                    /* DMA5 Inner Loop Count Start Value */
#define pREG_DMA5_XMOD                   ((volatile  int32_t *)REG_DMA5_XMOD)                    /* DMA5 Inner Loop Address Increment */
#define pREG_DMA5_YCNT                   ((volatile uint32_t *)REG_DMA5_YCNT)                    /* DMA5 Outer Loop Count Start Value (2D only) */
#define pREG_DMA5_YMOD                   ((volatile  int32_t *)REG_DMA5_YMOD)                    /* DMA5 Outer Loop Address Increment (2D only) */
#define pREG_DMA5_DSCPTR_CUR             ((void * volatile *)REG_DMA5_DSCPTR_CUR)                /* DMA5 Current Descriptor Pointer */
#define pREG_DMA5_DSCPTR_PRV             ((void * volatile *)REG_DMA5_DSCPTR_PRV)                /* DMA5 Previous Initial Descriptor Pointer */
#define pREG_DMA5_ADDR_CUR               ((void * volatile *)REG_DMA5_ADDR_CUR)                  /* DMA5 Current Address */
#define pREG_DMA5_STAT                   ((volatile uint32_t *)REG_DMA5_STAT)                    /* DMA5 Status Register */
#define pREG_DMA5_XCNT_CUR               ((volatile uint32_t *)REG_DMA5_XCNT_CUR)                /* DMA5 Current Count(1D) or intra-row XCNT (2D) */
#define pREG_DMA5_YCNT_CUR               ((volatile uint32_t *)REG_DMA5_YCNT_CUR)                /* DMA5 Current Row Count (2D only) */

/* =========================================================================
       DMA6
   ========================================================================= */
#define pREG_DMA6_DSCPTR_NXT             ((void * volatile *)REG_DMA6_DSCPTR_NXT)                /* DMA6 Pointer to Next Initial Descriptor */
#define pREG_DMA6_ADDRSTART              ((void * volatile *)REG_DMA6_ADDRSTART)                 /* DMA6 Start Address of Current Buffer */
#define pREG_DMA6_CFG                    ((volatile uint32_t *)REG_DMA6_CFG)                     /* DMA6 Configuration Register */
#define pREG_DMA6_XCNT                   ((volatile uint32_t *)REG_DMA6_XCNT)                    /* DMA6 Inner Loop Count Start Value */
#define pREG_DMA6_XMOD                   ((volatile  int32_t *)REG_DMA6_XMOD)                    /* DMA6 Inner Loop Address Increment */
#define pREG_DMA6_YCNT                   ((volatile uint32_t *)REG_DMA6_YCNT)                    /* DMA6 Outer Loop Count Start Value (2D only) */
#define pREG_DMA6_YMOD                   ((volatile  int32_t *)REG_DMA6_YMOD)                    /* DMA6 Outer Loop Address Increment (2D only) */
#define pREG_DMA6_DSCPTR_CUR             ((void * volatile *)REG_DMA6_DSCPTR_CUR)                /* DMA6 Current Descriptor Pointer */
#define pREG_DMA6_DSCPTR_PRV             ((void * volatile *)REG_DMA6_DSCPTR_PRV)                /* DMA6 Previous Initial Descriptor Pointer */
#define pREG_DMA6_ADDR_CUR               ((void * volatile *)REG_DMA6_ADDR_CUR)                  /* DMA6 Current Address */
#define pREG_DMA6_STAT                   ((volatile uint32_t *)REG_DMA6_STAT)                    /* DMA6 Status Register */
#define pREG_DMA6_XCNT_CUR               ((volatile uint32_t *)REG_DMA6_XCNT_CUR)                /* DMA6 Current Count(1D) or intra-row XCNT (2D) */
#define pREG_DMA6_YCNT_CUR               ((volatile uint32_t *)REG_DMA6_YCNT_CUR)                /* DMA6 Current Row Count (2D only) */

/* =========================================================================
       DMA7
   ========================================================================= */
#define pREG_DMA7_DSCPTR_NXT             ((void * volatile *)REG_DMA7_DSCPTR_NXT)                /* DMA7 Pointer to Next Initial Descriptor */
#define pREG_DMA7_ADDRSTART              ((void * volatile *)REG_DMA7_ADDRSTART)                 /* DMA7 Start Address of Current Buffer */
#define pREG_DMA7_CFG                    ((volatile uint32_t *)REG_DMA7_CFG)                     /* DMA7 Configuration Register */
#define pREG_DMA7_XCNT                   ((volatile uint32_t *)REG_DMA7_XCNT)                    /* DMA7 Inner Loop Count Start Value */
#define pREG_DMA7_XMOD                   ((volatile  int32_t *)REG_DMA7_XMOD)                    /* DMA7 Inner Loop Address Increment */
#define pREG_DMA7_YCNT                   ((volatile uint32_t *)REG_DMA7_YCNT)                    /* DMA7 Outer Loop Count Start Value (2D only) */
#define pREG_DMA7_YMOD                   ((volatile  int32_t *)REG_DMA7_YMOD)                    /* DMA7 Outer Loop Address Increment (2D only) */
#define pREG_DMA7_DSCPTR_CUR             ((void * volatile *)REG_DMA7_DSCPTR_CUR)                /* DMA7 Current Descriptor Pointer */
#define pREG_DMA7_DSCPTR_PRV             ((void * volatile *)REG_DMA7_DSCPTR_PRV)                /* DMA7 Previous Initial Descriptor Pointer */
#define pREG_DMA7_ADDR_CUR               ((void * volatile *)REG_DMA7_ADDR_CUR)                  /* DMA7 Current Address */
#define pREG_DMA7_STAT                   ((volatile uint32_t *)REG_DMA7_STAT)                    /* DMA7 Status Register */
#define pREG_DMA7_XCNT_CUR               ((volatile uint32_t *)REG_DMA7_XCNT_CUR)                /* DMA7 Current Count(1D) or intra-row XCNT (2D) */
#define pREG_DMA7_YCNT_CUR               ((volatile uint32_t *)REG_DMA7_YCNT_CUR)                /* DMA7 Current Row Count (2D only) */

/* =========================================================================
       DMA8
   ========================================================================= */
#define pREG_DMA8_DSCPTR_NXT             ((void * volatile *)REG_DMA8_DSCPTR_NXT)                /* DMA8 Pointer to Next Initial Descriptor */
#define pREG_DMA8_ADDRSTART              ((void * volatile *)REG_DMA8_ADDRSTART)                 /* DMA8 Start Address of Current Buffer */
#define pREG_DMA8_CFG                    ((volatile uint32_t *)REG_DMA8_CFG)                     /* DMA8 Configuration Register */
#define pREG_DMA8_XCNT                   ((volatile uint32_t *)REG_DMA8_XCNT)                    /* DMA8 Inner Loop Count Start Value */
#define pREG_DMA8_XMOD                   ((volatile  int32_t *)REG_DMA8_XMOD)                    /* DMA8 Inner Loop Address Increment */
#define pREG_DMA8_YCNT                   ((volatile uint32_t *)REG_DMA8_YCNT)                    /* DMA8 Outer Loop Count Start Value (2D only) */
#define pREG_DMA8_YMOD                   ((volatile  int32_t *)REG_DMA8_YMOD)                    /* DMA8 Outer Loop Address Increment (2D only) */
#define pREG_DMA8_DSCPTR_CUR             ((void * volatile *)REG_DMA8_DSCPTR_CUR)                /* DMA8 Current Descriptor Pointer */
#define pREG_DMA8_DSCPTR_PRV             ((void * volatile *)REG_DMA8_DSCPTR_PRV)                /* DMA8 Previous Initial Descriptor Pointer */
#define pREG_DMA8_ADDR_CUR               ((void * volatile *)REG_DMA8_ADDR_CUR)                  /* DMA8 Current Address */
#define pREG_DMA8_STAT                   ((volatile uint32_t *)REG_DMA8_STAT)                    /* DMA8 Status Register */
#define pREG_DMA8_XCNT_CUR               ((volatile uint32_t *)REG_DMA8_XCNT_CUR)                /* DMA8 Current Count(1D) or intra-row XCNT (2D) */
#define pREG_DMA8_YCNT_CUR               ((volatile uint32_t *)REG_DMA8_YCNT_CUR)                /* DMA8 Current Row Count (2D only) */

/* =========================================================================
       DMA9
   ========================================================================= */
#define pREG_DMA9_DSCPTR_NXT             ((void * volatile *)REG_DMA9_DSCPTR_NXT)                /* DMA9 Pointer to Next Initial Descriptor */
#define pREG_DMA9_ADDRSTART              ((void * volatile *)REG_DMA9_ADDRSTART)                 /* DMA9 Start Address of Current Buffer */
#define pREG_DMA9_CFG                    ((volatile uint32_t *)REG_DMA9_CFG)                     /* DMA9 Configuration Register */
#define pREG_DMA9_XCNT                   ((volatile uint32_t *)REG_DMA9_XCNT)                    /* DMA9 Inner Loop Count Start Value */
#define pREG_DMA9_XMOD                   ((volatile  int32_t *)REG_DMA9_XMOD)                    /* DMA9 Inner Loop Address Increment */
#define pREG_DMA9_YCNT                   ((volatile uint32_t *)REG_DMA9_YCNT)                    /* DMA9 Outer Loop Count Start Value (2D only) */
#define pREG_DMA9_YMOD                   ((volatile  int32_t *)REG_DMA9_YMOD)                    /* DMA9 Outer Loop Address Increment (2D only) */
#define pREG_DMA9_DSCPTR_CUR             ((void * volatile *)REG_DMA9_DSCPTR_CUR)                /* DMA9 Current Descriptor Pointer */
#define pREG_DMA9_DSCPTR_PRV             ((void * volatile *)REG_DMA9_DSCPTR_PRV)                /* DMA9 Previous Initial Descriptor Pointer */
#define pREG_DMA9_ADDR_CUR               ((void * volatile *)REG_DMA9_ADDR_CUR)                  /* DMA9 Current Address */
#define pREG_DMA9_STAT                   ((volatile uint32_t *)REG_DMA9_STAT)                    /* DMA9 Status Register */
#define pREG_DMA9_XCNT_CUR               ((volatile uint32_t *)REG_DMA9_XCNT_CUR)                /* DMA9 Current Count(1D) or intra-row XCNT (2D) */
#define pREG_DMA9_YCNT_CUR               ((volatile uint32_t *)REG_DMA9_YCNT_CUR)                /* DMA9 Current Row Count (2D only) */

/* =========================================================================
       DMA10
   ========================================================================= */
#define pREG_DMA10_DSCPTR_NXT            ((void * volatile *)REG_DMA10_DSCPTR_NXT)               /* DMA10 Pointer to Next Initial Descriptor */
#define pREG_DMA10_ADDRSTART             ((void * volatile *)REG_DMA10_ADDRSTART)                /* DMA10 Start Address of Current Buffer */
#define pREG_DMA10_CFG                   ((volatile uint32_t *)REG_DMA10_CFG)                    /* DMA10 Configuration Register */
#define pREG_DMA10_XCNT                  ((volatile uint32_t *)REG_DMA10_XCNT)                   /* DMA10 Inner Loop Count Start Value */
#define pREG_DMA10_XMOD                  ((volatile  int32_t *)REG_DMA10_XMOD)                   /* DMA10 Inner Loop Address Increment */
#define pREG_DMA10_YCNT                  ((volatile uint32_t *)REG_DMA10_YCNT)                   /* DMA10 Outer Loop Count Start Value (2D only) */
#define pREG_DMA10_YMOD                  ((volatile  int32_t *)REG_DMA10_YMOD)                   /* DMA10 Outer Loop Address Increment (2D only) */
#define pREG_DMA10_DSCPTR_CUR            ((void * volatile *)REG_DMA10_DSCPTR_CUR)               /* DMA10 Current Descriptor Pointer */
#define pREG_DMA10_DSCPTR_PRV            ((void * volatile *)REG_DMA10_DSCPTR_PRV)               /* DMA10 Previous Initial Descriptor Pointer */
#define pREG_DMA10_ADDR_CUR              ((void * volatile *)REG_DMA10_ADDR_CUR)                 /* DMA10 Current Address */
#define pREG_DMA10_STAT                  ((volatile uint32_t *)REG_DMA10_STAT)                   /* DMA10 Status Register */
#define pREG_DMA10_XCNT_CUR              ((volatile uint32_t *)REG_DMA10_XCNT_CUR)               /* DMA10 Current Count(1D) or intra-row XCNT (2D) */
#define pREG_DMA10_YCNT_CUR              ((volatile uint32_t *)REG_DMA10_YCNT_CUR)               /* DMA10 Current Row Count (2D only) */

/* =========================================================================
       DMA11
   ========================================================================= */
#define pREG_DMA11_DSCPTR_NXT            ((void * volatile *)REG_DMA11_DSCPTR_NXT)               /* DMA11 Pointer to Next Initial Descriptor */
#define pREG_DMA11_ADDRSTART             ((void * volatile *)REG_DMA11_ADDRSTART)                /* DMA11 Start Address of Current Buffer */
#define pREG_DMA11_CFG                   ((volatile uint32_t *)REG_DMA11_CFG)                    /* DMA11 Configuration Register */
#define pREG_DMA11_XCNT                  ((volatile uint32_t *)REG_DMA11_XCNT)                   /* DMA11 Inner Loop Count Start Value */
#define pREG_DMA11_XMOD                  ((volatile  int32_t *)REG_DMA11_XMOD)                   /* DMA11 Inner Loop Address Increment */
#define pREG_DMA11_YCNT                  ((volatile uint32_t *)REG_DMA11_YCNT)                   /* DMA11 Outer Loop Count Start Value (2D only) */
#define pREG_DMA11_YMOD                  ((volatile  int32_t *)REG_DMA11_YMOD)                   /* DMA11 Outer Loop Address Increment (2D only) */
#define pREG_DMA11_DSCPTR_CUR            ((void * volatile *)REG_DMA11_DSCPTR_CUR)               /* DMA11 Current Descriptor Pointer */
#define pREG_DMA11_DSCPTR_PRV            ((void * volatile *)REG_DMA11_DSCPTR_PRV)               /* DMA11 Previous Initial Descriptor Pointer */
#define pREG_DMA11_ADDR_CUR              ((void * volatile *)REG_DMA11_ADDR_CUR)                 /* DMA11 Current Address */
#define pREG_DMA11_STAT                  ((volatile uint32_t *)REG_DMA11_STAT)                   /* DMA11 Status Register */
#define pREG_DMA11_XCNT_CUR              ((volatile uint32_t *)REG_DMA11_XCNT_CUR)               /* DMA11 Current Count(1D) or intra-row XCNT (2D) */
#define pREG_DMA11_YCNT_CUR              ((volatile uint32_t *)REG_DMA11_YCNT_CUR)               /* DMA11 Current Row Count (2D only) */

/* =========================================================================
       DMA12
   ========================================================================= */
#define pREG_DMA12_DSCPTR_NXT            ((void * volatile *)REG_DMA12_DSCPTR_NXT)               /* DMA12 Pointer to Next Initial Descriptor */
#define pREG_DMA12_ADDRSTART             ((void * volatile *)REG_DMA12_ADDRSTART)                /* DMA12 Start Address of Current Buffer */
#define pREG_DMA12_CFG                   ((volatile uint32_t *)REG_DMA12_CFG)                    /* DMA12 Configuration Register */
#define pREG_DMA12_XCNT                  ((volatile uint32_t *)REG_DMA12_XCNT)                   /* DMA12 Inner Loop Count Start Value */
#define pREG_DMA12_XMOD                  ((volatile  int32_t *)REG_DMA12_XMOD)                   /* DMA12 Inner Loop Address Increment */
#define pREG_DMA12_YCNT                  ((volatile uint32_t *)REG_DMA12_YCNT)                   /* DMA12 Outer Loop Count Start Value (2D only) */
#define pREG_DMA12_YMOD                  ((volatile  int32_t *)REG_DMA12_YMOD)                   /* DMA12 Outer Loop Address Increment (2D only) */
#define pREG_DMA12_DSCPTR_CUR            ((void * volatile *)REG_DMA12_DSCPTR_CUR)               /* DMA12 Current Descriptor Pointer */
#define pREG_DMA12_DSCPTR_PRV            ((void * volatile *)REG_DMA12_DSCPTR_PRV)               /* DMA12 Previous Initial Descriptor Pointer */
#define pREG_DMA12_ADDR_CUR              ((void * volatile *)REG_DMA12_ADDR_CUR)                 /* DMA12 Current Address */
#define pREG_DMA12_STAT                  ((volatile uint32_t *)REG_DMA12_STAT)                   /* DMA12 Status Register */
#define pREG_DMA12_XCNT_CUR              ((volatile uint32_t *)REG_DMA12_XCNT_CUR)               /* DMA12 Current Count(1D) or intra-row XCNT (2D) */
#define pREG_DMA12_YCNT_CUR              ((volatile uint32_t *)REG_DMA12_YCNT_CUR)               /* DMA12 Current Row Count (2D only) */

/* =========================================================================
       DMA13
   ========================================================================= */
#define pREG_DMA13_DSCPTR_NXT            ((void * volatile *)REG_DMA13_DSCPTR_NXT)               /* DMA13 Pointer to Next Initial Descriptor */
#define pREG_DMA13_ADDRSTART             ((void * volatile *)REG_DMA13_ADDRSTART)                /* DMA13 Start Address of Current Buffer */
#define pREG_DMA13_CFG                   ((volatile uint32_t *)REG_DMA13_CFG)                    /* DMA13 Configuration Register */
#define pREG_DMA13_XCNT                  ((volatile uint32_t *)REG_DMA13_XCNT)                   /* DMA13 Inner Loop Count Start Value */
#define pREG_DMA13_XMOD                  ((volatile  int32_t *)REG_DMA13_XMOD)                   /* DMA13 Inner Loop Address Increment */
#define pREG_DMA13_YCNT                  ((volatile uint32_t *)REG_DMA13_YCNT)                   /* DMA13 Outer Loop Count Start Value (2D only) */
#define pREG_DMA13_YMOD                  ((volatile  int32_t *)REG_DMA13_YMOD)                   /* DMA13 Outer Loop Address Increment (2D only) */
#define pREG_DMA13_DSCPTR_CUR            ((void * volatile *)REG_DMA13_DSCPTR_CUR)               /* DMA13 Current Descriptor Pointer */
#define pREG_DMA13_DSCPTR_PRV            ((void * volatile *)REG_DMA13_DSCPTR_PRV)               /* DMA13 Previous Initial Descriptor Pointer */
#define pREG_DMA13_ADDR_CUR              ((void * volatile *)REG_DMA13_ADDR_CUR)                 /* DMA13 Current Address */
#define pREG_DMA13_STAT                  ((volatile uint32_t *)REG_DMA13_STAT)                   /* DMA13 Status Register */
#define pREG_DMA13_XCNT_CUR              ((volatile uint32_t *)REG_DMA13_XCNT_CUR)               /* DMA13 Current Count(1D) or intra-row XCNT (2D) */
#define pREG_DMA13_YCNT_CUR              ((volatile uint32_t *)REG_DMA13_YCNT_CUR)               /* DMA13 Current Row Count (2D only) */

/* =========================================================================
       DMA14
   ========================================================================= */
#define pREG_DMA14_DSCPTR_NXT            ((void * volatile *)REG_DMA14_DSCPTR_NXT)               /* DMA14 Pointer to Next Initial Descriptor */
#define pREG_DMA14_ADDRSTART             ((void * volatile *)REG_DMA14_ADDRSTART)                /* DMA14 Start Address of Current Buffer */
#define pREG_DMA14_CFG                   ((volatile uint32_t *)REG_DMA14_CFG)                    /* DMA14 Configuration Register */
#define pREG_DMA14_XCNT                  ((volatile uint32_t *)REG_DMA14_XCNT)                   /* DMA14 Inner Loop Count Start Value */
#define pREG_DMA14_XMOD                  ((volatile  int32_t *)REG_DMA14_XMOD)                   /* DMA14 Inner Loop Address Increment */
#define pREG_DMA14_YCNT                  ((volatile uint32_t *)REG_DMA14_YCNT)                   /* DMA14 Outer Loop Count Start Value (2D only) */
#define pREG_DMA14_YMOD                  ((volatile  int32_t *)REG_DMA14_YMOD)                   /* DMA14 Outer Loop Address Increment (2D only) */
#define pREG_DMA14_DSCPTR_CUR            ((void * volatile *)REG_DMA14_DSCPTR_CUR)               /* DMA14 Current Descriptor Pointer */
#define pREG_DMA14_DSCPTR_PRV            ((void * volatile *)REG_DMA14_DSCPTR_PRV)               /* DMA14 Previous Initial Descriptor Pointer */
#define pREG_DMA14_ADDR_CUR              ((void * volatile *)REG_DMA14_ADDR_CUR)                 /* DMA14 Current Address */
#define pREG_DMA14_STAT                  ((volatile uint32_t *)REG_DMA14_STAT)                   /* DMA14 Status Register */
#define pREG_DMA14_XCNT_CUR              ((volatile uint32_t *)REG_DMA14_XCNT_CUR)               /* DMA14 Current Count(1D) or intra-row XCNT (2D) */
#define pREG_DMA14_YCNT_CUR              ((volatile uint32_t *)REG_DMA14_YCNT_CUR)               /* DMA14 Current Row Count (2D only) */

/* =========================================================================
       DMA15
   ========================================================================= */
#define pREG_DMA15_DSCPTR_NXT            ((void * volatile *)REG_DMA15_DSCPTR_NXT)               /* DMA15 Pointer to Next Initial Descriptor */
#define pREG_DMA15_ADDRSTART             ((void * volatile *)REG_DMA15_ADDRSTART)                /* DMA15 Start Address of Current Buffer */
#define pREG_DMA15_CFG                   ((volatile uint32_t *)REG_DMA15_CFG)                    /* DMA15 Configuration Register */
#define pREG_DMA15_XCNT                  ((volatile uint32_t *)REG_DMA15_XCNT)                   /* DMA15 Inner Loop Count Start Value */
#define pREG_DMA15_XMOD                  ((volatile  int32_t *)REG_DMA15_XMOD)                   /* DMA15 Inner Loop Address Increment */
#define pREG_DMA15_YCNT                  ((volatile uint32_t *)REG_DMA15_YCNT)                   /* DMA15 Outer Loop Count Start Value (2D only) */
#define pREG_DMA15_YMOD                  ((volatile  int32_t *)REG_DMA15_YMOD)                   /* DMA15 Outer Loop Address Increment (2D only) */
#define pREG_DMA15_DSCPTR_CUR            ((void * volatile *)REG_DMA15_DSCPTR_CUR)               /* DMA15 Current Descriptor Pointer */
#define pREG_DMA15_DSCPTR_PRV            ((void * volatile *)REG_DMA15_DSCPTR_PRV)               /* DMA15 Previous Initial Descriptor Pointer */
#define pREG_DMA15_ADDR_CUR              ((void * volatile *)REG_DMA15_ADDR_CUR)                 /* DMA15 Current Address */
#define pREG_DMA15_STAT                  ((volatile uint32_t *)REG_DMA15_STAT)                   /* DMA15 Status Register */
#define pREG_DMA15_XCNT_CUR              ((volatile uint32_t *)REG_DMA15_XCNT_CUR)               /* DMA15 Current Count(1D) or intra-row XCNT (2D) */
#define pREG_DMA15_YCNT_CUR              ((volatile uint32_t *)REG_DMA15_YCNT_CUR)               /* DMA15 Current Row Count (2D only) */

/* =========================================================================
       DMA16
   ========================================================================= */
#define pREG_DMA16_DSCPTR_NXT            ((void * volatile *)REG_DMA16_DSCPTR_NXT)               /* DMA16 Pointer to Next Initial Descriptor */
#define pREG_DMA16_ADDRSTART             ((void * volatile *)REG_DMA16_ADDRSTART)                /* DMA16 Start Address of Current Buffer */
#define pREG_DMA16_CFG                   ((volatile uint32_t *)REG_DMA16_CFG)                    /* DMA16 Configuration Register */
#define pREG_DMA16_XCNT                  ((volatile uint32_t *)REG_DMA16_XCNT)                   /* DMA16 Inner Loop Count Start Value */
#define pREG_DMA16_XMOD                  ((volatile  int32_t *)REG_DMA16_XMOD)                   /* DMA16 Inner Loop Address Increment */
#define pREG_DMA16_YCNT                  ((volatile uint32_t *)REG_DMA16_YCNT)                   /* DMA16 Outer Loop Count Start Value (2D only) */
#define pREG_DMA16_YMOD                  ((volatile  int32_t *)REG_DMA16_YMOD)                   /* DMA16 Outer Loop Address Increment (2D only) */
#define pREG_DMA16_DSCPTR_CUR            ((void * volatile *)REG_DMA16_DSCPTR_CUR)               /* DMA16 Current Descriptor Pointer */
#define pREG_DMA16_DSCPTR_PRV            ((void * volatile *)REG_DMA16_DSCPTR_PRV)               /* DMA16 Previous Initial Descriptor Pointer */
#define pREG_DMA16_ADDR_CUR              ((void * volatile *)REG_DMA16_ADDR_CUR)                 /* DMA16 Current Address */
#define pREG_DMA16_STAT                  ((volatile uint32_t *)REG_DMA16_STAT)                   /* DMA16 Status Register */
#define pREG_DMA16_XCNT_CUR              ((volatile uint32_t *)REG_DMA16_XCNT_CUR)               /* DMA16 Current Count(1D) or intra-row XCNT (2D) */
#define pREG_DMA16_YCNT_CUR              ((volatile uint32_t *)REG_DMA16_YCNT_CUR)               /* DMA16 Current Row Count (2D only) */
#define pREG_DMA16_BWLCNT                ((volatile uint32_t *)REG_DMA16_BWLCNT)                 /* DMA16 Bandwidth Limit Count */
#define pREG_DMA16_BWLCNT_CUR            ((volatile uint32_t *)REG_DMA16_BWLCNT_CUR)             /* DMA16 Bandwidth Limit Count Current */
#define pREG_DMA16_BWMCNT                ((volatile uint32_t *)REG_DMA16_BWMCNT)                 /* DMA16 Bandwidth Monitor Count */
#define pREG_DMA16_BWMCNT_CUR            ((volatile uint32_t *)REG_DMA16_BWMCNT_CUR)             /* DMA16 Bandwidth Monitor Count Current */

/* =========================================================================
       DMA17
   ========================================================================= */
#define pREG_DMA17_DSCPTR_NXT            ((void * volatile *)REG_DMA17_DSCPTR_NXT)               /* DMA17 Pointer to Next Initial Descriptor */
#define pREG_DMA17_ADDRSTART             ((void * volatile *)REG_DMA17_ADDRSTART)                /* DMA17 Start Address of Current Buffer */
#define pREG_DMA17_CFG                   ((volatile uint32_t *)REG_DMA17_CFG)                    /* DMA17 Configuration Register */
#define pREG_DMA17_XCNT                  ((volatile uint32_t *)REG_DMA17_XCNT)                   /* DMA17 Inner Loop Count Start Value */
#define pREG_DMA17_XMOD                  ((volatile  int32_t *)REG_DMA17_XMOD)                   /* DMA17 Inner Loop Address Increment */
#define pREG_DMA17_YCNT                  ((volatile uint32_t *)REG_DMA17_YCNT)                   /* DMA17 Outer Loop Count Start Value (2D only) */
#define pREG_DMA17_YMOD                  ((volatile  int32_t *)REG_DMA17_YMOD)                   /* DMA17 Outer Loop Address Increment (2D only) */
#define pREG_DMA17_DSCPTR_CUR            ((void * volatile *)REG_DMA17_DSCPTR_CUR)               /* DMA17 Current Descriptor Pointer */
#define pREG_DMA17_DSCPTR_PRV            ((void * volatile *)REG_DMA17_DSCPTR_PRV)               /* DMA17 Previous Initial Descriptor Pointer */
#define pREG_DMA17_ADDR_CUR              ((void * volatile *)REG_DMA17_ADDR_CUR)                 /* DMA17 Current Address */
#define pREG_DMA17_STAT                  ((volatile uint32_t *)REG_DMA17_STAT)                   /* DMA17 Status Register */
#define pREG_DMA17_XCNT_CUR              ((volatile uint32_t *)REG_DMA17_XCNT_CUR)               /* DMA17 Current Count(1D) or intra-row XCNT (2D) */
#define pREG_DMA17_YCNT_CUR              ((volatile uint32_t *)REG_DMA17_YCNT_CUR)               /* DMA17 Current Row Count (2D only) */
#define pREG_DMA17_BWLCNT                ((volatile uint32_t *)REG_DMA17_BWLCNT)                 /* DMA17 Bandwidth Limit Count */
#define pREG_DMA17_BWLCNT_CUR            ((volatile uint32_t *)REG_DMA17_BWLCNT_CUR)             /* DMA17 Bandwidth Limit Count Current */
#define pREG_DMA17_BWMCNT                ((volatile uint32_t *)REG_DMA17_BWMCNT)                 /* DMA17 Bandwidth Monitor Count */
#define pREG_DMA17_BWMCNT_CUR            ((volatile uint32_t *)REG_DMA17_BWMCNT_CUR)             /* DMA17 Bandwidth Monitor Count Current */

/* =========================================================================
       DMA18
   ========================================================================= */
#define pREG_DMA18_DSCPTR_NXT            ((void * volatile *)REG_DMA18_DSCPTR_NXT)               /* DMA18 Pointer to Next Initial Descriptor */
#define pREG_DMA18_ADDRSTART             ((void * volatile *)REG_DMA18_ADDRSTART)                /* DMA18 Start Address of Current Buffer */
#define pREG_DMA18_CFG                   ((volatile uint32_t *)REG_DMA18_CFG)                    /* DMA18 Configuration Register */
#define pREG_DMA18_XCNT                  ((volatile uint32_t *)REG_DMA18_XCNT)                   /* DMA18 Inner Loop Count Start Value */
#define pREG_DMA18_XMOD                  ((volatile  int32_t *)REG_DMA18_XMOD)                   /* DMA18 Inner Loop Address Increment */
#define pREG_DMA18_YCNT                  ((volatile uint32_t *)REG_DMA18_YCNT)                   /* DMA18 Outer Loop Count Start Value (2D only) */
#define pREG_DMA18_YMOD                  ((volatile  int32_t *)REG_DMA18_YMOD)                   /* DMA18 Outer Loop Address Increment (2D only) */
#define pREG_DMA18_DSCPTR_CUR            ((void * volatile *)REG_DMA18_DSCPTR_CUR)               /* DMA18 Current Descriptor Pointer */
#define pREG_DMA18_DSCPTR_PRV            ((void * volatile *)REG_DMA18_DSCPTR_PRV)               /* DMA18 Previous Initial Descriptor Pointer */
#define pREG_DMA18_ADDR_CUR              ((void * volatile *)REG_DMA18_ADDR_CUR)                 /* DMA18 Current Address */
#define pREG_DMA18_STAT                  ((volatile uint32_t *)REG_DMA18_STAT)                   /* DMA18 Status Register */
#define pREG_DMA18_XCNT_CUR              ((volatile uint32_t *)REG_DMA18_XCNT_CUR)               /* DMA18 Current Count(1D) or intra-row XCNT (2D) */
#define pREG_DMA18_YCNT_CUR              ((volatile uint32_t *)REG_DMA18_YCNT_CUR)               /* DMA18 Current Row Count (2D only) */
#define pREG_DMA18_BWLCNT                ((volatile uint32_t *)REG_DMA18_BWLCNT)                 /* DMA18 Bandwidth Limit Count */
#define pREG_DMA18_BWLCNT_CUR            ((volatile uint32_t *)REG_DMA18_BWLCNT_CUR)             /* DMA18 Bandwidth Limit Count Current */
#define pREG_DMA18_BWMCNT                ((volatile uint32_t *)REG_DMA18_BWMCNT)                 /* DMA18 Bandwidth Monitor Count */
#define pREG_DMA18_BWMCNT_CUR            ((volatile uint32_t *)REG_DMA18_BWMCNT_CUR)             /* DMA18 Bandwidth Monitor Count Current */

/* =========================================================================
       DMA19
   ========================================================================= */
#define pREG_DMA19_DSCPTR_NXT            ((void * volatile *)REG_DMA19_DSCPTR_NXT)               /* DMA19 Pointer to Next Initial Descriptor */
#define pREG_DMA19_ADDRSTART             ((void * volatile *)REG_DMA19_ADDRSTART)                /* DMA19 Start Address of Current Buffer */
#define pREG_DMA19_CFG                   ((volatile uint32_t *)REG_DMA19_CFG)                    /* DMA19 Configuration Register */
#define pREG_DMA19_XCNT                  ((volatile uint32_t *)REG_DMA19_XCNT)                   /* DMA19 Inner Loop Count Start Value */
#define pREG_DMA19_XMOD                  ((volatile  int32_t *)REG_DMA19_XMOD)                   /* DMA19 Inner Loop Address Increment */
#define pREG_DMA19_YCNT                  ((volatile uint32_t *)REG_DMA19_YCNT)                   /* DMA19 Outer Loop Count Start Value (2D only) */
#define pREG_DMA19_YMOD                  ((volatile  int32_t *)REG_DMA19_YMOD)                   /* DMA19 Outer Loop Address Increment (2D only) */
#define pREG_DMA19_DSCPTR_CUR            ((void * volatile *)REG_DMA19_DSCPTR_CUR)               /* DMA19 Current Descriptor Pointer */
#define pREG_DMA19_DSCPTR_PRV            ((void * volatile *)REG_DMA19_DSCPTR_PRV)               /* DMA19 Previous Initial Descriptor Pointer */
#define pREG_DMA19_ADDR_CUR              ((void * volatile *)REG_DMA19_ADDR_CUR)                 /* DMA19 Current Address */
#define pREG_DMA19_STAT                  ((volatile uint32_t *)REG_DMA19_STAT)                   /* DMA19 Status Register */
#define pREG_DMA19_XCNT_CUR              ((volatile uint32_t *)REG_DMA19_XCNT_CUR)               /* DMA19 Current Count(1D) or intra-row XCNT (2D) */
#define pREG_DMA19_YCNT_CUR              ((volatile uint32_t *)REG_DMA19_YCNT_CUR)               /* DMA19 Current Row Count (2D only) */
#define pREG_DMA19_BWLCNT                ((volatile uint32_t *)REG_DMA19_BWLCNT)                 /* DMA19 Bandwidth Limit Count */
#define pREG_DMA19_BWLCNT_CUR            ((volatile uint32_t *)REG_DMA19_BWLCNT_CUR)             /* DMA19 Bandwidth Limit Count Current */
#define pREG_DMA19_BWMCNT                ((volatile uint32_t *)REG_DMA19_BWMCNT)                 /* DMA19 Bandwidth Monitor Count */
#define pREG_DMA19_BWMCNT_CUR            ((volatile uint32_t *)REG_DMA19_BWMCNT_CUR)             /* DMA19 Bandwidth Monitor Count Current */

/* =========================================================================
       DMA20
   ========================================================================= */
#define pREG_DMA20_DSCPTR_NXT            ((void * volatile *)REG_DMA20_DSCPTR_NXT)               /* DMA20 Pointer to Next Initial Descriptor */
#define pREG_DMA20_ADDRSTART             ((void * volatile *)REG_DMA20_ADDRSTART)                /* DMA20 Start Address of Current Buffer */
#define pREG_DMA20_CFG                   ((volatile uint32_t *)REG_DMA20_CFG)                    /* DMA20 Configuration Register */
#define pREG_DMA20_XCNT                  ((volatile uint32_t *)REG_DMA20_XCNT)                   /* DMA20 Inner Loop Count Start Value */
#define pREG_DMA20_XMOD                  ((volatile  int32_t *)REG_DMA20_XMOD)                   /* DMA20 Inner Loop Address Increment */
#define pREG_DMA20_YCNT                  ((volatile uint32_t *)REG_DMA20_YCNT)                   /* DMA20 Outer Loop Count Start Value (2D only) */
#define pREG_DMA20_YMOD                  ((volatile  int32_t *)REG_DMA20_YMOD)                   /* DMA20 Outer Loop Address Increment (2D only) */
#define pREG_DMA20_DSCPTR_CUR            ((void * volatile *)REG_DMA20_DSCPTR_CUR)               /* DMA20 Current Descriptor Pointer */
#define pREG_DMA20_DSCPTR_PRV            ((void * volatile *)REG_DMA20_DSCPTR_PRV)               /* DMA20 Previous Initial Descriptor Pointer */
#define pREG_DMA20_ADDR_CUR              ((void * volatile *)REG_DMA20_ADDR_CUR)                 /* DMA20 Current Address */
#define pREG_DMA20_STAT                  ((volatile uint32_t *)REG_DMA20_STAT)                   /* DMA20 Status Register */
#define pREG_DMA20_XCNT_CUR              ((volatile uint32_t *)REG_DMA20_XCNT_CUR)               /* DMA20 Current Count(1D) or intra-row XCNT (2D) */
#define pREG_DMA20_YCNT_CUR              ((volatile uint32_t *)REG_DMA20_YCNT_CUR)               /* DMA20 Current Row Count (2D only) */
#define pREG_DMA20_BWLCNT                ((volatile uint32_t *)REG_DMA20_BWLCNT)                 /* DMA20 Bandwidth Limit Count */
#define pREG_DMA20_BWLCNT_CUR            ((volatile uint32_t *)REG_DMA20_BWLCNT_CUR)             /* DMA20 Bandwidth Limit Count Current */
#define pREG_DMA20_BWMCNT                ((volatile uint32_t *)REG_DMA20_BWMCNT)                 /* DMA20 Bandwidth Monitor Count */
#define pREG_DMA20_BWMCNT_CUR            ((volatile uint32_t *)REG_DMA20_BWMCNT_CUR)             /* DMA20 Bandwidth Monitor Count Current */

/* =========================================================================
       DMA21
   ========================================================================= */
#define pREG_DMA21_DSCPTR_NXT            ((void * volatile *)REG_DMA21_DSCPTR_NXT)               /* DMA21 Pointer to Next Initial Descriptor */
#define pREG_DMA21_ADDRSTART             ((void * volatile *)REG_DMA21_ADDRSTART)                /* DMA21 Start Address of Current Buffer */
#define pREG_DMA21_CFG                   ((volatile uint32_t *)REG_DMA21_CFG)                    /* DMA21 Configuration Register */
#define pREG_DMA21_XCNT                  ((volatile uint32_t *)REG_DMA21_XCNT)                   /* DMA21 Inner Loop Count Start Value */
#define pREG_DMA21_XMOD                  ((volatile  int32_t *)REG_DMA21_XMOD)                   /* DMA21 Inner Loop Address Increment */
#define pREG_DMA21_YCNT                  ((volatile uint32_t *)REG_DMA21_YCNT)                   /* DMA21 Outer Loop Count Start Value (2D only) */
#define pREG_DMA21_YMOD                  ((volatile  int32_t *)REG_DMA21_YMOD)                   /* DMA21 Outer Loop Address Increment (2D only) */
#define pREG_DMA21_DSCPTR_CUR            ((void * volatile *)REG_DMA21_DSCPTR_CUR)               /* DMA21 Current Descriptor Pointer */
#define pREG_DMA21_DSCPTR_PRV            ((void * volatile *)REG_DMA21_DSCPTR_PRV)               /* DMA21 Previous Initial Descriptor Pointer */
#define pREG_DMA21_ADDR_CUR              ((void * volatile *)REG_DMA21_ADDR_CUR)                 /* DMA21 Current Address */
#define pREG_DMA21_STAT                  ((volatile uint32_t *)REG_DMA21_STAT)                   /* DMA21 Status Register */
#define pREG_DMA21_XCNT_CUR              ((volatile uint32_t *)REG_DMA21_XCNT_CUR)               /* DMA21 Current Count(1D) or intra-row XCNT (2D) */
#define pREG_DMA21_YCNT_CUR              ((volatile uint32_t *)REG_DMA21_YCNT_CUR)               /* DMA21 Current Row Count (2D only) */
#define pREG_DMA21_BWLCNT                ((volatile uint32_t *)REG_DMA21_BWLCNT)                 /* DMA21 Bandwidth Limit Count */
#define pREG_DMA21_BWLCNT_CUR            ((volatile uint32_t *)REG_DMA21_BWLCNT_CUR)             /* DMA21 Bandwidth Limit Count Current */
#define pREG_DMA21_BWMCNT                ((volatile uint32_t *)REG_DMA21_BWMCNT)                 /* DMA21 Bandwidth Monitor Count */
#define pREG_DMA21_BWMCNT_CUR            ((volatile uint32_t *)REG_DMA21_BWMCNT_CUR)             /* DMA21 Bandwidth Monitor Count Current */


/* =========================================================================
       CRC0
   ========================================================================= */
#define pREG_CRC0_CTL                    ((volatile uint32_t *)REG_CRC0_CTL)                     /* CRC0 Control Register */
#define pREG_CRC0_DCNT                   ((volatile uint32_t *)REG_CRC0_DCNT)                    /* CRC0 Data Word Count Register */
#define pREG_CRC0_DCNTRLD                ((volatile uint32_t *)REG_CRC0_DCNTRLD)                 /* CRC0 Data Word Count Reload Register */
#define pREG_CRC0_COMP                   ((volatile uint32_t *)REG_CRC0_COMP)                    /* CRC0 Data Compare Register */
#define pREG_CRC0_FILLVAL                ((volatile uint32_t *)REG_CRC0_FILLVAL)                 /* CRC0 Fill Value Register */
#define pREG_CRC0_DFIFO                  ((volatile uint32_t *)REG_CRC0_DFIFO)                   /* CRC0 Data FIFO Register */
#define pREG_CRC0_INEN                   ((volatile uint32_t *)REG_CRC0_INEN)                    /* CRC0 Interrupt Enable Register */
#define pREG_CRC0_INEN_SET               ((volatile uint32_t *)REG_CRC0_INEN_SET)                /* CRC0 Interrupt Enable Set Register */
#define pREG_CRC0_INEN_CLR               ((volatile uint32_t *)REG_CRC0_INEN_CLR)                /* CRC0 Interrupt Enable Clear Register */
#define pREG_CRC0_POLY                   ((volatile uint32_t *)REG_CRC0_POLY)                    /* CRC0 Polynomial Register */
#define pREG_CRC0_STAT                   ((volatile uint32_t *)REG_CRC0_STAT)                    /* CRC0 Status Register */
#define pREG_CRC0_DCNTCAP                ((volatile uint32_t *)REG_CRC0_DCNTCAP)                 /* CRC0 Data Count Capture Register */
#define pREG_CRC0_RESULT_FIN             ((volatile uint32_t *)REG_CRC0_RESULT_FIN)              /* CRC0 CRC Final Result Register */
#define pREG_CRC0_RESULT_CUR             ((volatile uint32_t *)REG_CRC0_RESULT_CUR)              /* CRC0 CRC Current Result Register */

/* =========================================================================
       CRC1
   ========================================================================= */
#define pREG_CRC1_CTL                    ((volatile uint32_t *)REG_CRC1_CTL)                     /* CRC1 Control Register */
#define pREG_CRC1_DCNT                   ((volatile uint32_t *)REG_CRC1_DCNT)                    /* CRC1 Data Word Count Register */
#define pREG_CRC1_DCNTRLD                ((volatile uint32_t *)REG_CRC1_DCNTRLD)                 /* CRC1 Data Word Count Reload Register */
#define pREG_CRC1_COMP                   ((volatile uint32_t *)REG_CRC1_COMP)                    /* CRC1 Data Compare Register */
#define pREG_CRC1_FILLVAL                ((volatile uint32_t *)REG_CRC1_FILLVAL)                 /* CRC1 Fill Value Register */
#define pREG_CRC1_DFIFO                  ((volatile uint32_t *)REG_CRC1_DFIFO)                   /* CRC1 Data FIFO Register */
#define pREG_CRC1_INEN                   ((volatile uint32_t *)REG_CRC1_INEN)                    /* CRC1 Interrupt Enable Register */
#define pREG_CRC1_INEN_SET               ((volatile uint32_t *)REG_CRC1_INEN_SET)                /* CRC1 Interrupt Enable Set Register */
#define pREG_CRC1_INEN_CLR               ((volatile uint32_t *)REG_CRC1_INEN_CLR)                /* CRC1 Interrupt Enable Clear Register */
#define pREG_CRC1_POLY                   ((volatile uint32_t *)REG_CRC1_POLY)                    /* CRC1 Polynomial Register */
#define pREG_CRC1_STAT                   ((volatile uint32_t *)REG_CRC1_STAT)                    /* CRC1 Status Register */
#define pREG_CRC1_DCNTCAP                ((volatile uint32_t *)REG_CRC1_DCNTCAP)                 /* CRC1 Data Count Capture Register */
#define pREG_CRC1_RESULT_FIN             ((volatile uint32_t *)REG_CRC1_RESULT_FIN)              /* CRC1 CRC Final Result Register */
#define pREG_CRC1_RESULT_CUR             ((volatile uint32_t *)REG_CRC1_RESULT_CUR)              /* CRC1 CRC Current Result Register */


/* =========================================================================
       DMC0
   ========================================================================= */
#define pREG_DMC0_PHY_CTL0               ((volatile uint32_t *)REG_DMC0_PHY_CTL0)                /* DMC0 PHY Control 0 Register */
#define pREG_DMC0_PHY_CTL1               ((volatile uint32_t *)REG_DMC0_PHY_CTL1)                /* DMC0 PHY Control 1 Register */
#define pREG_DMC0_PHY_CTL2               ((volatile uint32_t *)REG_DMC0_PHY_CTL2)                /* DMC0 PHY Control 2 Register */
#define pREG_DMC0_PHY_CTL4               ((volatile uint32_t *)REG_DMC0_PHY_CTL4)                /* DMC0 PHY Control 4 Register */
#define pREG_DMC0_PHY_STAT0              ((volatile uint32_t *)REG_DMC0_PHY_STAT0)               /* DMC0 PHY Status 0 Register */
#define pREG_DMC0_CAL_PADCTL0            ((volatile uint32_t *)REG_DMC0_CAL_PADCTL0)             /* DMC0 CALIBRATION PAD CTL 0 Register */
#define pREG_DMC0_CAL_PADCTL2            ((volatile uint32_t *)REG_DMC0_CAL_PADCTL2)             /* DMC0 CALIBRATION PAD CTL2 Register */


/* =========================================================================
       USB0
   ========================================================================= */
#define pREG_USB0_FADDR                  ((volatile  uint8_t *)REG_USB0_FADDR)                   /* USB0 Function Address Register */
#define pREG_USB0_POWER                  ((volatile  uint8_t *)REG_USB0_POWER)                   /* USB0 Power and Device Control Register */
#define pREG_USB0_INTRTX                 ((volatile uint16_t *)REG_USB0_INTRTX)                  /* USB0 Transmit Interrupt Register */
#define pREG_USB0_INTRRX                 ((volatile uint16_t *)REG_USB0_INTRRX)                  /* USB0 Receive Interrupt Register */
#define pREG_USB0_INTRTXE                ((volatile uint16_t *)REG_USB0_INTRTXE)                 /* USB0 Transmit Interrupt Enable Register */
#define pREG_USB0_INTRRXE                ((volatile uint16_t *)REG_USB0_INTRRXE)                 /* USB0 Receive Interrupt Enable Register */
#define pREG_USB0_IRQ                    ((volatile  uint8_t *)REG_USB0_IRQ)                     /* USB0 Common Interrupts Register */
#define pREG_USB0_IEN                    ((volatile  uint8_t *)REG_USB0_IEN)                     /* USB0 Common Interrupts Enable Register */
#define pREG_USB0_FRAME                  ((volatile uint16_t *)REG_USB0_FRAME)                   /* USB0 Frame Number Register */
#define pREG_USB0_INDEX                  ((volatile  uint8_t *)REG_USB0_INDEX)                   /* USB0 Index Register */
#define pREG_USB0_TESTMODE               ((volatile  uint8_t *)REG_USB0_TESTMODE)                /* USB0 Testmode Register */
#define pREG_USB0_EPI_TXMAXP0            ((volatile uint16_t *)REG_USB0_EPI_TXMAXP0)             /* USB0 EPn Transmit Maximum Packet Length Register */
#define pREG_USB0_EPI_TXCSR_P0           ((volatile uint16_t *)REG_USB0_EPI_TXCSR_P0)            /* USB0 EPn Transmit Configuration and Status (Peripheral) Register */
#define pREG_USB0_EPI_TXCSR_H0           ((volatile uint16_t *)REG_USB0_EPI_TXCSR_H0)            /* USB0 EPn Transmit Configuration and Status (Host) Register */
#define pREG_USB0_EP0I_CSR0_P            ((volatile uint16_t *)REG_USB0_EP0I_CSR0_P)             /* USB0 EP0 Configuration and Status (Peripheral) Register */
#define pREG_USB0_EP0I_CSR0_H            ((volatile uint16_t *)REG_USB0_EP0I_CSR0_H)             /* USB0 EP0 Configuration and Status (Host) Register */
#define pREG_USB0_EPI_RXMAXP0            ((volatile uint16_t *)REG_USB0_EPI_RXMAXP0)             /* USB0 EPn Receive Maximum Packet Length Register */
#define pREG_USB0_EPI_RXCSR_H0           ((volatile uint16_t *)REG_USB0_EPI_RXCSR_H0)            /* USB0 EPn Receive Configuration and Status (Host) Register */
#define pREG_USB0_EPI_RXCSR_P0           ((volatile uint16_t *)REG_USB0_EPI_RXCSR_P0)            /* USB0 EPn Receive Configuration and Status (Peripheral) Register */
#define pREG_USB0_EP0I_CNT0              ((volatile uint16_t *)REG_USB0_EP0I_CNT0)               /* USB0 EP0 Number of Received Bytes Register */
#define pREG_USB0_EPI_RXCNT0             ((volatile uint16_t *)REG_USB0_EPI_RXCNT0)              /* USB0 EPn Number of Bytes Received Register */
#define pREG_USB0_EPI_TXTYPE0            ((volatile  uint8_t *)REG_USB0_EPI_TXTYPE0)             /* USB0 EPn Transmit Type Register */
#define pREG_USB0_EP0I_TYPE0             ((volatile  uint8_t *)REG_USB0_EP0I_TYPE0)              /* USB0 EP0 Connection Type Register */
#define pREG_USB0_EPI_TXINTERVAL0        ((volatile  uint8_t *)REG_USB0_EPI_TXINTERVAL0)         /* USB0 EPn Transmit Polling Interval Register */
#define pREG_USB0_EP0I_NAKLIMIT0         ((volatile  uint8_t *)REG_USB0_EP0I_NAKLIMIT0)          /* USB0 EP0 NAK Limit Register */
#define pREG_USB0_EPI_RXTYPE0            ((volatile  uint8_t *)REG_USB0_EPI_RXTYPE0)             /* USB0 EPn Receive Type Register */
#define pREG_USB0_EPI_RXINTERVAL0        ((volatile  uint8_t *)REG_USB0_EPI_RXINTERVAL0)         /* USB0 EPn Receive Polling Interval Register */
#define pREG_USB0_EP0I_CFGDATA0          ((volatile  uint8_t *)REG_USB0_EP0I_CFGDATA0)           /* USB0 EP0 Configuration Information Register */
#define pREG_USB0_FIFOB0                 ((volatile  uint8_t *)REG_USB0_FIFOB0)                  /* USB0 FIFO Byte (8-Bit) Register */
#define pREG_USB0_FIFOB1                 ((volatile  uint8_t *)REG_USB0_FIFOB1)                  /* USB0 FIFO Byte (8-Bit) Register */
#define pREG_USB0_FIFOB2                 ((volatile  uint8_t *)REG_USB0_FIFOB2)                  /* USB0 FIFO Byte (8-Bit) Register */
#define pREG_USB0_FIFOB3                 ((volatile  uint8_t *)REG_USB0_FIFOB3)                  /* USB0 FIFO Byte (8-Bit) Register */
#define pREG_USB0_FIFOB4                 ((volatile  uint8_t *)REG_USB0_FIFOB4)                  /* USB0 FIFO Byte (8-Bit) Register */
#define pREG_USB0_FIFOB5                 ((volatile  uint8_t *)REG_USB0_FIFOB5)                  /* USB0 FIFO Byte (8-Bit) Register */
#define pREG_USB0_FIFOB6                 ((volatile  uint8_t *)REG_USB0_FIFOB6)                  /* USB0 FIFO Byte (8-Bit) Register */
#define pREG_USB0_FIFOB7                 ((volatile  uint8_t *)REG_USB0_FIFOB7)                  /* USB0 FIFO Byte (8-Bit) Register */
#define pREG_USB0_FIFOB8                 ((volatile  uint8_t *)REG_USB0_FIFOB8)                  /* USB0 FIFO Byte (8-Bit) Register */
#define pREG_USB0_FIFOB9                 ((volatile  uint8_t *)REG_USB0_FIFOB9)                  /* USB0 FIFO Byte (8-Bit) Register */
#define pREG_USB0_FIFOB10                ((volatile  uint8_t *)REG_USB0_FIFOB10)                 /* USB0 FIFO Byte (8-Bit) Register */
#define pREG_USB0_FIFOB11                ((volatile  uint8_t *)REG_USB0_FIFOB11)                 /* USB0 FIFO Byte (8-Bit) Register */
#define pREG_USB0_FIFOH0                 ((volatile uint16_t *)REG_USB0_FIFOH0)                  /* USB0 FIFO Half-Word (16-Bit) Register */
#define pREG_USB0_FIFOH1                 ((volatile uint16_t *)REG_USB0_FIFOH1)                  /* USB0 FIFO Half-Word (16-Bit) Register */
#define pREG_USB0_FIFOH2                 ((volatile uint16_t *)REG_USB0_FIFOH2)                  /* USB0 FIFO Half-Word (16-Bit) Register */
#define pREG_USB0_FIFOH3                 ((volatile uint16_t *)REG_USB0_FIFOH3)                  /* USB0 FIFO Half-Word (16-Bit) Register */
#define pREG_USB0_FIFOH4                 ((volatile uint16_t *)REG_USB0_FIFOH4)                  /* USB0 FIFO Half-Word (16-Bit) Register */
#define pREG_USB0_FIFOH5                 ((volatile uint16_t *)REG_USB0_FIFOH5)                  /* USB0 FIFO Half-Word (16-Bit) Register */
#define pREG_USB0_FIFOH6                 ((volatile uint16_t *)REG_USB0_FIFOH6)                  /* USB0 FIFO Half-Word (16-Bit) Register */
#define pREG_USB0_FIFOH7                 ((volatile uint16_t *)REG_USB0_FIFOH7)                  /* USB0 FIFO Half-Word (16-Bit) Register */
#define pREG_USB0_FIFOH8                 ((volatile uint16_t *)REG_USB0_FIFOH8)                  /* USB0 FIFO Half-Word (16-Bit) Register */
#define pREG_USB0_FIFOH9                 ((volatile uint16_t *)REG_USB0_FIFOH9)                  /* USB0 FIFO Half-Word (16-Bit) Register */
#define pREG_USB0_FIFOH10                ((volatile uint16_t *)REG_USB0_FIFOH10)                 /* USB0 FIFO Half-Word (16-Bit) Register */
#define pREG_USB0_FIFOH11                ((volatile uint16_t *)REG_USB0_FIFOH11)                 /* USB0 FIFO Half-Word (16-Bit) Register */
#define pREG_USB0_FIFO0                  ((volatile uint32_t *)REG_USB0_FIFO0)                   /* USB0 FIFO Word (32-Bit) Register */
#define pREG_USB0_FIFO1                  ((volatile uint32_t *)REG_USB0_FIFO1)                   /* USB0 FIFO Word (32-Bit) Register */
#define pREG_USB0_FIFO2                  ((volatile uint32_t *)REG_USB0_FIFO2)                   /* USB0 FIFO Word (32-Bit) Register */
#define pREG_USB0_FIFO3                  ((volatile uint32_t *)REG_USB0_FIFO3)                   /* USB0 FIFO Word (32-Bit) Register */
#define pREG_USB0_FIFO4                  ((volatile uint32_t *)REG_USB0_FIFO4)                   /* USB0 FIFO Word (32-Bit) Register */
#define pREG_USB0_FIFO5                  ((volatile uint32_t *)REG_USB0_FIFO5)                   /* USB0 FIFO Word (32-Bit) Register */
#define pREG_USB0_FIFO6                  ((volatile uint32_t *)REG_USB0_FIFO6)                   /* USB0 FIFO Word (32-Bit) Register */
#define pREG_USB0_FIFO7                  ((volatile uint32_t *)REG_USB0_FIFO7)                   /* USB0 FIFO Word (32-Bit) Register */
#define pREG_USB0_FIFO8                  ((volatile uint32_t *)REG_USB0_FIFO8)                   /* USB0 FIFO Word (32-Bit) Register */
#define pREG_USB0_FIFO9                  ((volatile uint32_t *)REG_USB0_FIFO9)                   /* USB0 FIFO Word (32-Bit) Register */
#define pREG_USB0_FIFO10                 ((volatile uint32_t *)REG_USB0_FIFO10)                  /* USB0 FIFO Word (32-Bit) Register */
#define pREG_USB0_FIFO11                 ((volatile uint32_t *)REG_USB0_FIFO11)                  /* USB0 FIFO Word (32-Bit) Register */
#define pREG_USB0_DEV_CTL                ((volatile  uint8_t *)REG_USB0_DEV_CTL)                 /* USB0 Device Control Register */
#define pREG_USB0_TXFIFOSZ               ((volatile  uint8_t *)REG_USB0_TXFIFOSZ)                /* USB0 Transmit FIFO Size Register */
#define pREG_USB0_RXFIFOSZ               ((volatile  uint8_t *)REG_USB0_RXFIFOSZ)                /* USB0 Receive FIFO Size Register */
#define pREG_USB0_TXFIFOADDR             ((volatile uint16_t *)REG_USB0_TXFIFOADDR)              /* USB0 Transmit FIFO Address Register */
#define pREG_USB0_RXFIFOADDR             ((volatile uint16_t *)REG_USB0_RXFIFOADDR)              /* USB0 Receive FIFO Address Register */
#define pREG_USB0_EPINFO                 ((volatile  uint8_t *)REG_USB0_EPINFO)                  /* USB0 Endpoint Information Register */
#define pREG_USB0_RAMINFO                ((volatile  uint8_t *)REG_USB0_RAMINFO)                 /* USB0 RAM Information Register */
#define pREG_USB0_LINKINFO               ((volatile  uint8_t *)REG_USB0_LINKINFO)                /* USB0 Link Information Register */
#define pREG_USB0_VPLEN                  ((volatile  uint8_t *)REG_USB0_VPLEN)                   /* USB0 VBUS Pulse Length Register */
#define pREG_USB0_HS_EOF1                ((volatile  uint8_t *)REG_USB0_HS_EOF1)                 /* USB0 High-Speed EOF 1 Register */
#define pREG_USB0_FS_EOF1                ((volatile  uint8_t *)REG_USB0_FS_EOF1)                 /* USB0 Full-Speed EOF 1 Register */
#define pREG_USB0_LS_EOF1                ((volatile  uint8_t *)REG_USB0_LS_EOF1)                 /* USB0 Low-Speed EOF 1 Register */
#define pREG_USB0_SOFT_RST               ((volatile  uint8_t *)REG_USB0_SOFT_RST)                /* USB0 Software Reset Register */
#define pREG_USB0_MP0_TXFUNCADDR         ((volatile  uint8_t *)REG_USB0_MP0_TXFUNCADDR)          /* USB0 MPn Transmit Function Address Register */
#define pREG_USB0_MP1_TXFUNCADDR         ((volatile  uint8_t *)REG_USB0_MP1_TXFUNCADDR)          /* USB0 MPn Transmit Function Address Register */
#define pREG_USB0_MP2_TXFUNCADDR         ((volatile  uint8_t *)REG_USB0_MP2_TXFUNCADDR)          /* USB0 MPn Transmit Function Address Register */
#define pREG_USB0_MP3_TXFUNCADDR         ((volatile  uint8_t *)REG_USB0_MP3_TXFUNCADDR)          /* USB0 MPn Transmit Function Address Register */
#define pREG_USB0_MP4_TXFUNCADDR         ((volatile  uint8_t *)REG_USB0_MP4_TXFUNCADDR)          /* USB0 MPn Transmit Function Address Register */
#define pREG_USB0_MP5_TXFUNCADDR         ((volatile  uint8_t *)REG_USB0_MP5_TXFUNCADDR)          /* USB0 MPn Transmit Function Address Register */
#define pREG_USB0_MP6_TXFUNCADDR         ((volatile  uint8_t *)REG_USB0_MP6_TXFUNCADDR)          /* USB0 MPn Transmit Function Address Register */
#define pREG_USB0_MP7_TXFUNCADDR         ((volatile  uint8_t *)REG_USB0_MP7_TXFUNCADDR)          /* USB0 MPn Transmit Function Address Register */
#define pREG_USB0_MP8_TXFUNCADDR         ((volatile  uint8_t *)REG_USB0_MP8_TXFUNCADDR)          /* USB0 MPn Transmit Function Address Register */
#define pREG_USB0_MP9_TXFUNCADDR         ((volatile  uint8_t *)REG_USB0_MP9_TXFUNCADDR)          /* USB0 MPn Transmit Function Address Register */
#define pREG_USB0_MP10_TXFUNCADDR        ((volatile  uint8_t *)REG_USB0_MP10_TXFUNCADDR)         /* USB0 MPn Transmit Function Address Register */
#define pREG_USB0_MP11_TXFUNCADDR        ((volatile  uint8_t *)REG_USB0_MP11_TXFUNCADDR)         /* USB0 MPn Transmit Function Address Register */
#define pREG_USB0_MP0_TXHUBADDR          ((volatile  uint8_t *)REG_USB0_MP0_TXHUBADDR)           /* USB0 MPn Transmit Hub Address Register */
#define pREG_USB0_MP1_TXHUBADDR          ((volatile  uint8_t *)REG_USB0_MP1_TXHUBADDR)           /* USB0 MPn Transmit Hub Address Register */
#define pREG_USB0_MP2_TXHUBADDR          ((volatile  uint8_t *)REG_USB0_MP2_TXHUBADDR)           /* USB0 MPn Transmit Hub Address Register */
#define pREG_USB0_MP3_TXHUBADDR          ((volatile  uint8_t *)REG_USB0_MP3_TXHUBADDR)           /* USB0 MPn Transmit Hub Address Register */
#define pREG_USB0_MP4_TXHUBADDR          ((volatile  uint8_t *)REG_USB0_MP4_TXHUBADDR)           /* USB0 MPn Transmit Hub Address Register */
#define pREG_USB0_MP5_TXHUBADDR          ((volatile  uint8_t *)REG_USB0_MP5_TXHUBADDR)           /* USB0 MPn Transmit Hub Address Register */
#define pREG_USB0_MP6_TXHUBADDR          ((volatile  uint8_t *)REG_USB0_MP6_TXHUBADDR)           /* USB0 MPn Transmit Hub Address Register */
#define pREG_USB0_MP7_TXHUBADDR          ((volatile  uint8_t *)REG_USB0_MP7_TXHUBADDR)           /* USB0 MPn Transmit Hub Address Register */
#define pREG_USB0_MP8_TXHUBADDR          ((volatile  uint8_t *)REG_USB0_MP8_TXHUBADDR)           /* USB0 MPn Transmit Hub Address Register */
#define pREG_USB0_MP9_TXHUBADDR          ((volatile  uint8_t *)REG_USB0_MP9_TXHUBADDR)           /* USB0 MPn Transmit Hub Address Register */
#define pREG_USB0_MP10_TXHUBADDR         ((volatile  uint8_t *)REG_USB0_MP10_TXHUBADDR)          /* USB0 MPn Transmit Hub Address Register */
#define pREG_USB0_MP11_TXHUBADDR         ((volatile  uint8_t *)REG_USB0_MP11_TXHUBADDR)          /* USB0 MPn Transmit Hub Address Register */
#define pREG_USB0_MP0_TXHUBPORT          ((volatile  uint8_t *)REG_USB0_MP0_TXHUBPORT)           /* USB0 MPn Transmit Hub Port Register */
#define pREG_USB0_MP1_TXHUBPORT          ((volatile  uint8_t *)REG_USB0_MP1_TXHUBPORT)           /* USB0 MPn Transmit Hub Port Register */
#define pREG_USB0_MP2_TXHUBPORT          ((volatile  uint8_t *)REG_USB0_MP2_TXHUBPORT)           /* USB0 MPn Transmit Hub Port Register */
#define pREG_USB0_MP3_TXHUBPORT          ((volatile  uint8_t *)REG_USB0_MP3_TXHUBPORT)           /* USB0 MPn Transmit Hub Port Register */
#define pREG_USB0_MP4_TXHUBPORT          ((volatile  uint8_t *)REG_USB0_MP4_TXHUBPORT)           /* USB0 MPn Transmit Hub Port Register */
#define pREG_USB0_MP5_TXHUBPORT          ((volatile  uint8_t *)REG_USB0_MP5_TXHUBPORT)           /* USB0 MPn Transmit Hub Port Register */
#define pREG_USB0_MP6_TXHUBPORT          ((volatile  uint8_t *)REG_USB0_MP6_TXHUBPORT)           /* USB0 MPn Transmit Hub Port Register */
#define pREG_USB0_MP7_TXHUBPORT          ((volatile  uint8_t *)REG_USB0_MP7_TXHUBPORT)           /* USB0 MPn Transmit Hub Port Register */
#define pREG_USB0_MP8_TXHUBPORT          ((volatile  uint8_t *)REG_USB0_MP8_TXHUBPORT)           /* USB0 MPn Transmit Hub Port Register */
#define pREG_USB0_MP9_TXHUBPORT          ((volatile  uint8_t *)REG_USB0_MP9_TXHUBPORT)           /* USB0 MPn Transmit Hub Port Register */
#define pREG_USB0_MP10_TXHUBPORT         ((volatile  uint8_t *)REG_USB0_MP10_TXHUBPORT)          /* USB0 MPn Transmit Hub Port Register */
#define pREG_USB0_MP11_TXHUBPORT         ((volatile  uint8_t *)REG_USB0_MP11_TXHUBPORT)          /* USB0 MPn Transmit Hub Port Register */
#define pREG_USB0_MP0_RXFUNCADDR         ((volatile  uint8_t *)REG_USB0_MP0_RXFUNCADDR)          /* USB0 MPn Receive Function Address Register */
#define pREG_USB0_MP1_RXFUNCADDR         ((volatile  uint8_t *)REG_USB0_MP1_RXFUNCADDR)          /* USB0 MPn Receive Function Address Register */
#define pREG_USB0_MP2_RXFUNCADDR         ((volatile  uint8_t *)REG_USB0_MP2_RXFUNCADDR)          /* USB0 MPn Receive Function Address Register */
#define pREG_USB0_MP3_RXFUNCADDR         ((volatile  uint8_t *)REG_USB0_MP3_RXFUNCADDR)          /* USB0 MPn Receive Function Address Register */
#define pREG_USB0_MP4_RXFUNCADDR         ((volatile  uint8_t *)REG_USB0_MP4_RXFUNCADDR)          /* USB0 MPn Receive Function Address Register */
#define pREG_USB0_MP5_RXFUNCADDR         ((volatile  uint8_t *)REG_USB0_MP5_RXFUNCADDR)          /* USB0 MPn Receive Function Address Register */
#define pREG_USB0_MP6_RXFUNCADDR         ((volatile  uint8_t *)REG_USB0_MP6_RXFUNCADDR)          /* USB0 MPn Receive Function Address Register */
#define pREG_USB0_MP7_RXFUNCADDR         ((volatile  uint8_t *)REG_USB0_MP7_RXFUNCADDR)          /* USB0 MPn Receive Function Address Register */
#define pREG_USB0_MP8_RXFUNCADDR         ((volatile  uint8_t *)REG_USB0_MP8_RXFUNCADDR)          /* USB0 MPn Receive Function Address Register */
#define pREG_USB0_MP9_RXFUNCADDR         ((volatile  uint8_t *)REG_USB0_MP9_RXFUNCADDR)          /* USB0 MPn Receive Function Address Register */
#define pREG_USB0_MP10_RXFUNCADDR        ((volatile  uint8_t *)REG_USB0_MP10_RXFUNCADDR)         /* USB0 MPn Receive Function Address Register */
#define pREG_USB0_MP11_RXFUNCADDR        ((volatile  uint8_t *)REG_USB0_MP11_RXFUNCADDR)         /* USB0 MPn Receive Function Address Register */
#define pREG_USB0_MP0_RXHUBADDR          ((volatile  uint8_t *)REG_USB0_MP0_RXHUBADDR)           /* USB0 MPn Receive Hub Address Register */
#define pREG_USB0_MP1_RXHUBADDR          ((volatile  uint8_t *)REG_USB0_MP1_RXHUBADDR)           /* USB0 MPn Receive Hub Address Register */
#define pREG_USB0_MP2_RXHUBADDR          ((volatile  uint8_t *)REG_USB0_MP2_RXHUBADDR)           /* USB0 MPn Receive Hub Address Register */
#define pREG_USB0_MP3_RXHUBADDR          ((volatile  uint8_t *)REG_USB0_MP3_RXHUBADDR)           /* USB0 MPn Receive Hub Address Register */
#define pREG_USB0_MP4_RXHUBADDR          ((volatile  uint8_t *)REG_USB0_MP4_RXHUBADDR)           /* USB0 MPn Receive Hub Address Register */
#define pREG_USB0_MP5_RXHUBADDR          ((volatile  uint8_t *)REG_USB0_MP5_RXHUBADDR)           /* USB0 MPn Receive Hub Address Register */
#define pREG_USB0_MP6_RXHUBADDR          ((volatile  uint8_t *)REG_USB0_MP6_RXHUBADDR)           /* USB0 MPn Receive Hub Address Register */
#define pREG_USB0_MP7_RXHUBADDR          ((volatile  uint8_t *)REG_USB0_MP7_RXHUBADDR)           /* USB0 MPn Receive Hub Address Register */
#define pREG_USB0_MP8_RXHUBADDR          ((volatile  uint8_t *)REG_USB0_MP8_RXHUBADDR)           /* USB0 MPn Receive Hub Address Register */
#define pREG_USB0_MP9_RXHUBADDR          ((volatile  uint8_t *)REG_USB0_MP9_RXHUBADDR)           /* USB0 MPn Receive Hub Address Register */
#define pREG_USB0_MP10_RXHUBADDR         ((volatile  uint8_t *)REG_USB0_MP10_RXHUBADDR)          /* USB0 MPn Receive Hub Address Register */
#define pREG_USB0_MP11_RXHUBADDR         ((volatile  uint8_t *)REG_USB0_MP11_RXHUBADDR)          /* USB0 MPn Receive Hub Address Register */
#define pREG_USB0_MP0_RXHUBPORT          ((volatile  uint8_t *)REG_USB0_MP0_RXHUBPORT)           /* USB0 MPn Receive Hub Port Register */
#define pREG_USB0_MP1_RXHUBPORT          ((volatile  uint8_t *)REG_USB0_MP1_RXHUBPORT)           /* USB0 MPn Receive Hub Port Register */
#define pREG_USB0_MP2_RXHUBPORT          ((volatile  uint8_t *)REG_USB0_MP2_RXHUBPORT)           /* USB0 MPn Receive Hub Port Register */
#define pREG_USB0_MP3_RXHUBPORT          ((volatile  uint8_t *)REG_USB0_MP3_RXHUBPORT)           /* USB0 MPn Receive Hub Port Register */
#define pREG_USB0_MP4_RXHUBPORT          ((volatile  uint8_t *)REG_USB0_MP4_RXHUBPORT)           /* USB0 MPn Receive Hub Port Register */
#define pREG_USB0_MP5_RXHUBPORT          ((volatile  uint8_t *)REG_USB0_MP5_RXHUBPORT)           /* USB0 MPn Receive Hub Port Register */
#define pREG_USB0_MP6_RXHUBPORT          ((volatile  uint8_t *)REG_USB0_MP6_RXHUBPORT)           /* USB0 MPn Receive Hub Port Register */
#define pREG_USB0_MP7_RXHUBPORT          ((volatile  uint8_t *)REG_USB0_MP7_RXHUBPORT)           /* USB0 MPn Receive Hub Port Register */
#define pREG_USB0_MP8_RXHUBPORT          ((volatile  uint8_t *)REG_USB0_MP8_RXHUBPORT)           /* USB0 MPn Receive Hub Port Register */
#define pREG_USB0_MP9_RXHUBPORT          ((volatile  uint8_t *)REG_USB0_MP9_RXHUBPORT)           /* USB0 MPn Receive Hub Port Register */
#define pREG_USB0_MP10_RXHUBPORT         ((volatile  uint8_t *)REG_USB0_MP10_RXHUBPORT)          /* USB0 MPn Receive Hub Port Register */
#define pREG_USB0_MP11_RXHUBPORT         ((volatile  uint8_t *)REG_USB0_MP11_RXHUBPORT)          /* USB0 MPn Receive Hub Port Register */
#define pREG_USB0_EP0_TXMAXP             ((volatile uint16_t *)REG_USB0_EP0_TXMAXP)              /* USB0 EPn Transmit Maximum Packet Length Register */
#define pREG_USB0_EP1_TXMAXP             ((volatile uint16_t *)REG_USB0_EP1_TXMAXP)              /* USB0 EPn Transmit Maximum Packet Length Register */
#define pREG_USB0_EP2_TXMAXP             ((volatile uint16_t *)REG_USB0_EP2_TXMAXP)              /* USB0 EPn Transmit Maximum Packet Length Register */
#define pREG_USB0_EP3_TXMAXP             ((volatile uint16_t *)REG_USB0_EP3_TXMAXP)              /* USB0 EPn Transmit Maximum Packet Length Register */
#define pREG_USB0_EP4_TXMAXP             ((volatile uint16_t *)REG_USB0_EP4_TXMAXP)              /* USB0 EPn Transmit Maximum Packet Length Register */
#define pREG_USB0_EP5_TXMAXP             ((volatile uint16_t *)REG_USB0_EP5_TXMAXP)              /* USB0 EPn Transmit Maximum Packet Length Register */
#define pREG_USB0_EP6_TXMAXP             ((volatile uint16_t *)REG_USB0_EP6_TXMAXP)              /* USB0 EPn Transmit Maximum Packet Length Register */
#define pREG_USB0_EP7_TXMAXP             ((volatile uint16_t *)REG_USB0_EP7_TXMAXP)              /* USB0 EPn Transmit Maximum Packet Length Register */
#define pREG_USB0_EP8_TXMAXP             ((volatile uint16_t *)REG_USB0_EP8_TXMAXP)              /* USB0 EPn Transmit Maximum Packet Length Register */
#define pREG_USB0_EP9_TXMAXP             ((volatile uint16_t *)REG_USB0_EP9_TXMAXP)              /* USB0 EPn Transmit Maximum Packet Length Register */
#define pREG_USB0_EP10_TXMAXP            ((volatile uint16_t *)REG_USB0_EP10_TXMAXP)             /* USB0 EPn Transmit Maximum Packet Length Register */
#define pREG_USB0_EP11_TXMAXP            ((volatile uint16_t *)REG_USB0_EP11_TXMAXP)             /* USB0 EPn Transmit Maximum Packet Length Register */
#define pREG_USB0_EP0_CSR0_H             ((volatile uint16_t *)REG_USB0_EP0_CSR0_H)              /* USB0 EP0 Configuration and Status (Host) Register */
#define pREG_USB0_EP0_TXCSR_H            ((volatile uint16_t *)REG_USB0_EP0_TXCSR_H)             /* USB0 EPn Transmit Configuration and Status (Host) Register */
#define pREG_USB0_EP1_TXCSR_H            ((volatile uint16_t *)REG_USB0_EP1_TXCSR_H)             /* USB0 EPn Transmit Configuration and Status (Host) Register */
#define pREG_USB0_EP2_TXCSR_H            ((volatile uint16_t *)REG_USB0_EP2_TXCSR_H)             /* USB0 EPn Transmit Configuration and Status (Host) Register */
#define pREG_USB0_EP3_TXCSR_H            ((volatile uint16_t *)REG_USB0_EP3_TXCSR_H)             /* USB0 EPn Transmit Configuration and Status (Host) Register */
#define pREG_USB0_EP4_TXCSR_H            ((volatile uint16_t *)REG_USB0_EP4_TXCSR_H)             /* USB0 EPn Transmit Configuration and Status (Host) Register */
#define pREG_USB0_EP5_TXCSR_H            ((volatile uint16_t *)REG_USB0_EP5_TXCSR_H)             /* USB0 EPn Transmit Configuration and Status (Host) Register */
#define pREG_USB0_EP6_TXCSR_H            ((volatile uint16_t *)REG_USB0_EP6_TXCSR_H)             /* USB0 EPn Transmit Configuration and Status (Host) Register */
#define pREG_USB0_EP7_TXCSR_H            ((volatile uint16_t *)REG_USB0_EP7_TXCSR_H)             /* USB0 EPn Transmit Configuration and Status (Host) Register */
#define pREG_USB0_EP8_TXCSR_H            ((volatile uint16_t *)REG_USB0_EP8_TXCSR_H)             /* USB0 EPn Transmit Configuration and Status (Host) Register */
#define pREG_USB0_EP9_TXCSR_H            ((volatile uint16_t *)REG_USB0_EP9_TXCSR_H)             /* USB0 EPn Transmit Configuration and Status (Host) Register */
#define pREG_USB0_EP10_TXCSR_H           ((volatile uint16_t *)REG_USB0_EP10_TXCSR_H)            /* USB0 EPn Transmit Configuration and Status (Host) Register */
#define pREG_USB0_EP11_TXCSR_H           ((volatile uint16_t *)REG_USB0_EP11_TXCSR_H)            /* USB0 EPn Transmit Configuration and Status (Host) Register */
#define pREG_USB0_EP0_CSR0_P             ((volatile uint16_t *)REG_USB0_EP0_CSR0_P)              /* USB0 EP0 Configuration and Status (Peripheral) Register */
#define pREG_USB0_EP0_TXCSR_P            ((volatile uint16_t *)REG_USB0_EP0_TXCSR_P)             /* USB0 EPn Transmit Configuration and Status (Peripheral) Register */
#define pREG_USB0_EP1_TXCSR_P            ((volatile uint16_t *)REG_USB0_EP1_TXCSR_P)             /* USB0 EPn Transmit Configuration and Status (Peripheral) Register */
#define pREG_USB0_EP2_TXCSR_P            ((volatile uint16_t *)REG_USB0_EP2_TXCSR_P)             /* USB0 EPn Transmit Configuration and Status (Peripheral) Register */
#define pREG_USB0_EP3_TXCSR_P            ((volatile uint16_t *)REG_USB0_EP3_TXCSR_P)             /* USB0 EPn Transmit Configuration and Status (Peripheral) Register */
#define pREG_USB0_EP4_TXCSR_P            ((volatile uint16_t *)REG_USB0_EP4_TXCSR_P)             /* USB0 EPn Transmit Configuration and Status (Peripheral) Register */
#define pREG_USB0_EP5_TXCSR_P            ((volatile uint16_t *)REG_USB0_EP5_TXCSR_P)             /* USB0 EPn Transmit Configuration and Status (Peripheral) Register */
#define pREG_USB0_EP6_TXCSR_P            ((volatile uint16_t *)REG_USB0_EP6_TXCSR_P)             /* USB0 EPn Transmit Configuration and Status (Peripheral) Register */
#define pREG_USB0_EP7_TXCSR_P            ((volatile uint16_t *)REG_USB0_EP7_TXCSR_P)             /* USB0 EPn Transmit Configuration and Status (Peripheral) Register */
#define pREG_USB0_EP8_TXCSR_P            ((volatile uint16_t *)REG_USB0_EP8_TXCSR_P)             /* USB0 EPn Transmit Configuration and Status (Peripheral) Register */
#define pREG_USB0_EP9_TXCSR_P            ((volatile uint16_t *)REG_USB0_EP9_TXCSR_P)             /* USB0 EPn Transmit Configuration and Status (Peripheral) Register */
#define pREG_USB0_EP10_TXCSR_P           ((volatile uint16_t *)REG_USB0_EP10_TXCSR_P)            /* USB0 EPn Transmit Configuration and Status (Peripheral) Register */
#define pREG_USB0_EP11_TXCSR_P           ((volatile uint16_t *)REG_USB0_EP11_TXCSR_P)            /* USB0 EPn Transmit Configuration and Status (Peripheral) Register */
#define pREG_USB0_EP0_RXMAXP             ((volatile uint16_t *)REG_USB0_EP0_RXMAXP)              /* USB0 EPn Receive Maximum Packet Length Register */
#define pREG_USB0_EP1_RXMAXP             ((volatile uint16_t *)REG_USB0_EP1_RXMAXP)              /* USB0 EPn Receive Maximum Packet Length Register */
#define pREG_USB0_EP2_RXMAXP             ((volatile uint16_t *)REG_USB0_EP2_RXMAXP)              /* USB0 EPn Receive Maximum Packet Length Register */
#define pREG_USB0_EP3_RXMAXP             ((volatile uint16_t *)REG_USB0_EP3_RXMAXP)              /* USB0 EPn Receive Maximum Packet Length Register */
#define pREG_USB0_EP4_RXMAXP             ((volatile uint16_t *)REG_USB0_EP4_RXMAXP)              /* USB0 EPn Receive Maximum Packet Length Register */
#define pREG_USB0_EP5_RXMAXP             ((volatile uint16_t *)REG_USB0_EP5_RXMAXP)              /* USB0 EPn Receive Maximum Packet Length Register */
#define pREG_USB0_EP6_RXMAXP             ((volatile uint16_t *)REG_USB0_EP6_RXMAXP)              /* USB0 EPn Receive Maximum Packet Length Register */
#define pREG_USB0_EP7_RXMAXP             ((volatile uint16_t *)REG_USB0_EP7_RXMAXP)              /* USB0 EPn Receive Maximum Packet Length Register */
#define pREG_USB0_EP8_RXMAXP             ((volatile uint16_t *)REG_USB0_EP8_RXMAXP)              /* USB0 EPn Receive Maximum Packet Length Register */
#define pREG_USB0_EP9_RXMAXP             ((volatile uint16_t *)REG_USB0_EP9_RXMAXP)              /* USB0 EPn Receive Maximum Packet Length Register */
#define pREG_USB0_EP10_RXMAXP            ((volatile uint16_t *)REG_USB0_EP10_RXMAXP)             /* USB0 EPn Receive Maximum Packet Length Register */
#define pREG_USB0_EP11_RXMAXP            ((volatile uint16_t *)REG_USB0_EP11_RXMAXP)             /* USB0 EPn Receive Maximum Packet Length Register */
#define pREG_USB0_EP0_RXCSR_H            ((volatile uint16_t *)REG_USB0_EP0_RXCSR_H)             /* USB0 EPn Receive Configuration and Status (Host) Register */
#define pREG_USB0_EP1_RXCSR_H            ((volatile uint16_t *)REG_USB0_EP1_RXCSR_H)             /* USB0 EPn Receive Configuration and Status (Host) Register */
#define pREG_USB0_EP2_RXCSR_H            ((volatile uint16_t *)REG_USB0_EP2_RXCSR_H)             /* USB0 EPn Receive Configuration and Status (Host) Register */
#define pREG_USB0_EP3_RXCSR_H            ((volatile uint16_t *)REG_USB0_EP3_RXCSR_H)             /* USB0 EPn Receive Configuration and Status (Host) Register */
#define pREG_USB0_EP4_RXCSR_H            ((volatile uint16_t *)REG_USB0_EP4_RXCSR_H)             /* USB0 EPn Receive Configuration and Status (Host) Register */
#define pREG_USB0_EP5_RXCSR_H            ((volatile uint16_t *)REG_USB0_EP5_RXCSR_H)             /* USB0 EPn Receive Configuration and Status (Host) Register */
#define pREG_USB0_EP6_RXCSR_H            ((volatile uint16_t *)REG_USB0_EP6_RXCSR_H)             /* USB0 EPn Receive Configuration and Status (Host) Register */
#define pREG_USB0_EP7_RXCSR_H            ((volatile uint16_t *)REG_USB0_EP7_RXCSR_H)             /* USB0 EPn Receive Configuration and Status (Host) Register */
#define pREG_USB0_EP8_RXCSR_H            ((volatile uint16_t *)REG_USB0_EP8_RXCSR_H)             /* USB0 EPn Receive Configuration and Status (Host) Register */
#define pREG_USB0_EP9_RXCSR_H            ((volatile uint16_t *)REG_USB0_EP9_RXCSR_H)             /* USB0 EPn Receive Configuration and Status (Host) Register */
#define pREG_USB0_EP10_RXCSR_H           ((volatile uint16_t *)REG_USB0_EP10_RXCSR_H)            /* USB0 EPn Receive Configuration and Status (Host) Register */
#define pREG_USB0_EP11_RXCSR_H           ((volatile uint16_t *)REG_USB0_EP11_RXCSR_H)            /* USB0 EPn Receive Configuration and Status (Host) Register */
#define pREG_USB0_EP0_RXCSR_P            ((volatile uint16_t *)REG_USB0_EP0_RXCSR_P)             /* USB0 EPn Receive Configuration and Status (Peripheral) Register */
#define pREG_USB0_EP1_RXCSR_P            ((volatile uint16_t *)REG_USB0_EP1_RXCSR_P)             /* USB0 EPn Receive Configuration and Status (Peripheral) Register */
#define pREG_USB0_EP2_RXCSR_P            ((volatile uint16_t *)REG_USB0_EP2_RXCSR_P)             /* USB0 EPn Receive Configuration and Status (Peripheral) Register */
#define pREG_USB0_EP3_RXCSR_P            ((volatile uint16_t *)REG_USB0_EP3_RXCSR_P)             /* USB0 EPn Receive Configuration and Status (Peripheral) Register */
#define pREG_USB0_EP4_RXCSR_P            ((volatile uint16_t *)REG_USB0_EP4_RXCSR_P)             /* USB0 EPn Receive Configuration and Status (Peripheral) Register */
#define pREG_USB0_EP5_RXCSR_P            ((volatile uint16_t *)REG_USB0_EP5_RXCSR_P)             /* USB0 EPn Receive Configuration and Status (Peripheral) Register */
#define pREG_USB0_EP6_RXCSR_P            ((volatile uint16_t *)REG_USB0_EP6_RXCSR_P)             /* USB0 EPn Receive Configuration and Status (Peripheral) Register */
#define pREG_USB0_EP7_RXCSR_P            ((volatile uint16_t *)REG_USB0_EP7_RXCSR_P)             /* USB0 EPn Receive Configuration and Status (Peripheral) Register */
#define pREG_USB0_EP8_RXCSR_P            ((volatile uint16_t *)REG_USB0_EP8_RXCSR_P)             /* USB0 EPn Receive Configuration and Status (Peripheral) Register */
#define pREG_USB0_EP9_RXCSR_P            ((volatile uint16_t *)REG_USB0_EP9_RXCSR_P)             /* USB0 EPn Receive Configuration and Status (Peripheral) Register */
#define pREG_USB0_EP10_RXCSR_P           ((volatile uint16_t *)REG_USB0_EP10_RXCSR_P)            /* USB0 EPn Receive Configuration and Status (Peripheral) Register */
#define pREG_USB0_EP11_RXCSR_P           ((volatile uint16_t *)REG_USB0_EP11_RXCSR_P)            /* USB0 EPn Receive Configuration and Status (Peripheral) Register */
#define pREG_USB0_EP0_CNT0               ((volatile uint16_t *)REG_USB0_EP0_CNT0)                /* USB0 EP0 Number of Received Bytes Register */
#define pREG_USB0_EP0_RXCNT              ((volatile uint16_t *)REG_USB0_EP0_RXCNT)               /* USB0 EPn Number of Bytes Received Register */
#define pREG_USB0_EP1_RXCNT              ((volatile uint16_t *)REG_USB0_EP1_RXCNT)               /* USB0 EPn Number of Bytes Received Register */
#define pREG_USB0_EP2_RXCNT              ((volatile uint16_t *)REG_USB0_EP2_RXCNT)               /* USB0 EPn Number of Bytes Received Register */
#define pREG_USB0_EP3_RXCNT              ((volatile uint16_t *)REG_USB0_EP3_RXCNT)               /* USB0 EPn Number of Bytes Received Register */
#define pREG_USB0_EP4_RXCNT              ((volatile uint16_t *)REG_USB0_EP4_RXCNT)               /* USB0 EPn Number of Bytes Received Register */
#define pREG_USB0_EP5_RXCNT              ((volatile uint16_t *)REG_USB0_EP5_RXCNT)               /* USB0 EPn Number of Bytes Received Register */
#define pREG_USB0_EP6_RXCNT              ((volatile uint16_t *)REG_USB0_EP6_RXCNT)               /* USB0 EPn Number of Bytes Received Register */
#define pREG_USB0_EP7_RXCNT              ((volatile uint16_t *)REG_USB0_EP7_RXCNT)               /* USB0 EPn Number of Bytes Received Register */
#define pREG_USB0_EP8_RXCNT              ((volatile uint16_t *)REG_USB0_EP8_RXCNT)               /* USB0 EPn Number of Bytes Received Register */
#define pREG_USB0_EP9_RXCNT              ((volatile uint16_t *)REG_USB0_EP9_RXCNT)               /* USB0 EPn Number of Bytes Received Register */
#define pREG_USB0_EP10_RXCNT             ((volatile uint16_t *)REG_USB0_EP10_RXCNT)              /* USB0 EPn Number of Bytes Received Register */
#define pREG_USB0_EP11_RXCNT             ((volatile uint16_t *)REG_USB0_EP11_RXCNT)              /* USB0 EPn Number of Bytes Received Register */
#define pREG_USB0_EP0_TYPE0              ((volatile  uint8_t *)REG_USB0_EP0_TYPE0)               /* USB0 EP0 Connection Type Register */
#define pREG_USB0_EP0_TXTYPE             ((volatile  uint8_t *)REG_USB0_EP0_TXTYPE)              /* USB0 EPn Transmit Type Register */
#define pREG_USB0_EP1_TXTYPE             ((volatile  uint8_t *)REG_USB0_EP1_TXTYPE)              /* USB0 EPn Transmit Type Register */
#define pREG_USB0_EP2_TXTYPE             ((volatile  uint8_t *)REG_USB0_EP2_TXTYPE)              /* USB0 EPn Transmit Type Register */
#define pREG_USB0_EP3_TXTYPE             ((volatile  uint8_t *)REG_USB0_EP3_TXTYPE)              /* USB0 EPn Transmit Type Register */
#define pREG_USB0_EP4_TXTYPE             ((volatile  uint8_t *)REG_USB0_EP4_TXTYPE)              /* USB0 EPn Transmit Type Register */
#define pREG_USB0_EP5_TXTYPE             ((volatile  uint8_t *)REG_USB0_EP5_TXTYPE)              /* USB0 EPn Transmit Type Register */
#define pREG_USB0_EP6_TXTYPE             ((volatile  uint8_t *)REG_USB0_EP6_TXTYPE)              /* USB0 EPn Transmit Type Register */
#define pREG_USB0_EP7_TXTYPE             ((volatile  uint8_t *)REG_USB0_EP7_TXTYPE)              /* USB0 EPn Transmit Type Register */
#define pREG_USB0_EP8_TXTYPE             ((volatile  uint8_t *)REG_USB0_EP8_TXTYPE)              /* USB0 EPn Transmit Type Register */
#define pREG_USB0_EP9_TXTYPE             ((volatile  uint8_t *)REG_USB0_EP9_TXTYPE)              /* USB0 EPn Transmit Type Register */
#define pREG_USB0_EP10_TXTYPE            ((volatile  uint8_t *)REG_USB0_EP10_TXTYPE)             /* USB0 EPn Transmit Type Register */
#define pREG_USB0_EP11_TXTYPE            ((volatile  uint8_t *)REG_USB0_EP11_TXTYPE)             /* USB0 EPn Transmit Type Register */
#define pREG_USB0_EP0_NAKLIMIT0          ((volatile  uint8_t *)REG_USB0_EP0_NAKLIMIT0)           /* USB0 EP0 NAK Limit Register */
#define pREG_USB0_EP0_TXINTERVAL         ((volatile  uint8_t *)REG_USB0_EP0_TXINTERVAL)          /* USB0 EPn Transmit Polling Interval Register */
#define pREG_USB0_EP1_TXINTERVAL         ((volatile  uint8_t *)REG_USB0_EP1_TXINTERVAL)          /* USB0 EPn Transmit Polling Interval Register */
#define pREG_USB0_EP2_TXINTERVAL         ((volatile  uint8_t *)REG_USB0_EP2_TXINTERVAL)          /* USB0 EPn Transmit Polling Interval Register */
#define pREG_USB0_EP3_TXINTERVAL         ((volatile  uint8_t *)REG_USB0_EP3_TXINTERVAL)          /* USB0 EPn Transmit Polling Interval Register */
#define pREG_USB0_EP4_TXINTERVAL         ((volatile  uint8_t *)REG_USB0_EP4_TXINTERVAL)          /* USB0 EPn Transmit Polling Interval Register */
#define pREG_USB0_EP5_TXINTERVAL         ((volatile  uint8_t *)REG_USB0_EP5_TXINTERVAL)          /* USB0 EPn Transmit Polling Interval Register */
#define pREG_USB0_EP6_TXINTERVAL         ((volatile  uint8_t *)REG_USB0_EP6_TXINTERVAL)          /* USB0 EPn Transmit Polling Interval Register */
#define pREG_USB0_EP7_TXINTERVAL         ((volatile  uint8_t *)REG_USB0_EP7_TXINTERVAL)          /* USB0 EPn Transmit Polling Interval Register */
#define pREG_USB0_EP8_TXINTERVAL         ((volatile  uint8_t *)REG_USB0_EP8_TXINTERVAL)          /* USB0 EPn Transmit Polling Interval Register */
#define pREG_USB0_EP9_TXINTERVAL         ((volatile  uint8_t *)REG_USB0_EP9_TXINTERVAL)          /* USB0 EPn Transmit Polling Interval Register */
#define pREG_USB0_EP10_TXINTERVAL        ((volatile  uint8_t *)REG_USB0_EP10_TXINTERVAL)         /* USB0 EPn Transmit Polling Interval Register */
#define pREG_USB0_EP11_TXINTERVAL        ((volatile  uint8_t *)REG_USB0_EP11_TXINTERVAL)         /* USB0 EPn Transmit Polling Interval Register */
#define pREG_USB0_EP0_RXTYPE             ((volatile  uint8_t *)REG_USB0_EP0_RXTYPE)              /* USB0 EPn Receive Type Register */
#define pREG_USB0_EP1_RXTYPE             ((volatile  uint8_t *)REG_USB0_EP1_RXTYPE)              /* USB0 EPn Receive Type Register */
#define pREG_USB0_EP2_RXTYPE             ((volatile  uint8_t *)REG_USB0_EP2_RXTYPE)              /* USB0 EPn Receive Type Register */
#define pREG_USB0_EP3_RXTYPE             ((volatile  uint8_t *)REG_USB0_EP3_RXTYPE)              /* USB0 EPn Receive Type Register */
#define pREG_USB0_EP4_RXTYPE             ((volatile  uint8_t *)REG_USB0_EP4_RXTYPE)              /* USB0 EPn Receive Type Register */
#define pREG_USB0_EP5_RXTYPE             ((volatile  uint8_t *)REG_USB0_EP5_RXTYPE)              /* USB0 EPn Receive Type Register */
#define pREG_USB0_EP6_RXTYPE             ((volatile  uint8_t *)REG_USB0_EP6_RXTYPE)              /* USB0 EPn Receive Type Register */
#define pREG_USB0_EP7_RXTYPE             ((volatile  uint8_t *)REG_USB0_EP7_RXTYPE)              /* USB0 EPn Receive Type Register */
#define pREG_USB0_EP8_RXTYPE             ((volatile  uint8_t *)REG_USB0_EP8_RXTYPE)              /* USB0 EPn Receive Type Register */
#define pREG_USB0_EP9_RXTYPE             ((volatile  uint8_t *)REG_USB0_EP9_RXTYPE)              /* USB0 EPn Receive Type Register */
#define pREG_USB0_EP10_RXTYPE            ((volatile  uint8_t *)REG_USB0_EP10_RXTYPE)             /* USB0 EPn Receive Type Register */
#define pREG_USB0_EP11_RXTYPE            ((volatile  uint8_t *)REG_USB0_EP11_RXTYPE)             /* USB0 EPn Receive Type Register */
#define pREG_USB0_EP0_RXINTERVAL         ((volatile  uint8_t *)REG_USB0_EP0_RXINTERVAL)          /* USB0 EPn Receive Polling Interval Register */
#define pREG_USB0_EP1_RXINTERVAL         ((volatile  uint8_t *)REG_USB0_EP1_RXINTERVAL)          /* USB0 EPn Receive Polling Interval Register */
#define pREG_USB0_EP2_RXINTERVAL         ((volatile  uint8_t *)REG_USB0_EP2_RXINTERVAL)          /* USB0 EPn Receive Polling Interval Register */
#define pREG_USB0_EP3_RXINTERVAL         ((volatile  uint8_t *)REG_USB0_EP3_RXINTERVAL)          /* USB0 EPn Receive Polling Interval Register */
#define pREG_USB0_EP4_RXINTERVAL         ((volatile  uint8_t *)REG_USB0_EP4_RXINTERVAL)          /* USB0 EPn Receive Polling Interval Register */
#define pREG_USB0_EP5_RXINTERVAL         ((volatile  uint8_t *)REG_USB0_EP5_RXINTERVAL)          /* USB0 EPn Receive Polling Interval Register */
#define pREG_USB0_EP6_RXINTERVAL         ((volatile  uint8_t *)REG_USB0_EP6_RXINTERVAL)          /* USB0 EPn Receive Polling Interval Register */
#define pREG_USB0_EP7_RXINTERVAL         ((volatile  uint8_t *)REG_USB0_EP7_RXINTERVAL)          /* USB0 EPn Receive Polling Interval Register */
#define pREG_USB0_EP8_RXINTERVAL         ((volatile  uint8_t *)REG_USB0_EP8_RXINTERVAL)          /* USB0 EPn Receive Polling Interval Register */
#define pREG_USB0_EP9_RXINTERVAL         ((volatile  uint8_t *)REG_USB0_EP9_RXINTERVAL)          /* USB0 EPn Receive Polling Interval Register */
#define pREG_USB0_EP10_RXINTERVAL        ((volatile  uint8_t *)REG_USB0_EP10_RXINTERVAL)         /* USB0 EPn Receive Polling Interval Register */
#define pREG_USB0_EP11_RXINTERVAL        ((volatile  uint8_t *)REG_USB0_EP11_RXINTERVAL)         /* USB0 EPn Receive Polling Interval Register */
#define pREG_USB0_EP0_CFGDATA0           ((volatile  uint8_t *)REG_USB0_EP0_CFGDATA0)            /* USB0 EP0 Configuration Information Register */
#define pREG_USB0_DMA_IRQ                ((volatile  uint8_t *)REG_USB0_DMA_IRQ)                 /* USB0 DMA Interrupt Register */
#define pREG_USB0_DMA0_CTL               ((volatile uint16_t *)REG_USB0_DMA0_CTL)                /* USB0 DMA Channel n Control Register */
#define pREG_USB0_DMA1_CTL               ((volatile uint16_t *)REG_USB0_DMA1_CTL)                /* USB0 DMA Channel n Control Register */
#define pREG_USB0_DMA2_CTL               ((volatile uint16_t *)REG_USB0_DMA2_CTL)                /* USB0 DMA Channel n Control Register */
#define pREG_USB0_DMA3_CTL               ((volatile uint16_t *)REG_USB0_DMA3_CTL)                /* USB0 DMA Channel n Control Register */
#define pREG_USB0_DMA4_CTL               ((volatile uint16_t *)REG_USB0_DMA4_CTL)                /* USB0 DMA Channel n Control Register */
#define pREG_USB0_DMA5_CTL               ((volatile uint16_t *)REG_USB0_DMA5_CTL)                /* USB0 DMA Channel n Control Register */
#define pREG_USB0_DMA6_CTL               ((volatile uint16_t *)REG_USB0_DMA6_CTL)                /* USB0 DMA Channel n Control Register */
#define pREG_USB0_DMA7_CTL               ((volatile uint16_t *)REG_USB0_DMA7_CTL)                /* USB0 DMA Channel n Control Register */
#define pREG_USB0_DMA0_ADDR              ((void * volatile *)REG_USB0_DMA0_ADDR)                 /* USB0 DMA Channel n Address Register */
#define pREG_USB0_DMA1_ADDR              ((void * volatile *)REG_USB0_DMA1_ADDR)                 /* USB0 DMA Channel n Address Register */
#define pREG_USB0_DMA2_ADDR              ((void * volatile *)REG_USB0_DMA2_ADDR)                 /* USB0 DMA Channel n Address Register */
#define pREG_USB0_DMA3_ADDR              ((void * volatile *)REG_USB0_DMA3_ADDR)                 /* USB0 DMA Channel n Address Register */
#define pREG_USB0_DMA4_ADDR              ((void * volatile *)REG_USB0_DMA4_ADDR)                 /* USB0 DMA Channel n Address Register */
#define pREG_USB0_DMA5_ADDR              ((void * volatile *)REG_USB0_DMA5_ADDR)                 /* USB0 DMA Channel n Address Register */
#define pREG_USB0_DMA6_ADDR              ((void * volatile *)REG_USB0_DMA6_ADDR)                 /* USB0 DMA Channel n Address Register */
#define pREG_USB0_DMA7_ADDR              ((void * volatile *)REG_USB0_DMA7_ADDR)                 /* USB0 DMA Channel n Address Register */
#define pREG_USB0_DMA0_CNT               ((volatile uint32_t *)REG_USB0_DMA0_CNT)                /* USB0 DMA Channel n Count Register */
#define pREG_USB0_DMA1_CNT               ((volatile uint32_t *)REG_USB0_DMA1_CNT)                /* USB0 DMA Channel n Count Register */
#define pREG_USB0_DMA2_CNT               ((volatile uint32_t *)REG_USB0_DMA2_CNT)                /* USB0 DMA Channel n Count Register */
#define pREG_USB0_DMA3_CNT               ((volatile uint32_t *)REG_USB0_DMA3_CNT)                /* USB0 DMA Channel n Count Register */
#define pREG_USB0_DMA4_CNT               ((volatile uint32_t *)REG_USB0_DMA4_CNT)                /* USB0 DMA Channel n Count Register */
#define pREG_USB0_DMA5_CNT               ((volatile uint32_t *)REG_USB0_DMA5_CNT)                /* USB0 DMA Channel n Count Register */
#define pREG_USB0_DMA6_CNT               ((volatile uint32_t *)REG_USB0_DMA6_CNT)                /* USB0 DMA Channel n Count Register */
#define pREG_USB0_DMA7_CNT               ((volatile uint32_t *)REG_USB0_DMA7_CNT)                /* USB0 DMA Channel n Count Register */
#define pREG_USB0_RQPKTCNT0              ((volatile uint16_t *)REG_USB0_RQPKTCNT0)               /* USB0 EPn Request Packet Count Register */
#define pREG_USB0_RQPKTCNT1              ((volatile uint16_t *)REG_USB0_RQPKTCNT1)               /* USB0 EPn Request Packet Count Register */
#define pREG_USB0_RQPKTCNT2              ((volatile uint16_t *)REG_USB0_RQPKTCNT2)               /* USB0 EPn Request Packet Count Register */
#define pREG_USB0_RQPKTCNT3              ((volatile uint16_t *)REG_USB0_RQPKTCNT3)               /* USB0 EPn Request Packet Count Register */
#define pREG_USB0_RQPKTCNT4              ((volatile uint16_t *)REG_USB0_RQPKTCNT4)               /* USB0 EPn Request Packet Count Register */
#define pREG_USB0_RQPKTCNT5              ((volatile uint16_t *)REG_USB0_RQPKTCNT5)               /* USB0 EPn Request Packet Count Register */
#define pREG_USB0_RQPKTCNT6              ((volatile uint16_t *)REG_USB0_RQPKTCNT6)               /* USB0 EPn Request Packet Count Register */
#define pREG_USB0_RQPKTCNT7              ((volatile uint16_t *)REG_USB0_RQPKTCNT7)               /* USB0 EPn Request Packet Count Register */
#define pREG_USB0_RQPKTCNT8              ((volatile uint16_t *)REG_USB0_RQPKTCNT8)               /* USB0 EPn Request Packet Count Register */
#define pREG_USB0_RQPKTCNT9              ((volatile uint16_t *)REG_USB0_RQPKTCNT9)               /* USB0 EPn Request Packet Count Register */
#define pREG_USB0_RQPKTCNT10             ((volatile uint16_t *)REG_USB0_RQPKTCNT10)              /* USB0 EPn Request Packet Count Register */
#define pREG_USB0_CT_UCH                 ((volatile uint16_t *)REG_USB0_CT_UCH)                  /* USB0 Chirp Timeout Register */
#define pREG_USB0_CT_HHSRTN              ((volatile uint16_t *)REG_USB0_CT_HHSRTN)               /* USB0 Host High Speed Return to Normal Register */
#define pREG_USB0_CT_HSBT                ((volatile uint16_t *)REG_USB0_CT_HSBT)                 /* USB0 High Speed Timeout Register */
#define pREG_USB0_LPM_ATTR               ((volatile uint16_t *)REG_USB0_LPM_ATTR)                /* USB0 LPM Attribute Register */
#define pREG_USB0_LPM_CTL                ((volatile  uint8_t *)REG_USB0_LPM_CTL)                 /* USB0 LPM Control Register */
#define pREG_USB0_LPM_IEN                ((volatile  uint8_t *)REG_USB0_LPM_IEN)                 /* USB0 LPM Interrupt Enable Register */
#define pREG_USB0_LPM_IRQ                ((volatile  uint8_t *)REG_USB0_LPM_IRQ)                 /* USB0 LPM Interrupt Status Register */
#define pREG_USB0_LPM_FADDR              ((volatile  uint8_t *)REG_USB0_LPM_FADDR)               /* USB0 LPM Function Address Register */
#define pREG_USB0_VBUS_CTL               ((volatile  uint8_t *)REG_USB0_VBUS_CTL)                /* USB0 VBUS Control Register */
#define pREG_USB0_BAT_CHG                ((volatile  uint8_t *)REG_USB0_BAT_CHG)                 /* USB0 Battery Charging Control Register */
#define pREG_USB0_PHY_CTL                ((volatile  uint8_t *)REG_USB0_PHY_CTL)                 /* USB0 PHY Control Register */
#define pREG_USB0_PLL_OSC                ((volatile uint16_t *)REG_USB0_PLL_OSC)                 /* USB0 PLL and Oscillator Control Register */


/* =========================================================================
       RTC0
   ========================================================================= */
#define pREG_RTC0_CLK                    ((volatile uint32_t *)REG_RTC0_CLK)                     /* RTC0 RTC Clock register */
#define pREG_RTC0_ALM                    ((volatile uint32_t *)REG_RTC0_ALM)                     /* RTC0 RTC Alarm register */
#define pREG_RTC0_IEN                    ((volatile uint32_t *)REG_RTC0_IEN)                     /* RTC0 RTC Interrupt Enable Register */
#define pREG_RTC0_STAT                   ((volatile uint32_t *)REG_RTC0_STAT)                    /* RTC0 RTC Status Register */
#define pREG_RTC0_STPWTCH                ((volatile uint32_t *)REG_RTC0_STPWTCH)                 /* RTC0 RTC Stop Watch Register */
#define pREG_RTC0_INIT                   ((volatile uint32_t *)REG_RTC0_INIT)                    /* RTC0 RTC Initialization Register */
#define pREG_RTC0_INITSTAT               ((volatile uint32_t *)REG_RTC0_INITSTAT)                /* RTC0 RTC Initialization Status Register */


/* =========================================================================
       PKTE0
   ========================================================================= */
#define pREG_PKTE0_CTL_STAT              ((volatile uint32_t *)REG_PKTE0_CTL_STAT)               /* PKTE0 Packet Engine Control Register */
#define pREG_PKTE0_SRC_ADDR              ((volatile uint32_t *)REG_PKTE0_SRC_ADDR)               /* PKTE0 Packet Engine Source Address */
#define pREG_PKTE0_DEST_ADDR             ((volatile uint32_t *)REG_PKTE0_DEST_ADDR)              /* PKTE0 Packet Engine Destination Address */
#define pREG_PKTE0_SA_ADDR               ((volatile uint32_t *)REG_PKTE0_SA_ADDR)                /* PKTE0 Packet Engine SA Address */
#define pREG_PKTE0_STATE_ADDR            ((volatile uint32_t *)REG_PKTE0_STATE_ADDR)             /* PKTE0 Packet Engine State Record Address */
#define pREG_PKTE0_USERID                ((volatile uint32_t *)REG_PKTE0_USERID)                 /* PKTE0 Packet Engine User ID */
#define pREG_PKTE0_LEN                   ((volatile uint32_t *)REG_PKTE0_LEN)                    /* PKTE0 Packet Engine Length Register */
#define pREG_PKTE0_CDRBASE_ADDR          ((volatile uint32_t *)REG_PKTE0_CDRBASE_ADDR)           /* PKTE0 PE Command Descriptor Ring Base Address */
#define pREG_PKTE0_RDRBASE_ADDR          ((volatile uint32_t *)REG_PKTE0_RDRBASE_ADDR)           /* PKTE0 PE Result Descriptor Ring Base Address */
#define pREG_PKTE0_RING_CFG              ((volatile uint32_t *)REG_PKTE0_RING_CFG)               /* PKTE0 PE Ring Configuration */
#define pREG_PKTE0_RING_THRESH           ((volatile uint32_t *)REG_PKTE0_RING_THRESH)            /* PKTE0 PE Ring Threshold Registers */
#define pREG_PKTE0_CDSC_CNT              ((volatile uint32_t *)REG_PKTE0_CDSC_CNT)               /* PKTE0 PE Command Descriptor Count Register */
#define pREG_PKTE0_CDSC_INCR             ((volatile uint32_t *)REG_PKTE0_CDSC_INCR)              /* PKTE0 PE Command Descriptor Count Increment Register */
#define pREG_PKTE0_RDSC_DECR             ((volatile uint32_t *)REG_PKTE0_RDSC_DECR)              /* PKTE0 PE Result Descriptor Count Decrement Registers */
#define pREG_PKTE0_RDSC_CNT              ((volatile uint32_t *)REG_PKTE0_RDSC_CNT)               /* PKTE0 PE Result Descriptor Count Registers */
#define pREG_PKTE0_RING_PTR              ((volatile uint32_t *)REG_PKTE0_RING_PTR)               /* PKTE0 PE Ring Pointer Status */
#define pREG_PKTE0_RING_STAT             ((volatile uint32_t *)REG_PKTE0_RING_STAT)              /* PKTE0 PE Ring Status */
#define pREG_PKTE0_CFG                   ((volatile uint32_t *)REG_PKTE0_CFG)                    /* PKTE0 PE Configuration Register */
#define pREG_PKTE0_STAT                  ((volatile uint32_t *)REG_PKTE0_STAT)                   /* PKTE0 PE Status Register */
#define pREG_PKTE0_BUF_THRESH            ((volatile uint32_t *)REG_PKTE0_BUF_THRESH)             /* PKTE0 PE Buffer Threshold Register */
#define pREG_PKTE0_INBUF_CNT             ((volatile uint32_t *)REG_PKTE0_INBUF_CNT)              /* PKTE0 Packet Engine Input Buffer Count Register */
#define pREG_PKTE0_INBUF_INCR            ((volatile uint32_t *)REG_PKTE0_INBUF_INCR)             /* PKTE0 Packet Engine Input Buffer Count Increment Register */
#define pREG_PKTE0_OUTBUF_CNT            ((volatile uint32_t *)REG_PKTE0_OUTBUF_CNT)             /* PKTE0 Packet Engine Output Buffer Count Register */
#define pREG_PKTE0_OUTBUF_DECR           ((volatile uint32_t *)REG_PKTE0_OUTBUF_DECR)            /* PKTE0 Packet Engine Output Buffer Count Decrement Register */
#define pREG_PKTE0_BUF_PTR               ((volatile uint32_t *)REG_PKTE0_BUF_PTR)                /* PKTE0 Packet Engine Buffer Pointer Register */
#define pREG_PKTE0_DMA_CFG               ((volatile uint32_t *)REG_PKTE0_DMA_CFG)                /* PKTE0 Packet Engine DMA Configuration Register */
#define pREG_PKTE0_ENDIAN_CFG            ((volatile uint32_t *)REG_PKTE0_ENDIAN_CFG)             /* PKTE0 Packet Engine Endian Configuration Register */
#define pREG_PKTE0_HLT_CTL               ((volatile uint32_t *)REG_PKTE0_HLT_CTL)                /* PKTE0 PE Halt Control Register */
#define pREG_PKTE0_HLT_STAT              ((volatile uint32_t *)REG_PKTE0_HLT_STAT)               /* PKTE0 PE Halt Status Register */
#define pREG_PKTE0_CONT                  ((volatile uint32_t *)REG_PKTE0_CONT)                   /* PKTE0 PE Continue Register */
#define pREG_PKTE0_CLK_CTL               ((volatile uint32_t *)REG_PKTE0_CLK_CTL)                /* PKTE0 PE Clock Control Register */
#define pREG_PKTE0_IUMSK_STAT            ((volatile uint32_t *)REG_PKTE0_IUMSK_STAT)             /* PKTE0 Interrupt Unmasked Status Register */
#define pREG_PKTE0_IMSK_STAT             ((volatile uint32_t *)REG_PKTE0_IMSK_STAT)              /* PKTE0 Interrupt Masked Status Register */
#define pREG_PKTE0_INT_CLR               ((volatile uint32_t *)REG_PKTE0_INT_CLR)                /* PKTE0 Interrupt Clear Register */
#define pREG_PKTE0_INT_EN                ((volatile uint32_t *)REG_PKTE0_INT_EN)                 /* PKTE0 Interrupt Enable Register */
#define pREG_PKTE0_INT_CFG               ((volatile uint32_t *)REG_PKTE0_INT_CFG)                /* PKTE0 Interrupt Configuration Register */
#define pREG_PKTE0_IMSK_EN               ((volatile uint32_t *)REG_PKTE0_IMSK_EN)                /* PKTE0 Interrupt Mask Enable Register */
#define pREG_PKTE0_IMSK_DIS              ((volatile uint32_t *)REG_PKTE0_IMSK_DIS)               /* PKTE0 Interrupt Mask Disable Register */
#define pREG_PKTE0_SA_CMD0               ((volatile uint32_t *)REG_PKTE0_SA_CMD0)                /* PKTE0 SA Command 0 */
#define pREG_PKTE0_SA_CMD1               ((volatile uint32_t *)REG_PKTE0_SA_CMD1)                /* PKTE0 SA Command 1 */
#define pREG_PKTE0_SA_KEY0               ((volatile uint32_t *)REG_PKTE0_SA_KEY0)                /* PKTE0 SA Key Registers */
#define pREG_PKTE0_SA_KEY1               ((volatile uint32_t *)REG_PKTE0_SA_KEY1)                /* PKTE0 SA Key Registers */
#define pREG_PKTE0_SA_KEY2               ((volatile uint32_t *)REG_PKTE0_SA_KEY2)                /* PKTE0 SA Key Registers */
#define pREG_PKTE0_SA_KEY3               ((volatile uint32_t *)REG_PKTE0_SA_KEY3)                /* PKTE0 SA Key Registers */
#define pREG_PKTE0_SA_KEY4               ((volatile uint32_t *)REG_PKTE0_SA_KEY4)                /* PKTE0 SA Key Registers */
#define pREG_PKTE0_SA_KEY5               ((volatile uint32_t *)REG_PKTE0_SA_KEY5)                /* PKTE0 SA Key Registers */
#define pREG_PKTE0_SA_KEY6               ((volatile uint32_t *)REG_PKTE0_SA_KEY6)                /* PKTE0 SA Key Registers */
#define pREG_PKTE0_SA_KEY7               ((volatile uint32_t *)REG_PKTE0_SA_KEY7)                /* PKTE0 SA Key Registers */
#define pREG_PKTE0_SA_IDIGEST0           ((volatile uint32_t *)REG_PKTE0_SA_IDIGEST0)            /* PKTE0 SA Inner Hash Digest Registers */
#define pREG_PKTE0_SA_IDIGEST1           ((volatile uint32_t *)REG_PKTE0_SA_IDIGEST1)            /* PKTE0 SA Inner Hash Digest Registers */
#define pREG_PKTE0_SA_IDIGEST2           ((volatile uint32_t *)REG_PKTE0_SA_IDIGEST2)            /* PKTE0 SA Inner Hash Digest Registers */
#define pREG_PKTE0_SA_IDIGEST3           ((volatile uint32_t *)REG_PKTE0_SA_IDIGEST3)            /* PKTE0 SA Inner Hash Digest Registers */
#define pREG_PKTE0_SA_IDIGEST4           ((volatile uint32_t *)REG_PKTE0_SA_IDIGEST4)            /* PKTE0 SA Inner Hash Digest Registers */
#define pREG_PKTE0_SA_IDIGEST5           ((volatile uint32_t *)REG_PKTE0_SA_IDIGEST5)            /* PKTE0 SA Inner Hash Digest Registers */
#define pREG_PKTE0_SA_IDIGEST6           ((volatile uint32_t *)REG_PKTE0_SA_IDIGEST6)            /* PKTE0 SA Inner Hash Digest Registers */
#define pREG_PKTE0_SA_IDIGEST7           ((volatile uint32_t *)REG_PKTE0_SA_IDIGEST7)            /* PKTE0 SA Inner Hash Digest Registers */
#define pREG_PKTE0_SA_ODIGEST0           ((volatile uint32_t *)REG_PKTE0_SA_ODIGEST0)            /* PKTE0 SA Outer Hash Digest Registers */
#define pREG_PKTE0_SA_ODIGEST1           ((volatile uint32_t *)REG_PKTE0_SA_ODIGEST1)            /* PKTE0 SA Outer Hash Digest Registers */
#define pREG_PKTE0_SA_ODIGEST2           ((volatile uint32_t *)REG_PKTE0_SA_ODIGEST2)            /* PKTE0 SA Outer Hash Digest Registers */
#define pREG_PKTE0_SA_ODIGEST3           ((volatile uint32_t *)REG_PKTE0_SA_ODIGEST3)            /* PKTE0 SA Outer Hash Digest Registers */
#define pREG_PKTE0_SA_ODIGEST4           ((volatile uint32_t *)REG_PKTE0_SA_ODIGEST4)            /* PKTE0 SA Outer Hash Digest Registers */
#define pREG_PKTE0_SA_ODIGEST5           ((volatile uint32_t *)REG_PKTE0_SA_ODIGEST5)            /* PKTE0 SA Outer Hash Digest Registers */
#define pREG_PKTE0_SA_ODIGEST6           ((volatile uint32_t *)REG_PKTE0_SA_ODIGEST6)            /* PKTE0 SA Outer Hash Digest Registers */
#define pREG_PKTE0_SA_ODIGEST7           ((volatile uint32_t *)REG_PKTE0_SA_ODIGEST7)            /* PKTE0 SA Outer Hash Digest Registers */
#define pREG_PKTE0_SA_SPI                ((volatile uint32_t *)REG_PKTE0_SA_SPI)                 /* PKTE0 SA SPI Register */
#define pREG_PKTE0_SA_SEQNUM0            ((volatile uint32_t *)REG_PKTE0_SA_SEQNUM0)             /* PKTE0 SA Sequence Number Register */
#define pREG_PKTE0_SA_SEQNUM1            ((volatile uint32_t *)REG_PKTE0_SA_SEQNUM1)             /* PKTE0 SA Sequence Number Register */
#define pREG_PKTE0_SA_SEQNUM_MSK0        ((volatile uint32_t *)REG_PKTE0_SA_SEQNUM_MSK0)         /* PKTE0 SA Sequence Number Mask Registers */
#define pREG_PKTE0_SA_SEQNUM_MSK1        ((volatile uint32_t *)REG_PKTE0_SA_SEQNUM_MSK1)         /* PKTE0 SA Sequence Number Mask Registers */
#define pREG_PKTE0_SA_RDY                ((volatile uint32_t *)REG_PKTE0_SA_RDY)                 /* PKTE0 SA Ready Indicator */
#define pREG_PKTE0_SA_NONCE              ((volatile uint32_t *)REG_PKTE0_SA_NONCE)               /* PKTE0 SA Initialization Vector Register */
#define pREG_PKTE0_STATE_IV0             ((volatile uint32_t *)REG_PKTE0_STATE_IV0)              /* PKTE0 State Initialization Vector Registers */
#define pREG_PKTE0_STATE_IV1             ((volatile uint32_t *)REG_PKTE0_STATE_IV1)              /* PKTE0 State Initialization Vector Registers */
#define pREG_PKTE0_STATE_IV2             ((volatile uint32_t *)REG_PKTE0_STATE_IV2)              /* PKTE0 State Initialization Vector Registers */
#define pREG_PKTE0_STATE_IV3             ((volatile uint32_t *)REG_PKTE0_STATE_IV3)              /* PKTE0 State Initialization Vector Registers */
#define pREG_PKTE0_STATE_BYTE_CNT0       ((volatile uint32_t *)REG_PKTE0_STATE_BYTE_CNT0)        /* PKTE0 State Hash Byte Count Registers */
#define pREG_PKTE0_STATE_BYTE_CNT1       ((volatile uint32_t *)REG_PKTE0_STATE_BYTE_CNT1)        /* PKTE0 State Hash Byte Count Registers */
#define pREG_PKTE0_STATE_IDIGEST0        ((volatile uint32_t *)REG_PKTE0_STATE_IDIGEST0)         /* PKTE0 State Inner Digest Registers */
#define pREG_PKTE0_STATE_IDIGEST1        ((volatile uint32_t *)REG_PKTE0_STATE_IDIGEST1)         /* PKTE0 State Inner Digest Registers */
#define pREG_PKTE0_STATE_IDIGEST2        ((volatile uint32_t *)REG_PKTE0_STATE_IDIGEST2)         /* PKTE0 State Inner Digest Registers */
#define pREG_PKTE0_STATE_IDIGEST3        ((volatile uint32_t *)REG_PKTE0_STATE_IDIGEST3)         /* PKTE0 State Inner Digest Registers */
#define pREG_PKTE0_STATE_IDIGEST4        ((volatile uint32_t *)REG_PKTE0_STATE_IDIGEST4)         /* PKTE0 State Inner Digest Registers */
#define pREG_PKTE0_STATE_IDIGEST5        ((volatile uint32_t *)REG_PKTE0_STATE_IDIGEST5)         /* PKTE0 State Inner Digest Registers */
#define pREG_PKTE0_STATE_IDIGEST6        ((volatile uint32_t *)REG_PKTE0_STATE_IDIGEST6)         /* PKTE0 State Inner Digest Registers */
#define pREG_PKTE0_STATE_IDIGEST7        ((volatile uint32_t *)REG_PKTE0_STATE_IDIGEST7)         /* PKTE0 State Inner Digest Registers */
#define pREG_PKTE0_ARC4STATE_BUF         ((volatile uint32_t *)REG_PKTE0_ARC4STATE_BUF)          /* PKTE0 Starting Entry of 256-byte ARC4 State Buffer */
#define pREG_PKTE0_DATAIO_BUF            ((volatile uint32_t *)REG_PKTE0_DATAIO_BUF)             /* PKTE0 Starting Entry of 256-byte Data Input/Output Buffer */


/* =========================================================================
       TRNG0
   ========================================================================= */
#define pREG_TRNG0_OUTPUT0               ((volatile uint32_t *)REG_TRNG0_OUTPUT0)                /* TRNG0 TRNG Output Registers */
#define pREG_TRNG0_OUTPUT1               ((volatile uint32_t *)REG_TRNG0_OUTPUT1)                /* TRNG0 TRNG Output Registers */
#define pREG_TRNG0_OUTPUT2               ((volatile uint32_t *)REG_TRNG0_OUTPUT2)                /* TRNG0 TRNG Output Registers */
#define pREG_TRNG0_OUTPUT3               ((volatile uint32_t *)REG_TRNG0_OUTPUT3)                /* TRNG0 TRNG Output Registers */
#define pREG_TRNG0_INPUT0                ((volatile uint32_t *)REG_TRNG0_INPUT0)                 /* TRNG0 TRNG Input Registers */
#define pREG_TRNG0_INPUT1                ((volatile uint32_t *)REG_TRNG0_INPUT1)                 /* TRNG0 TRNG Input Registers */
#define pREG_TRNG0_INTACK                ((volatile uint32_t *)REG_TRNG0_INTACK)                 /* TRNG0 TRNG Interrupt Acknowledge Register */
#define pREG_TRNG0_STAT                  ((volatile uint32_t *)REG_TRNG0_STAT)                   /* TRNG0 TRNG Status Register */
#define pREG_TRNG0_CTL                   ((volatile uint32_t *)REG_TRNG0_CTL)                    /* TRNG0 TRNG Control Register */
#define pREG_TRNG0_CFG                   ((volatile uint32_t *)REG_TRNG0_CFG)                    /* TRNG0 TRNG Configuration Register */
#define pREG_TRNG0_ALMCNT                ((volatile uint32_t *)REG_TRNG0_ALMCNT)                 /* TRNG0 TRNG Alarm Counter Register */
#define pREG_TRNG0_FROEN                 ((volatile uint32_t *)REG_TRNG0_FROEN)                  /* TRNG0 TRNG FRO Enable Register */
#define pREG_TRNG0_FRODETUNE             ((volatile uint32_t *)REG_TRNG0_FRODETUNE)              /* TRNG0 TRNG FRO De-tune Register */
#define pREG_TRNG0_ALMMSK                ((volatile uint32_t *)REG_TRNG0_ALMMSK)                 /* TRNG0 TRNG Alarm Mask Register */
#define pREG_TRNG0_ALMSTP                ((volatile uint32_t *)REG_TRNG0_ALMSTP)                 /* TRNG0 TRNG Alarm Stop Register */
#define pREG_TRNG0_CNT                   ((volatile uint32_t *)REG_TRNG0_CNT)                    /* TRNG0 TRNG Counter Access Register */
#define pREG_TRNG0_KEY0                  ((volatile uint32_t *)REG_TRNG0_KEY0)                   /* TRNG0 Post-Process Key Registers */
#define pREG_TRNG0_KEY1                  ((volatile uint32_t *)REG_TRNG0_KEY1)                   /* TRNG0 Post-Process Key Registers */
#define pREG_TRNG0_KEY2                  ((volatile uint32_t *)REG_TRNG0_KEY2)                   /* TRNG0 Post-Process Key Registers */
#define pREG_TRNG0_KEY3                  ((volatile uint32_t *)REG_TRNG0_KEY3)                   /* TRNG0 Post-Process Key Registers */
#define pREG_TRNG0_KEY4                  ((volatile uint32_t *)REG_TRNG0_KEY4)                   /* TRNG0 Post-Process Key Registers */
#define pREG_TRNG0_KEY5                  ((volatile uint32_t *)REG_TRNG0_KEY5)                   /* TRNG0 Post-Process Key Registers */
#define pREG_TRNG0_RUNCNT                ((volatile uint32_t *)REG_TRNG0_RUNCNT)                 /* TRNG0 TRNG Run Test State and Result Registers */
#define pREG_TRNG0_RUN1                  ((volatile uint32_t *)REG_TRNG0_RUN1)                   /* TRNG0 TRNG Run Test State and Result Registers */
#define pREG_TRNG0_RUN2                  ((volatile uint32_t *)REG_TRNG0_RUN2)                   /* TRNG0 TRNG Run Test State and Result Registers */
#define pREG_TRNG0_RUN3                  ((volatile uint32_t *)REG_TRNG0_RUN3)                   /* TRNG0 TRNG Run Test State and Result Registers */
#define pREG_TRNG0_RUN4                  ((volatile uint32_t *)REG_TRNG0_RUN4)                   /* TRNG0 TRNG Run Test State and Result Registers */
#define pREG_TRNG0_RUN5                  ((volatile uint32_t *)REG_TRNG0_RUN5)                   /* TRNG0 TRNG Run Test State and Result Registers */
#define pREG_TRNG0_RUN6                  ((volatile uint32_t *)REG_TRNG0_RUN6)                   /* TRNG0 TRNG Run Test State and Result Registers */
#define pREG_TRNG0_MONOBITCNT            ((volatile uint32_t *)REG_TRNG0_MONOBITCNT)             /* TRNG0 TRNG Monobit Test Result Register */
#define pREG_TRNG0_V0                    ((volatile uint32_t *)REG_TRNG0_V0)                     /* TRNG0 TRNG Post-Process aVa Value Registers */
#define pREG_TRNG0_V1                    ((volatile uint32_t *)REG_TRNG0_V1)                     /* TRNG0 TRNG Post-Process aVa Value Registers */
#define pREG_TRNG0_POKER0                ((volatile uint32_t *)REG_TRNG0_POKER0)                 /* TRNG0 TRNG Poker Test Result Registers */
#define pREG_TRNG0_POKER1                ((volatile uint32_t *)REG_TRNG0_POKER1)                 /* TRNG0 TRNG Poker Test Result Registers */
#define pREG_TRNG0_POKER2                ((volatile uint32_t *)REG_TRNG0_POKER2)                 /* TRNG0 TRNG Poker Test Result Registers */
#define pREG_TRNG0_POKER3                ((volatile uint32_t *)REG_TRNG0_POKER3)                 /* TRNG0 TRNG Poker Test Result Registers */
#define pREG_TRNG0_TEST                  ((volatile uint32_t *)REG_TRNG0_TEST)                   /* TRNG0 TRNG Test Register */
#define pREG_TRNG0_BLKCNT                ((volatile uint32_t *)REG_TRNG0_BLKCNT)                 /* TRNG0 TRNG Block Count Register */


/* =========================================================================
       PKA0
   ========================================================================= */
#define pREG_PKA0_APTR                   ((volatile uint32_t *)REG_PKA0_APTR)                    /* PKA0 PKA Vector_A Address */
#define pREG_PKA0_BPTR                   ((volatile uint32_t *)REG_PKA0_BPTR)                    /* PKA0 PKA Vector_B Address */
#define pREG_PKA0_CPTR                   ((volatile uint32_t *)REG_PKA0_CPTR)                    /* PKA0 PKA Vector_C Address */
#define pREG_PKA0_DPTR                   ((volatile uint32_t *)REG_PKA0_DPTR)                    /* PKA0 PKA Vector_D Address */
#define pREG_PKA0_ALEN                   ((volatile uint32_t *)REG_PKA0_ALEN)                    /* PKA0 PKA Vector_A Length */
#define pREG_PKA0_BLEN                   ((volatile uint32_t *)REG_PKA0_BLEN)                    /* PKA0 PKA Vector_B Length */
#define pREG_PKA0_SHIFT                  ((volatile uint32_t *)REG_PKA0_SHIFT)                   /* PKA0 PKA Bit Shift Value */
#define pREG_PKA0_FUNC                   ((volatile uint32_t *)REG_PKA0_FUNC)                    /* PKA0 PKA Function */
#define pREG_PKA0_COMPARE                ((volatile uint32_t *)REG_PKA0_COMPARE)                 /* PKA0 PKA Compare Result */
#define pREG_PKA0_RESULTMSW              ((volatile uint32_t *)REG_PKA0_RESULTMSW)               /* PKA0 PKA Most-Significant-Word of Result Vector */
#define pREG_PKA0_DIVMSW                 ((volatile uint32_t *)REG_PKA0_DIVMSW)                  /* PKA0 PKA Most-Significant-Word of Divide Remainder */
#define pREG_PKA0_RAM                    ((volatile uint32_t *)REG_PKA0_RAM)                     /* PKA0 Starting Entry of 4KB RAM space */


/* =========================================================================
       PKIC0
   ========================================================================= */
#define pREG_PKIC0_POL_CTL               ((volatile uint32_t *)REG_PKIC0_POL_CTL)                /* PKIC0 Polarity Control Register */
#define pREG_PKIC0_TYPE_CTL              ((volatile uint32_t *)REG_PKIC0_TYPE_CTL)               /* PKIC0 Type Control Register */
#define pREG_PKIC0_EN_CTL                ((volatile uint32_t *)REG_PKIC0_EN_CTL)                 /* PKIC0 Enable Control Register */
#define pREG_PKIC0_RAW_STAT              ((volatile uint32_t *)REG_PKIC0_RAW_STAT)               /* PKIC0 Raw Status Register */
#define pREG_PKIC0_EN_SET                ((volatile uint32_t *)REG_PKIC0_EN_SET)                 /* PKIC0 Enable Set Register */
#define pREG_PKIC0_EN_STAT               ((volatile uint32_t *)REG_PKIC0_EN_STAT)                /* PKIC0 Enabled Status Register */
#define pREG_PKIC0_ACK                   ((volatile uint32_t *)REG_PKIC0_ACK)                    /* PKIC0 Acknowledge Register */
#define pREG_PKIC0_EN_CLR                ((volatile uint32_t *)REG_PKIC0_EN_CLR)                 /* PKIC0 Enable Clear Register */


/* =========================================================================
       SCB0
   ========================================================================= */
#define pREG_SCB0_IB7_SYNC               ((volatile uint32_t *)REG_SCB0_IB7_SYNC)                /* SCB0 DDR Interface Block Sync Mode */
#define pREG_SCB0_MST00_RQOS             ((volatile uint32_t *)REG_SCB0_MST00_RQOS)              /* SCB0 DDE0 Read Quality of Service */
#define pREG_SCB0_MST00_WQOS             ((volatile uint32_t *)REG_SCB0_MST00_WQOS)              /* SCB0 DDE0 Write Quality of Service */
#define pREG_SCB0_MST01_RQOS             ((volatile uint32_t *)REG_SCB0_MST01_RQOS)              /* SCB0 DDE1 Read Quality of Service */
#define pREG_SCB0_MST01_WQOS             ((volatile uint32_t *)REG_SCB0_MST01_WQOS)              /* SCB0 DDE1 Write Quality of Service */
#define pREG_SCB0_MST02_RQOS             ((volatile uint32_t *)REG_SCB0_MST02_RQOS)              /* SCB0 DDE2 Read Quality of Service */
#define pREG_SCB0_MST02_WQOS             ((volatile uint32_t *)REG_SCB0_MST02_WQOS)              /* SCB0 DDE2 Write Quality of Service */
#define pREG_SCB0_MST03_RQOS             ((volatile uint32_t *)REG_SCB0_MST03_RQOS)              /* SCB0 DDE3 Read Quality of Service */
#define pREG_SCB0_MST03_WQOS             ((volatile uint32_t *)REG_SCB0_MST03_WQOS)              /* SCB0 DDE3 Write Quality of Service */
#define pREG_SCB0_MST04_RQOS             ((volatile uint32_t *)REG_SCB0_MST04_RQOS)              /* SCB0 DDE4 Read Quality of Service */
#define pREG_SCB0_MST04_WQOS             ((volatile uint32_t *)REG_SCB0_MST04_WQOS)              /* SCB0 DDE4 Write Quality of Service */
#define pREG_SCB0_MST05_RQOS             ((volatile uint32_t *)REG_SCB0_MST05_RQOS)              /* SCB0 DDE5 Read Quality of Service */
#define pREG_SCB0_MST05_WQOS             ((volatile uint32_t *)REG_SCB0_MST05_WQOS)              /* SCB0 DDE5 Write Quality of Service */
#define pREG_SCB0_MST06_RQOS             ((volatile uint32_t *)REG_SCB0_MST06_RQOS)              /* SCB0 DDE6 Read Quality of Service */
#define pREG_SCB0_MST06_WQOS             ((volatile uint32_t *)REG_SCB0_MST06_WQOS)              /* SCB0 DDE6 Write Quality of Service */
#define pREG_SCB0_MST07_RQOS             ((volatile uint32_t *)REG_SCB0_MST07_RQOS)              /* SCB0 DDE7 Read Quality of Service */
#define pREG_SCB0_MST07_WQOS             ((volatile uint32_t *)REG_SCB0_MST07_WQOS)              /* SCB0 DDE7 Write Quality of Service */
#define pREG_SCB0_MST08_RQOS             ((volatile uint32_t *)REG_SCB0_MST08_RQOS)              /* SCB0 DDE8 Read Quality of Service */
#define pREG_SCB0_MST08_WQOS             ((volatile uint32_t *)REG_SCB0_MST08_WQOS)              /* SCB0 DDE8 Write Quality of Service */
#define pREG_SCB0_MST09_RQOS             ((volatile uint32_t *)REG_SCB0_MST09_RQOS)              /* SCB0 DDE9 Read Quality of Service */
#define pREG_SCB0_MST09_WQOS             ((volatile uint32_t *)REG_SCB0_MST09_WQOS)              /* SCB0 DDE9 Write Quality of Service */
#define pREG_SCB0_MST10_RQOS             ((volatile uint32_t *)REG_SCB0_MST10_RQOS)              /* SCB0 DDE10 Read Quality of Service */
#define pREG_SCB0_MST10_WQOS             ((volatile uint32_t *)REG_SCB0_MST10_WQOS)              /* SCB0 DDE10 Write Quality of Service */
#define pREG_SCB0_MST11_RQOS             ((volatile uint32_t *)REG_SCB0_MST11_RQOS)              /* SCB0 DDE11 Read Quality of Service */
#define pREG_SCB0_MST11_WQOS             ((volatile uint32_t *)REG_SCB0_MST11_WQOS)              /* SCB0 DDE11 Write Quality of Service */
#define pREG_SCB0_MST12_RQOS             ((volatile uint32_t *)REG_SCB0_MST12_RQOS)              /* SCB0 DDE12 Read Quality of Service */
#define pREG_SCB0_MST12_WQOS             ((volatile uint32_t *)REG_SCB0_MST12_WQOS)              /* SCB0 DDE12 Write Quality of Service */
#define pREG_SCB0_MST13_RQOS             ((volatile uint32_t *)REG_SCB0_MST13_RQOS)              /* SCB0 DDE13 Read Quality of Service */
#define pREG_SCB0_MST13_WQOS             ((volatile uint32_t *)REG_SCB0_MST13_WQOS)              /* SCB0 DDE13 Write Quality of Service */
#define pREG_SCB0_MST14_RQOS             ((volatile uint32_t *)REG_SCB0_MST14_RQOS)              /* SCB0 DDE14 Read Quality of Service */
#define pREG_SCB0_MST14_WQOS             ((volatile uint32_t *)REG_SCB0_MST14_WQOS)              /* SCB0 DDE14 Write Quality of Service */
#define pREG_SCB0_MST15_RQOS             ((volatile uint32_t *)REG_SCB0_MST15_RQOS)              /* SCB0 DDE15 Read Quality of Service */
#define pREG_SCB0_MST15_WQOS             ((volatile uint32_t *)REG_SCB0_MST15_WQOS)              /* SCB0 DDE15 Write Quality of Service */
#define pREG_SCB0_MST16_RQOS             ((volatile uint32_t *)REG_SCB0_MST16_RQOS)              /* SCB0 DDE16 Read Quality of Service */
#define pREG_SCB0_MST16_WQOS             ((volatile uint32_t *)REG_SCB0_MST16_WQOS)              /* SCB0 DDE16 Write Quality of Service */
#define pREG_SCB0_MST17_RQOS             ((volatile uint32_t *)REG_SCB0_MST17_RQOS)              /* SCB0 DDE17 Read Quality of Service */
#define pREG_SCB0_MST17_WQOS             ((volatile uint32_t *)REG_SCB0_MST17_WQOS)              /* SCB0 DDE17 Write Quality of Service */
#define pREG_SCB0_MST22_RQOS             ((volatile uint32_t *)REG_SCB0_MST22_RQOS)              /* SCB0 USB0 Read Quality of Service */
#define pREG_SCB0_MST22_WQOS             ((volatile uint32_t *)REG_SCB0_MST22_WQOS)              /* SCB0 USB0 Write Quality of Service */
#define pREG_SCB0_MST25_RQOS             ((volatile uint32_t *)REG_SCB0_MST25_RQOS)              /* SCB0 MSI0 Read Quality of Service */
#define pREG_SCB0_MST25_WQOS             ((volatile uint32_t *)REG_SCB0_MST25_WQOS)              /* SCB0 MSI0 Write Quality of Service */
#define pREG_SCB0_IB6_SYNC               ((volatile uint32_t *)REG_SCB0_IB6_SYNC)                /* SCB0 Crypto Modules Sync Mode */
#define pREG_SCB0_MST26_RQOS             ((volatile uint32_t *)REG_SCB0_MST26_RQOS)              /* SCB0 Crypto Modules Read Quality of Service */
#define pREG_SCB0_MST26_WQOS             ((volatile uint32_t *)REG_SCB0_MST26_WQOS)              /* SCB0 Crypto Modules Write Quality of Service */
#define pREG_SCB0_MST23_RQOS             ((volatile uint32_t *)REG_SCB0_MST23_RQOS)              /* SCB0 Memory Interface Read Quality of Service */
#define pREG_SCB0_MST23_WQOS             ((volatile uint32_t *)REG_SCB0_MST23_WQOS)              /* SCB0 Memory Interface Write Quality of Service */
#define pREG_SCB0_MST24_RQOS             ((volatile uint32_t *)REG_SCB0_MST24_RQOS)              /* SCB0 MMR Read Quality of Service */
#define pREG_SCB0_MST24_WQOS             ((volatile uint32_t *)REG_SCB0_MST24_WQOS)              /* SCB0 MMR Write Quality of Service */
#define pREG_SCB0_MST18_RQOS             ((volatile uint32_t *)REG_SCB0_MST18_RQOS)              /* SCB0 DDE18 Read Quality of Service */
#define pREG_SCB0_MST18_WQOS             ((volatile uint32_t *)REG_SCB0_MST18_WQOS)              /* SCB0 DDE18 Write Quality of Service */
#define pREG_SCB0_MST19_RQOS             ((volatile uint32_t *)REG_SCB0_MST19_RQOS)              /* SCB0 DDE19 Read Quality of Service */
#define pREG_SCB0_MST19_WQOS             ((volatile uint32_t *)REG_SCB0_MST19_WQOS)              /* SCB0 DDE19 Write Quality of Service */
#define pREG_SCB0_MST20_RQOS             ((volatile uint32_t *)REG_SCB0_MST20_RQOS)              /* SCB0 DDE20 Read Quality of Service */
#define pREG_SCB0_MST20_WQOS             ((volatile uint32_t *)REG_SCB0_MST20_WQOS)              /* SCB0 DDE20 Write Quality of Service */
#define pREG_SCB0_MST21_RQOS             ((volatile uint32_t *)REG_SCB0_MST21_RQOS)              /* SCB0 DDE21 Read Quality of Service */
#define pREG_SCB0_MST21_WQOS             ((volatile uint32_t *)REG_SCB0_MST21_WQOS)              /* SCB0 DDE21 Write Quality of Service */
#define pREG_SCB0_MST27_RQOS             ((volatile uint32_t *)REG_SCB0_MST27_RQOS)              /* SCB0 ETR Read Quality of Service */
#define pREG_SCB0_MST27_WQOS             ((volatile uint32_t *)REG_SCB0_MST27_WQOS)              /* SCB0 ETR Write Quality of Service */
#define pREG_SCB0_MST28_RQOS             ((volatile uint32_t *)REG_SCB0_MST28_RQOS)              /* SCB0 SPIHP0 Read Quality of Service */
#define pREG_SCB0_MST28_WQOS             ((volatile uint32_t *)REG_SCB0_MST28_WQOS)              /* SCB0 SPIHP0 Write Quality of Service */
#define pREG_SCB0_MST29_RQOS             ((volatile uint32_t *)REG_SCB0_MST29_RQOS)              /* SCB0 DAP Read Quality of Service */
#define pREG_SCB0_MST29_WQOS             ((volatile uint32_t *)REG_SCB0_MST29_WQOS)              /* SCB0 DAP Write Quality of Service */
#define pREG_SCB0_MST30_SYNC             ((volatile uint32_t *)REG_SCB0_MST30_SYNC)              /* SCB0 Interface Block IB4 Sync Mode */
#define pREG_SCB0_MST31_SYNC             ((volatile uint32_t *)REG_SCB0_MST31_SYNC)              /* SCB0 Interface Block IB5 Sync Mode */

#ifdef _MISRA_RULES
#pragma diag(pop)
#endif /* _MISRA_RULES */

#endif	/* end ifndef _CDEF_BF706_H */
