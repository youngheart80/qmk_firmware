#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _COLEMAK 0
#define _NAV 1
#define _NUMPAD 2
#define _ADJUST 16

enum custom_keycodes {
  COLEMAK = SAFE_RANGE,
  NAV,
  NUMPAD,
  ADJUST,
};

#define KC_ KC_TRNS
#define _______ KC_TRNS
#define KC_NONE KC_NO
#define KC_COLM TO(0)
#define KC_NAV MO(1)
#define KC_NAVT TO(1)
#define KC_SPCN LT(1, KC_SPC)
#define KC_NUM MO(2)
#define KC_NUMT TO(2)
#define KC_ADJ MO(16)
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


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESCH, 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,MINS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , F  , P  , G  ,                J  , L  , U  , Y  ,SCLN,BSLS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     CAPM, A  , R  , S  , T  , D  ,                H  , N  , E  , I  , O  ,QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LSPO, ZC , XA , C  , V  , B  ,UNDO,     ADJ, K  , M  ,COMM,DOTA,SLSC,RSPC,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       NUM ,DEL ,BSPC,          SPC, ENT, NAV
  //                  `----+----+----'        `----+----+----'
  ),

  [_NAV] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     CAD , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 , F10, F11,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TASK,CSTB,WINL,WINM,WINR,CTAB,               PGUP,HOME, UP , END, INS, F12,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LOCK,SELA, CUT,COPY, PST, TAB,               SELL,LEFT,DOWN,RGHT,SELR,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LSFT,LCTL,    ,    ,    ,STAB,LGUI,     COLM,PGDN,WRDL,    ,WRDR,RCTL,RSFT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,DEL ,BSPC,         SPC , ENT,
  //                  `----+----+----'        `----+----+----'
  ),

  [_NUMPAD] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC , 1  , 2  , 3  , 4  , 5  ,               NLCK,GRV ,SLSH,ASTR,LCBR,RCBR,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB ,NONE, Q  , W  , E  ,NONE,               EQL , 7  , 8  , 9  ,LBRC,RBRC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     CAPS,NONE, A  , S  , D  , F  ,               PLUS, 4  , 5  , 6  ,MINS,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LSFT,NONE,NONE,NONE,NONE,NONE,LGUI,     COLM,DOT , 1  , 2  , 3  ,ENT ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,DEL ,BSPC,          SPC, 0  ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_ADJUST] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     RTOG,RVAI,RVAD,RHUI,RHUD,    ,                   ,RSAI,RSAD,    ,    ,COLM,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,DBUG,                   ,    ,    ,    ,    ,NAVT,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,NUMT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,APP ,PSCR,SLCK,RST ,         ,MPRV,MPLY,MSTP,MNXT,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  )

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case COLEMAK:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case NAV:
      if (record->event.pressed) {
        layer_on(_NAV);
        update_tri_layer(_NAV, _NUMPAD, _ADJUST);
      } else {
        layer_off(_NAV);
        update_tri_layer(_NAV, _NUMPAD, _ADJUST);
      }
      return false;
      break;
      case NUMPAD:
        if (record->event.pressed) {
          layer_on(_NUMPAD);
          update_tri_layer(_NAV, _NUMPAD, _ADJUST);
        } else {
          layer_off(_NUMPAD);
          update_tri_layer(_NAV, _NUMPAD, _ADJUST);
        }
        return false;
        break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

void matrix_init_user(void) {
  rgblight_enable();
  rgblight_sethsv_orange();
};

uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
    case _NAV:
        rgblight_sethsv_red();
        break;
    case _NUMPAD:
        rgblight_sethsv_green();
        break;
    case _ADJUST:
        rgblight_sethsv_blue();
        break;
    default: //  for any other layers, or the default layer
        rgblight_sethsv_orange();
        break;
    }
  return state;
}
