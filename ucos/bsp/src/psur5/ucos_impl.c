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
*                               Cortex-R5 (psur5) Implementation Specific
*
* File : ucos_impl.c
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                             INCLUDE FILES
*********************************************************************************************************
*/

#include  <app_cfg.h>
#include  <cpu_core.h>
#include  <cpu.h>
#include  <ucos_bsp.h>
#include  <ucos_int.h>

extern void _install_ucos_vector_table(void);

void UCOS_LowLevelInit (void)
{
    UCOS_IntInit();                                             /* Initialize interrupt controller.                     */
}

void UCOS_StartupInit (void)
{
    _install_ucos_vector_table();
}

