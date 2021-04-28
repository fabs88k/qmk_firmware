/* Copyright 2019 Yiancar
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

uint8_t led_state = 1;

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  XCODE = SAFE_RANGE,
  ANDROID,
  CHROME,
  TEAMS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( /* Base */
    XCODE,  ANDROID,  CHROME,  TEAMS \
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case XCODE:
      if (record->event.pressed) {
        // open Xcode via spotlight
        SEND_STRING(SS_DOWN(X_LCMD) SS_TAP(X_SPACE) SS_UP(X_LCMD) "xcode" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case ANDROID:
      if (record->event.pressed) {
        // open Android Studio via spotlight
        SEND_STRING(SS_DOWN(X_LCMD) SS_TAP(X_SPACE) SS_UP(X_LCMD) "android studio" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
    case CHROME:
      if (record->event.pressed) {
        // open Chrome via spotlight
        SEND_STRING(SS_DOWN(X_LCMD) SS_TAP(X_SPACE) SS_UP(X_LCMD) "chrome" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
    case TEAMS:
      if (record->event.pressed) {
        // open Microsoft Teams via spotlight
        SEND_STRING(SS_DOWN(X_LCMD) SS_TAP(X_SPACE) SS_UP(X_LCMD) "microsoft teams" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {
  setPinOutput(F6);
  writePinLow(F6);
}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
