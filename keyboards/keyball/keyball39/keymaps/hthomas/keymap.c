/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

enum keymap_layers {
    LAYER_BASE = 0,
    LAYER_GAME,
    LAYER_FUN_NUM,
    LAYER_FUN_A,
    LAYER_SYM,
    LAYER_SYM_A,
    LAYER_NUMPAD,
    LAYER_NUMPAD_A,
    LAYER_MOUSE,
    LAYER_MOUSE_A,
    LAYER_NAVIGATION_A,
    LAYER_NAVIGATION,
    LAYER_POINTER,
};

// Automatically enable sniping-mode on the pointer layer.
#define AUTO_SNIPING_ON_LAYER LAYER_POINTER

#define TAB_FUN LT(LAYER_FUN_NUM, KC_TAB)
#define ESC_NUM LT(LAYER_NUMPAD, KC_ESC)
#define SPC_SYM LT(LAYER_SYM, KC_SPC)
#define ESC_FUN LT(LAYER_FUN_NUM, KC_ESC)

#define TAB_FUN_A LT(LAYER_FUN_A, KC_TAB)
#define ESC_NUM_A LT(LAYER_NUMPAD_A, KC_ESC)

#define ENT_MOU LT(LAYER_MOUSE, KC_ENT)
#define SPC_NAV LT(LAYER_NAVIGATION, KC_SPC)

#define ENT_MOU_A LT(LAYER_MOUSE_A, KC_ENT)
#define SPC_NAV_A LT(LAYER_NAVIGATION_A, KC_SPC)

#define SM_Z LT(LAYER_SYM, KC_Z)
#define SM_SLSH LT(LAYER_SYM, KC_SLSH)

#define SM_X LT(LAYER_SYM, KC_X)
#define SM_DOT LT(LAYER_SYM, KC_DOT)

#define SM_C LT(LAYER_SYM_A, KC_C)
#define SM_COMM LT(LAYER_SYM_A, KC_COMM)

#define DF_BASE DF(LAYER_BASE)
#define DF_GAME DF(LAYER_GAME)
#define DF_NP   DF(LAYER_NUMPAD)
#define DF_NAV  DF(LAYER_NAVIGATION)
#define DF_NP_A   DF(LAYER_NUMPAD_A)
#define DF_NAV_A  DF(LAYER_NAVIGATION_A)

#define _L_PTR(KC) LT(LAYER_POINTER, KC)

// Combos for Hungarian accentuated characters, layout 1
// Hungarian characters centered around the home row, in the inner 3 columns
const uint16_t PROGMEM combo_ER[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM combo_UI[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo_SD[] = {LALT_T(KC_S), LCTL_T(KC_D), COMBO_END};
const uint16_t PROGMEM combo_DF[] = {LCTL_T(KC_D), LSFT_T(KC_F), COMBO_END};
const uint16_t PROGMEM combo_JK[] = {RSFT_T(KC_J), RCTL_T(KC_K), COMBO_END};
const uint16_t PROGMEM combo_KL[] = {RCTL_T(KC_K), LALT_T(KC_L), COMBO_END};
const uint16_t PROGMEM combo_CV[] = {SM_C, _L_PTR(KC_V), COMBO_END};
const uint16_t PROGMEM combo_M_COMM[] = {_L_PTR(KC_M), SM_COMM, COMBO_END};
const uint16_t PROGMEM combo_NAV_A[] = {DF_BASE, DF_NP, DF_NAV, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_ER, KC_LBRC), // ő
    COMBO(combo_UI, KC_NUHS), // ű
    COMBO(combo_SD, KC_NUBS), // í
    COMBO(combo_DF, KC_0), // ö
    COMBO(combo_JK, KC_MINS), // ü
    COMBO(combo_KL, KC_QUOT), // á
    COMBO(combo_CV, KC_EQUAL), // ó
    COMBO(combo_M_COMM, KC_RBRC), // ú
    COMBO(combo_NAV_A, DF_NAV_A) // switch to right handed nav layer.
};

// clang-format off
/** \brief QWERTY layout (3 rows, 10 columns). */
#define LAYOUT_LAYER_BASE                                                                     \
       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, \
       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, \
       SM_Z,    SM_X,    SM_C,    KC_V,    KC_B,    KC_N,    KC_M, SM_COMM,  SM_DOT, SM_SLSH, \
       XXXXXXX, XXXXXXX, XXXXXXX, TAB_FUN, ESC_NUM, SPC_SYM, ENT_MOU, SPC_NAV, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

/** \brief QWERTY layout (3 rows, 10 columns) without Home row mods */
#define LAYOUT_LAYER_GAME                                                                     \
       KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, \
       KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, \
       KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, \
       XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC, KC_LALT, ESC_FUN, ENT_MOU, SPC_NAV, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

/** \brief Numbers and Function layer. */
#define LAYOUT_LAYER_FUN_NUM                                                                \
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,   KC_7,    KC_8,    KC_9,    KC_GRV, \
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,  KC_F11, KC_F12, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,\
    KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,  KC_F6,  KC_F7,   KC_F8,   KC_F9,   KC_F10, \
    XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, KC_RALT, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

/** \brief Alternative Function layer. */
#define LAYOUT_LAYER_FUN_A                                                                       \
    KC_LALT, KC_F7,   KC_F8,   KC_F9,   KC_F12,  XXXXXXX,  XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, \
    KC_LSFT, KC_F4,   KC_F5,   KC_F6,   KC_F11,  XXXXXXX,  KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,   \
    KC_LCTL, KC_F1,   KC_F2,   KC_F3,   XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, KC_RALT, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX


/** \brief Numpad Layer */
#define LAYOUT_LAYER_NUMPAD                                                                             \
    KC_NUM,    LALT(KC_F4),LSFT(KC_TAB),KC_TAB,    KC_DEL,  KC_PSLS,  KC_P7,   KC_P8,   KC_P9, KC_PMNS, \
    KC_LGUI,   KC_LALT,    KC_LCTL,     KC_LSFT,   KC_PENT, KC_PAST,  KC_P4,   KC_P5,   KC_P6, KC_PPLS, \
    LCTL(KC_Y),LCTL(KC_X), LCTL(KC_C),  LCTL(KC_V),KC_BSPC, KC_P0,    KC_P1,   KC_P2,   KC_P3, KC_PDOT, \
    XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______,    KC_PENT, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

/** \brief Numpad Layer, alternative left handed version */
#define LAYOUT_LAYER_NUMPAD_A                                                                      \
    KC_PSLS,  KC_P7,   KC_P8,   KC_P9, KC_PMNS,    XXXXXXX,  XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, \
    KC_PAST,  KC_P4,   KC_P5,   KC_P6, KC_PPLS,    XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,    \
    KC_P0,    KC_P1,   KC_P2,   KC_P3, KC_PDOT,    XXXXXXX,  XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______,   KC_PENT, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX


/** \brief Pointing Layer for trackball controls and mouse click and misc */
#define LAYOUT_LAYER_POINTER                                                                       \
    SCRL_DVI,CPI_D100,KBC_SAVE,KBC_RST,  QK_BOOT, QK_BOOT, KBC_RST, KBC_SAVE, CPI_D100, SCRL_DVI, \
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, SSNP_VRT, SSNP_VRT, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI,      \
    SCRL_DVD, CPI_I100, SCRL_MO, _______, SSNP_FRE, SSNP_FRE, _______, SCRL_MO, CPI_I100, SCRL_DVD,      \
    XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN2, KC_BTN1, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

/** \brief Symbols layer - mostly for Hungarian special characters with AltGr */
// Custom version
// ~%|+< >=$§^
// '"\([ ])/*;
// !#&@{ }`°´˝
#define LAYOUT_LAYER_SYM                                                               \
    RALT(KC_1), LSFT(KC_5), RALT(KC_W), LSFT(KC_3), RALT(KC_M), RALT(KC_DOT), LSFT(KC_7), RALT(KC_SCLN), LSFT(KC_GRV), RALT(KC_3), \
    LSFT(KC_1), LSFT(KC_2), RALT(KC_Q), LSFT(KC_8), RALT(KC_F), RALT(KC_G), LSFT(KC_9), LSFT(KC_6), RALT(KC_SLASH), RALT(KC_COMMA), \
    LSFT(KC_4), RALT(KC_X), RALT(KC_C), RALT(KC_V), RALT(KC_B), RALT(KC_N), RALT(KC_7), RALT(KC_5), RALT(KC_9), RALT(KC_0), \
    XXXXXXX, XXXXXXX, XXXXXXX, SPC_NAV, ENT_MOU, KC_SPC, TAB_FUN, ESC_NUM, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

#define LAYOUT_LAYER_SYM_A                                                             \
    RALT(KC_1), LSFT(KC_5), RALT(KC_W), LSFT(KC_3), RALT(KC_M), RALT(KC_DOT), LSFT(KC_7), RALT(KC_SCLN), LSFT(KC_GRV), RALT(KC_3), \
    LSFT(KC_1), LSFT(KC_2), RALT(KC_Q), LSFT(KC_8), RALT(KC_F), RALT(KC_G), LSFT(KC_9), LSFT(KC_6), RALT(KC_SLASH), RALT(KC_COMMA), \
    LSFT(KC_4), RALT(KC_X), RALT(KC_C), RALT(KC_V), RALT(KC_B), RALT(KC_N), RALT(KC_7), RALT(KC_5), RALT(KC_9), RALT(KC_0), \
    XXXXXXX, XXXXXXX, XXXXXXX, TAB_FUN_A, ESC_NUM_A, KC_SPC, ENT_MOU_A, SPC_NAV_A, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX


/** \brief Mouse layer - traditional keyboard mouse controls and media controls */
#define LAYOUT_LAYER_MOUSE                                                                    \
    KC_WH_U, KC_WH_L, KC_MS_U, KC_WH_R, XXXXXXX, MS_ACL2, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, \
    KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN2, MS_ACL1, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, \
    KC_WH_D, KC_WBAK, KC_WREF, KC_WFWD, KC_BTN3, MS_ACL0, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

/** \brief Mouse layer - traditional keyboard mouse controls and media controls, alternative right handed version */
#define LAYOUT_LAYER_MOUSE_A                                                                  \
    XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, MS_ACL2, XXXXXXX, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U, \
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, MS_ACL1, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1, \
    XXXXXXX, KC_WBAK, KC_WREF, KC_WFWD, MS_ACL0, KC_BTN3, KC_WBAK, KC_WREF, KC_WFWD, KC_WH_D, \
    XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

/** \brief Navigation layer. */
#define LAYOUT_LAYER_NAVIGATION                                                               \
    KC_PGUP,  KC_HOME, KC_UP,   KC_END,  KC_DEL,  KC_CAPS, KC_PSCR, KC_SCRL, KC_PAUS, KC_NUM, \
    KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT,  KC_ENT,  CM_TOGG, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI,\
    KC_PGDN, KC_WBAK, KC_WREF, KC_WFWD,  KC_INS,  DF_GAME, DF_BASE,   DF_NP,  DF_NAV, KC_APP, \
    XXXXXXX, XXXXXXX, XXXXXXX, KC_TAB,  KC_ESC,  KC_SPC,   _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

/** \brief Navigation layer, alternative right handed version */
#define LAYOUT_LAYER_NAVIGATION_A                                                            \
    KC_CAPS, KC_PSCR, KC_SCRL, KC_PAUS,  KC_NUM,  KC_DEL, KC_HOME, KC_UP,   KC_END, KC_PGUP, \
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,  CM_TOGG, KC_ENT, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC,\
    KC_APP,  DF_NAV, DF_NP,    DF_BASE,  DF_GAME, KC_INS, KC_WBAK, KC_WREF, KC_WFWD, KC_PGDN,\
    XXXXXXX, XXXXXXX, XXXXXXX, KC_TAB,  KC_ESC,  KC_SPC, KC_ENT, SPC_NAV, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX


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

#define LAYOUT_wrapper(...) LAYOUT_universal(__VA_ARGS__)
// clang-format on

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_wrapper(
    POINTER_MOD(HOME_ROW_MOD_GACS(LAYOUT_LAYER_BASE))
  ),
  [LAYER_GAME] = LAYOUT_wrapper(LAYOUT_LAYER_GAME),
  [LAYER_FUN_NUM] = LAYOUT_wrapper(LAYOUT_LAYER_FUN_NUM),
  [LAYER_FUN_A] = LAYOUT_wrapper(LAYOUT_LAYER_FUN_A),
  [LAYER_SYM] = LAYOUT_wrapper(LAYOUT_LAYER_SYM),
  [LAYER_SYM_A] = LAYOUT_wrapper(LAYOUT_LAYER_SYM_A),
  [LAYER_NUMPAD_A] = LAYOUT_wrapper(LAYOUT_LAYER_NUMPAD_A),
  [LAYER_NUMPAD] = LAYOUT_wrapper(LAYOUT_LAYER_NUMPAD),
  [LAYER_MOUSE_A] = LAYOUT_wrapper(LAYOUT_LAYER_MOUSE_A),
  [LAYER_MOUSE] = LAYOUT_wrapper(LAYOUT_LAYER_MOUSE),
  [LAYER_NAVIGATION_A] = LAYOUT_wrapper(LAYOUT_LAYER_NAVIGATION_A),
  [LAYER_NAVIGATION] = LAYOUT_wrapper(LAYOUT_LAYER_NAVIGATION),
  [LAYER_POINTER] = LAYOUT_wrapper(LAYOUT_LAYER_POINTER),
};

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

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif

#    ifdef AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    keyball_set_sniping_mode(layer_state_cmp(state, AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif
