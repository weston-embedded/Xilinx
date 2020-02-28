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
INCLUDES=-I./. -I./uC-TCPIP/Source -I${INCLUDEDIR}

OUTS = *.o

include ../../../include/Makefile_def.inc

DIST_LIB=libucdhcpc-${UCOS_OS}-${UCOS_ARCH}.a

LIBSOURCES:=uC-DHCPc/Source/dhcp-c.c \
            uC-DHCPc/OS/${UCOS_DIR_NAME}/dhcp-c_os.c


INCLUDEFILES:=dhcp-c_cfg.h


ifeq (${strip ${UCOS_DHCPC_SRC_BASE}},)
OBJECTS =
else
OBJECTS =	$(addsuffix .o, $(basename ${LIBSOURCES}))
endif

libs: banner lib_copy ucos_final_libs clean

%.o: %.c
	${COMPILER} $(CC_FLAGS) $(ECC_FLAGS) $(INCLUDES) -o $@ $<

%.o: %.s
	${COMPILER} $(CC_FLAGS) $(ECC_FLAGS) $(INCLUDES) -o $@ $<

banner:
	echo "Compiling uC/DHCPc"

lib_copy:
ifeq (${strip ${UCOS_DHCPC_SRC_BASE}},)
	echo "uC/DHCPc sources not found, using pre-compiled library"
	${CP} ${UCOS_LIB_LOC}/${DIST_LIB} ${RELEASEDIR}/
	touch ${RELEASEDIR}/${DIST_LIB}
else
	echo "Building uC/DHCPc from sources at ${UCOS_DHCPC_SRC_BASE}"
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
	${CP} ${UCOS_SRC_BASE}/uC-DHCPc/Source/dhcp-c.h ${INCLUDEDIR}/Source


clean:
	rm -rf ${OBJECTS}

