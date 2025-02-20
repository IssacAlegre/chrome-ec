# -*- makefile -*-
# Copyright 2020 The Chromium OS Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.
#
# Board specific files build
#

CHIP:=npcx
CHIP_FAMILY:=npcx7
CHIP_VARIANT:=npcx7m6fc
BASEBOARD:=trogdor

board-y+=battery.o
board-y+=board.o
board-y+=led.o
board-y+=sku.o
board-y+=switchcap.o
board-y+=usbc_config.o
