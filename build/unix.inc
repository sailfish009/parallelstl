##===-- unix.inc ----------------------------------------------------------===##
#
# Copyright (C) 2017-2019 Intel Corporation
#
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#
# This file incorporates work covered by the following copyright and permission
# notice:
#
# Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
# See https://llvm.org/LICENSE.txt for license information.
#
##===----------------------------------------------------------------------===##

PYTHON = python
KEY = -
QKEY = $(KEY)q
FKEY = $(KEY)
FQKEY = $(KEY)
MACHINE_KEY = $(KEY)m
OBJ_SFX = .o
DEL_CMD = rm $(KEY)f
RUN_CMD = ./
COMMAND_SEPARATOR = ;
compiler ?= gcc
COMPILER_NOLOGO_KEY =
OPTIMIZATION_DISABLED_FLAGS = $(KEY)O0 $(KEY)g
OPTIMIZATION_ENABLED_FLAGS +=  $(KEY)O2
TBB_LIB_NAME = tbb
CPLUS = $(compiler)
LD = $(CPLUS)

USE_SHARED_CPPRUNTIME_KEY =
LINK_KEY = $(KEY)l

LD_OUT_KEY = $(KEY)o
DYN_LDFLAGS += -L. -L$(proj_root)/build

ifneq ($(PSTL_LIB_NAME), )
    PSTL_LIB_LINK += $(LINK_KEY)$(PSTL_LIB_NAME)$(PSTL_LIB_EXT)
endif

ifeq ($(backend), tbb)
    DYN_LDFLAGS += $(LINK_KEY)$(TBB_LIB_NAME)
endif


ifeq ($(arch),intel64)
    PSTL_ARCH = $(MACHINE_KEY)64
else ifeq ($(arch),ia32)
    PSTL_ARCH = $(MACHINE_KEY)32
else ifeq ($(arch),)
    $(info arch=native by default)
else
    PSTL_ARCH = $(MACHINE_KEY)$(arch)
endif
