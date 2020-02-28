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


ARCH_LIBSOURCES:=${UCOS_SRC_BASE}/uC-CPU/ARM-Cortex-A/ARMv7-A/GNU/cpu_a.S \
                 ${UCOS_SRC_BASE}/uC-CPU/Cache/ARM/armv7_generic_l1_l2c310_l2/cpu_cache_armv7_generic_l1_l2c310_l2.c \
                 ${UCOS_SRC_BASE}/uC-CPU/Cache/ARM/armv7_generic_l1_l2c310_l2/GNU/cpu_cache_armv7_generic_l1_l2c310_l2_a.S \
                 ps7/cpu_bsp.c

ARCH_INCLUDEFILES:=${UCOS_SRC_BASE}/uC-CPU/ARM-Cortex-A/ARMv7-A/GNU/cpu.h
