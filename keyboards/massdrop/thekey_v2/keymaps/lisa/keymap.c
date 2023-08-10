/* Copyright 2022 Jason Wihardja
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

#include QMK_KEYBOARD_H

/* Google Meet Shortcuts */
#define PUSH_TO_TALK KC_SPC
#define TOGGLE_HAND LCTL(LGUI(KC_H))
#define TOGGLE_CAMERA LGUI(KC_E)
#define TOGGLE_MIC LGUI(KC_D)
#define TOGGLE_CHAT LCTL(LGUI(KC_C))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = LAYOUT(PUSH_TO_TALK, TOGGLE_CHAT,   MO(1)),
	[1] = LAYOUT(TOGGLE_MIC,   TOGGLE_CAMERA, KC_TRNS),

};
