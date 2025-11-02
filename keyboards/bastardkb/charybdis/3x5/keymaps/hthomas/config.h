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
#pragma once

#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY

#define CHORDAL_HOLD

#define HOLD_ON_OTHER_KEY_PRESS
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

#define TAPPING_TERM 200
#define QUICK_TAP_TERM 150
#define COMBO_TERM 40
#define FLOW_TAP_TERM 40

#define COMBO_MUST_TAP_PER_COMBO

//#define MK_COMBINED
//#define MOUSEKEY_DELAY	        150
//#define MOUSEKEY_INTERVAL   	16
//#define MOUSEKEY_FRICTION   	24
//#define MOUSEKEY_MOVE_DELTA	    1
//#define MOUSEKEY_MAX_SPEED  	32
//#define MOUSEKEY_TIME_TO_MAX    32

#define MOUSEKEY_DELAY   	    15
#define MOUSEKEY_INTERVAL	    16
#define MOUSEKEY_MOVE_DELTA 	6
#define MOUSEKEY_MAX_SPEED  	10
#define MOUSEKEY_TIME_TO_MAX	30

#ifdef VIA_ENABLE
/* VIA configuration. */
#    define DYNAMIC_KEYMAP_LAYER_COUNT 8
#endif // VIA_ENABLE

#ifndef __arm__
/* Disable unused features. */
#    define NO_ACTION_ONESHOT
#endif // __arm__

/* Charybdis-specific features. */

#ifdef POINTING_DEVICE_ENABLE
// Automatically enable the pointer layer when moving the trackball.  See also:
// - `CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS`
// - `CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD`
// #define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#endif // POINTING_DEVICE_ENABLE
