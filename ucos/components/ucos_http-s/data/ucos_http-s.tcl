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
    ucos_log_put "TRACE" "Generating ucos_http-s."

    set ucos_src_base [ucos_get_source_base]
    set https_src_base [ucos_get_product_source_base https]


    if {[llength $https_src_base] == 0} {
        set https_src_base $ucos_src_base
    }

    file copy -force "$https_src_base/uC-HTTP/Server/Cfg/Template/http-s_cfg.h" "./src"
    file copy -force "$https_src_base/uC-HTTP/Server/FS/Static/Cfg/Template/http-s_fs_static_cfg.h" "./src"

    file copy -force "$https_src_base/uC-HTTP" "./src/uC-HTTP"

    file mkdir "../../include/Common"
    file mkdir "../../include/Server/Source"
    file mkdir "../../include/Server/FS/Static"

    set_define "./src/http-s_cfg.h" "HTTPs_CFG_ARG_CHK_EXT_EN"  [expr ([get_property CONFIG.HTTPs_CFG_ARG_CHK_EXT_EN  $ucos_handle] == true)?"DEF_ENABLED":"DEF_DISABLED"]
    set_define "./src/http-s_cfg.h" "HTTPs_CFG_DBG_INFO_EN"     [expr ([get_property CONFIG.HTTPs_CFG_DBG_INFO_EN     $ucos_handle] == true)?"DEF_ENABLED":"DEF_DISABLED"]

    set_define "./src/http-s_cfg.h" "HTTPs_CFG_CTR_STAT_EN"    [expr ([get_property CONFIG.HTTPs_CFG_CTR_STAT_EN    $ucos_handle] == true)?"DEF_ENABLED":"DEF_DISABLED"]
    set_define "./src/http-s_cfg.h" "HTTPs_CFG_CTR_ERR_EN"     [expr ([get_property CONFIG.HTTPs_CFG_CTR_ERR_EN     $ucos_handle] == true)?"DEF_ENABLED":"DEF_DISABLED"]

    set_define "./src/http-s_cfg.h" "HTTPs_CFG_FS_PRESENT_EN"     [expr ([get_property CONFIG.HTTPs_CFG_FS_PRESENT_EN     $ucos_handle] == true)?"DEF_ENABLED":"DEF_DISABLED"]

    set_define "./src/http-s_cfg.h" "HTTPs_CFG_PERSISTENT_CONN_EN"     [expr ([get_property CONFIG.HTTPs_CFG_PERSISTENT_CONN_EN     $ucos_handle] == true)?"DEF_ENABLED":"DEF_DISABLED"]

    set_define "./src/http-s_cfg.h" "HTTPs_CFG_HDR_RX_EN"    [expr ([get_property CONFIG.HTTPs_CFG_HDR_RX_EN    $ucos_handle] == true)?"DEF_ENABLED":"DEF_DISABLED"]
    set_define "./src/http-s_cfg.h" "HTTPs_CFG_HDR_TX_EN"    [expr ([get_property CONFIG.HTTPs_CFG_HDR_TX_EN    $ucos_handle] == true)?"DEF_ENABLED":"DEF_DISABLED"]

    set_define "./src/http-s_cfg.h" "HTTPs_CFG_QUERY_STR_EN"     [expr ([get_property CONFIG.HTTPs_CFG_QUERY_STR_EN     $ucos_handle] == true)?"DEF_ENABLED":"DEF_DISABLED"]

    set_define "./src/http-s_cfg.h" "HTTPs_CFG_FORM_EN"           [expr ([get_property CONFIG.HTTPs_CFG_FORM_EN             $ucos_handle] == true)?"DEF_ENABLED":"DEF_DISABLED"]
    set_define "./src/http-s_cfg.h" "HTTPs_CFG_FORM_MULTIPART_EN" [expr ([get_property CONFIG.HTTPs_CFG_FORM_MULTIPART_EN   $ucos_handle] == true)?"DEF_ENABLED":"DEF_DISABLED"]

    set_define "./src/http-s_cfg.h" "HTTPs_CFG_TOKEN_PARSE_EN"     [expr ([get_property CONFIG.HTTPs_CFG_TOKEN_PARSE_EN     $ucos_handle] == true)?"DEF_ENABLED":"DEF_DISABLED"]

    set_define "./src/http-s_cfg.h" "HTTPs_CFG_ABSOLUTE_URI_EN"     [expr ([get_property CONFIG.HTTPs_CFG_ABSOLUTE_URI_EN     $ucos_handle] == true)?"DEF_ENABLED":"DEF_DISABLED"]

}
