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
#include "keychron_common.h"

// clang-format off

#define CAPS_LOCK_LED_INDEX 29
//#define FN3_TOGGLE_LED_INDEX 43
#define FN2_LED_INDEX 63
#define FN3_LED_INDEX 64

#define RGB_INDICATOR RGB_WHITE

enum layers{
    MAC_BASE,
    WIN_BASE,
    _FN1,
    _FN2,
    _FN3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_iso_70(
        KC_ESC,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,     KC_7,     KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,             KC_MUTE,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,                       KC_DEL,
        KC_CAPS, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN,  KC_QUOT,  KC_NUHS,  KC_ENT,              KC_HOME,
        KC_LSFT, KC_NUBS,  KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,     KC_B,     KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT, KC_UP,
        KC_LCTL, KC_LOPTN, KC_LCMMD,          KC_SPC,           MO(_FN1), MO(_FN3),          KC_SPC,            KC_RCMMD,           KC_LEFT, KC_DOWN,    KC_RGHT),

    [WIN_BASE] = LAYOUT_iso_70(
        KC_ESC,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,     KC_7,     KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,             KC_MUTE,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,                       KC_DEL,
        KC_CAPS, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN,  KC_QUOT,  KC_NUHS,  KC_ENT,              KC_HOME,
        KC_LSFT, KC_NUBS,  KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,     KC_B,     KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT, KC_UP,
        KC_LCTL, KC_LWIN,  KC_LALT,           KC_SPC,           MO(_FN2), MO(_FN3),          KC_SPC,            KC_RALT,            KC_LEFT, KC_DOWN,    KC_RGHT),

    [_FN1] = LAYOUT_iso_70(
        KC_GRV,  KC_BRID,  KC_BRIU,  KC_MCTL, KC_LPAD, RGB_VAD, RGB_VAI,  KC_MPRV,  KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,             RGB_TOG,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI, _______,  _______,  _______, _______, _______,  _______,  _______,                       _______,
        _______, RGB_RMOD, RGB_VAD,  RGB_HUD, RGB_SAD, RGB_SPD, _______,  _______,  _______, _______, _______,  _______,  _______,  _______,             _______,
        _______, _______,  _______,  _______, _______, _______, _______,  _______,  NK_TOGG, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,           _______,           _______,            _______, _______,    _______),

    [_FN2] = LAYOUT_iso_70(
        KC_GRV,  KC_BRID,  KC_BRIU,  KC_TASK, KC_FLXP, RGB_VAD, RGB_VAI,  KC_MPRV,  KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,             RGB_TOG,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI, _______,  _______,  _______, _______, _______,  _______,  _______,                       _______,
        _______, RGB_RMOD, RGB_VAD,  RGB_HUD, RGB_SAD, RGB_SPD, _______,  _______,  _______, _______, _______,  _______,  _______,  _______,             _______,
        _______, _______,  _______,  _______, _______, _______, _______,  _______,  NK_TOGG, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,           _______,           _______,            _______, _______,    _______),

    [_FN3] = LAYOUT_iso_70(
        KC_TILD, KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,    KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,             _______,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI, _______,  _______,  _______, _______, _______,  _______,  _______,                       _______,
        _______, RGB_RMOD, RGB_VAD,  RGB_HUD, RGB_SAD, RGB_SPD, _______,  _______,  _______, _______, _______,  _______,  _______,  _______,             _______,
        _______, _______,  _______,  _______, _______, _______, _______,  _______,  _______, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,           _______,           _______,            _______, _______,    _______)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_FN1]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [_FN2]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [_FN3]   = {ENCODER_CCW_CW(_______, _______)}
};
#endif // ENCODER_MAP_ENABLE

// clang-format on

void housekeeping_task_user(void) {
    housekeeping_task_keychron();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron(keycode, record)) {
        return false;
    }
    return true;
}

void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

    // Set caps lock indicator
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(CAPS_LOCK_LED_INDEX, RGB_INDICATOR);
    } else {
        rgb_matrix_set_color(CAPS_LOCK_LED_INDEX, RGB_OFF);
    }

    // Light the FN buttons when the fn layers are active
    switch (get_highest_layer(layer_state|default_layer_state))
    {
        case _FN1:
        case _FN2:
            rgb_matrix_set_color(FN2_LED_INDEX, RGB_INDICATOR);
            rgb_matrix_set_color(FN3_LED_INDEX, RGB_OFF);
            break; 
        case _FN3:
            rgb_matrix_set_color(FN2_LED_INDEX, RGB_OFF);
            rgb_matrix_set_color(FN3_LED_INDEX, RGB_INDICATOR);
            break;
        default:
            rgb_matrix_set_color(FN2_LED_INDEX, RGB_OFF);
            rgb_matrix_set_color(FN3_LED_INDEX, RGB_OFF);
    }
    return false;
}

