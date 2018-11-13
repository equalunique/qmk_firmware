/* Copyright 2018 Evan J. Rowley (rowley.evan@gmail.com)
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
#include "xd75.h"
#include "backlight.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum my_layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _NUM,
  _FUN,
  _ARROWS1,
  _ARROWS2,
  _MOUSE1,
  _MOUSE2
};

enum my_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  NUM,
  FUN,
  ARROWS1,
  ARROWS2,
  MOUSE1,
  MOUSE2,
  BACKLIT,
  EXT_FUN,
  EXT_AR2,
  EXT_MS2
};

// Fillers to make layering more clear.
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Additional keycodes.
#define NUM TT(_NUM)
#define FUN TO(_FUN)
#define ARROWS1 TT(_ARROWS1)
#define ARROWS2 TO(_ARROWS2)
#define MOUSE1 TT(_MOUSE1)
#define MOUSE2 TO(_MOUSE2)
#define LSFTOSM OSM(MOD_LSFT)
#define RSFTOSM OSM(MOD_RSFT)
#define LCTLOSM OSM(MOD_LCTL)
#define RCTLOSM OSM(MOD_RCTL)
#define LALTOSM OSM(MOD_LALT)
#define RALTOSM OSM(MOD_RALT)
#define LGUIOSM OSM(MOD_LGUI)

//// Settings for One Shot Mods (i.e, OSM()).
//#define IGNORE_MOD_TAP_INTERRUPT
//#define TAPPING_TERM 300
//#define ONESHOT_TAP_TOGGLE 3  /* Tapping this number of times holds the key until tapped this number of times again. */
//#define ONESHOT_TIMEOUT 3000  /* Time (in ms) before the one shot key is released */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_QWERTY] = { /* QWERTY */
  { XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX, XXXXXXX, XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX  },
  { KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX, XXXXXXX, XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC  },
  { KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    XXXXXXX, XXXXXXX, XXXXXXX, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT   },
  { ARROWS1, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX, XXXXXXX, XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MOUSE1   },
  { XXXXXXX, XXXXXXX, XXXXXXX, LGUIOSM, LSFTOSM, NUM,     XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC,  LCTLOSM, LALTOSM, XXXXXXX, XXXXXXX, XXXXXXX  }
 },

 [_COLEMAK] = { /* COLEMAK */
  { XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX, XXXXXXX, XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX  },
  { KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    XXXXXXX, XXXXXXX, XXXXXXX, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC  },
  { KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    XXXXXXX, XXXXXXX, XXXXXXX, KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT   },
  { ARROWS1, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX, XXXXXXX, XXXXXXX, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MOUSE1   },
  { XXXXXXX, XXXXXXX, XXXXXXX, LGUIOSM, LSFTOSM, NUM,     XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC,  LCTLOSM, LALTOSM, XXXXXXX, XXXXXXX, XXXXXXX  }
 },

 [_DVORAK] = { /* DVORAK */
  { XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX, XXXXXXX, XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX  },
  { KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    XXXXXXX, XXXXXXX, XXXXXXX, KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC  },
  { KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    XXXXXXX, XXXXXXX, XXXXXXX, KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT   },
  { ARROWS1, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    XXXXXXX, XXXXXXX, XXXXXXX, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    MOUSE1   },
  { XXXXXXX, XXXXXXX, XXXXXXX, LGUIOSM, LSFTOSM, NUM,     XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC,  LCTLOSM, LALTOSM, XXXXXXX, XXXXXXX, XXXXXXX  }
 },

 [_NUM] = { /* NUMBERS (& SYMBOLS) */
  { XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX  },
  { XXXXXXX, KC_QUOT, KC_TILD, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS, KC_EQL,  XXXXXXX  },
  { KC_LBRC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_RBRC  },
  { XXXXXXX, KC_BSLS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLSH, XXXXXXX  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, FUN,     _______, _______, _______, _______, _______  }
 },

 [_FUN] = { /* FUNCTION */
  { XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX  },
  { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,   _______, _______, _______, BACKLIT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  },
  { KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, _______, _______, KC_F7,   KC_F8,   KC_F9,  KC_F10,   KC_F11,  KC_F12   },
  { XXXXXXX, COLEMAK, QWERTY,  DVORAK,  _______, BACKLIT, _______, _______, _______, XXXXXXX, KC_PAUS, KC_PSCR, KC_SLCK, XXXXXXX, XXXXXXX  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, EXT_FUN, _______, _______, _______, _______, _______  }
 },

 [_ARROWS1] = { /* ARROWS1 */
  { XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX  },
  { XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  },
  { XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  },
  { _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ARROWS2  },
  { _______, _______, _______, _______, _______, XXXXXXX, _______, _______, _______, XXXXXXX, _______, _______, _______, _______, _______  }
 },

 [_ARROWS2] = { /* ARROWS2 */
  { XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX  },
  { XXXXXXX, XXXXXXX, XXXXXXX, KC_PGUP, XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  },
  { XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN, KC_END,  XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  },
  { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, EXT_AR2  },
  { _______, _______, _______, _______, _______, XXXXXXX, _______, _______, _______, XXXXXXX, _______, _______, _______, _______, _______  }
 },

 [_MOUSE1] = { /* MOUSE1 */
  { XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX  },
  { XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  },
  { XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, _______, _______, _______, XXXXXXX, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, KC_BTN5  },
  { MOUSE2,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______  },
  { _______, _______, _______, _______, _______, XXXXXXX, _______, _______, _______, XXXXXXX, _______, _______, _______, _______, _______  }
 },

 [_MOUSE2] = { /* MOUSE2 */
  { XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX  },
  { XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_U, XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX, KC_MNXT, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX  },
  { XXXXXXX, XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_R, XXXXXXX, _______, _______, _______, XXXXXXX, KC_MPLY, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX  },
  { EXT_MS2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX, KC_MPRV, KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX  },
  { _______, _______, _______, _______, _______, XXXXXXX, _______, _______, _______, XXXXXXX, _______, _______, _______, _______, _______  }
 },

/*
 [_RAISE] = {

  { XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX  },
  { XXXXXXX, KC_EXLM, KC_AT,   KC_UP,   KC_LCBR, KC_RCBR, _______, _______, _______, KC_CIRC, KC_7,    KC_8,    KC_9,    KC_ASTR, XXXXXXX  },
  { _______, KC_HASH, KC_LEFT, KC_DOWN, KC_RGHT, KC_DLR,  _______, _______, _______, KC_PERC, KC_4,    KC_5,    KC_6,    KC_PLUS, _______  },
  { KC_PIPE, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_AMPR, _______, _______, _______, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_TILD, KC_BSLS  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DOT,  KC_0,    KC_EQL,  _______  }
 },

 [_LOWER] = {
  { XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX  },
  { XXXXXXX, XXXXXXX, KC_PAUS, KC_PSCR, KC_SLCK, XXXXXXX, _______, _______, _______, KC_WH_L, KC_PGUP, KC_MS_U, KC_HOME, KC_WH_U, XXXXXXX  },
  { _______, KC_BTN4, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN5, _______, _______, _______, KC_WH_R, KC_MS_L, XXXXXXX, KC_MS_R, KC_WH_D, _______  },
  { _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX, KC_PGDN, KC_MS_D, KC_END,  LCTLOSM, _______  },
  { _______, _______, _______, _______, _______, XXXXXXX, _______, _______, _______, XXXXXXX, _______, KC_INS,  KC_DEL,  _______, _______  }
 },

 [_FUNCT] = {
  { XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX  },
  { XXXXXXX, QWERTY,  XXXXXXX, KC_VOLU, KC_MNXT, RESET,   _______, _______, _______, XXXXXXX, KC_F7,   KC_F8,  KC_F9,    KC_F10,  XXXXXXX  },
  { _______, DVORAK,  KC_MUTE, KC_MSTP, KC_MPLY, XXXXXXX, _______, _______, _______, XXXXXXX, KC_F4,   KC_F5,  KC_F6,    KC_F11,  _______  },
  { _______, COLEMAK, XXXXXXX, KC_VOLD, KC_MPRV, BACKLIT, _______, _______, _______, XXXXXXX, KC_F1,   KC_F2,  KC_F3,    KC_F12,  _______  },
  { _______, _______, _______, _______, _______, XXXXXXX, _______, _______, _______, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, _______  }
 }
*/

};

/*
uint32_t layer_state_set_user(uint32_t state) {
  state = update_tri_layer_state(state, _LOWER, _RAISE, _FUNCT);
  return state;
}
*/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case EXT_FUN:
      if (record->event.pressed) {
	 layer_off(_FUN);
      }
      return false;
      break;
    case EXT_AR2:
      if (record->event.pressed) {
         layer_off(_ARROWS2);
      }
      return false;
      break;
    case EXT_MS2:
      if (record->event.pressed) {
	 layer_off(_MOUSE2);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        PORTE &= ~(1<<6);
      } else {
        unregister_code(KC_RSFT);
        PORTE |= (1<<6);
      }
      return false;
      break;
  }
  return true;
}

/*
const uint16_t PROGMEM fn_actions[] = {

};
*/
/*
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
//            register_code(KC_RSFT);
//            #ifdef BACKLIGHT_ENABLE
//              backlight_step();
//            #endif
          } else {
//            unregister_code(KC_RSFT);
          }
          break;
      }
    return MACRO_NONE;
};
*/

