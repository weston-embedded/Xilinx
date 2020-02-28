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


ARCH_LIBSOURCES:=${UCOS_SRC_BASE}/uCOS-III/Ports/ARM-Cortex-R/ARMv7-R/os_cpu_c.c \
                 ${UCOS_SRC_BASE}/uCOS-III/Ports/ARM-Cortex-R/ARMv7-R/GNU/os_cpu_a_vfp-none.S \
                 ./bsp/psur5/ucos_osiii_bsp.c


ARCH_INCLUDEFILES:=${UCOS_SRC_BASE}/uCOS-III/Ports/ARM-Cortex-R/ARMv7-R/GNU/os_cpu.h \
                   ./bsp/psur5/ucos_osiii_bsp.h
