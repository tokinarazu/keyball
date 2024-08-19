/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"
// #include "keymap_japanese.h"
// #include "features/twpair_on_jis.h"

enum custom_keycodes {
   MY_MACRO_0 = SAFE_RANGE,  // 0x7E40
   MY_MACRO_1,
   MY_MACRO_2,
   MY_MACRO_3,
   MY_MACRO_4,
   MY_MACRO_5,
   MY_USER_0 = KEYBALL_SAFE_RANGE  // 0x7E40
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  [0] = LAYOUT_universal(
    KC_TAB   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                        KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_BSPC   ,
    LCTL_T(KC_ESC), LGUI_T(KC_A), LALT_T(KC_S), LSFT_T(KC_D) , LCTL_T(KC_F) , KC_G ,                         KC_H     , LCTL_T(KC_J) , RSFT_T(KC_K)    , LALT_T(KC_L) , LT(1,KC_SCLN) , KC_MINUS ,
    KC_LSFT  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                                        KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , LT(3,KC_QUOT) ,
                  KC_LALT , KC_LGUI , LT(2,KC_LNG2)   , LT(3,KC_SPC) , LT(1,KC_LNG1) ,                QK_REPEAT_KEY, LT(2,KC_ENT), KC_NO      , KC_NO    , QK_KEY_OVERRIDE_TOGGLE
  ),

  [1] = LAYOUT_universal(
    _______  ,  KC_PGUP , MY_MACRO_0, KC_END  , MY_MACRO_2, MY_MACRO_5 ,                                     KC_ENT   , KC_HOME  , KC_UP    , KC_END   , KC_F6    , KC_F7    ,
    _______  ,  KC_HOME , MY_MACRO_1, KC_PGDN , MY_MACRO_3, MY_MACRO_4 ,                                     KC_BSPC  , KC_LEFT  , KC_DOWN  , KC_RGHT  , KC_F8    , KC_F9    ,
    _______  ,  KC_F1   , KC_F2     , KC_F4   , KC_F4     , KC_F5  ,                                         KC_DEL   , KC_BTN1  , KC_BTN3  , KC_BTN2  , KC_F10   , KC_F11   ,
                  _______  , _______ , _______  ,         _______  , _______  ,                   _______  , _______  , _______       , _______  , KC_F12
  ),

  [2] = LAYOUT_universal(
    _______  ,KC_QUOT   , S(KC_COMM)  , S(KC_DOT) , S(KC_QUOT) , KC_DOT  ,                                   S(KC_7)    , KC_LBRC    , KC_RBRC    , KC_SCLN    , S(KC_5)    , QK_GESC  ,
    _______  ,S(KC_1)   , KC_MINS     , S(KC_EQL) , KC_EQL     , S(KC_3)  ,                                  S(KC_BSLS) , S(KC_9)    , S(KC_0)    , S(KC_SCLN) , S(KC_SLSH) , S(KC_MINS)  ,
    _______  ,S(KC_6)   , KC_SLSH     , S(KC_8)   , KC_BSLS    , KC_GRV ,                                    KC_COMM    , S(KC_LBRC) , S(KC_RBRC) , S(KC_4)    , S(KC_2)    , S(KC_GRV) ,
                  _______  , _______  , _______  ,         _______  , _______  ,                   _______  , _______ , _______       , _______  , _______
  ),

  [3] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  , _______ ,                                          S(KC_8)  , KC_7    , KC_8     , KC_9     , KC_SLSH  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______ ,                                          S(KC_MINS) , KC_4  , KC_5     , KC_6     , KC_MINUS , S(KC_SCLN) ,
    _______  , _______  , _______  , _______  , _______  , _______ ,                                          KC_0     , KC_1    , KC_2     , KC_3     , KC_DOT   , KC_NO    ,
                  QK_BOOT  , KBC_SAVE  , _______  ,        _______  , _______  ,                   _______  , _______  , _______       , _______  , KC_EQUAL
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif

// [CUSTOM]
#if defined(KEY_OVERRIDE_ENABLE)
// shift+2  " -> @
const key_override_t kor_at = ko_make_with_layers(MOD_MASK_SHIFT, KC_2, S(KC_2), ~0);
// shift+6  & -> ^
const key_override_t kor_circ = ko_make_with_layers(MOD_MASK_SHIFT, KC_6, KC_EQL, ~0);
// shift+7  ' -> &
const key_override_t kor_ampr = ko_make_with_layers(MOD_MASK_SHIFT, KC_7, S(KC_6), ~0);
// shift+8  ( -> *
const key_override_t kor_astr = ko_make_with_layers(MOD_MASK_SHIFT, KC_8, S(KC_2), ~0);
// shift+9  ) -> (
const key_override_t kor_lprn = ko_make_with_layers(MOD_MASK_SHIFT, KC_9, S(KC_QUOT), ~0);
// shift+0    -> )
const key_override_t kor_rprn = ko_make_with_layers(MOD_MASK_SHIFT, KC_0, S(KC_9), ~0);
// shift+-  = -> _
const key_override_t kor_unds = ko_make_with_layers(MOD_MASK_SHIFT, KC_MINS, S(KC_INT1), ~0);
// =        ^ -> =
const key_override_t kor_eql = ko_make_with_layers_and_negmods(0, KC_EQL, KC_MINS, ~0, MOD_MASK_SHIFT);
// shift+=  ~ -> +
const key_override_t kor_plus = ko_make_with_layers(MOD_MASK_SHIFT, KC_EQL, S(KC_SCLN), ~0);
// [        @ -> [
const key_override_t kor_lbrc = ko_make_with_layers_and_negmods(0, KC_LBRC, KC_RBRC, ~0, MOD_MASK_SHIFT);
// shift+[  ` -> {
const key_override_t kor_lcbr = ko_make_with_layers(MOD_MASK_SHIFT, KC_LBRC, S(KC_NUHS), ~0);
// ]        [ -> ]
const key_override_t kor_rbrc = ko_make_with_layers_and_negmods(0, KC_RBRC, KC_NUHS, ~0, MOD_MASK_SHIFT);
// shift+]  { -> }
const key_override_t kor_rcbr = ko_make_with_layers(MOD_MASK_SHIFT, KC_RBRC, S(KC_RBRC), ~0);
/* \        ] -> \ */
const key_override_t kor_bsls = ko_make_with_layers_and_negmods(0, KC_BSLS, KC_INT1, ~0, MOD_MASK_SHIFT);
/* shift+\  } -> | */
const key_override_t kor_pipe = ko_make_with_layers(MOD_MASK_SHIFT, KC_BSLS, S(KC_INT3), ~0);
// shift+;  + -> :
const key_override_t kor_coln = ko_make_with_layers(MOD_MASK_SHIFT, KC_SCLN, S(KC_QUOT), ~0);
// '        : -> '
const key_override_t kor_quot = ko_make_with_layers_and_negmods(0, KC_QUOT, KC_EQLS, ~0, MOD_MASK_SHIFT);
// shift+'  * -> "
const key_override_t kor_dquo = ko_make_with_layers(MOD_MASK_SHIFT, KC_QUOT, KC_LBRC, ~0);
// `        全角半角 -> `
const key_override_t kor_grv = ko_make_with_layers_and_negmods(0, KC_GRV, S(KC_LBRC), ~0, MOD_MASK_SHIFT);
// shift+`  shift+全角半角 -> ~
const key_override_t kor_tild = ko_make_with_layers(MOD_MASK_SHIFT, KC_GRV, S(KC_EQL), ~0);

// shift+backspace -> delete
const key_override_t kor_delete = ko_make_with_layers(MOD_MASK_SHIFT, KC_BSPC, KC_DEL, ~0);

// ALTER REPEAT KEY
const key_override_t kor_alt_repeat = ko_make_with_layers(MOD_MASK_ALT, QK_REP, QK_AREP, ~0);

const key_override_t **key_overrides = (const key_override_t *[]){
    &kor_at,
    &kor_circ,
    &kor_ampr,
    &kor_astr,
    &kor_lprn,
    &kor_rprn,
    &kor_unds,
    &kor_eql,
    &kor_plus,
    &kor_bsls,
    &kor_pipe,
    &kor_lbrc,
    &kor_lcbr,
    &kor_rbrc,
    &kor_rcbr,
    &kor_coln,
    &kor_quot,
    &kor_dquo,
    &kor_grv,
    &kor_tild,
    &kor_delete,
    &kor_alt_repeat,
    NULL
};
#endif // KEY_OVERRIDE_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MY_MACRO_0:
      if (record->event.pressed) {
        // WIN + SPACE (JIS ⇔ US配列切替)
        SEND_STRING(SS_LGUI(SS_TAP(X_SPACE)));
      }
      return false;
      break;
    case MY_MACRO_1:
      if (record->event.pressed) {
        // CTRL + HOME (先頭へ移動)
        SEND_STRING(SS_LCTL(SS_TAP(X_HOME)));
      }
      return false;
      break;
    case MY_MACRO_2:
      if (record->event.pressed) {
        // CTRL + END (最後へ移動)
        SEND_STRING(SS_LCTL(SS_TAP(X_END)));
      }
      return false;
      break;
    case MY_MACRO_3:
      if (record->event.pressed) {
        // CTRL + F3 (カーソル位置の単語で次へ検索)
        SEND_STRING(SS_LCTL(SS_TAP(X_F3)));
      }
      return false;
      break;
    case MY_MACRO_4:
      if (record->event.pressed) {
        // ALT + F5 (VSCode: 差分を次へ検索)
        SEND_STRING(SS_LALT(SS_TAP(X_F5)));
      }
      return false;
      break;
    case MY_MACRO_5:
      if (record->event.pressed) {
        // click して行全体をコピー
        SEND_STRING(SS_TAP(X_BTN1) SS_TAP(X_HOME) SS_TAP(X_HOME) SS_LSFT(SS_TAP(X_END)) SS_LCTL("c"));
      }
      return false;
      break;
  }

  return true;
}
