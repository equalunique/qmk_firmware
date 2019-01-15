// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

/*
 * Indicator lights:
 *   - Caps Lock
 *   - Num Lock
 *   - Scroll Lock
 *   - Raise Hold
 *   - Lower Hold/Toggle
 *   - QWERTY
 *   - DVORAK
 */

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QW 0
#define _DV 1
#define _LW 2
#define _RS 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /*
   *   q      w      e     r    t        ||       y      u     i     o    p
   *   a      s      d     f    g        ||       h      j     k     l    ;
   *   z      x      c     v    b        ||       n      m     ,     .    /
   *  esc    tab   super shift bksp ctrl || alt space    fn    -     '  enter
   */
  //[_QW] = LAYOUT( /* QWERTY */ 
  //  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P   ,
  //  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
  //  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
  //  KC_ESC,  KC_TAB,  KC_LGUI, RAISE,   KC_BSPC,  KC_LCTL, KC_LALT, KC_SPC,  LOWER,   KC_MINS, KC_QUOT, KC_ENT
  //),

  /*
   *   '      ,      .     p    y        ||       f       g     c     r    l
   *   a      o      e     u    i        ||       d       h     t     n    s
   *   ;      q      j     k    x        ||       b       m     v     v    z
   *  esc    tab   super shift bksp ctrl || alt space     fn    -     /  enter
   */
  [_DEFAULT] = LAYOUT( /* Dvorak */
    KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                      KC_F,    KC_G,    KC_C,    KC_R,    KC_L,
    KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                      KC_D,    KC_H,    KC_T,    KC_N,    KC_S,
    KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,                      KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,
    KC_ESC,  KC_TAB,  KC_LGUI, SHIF,    KC_BSPC, OS_LCTL, OS_LALT, KC_SPC,  SYMB,    KC_MINS, KC_SLSH, KC_ENT
  ),

  /*
   *   "      <      >     P    Y        ||       F       G     C     R    L
   *   A      O      E     U    I        ||       D       H     T     N    S
   *   :      Q      J     K    X        ||       B       M     W     V    Z
   *  esc    tab   super shift bksp ctrl || alt space     fn    _     ?  enter
   */
  [_SHIF] = LAYOUT( /* Dvorak Shifted */
    S(KC_QUOT), S(KC_COMM), S(KC_DOT), S(KC_P), S(KC_Y),                   S(KC_F), S(KC_G), S(KC_C),    S(KC_R),    S(KC_L),
    S(KC_A),    S(KC_O),    S(KC_E),   S(KC_U), S(KC_I),                   S(KC_D), S(KC_H), S(KC_T),    S(KC_N),    S(KC_S),
    S(KC_SCLN), S(KC_Q),    S(KC_J),   S(KC_K), S(KC_X),                   S(KC_B), S(KC_M), S(KC_W),    S(KC_V),    S(KC_Z),
    KC_ESC,     KC_TAB,     KC_LGUI,   _______, KC_BSPC, OS_LCTL, OS_LALT, KC_SPC,  SYMB,    S(KC_MINS), S(KC_SLSH), KC_ENT
  ),

  /*
   *   !      @      {     }    ^        ||     ScrLk    7     8     9    *
   *   #      \      (     )    $        ||     NumLk    4     5     6    +
   *   `      %      [     ]    &        ||     CapLk    1     2     3    \
   * lower  oLower super shift bksp ctrl || alt space    fn    .     0    =
   */
  [_SYMB] = LAYOUT( /* Symbols & Navigaton & Num Pad */
    KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_CIRC,                   KC_SLCK, KC_P7,   KC_P8,   KC_P9, KC_PAST,
    KC_HASH, KC_BSLS, KC_LPRN, KC_RPRN, KC_DLR,                    KC_NLCK, KC_P4,   KC_P5,   KC_P6, KC_PPLS,
    KC_GRV,  KC_PERC, KC_LBRC, KC_RBRC, KC_AMPR,                   KC_CLCK, KC_P1,   KC_P2,   KC_P3, KC_PSLS,
    TG(_LW), ML(_LW), KC_LGUI, SHIF,    KC_BSPC, OS_LCTL, OS_LALT, KC_SPC,  _______, KC_PDOT, KC_P0, KC_PEQL
   ),

  /*
   *  next vol+  bri+   SysReq bl+       ||     rgb+    F7    F8    F9    F10
   *  paus play  PrtSc  PBreak bl?       ||     rgb?    F4    F5    F6    F11
   *  prev vol-  bri-   winapp bl-       ||     rgb-    F1    F2    F3    F12
   *             super  shift  bksp ctrl || alt space   df  qwerty dvorak reset
   */
  [_FUNC] = LAYOUT( /* Function Keys & Advanced Features */
    KC_MPLY, KC_MPRV, KC_MNXT, KC_SYSREQ, RESET,                     RGB_VAI,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_MUTE, KC_VOLD, KC_VOLU, KC_PAUS,   DEBUG,                     RGB_TOG,   KC_F4,   KC_F5,   KC_F6,   KC_F11,
    KC_PSCR, KC_BRID, KC_BRIU, KC_APP,    VSN,                       RGB_VAD,   KC_F1,   KC_F2,   KC_F3,   KC_F12,
    _______, KC_LOCK, KC_LGUI, _______,   KC_BSPC, OS_LCTL, OS_LALT, KC_SPC,    _______, QWERTY,  DVORAK,  BRITE
   )
};

const uint16_t PROGMEM fn_actions[] = {

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
