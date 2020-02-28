/*
*********************************************************************************************************
*                                             uCOS XSDK BSP
*
*                    Copyright 2014-2020 Silicon Laboratories Inc. www.silabs.com
*
*                                 SPDX-License-Identifier: APACHE-2.0
*
*               This software is subject to an open source license and is distributed by
*                Silicon Laboratories Inc. pursuant to the terms of the Apache License,
*                    Version 2.0 available at www.apache.org/licenses/LICENSE-2.0.
*
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                Cortex-A9 (ps7) Interrupt Management
*
* File : ucos_int_impl.h
*********************************************************************************************************
*/

#ifndef  UCOS_INT_IMPL_PRESENT
#define  UCOS_INT_IMPL_PRESENT

#ifdef __cplusplus
extern "C" {
#endif

#include  <lib_def.h>
#include  <cpu.h>
#include  <xil_exception.h>

typedef  Xil_InterruptHandler  UCOS_INT_FNCT_PTR;
typedef  CPU_INT32U  UCOS_INT_TYPE;

#endif /* UCOS_INT_IMPL_PRESENT */

#ifdef __cplusplus
}
#endif
