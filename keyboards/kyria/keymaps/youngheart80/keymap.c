/* Copyright 2020 Grant M. Gardner https://grantmichaelgardner.com
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
#include QMK_KEYBOARD_H

enum layers {
    _COLEMAK = 0,
    _NAV,
    _NUMPAD,
	_SYMBOL,
    _ADJUST
};

#define _COLEMAK 0
#define _NAV 1
#define _NUMPAD 2 
#define _SYMBOL 3
#define _ADJUST 4

// Remove all of this and put into Userspace as some future date
#define KC_ KC_TRNS
#define _______ KC_TRNS
#define KC_NONE KC_NO
#define KC_COLM TO(0)
#define KC_NAV TT(1)
#define KC_NAVT TO(1)
#define KC_SPCN LT(1, KC_SPC)
#define KC_NUM TT(2)
#define KC_NUMT TO(2)
#define KC_SYMB TT(3)
#define KC_ADJ TT(4)
#define KC_RST RESET
//#define KC_BL_S BL_STEP
#define KC_DBUG DEBUG

/* RGB Underglow control definitions */
#define KC_RTOG RGB_TOG
#define KC_RMOD RGB_MOD
#define KC_RHUI RGB_HUI
#define KC_RHUD RGB_HUD
#define KC_RSAI RGB_SAI
#define KC_RSAD RGB_SAD
#define KC_RVAI RGB_VAI
#define KC_RVAD RGB_VAD


/* My personal definitions */
#define KC_XA ALT_T(KC_X) //mod tap - ALT when held, X when tapped
#define KC_DOTA ALGR_T(KC_DOT) //mod top - ALTGr when held, . when tapped
#define KC_ZC CTL_T(KC_Z) //mod tap - CTRL when held, Slash when tapped
#define KC_SLSC CTL_T(KC_SLSH) //mod tap - CTRL when held, Slash when tapped
#define KC_ESCH ALL_T(KC_ESC) //mod tap - HYPER when held, Esc when tapped
#define KC_CAPM MEH_T(KC_CAPS) //mod tap - MEH when held, CAPS when tapped
/* Modified Keycodes */
#define KC_UNDO LCTL(KC_Z) //Undo
#define KC_SELA LCTL(KC_A) //Select all
#define KC_COPY LCTL(KC_C) //Copy
#define KC_CUT LCTL(KC_X) //Cut
#define KC_PST LCTL(KC_V) //Paste
#define KC_STAB LSFT(KC_TAB) //Navigate back with shift tab
#define KC_CTAB LCTL(KC_TAB) //Chrome tab navigation
#define KC_CSTB LSFT(LCTL(KC_TAB)) //Chrome tab navigation
#define KC_WRDR LCTL(KC_RGHT) //Move cursor to next word
#define KC_WRDL LCTL(KC_LEFT) //Move cursor to previous word
#define KC_SELR LCTL(LSFT(KC_RGHT)) //Select work to Right
#define KC_SELL LCTL(LSFT(KC_LEFT)) //Select word to left
#define KC_CAD  LCTL(LALT(KC_DEL)) //One key CTRL-ALT-DEL
#define KC_TASK LSFT(LCTL(KC_ESC)) //Open Task Manager on Windows
#define KC_LOCK LGUI(KC_L) //One key lock for Windows
#define KC_WINM LGUI(KC_UP) //Maximize Window
#define KC_WINL LGUI(KC_LEFT) //Snap window left
#define KC_WINR LGUI(KC_RGHT) //Snap window right
// end Remove

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* 
 * Base Layer: Colemak
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |ESC/HYP |   Q  |   W  |   F  |   P  |   G  |                              |   J  |   L  |   U  |   Y  |   ;  |  | \   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Tab   |   A  |   R  |  S   |   T  |   D  |                              |   H  |   N  |   E  |   I  |  O   |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |SpcCadet|Z/Ctrl| X/Alt|   C  |   V  |   B  | UNDO | CAPM |  |ADJUST|LEADER|   K  |   M  | ,  < | . >  | /  ? |SpcCadet|
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | NAV  | SYMB | NUM  | Bspc | Del  |  | NAV  | Space| Enter| SYMB | Lock |
 *                        |      |      |      |      |      |  |      |      |      |      |Gui-L |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_COLEMAK] = LAYOUT(
      KC_ESCH, KC_Q   , KC_W   , KC_F   , KC_P   , KC_G   ,                                     KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, KC_MINS,
      KC_TAB , KC_A   , KC_R   , KC_S   , KC_T   , KC_D   ,                                     KC_H   , KC_N   , KC_E   , KC_I   , KC_O   , KC_QUOT,
      KC_LSPO, KC_ZC  , KC_XA  , KC_C   , KC_V   , KC_B   , KC_UNDO, KC_CAPM, KC_ADJ , KC_LEAD, KC_K   , KC_M   , KC_COMM, KC_DOT , KC_SLSC, KC_RSPC,
                                 KC_LGUI, KC_SYMB, KC_NUM , KC_BSPC, KC_DEL , KC_NAV , KC_SPC , KC_ENT , KC_SYMB, KC_LOCK
    ),
/*
 * Navigation Layer: NAV
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |Ct-Alt-D|      |Scrlck|PntScn|PausBr|      |                              | PGUP | HOME |  UP  | END  |Insert|        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |TaskMgr |      | LSFT | LALT | LCTL | Tab  |                              | None | LEFT | DOWN | RGHT | None |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | L Shft | LCTL | Cut  | Copy |Paste |ShfTab|      |      |  | COLM |      | PGDN | Tab  | None |ShfTab| RCTL | RSFT   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |WindL |WindR |      | Bspc | Del  |  |      | Space| Enter|      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
      KC_CAD , _______, KC_SLCK, KC_PSCR, KC_PAUS, _______,                                     KC_PGUP, KC_HOME, KC_UP  , KC_END , KC_INS , _______,
      KC_TASK, _______, KC_LSFT, KC_LALT, KC_LCTL, KC_TAB ,                                     KC_NO  , KC_LEFT, KC_DOWN, KC_RGHT, KC_NO  , _______,
      KC_LSFT, KC_LCTL, KC_CUT , KC_COPY, KC_PST , KC_STAB, _______, _______, KC_COLM, _______, KC_PGDN, KC_TAB , KC_NO  , KC_STAB, KC_RCTL, KC_RSFT,
                                 KC_WINL, KC_WINR, _______, KC_BSPC, KC_DEL , _______, KC_SPC , KC_ENT , _______, _______
    ),
/*
 * Numpad Layer: Number keys and Numpad
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  VOLU  |  1   |  2   |  3   |  4   |  5   |                              |  =   |  7   |  8   |  9   |  [   |   ]    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  VOLD  |  6   |  7   |  8   |  9   |  0   |                              |  +   |  4   |  5   |  6   |  -   |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  MUTE  |  /   |  *   |  -   |  +   |  .   |      |      |  | COLM |      |  .   |  1   |  2   |  3   |  /   |NumLock |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      | Bspc | Del  |  |      | Space|   0  |  *   |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NUMPAD] = LAYOUT(
      KC_VOLU, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                                     KC_EQL , KC_7   , KC_8   , KC_9   , KC_LBRC, KC_RBRC,
      KC_VOLD, KC_6   , KC_7   , KC_8   , KC_9   , KC_0   ,                                     KC_PLUS, KC_4   , KC_5   , KC_6   , KC_MINS, _______,
      KC_MUTE, KC_SLSH, KC_ASTR, KC_MINS, KC_PLUS, KC_DOT , _______, _______, KC_COLM, _______, KC_DOT , KC_1   , KC_2   , KC_3   , KC_SLSH, KC_NLCK,
                                 _______, _______, _______, KC_BSPC, KC_DEL , _______, KC_SPC , KC_0   , KC_ASTR, _______
    ),
/*
 * Layer: Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  !   |  @   |  #   |  $   |  %   |                              |      |      |      |      |      |  \ |   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  ^   |  &   |  *   |  |   |  `   |                              |   +  |  -   |  /   |  *   |  =   |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  [   |  ]   |  {   |  }   |  ~   |      |      |  | COLM |      |      |      |  ,   |  .   |  / ? |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      | Bspc | Del  |  |      | Space| Enter|      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYMBOL] = LAYOUT(
      _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                                     _______, _______, _______, _______, _______, KC_BSLS,
      _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_PIPE, KC_GRV ,                                     KC_PLUS, KC_MINS, KC_SLSH, KC_ASTR, KC_EQL , KC_QUOT,
      _______, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_TILD, _______, _______, KC_COLM, _______, _______, _______, KC_COMM, KC_DOT , KC_SLSH, _______,
                                 _______, _______, _______, KC_BSPC, KC_DEL , KC_SPC , KC_ENT , _______, _______, _______
    ),
/*
 * Adjust Layer: Function keys, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  VOLU  | F1   |  F2  | F3   | F4   | F5   |                              |      |      |      |      |      |COLM Tog|
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  VOLD  | F6   | F7   |  F8  | F9   | F10  |                              | TOG  | SAI  | HUI  | VAI  | MOD  |NAV Tog |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  MUTE  |      |      |      | F11  | F12  |      |      |  |      |      |      | SAD  | HUD  | VAD  | RMOD |NUM Tog |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT(
      KC_VOLU, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                                     _______, _______, _______, _______, _______,  KC_COLM,
      KC_VOLD, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 ,                                     RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,  KC_NAVT,
      KC_MUTE, _______, _______, _______, KC_F11 , KC_F12 , _______, _______, _______, _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, KC_NUMT,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

//layer_state_t layer_state_set_user(layer_state_t state) {
//    return update_tri_layer_state(state, _NAV, _NUMPAD, _ADJUST);
//}


//void matrix_init_user(void) {
//  rgblight_enable();
//  rgblight_sethsv_noeeprom(HSV_GOLDENROD);
//};


//New Lighting Layers stuff 2021 working out
// Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 4, HSV_RED},       // Light 4 LEDs, starting with LED 1
    {11, 4, HSV_RED}       // Light 4 LEDs, starting with LED 11
);
// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 2, HSV_CYAN}
);
// Light LEDs 11 & 12 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {11, 2, HSV_PURPLE}
);


// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_layer1_layer,    // Overrides caps lock layer
    my_layer2_layer     // Overrides other layers
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}




layer_state_t layer_state_set_user(layer_state_t state) {
    // Both layers will light up if both kb layers are active
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    return state;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}



//2020 Version
/*layer_state_t layer_state_set_user(layer_state_t state) {	
	switch (get_highest_layer(state)) {
    case _NAV:
        rgblight_sethsv_noeeprom(HSV_RED);
        break;
    case _NUMPAD:
        rgblight_sethsv_noeeprom(HSV_GREEN); 
        break;
	case _SYMBOL:
        rgblight_sethsv_noeeprom(HSV_PURPLE); 
        break;
    case _ADJUST:
        rgblight_sethsv_noeeprom(HSV_BLUE);
        break;
    default: //  for any other layers, or the default layer
        rgblight_sethsv_noeeprom(HSV_GOLDENROD);
        break;
    }
  return state;
 
}
*/