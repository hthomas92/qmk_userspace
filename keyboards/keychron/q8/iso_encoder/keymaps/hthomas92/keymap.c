/* Copyright 2021 @ Keychron (https://www.keychron.com)
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

// clang-format off

enum layers {
    MAC_BASE, // Space+Fn enabled, layer 0 in Keychron launcher
    WIN_BASE, // Space+Fn disabled for gaming, layer 1 in Keychron launcher
    _SYM,     // Numbers and symbols layer
    _NUM,     // Numpad layer
    _NAV      // Nav layer
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

#define NAV_SPC LT(_NAV, KC_SPC)
#define SYM_SPC LT(_SYM, KC_SPC)

#define RCTL_LEFT MT(MOD_RCTL, KC_LEFT)

#define CAPS_LOCK_LED_INDEX 29

#define NAV_LED_INDEX 63
#define NUM_LED_INDEX 64

#define RGB_INDICATOR RGB_WHITE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_iso_70(
        KC_GRV,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,     KC_7,     KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_MPLY,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,                    KC_PSCR,
        KC_ESC,  KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN,  KC_QUOT,  KC_NUHS,  KC_ENT,           KC_PAUS,
        KC_LSFT, KC_NUBS,  KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,     KC_DEL,   KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT, KC_UP,
        KC_LCTL, KC_LWIN,  KC_LALT,           SYM_SPC,          TG(_NAV), TG(_NUM),          NAV_SPC,          KC_RALT,           RCTL_LEFT,KC_DOWN, KC_RGHT),

    [WIN_BASE] = LAYOUT_iso_70(
        KC_GRV,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,     KC_7,     KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_MPLY,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,                    KC_PSCR,
        KC_ESC,  KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN,  KC_QUOT,  KC_NUHS,  KC_ENT,           KC_PAUS,
        KC_LSFT, KC_NUBS,  KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,     KC_DEL,   KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT, KC_UP,
        KC_LCTL, KC_LWIN,  KC_LALT,           KC_SPC,           MO(_NAV), TG(_NUM),          NAV_SPC,           KC_RALT,           KC_LEFT, KC_DOWN, KC_RGHT),

    [_SYM] = LAYOUT_iso_70(
        XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,          XXXXXXX,
        KC_GRV,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,     KC_7,     KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,                     XXXXXXX,
        _______, KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,    KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   XXXXXXX,          XXXXXXX,
        _______, S(KC_GRV),S(KC_1),  S(KC_2), S(KC_3), S(KC_4), S(KC_5),  _______,  S(KC_6),  S(KC_7), S(KC_8), S(KC_9),  S(KC_0),  _______,  KC_PGUP,
        _______, _______,  _______,           _______,          XXXXXXX,  XXXXXXX,           _______,           _______,            KC_HOME, KC_PGDN, KC_END),

    [_NUM] = LAYOUT_iso_70(
        KC_ESC,  KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,    KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_BSPC,          KC_MUTE,
        KC_TAB,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, KC_PSLS,  KC_P7,    KC_P8,   KC_P9,   KC_PMNS,  _______,  _______,                    KC_SCRL,
        KC_CAPS, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, KC_PAST,  KC_P4,    KC_P5,   KC_P6,   KC_PPLS,  _______,  _______,  _______,           KC_NUM,
        _______, XXXXXXX,  XXXXXXX,  KC_CALC, XXXXXXX, XXXXXXX, _______,  KC_INS,   KC_P0,   KC_P1,   KC_P2,    KC_P3,    _______,  _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,           KC_P0,             KC_PENT,            _______, _______, _______),

    [_NAV] = LAYOUT_iso_70(
        KC_ESC,  KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,    KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,          RM_TOGG,
        _______, KC_PGUP,  KC_HOME,  KC_UP,   KC_END,   KC_DEL, KC_WH_U,  KC_WH_L,  KC_MS_U, KC_WH_R, KC_BTN2,  _______,  _______,                    KC_SCRL,
        _______, KC_BSPC,  KC_LEFT,  KC_DOWN, KC_RGHT,  KC_ENT, KC_WH_D,  KC_MS_L,  KC_MS_D, KC_MS_R, KC_BTN1,  _______,  _______,  _______,           KC_NUM,
        _______, XXXXXXX,  KC_PGDN,  XXXXXXX, XXXXXXX,  KC_INS, _______,  _______,  _______, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,            KC_SPC,          _______,  _______,            KC_SPC,            KC_APP,            _______, _______, _______)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_BASE] = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT)},
    [_SYM]   = {ENCODER_CCW_CW(RM_VALD, RM_VALU)},
    [_NUM]   = {ENCODER_CCW_CW(KC_VOLD, KC_VOLD)},
    [_NAV]   = {ENCODER_CCW_CW(RM_VALD, RM_VALU)}
};
#endif // ENCODER_MAP_ENABLE

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

    // // Set custom caps lock indicator
    // if (host_keyboard_led_state().caps_lock) {
    //     rgb_matrix_set_color(CAPS_LOCK_LED_INDEX, RGB_INDICATOR);
    // } else {
    //     rgb_matrix_set_color(CAPS_LOCK_LED_INDEX, RGB_OFF);
    // }

    // Light the FN buttons when the fn layers are active
    switch (get_highest_layer(layer_state|default_layer_state))
    {
        case _NUM:
            rgb_matrix_set_color(NUM_LED_INDEX, RGB_INDICATOR);
            rgb_matrix_set_color(NAV_LED_INDEX, RGB_OFF);
            break;
        case _NAV:
            rgb_matrix_set_color(NUM_LED_INDEX, RGB_OFF);
            rgb_matrix_set_color(NAV_LED_INDEX, RGB_INDICATOR);
            break;
        default:
            rgb_matrix_set_color(NUM_LED_INDEX, RGB_OFF);
            rgb_matrix_set_color(NAV_LED_INDEX, RGB_OFF);
    }
    return true; // Continue running the keyboard-level callback and use default caps lock indicator
}
