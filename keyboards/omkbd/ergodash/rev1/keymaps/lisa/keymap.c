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

#undef LAYOUT
#define LAYOUT LAYOUT_3key_2us

#define LCtlBrc LCTL_T(KC_LBRC)
#define LCmdCbr LCMD_T(KC_LCBR)
#define LSftPrn LSFT_T(KC_LPRN)
#define RCtlBrc RCTL_T(KC_RBRC)
#define RCmdCbr RCMD_T(KC_RCBR)
#define RSftPrn RSFT_T(KC_RPRN)

#define FN_Spc LT(_FN, KC_SPC)
#define FN_Bspc LT(_FN, KC_BSPC)

#define Sleep LCTL(LCMD(KC_Q))
#define WinUp LCTL(LOPT(KC_W))
#define WinDown LCTL(LOPT(KC_X))
#define WinLeft LCTL(LOPT(KC_A))
#define WinRight LCTL(LOPT(KC_D))
#define WinUL LCTL(LOPT(KC_Q))
#define WinUR LCTL(LOPT(KC_E))
#define WinDL LCTL(LOPT(KC_Z))
#define WinDR LCTL(LOPT(KC_C))
#define WinL2T LCTL(LOPT(KC_Y))
#define WinLT LCTL(LOPT(KC_U))
#define WinCT LCTL(LOPT(KC_I))
#define WinRT LCTL(LOPT(KC_O))
#define WinR2T LCTL(LOPT(KC_P))
#define WinMax LCTL(LOPT(KC_ENT))

#define SpaceLeft LCTL(KC_LEFT)
#define SpaceRight LCTL(KC_RIGHT)

#define HYPR_MUTE HYPR_T(KC_MUTE)

#define DCD LCTL(KC_RBRC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY]=LAYOUT(
    KC_ESC,    KC_1,      KC_2,       KC_3,     KC_4,    KC_5,    KC_UNDS, /**/     /**/ /**/     Sleep,   KC_6,    KC_7,       KC_8,    KC_9,     KC_0,       KC_MINS,
    KC_GRV,    KC_Q,      KC_W,       KC_E,     KC_R,    KC_T,    LCtlBrc, /**/     /**/ /**/     RCtlBrc, KC_Y,    KC_U,       KC_I,    KC_O,     KC_P,       KC_EQL,
    KC_VOLU,   KC_A,      KC_S,       KC_D,     KC_F,    KC_G,    KC_TAB,  /**/     /**/ /**/     KC_ENT,  KC_H,    KC_J,       KC_K,    KC_L,     KC_SCLN,    KC_QUOT,
    KC_VOLD,   KC_Z,      KC_X,       KC_C,     KC_V,    KC_B,    /**/     /**/     /**/ /**/     /**/     KC_N,    KC_M,       KC_COMM, KC_DOT,   KC_SLSH,    KC_MINS,
    HYPR_MUTE, KC_HOME,   KC_END,     /**/      KC_LOPT, LCmdCbr, FN_Bspc, LSftPrn, /**/ RSftPrn, FN_Spc,  RCmdCbr, MO(_MACRO), /**/     KC_PGUP,  KC_PGDN,    KC_BSLS
  ),
  [_FN]=LAYOUT(
    KC_NO,     KC_F1,     KC_F2,      KC_F3,    KC_F4,   KC_F5,   KC_NO,   /**/     /**/ /**/     KC_NO,   KC_F6,   KC_F7,      KC_F8,   KC_F9,    KC_F10,     KC_F11,
    KC_NO,     WinUL,     WinUp,      WinUR,    KC_NO,   KC_NO,   KC_TRNS, /**/     /**/ /**/     KC_TRNS, WinL2T,  WinLT,      WinCT,   WinRT,    WinR2T,     KC_F12,
    KC_BRMU,   WinLeft,   KC_NO,      WinRight, KC_NO,   KC_NO,   KC_NO,   /**/     /**/ /**/     WinMax,  KC_LEFT, KC_DOWN,    KC_UP,   KC_RIGHT, KC_NO,      KC_NO,
    KC_BRMD,   WinDL,     WinDown,    WinDR,    KC_NO,   KC_NO,   /**/     /**/     /**/ /**/     /**/     KC_NO,   KC_NO,      KC_VOLD, KC_VOLU,  KC_KB_MUTE, KC_NO,
    KC_NO,     SpaceLeft, SpaceRight, /**/      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /**/ KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,      /**/     KC_NO,    KC_NO,      MO(_MACRO)
  ),
  [_MACRO]=LAYOUT(
    M_ESC,     M_1,       M_2,        KC_NO,    KC_NO,   KC_NO,   DM_PLY1, /**/     /**/ /**/     DM_REC1, KC_NO,   KC_NO,      KC_NO,   KC_NO,    KC_NO,      KC_NO,
    KC_NO,     KC_NO,     KC_NO,      KC_NO,    KC_NO,   KC_NO,   DM_PLY2, /**/     /**/ /**/     DM_REC2, KC_NO,   KC_NO,      KC_NO,   KC_NO,    KC_NO,      KC_NO,
    KC_NO,     KC_NO,     KC_NO,      KC_NO,    KC_NO,   KC_NO,   KC_NO,   /**/     /**/ /**/     DM_RSTP, KC_NO,   KC_NO,      KC_NO,   KC_NO,    KC_NO,      KC_NO,
    KC_NO,     KC_NO,     KC_NO,      KC_NO,    KC_NO,   KC_NO,   /**/     /**/     /**/ /**/     /**/     KC_NO,   KC_NO,      KC_NO,   KC_NO,    KC_NO,      KC_NO,
    KC_NO,     KC_NO,     KC_NO,      /**/      KC_NO,   KC_NO,   KC_NO,   KC_NO,   /**/ KC_NO,   KC_NO,   KC_NO,   KC_NO,      /**/     KC_NO,    KC_NO,      KC_NO
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
    case FN_Bspc:
      return false; // Do not select the hold action when another key is tapped. Allows fast typing with space/backspace.
    default: return true; // Immediately select the hold action when another key is tapped. Allows quick keyboard shortcuts.
  }
}

const uint16_t PROGMEM kj[] = {KC_K, KC_J, COMBO_END};
const uint16_t PROGMEM df[] = {KC_D, KC_F, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
  COMBO(kj, KC_ESC),
  COMBO(df, DCD),
};

#define MOD_MASK_NONE 0
const key_override_t semicolon_override = ko_make_basic(MOD_MASK_SHIFT, KC_SCLN, KC_SCLN);
const key_override_t colon_override = ko_make_basic(MOD_MASK_NONE, KC_SCLN, KC_COLON);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
	&semicolon_override,
  &colon_override,
	NULL // Null terminate the array of overrides!
};
