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


ARCH_LIBSOURCES:=${UCOS_SRC_BASE}/uC-CPU/MicroBlaze/GNU/cpu_c.c \
                 ${UCOS_SRC_BASE}/uC-CPU/MicroBlaze/GNU/cpu_a.S \
                 mb/cpu_bsp.c \
                 mb/cache/mb_flush_dcache_range.S \
                 mb/cache/mb_invalidate_dcache_range.S \
                 mb/cache/mb_dcache_init.c

ARCH_INCLUDEFILES:=${UCOS_SRC_BASE}/uC-CPU/MicroBlaze/GNU/cpu.h
