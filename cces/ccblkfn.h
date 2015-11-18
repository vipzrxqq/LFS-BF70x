#pragma once
#pragma system_header /* ccblkfn.h */
/************************************************************************
 *
 * ccblkfn.h
 *
 * (c) Copyright 2001-2014 Analog Devices, Inc.  All rights reserved.
 *
 ************************************************************************/

/* ccblkfn definitions */

#ifndef _CCBLKFN_H
#define _CCBLKFN_H

#include <stdlib.h>
  /* include builtins.h to define prototype all compiler builtins (intrinsics) 
  ** and define shortnames inline functions for each  
  */
#include <builtins.h>
#include <sys/anomaly_macros_rtl.h>

#include <sys/adi_core.h>

  /* disable misra diagnostics as necessary */
#if defined(_MISRA_2004_RULES) || defined(_MISRA_2012_RULES)
#pragma diag(push)
#ifdef _MISRA_2012_RULES
#pragma diag(suppress:misra2012_rule_11_3: "ADI header allows conversions between pointer types")
#pragma diag(suppress:misra2012_rule_20_1:"#include after declaration")
#else
#pragma diag(suppress:misra_rule_5_6:"ADI header will re-use identifiers")
#pragma diag(suppress:misra_rule_5_7:"ADI header will re-use identifiers")
#pragma diag(suppress:misra_rule_6_3:"ADI header allows use of basic types")
#pragma diag(suppress:misra_rule_8_1:"ADI header uses inline functions")
#pragma diag(suppress:misra_rule_8_5:"ADI header uses inline functions")
#pragma diag(suppress:misra_rule_11_2: "ADI header allows conversions between pointer types")
#pragma diag(suppress:misra_rule_11_3: "ADI header allows conversions between pointer types")
#pragma diag(suppress:misra_rule_11_4: "ADI header allows conversions between pointer types")
#pragma diag(suppress:misra_rule_11_5: "ADI header allows conversions between pointer types")
#pragma diag(suppress:misra_rule_19_1:"#include after defines")
#pragma diag(suppress:misra_rule_19_4:"ADI header allows any substitution text")
#pragma diag(suppress:misra_rule_19_7:"ADI header allows function macros")
#pragma diag(suppress:misra_rule_19_14:"ADI header allows non-misra use of defined() macro")
#endif /* _MISRA_2012_RULES */
#endif /* defined(_MISRA_2004_RULES) || defined(_MISRA_2012_RULES) */

#ifdef __cplusplus
extern "C" {
#endif

/* These are provided for backwards compatibility, but the
** definitions in builtins.h should be used in preference.
*/

#define __lvitmax2x16(A, B, C, D, E) { \
  (D) = __builtin_lvitmax2x16_r1((A), (B), (C)); \
  (E) = __builtin_lvitmax2x16_r2(D); \
}

#define __rvitmax2x16(A, B, C, D, E) { \
  (D) = __builtin_rvitmax2x16_r1((A), (B), (C)); \
  (E) = __builtin_rvitmax2x16_r2(D); \
}

#define __lvitmax1x16(A, B, C, D) { \
  (C) = __builtin_lvitmax1x16_r1((A), (B)); \
  (D) = __builtin_lvitmax1x16_r2(C); \
}

#define __rvitmax1x16(A,B,C,D) { \
  (C) = __builtin_rvitmax1x16_r1((A),(B)); \
  (D) = __builtin_rvitmax1x16_r2(C); \
}

#define __builtin_lvitmax2x16 __lvitmax2x16
#define __builtin_rvitmax2x16 __rvitmax2x16
#define __builtin_lvitmax1x16 __lvitmax1x16
#define __builtin_rvitmax1x16 __rvitmax1x16

/* halt() and abort() operations are no longer supported by the simulators.
** Invoke the _Exit() system call, which circumvents exit()'s clean-up.
*/

#define sys_halt() _Exit(1)

#if !defined(abort)

#define sys_abort() _Exit(1)

#endif

/* Copy from L1 Instruction memory */
void *_l1_memcpy(void *datap, const void *instrp, size_t n);

/* Copy to L1 Instruction memory */
void *_memcpy_l1(void *instrp, const void *datap, size_t n);

/*
** Routines for set/unsetting atomic access bit in value pointed to.
** These routines use the TESTSET instruction to gain exclusive access
** to a flag variable.
**
** Obtaining the flag provides atomic access for the core that claims
** the flag that is passed in.
**
** NOTE: It is assumed that the routines will be called in a lock/unlock
**       order.  No checking is performed in the unlock routine to ensure
**       that the current core has the lock.  As long as the routines
**       are used correctly there is no need for this functionality.
**
** For Multi-Core Processors Only
*/

#include <sys/mc_typedef.h>
#pragma inline
#pragma always_inline
static void adi_acquire_lock(testset_t *_t) {
  __builtin_csync();
  while(__builtin_testset((char *) _t)==0) {
    __builtin_csync();
  }
}

#pragma inline
#pragma always_inline
static int adi_try_lock(testset_t *_t) {
  int rtn;
  __builtin_csync();
  rtn = __builtin_testset((char *) _t);
  return rtn;
}

#pragma inline
#pragma always_inline
static void adi_release_lock(testset_t *_t) {
  __builtin_untestset((char *) _t);
  __builtin_ssync();
}

/* Legacy routines - will be deprecated */

#pragma inline
#pragma always_inline
static void claim_atomic_access(testset_t *_t) {
  adi_acquire_lock(_t);
}

#pragma inline
#pragma always_inline
static void release_atomic_access(testset_t *_t) {
  adi_release_lock(_t);
}

#ifdef __cplusplus
} /* extern "C" */
#endif

#if defined(_MISRA_2004_RULES) || defined(_MISRA_2012_RULES)
#pragma diag(pop)
#endif /* defined(_MISRA_2004_RULES) || defined(_MISRA_2012_RULES) */

#endif  /* _CCBLKFN_H */
