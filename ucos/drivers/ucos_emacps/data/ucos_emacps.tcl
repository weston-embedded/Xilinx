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
    ucos_log_put "TRACE" "Generating ucos_emacps."

    xdefine_zynq_include_file $drv_handle "xparameters.h" "UCOS_EMACPS" "NUM_INSTANCES" "DEVICE_ID" "C_BASEADDR" "C_HIGHADDR" "CLOCK_FREQ_HZ"

    ucos_define_intr_sources $drv_handle "UCOS_EMACPS"

    xdefine_zynq_config_file_intr $drv_handle "ucos_emacps_g.c" "UCOS_EMACPS"  "DEVICE_ID" "C_BASEADDR" "CLOCK_FREQ_HZ"

    xdefine_zynq_canonical_xpars $drv_handle "xparameters.h" "UCOS_EMACPS" "NUM_INSTANCES" "DEVICE_ID" "C_BASEADDR" "C_HIGHADDR" "CLOCK_FREQ_HZ"
}
