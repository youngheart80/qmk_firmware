/*
Copyright 2017 Christopher Courtney <drashna@live.com> @drashna

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

#pragma once
#include QMK_KEYBOARD_H

#include "wrappers.h"

/* Define layer names */
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

/* Layer keycode definitions to make typing easier */
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