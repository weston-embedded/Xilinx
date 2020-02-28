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
*                                         uC/IPerf INIT CODE
*
* File : ucos_iperf_init.c
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

#if (APP_IPERF_ENABLED == DEF_ENABLED)
#include <Source/iperf.h>
#endif

#if (APP_IPERF_ENABLED == DEF_ENABLED)
CPU_BOOLEAN UCOS_IPerf_Init (void)
{
    NET_SOCK_ADDR_FAMILY ip_type = AF_INET;
    CPU_BOOLEAN ok;
    IPERF_ERR err_iperf;


#if (UCOS_START_DEBUG_TRACE == DEF_ENABLED)
    UCOS_Print("UCOS - Initializing uC/IPerf.\r\n");
#endif

    IPerf_Init(&err_iperf);

    if (err_iperf != IPERF_ERR_NONE) {
        UCOS_Printf("UCOS - Error initializing uC/IPerf. Error code %d.\r\n", err_iperf);
        return (DEF_FAIL);
    }

    if (err_iperf == IPERF_ERR_NONE) {
        IPerfShell_Init(&err_iperf);
    }

    if (err_iperf != IPERF_ERR_NONE) {
        UCOS_Printf("UCOS - Error registering uC/IPerf shell commands. Error code %d.\r\n", err_iperf);
        return (DEF_FAIL);
    }

    return (DEF_OK);
}

#endif /* #if (APP_IPERF_ENABLED == DEF_ENABLED) */
