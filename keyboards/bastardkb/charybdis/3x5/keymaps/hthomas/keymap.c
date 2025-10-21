/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#    include "timer.h"
#endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_GAME = 1,
    LAYER_FUN_NUM = 2,
    LAYER_SYM = 3,
    LAYER_NUMPAD = 4,
    LAYER_MOUSE = 5,
    LAYER_NAVIGATION = 6,
    LAYER_POINTER = 7,
};

// Automatically enable sniping-mode on the pointer layer.
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER LAYER_POINTER

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#endif     // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#define TAB_SYM LT(LAYER_SYM, KC_TAB)
#define SPC_FUN LT(LAYER_FUN_NUM, KC_SPC)
#define ESC_NUM LT(LAYER_NUMPAD, KC_ESC)
#define ESC_FUN LT(LAYER_FUN_NUM, KC_ESC)

#define ENT_MOU LT(LAYER_MOUSE, KC_ENT)
#define SPC_NAV LT(LAYER_NAVIGATION, KC_SPC)

#define DF_BASE DF(LAYER_BASE)
#define DF_GAME DF(LAYER_GAME)
#define DF_NP   DF(LAYER_NUMPAD)
#define DF_NAV  DF(LAYER_NAVIGATION)

#define _L_PTR(KC) LT(LAYER_POINTER, KC)

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

const uint16_t PROGMEM combo_AS[] = {LGUI_T(KC_A), LALT_T(KC_S), COMBO_END};
const uint16_t PROGMEM combo_SD[] = {LALT_T(KC_S), LCTL_T(KC_D), COMBO_END};
const uint16_t PROGMEM combo_DF[] = {LCTL_T(KC_D), LSFT_T(KC_F), COMBO_END};
const uint16_t PROGMEM combo_FG[] = {LSFT_T(KC_F), KC_G, COMBO_END};
const uint16_t PROGMEM combo_HJ[] = {KC_H, RSFT_T(KC_J), COMBO_END};
const uint16_t PROGMEM combo_JK[] = {RSFT_T(KC_J), RCTL_T(KC_K), COMBO_END};
const uint16_t PROGMEM combo_KL[] = {RCTL_T(KC_K), LALT_T(KC_L), COMBO_END};
const uint16_t PROGMEM combo_LÉ[] = {LALT_T(KC_L), RGUI_T(KC_SCLN), COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_AS, KC_NUBS),
    COMBO(combo_SD, KC_EQUAL),
    COMBO(combo_DF, KC_0),
    COMBO(combo_FG, KC_LBRC),
    COMBO(combo_HJ, KC_RBRC),
    COMBO(combo_JK, KC_MINS),
    COMBO(combo_KL, KC_NUHS),
    COMBO(combo_LÉ, KC_QUOT),
};

// clang-format off
/** \brief QWERTY layout (3 rows, 10 columns). */
#define LAYOUT_LAYER_BASE                                                                     \
       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, \
       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, \
       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, \
                      TAB_SYM, SPC_FUN, ESC_NUM, ENT_MOU, SPC_NAV

/** \brief QWERTY layout (3 rows, 10 columns) without Home row mods */
#define LAYOUT_LAYER_GAME                                                                     \
       KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, \
       KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, \
       KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, \
                      KC_LALT, KC_SPC, ESC_FUN, ENT_MOU, SPC_NAV

/** \brief Numbers and Function layer. */
#define LAYOUT_LAYER_FUN_NUM                                                                 \
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,   KC_7,    KC_8,    KC_9,    KC_GRV, \
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,  KC_F11, KC_F12, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, \
    KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,  KC_F6,  KC_F7,   KC_F8,   KC_F9,   KC_F10, \
                      _______, _______, _______, KC_RALT, _______

/** \brief Numpad Layer */
#define LAYOUT_LAYER_NUMPAD                                                                    \
    XXXXXXX, XXXXXXX, KC_NUM, KC_TAB,  KC_DEL,     KC_PSLS,   KC_P7,   KC_P8,   KC_P9, KC_PMNS, \
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_PENT,    KC_PAST,   KC_P4,   KC_P5,   KC_P6, KC_PPLS, \
    XXXXXXX, XXXXXXX, XXXXXXX, LSFT(KC_TAB), KC_BSPC,      KC_P0,   KC_P1,   KC_P2,   KC_P3, KC_PDOT, \
                      _______, _______, _______,    KC_PENT, _______

/** \brief Pointing Layer for trackball controls and mouse click and misc */
#define LAYOUT_LAYER_POINTER                                                                  \
    DPI_MOD,  S_D_MOD, RM_TOGG,   EE_CLR, QK_BOOT, QK_BOOT,  EE_CLR, RM_TOGG,  S_D_MOD, DPI_MOD, \
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, XXXXXXX, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, \
    DPI_RMOD, S_D_RMOD, DRGSCRL, _______, SNIPING, SNIPING, _______, DRGSCRL, S_D_RMOD, DPI_RMOD, \
                      KC_BTN2, KC_BTN1, KC_BTN3, KC_BTN3, KC_BTN1

/** \brief Symbols layer - mostly for Hungarian special characters with AltGr */
#define LAYOUT_LAYER_SYM                                                               \
    LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_GRV), \
    RALT(KC_Q), RALT(KC_W), RALT(KC_3), RALT(KC_M), RALT(KC_F), RALT(KC_G), RALT(KC_DOT), RALT(KC_SCLN), RALT(KC_SLASH), RALT(KC_COMMA), \
    RALT(KC_1), RALT(KC_X), RALT(KC_C), RALT(KC_V), RALT(KC_B), RALT(KC_N), RALT(KC_7), RALT(KC_5), RALT(KC_9), RALT(KC_0), \
                      _______, _______, _______, _______, _______

/** \brief Mouse layer - traditional keyboard mouse controls and media controls */
#define LAYOUT_LAYER_MOUSE                                                               \
    KC_WH_U, KC_WH_L, KC_MS_U, KC_WH_R, XXXXXXX, MS_ACL0, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, \
    KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN2, MS_ACL2, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, \
    KC_WH_D, KC_WBAK, KC_WREF, KC_WFWD, KC_BTN3, MS_ACL1, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, \
                      _______, _______, _______, _______, _______

/** \brief Navigation layer. */
#define LAYOUT_LAYER_NAVIGATION                                                                  \
    KC_PGUP,  KC_HOME, KC_UP,   KC_END,  KC_DEL,    KC_CAPS, KC_PSCR, KC_SCRL, KC_PAUS, KC_NUM, \
    KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT,  KC_ENT,    CM_TOGG, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, \
    KC_PGDN, KC_WBAK, KC_WREF, KC_WFWD,  KC_INS,    DF_GAME, DF_BASE,   DF_NP,  DF_NAV, KC_APP, \
                      _______,  KC_SPC, _______, _______, _______

/**
 * \brief Add Home Row mod to a layout.
 *
 * Expects a 10-key per row layout.  Adds support for GACS (Gui, Alt, Ctl, Shift)
 * home row.  The layout passed in parameter must contain at least 20 keycodes.
 *
 * This is meant to be used with `LAYER_ALPHAS_QWERTY` defined above, eg.:
 *
 *     HOME_ROW_MOD_GACS(LAYER_ALPHAS_QWERTY)
 */
#define _HOME_ROW_MOD_GACS(                                            \
    L00, L01, L02, L03, L04, R05, R06, R07, R08, R09,                  \
    L10, L11, L12, L13, L14, R15, R16, R17, R18, R19,                  \
    ...)                                                               \
             L00,         L01,         L02,         L03,         L04,  \
             R05,         R06,         R07,         R08,         R09,  \
      LGUI_T(L10), LALT_T(L11), LCTL_T(L12), LSFT_T(L13),        L14,  \
             R15,  RSFT_T(R16), RCTL_T(R17), LALT_T(R18), RGUI_T(R19), \
      __VA_ARGS__
#define HOME_ROW_MOD_GACS(...) _HOME_ROW_MOD_GACS(__VA_ARGS__)

/**
 * \brief Add pointer layer keys to a layout.
 *
 * Expects a 10-key per row layout.  The layout passed in parameter must contain
 * at least 30 keycodes.
 *
 * This is meant to be used with `LAYER_ALPHAS_QWERTY` defined above, eg.:
 *
 *     POINTER_MOD(LAYER_ALPHAS_QWERTY)
 */
#define _POINTER_MOD(                                                  \
    L00, L01, L02, L03, L04, R05, R06, R07, R08, R09,                  \
    L10, L11, L12, L13, L14, R15, R16, R17, R18, R19,                  \
    L20, L21, L22, L23, L24, R25, R26, R27, R28, R29,                  \
    ...)                                                               \
             L00,         L01,         L02,         L03,         L04,  \
             R05,         R06,         R07,         R08,         R09,  \
             L10,         L11,         L12,         L13,         L14,  \
             R15,         R16,         R17,         R18,         R19,  \
             L20,         L21,         L22,  _L_PTR(L23),        L24,  \
             R25,  _L_PTR(R26),        R27,         R28,         R29,  \
      __VA_ARGS__
#define POINTER_MOD(...) _POINTER_MOD(__VA_ARGS__)

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_wrapper(
    POINTER_MOD(HOME_ROW_MOD_GACS(LAYOUT_LAYER_BASE))
  ),
  [LAYER_GAME] = LAYOUT_wrapper(LAYOUT_LAYER_GAME),
  [LAYER_FUN_NUM] = LAYOUT_wrapper(LAYOUT_LAYER_FUN_NUM),
  [LAYER_SYM] = LAYOUT_wrapper(LAYOUT_LAYER_SYM),
  [LAYER_NUMPAD] = LAYOUT_wrapper(LAYOUT_LAYER_NUMPAD),
  [LAYER_MOUSE] = LAYOUT_wrapper(LAYOUT_LAYER_MOUSE),
  [LAYER_NAVIGATION] = LAYOUT_wrapper(LAYOUT_LAYER_NAVIGATION),
  [LAYER_POINTER] = LAYOUT_wrapper(LAYOUT_LAYER_POINTER),
};
// clang-format on

#ifdef POINTING_DEVICE_ENABLE
#    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
        if (auto_pointer_layer_timer == 0) {
            layer_on(LAYER_POINTER);
#        ifdef RGB_MATRIX_ENABLE
            rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
            rgb_matrix_sethsv_noeeprom(HSV_GREEN);
#        endif // RGB_MATRIX_ENABLE
        }
        auto_pointer_layer_timer = timer_read();
    }
    return mouse_report;
}

void matrix_scan_user(void) {
    if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
        auto_pointer_layer_timer = 0;
        layer_off(LAYER_POINTER);
#        ifdef RGB_MATRIX_ENABLE
        rgb_matrix_mode_noeeprom(RGB_MATRIX_DEFAULT_MODE);
#        endif // RGB_MATRIX_ENABLE
    }
}
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in
// rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif
