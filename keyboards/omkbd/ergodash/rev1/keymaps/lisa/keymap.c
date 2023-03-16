#include QMK_KEYBOARD_H
#include "macros.h"

enum layer_names {
    _QWERTY,
		_FN,
		_MACRO
};

enum custom_keycodes {
    M_ESC = SAFE_RANGE,
    M_1,
    M_2,
};

#define LCtlBrc LCTL_T(KC_LBRC)
#define LCmdCbr LCMD_T(KC_LCBR)
#define LSftPrn LSFT_T(KC_LPRN)

#define RCtlBrc RCTL_T(KC_RBRC)
#define RCmdCbr RCMD_T(KC_RCBR)
#define RSftPrn RSFT_T(KC_RPRN)

#define FN_Spc LT(_FN, KC_SPC)
#define FN_Bspc LT(_FN, KC_BSPC)
#define Sleep LCTL(LCMD(KC_Q))
#define WinUp LCTL(LOPT(KC_UP))
#define WinDown LCTL(LOPT(KC_DOWN))
#define WinLeft LCTL(LOPT(KC_LEFT))
#define WinRight LCTL(LOPT(KC_RIGHT))
#define WinMax LCTL(LOPT(KC_ENT))
#define SpaceLeft LCTL(KC_LEFT)
#define SpaceRight LCTL(KC_RIGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY]=LAYOUT_3key_2us(
	  KC_ESC,  KC_1,      KC_2,       KC_3,     KC_4,    KC_5,    KC_UNDS, /**/     /**/ /**/     Sleep,   KC_6,    KC_7,       KC_8,    KC_9,     KC_0,       KC_MINS,
		KC_GRV,  KC_Q,      KC_W,       KC_E,     KC_R,    KC_T,    LCtlBrc, /**/     /**/ /**/     RCtlBrc, KC_Y,    KC_U,       KC_I,    KC_O,     KC_P,       KC_EQL,
		KC_VOLU, KC_A,      KC_S,       KC_D,     KC_F,    KC_G,    KC_TAB,  /**/     /**/ /**/     KC_ENT,  KC_H,    KC_J,       KC_K,    KC_L,     KC_COLN,    KC_QUOT,
		KC_VOLD, KC_Z,      KC_X,       KC_C,     KC_V,    KC_B,    /**/     /**/     /**/ /**/     /**/     KC_N,    KC_M,       KC_COMM, KC_DOT,   KC_SLSH,    KC_MINS,
		KC_MUTE, KC_HOME,   KC_END,     /**/      KC_LOPT, LCmdCbr, FN_Bspc, LSftPrn, /**/ RSftPrn, FN_Spc,  RCmdCbr, MO(_MACRO), /**/     KC_PGUP,  KC_PGDN,    KC_BSLS
  ),
	[_FN]=LAYOUT_3key_2us(
	  KC_NO,   KC_F1,     KC_F2,      KC_F3,    KC_F4,   KC_F5,   KC_NO,   /**/     /**/ /**/     KC_NO,   KC_F6,   KC_F7,      KC_F8,   KC_F9,    KC_F10,     KC_F11,
		KC_NO,   KC_NO,     KC_NO,      KC_NO,    KC_NO,   KC_NO,   KC_NO,   /**/     /**/ /**/     KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_NO,    KC_NO,      KC_F12,
		KC_BRMU, WinLeft,   KC_NO,      WinRight, KC_NO,   KC_NO,   KC_NO,   /**/     /**/ /**/     WinMax,  KC_LEFT, KC_DOWN,    KC_UP,   KC_RIGHT, KC_NO,      KC_NO,
		KC_BRMD, KC_NO,     KC_NO,      KC_NO,    KC_NO,   KC_NO,   /**/     /**/     /**/ /**/     /**/     KC_NO,   KC_NO,      KC_VOLD, KC_VOLU,  KC_KB_MUTE, KC_NO,
		KC_NO,   SpaceLeft, SpaceRight, /**/      KC_NO,   KC_NO,   KC_NO,   KC_NO,   /**/ KC_NO,   KC_NO,   KC_NO,   KC_NO,      /**/     KC_NO,    KC_NO,      MO(_MACRO)
	),
	[_MACRO]=LAYOUT_3key_2us(
	  M_ESC,   M_1,       M_2,        KC_NO,    KC_NO,   KC_NO,   DM_PLY1, /**/     /**/ /**/     DM_REC1, KC_NO,   KC_NO,      KC_NO,   KC_NO,    KC_NO,      KC_NO,
		KC_NO,   KC_NO,     KC_NO,      KC_NO,    KC_NO,   KC_NO,   DM_PLY2, /**/     /**/ /**/     DM_REC2, KC_NO,   KC_NO,      KC_NO,   KC_NO,    KC_NO,      KC_NO,
		KC_NO,   KC_NO,     KC_NO,      KC_NO,    KC_NO,   KC_NO,   KC_NO,   /**/     /**/ /**/     DM_RSTP, KC_NO,   KC_NO,      KC_NO,   KC_NO,    KC_NO,      KC_NO,
		KC_NO,   KC_NO,     KC_NO,      KC_NO,    KC_NO,   KC_NO,   /**/     /**/     /**/ /**/     /**/     KC_NO,   KC_NO,      KC_NO,   KC_NO,    KC_NO,      KC_NO,
		KC_NO,   KC_NO,     KC_NO,      /**/      KC_NO,   KC_NO,   KC_NO,   KC_NO,   /**/ KC_NO,   KC_NO,   KC_NO,   KC_NO,      /**/     KC_NO,    KC_NO,      KC_NO
	)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LSftPrn: // Convert 9 to ( (Mod tap doesn't support shift)
			if (record->tap.count && record->event.pressed) {
				tap_code16(KC_LPRN);
				return false;
			}
			break;
    case RSftPrn: // Convert 0 to ) (Mod tap doesn't support shift)
			if (record->tap.count && record->event.pressed) {
				tap_code16(KC_RPRN);
				return false;
			}
			break;
    case LCmdCbr: // Convert [ to { (Mod tap doesn't support shift)
			if (record->tap.count && record->event.pressed) {
				tap_code16(KC_LCBR);
				return false;
			}
			break;
    case RCmdCbr: // Convert ] to } (Mod tap doesn't support shift)
			if (record->tap.count && record->event.pressed) {
				tap_code16(KC_RCBR);
				return false;
			}
			break;
    case M_ESC:
      if (record->event.pressed) {
        MACRO_ESC;
      }
      break;
    case M_1:
      if (record->event.pressed) {
        MACRO_1;
      }
      break;
    case M_2:
      if (record->event.pressed) {
        MACRO_2;
      }
      break;
	}
	return true;
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case FN_Spc:
						// Do not select the hold action when another key is tapped. Allows fast typing with space.
            return false;
        default:
						// Immediately select the hold action when another key is tapped. Allows quick keyboard shortcuts.
            return true;
    }
}

const uint16_t PROGMEM kj[] = {KC_K, KC_J, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(kj, KC_ESC),
};

