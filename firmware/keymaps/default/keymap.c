#include QMK_KEYBOARD_H
#include "raw_hid.h"
#include "fruitbar.h"


enum layers{
  _BASE,
  _FN,
  _ARROWS
};


enum {
  SPACE_FN_LAYER,
  FN_ARR_LAYER,
  SLSH_BKSLSH,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [SPACE_FN_LAYER] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, MO(_FN)),
  [FN_ARR_LAYER] = ACTION_TAP_DANCE_DOUBLE(MO(_FN), MO(_ARROWS)),
  [SLSH_BKSLSH] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_BSLS),
};

void raw_hid_receive(uint8_t *data, uint8_t length) {
    // Your code goes here. data is the packet received from host.
    raw_hid_send(data, length);
}

bool encoder_update_user(uint8_t index, bool clockwise) {
  if(clockwise) {
    tap_code(KC_VOLU);
  } else {
    tap_code(KC_VOLD);
  }
  return false;
}



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
           KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC,       KC_HOME, KC_MUTE,
           KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_BSLS, KC_ENT,
           KC_LSHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, TD(SLSH_BKSLSH), KC_RSFT,                     KC_UP,
           KC_LCTRL, KC_LGUI, KC_LALT,    KC_SPC, TD(FN_ARR_LAYER), TD(SPACE_FN_LAYER),KC_RALT, MO(_FN), KC_RCTRL,   KC_LEFT, KC_DOWN, KC_RIGHT
  ),

  [_FN] = LAYOUT(
           KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_DEL,         KC_HOME, KC_TRNS,
           KC_CAPS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,
       RESET, KC_TRNS, KC_TRNS,      KC_BSPC, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS,        KC_HOME, KC_TRNS, KC_END, 
  ),
  [_ARROWS] = LAYOUT(
           KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_HOME, KC_END, KC_BSLS,         KC_PGDN, KC_TRNS,
           KC_CAPS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
      	   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, 
      	   RESET, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, 
        ) 
        };
