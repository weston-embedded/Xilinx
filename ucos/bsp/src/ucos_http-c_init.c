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
*                                         uC/HTTP-C INIT CODE
*
* File : ucos_http-c_init.c
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

#if (APP_TCPIP_ENABLED == DEF_ENABLED)
#include  <IP/IPv4/net_ipv4.h>
#include  <Source/net_type.h>
#include  <Source/net_ip.h>


#if (APP_HTTPC_ENABLED == DEF_ENABLED)
#include  <Client/Source/http-c.h>
#endif


#if (APP_HTTPC_ENABLED == DEF_ENABLED)
CPU_BOOLEAN UCOS_HTTPc_Init (void)
{
    HTTPc_ERR    err_httpc;


#if (UCOS_START_DEBUG_TRACE == DEF_ENABLED)
    UCOS_Print("UCOS - Initializing uC/HTTPc.\r\n");
#endif

#if (HTTPc_CFG_MODE_ASYNC_TASK_EN == DEF_ENABLED)
    HTTPc_Init(&HTTPc_Cfg, &HTTPc_TaskCfg, DEF_NULL, &err_httpc);
#else
    HTTPc_Init(&HTTPc_Cfg, DEF_NULL, DEF_NULL, &err_httpc);
#endif
    if (err_httpc != HTTPc_ERR_NONE) {
        UCOS_Printf("UCOS - Error initializing uC/HTTPc. Error code %d\r\n", err_httpc);
        return (DEF_FAIL);
    }

    return (DEF_OK);
}

#endif /* #if (APP_HTTPC_ENABLED == DEF_ENABLED) */
#endif /* #if (APP_TCPIP_ENABLED == DEF_ENABLED) */
