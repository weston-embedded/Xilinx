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
    ucos_log_put "TRACE" "Generating ucos_telnet-s."

    set ucos_src_base [ucos_get_source_base]

    file copy -force "$ucos_src_base/uC-TELNETs/Cfg/Template/telnet-s_cfg.h" "./src"

    file copy -force "$ucos_src_base/uC-TELNETs" "./src/uC-TELNETs"

    file mkdir "../../include/Source"
    file mkdir "../../include/Shell"

    set_define "./src/telnet-s_cfg.h" "TELNETs_OS_CFG_SERVER_TASK_PRIO"     [format "%u" [get_property CONFIG.TELNETs_OS_CFG_SERVER_TASK_PRIO         $ucos_handle]]
    set_define "./src/telnet-s_cfg.h" "TELNETs_OS_CFG_SESSION_TASK_PRIO"     [format "%u" [get_property CONFIG.TELNETs_OS_CFG_SESSION_TASK_PRIO         $ucos_handle]]
    set_define "./src/telnet-s_cfg.h" "TELNETs_OS_CFG_SERVER_TASK_STK_SIZE"     [format "%u" [get_property CONFIG.TELNETs_OS_CFG_SERVER_TASK_STK_SIZE         $ucos_handle]]
    set_define "./src/telnet-s_cfg.h" "TELNETs_OS_CFG_SESSION_TASK_STK_SIZE"     [format "%u" [get_property CONFIG.TELNETs_OS_CFG_SESSION_TASK_STK_SIZE         $ucos_handle]]

    set_define "./src/telnet-s_cfg.h" "TELNETs_CFG_PORT_SERVER"        [format "%u" [get_property CONFIG.TELNETs_CFG_PORT_SERVER         $ucos_handle]]
    set_define "./src/telnet-s_cfg.h" "TELNETs_CFG_PORT_SERVER_SECURE" [format "%u" [get_property CONFIG.TELNETs_CFG_PORT_SERVER_SECURE         $ucos_handle]]

    set_define "./src/telnet-s_cfg.h" "TELNETs_CFG_INACTIVITY_TIMEOUT_S"     [format "%u" [get_property CONFIG.TELNETs_CFG_INACTIVITY_TIMEOUT_S         $ucos_handle]]
    set_define "./src/telnet-s_cfg.h" "TELNETs_CFG_MAX_TX_TRIES"     [format "%u" [get_property CONFIG.TELNETs_CFG_MAX_TX_TRIES         $ucos_handle]]

    set_define "./src/telnet-s_cfg.h" "TELNETs_CFG_RX_BUF_LEN"     [format "%u" [get_property CONFIG.TELNETs_CFG_RX_BUF_LEN         $ucos_handle]]
    set_define "./src/telnet-s_cfg.h" "TELNETs_CFG_NVT_BUF_LEN"    [format "%u" [get_property CONFIG.TELNETs_CFG_NVT_BUF_LEN         $ucos_handle]]


    set_define "./src/telnet-s_cfg.h" "TELNETs_CFG_MAX_USR_NAME_LEN"     [format "%u" [get_property CONFIG.TELNETs_CFG_MAX_USR_NAME_LEN         $ucos_handle]]
    set_define "./src/telnet-s_cfg.h" "TELNETs_CFG_MAX_PW_LEN"     [format "%u" [get_property CONFIG.TELNETs_CFG_MAX_PW_LEN         $ucos_handle]]

    set_define "./src/telnet-s_cfg.h" "TELNETs_CFG_MAX_LOGIN_TRIES"     [format "%u" [get_property CONFIG.TELNETs_CFG_MAX_LOGIN_TRIES         $ucos_handle]]

    set_define "./src/telnet-s_cfg.h" "TELNETs_CFG_FS_EN"    [expr ([get_property CONFIG.TELNETs_CFG_FS_EN                  $ucos_handle] == true)?"DEF_ENABLED":"DEF_DISABLED"]
    set_define "./src/telnet-s_cfg.h" "TELNETs_CFG_ECHO_EN"  [expr ([get_property CONFIG.TELNETs_CFG_ECHO_EN               $ucos_handle] == true)?"DEF_ENABLED":"DEF_DISABLED"]

    set_define "./src/telnet-s_cfg.h" "TELNETs_CFG_FS_MAX_PATH_NAME_LEN" [format "%u" [get_property CONFIG.TELNETs_CFG_FS_MAX_PATH_NAME_LEN         $ucos_handle]]
}
