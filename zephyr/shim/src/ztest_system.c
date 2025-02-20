/* Copyright 2021 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "system.h"

/* Ongoing actions preventing going into deep-sleep mode. */
uint32_t sleep_mask;

void system_common_pre_init(void)
{
}

int system_add_jump_tag(uint16_t tag, int version, int size, const void *data)
{
	return EC_SUCCESS;
}

const uint8_t *system_get_jump_tag(uint16_t tag, int *version, int *size)
{
	return NULL;
}

int system_jumped_late(void)
{
	return 0;
}

enum ec_image system_get_image_copy(void)
{
	return EC_IMAGE_RW;
}

int system_is_locked(void)
{
	return 0;
}

int system_is_in_rw(void)
{
	return 1;
}

uint32_t system_get_reset_flags(void)
{
	return 0;
}
