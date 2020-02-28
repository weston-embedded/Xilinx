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

source ./axiethernet.tcl

namespace import ::hsm::utils::*

proc generate {drv_handle} {
    xdefine_axiethernet_include_file $drv_handle "xparameters.h" "UCOS_AXIETHERNET"

    xdefine_axiethernet_config_file  "ucos_axiethernet_g.c" "UCOS_AXIETHERNET"
}
