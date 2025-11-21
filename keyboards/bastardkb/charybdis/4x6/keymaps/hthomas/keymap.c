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
    LAYER_GAME,
    LAYER_FUN_NUM,
    LAYER_SYM,
    LAYER_NUMPAD,
    LAYER_MOUSE,
    LAYER_NAVIGATION,
    LAYER_POINTER,
};

/** \brief Automatically enable sniping-mode on the pointer layer. */
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

#define GUI_A MT(MOD_LGUI, KC_A)
#define ALT_S MT(MOD_LALT, KC_S)
#define CTL_D MT(MOD_LCTL, KC_D)
#define SFT_F MT(MOD_LSFT, KC_F)

#define SFT_J MT(MOD_RSFT, KC_J)
#define CTL_K MT(MOD_RCTL, KC_K)
#define ALT_L MT(MOD_LALT, KC_L)
#define GUI_É MT(MOD_RGUI, KC_SCLN)

#define SFT_Í MT(MOD_LSFT, KC_NUBS)
#define SFT_QUOT MT(MOD_RSFT, KC_QUOT)

#define CTL_RBRC MT(MOD_RCTL, KC_RBRC)

#define TAB_FUN LT(LAYER_FUN_NUM, KC_TAB)
#define ESC_NUM LT(LAYER_NUMPAD, KC_ESC)
#define SPC_SYM LT(LAYER_SYM, KC_SPC)
#define ESC_FUN LT(LAYER_FUN_NUM, KC_ESC)

#define ENT_MOU LT(LAYER_MOUSE, KC_ENT)
#define SPC_NAV LT(LAYER_NAVIGATION, KC_SPC)

#define SM_Z LT(LAYER_SYM, KC_Z)
#define SM_SLSH LT(LAYER_SYM, KC_SLSH)

#define SM_C LT(LAYER_SYM, KC_C)
#define SM_COMM LT(LAYER_SYM, KC_COMM)

#define DF_BASE DF(LAYER_BASE)
#define DF_GAME DF(LAYER_GAME)
#define DF_NP   DF(LAYER_NUMPAD)
#define DF_NAV  DF(LAYER_NAVIGATION)

#define MO_FUN MO(LAYER_FUN_NUM)

#define PT_V LT(LAYER_POINTER, KC_V)
#define PT_M LT(LAYER_POINTER, KC_M)

#define _L_PTR(KC) LT(LAYER_POINTER, KC)

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

// Home row mod combos, not used on 4x6
// Combos for Hungarian accentuated characters
// Hungarian characters centered around the home row, in the inner 3 columns
const uint16_t PROGMEM combo_ER[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM combo_UI[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo_SD[] = {LALT_T(KC_S), LCTL_T(KC_D), COMBO_END};
const uint16_t PROGMEM combo_DF[] = {LCTL_T(KC_D), LSFT_T(KC_F), COMBO_END};
const uint16_t PROGMEM combo_JK[] = {RSFT_T(KC_J), RCTL_T(KC_K), COMBO_END};
const uint16_t PROGMEM combo_KL[] = {RCTL_T(KC_K), LALT_T(KC_L), COMBO_END};
const uint16_t PROGMEM combo_CV[] = {SM_C, _L_PTR(KC_V), COMBO_END};
const uint16_t PROGMEM combo_M_COMM[] = {_L_PTR(KC_M), SM_COMM, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_ER, KC_EQUAL), // ó
    COMBO(combo_UI, KC_RBRC), // ú
    COMBO(combo_SD, KC_NUBS), // í
    COMBO(combo_DF, KC_0), // ö
    COMBO(combo_JK, KC_MINS), // ü
    COMBO(combo_KL, KC_QUOT), // á
    COMBO(combo_CV, KC_LBRC), // ő
    COMBO(combo_M_COMM, KC_NUHS), // ű
};

// Use combos on the game layer for typing, can be disabled from the nav layer
// const uint16_t PROGMEM combo_AS[] = {KC_A,KC_S, COMBO_END};
// const uint16_t PROGMEM combo_SD[] = {KC_S, KC_D, COMBO_END};
// const uint16_t PROGMEM combo_DF[] = {KC_D, KC_F, COMBO_END};
// const uint16_t PROGMEM combo_FG[] = {KC_F, KC_G, COMBO_END};
// const uint16_t PROGMEM combo_HJ[] = {KC_H, KC_J, COMBO_END};
// const uint16_t PROGMEM combo_JK[] = {KC_J, KC_K, COMBO_END};
// const uint16_t PROGMEM combo_KL[] = {KC_K, KC_L, COMBO_END};
// const uint16_t PROGMEM combo_LÉ[] = {KC_L, KC_SCLN, COMBO_END};

// combo_t key_combos[] = {
//     COMBO(combo_AS, KC_NUBS),
//     COMBO(combo_SD, KC_EQUAL),
//     COMBO(combo_DF, KC_0),
//     COMBO(combo_FG, KC_LBRC),
//     COMBO(combo_HJ, KC_RBRC),
//     COMBO(combo_JK, KC_MINS),
//     COMBO(combo_KL, KC_NUHS),
//     COMBO(combo_LÉ, KC_QUOT),
// };

// clang-format off
// Classic Hungarian accents, only NUHS and KC_RBRC is changed
/*
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, KC_NUHS,    KC_0, KC_MINS,  KC_EQL,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_NUBS,   GUI_A,   ALT_S,   CTL_D,   SFT_F,    KC_G,       KC_H,   SFT_J,   CTL_K,   ALT_L,   GUI_É, KC_QUOT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX,    KC_Z,    KC_X,    SM_C,    PT_V,    KC_B,       KC_N,    PT_M, SM_COMM,  KC_DOT, KC_SLSH, KC_RBRC,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  TAB_FUN, ESC_NUM, SPC_SYM,     ENT_MOU, SPC_NAV,
                                           XXXXXXX, XXXXXXX,     KC_RALT
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  */

  // Alternative Hungarian layout
  const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_EQUAL,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,  KC_GRV,  KC_RBRC,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_0,       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_MINS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_NUBS,   GUI_A,   ALT_S,   CTL_D,   SFT_F,    KC_G,       KC_H,   SFT_J,   CTL_K,   ALT_L,   GUI_É, KC_QUOT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LBRC,    SM_Z,    KC_X,    SM_C,    PT_V,    KC_B,       KC_N,    PT_M, SM_COMM,  KC_DOT, SM_SLSH, KC_NUHS,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  TAB_FUN, ESC_NUM, SPC_SYM,     ENT_MOU, SPC_NAV,
                                           XXXXXXX, XXXXXXX,     KC_RALT
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_GAME] = LAYOUT(
    // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
          KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,  KC_0,    KC_BSPC,
    // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
          KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_ENT,
    // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
         KC_LSFT,   KC_A,     KC_S,    KC_D,    KC_F,    KC_G,       KC_H,   KC_J,   KC_K,     KC_L,  KC_SCLN,  KC_RSFT,
    // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
         KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    PT_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RCTL,
    // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                    KC_LALT, KC_SPC,  MO_FUN,     ENT_MOU,  SPC_NAV,
                                             KC_LGUI, KC_ESC,     KC_RALT
    //                            ╰───────────────────────────╯ ╰──────────────────╯
    ),

  [LAYER_FUN_NUM] = LAYOUT(
    // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
         XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,  KC_GRV, XXXXXXX,
    // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
         _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,  KC_F11,     KC_F12, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, _______,
    // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
         _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,_______,
    // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                    _______, _______, _______,    _______, _______,
                                             XXXXXXX, XXXXXXX,    XXXXXXX
    //                            ╰───────────────────────────╯ ╰──────────────────╯
    ),

    [LAYER_SYM] = LAYOUT(
    // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
         XXXXXXX, RALT(KC_1), LSFT(KC_5), RALT(KC_W), LSFT(KC_3), RALT(KC_M), RALT(KC_DOT), LSFT(KC_7), RALT(KC_SCLN), LSFT(KC_GRV), RALT(KC_3), XXXXXXX,
    // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
         _______, LSFT(KC_1), LSFT(KC_2), RALT(KC_Q), LSFT(KC_8), RALT(KC_F), RALT(KC_G), LSFT(KC_9), LSFT(KC_6), RALT(KC_SLASH), RALT(KC_COMMA), _______,
    // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
         _______, LSFT(KC_4), RALT(KC_X), RALT(KC_C), RALT(KC_V), RALT(KC_B), RALT(KC_N), RALT(KC_7), RALT(KC_5), RALT(KC_9), RALT(KC_0), _______,
    // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                    _______, _______, _______,    _______, _______,
                                             XXXXXXX, XXXXXXX,    XXXXXXX
    //                            ╰───────────────────────────╯ ╰──────────────────╯
    ),

  [LAYER_NUMPAD] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_NUM,    XXXXXXX,LSFT(KC_TAB), KC_TAB,    KC_DEL,  KC_PSLS,  KC_P7,   KC_P8,   KC_P9, KC_PMNS, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, KC_LGUI,   KC_LALT,   KC_LCTL,   KC_LSFT,   KC_PENT, KC_PAST,  KC_P4,   KC_P5,   KC_P6, KC_PPLS, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, LCTL(KC_Z),LCTL(KC_X),LCTL(KC_C),LCTL(KC_V),KC_BSPC, KC_P0,    KC_P1,   KC_P2,   KC_P3, KC_PDOT, _______,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                    _______, _______, _______,    KC_PENT, _______,
                                             XXXXXXX, XXXXXXX,    XXXXXXX
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_MOUSE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_WH_U, KC_WH_L, KC_MS_U, KC_WH_R, XXXXXXX,    MS_ACL2, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN2,    MS_ACL1, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_WH_D, KC_WBAK, KC_WREF, KC_WFWD, KC_BTN3,    MS_ACL0, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, _______,_______,     _______,  _______,
                                           _______,  _______,     _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),


  [LAYER_NAVIGATION] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_PGUP,  KC_HOME, KC_UP,   KC_END,  KC_DEL,    KC_CAPS, KC_PSCR, KC_SCRL, KC_PAUS,  KC_NUM, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT,  KC_ENT,    CM_TOGG, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, KC_PGDN, KC_WBAK, KC_WREF, KC_WFWD,  KC_INS,     DF_GAME, DF_BASE,   DF_NP,  DF_NAV, KC_APP, _______,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_TAB,   KC_ESC,  KC_SPC,    _______, _______,
                                            XXXXXXX, XXXXXXX,    XXXXXXX
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_POINTER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, S_D_RMOD, DPI_RMOD, RM_TOGG,   EE_CLR, QK_BOOT, QK_BOOT,  EE_CLR, RM_TOGG, DPI_RMOD, S_D_RMOD, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,   XXXXXXX, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, S_D_MOD, DPI_MOD, DRGSCRL, _______, SNIPING, SNIPING, _______, DRGSCRL, DPI_MOD, S_D_MOD, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_BTN1, KC_BTN2, KC_BTN3,    KC_BTN2, KC_BTN1,
                                           XXXXXXX, XXXXXXX,    XXXXXXX
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
};
// clang-format on

#ifdef POINTING_DEVICE_ENABLE
#    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
        if (auto_pointer_layer_timer == 0) {
           4 layer_on(LAYER_POINTER);
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
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif


// Turn off chordal hold when using drag on the pointer layer
// Turn off chordal hold for the thumb button layer taps
bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                      uint16_t other_keycode, keyrecord_t* other_record) {
    // Exceptionally allow some one-handed chords for hotkeys.
    switch (tap_hold_keycode) {
        case TAB_FUN:
        case ESC_NUM:
        case SPC_SYM:
        case ESC_FUN:
        case ENT_MOU:
        case SPC_NAV:
            return true;

        case _L_PTR(KC_V):
            if (other_keycode == SM_C) {
                return true;
            }
            break;

        case _L_PTR(KC_M):
            if (other_keycode == SM_COMM) {
                return true;
            }
            break;
    }
    // Otherwise defer to the opposite hands rule.
    return get_chordal_hold_default(tap_hold_record, other_record);
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    return true;
    /*
    switch (keycode) {
        case _L_PTR(KC_V):
        case _L_PTR(KC_M):
            // Do not select the hold action when another key is tapped.
            return false;
        default:
            // Immediately select the hold action when another key is tapped.
            return true;
    }
    */
}

// Allow quickly enter numbers and symbols with the thumb keys
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TAB_FUN:
        case ESC_NUM:
        case ESC_FUN:
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

// Use tap-only combos for Hungarian accents
// This will prevent writing 'ööööööööööö' by holding down the combo,
// but make easier to use home row mods when they overlap with combos.
#ifdef COMBO_MUST_TAP_PER_COMBO
bool get_combo_must_tap(uint16_t combo_index, combo_t *combo) {
    // If you want *all* combos, that have Mod-Tap/Layer-Tap/Momentary keys in its chord, to be tap-only, this is for you:
    uint16_t key;
    uint8_t idx = 0;
    while ((key = pgm_read_word(&combo->keys[idx])) != COMBO_END) {
        switch (key) {
            case QK_MOD_TAP...QK_MOD_TAP_MAX:
            case QK_LAYER_TAP...QK_LAYER_TAP_MAX:
            case QK_MOMENTARY...QK_MOMENTARY_MAX:
                return true;
        }
        idx += 1;
    }
    return false;

}
#endif


bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_0:
        case KC_SCLN:
        case KC_LBRC:
        case KC_MINS:
        case KC_NUHS:
        case KC_NUBS:
        case KC_EQL:
        case KC_RBRC:
        case KC_QUOT:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_SLSH: // Hungarian - key
        case KC_1 ... KC_9:
        case KC_GRV:
        case KC_BSPC:
        case KC_DEL:
        case S(KC_SLSH):
        //case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}
