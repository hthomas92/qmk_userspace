#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

enum keymap_layers {
    LAYER_BASE = 0,
    LAYER_GAME = 1,
    LAYER_FUN_NUM = 2,
    LAYER_SYM = 3,
    LAYER_NUMPAD = 4,
    LAYER_MOUSE = 5,
    LAYER_NAVIGATION = 6,
};


#define TAB_FUN LT(LAYER_FUN_NUM, KC_TAB)
#define ESC_NUM LT(LAYER_NUMPAD, KC_ESC)
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

// Combos for Hungarian accentuated characters, layout 1
// Hungarian characters centered around the home row, in the inner 3 columns
const uint16_t PROGMEM combo_ER[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM combo_UI[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo_SD[] = {LALT_T(KC_S), LCTL_T(KC_D), COMBO_END};
const uint16_t PROGMEM combo_DF[] = {LCTL_T(KC_D), LSFT_T(KC_F), COMBO_END};
const uint16_t PROGMEM combo_JK[] = {RSFT_T(KC_J), RCTL_T(KC_K), COMBO_END};
const uint16_t PROGMEM combo_KL[] = {RCTL_T(KC_K), LALT_T(KC_L), COMBO_END};
const uint16_t PROGMEM combo_CV[] = {SM_C, KC_V, COMBO_END};
const uint16_t PROGMEM combo_M_COMM[] = {KC_M, SM_COMM, COMBO_END};
const uint16_t PROGMEM combo_LeftThumbs[] = {TAB_FUN, ESC_NUM, COMBO_END};
const uint16_t PROGMEM combo_BootLoader[] = {KC_CAPS, KC_PSCR, COMBO_END};
const uint16_t PROGMEM combo_Clear[] = {KC_PSCR, KC_SCRL, COMBO_END};
const uint16_t PROGMEM combo_Backlight[] = {KC_SCRL, KC_PAUS, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_ER, KC_EQUAL), // ó
    COMBO(combo_UI, KC_RBRC), // ú
    COMBO(combo_SD, KC_NUBS), // í
    COMBO(combo_DF, KC_0), // ö
    COMBO(combo_JK, KC_MINS), // ü
    COMBO(combo_KL, KC_QUOT), // á
    COMBO(combo_CV, KC_LBRC), // ő
    COMBO(combo_M_COMM, KC_NUHS), // ű
    COMBO(combo_LeftThumbs, KC_SPC),
    COMBO(combo_BootLoader, QK_BOOT),
    COMBO(combo_Clear, EE_CLR),
    COMBO(combo_Backlight, RM_TOGG),
};

// clang-format off
/** \brief QWERTY layout (3 rows, 10 columns). */
#define LAYOUT_LAYER_BASE                                                                     \
       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, \
       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, \
       SM_Z,    KC_X,    SM_C,    KC_V,    KC_B,    KC_N,    KC_M, SM_COMM,  KC_DOT, SM_SLSH, \
                      TAB_FUN, ESC_NUM, ENT_MOU, SPC_NAV, \
     KC_MPLY, _______, _______, _______, _______, KC_MPLY, _______, _______, _______, _______

/** \brief QWERTY layout (3 rows, 10 columns) without Home row mods */
#define LAYOUT_LAYER_GAME                                                                     \
       KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, \
       KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, \
       KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, \
                      KC_SPC, ESC_FUN, ENT_MOU, SPC_NAV, \
     KC_MPLY, _______, _______, _______, _______, KC_MPLY, _______, _______, _______, _______

/** \brief Numbers and Function layer. */
#define LAYOUT_LAYER_FUN_NUM                                                                 \
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,   KC_7,    KC_8,    KC_9,    KC_GRV, \
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,  KC_F11, KC_F12, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, \
    KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,  KC_F6,  KC_F7,   KC_F8,   KC_F9,   KC_F10, \
                      _______, _______, KC_RALT, _______, \
     KC_MUTE, _______, _______, _______, _______, KC_MUTE, _______, _______, _______, _______

/** \brief Numpad Layer */
#define LAYOUT_LAYER_NUMPAD                                                                    \
    KC_NUM,LALT(KC_F4),LSFT(KC_TAB), KC_TAB,    KC_DEL,  KC_PSLS,  KC_P7,   KC_P8,   KC_P9, KC_PMNS, \
    KC_LGUI,   KC_LALT,   KC_LCTL,   KC_LSFT,   KC_PENT, KC_PAST,  KC_P4,   KC_P5,   KC_P6, KC_PPLS, \
    LCTL(KC_Y),LCTL(KC_X),LCTL(KC_C),LCTL(KC_V),KC_BSPC, KC_P0,    KC_P1,   KC_P2,   KC_P3, KC_PDOT, \
                      _______, _______,    KC_PENT, _______, \
     KC_MUTE, _______, _______, _______, _______, KC_MUTE, _______, _______, _______, _______

/** \brief Symbols layer - mostly for Hungarian special characters with AltGr */
// Classic version with SFT numbers top row
// '"+!% /=()§
// \|^<[ ]>$*;
// ~#&@{ }`°´˝
/*
#define LAYOUT_LAYER_SYM                                                               \
    LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_GRV), \
    RALT(KC_Q), RALT(KC_W), RALT(KC_3), RALT(KC_M), RALT(KC_F), RALT(KC_G), RALT(KC_DOT), RALT(KC_SCLN), RALT(KC_SLASH), RALT(KC_COMMA), \
    RALT(KC_1), RALT(KC_X), RALT(KC_C), RALT(KC_V), RALT(KC_B), RALT(KC_N), RALT(KC_7), RALT(KC_5), RALT(KC_9), RALT(KC_0), \
                      _______, _______,  _______, _______, \
     KC_MUTE, _______, _______, _______, _______, KC_MUTE, _______, _______, _______, _______
*/

// Custom version
// ~%|+< >=$§^
// '"\([ ])/*;
// !#&@{ }`°´˝
#define LAYOUT_LAYER_SYM                                                               \
    RALT(KC_1), LSFT(KC_5), RALT(KC_W), LSFT(KC_3), RALT(KC_M), RALT(KC_DOT), LSFT(KC_7), RALT(KC_SCLN), LSFT(KC_GRV), RALT(KC_3), \
    LSFT(KC_1), LSFT(KC_2), RALT(KC_Q), LSFT(KC_8), RALT(KC_F), RALT(KC_G), LSFT(KC_9), LSFT(KC_6), RALT(KC_SLASH), RALT(KC_COMMA), \
    LSFT(KC_4), RALT(KC_X), RALT(KC_C), RALT(KC_V), RALT(KC_B), RALT(KC_N), RALT(KC_7), RALT(KC_5), RALT(KC_9), RALT(KC_0), \
                       SPC_NAV, ENT_MOU,  TAB_FUN, ESC_NUM, \
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______


/** \brief Mouse layer - traditional keyboard mouse controls and media controls */
#define LAYOUT_LAYER_MOUSE                                                               \
    MS_WHLU, MS_WHLL, MS_UP, MS_WHLR, XXXXXXX, MS_ACL2, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, \
    MS_BTN1, MS_LEFT, MS_DOWN, MS_RGHT, MS_BTN2, MS_ACL1, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, \
    MS_WHLD, KC_WBAK, KC_WREF, KC_WFWD, MS_BTN3, MS_ACL0, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, \
                      _______, _______, _______, _______, \
     KC_MUTE, _______, _______, _______, _______, KC_MUTE, _______, _______, _______, _______

/** \brief Navigation layer. */
#define LAYOUT_LAYER_NAVIGATION                                                                  \
    KC_PGUP,  KC_HOME, KC_UP,   KC_END,  KC_DEL,    KC_CAPS, KC_PSCR, KC_SCRL, KC_PAUS, KC_NUM, \
    KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT,  KC_ENT,    CM_TOGG, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, \
    KC_PGDN, KC_WBAK, KC_WREF, KC_WFWD,  KC_INS,    DF_GAME, DF_BASE,   DF_NP,  DF_NAV, KC_APP, \
                      KC_TAB,  KC_ESC,  _______, _______, \
     KC_MUTE, _______, _______, _______, _______, KC_MUTE, _______, _______, _______, _______

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

#define LAYOUT_wrapper(...) LAYOUT_ferris_hlc(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_wrapper(
    HOME_ROW_MOD_GACS(LAYOUT_LAYER_BASE)
  ),
  [LAYER_GAME] = LAYOUT_wrapper(LAYOUT_LAYER_GAME),
  [LAYER_FUN_NUM] = LAYOUT_wrapper(LAYOUT_LAYER_FUN_NUM),
  [LAYER_SYM] = LAYOUT_wrapper(LAYOUT_LAYER_SYM),
  [LAYER_NUMPAD] = LAYOUT_wrapper(LAYOUT_LAYER_NUMPAD),
  [LAYER_MOUSE] = LAYOUT_wrapper(LAYOUT_LAYER_MOUSE),
  [LAYER_NAVIGATION] = LAYOUT_wrapper(LAYOUT_LAYER_NAVIGATION),
};
// clang-format on

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_MPRV, KC_MNXT)},
    [1] = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_MPRV, KC_MNXT)},
    [2] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [3] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [4] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [5] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [6] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)}
};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

// Turn off chordal hold for the thumb button layer taps
bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                      uint16_t other_keycode, keyrecord_t* other_record) {
    // Exceptionally allow some one-handed chords for hotkeys.
    switch (tap_hold_keycode) {
        case TAB_FUN:
        case ESC_NUM:
        case ESC_FUN:
        case ENT_MOU:
        case SPC_NAV:
            return true;
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

#ifdef OTHER_KEYMAP_C
#    include OTHER_KEYMAP_C
#endif // OTHER_KEYMAP_C

