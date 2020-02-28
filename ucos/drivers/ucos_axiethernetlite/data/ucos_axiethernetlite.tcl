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

namespace import ::hsm::utils::*

proc generate {drv_handle} {
    ucos_log_put "TRACE" "Generating ucos_axiethernetlite."

    xdefine_include_file $drv_handle "xparameters.h" "UCOS_AXIETHERNETLITE" "NUM_INSTANCES" "DEVICE_ID" "C_BASEADDR" "C_HIGHADDR" "C_TX_PING_PONG" "C_RX_PING_PONG"

    ucos_define_intr_sources $drv_handle "UCOS_AXIETHERNETLITE"

    xdefine_config_file_intr $drv_handle "ucos_axiethernetlite_g.c" "UCOS_AXIETHERNETLITE"  "DEVICE_ID" "C_BASEADDR" "C_TX_PING_PONG" "C_RX_PING_PONG"
}
