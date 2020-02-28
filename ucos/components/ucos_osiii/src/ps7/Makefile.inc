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


ARCH_LIBSOURCES:=${UCOS_SRC_BASE}/uCOS-III/Ports/ARM-Cortex-A/ARMv7-A/os_cpu_c.c \
                 ${UCOS_SRC_BASE}/uCOS-III/Ports/ARM-Cortex-A/ARMv7-A/GNU/os_cpu_a_vfp-d32.S \
                 ./bsp/ps7/ucos_osiii_bsp.c


ARCH_INCLUDEFILES:=${UCOS_SRC_BASE}/uCOS-III/Ports/ARM-Cortex-A/ARMv7-A/GNU/os_cpu.h \
                   ./bsp/ps7/ucos_osiii_bsp.h
