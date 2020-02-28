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
INCLUDES=-I./. -I${INCLUDEDIR}

OUTS = *.o

include ../../../include/Makefile_def.inc
DIST_LIB=libuccan-${UCOS_OS}-${UCOS_ARCH}.a

LIBSOURCES:=uC-CAN/Source/can_bus.c \
            uC-CAN/Source/can_frm.c \
            uC-CAN/Source/can_msg.c \
            uC-CAN/Source/can_sig.c \
            uC-CAN/OS/${UCOS_DIR_NAME}/can_os.c \
            uC-CAN/Drivers/ZC7xxx/drv_can.c \
            bsp/can_bsp.c \
            bsp/can_cfg.c


INCLUDEFILES:=uC-CAN/Source/can_bus.h \
              uC-CAN/Source/can_frm.h \
              uC-CAN/Source/can_msg.h \
              uC-CAN/Source/can_sig.h \
              uC-CAN/Source/can_err.h \
              uC-CAN/Source/can_drv.h \
              uC-CAN/OS/${UCOS_DIR_NAME}/can_os.h \
              uC-CAN/Drivers/drv_def.h \
              uC-CAN/Drivers/ZC7xxx/drv_can.h \
              uC-CAN/Drivers/ZC7xxx/drv_can_reg.h \
              bsp/can_bsp.h \
              bsp/can_cfg.h


ifeq (${strip ${UCOS_CAN_SRC_BASE}},)
OBJECTS =
else
OBJECTS = $(addsuffix .o, $(basename ${LIBSOURCES}))
endif

libs: banner lib_copy ucos_final_libs bsp clean

%.o: %.c
	${COMPILER} $(CC_FLAGS) $(ECC_FLAGS) $(INCLUDES) -o $@ $<

%.o: %.s
	${COMPILER} $(CC_FLAGS) $(ECC_FLAGS) $(INCLUDES) -o $@ $<

banner:
	echo "Compiling uC/CAN"

lib_copy:
ifeq (${strip ${UCOS_FS_SRC_BASE}},)
	echo "uC/CAN sources not found, using pre-compiled library"
	${CP} ${UCOS_LIB_LOC}/${DIST_LIB} ${RELEASEDIR}/
	touch ${RELEASEDIR}/${DIST_LIB}
else
	echo "Building uC/CAN from sources at ${UCOS_TCPIP_SRC_BASE}"
endif

${RELEASEDIR}/${DIST_LIB}: ${OBJECTS}
		$(ARCHIVER) -cr ${RELEASEDIR}/${DIST_LIB} ${OBJECTS}

ucos_final_libs: ${RELEASEDIR}/${DIST_LIB}
		rm -rf ${OBJECTS}
		$(ARCHIVER) -x ${RELEASEDIR}/${DIST_LIB}
		$(ARCHIVER) -r ${RELEASEDIR}/${LIB} *.o
		rm -rf *.o

bsp: ${BSPOBJECTS}
	$(ARCHIVER) -r ${RELEASEDIR}/${LIB} ${BSPOBJECTS}

.PHONY: include
include:
	${CP} ${INCLUDEFILES} ${INCLUDEDIR}


clean:
	rm -rf ${OBJECTS}

