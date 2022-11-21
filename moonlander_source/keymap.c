#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_korean.h"
#include "keymap_bepo.h"
#include "keymap_italian.h"
#include "keymap_slovenian.h"
#include "keymap_lithuanian_azerty.h"
#include "keymap_danish.h"
#include "keymap_norwegian.h"
#include "keymap_portuguese.h"
#include "keymap_contributions.h"
#include "keymap_czech.h"
#include "keymap_romanian.h"
#include "keymap_russian.h"
#include "keymap_uk.h"
#include "keymap_estonian.h"
#include "keymap_belgian.h"
#include "keymap_us_international.h"
#include "keymap_croatian.h"
#include "keymap_turkish_q.h"
#include "keymap_slovak.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define SE_SECT_MAC ALGR(KC_6)
#define MOON_LED_LEVEL LED_LEVEL

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  KC_MISSION_CONTROL,
  KC_SPOTLIGHT,
  KC_DICTATION,
  KC_DO_NOT_DISTURB,
  KC_LOCK_SCREEN,
};
#define KC_MCTL KC_MISSION_CONTROL
#define KC_SPLT KC_SPOTLIGHT
#define KC_SIRI KC_DICTATION
#define KC_DOND KC_DO_NOT_DISTURB
#define KC_LOCK KC_LOCK_SCREEN

#define HCS(report) host_consumer_send(record->event.pressed ? report : 0); return false
#define HSS(report) host_system_send(record->event.pressed ? report : 0); return false


enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_ESCAPE,                                      KC_DELETE,      KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_LEFT,                                        KC_UP,          KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_EQUAL,       
    KC_LBRACKET,    KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_RIGHT,                                                                       KC_DOWN,        KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_QUOTE,       
    KC_RBRACKET,    KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_BSLASH,      
    KC_CAPSLOCK,    KC_LCTRL,       KC_LALT,        KC_LGUI,        KC_LSHIFT,      OSL(1),                                                                                                         OSL(1),         KC_RSHIFT,      KC_RGUI,        KC_RALT,        KC_RCTRL,       KC_CAPSLOCK,    
    KC_SPACE,       KC_TAB,         TD(DANCE_0),                    TD(DANCE_1),    KC_BSPACE,      KC_ENTER
  ),
  [1] = LAYOUT_moonlander(
    KC_MINUS,       KC_0,           KC_9,           KC_8,           KC_7,           KC_6,           KC_DELETE,                                      KC_ESCAPE,      KC_5,           KC_4,           KC_3,           KC_2,           KC_1,           KC_GRAVE,       
    KC_EQUAL,       KC_P,           KC_O,           KC_I,           KC_U,           KC_Y,           KC_UP,                                          KC_LEFT,        KC_T,           KC_R,           KC_E,           KC_W,           KC_Q,           KC_TAB,         
    KC_QUOTE,       KC_SCOLON,      KC_L,           KC_K,           KC_J,           KC_H,           KC_DOWN,                                                                        KC_RIGHT,       KC_G,           KC_F,           KC_D,           KC_S,           KC_A,           KC_LBRACKET,    
    KC_BSLASH,      KC_SLASH,       KC_DOT,         KC_COMMA,       KC_M,           KC_N,                                           KC_B,           KC_V,           KC_C,           KC_X,           KC_Z,           KC_RBRACKET,    
    KC_TRANSPARENT, KC_RCTRL,       KC_RALT,        KC_RGUI,        KC_RSHIFT,      KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_LSHIFT,      KC_LGUI,        KC_LALT,        KC_LCTRL,       KC_TRANSPARENT, 
    KC_ENTER,       KC_BSPACE,      KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TAB,         KC_SPACE
  ),
  [2] = LAYOUT_moonlander(
    KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,          MOON_LED_LEVEL,                                 KC_SYSTEM_POWER,KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         
    KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_MCTL,    KC_SPLT,        KC_SIRI,        KC_DOND,        KC_PGUP,                                        KC_HOME,        KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,
    RGB_SPI,        RGB_HUI,        KC_NO,          KC_UP,          KC_NO,          RGB_SAI,        KC_PGDOWN,                                                                      KC_END,         RGB_VAI,        KC_MS_BTN1,     KC_MS_UP,       KC_MS_BTN2,     KC_TRANSPARENT, AU_TOG,         
    RGB_SPD,        RGB_HUD,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       RGB_SAD,                                        RGB_VAD,        KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    MU_MOD,         MU_TOG,         
    TO(0),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, OSL(3),                                                                                                         OSL(3),         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    TOGGLE_LAYER_COLOR,RGB_TOG,        KC_TRANSPARENT,                 KC_TRANSPARENT, RGB_SLD,        RGB_MOD
  ),
  [3] = LAYOUT_moonlander(
    KC_F12,         KC_F11,         KC_F10,         KC_F9,          KC_F8,          KC_F7,          KC_SYSTEM_POWER,                                MOON_LED_LEVEL, KC_F6,          KC_F5,          KC_F4,          KC_F3,          KC_F2,          KC_F1,          
    KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,  KC_MEDIA_NEXT_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_PREV_TRACK,KC_HOME,                                        KC_PGUP,        KC_DOND, KC_SIRI, KC_SPLT, KC_MCTL,    KC_BRIGHTNESS_UP,KC_BRIGHTNESS_DOWN,
    AU_TOG,         KC_TRANSPARENT, KC_MS_BTN2,     KC_MS_UP,       KC_MS_BTN1,     RGB_VAI,        KC_END,                                                                         KC_PGDOWN,      RGB_SAI,        KC_NO,          KC_UP,          KC_NO,          RGB_HUI,        RGB_SPI,        
    MU_TOG,         MU_MOD,         KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    RGB_VAD,                                        RGB_SAD,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       RGB_HUD,        RGB_SPD,        
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(0),          
    RGB_MOD,        RGB_SLD,        KC_TRANSPARENT,                 KC_TRANSPARENT, RGB_TOG,        TOGGLE_LAYER_COLOR
  ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case KC_MISSION_CONTROL:
      HCS(0x29F);
    case KC_SPOTLIGHT:
      HCS(0x221);
    case KC_DICTATION:
      HCS(0xCF);
    case KC_DO_NOT_DISTURB:
      HSS(0x9B);
    case KC_LOCK_SCREEN:
      HCS(0x19E);
  }
  return true;
}

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[2];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);

void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_HOLD: layer_on(2); break;
        case DOUBLE_TAP: layer_move(2); break;
    }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_HOLD: layer_off(2); break;
    }
    dance_state[0].step = 0;
}
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);

void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_HOLD: layer_on(2); break;
        case DOUBLE_TAP: layer_move(2); break;
    }
}

void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_HOLD: layer_off(2); break;
    }
    dance_state[1].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_1_finished, dance_1_reset),
};

