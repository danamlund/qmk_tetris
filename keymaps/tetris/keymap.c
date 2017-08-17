#include "tada68.h"
#include "tetris_text.h"

#define _MA 0
#define _GA 1
#define _FL 2
#define _AR 3
#define _LO 4
#define _UL 5

#define TRNS KC_TRNS
#define trigger_time 400
#define LSHIFT OSM(MOD_LSFT)
#define SPACE LT(_AR, KC_SPC)
#define GRAVE_MODS  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT)|MOD_BIT(KC_LGUI)|MOD_BIT(KC_RGUI)|MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT))

enum emoticons {
	LENNY = SAFE_RANGE,
	DWNHRT,
	SHRUG
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _MA: Main Layer, Default
   * ,----------------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |P/P |
   * |----------------------------------------------------------------| 
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
   * |----------------------------------------------------------------|
   * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgUp|
   * |----------------------------------------------------------------|
   * |Shft|End|  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|PgDn|
   * |----------------------------------------------------------------|
   * |Ctrl|Win |Alt |        Space          |Alt|Ctrl| FN|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[_MA] = KEYMAP_ANSI(
  F(0),		KC_1, 		KC_2, 		KC_3, 		KC_4, 		KC_5, 		KC_6, 		KC_7, 		KC_8, 		KC_9, 		KC_0, 		KC_MINS, 	KC_EQL,		KC_BSPC,	KC_MPLY, \
  KC_TAB,	KC_Q, 		KC_W, 		KC_E, 		KC_R, 		KC_T, 		KC_Y, 		KC_U, 		KC_I,  		KC_O,  		KC_P, 		KC_LBRC,	KC_RBRC,	KC_BSLS,	KC_DEL, \
  KC_CAPS,	KC_A, 		KC_S,   	KC_D, 		KC_F, 		KC_G, 		KC_H, 		KC_J, 		KC_K,  		KC_L,  		KC_SCLN, 	KC_QUOT,  				KC_ENT,		KC_PGUP, \
  LSHIFT, 	TRNS,		KC_Z, 		KC_X,   	KC_C, 		KC_V, 		KC_B, 		KC_N, 		KC_M, 		KC_COMM, 	KC_DOT,		KC_SLSH, 	KC_RSFT,    KC_UP,		KC_PGDN, \
  KC_LCTL, 	KC_LGUI, 	KC_LALT,							SPACE,											KC_RALT,	KC_RCTRL, 	MO(_FL),	KC_LEFT, 	KC_DOWN, 	KC_RGHT),
  
  /* Keymap _FL: Function Layer
   * ,----------------------------------------------------------------.
   * |~` | F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Reset  |Prsc|
   * |----------------------------------------------------------------|
   * |     |MbL|MsU|MbR|   |Tet|   |   |   |   |   |   |   |     |_LO |
   * |----------------------------------------------------------------|
   * |      |MsL|MsD|MsR|   |_GA|   |   |   |   |   |   |        |Hme |
   * |----------------------------------------------------------------|
   * |    |   |   |   |   |   |   |   |   |VoU|VoD|Mut|      |MwU|End |
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |MwL|MwD|MwR |  
   * `----------------------------------------------------------------'
   */
[_FL] = KEYMAP_ANSI(
  KC_GRV,	KC_F1,		KC_F2,  	KC_F3,  	KC_F4,  	KC_F5,		KC_F6,		KC_F7, 		KC_F8,		KC_F9,		KC_F10,  	KC_F11,		KC_F12,		RESET,		KC_PSCR, \
  TRNS, 	KC_BTN1,	KC_MS_U,  	KC_BTN2, 	TRNS, 		F(1), 		TRNS,		TRNS, 		TRNS, 		TRNS, 		TRNS, 		TRNS,		TRNS,		TRNS,		TO(_LO), \
  TRNS, 	KC_MS_L,	KC_MS_D, 	KC_MS_R,	TRNS,		TG(_GA),	TRNS,		TRNS,		TRNS,		TRNS,		TRNS,		TRNS,					TRNS,		KC_HOME, \
  TRNS, 	TRNS,		TRNS,		TRNS,		TRNS,	 	TRNS, 		TRNS, 		TRNS,		TRNS,		KC_VOLD,	KC_VOLU,	KC_MUTE,	TRNS,		KC_WH_U,	KC_END, \
  TRNS, 	TRNS, 		TRNS,								M(13),											TRNS,		TRNS,		TRNS,   	KC_WH_L,	KC_WH_D, 	KC_WH_R),

  /* Keymap _AR: Arrow layer
   * ,----------------------------------------------------------------.
   * |~` | F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|       |    |
   * |----------------------------------------------------------------|
   * |Lenny|   |   |   |   |   |   |   |   |   |   |   |   |     |    |
   * |----------------------------------------------------------------|
   * |Dwnhrt|   |   |   |   |   |Lft|Dwn| Up|Rgt|   |   |        |    |
   * |----------------------------------------------------------------|
   * |Shrg|   |   |   |   |   |   |   |   |   |   |   |      |   |    |
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |   |   |    |
   * `----------------------------------------------------------------'
   */
[_AR] = KEYMAP_ANSI(
 KC_GRV,	KC_F1,		KC_F2,  	KC_F3,  	KC_F4,  	KC_F5,		KC_F6,		KC_F7, 		KC_F8,		KC_F9,		KC_F10,  	KC_F11,		KC_F12,		TRNS,		TRNS, \
  LENNY,	TRNS, 		TRNS, 		TRNS, 		M(14), 		TRNS, 		TRNS, 		TRNS, 		TRNS,  		TRNS,  		TRNS, 		TRNS,		TRNS,		TRNS,		TRNS, \
  DWNHRT,	TRNS, 		TRNS,   	TRNS, 		TRNS, 		TRNS, 		KC_LEFT, 	KC_DOWN, 	KC_UP,  	KC_RGHT,  	TRNS, 		TRNS, 	 				TRNS,		TRNS, \
  SHRUG, 	TRNS,   	TRNS,		TRNS,		TRNS,		TRNS,	 	TRNS, 		TRNS, 		TRNS, 		TRNS, 		TRNS,		TRNS, 		TRNS,   	TRNS,		TRNS, \
  TRNS, 	TRNS, 		TRNS,								TRNS,											TRNS,		TRNS, 		M(0),		TRNS, 		TRNS, 		TRNS),

  /* Keymap _GA: Game layer
   * ,----------------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |P/P |
   * |----------------------------------------------------------------| 
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
   * |----------------------------------------------------------------|
   * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgUp|
   * |----------------------------------------------------------------|
   * |Shft|End|  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|PgDn|
   * |----------------------------------------------------------------|
   * |Ctrl|Win |Alt |        Space          |Alt|Ctrl| FN|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[_GA] = KEYMAP_ANSI(
  KC_ESC,	KC_1, 		KC_2, 		KC_3, 		KC_4, 		KC_5, 		KC_6, 		KC_7, 		KC_8, 		KC_9, 		KC_0, 		KC_MINS, 	KC_EQL,		KC_BSPC,	KC_MPLY, \
  KC_TAB,	KC_Q, 		KC_W, 		KC_E, 		KC_R, 		KC_T, 		KC_Y, 		KC_U, 		KC_I,  		KC_O,  		KC_P, 		KC_LBRC,	KC_RBRC,	KC_BSLS,	KC_DEL, \
  KC_CAPS,	KC_A, 		KC_S,   	KC_D, 		KC_F, 		KC_G, 		KC_H, 		KC_J, 		KC_K,  		KC_L,  		KC_SCLN, 	KC_QUOT,  				KC_ENT,		KC_PGUP, \
  KC_LSFT, 	TRNS,		KC_Z, 		KC_X,   	KC_C, 		KC_V, 		KC_B, 		KC_N, 		KC_M, 		KC_COMM, 	KC_DOT,		KC_SLSH, 	KC_RSFT,    KC_UP,		KC_PGDN, \
  KC_LCTL, 	KC_LGUI, 	KC_LALT,							KC_SPC,											KC_RALT,	KC_RCTRL, 	MO(_FL),	KC_LEFT, 	KC_DOWN, 	KC_RGHT),

  /* Keymap _UL: Unlock layer
   * ,----------------------------------------------------------------.
   * |   |   |   |   |   |   |   |   |   |   |   |   |   |       |    |
   * |----------------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |_MA |
   * |----------------------------------------------------------------|
   * |      |   |   |   |   |   |   |   |   |   |   |   |        |    |
   * |----------------------------------------------------------------|
   * |    |   |   |   |   |   |   |   |   |   |   |   |      |   |    |
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |   |   |    |
   * `----------------------------------------------------------------'
   */
[_UL] = KEYMAP_ANSI(
  KC_NO,	KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO,  	KC_NO, 		KC_NO, 		KC_NO,  	KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, \
  KC_NO, 	KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO,  	KC_NO, 		KC_NO,  	KC_NO, 		TO(_MA), \
  KC_NO, 	KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 					KC_NO, 		KC_NO, \
  KC_NO, 	KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, \
  KC_NO, 	KC_NO, 		KC_NO,    							KC_NO,											KC_NO, 		KC_NO, 		TRNS, 		KC_NO, 		KC_NO, 		KC_NO),

  /* Keymap _LO: Lock layer
   * ,----------------------------------------------------------------.
   * |   |   |   |   |   |   |   |   |   |   |   |   |   |       |    |
   * |----------------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |    |
   * |----------------------------------------------------------------|
   * |      |   |   |   |   |   |   |   |   |   |   |   |        |    |
   * |----------------------------------------------------------------|
   * |    |   |   |   |   |   |   |   |   |   |   |   |      |   |    |
   * |----------------------------------------------------------------|
   * |    |    |    |                      |   |   | _UL |   |   |    |
   * `----------------------------------------------------------------'
   */
[_LO] = KEYMAP_ANSI(
  KC_NO,	KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO,  	KC_NO, 		KC_NO, 		KC_NO,  	KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, \
  KC_NO, 	KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO,  	KC_NO, 		KC_NO,  	KC_NO, 		KC_NO, \
  KC_NO, 	KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 					KC_NO, 		KC_NO, \
  KC_NO, 	KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, \
  KC_NO, 	KC_NO, 		KC_NO,    							KC_NO,											KC_NO, 		KC_NO, 		MO(_UL), 	KC_NO, 		KC_NO, 		KC_NO),
};

void tap(uint16_t keycode){
    register_code(keycode);
    unregister_code(keycode);
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch (id) {
		case 0:
			if (record->event.pressed) {
				SEND_STRING("AdminF123!");
			}
			break;
	}
    return MACRO_NONE;
};

void led_set_user(uint8_t usb_led) {
	if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        // Turn capslock on
        PORTB |= (1<<6);
    } else {
        // Turn capslock off
        PORTB &= ~(1<<6);
    }
}

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_FUNCTION(0),  // Calls action_function()
  [1] = ACTION_FUNCTION(1)
};

static uint8_t tetris_key_presses = 0;
static uint16_t tetris_timer = 0;
static uint8_t tetris_running = 0;
static int tetris_keypress = 0;

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch (id) {
  case 1:
    if (record->event.pressed) {
        tetris_running = 1;
        tetris_timer = 0;
        tetris_keypress = 0;
        // set randomness using total number of key presses
        tetris_start(tetris_key_presses);
    }
    break;
  }
}

/*
 * Set up tetris
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    tetris_key_presses++;
  }

  if (tetris_running && record->event.pressed) {
    tetris_keypress = 0;
    switch (keycode) {
    case KC_UP: tetris_keypress = 1; break;
    case KC_LEFT: tetris_keypress = 2; break;
    case KC_DOWN: tetris_keypress = 3; break;
    case KC_RIGHT: tetris_keypress = 4; break;
    case KC_ESC: tetris_running = 0; return false; // ESC stops tetris
    }
    if (tetris_keypress != 0) {
      return false;
    }
  }

  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
}


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
  if (tetris_running) {
    tetris_timer++;
    if (tetris_timer > 1000) {
      // every 1000 times this is run is about 100 ms.
      if (!tetris_tick(100)) {
        // game over
        tetris_running = 0;
      }
      tetris_timer = 0;
    }
  }
	uint8_t layer = biton32(layer_state);
	
	switch(layer) {
		case 1:
			led[0].r = 255;
			led[0].g = 0;
			led[0].b = 0;
			ws2812_setleds(led, 1);
			break;
	}
}

void send_keycode(uint16_t keycode) {
  register_code(keycode);
  unregister_code(keycode);
}

void send_keycode_shift(uint16_t keycode) {
  register_code(KC_LSFT);
  register_code(keycode);
  unregister_code(keycode);
  unregister_code(KC_LSFT);
}

void tetris_send_up(void) {
  send_keycode(KC_UP);
}
void tetris_send_left(void) {
  send_keycode(KC_LEFT);
}
void tetris_send_down(void) {
  send_keycode(KC_DOWN);
}
void tetris_send_right(void) {
  send_keycode(KC_RGHT);
}

void tetris_send_backspace(void) {
  send_keycode(KC_BSPC);
}
void tetris_send_delete(void) {
  send_keycode(KC_DEL);
}

void tetris_send_string(const char *s) {
  for (int i = 0; s[i] != 0; i++) {
    if (s[i] >= 'a' && s[i] <= 'z') {
      send_keycode(KC_A + (s[i] - 'a'));
    } else if (s[i] >= 'A' && s[i] <= 'Z') {
      send_keycode_shift(KC_A + (s[i] - 'A'));
    } else if (s[i] >= '1' && s[i] <= '9') {
      send_keycode(KC_1 + (s[i] - '1'));
    } else {
      switch (s[i]) {
      case ' ': send_keycode(KC_SPACE); break;
      case '.': send_keycode(KC_DOT); break;
      case '0': send_keycode(KC_0); break;
      }
    }
  }
}

void tetris_send_newline(void) {
  send_keycode(KC_ENT);
}

int tetris_get_keypress(void) {
  int out = tetris_keypress;
  tetris_keypress = 0;
  return out;
}
