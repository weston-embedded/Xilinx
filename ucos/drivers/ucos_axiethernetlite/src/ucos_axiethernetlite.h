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
*                                    MICRIUM BOARD SUPPORT PACKAGE
*                                           AXI ETHERNETLITE
*
* File : ucos_axiethernetlite.h
*********************************************************************************************************
*/

#ifndef  UCOS_AXIETHERNETLITE_PRESENT
#define  UCOS_AXIETHERNETLITE_PRESENT


/*
*********************************************************************************************************
*                                             INCLUDE FILES
*********************************************************************************************************
*/

#include <lib_def.h>
#include <cpu.h>

/*
*********************************************************************************************************
*                                        STRUCTURE DEFINITIONS
*********************************************************************************************************
*/


typedef struct {
    CPU_INT32U  DeviceId;
    CPU_INT32U  BaseAddress;
    CPU_INT32U  TxPong;
    CPU_INT32U  RxPong;
    CPU_INT32U  IntSource;
} UCOS_AXIETHERNETLITE_Config;


#endif /* UCOS_AXIETHERNETLITE_PRESENT */
