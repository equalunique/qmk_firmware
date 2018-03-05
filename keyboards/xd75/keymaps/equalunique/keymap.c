/* Copyright 2017 Evan J. Rowley (rowley.evan@gmail.com)
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

// Fillers to make layering more clear
#define _______ KC_TRNS
#define ___T___ KC_TRNS
#define XXXXXXX KC_NO

// Layer shorthand
#define _DV 0
#define _QW 1
#define _CM 2
#define _A1 3
#define _A2 4
#define _FN 5

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
                                                                                                                                  
/* QWERTY - MIT ENHANCED / GRID COMPATIBLE
 * .---------------------------------------------------------------------------------------------------------------------- 2u ------------.
 * | XXXXXX | 1      | 2      | 3      | 4      | 5      | XXXXXX | XXXXXX | XXXXXX | 6      | 7      | 8      | 9      | 0      | XXXXXX |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | XXXXXX | Q      | W      | E      | R      | T      | XXXXXX | XXXXXX | XXXXXX | Y      | U      | I      | O      | P      | XXXXXX |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | XXXXXX | A      | S      | D      | F      | G      | XXXXXX | XXXXXX | XXXXXX | H      | J      | K      | L      | ;      | XXXXXX |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | XXXXXX | Z      | X      | C      | V      | B      | RCTRL  | XXXXXX | RALT   | N      | M      | ,      | .      | /      | XXXXXX |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | XXXXXX | ESC    | TAB    | LGUI   | LSHIFT | BACKSP | LCTRL  | XXXXXX | LALT   | SPACE  | _XX    | -      | '      | ENTER  | XXXXXX |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */                                                                                                                               
	                                                                                                                          
 [_QW] = { /* QWERTY */                                                                                                           
  { XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX, XXXXXXX, XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX  },
  { XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX, XXXXXXX, XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX  },
  { XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    XXXXXXX, XXXXXXX, XXXXXXX, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, XXXXXXX  },
  { XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_RCTL, XXXXXXX, KC_RALT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX  },
  { XXXXXXX, KC_ESC,  KC_TAB,  KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, XXXXXXX, KC_LALT, KC_SPC,  MO(_A1), KC_MINS, KC_QUOT, KC_ENT,  XXXXXXX  },
 },                                                                                                                               
                                                                                                                                  
/* COLEMAK - MIT ENHANCED / GRID COMPATIBLE                                                                                       
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | XXXXXX | 1      | 2      | 3      | 4      | 5      | XXXXXX | XXXXXX | XXXXXX | 6      | 7      | 8      | 9      | 0      | XXXXXX |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | XXXXXX | Q      | W      | F      | P      | G      | XXXXXX | XXXXXX | XXXXXX | J      | L      | U      | Y      | ;      | XXXXXX |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | XXXXXX | A      | R      | S      | T      | D      | XXXXXX | XXXXXX | XXXXXX | H      | N      | E      | I      | O      | XXXXXX |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | XXXXXX | Z      | X      | C      | V      | B      | RCTRL  | XXXXXX | RALT   | K      | M      | ,      | .      | /      | XXXXXX |
 * |--------+--------+--------+--------+--------+- 2u ------------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | XXXXXX | ESC    | TAB    | LGUI   | LSHIFT | BACKSP | LCTRL  | XXXXXX | LALT   | SPACE  | _XX    | -      | '      | ENTER  | XXXXXX |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */                                                                                                                               
	                                                                                                                          
 [_CM] = { /* COLEMAK */                                                                                                          
  { XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX, XXXXXXX, XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX  },
  { XXXXXXX, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    XXXXXXX, XXXXXXX, XXXXXXX, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, XXXXXXX  },
  { XXXXXXX, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    XXXXXXX, XXXXXXX, XXXXXXX, KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    XXXXXXX  },
  { XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_RCTL, XXXXXXX, KC_RALT, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX  },
  { XXXXXXX, KC_ESC,  KC_TAB,  KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, XXXXXXX, KC_LALT, KC_SPC,  MO(_A1), KC_MINS, KC_QUOT, KC_ENT,  XXXXXXX  },
 },                                                                                                                               
	                                                                                                                          
/* DVORAK - MIT ENHANCED / GRID COMPATIBLE                                                                                        
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | XXXXXX | 1      | 2      | 3      | 4      | 5      | XXXXXX | XXXXXX | XXXXXX | 6      | 7      | 8      | 9      | 0      | XXXXXX |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | XXXXXX | '      | ,      | .      | P      | Y      | XXXXXX | XXXXXX | XXXXXX | F      | G      | C      | R      | L      | XXXXXX |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | XXXXXX | A      | O      | E      | U      | I      | XXXXXX | XXXXXX | XXXXXX | D      | H      | T      | N      | S      | XXXXXX |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | XXXXXX | ;      | Q      | J      | K      | X      | RCTRL  | XXXXXX | RALT   | B      | M      | W      | V      | Z      | XXXXXX |
 * |--------+--------+--------+--------+--------+- 2u ------------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | XXXXXX | ESC    | TAB    | LGUI   | LSHIFT | BACKSP | LCTRL  | XXXXXX | LALT   | SPACE  | _XX    | -      | /      | ENTER  | XXXXXX |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */                                                                                                                               
                                                                                                                                  
 [_DV] = { /* DVORAK */                                                                                                           
  { XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX, XXXXXXX, XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX  },
  { XXXXXXX, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    XXXXXXX, XXXXXXX, XXXXXXX, KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    XXXXXXX  },
  { XXXXXXX, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    XXXXXXX, XXXXXXX, XXXXXXX, KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    XXXXXXX  },
  { XXXXXXX, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_RCTL, XXXXXXX, KC_RALT, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    XXXXXXX  },
  { XXXXXXX, KC_ESC,  KC_TAB,  KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, XXXXXXX, KC_LALT, KC_SPC,  MO(_A1), KC_MINS, KC_SLSH, KC_ENT,  XXXXXXX  },
 },                                                                                                                               
                                                                                                                                  
/* ATREUS LAYER 1                                                                                                                        
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | RESET  | !      | @      | #      | $      | %      | XXXXXX | XXXXXX | XXXXXX | ^      | &      | *      | (      | )      | XXXXXX |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | XXXXXX | !      | @      | UP     | {      | }      | XXXXXX | XXXXXX | XXXXXX | PGUP   | 7      | 8      | 9      | *      | XXXXXX |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | XXXXXX | #      | LEFT   | DOWN   | RIGHT  | $      | XXXXXX | XXXXXX | XXXXXX | PGDN   | 4      | 5      | 6      | +      | XXXXXX |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | XXXXXX | [      | ]      | (      | )      | &      | RCTRL  | XXXXXX | RALT   | `      | 1      | 2      | 3      | \      | XXXXXX |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | XXXXXX | ESC    | INS    | LGUI   | LSHIFT | BACKSP | LCTRL  | XXXXXX | LALT   | SPACE  | _XX    | .      | 0      | =      | XXXXXX |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */                                                                                                                               
                                                                                                                                  
 [_A1] = { /* ATREUS LAYER 1 */                                                                                                          
  { RESET,   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXXXX, XXXXXXX, XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX  },
  { XXXXXXX, KC_EXLM, KC_AT,   KC_UP,   KC_LCBR, KC_RCBR, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGUP, KC_7,    KC_8,    KC_9,    KC_ASTR, XXXXXXX  },
  { XXXXXXX, KC_HASH, KC_LEFT, KC_DOWN, KC_RGHT, KC_DLR,  XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN, KC_4,    KC_5,    KC_6,    KC_PLUS, XXXXXXX  },
  { XXXXXXX, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_AMPR, KC_RCTL, XXXXXXX, KC_RALT, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, XXXXXXX  },
  { XXXXXXX, TO(_A2), KC_TAB,  KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, XXXXXXX, KC_LALT, KC_SPC,  KC_TRNS, KC_DOT,  KC_0,    KC_EQL,  XXXXXXX  },
 },                                                                                                                               
                                                                                                                                  
/* ATREUS LAYER 2                                                                                                                         
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | RESET  | !      | @      | #      | $      | %      | XXXXXX | XXXXXX | XXXXXX | ^      | &      | *      | (      | )      |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | XXXXXX | INS    | HOME   | UP     | END    | PGUP   | XXXXXX | XXXXXX | XXXXXX | UP     | F7     | F8     | F9     | F10    |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | XXXXXX | DEL    | LEFT   | DOWN   | RIGHT  | PGDN   | XXXXXX | XXXXXX | XXXXXX | DOWN   | F4     | F5     | F6     | F11    |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | XXXXXX |        | VOL+   |        |        |        | RCTRL  | XXXXXX | RALT   |        | F1     | F2     | F3     | F12    |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | XXXXXX |        | VOL-   | SUPER  | SHIFT  | BACKSP | LCTRL  | XXXXXX | LALT   | SPACE  |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */                                                                                                                               
                                                                                                                                  
 [_A2] = { /* ATREUS LAYER 2 */                                                                                                           
  { RESET,   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXXXX, XXXXXXX, XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX  },
  { XXXXXXX, KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX  },
  { XXXXXXX, KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX, KC_DOWN, KC_F4,   KC_F5,   KC_F6,   KC_F11,  XXXXXXX  },
  { XXXXXXX, XXXXXXX, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, KC_RCTL, XXXXXXX, KC_RALT, XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F12,  XXXXXXX  },
  { XXXXXXX, XXXXXXX, KC_VOLD, KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, XXXXXXX, KC_LALT, KC_SPC,  TO(_DV), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  },
 },                                                                                                                               
                                                                                                                                  
/* FUNCTION                                                                                                                       
 * .------------------------------------------------------------------------- 2u ---------------------------------------------------------.
 * | NUM LK | F1     | F2     | F3     | F4     | F5     | F11    | F12    | XXXXXX . F6     | F7     | F8     | F9     | F10    |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+--------|
 * | SCR LK | F13    | F14    | F15    | F16    | F17    | F23    | F24    | PAUSE  | F18    | F19    | F20    | F21    | F22    | PR SCR |
 * |--------+--------+--------+--------+--------+--------+--------+- 2u ------------+--------+--------+--------+--------+--------+--------|
 * | CAP LK | MS BT5 | MS BT4 | MS BT3 | MS BT2 | SLOW M |        | XXXXXX .        | FAST M | NEXT   | VOL+   | VOL-   | PLAY   | WHEEL+ |
 * |--------+--------+--------+--------+--------+--------+- 2u ---------------------+--------+--------+--------+--------+--------+--------|
 * | RGB TG | RGB MD | RGB HI | RGB HD | RGB SI | RGB SD | XXXXXX .        | MOUS U | RGB VI | RGB VD | BL TOG | BL INC | BL DEC | WHEEL- |
 * |--------+--------+--------+--------+--------+-- 2u --------------------+--------+--------+--------+--------+--------+--------+--------|
 * | RESET  |        | QWERTY | COLEMK | DVORAK | XXXXXX .        | MOUS L | MOUS D | MS BT1 |        |        |        |        | MOUS R |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */                                                                                                                               
                                                                                                                                  
 [_FN] = { /* FUNCTION */                                                                                                         
  { KC_NLCK, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,  KC_F12,  ___T___, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  ___T___  },
  { KC_SLCK, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F23,  KC_F24,  KC_PAUS, KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_PSCR  },
  { KC_CAPS, KC_BTN5, KC_BTN4, KC_BTN3, KC_BTN2, KC_ACL0, XXXXXXX, ___T___, ___T___, KC_ACL2, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, KC_WH_U  },
  { RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, ___T___, ___T___, KC_MS_U,RGB_VAI, RGB_VAD, BL_TOGG, BL_INC,  BL_DEC,   KC_WH_D  },
  { RESET  , XXXXXXX, DF(_QW), DF(_CM), DF(_DV), KC_BTN1, XXXXXXX, KC_MS_L, KC_MS_D, KC_BTN1, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_R  },
 },
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};
