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
*
* File : app_cfg.h
*********************************************************************************************************
*/

#ifndef  UCOS_APP_CFG_PRESENT
#define  UCOS_APP_CFG_PRESENT

#include  <lib_def.h>

#include  <xparameters.h>

#define  APP_CPU_ENABLED DEF_DISABLED

#define  APP_LIB_ENABLED DEF_DISABLED

#define  APP_COMMON_ENABLED DEF_DISABLED

#define  APP_SHELL_ENABLED DEF_DISABLED

#define  APP_CLK_ENABLED DEF_DISABLED

#define  APP_OSIII_ENABLED DEF_DISABLED

#define  APP_OSII_ENABLED  DEF_DISABLED

#define  APP_TCPIP_ENABLED  DEF_DISABLED

#define  APP_TCPIP_EXP_ENABLED  DEF_DISABLED

#define  APP_DHCPC_ENABLED  DEF_DISABLED

#define  APP_DNSC_ENABLED  DEF_DISABLED

#define  APP_HTTPC_ENABLED  DEF_DISABLED

#define  APP_MQTTC_ENABLED  DEF_DISABLED

#define  APP_TELNETS_ENABLED  DEF_DISABLED

#define  APP_IPERF_ENABLED  DEF_DISABLED

#define  APP_FS_ENABLED  DEF_DISABLED

#define  APP_USBD_ENABLED  DEF_DISABLED

#define  APP_USBH_ENABLED  DEF_DISABLED

#define  APP_OPENAMP_ENABLED  DEF_DISABLED

#define  OS_TASK_TMR_PRIO                 (OS_LOWEST_PRIO - 2u)

#define  CLK_OS_CFG_TASK_STK_SIZE      1024
#define  CLK_OS_CFG_TASK_PRIO            20

#endif /* #ifndef  UCOS_APP_CFG_PRESENT */

