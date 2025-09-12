/* Copyright 2015-2017 Jack Humbert
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
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
// #define _QWERTY 0
// #define _GAME 3
// #define _LOWER 4
// #define _RAISE 5
// #define _ADJUST 16

enum custom_layers {
  _QWERTY,
  // _GAME,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  // GAME,
  LOWER,
  RAISE,
  ADJUST,

  PTR_ARROW,
  MAKE_KEYBOARD
};

#define XXXXXXX KC_NO
#define _______ KC_TRNS

#define CTL_ESC CTL_T(KC_ESC)  // Tap for Escape, hold for Control
#define HPR_TAB ALL_T(KC_TAB)  // Tap for Tab, hold for Hyper (Super+Ctrl+Alt+Shift)
#define MEH_GRV MEH_T(KC_GRV)  // Tap for Backtick, hold for Meh (Ctrl+Alt+Shift)
#define SFT_BSP SFT_T(KC_BSPC) // Tap for Backspace, hold for Shift
#define SFT_ENT SFT_T(KC_ENT)  // Tap for Enter, hold for Shift
#define SFT_SPC SFT_T(KC_SPC)  // Tap for Space, hold for Shift
#define UMLAUT  RALT(KC_U)     // Combine Alt and U

// Note: For some reason KC_LGUI is left alt for some reason...
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,--------------------------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |      |      |      |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |      |      |      |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |      |      |      |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Meh  | Alt  | GUI  |Lower |Space |      |      |      | Tab  |Raise | GUI  |AltGr | Umlt | Ctrl |
 * `--------------------------------------------------------------------------------------------------------'
 */

[_QWERTY] = {
  { _______, KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_KP_ENTER,  KC_KP_ASTERISK,   KC_KP_SLASH,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL},
  {  KC_TAB, KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_KP_7,      KC_KP_8,          KC_KP_9,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC },
  { KC_ESC, KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_KP_4,      KC_KP_5,          KC_KP_6,        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT },
  { KC_LSFT, KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_KP_1,      KC_KP_2,          KC_KP_3,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT },
  { KC_LCTL, MEH_GRV,  KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_KP_0,      KC_KP_DOT,        KC_NUM_LOCK,    SFT_BSP, RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  },
},

// [_GAME] = {
//   { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______,_______},
//   { KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, _______,_______,_______},
//   { CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, _______,_______,_______},
//   { KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT, _______,_______,_______},
//   { KC_LCTL, _______, _______, _______, LOWER,   KC_SPC,  SFT_BSP, RAISE,   KC_RGUI, KC_RALT, KC_RCTL, _______,  _______,_______,_______},
// },

/* Lower
 * ,--------------------------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |      |      |      |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |      |      |      |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |      |      |      |  F12 | MS L | MS D |MS U  | MS R |MS Btn|
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `--------------------------------------------------------------------------------------------------------'
  */
[_LOWER] = {
  { _______, _______, _______, _______, _______, _______, _______,   _______, _______,      _______, _______, PTR_ARROW, KC_PAUSE, KC_INS, KC_PSCR },
  { KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_INSERT, KC_HOME, KC_PAGE_UP,   KC_CIRC, KC_AMPR, KC_ASTR,   KC_LPRN, KC_RPRN, KC_BSPC },
  { KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_DELETE, KC_END,  KC_PAGE_DOWN, KC_F6,   KC_UNDS, KC_PLUS,   KC_LCBR, KC_RCBR, KC_PIPE },
  { _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______,   _______, _______,      KC_F12,  KC_MS_L, KC_MS_D,   KC_MS_U, KC_MS_R, KC_BTN1 },
  { _______, _______, _______, _______, _______, _______, _______,   _______, _______,      _______, _______, KC_MNXT,   KC_VOLD, KC_VOLU, KC_MPLY }
},

/* Raise
 * ,--------------------------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |      |      |      |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |      |      |      |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |      |      |      |  F12 | Left | Down |  Up  | Rght |MS_BN2|
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `--------------------------------------------------------------------------------------------------------'
 */
[_RAISE] = {
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC },
  { KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, _______, KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS },
  { _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______, _______, _______, KC_F12,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BTN2 },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY }
},


/* Adjust (Lower + Raise)
 * ,--------------------------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|      |      |      |AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|      |      |      |MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * `--------------------------------------------------------------------------------------------------------'
 */
[_ADJUST] =  {
  { _______, _______,       _______, _______, _______, _______, RGB_TOG, RGB_MOD, BL_TOGG, _______, _______, _______, _______, _______, _______ },
  { _______, QK_BOOT, MAKE_KEYBOARD, _______, _______, _______, RGB_HUI, RGB_HUD, BL_STEP, _______, _______, _______, _______, _______, KC_DEL  },
  { _______, _______,       _______, _______, _______, _______, RGB_SAI, RGB_SAD, BL_UP,   _______, _______, _______, _______, _______, _______ },
  { _______, _______,       _______, _______, _______, _______, RGB_VAI, RGB_VAD, BL_DOWN, _______, _______, _______, _______, _______, _______ },
  { _______, _______,       _______, _______, _______, _______, _______, _______, BL_BRTG, _______, _______, _______, _______, _______, _______ },
},

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case BL_TOGG:
      if (record->event.pressed) {
        // keycaps_led_toggle();
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
      case ADJUST:
        if(record->event.pressed){
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
        break;
      case PTR_ARROW:
        if(record->event.pressed){
          SEND_STRING("->");
        }
        return false;
        break;
      case MAKE_KEYBOARD:
        if(record->event.pressed){
          SEND_STRING("make xd75:jonathansty");
        }
        return false;
        break;
  }
  return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t* record)
{
  switch(keycode) {
    case SFT_ENT:
      return 95;
    default:
      return TAPPING_TERM;
  }
}
