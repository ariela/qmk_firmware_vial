// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_number {
    _QWERTY = 0,
    _RAISE,
    _LOWER,
    _ADJUST,
};

#define _______ KC_TRNS // 下位レイヤーのキーコードを使用
#define XXXXXXX KC_NO   // キーを無効にする

#define KC_LOWER LT(_LOWER, KC_LNG2) // Lowerレイヤー
#define KC_RAISE LT(_RAISE, KC_LNG1) // Raiseレイヤー

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   /* Qwerty
    *,-----------------------------------------------------------.        ,-----------------------------------------------------------.
    *|   Tab   |    Q    |    W    |    E    |    R    |    T    |        |    Y    |    U    |    I    |    O    |    P    |   BkSp  |
    *|---------+---------+---------+---------+---------+---------|        |---------+---------+---------+---------+---------+---------|
    *|  Ctrl   |    A    |    S    |    D    |    F    |    G    |        |    H    |    J    |    K    |    L    |    ;    |    '    |
    *|---------+---------+---------+---------+---------+---------|        |---------+---------+---------+---------+---------+---------|
    *|  Shift  |    Z    |    X    |    C    |    V    |    B    |        |    N    |    M    |    ,    |    .    |    /    |  Enter  |
    *`-------------------+---------+---------+---------+---------|        |---------+---------+---------+---------+-------------------'
    *                    |   Alt   |   GUI   |  Lower  |  Space  |        |  Space  |  Raise  |  Shift  |   ESC   |
    *                    `---------+---------+---------+---------'        `---------+---------+---------+---------'
    */
   [_QWERTY] = LAYOUT(
      KC_TAB   , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    ,         KC_Y     , KC_U    , KC_I    , KC_O     , KC_P   , KC_BSPC ,
      KC_LCTL  , KC_A    , KC_S    , KC_D    , KC_F    , KC_G    ,         KC_H     , KC_J    , KC_K    , KC_L     , KC_SCLN, KC_QUOT ,
      KC_LSFT  , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    ,         KC_N     , KC_M    , KC_COMM , KC_DOT   , KC_SLSH, KC_RSFT ,
                           KC_LALT , KC_LGUI , KC_LOWER, KC_SPC  ,         KC_SPC   , KC_RAISE, KC_RSFT , KC_ESC
   ),

   /* Raise
    *,-----------------------------------------------------------.        ,-----------------------------------------------------------.
    *|    ~    |    !    |    @    |    #    |    $    |    %    |        |    ^    |    &    |    *    |    (    |    )    |    |    |
    *|---------+---------+---------+---------+---------+---------|        |---------+---------+---------+---------+---------+---------|
    *|         |    ^    |    &    |    *    |    (    |    )    |        |         |    _    |    +    |    {    |    }    |         |
    *|---------+---------+---------+---------+---------+---------|        |---------+---------+---------+---------+---------+---------|
    *|         |         |         |         |    _    |    {    |        |    }    |    +    |         |         |         |         |
    *`-------------------+---------+---------+---------+---------|        |---------+---------+---------+---------+-------------------'
    *                    |  VoUp   |  VoDn   |         |  EISU   |        |         |         |         |         |
    *                    `---------+---------+---------+---------'        `---------+---------+---------+---------'
    */
   [_RAISE] = LAYOUT(
      KC_TILD  , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC ,         KC_CIRC  , KC_AMPR , KC_ASTR , KC_LPRN  , KC_RPRN, KC_PIPE ,
      _______  , KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN ,         _______  , KC_UNDS , KC_PLUS , KC_LCBR  , KC_RCBR, _______ ,
      _______  , _______ , _______ , _______ , KC_UNDS , KC_LCBR ,         KC_RCBR  , KC_PLUS , _______ , _______  , _______, _______ ,
                           KC_VOLU , KC_VOLD , _______ , KC_LNG2 ,         _______  , _______ , _______ , _______
   ),

   /* Lower
    *,-----------------------------------------------------------.        ,-----------------------------------------------------------.
    *|    `    |    1    |    2    |    3    |    4    |    5    |        |    6    |    7    |    8    |    9    |    0    |    \    |
    *|---------+---------+---------+---------+---------+---------|        |---------+---------+---------+---------+---------+---------|
    *|         |    6    |    7    |    8    |    9    |    0    |        |         |    -    |    =    |    [    |    ]    |         |
    *|---------+---------+---------+---------+---------+---------|        |---------+---------+---------+---------+---------+---------|
    *|         |         |         |         |    -    |    [    |        |    ]    |    =    |         |         |         |         |
    *`-------------------+---------+---------+---------+---------|        |---------+---------+---------+---------+-------------------'
    *                    |   RST   |         |         |         |        |  KANA   |         |  BrUp   |  BrDn   |
    *                    `---------+---------+---------+---------'        `---------+---------+---------+---------'
    */
   [_LOWER] = LAYOUT(
      KC_GRV   , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    ,         KC_6     , KC_7    , KC_8    , KC_9     , KC_0   , KC_BSLS ,
      _______  , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    ,         _______  , KC_MINS , KC_EQL  , KC_LBRC  , KC_RBRC, _______ ,
      _______  , _______ , _______ , _______ , KC_MINS , KC_LBRC ,         KC_RBRC  , KC_EQL  , _______ , _______  , _______, _______ ,
                           QK_RBT  , _______ , _______ , _______ ,         KC_LNG1  , _______ , KC_BRIU , KC_BRID
   ),

   /* Adjust
    *,-----------------------------------------------------------.        ,-----------------------------------------------------------.
    *|   F1    |   F2    |   F3    |   F4    |   F5    |   F6    |        |    F7   |    F8   |    F9   |   F10   |   F11   |   F12   |
    *|---------+---------+---------+---------+---------+---------|        |---------+---------+---------+---------+---------+---------|
    *|   F7    |   F8    |   F9    |   F10   |   F11   |   F12   |        |   LEFT  |   DOWN  |    UP   |  RIGHT  |         |         |
    *|---------+---------+---------+---------+---------+---------|        |---------+---------+---------+---------+---------+---------|
    *|         |         |         |         |         |         |        |         |         |         |         |         |         |
    *`-------------------+---------+---------+---------+---------|        |---------+---------+---------+---------+-------------------'
    *                    |         |         |         |         |        |         |         |         |         |
    *                    `---------+---------+---------+---------'        `---------+---------+---------+---------'
    */
   [_ADJUST] = LAYOUT(
      KC_F1    , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   ,         KC_F7    , KC_F8   , KC_F9   , KC_F10   , KC_F11 , KC_F12  ,
      KC_F7    , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  ,         KC_LEFT  , KC_DOWN , KC_UP   , KC_RGHT  , _______, _______ ,
      _______  , _______ , _______ , _______ , _______ , _______ ,         _______  , _______ , _______ , _______  , _______, _______ ,
                           _______ , _______ , _______ , _______ ,         _______  , _______ , _______ , _______
   )
};
