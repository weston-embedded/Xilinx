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
    ucos_log_put "TRACE" "Generating ucos_axiuartlite."

    xdefine_include_file $drv_handle "xparameters.h" "UCOS_AXIUARTLITE" "NUM_INSTANCES" "C_BASEADDR" "C_HIGHADDR" "DEVICE_ID" "C_BAUDRATE" "C_USE_PARITY" "C_ODD_PARITY" "C_DATA_BITS"
    ucos_define_intr_sources $drv_handle "UCOS_AXIUARTLITE"
    xdefine_config_file_intr $drv_handle "ucos_axiuartlite_g.c" "UCOS_AXIUARTLITE"  "DEVICE_ID" "C_BASEADDR" "C_BAUDRATE" "C_USE_PARITY" "C_ODD_PARITY"  "C_DATA_BITS"
    xdefine_canonical_xpars $drv_handle "xparameters.h" "UCOS_AXIUARTLITE" "DEVICE_ID" "C_BASEADDR" "C_HIGHADDR" "C_BAUDRATE" "C_USE_PARITY" "C_ODD_PARITY" "C_DATA_BITS"
}
