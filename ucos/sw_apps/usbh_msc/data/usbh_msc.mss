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


PARAMETER VERSION = 2.2.0


BEGIN OS
 PARAMETER OS_NAME = ucos
END

BEGIN LIBRARY
 PARAMETER LIBRARY_NAME = ucos_osiii
END

BEGIN LIBRARY
 PARAMETER LIBRARY_NAME = ucos_common
END

BEGIN LIBRARY
 PARAMETER LIBRARY_NAME = ucos_standalone
END

BEGIN LIBRARY
 PARAMETER LIBRARY_NAME = ucos_usbh
END

BEGIN LIBRARY
 PARAMETER LIBRARY_NAME = ucos_fs
END
