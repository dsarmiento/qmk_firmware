#include "dz60.h"

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Macro for my layout
#define KEYMAP_E( \
	K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, \
	K100,       K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, \
	K200,       K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213,       \
	K300,       K302, K303, K304, K305, K306, K307, K308, K309, K310,       K312, K313, K314, \
	K400, K401,       K403, K404,       K406,       K408,       K410, K411, K412, K413, K414  \
) { \
	{ K000,  K001,  K002,  K003,  K004,  K005,  K006,  K007,  K008,  K009,  K010,  K011,  K012,  K013,  K014 }, \
	{ K100,  KC_NO, K102,  K103,  K104,  K105,  K106,  K107,  K108,  K109,  K110,  K111,  K112,  K113,  K114 }, \
	{ K200,  KC_NO, K202,  K203,  K204,  K205,  K206,  K207,  K208,  K209,  K210,  K211,  K212,  K213,  KC_NO }, \
	{ K300,  KC_NO, K302,  K303,  K304,  K305,  K306,  K307,  K308,  K309,  K310,  KC_NO, K312,  K313,  K314 }, \
	{ K400,  K401,  KC_NO, K403,  K404,  KC_NO, K406,  KC_NO, K408,  KC_NO, K410,  K411,  K412,  K413,  K414 }  \
}

enum custom_keycodes {
	TOG_GUI = SAFE_RANGE,
	CUR_GUI
};

uint16_t currGUI = KC_LGUI;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Layer x
 * ,-----------------------------------------------------------------------------------------.
 * |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |
 * |-----------------------------------------------------------------------------------------|
 * |       |     |     |     |     |     |     |     |     |     |     |     |     |         |
 * |-----------------------------------------------------------------------------------------|
 * |         |     |     |     |     |     |     |     |     |     |     |     |             |
 * |-----------------------------------------------------------------------------------------|
 * |           |     |     |     |     |     |     |     |     |     |           |     |     |
 * |-----------------------------------------------------------------------------------------|
 * |       |      |      |            |      |               |      |      |     |     |     |
 * `-----------------------------------------------------------------------------------------'
 */
/* KEYMAP_E (
 *     _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
 *     _______,        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
 *     _______,        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
 *     _______,        _______,_______,_______,_______,_______,_______,_______,_______,_______,        _______,_______,_______,
 *     _______,_______,        _______,_______,        _______,        _______,        _______,_______,_______,_______,_______)
 * }
 */

/* Layer 0
 * ,-----------------------------------------------------------------------------------------.
 * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  | Ins |  \  |
 * |-----------------------------------------------------------------------------------------|
 * | Tab   |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |  BkSpc  |
 * |-----------------------------------------------------------------------------------------|
 * | Caps    |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
 * |-----------------------------------------------------------------------------------------|
 * | LShift    |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |    RSh    |  ↑  |  /  |
 * |-----------------------------------------------------------------------------------------|
 * | LCtrl |CURGUI| LAlt |   Space    | Mo 1 |     Space     | RAlt |RCtrl |  ←  |  ↓  |  →  |
 * `-----------------------------------------------------------------------------------------'
 */
	KEYMAP_E (
		KC_ESC ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_MINS,KC_EQL ,KC_INS ,KC_BSLS,
		KC_TAB ,        KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_LBRC,KC_RBRC,KC_BSPC,
		KC_CAPS,        KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,KC_QUOT,KC_ENT ,
		KC_LSFT,        KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,KC_N   ,KC_M   ,KC_COMM,KC_DOT ,        KC_RSFT,KC_UP  ,KC_SLSH,
		KC_LCTL,CUR_GUI,        KC_LALT,KC_SPC ,        MO(1)  ,        KC_SPC ,        KC_RALT,KC_RCTL,KC_LEFT,KC_DOWN,KC_RIGHT),

/* Layer 1
 * ,-----------------------------------------------------------------------------------------.
 * |     | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |T GUI|  `  |
 * |-----------------------------------------------------------------------------------------|
 * |       |     |     |     |     |     |     |  7  |  8  |  9  |  /  |  *  |     |   Del   |
 * |-----------------------------------------------------------------------------------------|
 * |         |     |     |     |     |     |     |  4  |  5  |  6  | -   | +   |             |
 * |-----------------------------------------------------------------------------------------|
 * |           |     |     |     |     |     |     |  1  |  2  |  3  |   Mo 2    | PgUp|     |
 * |-----------------------------------------------------------------------------------------|
 * |       |      |      |            |      |       0       |      | Mo 3 | Home| PgDn| End |
 * `-----------------------------------------------------------------------------------------'
 */
	KEYMAP_E (
		_______,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,TOG_GUI,KC_GRV ,
		_______,        _______,_______,_______,_______,_______,_______,KC_P7  ,KC_P8  ,KC_P9  ,KC_PSLS,KC_PAST,_______,KC_DEL ,
		_______,        _______,_______,_______,_______,_______,_______,KC_P4  ,KC_P5  ,KC_P6  ,KC_PMNS,KC_PPLS,_______,
		_______,        _______,_______,_______,_______,_______,_______,KC_P1  ,KC_P2  ,KC_P3  ,        MO(2)  ,KC_PGUP,_______,
		_______,_______,        _______,_______,        _______,        KC_P0  ,        _______,MO(3)  ,KC_HOME,KC_PGDN,KC_END ),

/* Layer 2
 * ,-----------------------------------------------------------------------------------------.
 * |     | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20 | F21 | F22 | F23 | F24 |     |     |
 * |-----------------------------------------------------------------------------------------|
 * |       |     |     |     |     |     |     |     |     |     |     |     |     |         |
 * |-----------------------------------------------------------------------------------------|
 * |         |     |     |     |     |     |     |     |     |     |     |     |             |
 * |-----------------------------------------------------------------------------------------|
 * |           |     |     |     |     |     |     |     |     |     |           |     |     |
 * |-----------------------------------------------------------------------------------------|
 * |       |      |      |            |      |               |      |      |     |     |     |
 * `-----------------------------------------------------------------------------------------'
 */
    KEYMAP_E (
        _______,KC_F13 ,KC_F14 ,KC_F15 ,KC_F16 ,KC_F17 ,KC_F18 ,KC_F19 ,KC_F20 ,KC_F21 ,KC_F22 ,KC_F23 ,KC_F24 ,_______,_______,
        _______,        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
        _______,        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
        _______,        _______,_______,_______,_______,_______,_______,_______,_______,_______,        _______,_______,_______,
        _______,_______,        _______,_______,        _______,        _______,        _______,_______,_______,_______,_______),



/* Layer 3
 * ,-----------------------------------------------------------------------------------------.
 * | Rst |     |     |     |     |     |     |     |     |     |     |     |     |     |     |
 * |-----------------------------------------------------------------------------------------|
 * |       |     |     |     |     |     |     |     |     |     |     |     |     |         |
 * |-----------------------------------------------------------------------------------------|
 * |         |     |     |     |     |     |     |     |     |     |     |     |             |
 * |-----------------------------------------------------------------------------------------|
 * |           |     |     |     |     |     |     |     |     |     |           |     |     |
 * |-----------------------------------------------------------------------------------------|
 * |       |      |      |            |      |               |      |      |     |     |     |
 * `-----------------------------------------------------------------------------------------'
 */
	KEYMAP_E (
		RESET  ,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
		_______,        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
		_______,        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
		_______,        _______,_______,_______,_______,_______,_______,_______,_______,_______,        _______,_______,_______,
		_______,_______,        _______,_______,        _______,        _______,        _______,_______,_______,_______,_______)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (record->event.pressed)
	{
		switch(keycode)
		{
			case TOG_GUI:
				if(currGUI == KC_LGUI)
				{
					currGUI = XXXXXXX;
				}
				else
				{
					currGUI = KC_LGUI;
				}
				return false;

			case CUR_GUI:
				if(currGUI == KC_LGUI)
				{
					SEND_STRING(SS_DOWN(X_LGUI));
				}
				return false;
		}
	}
	else
	{
		switch(keycode)
		{
			case CUR_GUI:
				if(currGUI == KC_LGUI)
				{
					SEND_STRING(SS_UP(X_LGUI));
				}
				return false;
		}
	}
	return true;
};



enum function_id {
    SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(SHIFT_ESC),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t shift_esc_shift_mask;
  switch (id) {
    case SHIFT_ESC:
      shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
      if (record->event.pressed) {
        if (shift_esc_shift_mask) {
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        if (shift_esc_shift_mask) {
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      break;
  }
}