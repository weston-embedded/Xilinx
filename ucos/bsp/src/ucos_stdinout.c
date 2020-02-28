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
*                                          STDIN and STDOUT
*
* File : ucos_stdinout.c
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
#include  "ucos_int.h"
#include  <xparameters.h>


#define  DRIVER_USED(drv) ((UCOS_STDOUT_DRIVER == (drv)) || (UCOS_STDIN_DRIVER == (drv)))

#if DRIVER_USED(UCOS_UART_PS7_UART)
#include  <ucos_uartps.h>
#endif

#if DRIVER_USED(UCOS_UART_AXI_UART_LITE)
#include  <ucos_axiuartlite.h>
#endif


#if (UCOS_STDOUT_DRIVER == UCOS_UART_PS7_UART)
UARTPS_HANDLE  STDOUT_Handle;
#elif (UCOS_STDOUT_DRIVER == UCOS_UART_AXI_UART_LITE)
AXIUARTLITE_HANDLE  STDOUT_Handle;
#endif

#if (UCOS_STDIN_DRIVER == UCOS_UART_PS7_UART)
UARTPS_HANDLE  STDIN_Handle;
#elif (UCOS_STDIN_DRIVER == UCOS_UART_AXI_UART_LITE)
AXIUARTLITE_HANDLE  STDIN_Handle;
#endif


void UCOS_StdInOutInit()
{
#if (UCOS_STDOUT_DRIVER == UCOS_UART_PS7_UART)
    STDOUT_Handle = UARTPS_Init(UCOS_STDOUT_DEVICE_ID);
#elif (UCOS_STDOUT_DRIVER == UCOS_UART_AXI_UART_LITE)
    STDOUT_Handle = AXIUARTLite_Init(UCOS_STDOUT_DEVICE_ID);
#endif

#if (UCOS_STDIN_DRIVER == UCOS_UART_PS7_UART)
    STDIN_Handle = UARTPS_Init(UCOS_STDIN_DEVICE_ID);
#elif (UCOS_STDIN_DRIVER == UCOS_UART_AXI_UART_LITE)
    STDIN_Handle = AXIUARTLite_Init(UCOS_STDIN_DEVICE_ID);
#endif
}


void  UCOS_Print (const CPU_CHAR *p_string)
{
#if (UCOS_STDOUT_DRIVER == UCOS_UART_PS7_UART)
    UARTPS_WrStr(STDOUT_Handle, p_string);
#elif (UCOS_STDOUT_DRIVER == UCOS_UART_AXI_UART_LITE)
    AXIUARTLite_WrStr(STDOUT_Handle, p_string);
#else
    (void)p_string;
#endif
}


CPU_INT32U UCOS_Read (CPU_CHAR *buf, CPU_INT32U cnt)
{
    CPU_INT32U i = 0;


#if (UCOS_STDIN_DRIVER == UCOS_UART_PS7_UART)
    for (i = 0; i < cnt; i++) {
        *(buf + i) = UARTPS_RdByte(STDIN_Handle);
        if ((*(buf + i) == '\n' || *(buf + i) == '\r'))
        {
            i++;
            break;
        }
    }
#elif (UCOS_STDIN_DRIVER == UCOS_UART_AXI_UART_LITE)
    for (i = 0; i < cnt; i++) {
        *(buf + i) = AXIUARTLite_RdByte(STDIN_Handle);
        if ((*(buf + i) == '\n' || *(buf + i) == '\r'))
        {
            i++;
            break;
        }
    }
#else
    (void)buf;
    (void)cnt;
#endif

    return i;
}
