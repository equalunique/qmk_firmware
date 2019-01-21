#include QMK_KEYBOARD_H
#include "atreus.h"
#include "action_layer.h"


/*
 * Atrix Layout, by Evan Rowley, Copyright 2018.
 *
 * WORK IN PROGRESS / NOT TESTED
 *
 * The purpose of this keymap is to provide an Atreus42-like experience on
 * different keyboards. In all cases except for derivatises of the Atreus
 * and HeliDox/Crkbd/Corne, there will be some unsued keys, and also often
 * outer mod column keys that duplicate the function of lower mod row keys.
 * While the layout certainly isn't optimal for most of these keyboards, the
 * layout is optimal for typists who believe the Atreus42's compact layout
 * is superior. A main differnce you will find on keyboards which use top
 * number row is the symbol layer's numpad will function as a true numpad,
 * enabling one to access Home, End, and Del all from the second layer, all
 * depending on the state of numlock. ;)
 *
 * With some modification, this should be compatible across a wide variety 
 * of ergo/ortho boards, such as:
 *
 *   - Atreus42/52/62
 *   - HeliDox/Crkbd/Corne
 *   - Planck/Preonic/Let's Split/Helix
 *   - ErgoDox/ErgoDone/Zen/Sol
 *   - ReDox/ErgoTravel/Fortitude60
 *   - Dichotomy
 *   - Iris
 *
 */
 
 
/*
 * Indicator lights: ???
 *   - Caps Lock
 *   - Num Lock
 *   - Scroll Lock
 *   - Raise Hold
 *   - Lower Hold/Toggle
 *   - QWERTY
 *   - DVORAK
 */
 

extern keymap_config_t keymap_config;

enum atreus_layers {
  _QWERTY,
  _DVORAK,
  _SHIFTED,
  _SYMBOL,
  _FUNCTION,
};

enum atreus_keycodes {
  QWERTY = SAFE_RANGE,
  DVORAK,
  SHIFTED,
  SYMBOL,
  BRITE
};

#define OS_LCTL OSM(MOD_LCTL)
#define OS_LALT OSM(MOD_LALT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /*
   *   q      w      e     r    t        ||       y      u     i     o    p
   *   a      s      d     f    g        ||       h      j     k     l    ;
   *   z      x      c     v    b        ||       n      m     ,     .    /
   *  esc    tab   super shift bksp ctrl || alt space    fn    -     '  enter
   */
  [_QWERTY] = LAYOUT( /* QWERTY */ 
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                       KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
    KC_ESC,  KC_TAB,  KC_LGUI, SHIFTED, KC_BSPC,  OS_LCTL, OS_LALT, KC_SPC, SYMBOL,  KC_MINS, KC_QUOT, KC_ENT
  ),

  /*
   *   '      ,      .     p    y        ||       f       g     c     r    l
   *   a      o      e     u    i        ||       d       h     t     n    s
   *   ;      q      j     k    x        ||       b       m     v     v    z
   *  esc    tab   super shift bksp ctrl || alt space     fn    -     /  enter
   */
  [_DVORAK] = LAYOUT( /* Dvorak */
    KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                      KC_F,    KC_G,    KC_C,    KC_R,    KC_L,
    KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                      KC_D,    KC_H,    KC_T,    KC_N,    KC_S,
    KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,                      KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,
    KC_ESC,  KC_TAB,  KC_LGUI, SHIFTED, KC_BSPC, OS_LCTL, OS_LALT, KC_SPC,  SYMBOL,  KC_MINS, KC_SLSH, KC_ENT
  ),

  /*
   *   "      <      >     P    Y        ||       F       G     C     R    L
   *   A      O      E     U    I        ||       D       H     T     N    S
   *   :      Q      J     K    X        ||       B       M     W     V    Z
   *  esc    tab   super shift bksp ctrl || alt space     fn    _     ?  enter
   */
  [_SHIFTED] = LAYOUT( /* Dvorak Shifted */
    S(KC_QUOT), S(KC_COMM), S(KC_DOT), S(KC_P), S(KC_Y),                   S(KC_F),  S(KC_G),  S(KC_C),    S(KC_R),    S(KC_L),
    S(KC_A),    S(KC_O),    S(KC_E),   S(KC_U), S(KC_I),                   S(KC_D),  S(KC_H),  S(KC_T),    S(KC_N),    S(KC_S),
    S(KC_SCLN), S(KC_Q),    S(KC_J),   S(KC_K), S(KC_X),                   S(KC_B),  S(KC_M),  S(KC_W),    S(KC_V),    S(KC_Z),
    _______,    _______,    _______,   _______, _______, _______, _______, _______,  _______,  S(KC_MINS), S(KC_SLSH), _______
  ),

  /*
   *   !      @      {     }    ^        ||     ScrLk    7     8     9    *
   *   #      \      (     )    $        ||     NumLk    4     5     6    +
   *   `      %      [     ]    &        ||     CapLk    1     2     3    \
   * lower  oLower super shift bksp ctrl || alt space    fn    .     0    =
   */
  [_SYMBOL] = LAYOUT( /* Symbols (& Navigaton & Num Pad) */
    KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_CIRC,                   KC_SLCK, KC_P7,   KC_P8,   KC_P9, KC_PAST,
    KC_HASH, KC_BSLS, KC_LPRN, KC_RPRN, KC_DLR,                    KC_NLCK, KC_P4,   KC_P5,   KC_P6, KC_PPLS,
    KC_GRV,  KC_PERC, KC_LBRC, KC_RBRC, KC_AMPR,                   KC_CLCK, KC_P1,   KC_P2,   KC_P3, KC_PSLS,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PDOT, KC_P0, KC_PEQL
   ),

  /*
   *  play prev  next  SysReq reset     ||     rgb+    F7    F8     F9     F10
   *  mute vol-  vol+  PBreak debug     ||     rgb?    F4    F5     F6     F11
   *  PScr bri-?  bri+?  winapp VSN?       ||     rgb-    F1    F2     F3     F12
   *       lock? super  _____  bksp ctrl || alt space   ____  qwerty dvorak backlight
   */
  [_FUNCTION] = LAYOUT( /* Function Keys & Advanced Features */
    KC_MPLY, KC_MPRV, KC_MNXT, KC_SYSREQ, RESET,                     RGB_VAI,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_MUTE, KC_VOLD, KC_VOLU, KC_PAUS,   DEBUG,                     RGB_TOG,   KC_F4,   KC_F5,   KC_F6,   KC_F11,
    KC_PSCR, _______, _______, KC_APP,    _______,                   RGB_VAD,   KC_F1,   KC_F2,   KC_F3,   KC_F12,
    _______, _______, _______, _______,   _______, _______, _______, _______,   _______, QWERTY,  DVORAK,  BRITE
   )
};

const uint16_t PROGMEM fn_actions[] = {

};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _SHIFTED, _SYMBOL, _FUNCTION);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint16_t shifted_layer_timer;
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case BRITE:
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
    case SHIFTED:
      if (record->event.pressed) {
        shifted_layer_timer = timer_read();
		layer_on(_SHIFTED);
      } else {
	    layer_off(_SHIFTED);
		if(timer_elapsed(shifted_layer_timer) < 150) {
	      set_oneshot_mods(MOD_LSFT);
		}
	  }
      return false;
      break;
  }
  return true;
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        register_code(KC_RSFT);
      } else {
        unregister_code(KC_RSFT);
      }
    break;
  }
  return MACRO_NONE;
};
