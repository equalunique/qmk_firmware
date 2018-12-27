#include "dz60.h"

#include "action_layer.h"

extern keymap_config_t keymap_config;

enum dz60_layers {
 _QWERTY,
 _DVORAK,
 _COLEMAK,
 _WORKMAN,
 _FN,
 _SFX,
 _MOUSEB,
 _MOUSEW
};

/* 
 * These keycodes are for switching the underlying layout.
 * I define them like this because this is how it's done in
 * the default keymap for planck, which is a keymap file 
 * where I know this works for sure. 
 */
enum dz60_keycodes {
  QWERTY = SAFE_RANGE,
  DVORAK,
  COLEMAK,
  WORKMAN
};

/* Fillers to make layering more clear */
#define _______ KC_TRNS
#define ___X___ KC_NO

/* Mouse Layer Keycodes */
#define MOUSEB  MO(_MOUSEB)
#define MOUSEW  MO(_MOUSEW)

/* One Shot Mod Keycodes */
//#define KC_LCTL OSM(KC_LCTL)
//#define KC_LALT OSM(KC_LALT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* 
 * QWERTY gui/alt/space/alt/gui
 *
 * ,-----------------------------------------------------------------------------------------.
 * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  \  |  `  |
 * |-----------------------------------------------------------------------------------------+
 * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |  Bksp  |
 * |-----------------------------------------------------------------------------------------+
 * | Ctrl    |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
 * |-----------------------------------------------------------------------------------------+
 * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  | RShift    | FN  |
 * |-----------------------------------------------------------------------------------------+
 *         |LGUI | LAlt  |               Space                | RAlt   |RGUI |
 *         `-----------------------------------------------------------------'
 */
  [_QWERTY] = LAYOUT_hhkb( /* Basic QWERTY */
      KC_ESC,   KC_1,     KC_2,    KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV, \
      KC_TAB,   KC_Q,     KC_W,    KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,  \
      KC_LCTL,  KC_A,     KC_S,    KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  \
      KC_LSPO,  _______,  KC_Z,    KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC, MO(_FN), \
                KC_LGUI,  KC_LALT,                   KC_SPC,                    MOUSEB,  KC_RCTL \
      ),

/* Dvorak gui/alt/space/alt/gui
 * ,-----------------------------------------------------------------------------------------.
 * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  [  |  ]  |  \  |  `  |
 * |-----------------------------------------------------------------------------------------+
 * | Tab    |  '  |  ,  |  .  |  P  |  Y  |  F  |  G  |  C  |  R  |  L  |  /  |  =  |  Bksp  |
 * |-----------------------------------------------------------------------------------------+
 * | Ctrl    |  A  |  O  |  E  |  U  |  I  |  D  |  H  |  T  |  N  |  S  |  -  |    Enter    |
 * |-----------------------------------------------------------------------------------------+
 * | Shift     |  ;  |  Q  |  J  |  K  |  X  |  B  |  M  |  W  |  V  |  Z  | RShift    | FN  |
 * |-----------------------------------------------------------------------------------------+
 *         |LGUI | LAlt  |               Space                | RAlt   |RGUI |
 *         `-----------------------------------------------------------------'
 */
  [_DVORAK] = LAYOUT_hhkb( /* Basic DVORAK */
      KC_ESC,  KC_1,    KC_2,    KC_3,   KC_4, KC_5,   KC_6, KC_7, KC_8,    KC_9,    KC_0,    KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV, \
      KC_TAB,  KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y,   KC_F, KC_G, KC_C,    KC_R,    KC_L,    KC_SLSH, KC_EQL,  KC_BSPC,  \
      KC_LCTL, KC_A,    KC_O,    KC_E,   KC_U, KC_I,   KC_D, KC_H, KC_T,    KC_N,    KC_S,    KC_MINS, KC_ENT,  \
      KC_LSPO, _______, KC_SCLN, KC_Q,   KC_J, KC_K,   KC_X, KC_B, KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSPC, MO(_FN), \
               KC_LGUI, KC_LALT,                       KC_SPC,                       MOUSEB,  KC_RCTL \
      ),

/* Colemak gui/alt/space/alt/gui
 * ,-----------------------------------------------------------------------------------------.
 * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  \  |  `  |
 * |-----------------------------------------------------------------------------------------+
 * | Tab    |  Q  |  W  |  F  |  P  |  G  |  J  |  L  |  U  |  Y  |  ;  |  [  |  ]  |  Bksp  |
 * |-----------------------------------------------------------------------------------------+
 * | Ctrl    |  A  |  R  |  S  |  T  |  D  |  H  |  N  |  E  |  I  |  O  |  '  |    Enter    |
 * |-----------------------------------------------------------------------------------------+
 * | Shift     |  Z  |  X  |  C  |  V  |  B  |  K  |  M  |  ,  |  .  |  /  | RShift    | FN  |
 * |-----------------------------------------------------------------------------------------+
 *         |LGUI | LAlt  |               Space                | RAlt   |RGUI |
 *         `-----------------------------------------------------------------'
 */
  [_COLEMAK] = LAYOUT_hhkb( /* Basic COLEMAK */
      KC_ESC,  KC_1,    KC_2,    KC_3, KC_4, KC_5, KC_6, KC_7, KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV, \
      KC_TAB,  KC_Q,    KC_W,    KC_F, KC_P, KC_G, KC_J, KC_L, KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC, KC_BSPC,  \
      KC_LCTL, KC_A,    KC_R,    KC_S, KC_T, KC_D, KC_H, KC_N, KC_E,    KC_I,    KC_O,    KC_QUOT, KC_ENT,  \
      KC_LSPO, _______, KC_Z,    KC_X, KC_C, KC_V, KC_B, KC_K, KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC, MO(_FN), \
               KC_LGUI, KC_LALT,                   KC_SPC,                       MOUSEB,  KC_RCTL \
      ),

/* Workman gui/alt/space/alt/gui
 * ,-----------------------------------------------------------------------------------------.
 * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  \  |  `  |
 * |-----------------------------------------------------------------------------------------+
 * | Tab    |  Q  |  D  |  R  |  W  |  B  |  J  |  F  |  U  |  P  |  ;  |  [  |  ]  |  Bksp  |
 * |-----------------------------------------------------------------------------------------+
 * | Ctrl    |  A  |  S  |  H  |  T  |  G  |  Y  |  N  |  E  |  O  |  I  |  '  |    Enter    |
 * |-----------------------------------------------------------------------------------------+
 * | Shift     |  Z  |  X  |  M  |  C  |  V  |  K  |  L  |  ,  |  .  |  /  | RShift    | FN  |
 * |-----------------------------------------------------------------------------------------+
 *         |LGUI | LAlt  |               Space                | RAlt   |RGUI |
 *         `-----------------------------------------------------------------'
 */
  [_WORKMAN] = LAYOUT_hhkb( /* Basic Workman */
      KC_ESC,  KC_1,    KC_2,    KC_3, KC_4, KC_5,   KC_6, KC_7, KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV, \
      KC_TAB,  KC_Q,    KC_D,    KC_R, KC_W, KC_B,   KC_J, KC_F, KC_U,    KC_P,    KC_SCLN, KC_LBRC, KC_RBRC, KC_BSPC,  \
      KC_LCTL, KC_A,    KC_S,    KC_H, KC_T, KC_G,   KC_Y, KC_N, KC_E,    KC_O,    KC_I,    KC_QUOT, KC_ENT,  \
      KC_LSPO, _______, KC_Z,    KC_X, KC_M, KC_C,   KC_V, KC_K, KC_L,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC, MO(_FN), \
               KC_LGUI, KC_LALT,                     KC_SPC,                       MOUSEB,  KC_RCTL \
      ),


/* FN Layer
 * ,-----------------------------------------------------------------------------------------.
 * | SFX | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 | Ins | Del |
 * |-----------------------------------------------------------------------------------------+
 * |  CAPS  |     |     |     |     |     |     |     | Psc | Slck| Paus| Up  |     |        |
 * |-----------------------------------------------------------------------------------------+
 * |         | Vol-| Vol+| Mute|     |     | *   | /   | Home| PgUp| Left|Right|             |
 * |-----------------------------------------------------------------------------------------+
 * |           | Prev| Play| Next|     |     | +   | -   | End  |PgDn| Down|           |     |
 * |-----------------------------------------------------------------------------------------+
 *         |       |       |                                 | Stop  |       |
 *         `-----------------------------------------------------------------'
 */
  [_FN] = LAYOUT_hhkb( /* Layer 1 */
      TG(_SFX), KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,  KC_DEL, \
      _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP,   _______, _______,  \
      KC_CAPS,  KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, _______,   \
      _______,  _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, KC_PPLS, KC_PMNS, KC_END,  KC_PGDN, KC_DOWN, _______, _______,  \
                _______, _______,                   _______,                            KC_MSTP, _______ \
      ),


/* SFX Layer
 * ,-----------------------------------------------------------------------------------------.
 * |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |
 * |-----------------------------------------------------------------------------------------+
 * |        | BL- | BL+ | BL  |     |     |     |     |     |     |     |     |     |        |
 * |-----------------------------------------------------------------------------------------+
 * |         | RGBT| RGBM|     |     |     |     | QWE | DVO | COL | WOR |     |             |
 * |-----------------------------------------------------------------------------------------+
 * |           | Hue+| Hue-| Sat+| Sat-| Val+| Val-|     |      |    |     |           |     |
 * |-----------------------------------------------------------------------------------------+
 *         |       |       |                                 |       |       |
 *         `-----------------------------------------------------------------'
 */
  [_SFX] = LAYOUT_hhkb(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, BL_TOGG, BL_STEP, BL_DEC,  BL_INC,  _______, _______, DVORAK,  DVORAK,  _______, _______, _______, _______, _______,  \
      _______, RGB_TOG, RGB_MOD, _______, _______, _______, _______, DVORAK,  QWERTY,  COLEMAK, WORKMAN, _______, _______,  \
      _______, _______, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______, _______,  \
               _______, _______,                         _______,                      _______, _______ \
      ),

/* Mouse Button Layer
 * ,-----------------------------------------------------------------------------------------.
 * |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |
 * |-----------------------------------------------------------------------------------------+
 * |        | BL- | BL+ | BL  |     |     |     |     |     |     |     |     |     |        |
 * |-----------------------------------------------------------------------------------------+
 * |         | RGBT| RGBM|     |     |     |     |     |     |     |     |     |             |
 * |-----------------------------------------------------------------------------------------+
 * |           | Hue+| Hue-| Sat+| Sat-| Val+| Val-|     |      |    |     |           |     |
 * |-----------------------------------------------------------------------------------------+
 *         |       |       |                                 |       |       |
 *         `-----------------------------------------------------------------'
 */
  [_MOUSEB] = LAYOUT_hhkb(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_U, _______, KC_BTN1,  \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_R, KC_BTN2,  \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_D, KC_BTN3, MOUSEW,  \
               _______, _______,                       _______,                        _______, _______ \
      ),

/* Mouse Button Layer
 * ,-----------------------------------------------------------------------------------------.
 * |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |
 * |-----------------------------------------------------------------------------------------+
 * |        | BL- | BL+ | BL  |     |     |     |     |     |     |     |     |     |        |
 * |-----------------------------------------------------------------------------------------+
 * |         | RGBT| RGBM|     |     |     |     |     |     |     |     |     |             |
 * |-----------------------------------------------------------------------------------------+
 * |           | Hue+| Hue-| Sat+| Sat-| Val+| Val-|     |      |    |     |           |     |
 * |-----------------------------------------------------------------------------------------+
 *         |       |       |                                 |       |       |
 *         `-----------------------------------------------------------------'
 */
  [_MOUSEW] = LAYOUT_hhkb(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_WH_U, _______, KC_BTN1,  \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_R, KC_BTN2,  \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_WH_D, KC_BTN3, _______,  \
                 _______, _______,                       _______,                        _______, _______ \
      )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
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
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
   case WORKMAN:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_WORKMAN);
      }
      return false;
      break;
  }
  return true;
}

