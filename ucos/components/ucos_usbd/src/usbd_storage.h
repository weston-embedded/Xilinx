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
* File : usbd_storage.h
*********************************************************************************************************
*/

#include <xparameters.h>
#include <ucos_bsp.h>

#if (UCOS_USBD_STORAGE_DRV == UCOS_USBD_STORAGE_DRV_FS)
#include "Class/MSC/Storage/uC-FS/V4/usbd_storage.h"
#else
#include "Class/MSC/Storage/RAMDisk/usbd_storage.h"
#endif