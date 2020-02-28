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
*                                         uC/Shell INIT CODE
*
* File : ucos_dhcp-c_init.c
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

#if (APP_SHELL_ENABLED == DEF_ENABLED)
#include <Source/shell.h>
#endif

#if (APP_SHELL_ENABLED == DEF_ENABLED)
CPU_BOOLEAN UCOS_Shell_Init (void)
{
    CPU_BOOLEAN err_shell;


#if (UCOS_START_DEBUG_TRACE == DEF_ENABLED)
    UCOS_Print("UCOS - Initializing uC/Shell.\r\n");
#endif

    err_shell = Shell_Init();

    if (err_shell != DEF_OK) {
        UCOS_Printf("UCOS - Error initializing uC/Shell.\r\n");
        return (DEF_FAIL);
    }

    return (DEF_OK);
}

#endif /* #if (APP_SHELL_ENABLED == DEF_ENABLED) */
