#include QMK_KEYBOARD_H
#include <print.h>

extern keymap_config_t keymap_config;

enum layers{
  _QWERTY= 0,
  _COLEMAK,
  _DVORAK,
  _MOVE,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  MOVE,
  LOWER,
  RAISE,
  ADJUST,
};

// Custom key abbreviations
#define MOVE    LT(_MOVE, KC_SCLN)
#define CTL_ESC CTL_T(KC_ESC)
#define CTL_LBR CTL_T(KC_LBRC)
#define CTL_RBR CTL_T(KC_RBRC)
#define ALL_LCB MACROTAP(M_ALL_LCB)
#define ALL_RCB MACROTAP(M_ALL_RCB)
#define GUI_LAB MACROTAP(M_GUI_LAB)
#define GUI_RAB MACROTAP(M_GUI_RAB)
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Macro ID numbers
enum macro_ids {
  M_ALL_LCB = 1,
  M_ALL_RCB,
  M_GUI_LAB,
  M_GUI_RAB
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_dactyl( \
  KC_GESC, KC_1   , KC_2,    KC_3,     KC_4,    KC_5,       KC_6,    KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC, \
  KC_TAB , KC_Q   , KC_W,    KC_E,     KC_R,    KC_T,       KC_Y,    KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC , \
  CTL_ESC, KC_A   , KC_S,    KC_D,     KC_F,    KC_G,       KC_H,    KC_J   , KC_K   , KC_L   , MOVE   , KC_ENT , \
  KC_LSPO, KC_Z   , KC_X,    KC_C,     KC_V,    KC_B,       KC_N,    KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSPC, \
  CTL_LBR, ALL_LCB, GUI_LAB, KC_LALT,  KC_NO  , XXXXXXX,    XXXXXXX, KC_NO  , KC_RALT, GUI_RAB, ALL_RCB, CTL_RBR, \
                                       KC_NO  , KC_LGUI,    KC_NO  , KC_NO  , \
                                                KC_NO  ,    KC_NO  , \
                             KC_SPC ,  LOWER  , KC_LCTL,    KC_LALT, RAISE  ,  KC_SPC  \
),
[_MOVE] = LAYOUT_dactyl( \
  _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, KC_PGUP, _______, _______,     _______, _______, KC_UP  , _______, _______, _______, \
  _______, _______, KC_HOME, KC_PGDN, KC_END , _______,     KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, \
  _______, _______, _______, _______, _______, _______,     KC_END , _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, XXXXXXX,     XXXXXXX, _______, _______, _______, _______, _______, \
                                      _______, _______,     _______, _______, \
                                               _______,     _______, \
                             _______, _______, _______,     _______, _______, _______ \
),
[_LOWER] = LAYOUT_dactyl( \
  _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, KC_DEL , \
  _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,     KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_DEL , \
  _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______, \
  _______, KC_TILD, KC_UNDS, KC_PLUS, KC_PIPE, _______,     _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, RESET  , XXXXXXX,     XXXXXXX, _______, _______, _______, _______, _______, \
                                      _______, _______,     _______, _______, \
                                               _______,     _______, \
                             _______, _______, _______,     _______, _______, KC_DEL  \
),
[_RAISE] = LAYOUT_dactyl( \
  _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, KC_DEL , \
  _______, KC_F11 , KC_F12 , KC_F13 , KC_F14 , KC_F15,      KC_F16 , KC_F17 , KC_F18 , KC_F19 , KC_F20 , KC_DEL , \
  _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_QUOT, KC_DQUO, _______, \
  _______, KC_GRV,  KC_MINS, KC_EQL,  KC_BSLS, _______,     _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, XXXXXXX,     XXXXXXX, RESET  , _______, _______, _______, _______, \
                                      _______, _______,     _______, _______, \
                                               _______,     _______, \
                             KC_BSPC, _______, _______,     _______, _______, _______ \
),
[_ADJUST] = LAYOUT_dactyl( \
  _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,     _______, KC_MSTP, KC_VOLU, KC_MPLY, KC_PSCR, _______, \
  _______, QWERTY , DVORAK , COLEMAK, _______, _______,     _______, KC_MPRV, KC_VOLD, KC_MNXT, _______, _______, \
  _______, _______, _______, KC_CALC, _______, _______,     _______, KC_MUTE, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, XXXXXXX,     XXXXXXX, _______, _______, _______, _______, _______, \
                                      _______, _______,     _______, _______, \
                                               _______,     _______, \
                             _______, _______, _______,     _______, _______, _______ \
)
};

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  //debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif 

  switch (keycode) {
  case QWERTY:
    if (record->event.pressed) {
      layer_on(_QWERTY);
      layer_off(_DVORAK);
      layer_off(_COLEMAK);
    } else {
    }
    return false;
    break;
  case DVORAK:
    if (record->event.pressed) {
      layer_off(_QWERTY);
      layer_on(_DVORAK);
      layer_off(_COLEMAK);
    } else {
    }
    return false;
    break;
  case COLEMAK:
    if (record->event.pressed) {
      layer_off(_QWERTY);
      layer_off(_DVORAK);
      layer_on(_COLEMAK);
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
  }
  return MACRO_NONE;
};