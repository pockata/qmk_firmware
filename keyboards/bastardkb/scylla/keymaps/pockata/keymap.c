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

#include QMK_KEYBOARD_H

// ESC on click, CTRL on hold
#define MY_ESC LCTL_T(KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   /**
    * .-----------------------------------------.                                  .-----------------------------------------.
    * | Tab  |   1  |   2  |   3  |   4  |   5  |                                  |   6  |   7  |   8  |   9  |   0  |  Bsp |
    * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
    * | ESC* |   Q  |   W  |   E  |   R  |   T  |                                  |   Y  |   U  |   I  |   O  |   P  |  \   |
    * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
    * | Shft |   A  |   S  |   D  |   F  |   G  |                                  |   H  |   J  |   K  |   L  |   ;  |  '   |
    * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
    * | Ctrl |   Z  |   X  |   C  |   V  |   B  |                                  |   N  |   M  |   ,  |   .  |   /  | Entr |
    * '-----------------------------------------/                                  \-----------------------------------------'
    *                                  /  WIN  /---------------.    .---------------\  CTRL \
    *                                 /       / Space /  ALT  /      \  ALT  \ LAYER \       \
    *                                '-------/       /       /        \       \  2    \-------'
    *                                       /---------------/          \---------------\
    *                                      / LAYER / Ctrl  /            \  SHFT \ LAYER \
    *                                     /   1   /       /              \       \  3    \
    *                                    '---------------'                '---------------'
    */
    [0] = LAYOUT_split_4x6_5(
        KC_TAB,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,		  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        MY_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,		  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,	      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                                   KC_LWIN, KC_SPC,  KC_LALT,	  KC_LALT, MO(2),   KC_LCTL,
                                            MO(1),   KC_LCTL,     KC_LSFT, MO(3)
    ),


    [1] = LAYOUT_split_4x6_5(
        XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,		  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        XXXXXXX, KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX,	  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,	  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAD, RGB_TOG, XXXXXXX,
                                   _______, _______, _______,	  _______, XXXXXXX, _______,
                                            XXXXXXX, RESET,       _______, XXXXXXX
    ),

    [2] = LAYOUT_split_4x6_5(
        XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,	  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,		  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,	  KC_MINS, KC_EQL,  KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS, XXXXXXX,
                                   _______, _______, _______,	  _______, XXXXXXX, _______,
                                            XXXXXXX, _______,     XXXXXXX, XXXXXXX
    ),


    [3] = LAYOUT_split_4x6_5(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,	  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,	  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_VOLD,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,	  XXXXXXX, KC_MNXT, KC_MPLY, XXXXXXX, KC_BSLS, KC_PSCR,
                                   _______, _______, _______,     _______, XXXXXXX, _______,
                                            XXXXXXX, _______,     _______, XXXXXXX
    ),
};

// TODO: Turn off RGB lights on keyboard idle, e.g. 10min
// Code is for RGB Matrix only but can be asapted for RGB Underglow also
// https://gist.github.com/MaxWinterstein/c99594a5f4f8da942feb72c8233445aa/#file-keymap-c-L133

