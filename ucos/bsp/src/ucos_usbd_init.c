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
*                                       uC/USB-Device INIT CODE
*
* File : ucos_usbd_init.c
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                             INCLUDE FILES
*********************************************************************************************************
*/

#include <app_cfg.h>
#include <cpu.h>
#include <ucos_bsp.h>
#include <ucos_int.h>
#include <xparameters.h>
#include <KAL/kal.h>

#if ((APP_USBD_ENABLED == DEF_ENABLED) && (UCOS_USB_TYPE == UCOS_USB_TYPE_DEVICE))
#include  <Source/usbd_core.h>
#include  "usbd_dev_cfg.h"

CPU_BOOLEAN UCOS_USBD_Init (void)
{
    CPU_INT08U   dev_nbr;
    USBD_ERR     usbd_err;

#if (UCOS_START_DEBUG_TRACE == DEF_ENABLED)
    UCOS_Print("UCOS - Initializing uC/USB-Device.\r\n");
#endif

    USBD_Init(&usbd_err);
    if (usbd_err != USBD_ERR_NONE) {
#if (UCOS_START_DEBUG_TRACE == DEF_ENABLED)
        UCOS_Printf("UCOS - Error initializing uC/USB-Device. USBD_Init() returned error code %d\r\n", usbd_err);
#endif
        return (DEF_FAIL);
    }

    return (DEF_OK);
}

#endif /* #if (APP_USBD_ENABLED == DEF_ENABLED) */
