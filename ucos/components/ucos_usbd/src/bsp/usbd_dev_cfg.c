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
* File : ucos_dev_cfg.h
*********************************************************************************************************
*/

#include  <Source/usbd_core.h>

#include  <ucos_bsp.h>
#include  <xparameters.h>

#if (UCOS_USB_DRIVER == UCOS_USB_USBPS)
#include  "usbd_bsp_ps7_usb.h"

USBD_DRV_CFG  UCOS_USBD_DrvCfg_PS7 = {
#if (UCOS_USB_DEVICE_ID == 1)
        XPAR_UCOS_USBPS_1_BASEADDR,
#else
        XPAR_UCOS_USBPS_0_BASEADDR,
#endif
        0,
        0,
        USBD_DEV_SPD_HIGH,
        USBD_DrvEP_InfoTbl_PS7_USB
    };
#endif
