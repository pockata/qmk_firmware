/*
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once
#include "config_common.h"
#define VENDOR_ID 0xA8F8
#define PRODUCT_ID 0x1829
#define DEVICE_VER 0x0001
#define MANUFACTURER Bastard Keyboards
#define PRODUCT Scylla

#define MATRIX_ROWS 12
#define MATRIX_COLS 6
#define DIODE_DIRECTION COL2ROW

#define MATRIX_ROW_PINS { D4, C6, D7, E6, B4, B5 }
#define MATRIX_COL_PINS { B6, B2, B3, B1, F7, F6 }
#define MATRIX_COL_PINS_RIGHT { F6, F7, B1, B3, B2, B6 }

#define MASTER_LEFT
#define DEBOUNCE 5
#define USE_SERIAL

#define RGB_DI_PIN D1
#define RGBLED_NUM 26
#define RGBLED_SPLIT { 13, 13 }

// switch off the RGB lights when the host goes to sleep
#define RGBLIGHT_SLEEP
#define RGBLIGHT_ANIMATIONS
// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_rgblight.md#configuration
//
// TODO: Create custom keycode to print current RGB info to console
// https://docs.qmk.fm/#/custom_quantum_functions?id=defining-a-new-keycode
#define RGBLIGHT_HUE_STEP 3 // default: 10
#define RGBLIGHT_SAT_STEP 5 // default: 17
#define RGBLIGHT_DEFAULT_VAL 221 // default: 255
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_LIGHT
#define RGBLIGHT_DEFAULT_HUE 24

