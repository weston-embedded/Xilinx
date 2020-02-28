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



COMPILER=
CP=cp
COMPILER_FLAGS=
EXTRA_COMPILER_FLAGS=
LIB=libucos.a

CC_FLAGS = $(COMPILER_FLAGS)
ECC_FLAGS = $(EXTRA_COMPILER_FLAGS)

RELEASEDIR=../../../lib
INCLUDEDIR=../../../include
INCLUDES=-I${UCOS_SRC_BASE}/uCOS-III/Source -I${UCOS_SRC_BASE}/uCOS-III -I${INCLUDEDIR}

OUTS = *.o

include ../../../include/Makefile_def.inc
include Makefile.inc

LIBSOURCES:=${UCOS_SRC_BASE}/uCOS-III/Source/os_cfg_app.c \
            ${UCOS_SRC_BASE}/uCOS-III/Source/os_core.c \
            ${UCOS_SRC_BASE}/uCOS-III/Source/os_dbg.c \
            ${UCOS_SRC_BASE}/uCOS-III/Source/os_flag.c \
            ${UCOS_SRC_BASE}/uCOS-III/Source/os_mem.c \
            ${UCOS_SRC_BASE}/uCOS-III/Source/os_msg.c \
            ${UCOS_SRC_BASE}/uCOS-III/Source/os_mutex.c \
            ${UCOS_SRC_BASE}/uCOS-III/Source/os_prio.c \
            ${UCOS_SRC_BASE}/uCOS-III/Source/os_q.c \
            ${UCOS_SRC_BASE}/uCOS-III/Source/os_sem.c \
            ${UCOS_SRC_BASE}/uCOS-III/Source/os_stat.c \
            ${UCOS_SRC_BASE}/uCOS-III/Source/os_task.c \
            ${UCOS_SRC_BASE}/uCOS-III/Source/os_tick.c \
            ${UCOS_SRC_BASE}/uCOS-III/Source/os_time.c \
            ${UCOS_SRC_BASE}/uCOS-III/Source/os_tmr.c \
            ${UCOS_SRC_BASE}/uCOS-III/Source/os_var.c \
            ${UCOS_SRC_BASE}/uCOS-III/TLS/NewLib/os_tls.c

LIBSOURCES += $(ARCH_LIBSOURCES)

INCLUDEFILES:=os_cfg.h \
              os_cfg_app.h

INCLUDEFILES += $(ARCH_INCLUDEFILES)


OBJECTS =	$(addsuffix .o, $(basename ${LIBSOURCES}))

libs: banner ucos_osiii_libs clean

%.o: %.c
	${MKDIR} -p $(@D)
	${COMPILER} $(CC_FLAGS) $(ECC_FLAGS) $(INCLUDES) -o $@ $<


%.o: %.S
	${MKDIR} -p $(@D)
	${COMPILER} $(CC_FLAGS) $(ECC_FLAGS) $(INCLUDES) -o $@ $<

banner:
	echo "Compiling uC/OS-III"

ucos_osiii_libs: ${OBJECTS}
	$(ARCHIVER) -r ${RELEASEDIR}/${LIB} ${OBJECTS}

.PHONY: include
include:
	${CP} ${INCLUDEFILES} ${INCLUDEDIR}

	${CP} ${UCOS_SRC_BASE}/uCOS-III/Source/os.h ${INCLUDEDIR}
	${CP} ${UCOS_SRC_BASE}/uCOS-III/Source/os_trace.h ${INCLUDEDIR}
	${CP} ${UCOS_SRC_BASE}/uCOS-III/Source/os_type.h ${INCLUDEDIR}

	${CP} ${UCOS_SRC_BASE}/uCOS-III/Source/os.h ${INCLUDEDIR}/Source
	${CP} ${UCOS_SRC_BASE}/uCOS-III/Source/os_trace.h ${INCLUDEDIR}/Source
	${CP} ${UCOS_SRC_BASE}/uCOS-III/Source/os_type.h ${INCLUDEDIR}/Source

clean:
	rm -rf ${OBJECTS}

