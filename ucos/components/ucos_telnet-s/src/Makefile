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
ARCHIVER=
CP=cp
COMPILER_FLAGS=
EXTRA_COMPILER_FLAGS=
LIB=libucos.a

CC_FLAGS = $(COMPILER_FLAGS)
ECC_FLAGS = $(EXTRA_COMPILER_FLAGS)

RELEASEDIR=../../../lib
INCLUDEDIR=../../../include
INCLUDES=-I./. -I./uC-TCPIP/Source -I${INCLUDEDIR}

OUTS = *.o

include ../../../include/Makefile_def.inc

DIST_LIB=libuctelnets-${UCOS_OS}-${UCOS_ARCH}.a

LIBSOURCES= uC-TELNETs/Source/telnet-s.c \
            uC-TELNETs/OS/${UCOS_DIR_NAME}/telnet-s_os.c

ifdef UCOS_TCPIP_NETCMD
LIBSOURCES+= uC-TELNETs/Shell/telnet-s_shell.c
endif

INCLUDEFILES:=telnet-s_cfg.h

ifeq (${strip ${UCOS_TELNETS_SRC_BASE}},)
OBJECTS =
else
OBJECTS = $(addsuffix .o, $(basename ${LIBSOURCES}))
endif

libs: banner lib_copy ucos_final_libs clean

%.o: %.c
	${MKDIR} -p $(@D)
	${COMPILER} $(CC_FLAGS) $(ECC_FLAGS) $(INCLUDES) -o $@ $<

%.o: %.S
	${MKDIR} -p $(@D)
	${COMPILER} $(CC_FLAGS) $(ECC_FLAGS) $(INCLUDES) -o $@ $<

banner:
	echo "Compiling uC/TELNETs"

lib_copy:
ifeq (${strip ${UCOS_TELNETS_SRC_BASE}},)
	echo "uC/TELNETs sources not found, using pre-compiled library"
	${CP} ${UCOS_LIB_LOC}/${DIST_LIB} ${RELEASEDIR}/
	touch ${RELEASEDIR}/${DIST_LIB}
else
	echo "Building uC/TELNETs from sources at ${UCOS_TELNETS_SRC_BASE}"
endif

${RELEASEDIR}/${DIST_LIB}: ${OBJECTS}
		$(ARCHIVER) -cr ${RELEASEDIR}/${DIST_LIB} ${OBJECTS}

ucos_final_libs: ${RELEASEDIR}/${DIST_LIB}
		rm -rf ${OBJECTS}
		$(ARCHIVER) -x ${RELEASEDIR}/${DIST_LIB}
		$(ARCHIVER) -r ${RELEASEDIR}/${LIB} *.o
		rm -rf *.o

.PHONY: include
include:
	${CP} ${INCLUDEFILES} ${INCLUDEDIR}
	${CP} ${UCOS_SRC_BASE}/uC-TELNETs/Source/telnet-s.h ${INCLUDEDIR}/Source
ifdef UCOS_TCPIP_NETCMD
	${CP} ${UCOS_SRC_BASE}/uC-TELNETs/Shell/telnet-s_shell.h ${INCLUDEDIR}/Cmd
endif


clean:
	rm -rf ${OBJECTS}

