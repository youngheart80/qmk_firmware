/* Copyright 2020 Grant Gardner youngheart80@gmail.com>
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

#pragma once

//#ifdef OLED_DRIVER_ENABLE
//  #define OLED_DISPLAY_128X64
//#endif

#ifdef RGBLIGHT_ENABLE
//#define RGBLIGHT_ANIMATIONS
  #define RGBLIGHT_LAYERS
  #define RGBLIGHT_SPLIT 10
  #define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
  #define RGBLIGHT_DEFAULT_HUE 30
  #define RGBLIGHT_SLEEP
  #define RGBLIGHT_HUE_STEP 10
  #define RGBLIGHT_SAT_STEP 17
  #define RGBLIGHT_VAL_STEP 17
#endif

// If you are using an Elite C rev3 on the slave side, uncomment the lines below:
// #define SPLIT_USB_DETECT
// #define NO_USB_STARTUP_CHECK

#define TAPPING_TERM 150
#define TAPPING_TOGGLE 3  //Tap to toggle for layers

#define LEADER_PER_KEY_TIMING  150  //Leader key timeout per key
//#define LEADER_TIMEOUT 300 			//Leader key timeout 

#define IGNORE_MOD_TAP_INTERRUPT
#define PREVENT_STUCK_MODIFIERS