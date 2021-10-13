#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   /* Qwerty
    * ,------------------------------------------------------------------------------------.
    * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  Bksp*|
    * |------+------+------+------+------+-------------+------+------+------+------+-------|
    * | Esc* |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   "   |
    * |------+------+------+------+------+------|------+------+------+------+------+-------|
    * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Enter |
    * |------+------+------+------+------+------+------+------+------+------+------+-------|
    * | Ctrl |ADJUST|  Gui |  Alt |    Space    |     NUMS    |ADJUST|  APP | PRINT|  CTRL |
    * `------------------------------------------------------------------------------------'
    *
    * LCTL_T(KC_ESC)
    */
    [0] = LAYOUT_ortho_4x12_2x2u(
        KC_TAB,         KC_Q,  KC_W,    KC_E,    KC_R,   KC_T,  KC_Y,  KC_U,   KC_I,    KC_O,   KC_P,    KC_BSPC,
        LCTL_T(KC_ESC), KC_A,  KC_S,    KC_D,    KC_F,   KC_G,  KC_H,  KC_J,   KC_K,    KC_L,   KC_SCLN, KC_QUOT,
        KC_LSFT,        KC_Z,  KC_X,    KC_C,    KC_V,   KC_B,  KC_N,  KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
        KC_LCTL,        MO(2), KC_LGUI, KC_LALT,    KC_SPC,        MO(1),      MO(2),   KC_APP, KC_PSCR, KC_RCTL
    ),

   /* Nums
    * ,-----------------------------------------------------------------------------------.
    * |  ~   |   1  |   2  |  3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  Bksp |
    * |------+------+------+-----+------+-------------+------+------+------+------+-------|
    * | Esc  |      |      |     |      |      |   -  |   =  |   (  |   )  |   [  |   ]   |
    * |------+------+------+-----+------+------|------+------+------+------+------+-------|
    * | Shift|      |      |     |      |      |      |      |      |      |      |       |
    * |------+------+------+-----+------+------+------+------+------+------+------+-------|
    * | Ctrl |      | GUI  | ALT |             |     NUMS    |      |      |      |       |
    * `-----------------------------------------------------------------------------------'
    */
    [1] = LAYOUT_ortho_4x12_2x2u(
        KC_GRV,   KC_1,  KC_2,    KC_3,    KC_4,  KC_5,    KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_BSPC,
        _______,  KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_MINS, KC_EQL, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC,
        _______,  KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,
        _______,  KC_NO, _______, _______,     KC_NO,         _______,      KC_NO,   KC_NO,   KC_NO,   KC_NO
    ),


   /* Adjust
    * ,-----------------------------------------------------------------------------------.
    * |      |  F1  |  F2  | F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  Vol+ |
    * |------+------+------+-----+------+-------------+------+------+------+------+-------|
    * | Esc  | F11  |  F12 |     |      |      |      | LEFT | DOWN |  UP  |RIGHT |  Vol- |
    * |------+------+------+-----+------+------|------+------+------+------+------+-------|
    * | Shift|      |      |     |      |      | Prev | Next | Play |      |   \  |  Mute |
    * |------+------+------+-----+------+------+------+------+------+------+------+-------|
    * | Ctrl |      |  GUI | ALT |             |     NUMS    |      | RESET|      |       |
    * `-----------------------------------------------------------------------------------'
    */
    [2] = LAYOUT_ortho_4x12_2x2u(
        KC_NO,   KC_F1,  KC_F2,    KC_F3,   KC_F4, KC_F5, KC_F6,   KC_F7,   KC_F8,   KC_F9, KC_F10,  KC_VOLU,
        _______, KC_F11, KC_F12,   KC_NO,   KC_NO, KC_NO, KC_NO,   KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_VOLD,
        _______, KC_NO,  KC_NO,    KC_NO,   KC_NO, KC_NO, KC_MPRV, KC_MNXT, KC_MPLY, KC_NO, KC_BSLS, KC_MUTE,
        _______, KC_NO,  _______,  _______,    KC_NO,         KC_NO,        KC_NO,   RESET, KC_NO,   KC_NO
    )
};

// `shift + backspace = del` combo
//
// https://docs.qmk.fm/#/feature_key_overrides?id=simple-example
const key_override_t delete_key_override = ko_make_basic(
    MOD_MASK_SHIFT,
    KC_BSPACE,
    KC_DELETE
);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    NULL // Null terminate the array of overrides!
};

// See also default debounce algorithms
// https://docs.qmk.fm/#/feature_debounce_type
//
// https://docs.qmk.fm/#/tap_hold
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_ESC:
            return TAPPING_TERM + 150;
        default:
            return TAPPING_TERM;
    }
}

