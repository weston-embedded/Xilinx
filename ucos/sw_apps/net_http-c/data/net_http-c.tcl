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


proc swapp_get_name {} {
    return "Micrium HTTP Client example project.";
}

proc swapp_get_description {} {
    return "An example querying a web page using the HTTP Client module.";
}

proc swapp_is_supported_hw {} {
    return 1;
}

proc swapp_is_supported_sw {} {
    return 1;
}

proc swapp_generate {} {

}

proc swapp_get_linker_constraints {} {
    return "";
}

proc swapp_get_supported_processors {} {
    return "microblaze ps7_cortexa9 psu_cortexr5 psu_cortexa53";
}

proc swapp_get_supported_os {} {
    return "ucos";
}