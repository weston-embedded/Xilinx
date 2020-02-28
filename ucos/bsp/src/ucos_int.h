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
*                                        INTERRUPT MANAGEMENT
*
* File : ucos_int.h
*********************************************************************************************************
*/

#ifndef  UCOS_INT_PRESENT
#define  UCOS_INT_PRESENT

#ifdef __cplusplus
extern "C" {
#endif

#include  <lib_def.h>
#include  <cpu.h>
#include  <ucos_int_impl.h>
#include  <xil_exception.h>

/*
*********************************************************************************************************
*                                               DEFINES
*********************************************************************************************************
*/

#define  UCOS_INT_TYPE_LEVEL 0
#define  UCOS_INT_TYPE_EDGE 1


/*
*********************************************************************************************************
*                                         FUNCTION PROTOTYPES
*********************************************************************************************************
*/

CPU_BOOLEAN UCOS_IntInit (void);

CPU_BOOLEAN UCOS_IntSrcEn (CPU_INT32U int_id);

CPU_BOOLEAN UCOS_IntSrcDis (CPU_INT32U int_id);

CPU_BOOLEAN UCOS_IntPrioSet (CPU_INT32U int_id, CPU_INT32U int_prio);

CPU_BOOLEAN UCOS_IntTargetSet (CPU_INT32U int_id, CPU_INT32U int_target_list);

CPU_BOOLEAN UCOS_IntTypeSet (CPU_INT32U int_id, UCOS_INT_TYPE type);

CPU_BOOLEAN UCOS_IntVectSet (CPU_INT32U         int_id,
                             CPU_INT32U         int_prio,
                             CPU_INT08U         int_target_list,
                             UCOS_INT_FNCT_PTR  int_fnct,
                             void              *p_int_arg);

#endif /* UCOS_INT_PRESENT */

#ifdef __cplusplus
}
#endif