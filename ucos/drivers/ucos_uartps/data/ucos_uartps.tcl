#########################################################################################################
#                                             uCOS XSDK BSP
#
#                    Copyright 2014-2020 Silicon Laboratories Inc. www.silabs.com
#
#                                 SPDX-License-Identifier: APACHE-2.0
#
#               This software is subject to an open source license and is distributed by
#                Silicon Laboratories Inc. pursuant to the terms of the Apache License,
#                    Version 2.0 available at www.apache.org/licenses/LICENSE-2.0.
#
#########################################################################################################


source ../../../bsp/data/ucos_tcl_utils.tcl
source ../../../bsp/data/xil_tcl_utils.tcl

proc generate {drv_handle} {
    ucos_log_put "TRACE" "Generating ucos_uartps."

    xdefine_zynq_include_file $drv_handle "xparameters.h" "UCOS_UARTPS" "NUM_INSTANCES" "DEVICE_ID" "C_S_AXI_BASEADDR" "C_S_AXI_HIGHADDR" "C_UART_CLK_FREQ_HZ" "C_HAS_MODEM"

    ucos_define_intr_sources $drv_handle "UCOS_UARTPS"

    xdefine_zynq_config_file_intr $drv_handle "ucos_uartps_g.c" "UCOS_UARTPS"  "DEVICE_ID" "C_S_AXI_BASEADDR" "C_UART_CLK_FREQ_HZ" "C_HAS_MODEM"

    xdefine_zynq_canonical_xpars $drv_handle "xparameters.h" "UCOS_UARTPS" "DEVICE_ID" "C_S_AXI_BASEADDR" "C_S_AXI_HIGHADDR" "C_UART_CLK_FREQ_HZ" "C_HAS_MODEM"
}