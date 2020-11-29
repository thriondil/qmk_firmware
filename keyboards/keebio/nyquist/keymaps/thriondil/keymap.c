#include "nyquist.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Make MT work better when typing quickly
#define PERMISSIVE_HOLD

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Define layer order
enum layers {
  _QWERTY = 0,
  _DVORAK,
  _COLEMAK,
  _TEST,
  _KEYPAD,
  _MOVE,
  _LOWER,
  _RAISE,
  _ADJUST
};

// Custom keycodes
enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  DVORAK,
  COLEMAK,
  TEST,
  KEYPAD,
  LOWER,
  RAISE
};

// Custom key abbreviations
#define MOVE LT(_MOVE, KC_SCLN)
#define CTL_ESC CTL_T(KC_ESC)
#define CTL_ENT CTL_T(KC_ENT)
#define SFT_LPN SFT_T(KC_LPRN)
#define SFT_RPN SFT_T(KC_RPRN)
#define CTL_LBR CTL_T(KC_LBRC)
#define CTL_RBR CTL_T(KC_RBRC)
#define ALT_QUO ALT_T(KC_QUOT)
#define MICMUTE LALT(KC_F4)

// Macro ID numbers
enum macro_ids {
  M_ALL_LCB = 1,
  M_ALL_RCB,
  M_GUI_LAB,
  M_GUI_RAB,
  M_ALT_MIC,
  M_ALT_DQO
};

// Custom macro keycodes
#define ALL_LCB MACROTAP(M_ALL_LCB)
#define ALL_RCB MACROTAP(M_ALL_RCB)
#define GUI_LAB MACROTAP(M_GUI_LAB)
#define GUI_RAB MACROTAP(M_GUI_RAB)
#define ALT_MIC MACROTAP(M_ALT_MIC)
#define ALT_DQO MACROTAP(M_ALT_DQO)

// Keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = KEYMAP( \
  KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    MOVE,    CTL_ENT, \
  KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC, \
  CTL_LBR, ALL_LCB, GUI_LAB, ALT_QUO, LOWER,   KC_SPC,  KC_SPC,  RAISE,   ALT_DQO, GUI_RAB, ALL_RCB, CTL_RBR \
),

// Not actually Dvorak yet, just a copy of Qwerty
[_DVORAK] = KEYMAP( \
  KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    MOVE,    CTL_ENT, \
  KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC, \
  CTL_LBR, ALL_LCB, GUI_LAB, ALT_QUO, LOWER,   KC_SPC,  KC_SPC,  RAISE,   ALT_DQO, GUI_RAB, ALL_RCB, CTL_RBR \
),

// Not actually Colemak yet, just a copy of Qwerty
[_COLEMAK] = KEYMAP( \
  KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    MOVE,    CTL_ENT, \
  KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC, \
  CTL_LBR, ALL_LCB, GUI_LAB, ALT_QUO, LOWER,   KC_SPC,  KC_SPC,  RAISE,   ALT_DQO, GUI_RAB, ALL_RCB, CTL_RBR \
),

// Not actually Test yet, just a copy of Qwerty
[_TEST] = KEYMAP( \
  KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    MOVE,    CTL_ENT, \
  KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC, \
  CTL_LBR, ALL_LCB, GUI_LAB, ALT_QUO, LOWER,   KC_SPC,  KC_SPC,  RAISE,   ALT_DQO, GUI_RAB, ALL_RCB, CTL_RBR \
),

[_KEYPAD] = KEYMAP( \
  KC_GESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NLCK, XXXXXXX, KC_PEQL, KC_PSLS, \
  KC_TAB,  XXXXXXX, KC_BTN1, KC_MS_U, KC_BTN2, XXXXXXX, XXXXXXX, XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PAST, \
  CTL_ESC, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX, XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PMNS, \
  KC_LSPO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PPLS, \
  CTL_LBR, ALL_LCB, GUI_LAB, ALT_QUO, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_P0,   KC_P0,   KC_DOT,  KC_PENT \
),

[_MOVE] = KEYMAP( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, KC_PGUP, _______, _______, _______, _______, KC_UP,   _______, _______, _______, \
  _______, _______, KC_HOME, KC_PGDN, KC_END,  _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, \
  _______, _______, _______, _______, _______, _______, KC_END,  _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

[_LOWER] = KEYMAP( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,  \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,  \
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
  _______, KC_TILD, KC_UNDS, KC_PLUS, KC_PIPE, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, KC_DEL,  _______, _______, _______, _______, _______ \
),

[_RAISE] = KEYMAP( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,  \
  _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_DEL,  \
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_QUOT, KC_DQUO, _______, \
  _______, KC_GRV,  KC_MINS, KC_EQL,  KC_BSLS, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, KC_BSPC, _______, _______, _______, _______, _______, _______ \
),

[_ADJUST] = KEYMAP( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  KEYPAD,  _______, _______, _______, _______, _______, _______, KC_MSTP, KC_VOLU, KC_MPLY, KC_PSCR, _______, \
  _______, QWERTY,  DVORAK,  COLEMAK, TEST,    _______, _______, KC_MPRV, KC_VOLD, KC_MNXT, _______, _______, \
  _______, _______, _______, KC_CALC, KEYPAD,  _______, _______, KC_MUTE, MICMUTE, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

};

// I don't know what this does
void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Layer switching
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        layer_on(_QWERTY);
        layer_off(_DVORAK);
        layer_off(_COLEMAK);
        layer_off(_TEST);
        layer_off(_KEYPAD);
      } else {
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        layer_off(_QWERTY);
        layer_on(_DVORAK);
        layer_off(_COLEMAK);
        layer_off(_TEST);
        layer_off(_KEYPAD);
      } else {
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        layer_off(_QWERTY);
        layer_off(_DVORAK);
        layer_on(_COLEMAK);
        layer_off(_TEST);
        layer_off(_KEYPAD);
      } else {
      }
      return false;
      break;
    case TEST:
      if (record->event.pressed) {
        layer_off(_QWERTY);
        layer_off(_DVORAK);
        layer_off(_COLEMAK);
        layer_on(_TEST);
        layer_off(_KEYPAD);
      } else {
      }
      return false;
      break;
    case KEYPAD:
      if (record->event.pressed) {
        layer_off(_QWERTY);
        layer_off(_DVORAK);
        layer_off(_COLEMAK);
        layer_off(_TEST);
        layer_on(_KEYPAD);
      } else {
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
  }
  return true;
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    case M_ALL_LCB:
      return MACRO_TAP_HOLD(record, (MACRO(D(LCTL), D(LALT), D(LSFT), D(LGUI), END)), (MACRO(U(LCTL), U(LALT), U(LSFT), U(LGUI), END)), (MACRO(I(10), D(LSFT), T(LBRC), U(LSFT), END)));
    case M_ALL_RCB:
      return MACRO_TAP_HOLD(record, (MACRO(D(LCTL), D(LALT), D(LSFT), D(LGUI), END)), (MACRO(U(LCTL), U(LALT), U(LSFT), U(LGUI), END)), (MACRO(I(10), D(LSFT), T(RBRC), U(LSFT), END)));
    case M_GUI_LAB:
      return MACRO_TAP_HOLD_MOD(record, (MACRO(I(10), D(LSFT), T(COMM), U(LSFT), END)), LGUI);
    case M_GUI_RAB:
      return MACRO_TAP_HOLD_MOD(record, (MACRO(I(10), D(LSFT), T(DOT), U(LSFT), END)), LGUI);
    /*case M_ALT_MIC:
      return MACRO_TAP_HOLD_MOD(record, (MACRO(I(10), D(LGUI), T(F4), U(LGUI), END)), LALT);*/
    case M_ALT_DQO:
      return MACRO_TAP_HOLD_MOD(record, (MACRO(I(10), D(LSFT), T(QUOT), U(LSFT), END)), RALT);
  }
  return MACRO_NONE;
};