/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
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

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum layer_number {
    _QWERTY = 0,
    _RAISE,
    _LOWER,
    _ADJUST,
};

// カスタムキーコードの定義
enum blender_keycode {
    CK_W = QK_KB_0,
    CK_S,
    CK_A,
    CK_D
};

#define KC_L_SPC LT(_LOWER, KC_SPC)  // lower
#define KC_R_ENT LT(_RAISE, KC_ENT)  // raise
#define KC_G_JA LGUI_T(KC_LNG1)     // cmd or win
#define KC_G_EN LGUI_T(KC_LNG2)     // cmd or win
#define KC_C_BS LCTL_T(KC_BSPC)      // ctrl
#define KC_A_DEL ALT_T(KC_DEL)       // alt

#define KC_LOWER LT(_LOWER, KC_LNG2) // Lowerレイヤー
#define KC_RAISE LT(_RAISE, KC_LNG1) // Raiseレイヤー

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   /* Qwerty
    *,-----------------------------------------------------------.                      ,-----------------------------------------------------------.
    *|   Tab   |    Q    |    W    |    E    |    R    |    T    |                      |    Y    |    U    |    I    |    O    |    P    |   BkSp  |
    *|---------+---------+---------+---------+---------+---------+---------.  .---------+---------+---------+---------+---------+---------+---------|
    *|  Ctrl   |    A    |    S    |    D    |    F    |    G    |  BkSp   |  |   BkSp  |    H    |    J    |    K    |    L    |    ;    |    '    |
    *|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------|
    *|  Shift  |    Z    |    X    |    C    |    V    |    B    |  Del    |  |   Del   |    N    |    M    |    ,    |    .    |    /    |  Enter  |
    *`-------------------+---------+---------+---------+---------+---------'  '---------+---------+---------+---------+---------+-------------------'
    *                    |   Alt   |   GUI   |  Lower  |  Space  |                      |  Space  |  Raise  |  Shift  |   ESC   |
    *                    `---------+---------+---------+---------'                      `---------+---------+---------+---------'
    */
   [_QWERTY] = LAYOUT(
      KC_TAB   , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    ,                        KC_Y    , KC_U    , KC_I    , KC_O     , KC_P   , KC_BSPC ,
      KC_LCTL  , KC_A    , KC_S    , KC_D    , KC_F    , KC_G    , KC_BSPC ,    KC_BSPC , KC_H    , KC_J    , KC_K    , KC_L     , KC_SCLN, KC_QUOT ,
      KC_LSFT  , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , KC_DEL  ,    KC_DEL  , KC_N    , KC_M    , KC_COMM , KC_DOT   , KC_SLSH, KC_RSFT ,
                           KC_LALT , KC_LGUI , KC_LOWER, KC_SPC  ,                        KC_SPC  , KC_RAISE, KC_RSFT , KC_ESC
   ),
   
   /* Raise
    *,-----------------------------------------------------------.                      ,-----------------------------------------------------------.
    *|    ~    |    !    |    @    |    #    |    $    |    %    |                      |    ^    |    &    |    *    |    (    |    )    |    |    |
    *|---------+---------+---------+---------+---------+---------+---------.  .---------+---------+---------+---------+---------+---------+---------|
    *|         |    ^    |    &    |    *    |    (    |    )    |         |  |         |         |    _    |    +    |    {    |    }    |         |
    *|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------|
    *|         |         |         |         |    _    |    {    |         |  |         |    }    |    +    |         |         |         |         |
    *`-------------------+---------+---------+---------+---------+---------'  '---------+---------+---------+---------+---------+-------------------'
    *                    |  VoUp   |  VoDn   |         |  EISU   |                      |         |         |         |         |
    *                    `---------+---------+---------+---------'                      `---------+---------+---------+---------'
    */
   [_RAISE] = LAYOUT(
      KC_TILD  , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC ,                        KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN  , KC_RPRN, KC_PIPE ,
      _______  , KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , _______ ,    _______ , _______ , KC_UNDS , KC_PLUS , KC_LCBR  , KC_RCBR, _______ ,
      _______  , _______ , _______ , _______ , KC_UNDS , KC_LCBR , _______ ,    _______ , KC_RCBR , KC_PLUS , _______ , _______  , _______, _______ ,
                           KC_VOLU , KC_VOLD , _______ , KC_LNG2 ,                        _______ , _______ , _______ , _______
   ),

   /* Lower
    *,-----------------------------------------------------------.                      ,-----------------------------------------------------------.
    *|    `    |    1    |    2    |    3    |    4    |    5    |                      |    6    |    7    |    8    |    9    |    0    |    \    |
    *|---------+---------+---------+---------+---------+---------+---------.  .---------+---------+---------+---------+---------+---------+---------|
    *|         |    6    |    7    |    8    |    9    |    0    |         |  |         |         |    -    |    =    |    [    |    ]    |         |
    *|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------|
    *|         |         |         |         |    -    |    [    |         |  |         |    ]    |    =    |         |         |         |         |
    *`-------------------+---------+---------+---------+---------+---------'  '---------+---------+---------+---------+---------+-------------------'
    *                    |   RST   |         |         |         |                      |  KANA   |         |  BrUp   |  BrDn   |
    *                    `---------+---------+---------+---------'                      `---------+---------+---------+---------'
    */
   [_LOWER] = LAYOUT(
      KC_GRV   , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    ,                        KC_6    , KC_7    , KC_8    , KC_9     , KC_0   , KC_BSLS ,
      _______  , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , _______ ,    _______ , _______ , KC_MINS , KC_EQL  , KC_LBRC  , KC_RBRC, _______ ,
      _______  , _______ , _______ , _______ , KC_MINS , KC_LBRC , _______ ,    _______ , KC_RBRC , KC_EQL  , _______ , _______  , _______, _______ ,
                           QK_RBT  , _______ , _______ , _______ ,                        KC_LNG1 , _______ , KC_BRIU , KC_BRID
   ),

   /* Adjust
    *,-----------------------------------------------------------.                      ,-----------------------------------------------------------.
    *|   F1    |   F2    |   F3    |   F4    |   F5    |   F6    |                      |    F7   |    F8   |    F9   |   F10   |   F11   |   F12   |
    *|---------+---------+---------+---------+---------+---------+---------'  '---------+---------+---------+---------+---------+---------+---------|
    *|   F7    |   F8    |   F9    |   F10   |   F11   |   F12   |         |  |         |   LEFT  |   DOWN  |    UP   |  RIGHT  |         |         |
    *|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------|
    *|         |         |         |         |         |         |         |  |         |         |         |         |         |         |         |
    *`-------------------+---------+---------+---------+---------+---------'  '---------+---------+---------+---------+---------+-------------------'
    *                    |         |         |         |         |                      |         |         |         |         |
    *                    `---------+---------+---------+---------'                      `---------+---------+---------+---------'
    */
   [_ADJUST] = LAYOUT(
      KC_F1    , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   ,                        KC_F7   , KC_F8   , KC_F9   , KC_F10   , KC_F11 , KC_F12  ,
      KC_F7    , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , _______ ,    _______ , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT  , _______, _______ ,
      _______  , _______ , _______ , _______ , _______ , _______ , _______ ,    _______ , _______ , _______ , _______ , _______  , _______, _______ ,
                           _______ , _______ , _______ , _______ ,                        _______ , _______ , _______ , _______
   ),
};

//==+====1====+====2====+====3====+====4====+====5====+====6====+====7====+====8====+====9====+====0
// ロータリーエンコーダー定義
//==+====1====+====2====+====3====+====4====+====5====+====6====+====7====+====8====+====9====+====0
#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_QWERTY] = { ENCODER_CCW_CW(KC_NO, KC_NO),     ENCODER_CCW_CW(KC_NO, KC_NO),     ENCODER_CCW_CW(KC_NO, KC_NO),     ENCODER_CCW_CW(KC_NO, KC_NO)     },
    [_RAISE]  = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [_LOWER]  = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [_ADJUST] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
};
#endif

//==+====1====+====2====+====3====+====4====+====5====+====6====+====7====+====8====+====9====+====0
// カスタムキーコード対応
//==+====1====+====2====+====3====+====4====+====5====+====6====+====7====+====8====+====9====+====0
// キルスイッチ用フラグ
static bool keep_key_w = false;
static bool keep_key_s = false;
static bool keep_key_a = false;
static bool keep_key_d = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CK_W:
            // ----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
            // キルスイッチ: W
            if (record->event.pressed) {
                keep_key_w = true;
                unregister_code(KC_S);
                register_code(KC_W);
            } else {
                keep_key_w = false;
                unregister_code(KC_W);
                if (keep_key_s) {
                    register_code(KC_S);
                }
            }
            return false;

        case CK_S:
            // ----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
            // キルスイッチ: S
            if (record->event.pressed) {
                keep_key_s = true;
                unregister_code(KC_W);
                register_code(KC_S);
            } else {
                keep_key_s = false;
                unregister_code(KC_S);
                if (keep_key_w) {
                    register_code(KC_W);
                }
            }
            return false;

        case CK_A:
            // ----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
            // キルスイッチ: A
            if (record->event.pressed) {
                keep_key_a = true;
                unregister_code(KC_D);
                register_code(KC_A);
            } else {
                keep_key_a = false;
                unregister_code(KC_A);
                if (keep_key_d) {
                    register_code(KC_D);
                }
            }
            return false;

        case CK_D:
            // ----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
            // キルスイッチ: D
            if (record->event.pressed) {
                keep_key_d = true;
                unregister_code(KC_A);
                register_code(KC_D);
            } else {
                keep_key_d = false;
                unregister_code(KC_D);
                if (keep_key_a) {
                    register_code(KC_A);
                }
            }
            return false;

        default:
            // ----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
            // その他キー
            return true;
    }
}

//==+====1====+====2====+====3====+====4====+====5====+====6====+====7====+====8====+====9====+====0
// OLED 定義
//==+====1====+====2====+====3====+====4====+====5====+====6====+====7====+====8====+====9====+====0
#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    
    return false;
}
#endif


