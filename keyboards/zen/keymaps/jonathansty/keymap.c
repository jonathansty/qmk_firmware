#include "zen.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "jonathansty.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _RAISE 1
#define _LOWER 2
#define _ADJUST 3


enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  RAISE,
  LOWER,
  ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------.             .-----------------------------------------.
 * | GESC |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |   \  |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |CAPS(NAV)|A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------..-----+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |RGBTOG| NAV  |Space |Delete||Enter|Space |  NAV |   -  |   =  | PGUP | PGDN |
 * `------------------------------------------------''-----------------------------------------------'
 */
[_QWERTY] = KEYMAP( \
  KC_CAPS, KC_1,    KC_2,    KC_3,    KC_4,     KC_5,                    KC_6,     KC_7,     KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,                    KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    KC_BSLS, \
  KC_GESC, KC_A,    KC_S,    KC_D,    KC_F,     KC_G,                    KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,                    KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT, \
  KC_LCTL, KC_LGUI, KC_LALT, RGB_TOG, LOWER, KC_SPC, _______,  _______,  KC_BSPC,  RAISE,    KC_MINS, KC_EQL,  KC_PGUP, KC_PGDN  \
),

/* NAV
 * ,-----------------------------------------.             .-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |  F7  |  F8  |  F9  |  F10 |  F11 | F12  |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |RGBSAI|RGBVAI|RGBSAD| RESET|  [   |             |   ]  | Pgup |  Up  | Pgdn |Insert| Home |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |RGBHUD|RGBVAD|RGBHUI|      |      |             |      | Left | Down | Right|Delete| End  |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |Shift |      |      |      |      |      |             | NKRO |      |      | Pause| Back | Next |
 * |------+------+------+------+------+------+------..-----+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |RGBMOD|      |      |      ||     |      |      |      | Mute | VOLUP| VOLDN|
 * `------------------------------------------------''-----------------------------------------------'
 */
[_LOWER] = KEYMAP( \
  _______, _______, _______, _______, _______, _______,                   _______,_______, _______,_______,_______,_______, \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR,   KC_LPRN, KC_RPRN, KC_BSPC,\
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_UNDS, KC_PLUS,   KC_LCBR, KC_RCBR, KC_PIPE,\
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,                    KC_F12,  KC_MS_L, KC_MS_D,   KC_MS_U, KC_MS_R, KC_BTN1,\
  _______, _______, _______, _______, _______, _______, KC_TRNS, KC_TRNS, _______,_______,  KC_MNXT,   KC_VOLD, KC_VOLU, KC_MPLY \
),

[_RAISE] = KEYMAP( \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______,_______,_______,_______, \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,                    KC_F12,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BTN2,
  _______, _______, _______, _______, _______, _______, KC_TRNS, KC_TRNS, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

[_ADJUST] = KEYMAP( \
  _______, _______, RGB_TOG, RGB_MOD, BL_TOGG, _______,                   _______,_______, _______,_______,_______,_______, \
  _______, RESET,   RGB_HUI, RGB_HUD, BL_STEP, _______,                   _______,_______, _______,_______,_______,_______, \
  _______, _______, RGB_SAI, RGB_SAD, BL_INC, _______,                   _______,_______, _______,_______,_______,_______, \
  _______, _______, RGB_VAI, RGB_VAD, BL_DEC, _______,                   _______,_______, _______,_______,_______,_______, \
  _______, _______, _______, _______, _______, _______, KC_TRNS, KC_TRNS, _______,_______, _______,_______,_______,_______ \
)

};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        layer_off(_RAISE);
        layer_off(_LOWER);

        set_single_persistent_default_layer(_QWERTY);
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
  }
  return true;
}
