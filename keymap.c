#include QMK_KEYBOARD_H

enum layers {
	_BASE,
	_FUNC
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT(
		 KC_ESC, KC_GRV,  KC_1, KC_2, KC_3, KC_4, KC_5, KC_6,       KC_7,   KC_8, KC_9, KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_DEL, \
		KC_COPY, KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T,             KC_Y,   KC_U, KC_I, KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC, \
	   KC_PASTE, KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G,             KC_H,   KC_J, KC_K, KC_L,    KC_SCLN, KC_QUOT,          KC_ENT, \
				 KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,             MO(1),  KC_N, KC_M, KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(1), \
				 KC_LCTL,    KC_LALT, LT(1,KC_SPC), KC_LGUI,        KC_SPC,       KC_RALT,                         KC_RCTL),
	[_FUNC] = LAYOUT(
		RGB_TOG, VLK_TOG, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F6,     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NO, RESET, \
		RGB_MOD, KC_NO,   KC_NO,   KC_NO,   KC_UP,   KC_NO,   KC_NO,             KC_CALC, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, LCTL(KC_BSPC), \
	   RGB_RMOD, KC_NO,   KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,             KC_NO,   KC_HOME, KC_NO,   KC_NO,   KC_END,  KC_UP,   KC_NO, \
		         KC_TRNS, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI,           RGB_VAD, KC_VOLU, KC_VOLD, KC_MUTE, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, \
				 KC_TRNS, 		            KC_TRNS, KC_NO,   KC_TRNS,           KC_TRNS,          KC_RALT,                            KC_TRNS)
};
