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

#include QMK_KEYBOARD_H

#define _______ KC_TRNS
#define ____ KC_TRNS
#define ___X___ KC_NO
#define KC_SYRQ KC_SYSREQ

extern keymap_config_t keymap_config;

enum preonic_layers {
  _QWERTY,
  _DVORAK,
  _COLEMAK,
  _NAV,
  _NUM,
  _FUN,
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  DVORAK,
  COLEMAK,
  NAV,
  NUM,
  FUN,
  BACKLIT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid( \
  ___X___, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    ___X___, \
  KC_LALT, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_RALT, \
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_RCTL, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
  BACKLIT, KC_ESC,  KC_TAB,  KC_LGUI, NAV,     KC_BSPC, KC_SPC,  NUM,     KC_MINS, KC_QUOT, KC_ENT,  ___X___  \
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_preonic_grid( \
  ___X___, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    ___X___, \
  KC_LALT, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_RALT, \
  KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_RCTL, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
  BACKLIT, KC_ESC,  KC_TAB,  KC_LGUI, NAV,     KC_BSPC, KC_SPC,  NUM,     KC_MINS, KC_QUOT, KC_ENT,  ___X___  \
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_preonic_grid( \
  ___X___, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    ___X___, \
  KC_LALT, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_RALT, \
  KC_LCTL, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_RCTL, \
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT, \
  BACKLIT, KC_ESC,  KC_TAB,  KC_LGUI, NAV,     KC_BSPC, KC_SPC,  NUM,     KC_MINS, KC_SLSH, KC_ENT,  ___X___  \
),

/* Shifted
 *
 * This layer would make sense on the Atreus42, but it's unnecessary for Preonic & Planck keyboards.
 * Basically, whatever layer is underneath this, we shift those characters.
 *
 * I almost used a regex like this to make this change in NeoVim: KC_[A-Z0-9]*
 * 
 * Instead, I used this one, because I know the length of what I was going to replace with.
 *
 * The one above it may have been better if I had vim-easy-align(?) configured for this.
 *
 *
[_SHIFTED] = LAYOUT_preonic_grid( \
  _______, S(____), S(____), S(____), S(____), S(____), S(____), S(____), S(____), S(____), S(____), _______, \
  _______, S(____), S(____), S(____), S(____), S(____), S(____), S(____), S(____), S(____), S(____), _______, \
  _______, S(____), S(____), S(____), S(____), S(____), S(____), S(____), S(____), S(____), S(____), _______, \
  _______, S(____), S(____), S(____), S(____), S(____), S(____), S(____), S(____), S(____), S(____), _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),
 */

/* Navigation (& Symbols)
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = LAYOUT_preonic_grid( \
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
  _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_CIRC, KC_SLCK, KC_HOME, KC_UP,   KC_PGUP, KC_PAST, _______, \
  _______, KC_HASH, KC_BSLS, KC_LPRN, KC_RPRN, KC_DLR,  KC_NLCK, KC_LEFT, ___X___, KC_RGHT, KC_PPLS, _______, \
  _______, KC_GRV,  KC_PERC, KC_LBRC, KC_RBRC, KC_AMPR, KC_CLCK, KC_END,  KC_DOWN, KC_PGDN, KC_PSLS, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_INS,  KC_DEL,  KC_PEQL, _______  \
),

/* Numbers (& Symbols)
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_NUM] = LAYOUT_preonic_grid( \
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
  _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_CIRC, KC_SLCK, KC_7,    KC_8,    KC_9,    KC_PAST, _______, \
  _______, KC_HASH, KC_BSLS, KC_LPRN, KC_RPRN, KC_DLR,  KC_NLCK, KC_4,    KC_5,    KC_6,    KC_PPLS, _______, \
  _______, KC_GRV,  KC_PERC, KC_LBRC, KC_RBRC, KC_AMPR, KC_CLCK, KC_1,    KC_2,    KC_3,    KC_PSLS, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_PDOT, KC_0,    KC_PEQL, _______  \
),

/* Functions (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FUN] = LAYOUT_preonic_grid( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
  _______, KC_MPLY, KC_MPRV, KC_MNXT, KC_SYRQ, RESET,   RGB_VAI, KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
  _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_PAUS, DEBUG,   RGB_TOG, KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______, \
  _______, KC_PSCR, _______, _______, KC_APP,  _______, RGB_VAD, KC_F1,   KC_F2,   KC_F3,   KC_F12,  _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, QWERTY,  COLEMAK, DVORAK,  _______  \
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
        case NAV:
          if (record->event.pressed) {
            layer_on(_NAV);
            update_tri_layer(_NAV, _NUM, _FUN);
          } else {
            layer_off(_NAV);
            update_tri_layer(_NAV, _NUM, _FUN);
          }
          return false;
          break;
        case NUM:
          if (record->event.pressed) {
            layer_on(_NUM);
            update_tri_layer(_NAV, _NUM, _FUN);
          } else {
            layer_off(_NUM);
            update_tri_layer(_NAV, _NUM, _FUN);
          }
          return false;
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef __AVR__
            PORTE &= ~(1<<6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            PORTE |= (1<<6);
            #endif
          }
           return false;
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_NUM)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
}

void dip_update(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        layer_on(_FUN);
      } else {
        layer_off(_FUN);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
        #ifdef AUDIO_ENABLE
          stop_all_notes();
        #endif
      }
   }
}

/*
 * I took this out because it gives me this compile error:
 *
 * error: implicit declaration of function 'muse_clock_pulse' [-Werror=implicit-function-declaration]
 *  uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
 *                                          ^~~~~~~~~~~~~~~~
 *
void matrix_scan_user(void) {
  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
}
*/

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case NUM:
    case NAV:
      return false;
    default:
      return true;
  }
}
