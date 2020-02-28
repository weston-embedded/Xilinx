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
*                                             AXI ETHERNET
*
* File : ucos_axiethernet.h
*********************************************************************************************************
*/

#ifndef  UCOS_AXIETHERNET_PRESENT
#define  UCOS_AXIETHERNET_PRESENT


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
    CPU_INT32U  EmacType;
    CPU_INT32U  TxCSum;
    CPU_INT32U  RxCSum;
    CPU_INT32U  PhyType;
    CPU_INT32U  TXVlanTran;
    CPU_INT32U  RXVlanTran;
    CPU_INT32U  TXVlanTag;
    CPU_INT32U  RXVlanTag;
    CPU_INT32U  TXVlanStrip;
    CPU_INT32U  RXVlanStrip;
    CPU_INT32U  MCastExt;
    CPU_INT32U  Stats;
    CPU_INT32U  AVB;
    CPU_INT32U  SGMIIOverLVDS;
    CPU_INT32U  Intr;
    CPU_INT32U  ConnType;
    CPU_INT32U  ConnAddr;
    CPU_INT32U  PhyAddr;
    CPU_INT32U  RXIntr;
    CPU_INT32U  TCIntr;
} UCOS_AXIETHERNET_Config;


#endif /* UCOS_AXIETHERNET_PRESENT */
