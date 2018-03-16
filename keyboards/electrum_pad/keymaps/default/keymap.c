// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "electrum_pad.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,------------------------------------------
 * |  `   |   1  |   2  |   3  |   4  |   5  |
 * |------+------+------+------+------+-------
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |
 * |------+------+------+------+------+-------
 * | F15  |   A  |   S  |   D  |   F  |   G  |
 * |------+------+------+------+------+-------
 * | Shift|   Z  |   X  |   C  |   V  |   B  |
 * |------+------+------+------+------+------+
 * | Ctrl | F13  | Alt  | F14  |    Space    |
 * `------------------------------------------   
 */
[0] = {
    { KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , RESET  },
    { KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   },
    { KC_F15 , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   },
    { KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   },
    { KC_LCTL, KC_F13 , KC_LALT, KC_F14 , KC_SPC , KC_SPC }
}
};

 //   { KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   },
 //   { KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   },
 //   { KC_F15 , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   },
 //   { KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   },
 //   { KC_LCTL, KC_F13 , KC_LALT, KC_F14 , KC_SPC , KC_SPC }      