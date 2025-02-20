/* Copyright 2021 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 *
 * Blipper specific PWM LED settings.
 */

#include "common.h"
#include "led_onoff_states.h"
#include "led_common.h"
#include "gpio.h"
#include "pwm.h"

#define LED_OFF_LVL	0
#define LED_ON_LVL	1

const int led_charge_lvl_1 = 5;

const int led_charge_lvl_2 = 97;

struct led_descriptor led_bat_state_table[LED_NUM_STATES][LED_NUM_PHASES] = {
	[STATE_CHARGING_LVL_1]	     = {{EC_LED_COLOR_RED,   LED_INDEFINITE} },
	[STATE_CHARGING_LVL_2]	     = {{EC_LED_COLOR_AMBER, LED_INDEFINITE} },
	[STATE_CHARGING_FULL_CHARGE] = {{EC_LED_COLOR_GREEN, LED_INDEFINITE} },
	[STATE_DISCHARGE_S0]	     = {{LED_OFF,            LED_INDEFINITE} },
	[STATE_DISCHARGE_S3]	     = {{LED_OFF,            LED_INDEFINITE} },
	[STATE_DISCHARGE_S5]         = {{LED_OFF,            LED_INDEFINITE} },
	[STATE_BATTERY_ERROR]        = {{EC_LED_COLOR_RED,   1 * LED_ONE_SEC},
					{LED_OFF,	     1 * LED_ONE_SEC} },
	[STATE_FACTORY_TEST]         = {{EC_LED_COLOR_RED,   2 * LED_ONE_SEC},
					{EC_LED_COLOR_GREEN, 2 * LED_ONE_SEC} },
};

const enum ec_led_id supported_led_ids[] = {
	EC_LED_ID_BATTERY_LED
};
const int supported_led_ids_count = ARRAY_SIZE(supported_led_ids);

void led_set_color_battery(enum ec_led_colors color)
{
	switch (color) {
	case EC_LED_COLOR_RED:
		pwm_enable(PWM_CH_LED_RED, LED_ON_LVL);
		pwm_enable(PWM_CH_LED_GREEN, LED_OFF_LVL);
		break;
	case EC_LED_COLOR_AMBER:
		pwm_enable(PWM_CH_LED_RED, LED_ON_LVL);
		pwm_enable(PWM_CH_LED_GREEN, LED_ON_LVL);
		break;
	case EC_LED_COLOR_GREEN:
		pwm_enable(PWM_CH_LED_RED, LED_OFF_LVL);
		pwm_enable(PWM_CH_LED_GREEN, LED_ON_LVL);
		break;
	default: /* LED_OFF and other unsupported colors */
		pwm_enable(PWM_CH_LED_RED, LED_OFF_LVL);
		pwm_enable(PWM_CH_LED_GREEN, LED_OFF_LVL);
		break;
	}
}

void led_get_brightness_range(enum ec_led_id led_id, uint8_t *brightness_range)
{
	brightness_range[EC_LED_COLOR_RED] = 1;
	brightness_range[EC_LED_COLOR_AMBER] = 1;
	brightness_range[EC_LED_COLOR_GREEN] = 1;
}

int led_set_brightness(enum ec_led_id led_id, const uint8_t *brightness)
{
	if (brightness[EC_LED_COLOR_RED] != 0)
		led_set_color_battery(EC_LED_COLOR_RED);
	else if (brightness[EC_LED_COLOR_AMBER] != 0)
		led_set_color_battery(EC_LED_COLOR_AMBER);
	else if (brightness[EC_LED_COLOR_GREEN] != 0)
		led_set_color_battery(EC_LED_COLOR_GREEN);
	else
		led_set_color_battery(LED_OFF);
	return EC_SUCCESS;
}
