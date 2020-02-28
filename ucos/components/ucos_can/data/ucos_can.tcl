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

proc generate {ucos_handle} {

    ucos_log_put "TRACE" "Generating ucos_can."

    set ucos_src_base [ucos_get_source_base]
    set can_src_base [ucos_get_product_source_base can]

    set source_avail 1
    if {[llength $can_src_base] == 0} {
        set source_avail 0
        set can_src_base $ucos_src_base
    }

    file copy -force "$can_src_base/uC-CAN" "./src/uC-CAN"
    #file copy -force "$can_src_base/uC-CAN/Cfg/Template/can_cfg.h" "./src/can_cfg.h"
    #file copy -force "$can_src_base/uC-CAN/Cfg/Template/can_cfg.c" "./src/can_cfg.c"

}
