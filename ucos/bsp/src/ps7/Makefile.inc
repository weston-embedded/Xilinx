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


ARCH_LIBSOURCES:= ps7/ucos_impl.c \
                  ps7/ucos_int_impl.c \
                  ps7/ucos_vectors.S


ARCH_INCLUDEFILES:=ps7/ucos_int_impl.h \
                   ps7/ucos_impl.h