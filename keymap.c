#include QMK_KEYBOARD_H
#include "version.h"

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
#define MODS_SHIFT_MASK (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT))

const key_override_t comma_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COMMA);
const key_override_t scolon_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COLN, KC_SCOLON);
const key_override_t dquo_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUOTE, KC_DQUO);

const key_override_t **key_overrides = 
  (const key_override_t *[]) { 
    &comma_key_override,
    &scolon_key_override,
    &dquo_key_override,
    NULL
  };

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7,                        KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_F13, KC_F14,
    KC_QUES, KC_TRANSPARENT, KC_C, KC_F, KC_P, KC_TRANSPARENT, KC_MEH,      KC_TRANSPARENT, KC_TRANSPARENT, KC_DOT, KC_COLN, KC_QUOTE, KC_GRAVE, KC_TRANSPARENT,
    KC_MINUS, KC_Y, KC_L, KC_S, KC_T, KC_TRANSPARENT, KC_HYPR,              TG(3), KC_TRANSPARENT, KC_E, KC_A, KC_I, KC_U, KC_TRANSPARENT,
    KC_EXLM, KC_TRANSPARENT, KC_X, KC_K, KC_N, KC_TRANSPARENT,              KC_F23, KC_O, KC_COMMA, KC_DOT, KC_SCOLON, KC_DQUO,
    KC_F15, KC_F16, KC_F17, KC_F18, TG(4), LT(1, KC_SPACE),                 LT(2, KC_BSPACE), KC_TAB, KC_F20, KC_F21, KC_F22, KC_F23,
    KC_LSHIFT, KC_LCTRL, LT(4,KC_ESCAPE),                                   KC_ENTER, KC_LALT, KC_LGUI
  ),
  [1] = LAYOUT_moonlander( // LATIN SYMBOLS
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7,                   KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_F13, KC_F14,
    KC_PERC, KC_AMPR, KC_AT, KC_LCBR, KC_RCBR, KC_PIPE, KC_TRANSPARENT,                  KC_TRANSPARENT, KC_EQUAL, KC_7, KC_8, KC_9, KC_ASTR, KC_TRANSPARENT,
    KC_CIRC, KC_HASH, KC_DLR, KC_LPRN, KC_RPRN, KC_SLASH, KC_TRANSPARENT,                KC_TRANSPARENT, KC_0, KC_4, KC_5, KC_6, KC_PLUS, KC_TRANSPARENT,
    KC_TILD, KC_LABK, KC_RABK, KC_LBRACKET, KC_RBRACKET, KC_BSLASH,                      KC_UNDS, KC_1, KC_2, KC_3, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                            MO(2),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RESET,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_UP,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_MS_WH_UP,    KC_TRANSPARENT, KC_UP,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_MS_WH_DOWN,  KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,  KC_TRANSPARENT, KC_TRANSPARENT,
    KC_MS_BTN1,     KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN2
  ),
};

static bool a_hold = false;
static bool a_was_used = false;
static bool e_hold = false;
static bool e_was_used = false;
static bool i_hold = false;
static bool i_was_used = false;
static bool u_hold = false;
static bool u_was_used = false;
static bool o_hold = false;
static bool o_was_used = false;

static bool c_was_used = false;
static bool f_was_used = false;
static bool p_was_used = false;
static bool y_was_used = false;
static bool l_was_used = false;
static bool s_was_used = false;
static bool t_was_used = false;
static bool k_was_used = false;
static bool n_was_used = false;

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  switch(keycode) {

    case KC_A:
      if (record->event.pressed) {
        a_hold = true;
      } else {
        if (!a_was_used) { tap_code(KC_A); }
        a_was_used = false;
        a_hold = false;
      };
      return false;

    case KC_E:
      if (record->event.pressed) {
        e_hold = true;
      } else {
        e_hold = false;
        if (e_was_used) { e_was_used = false; }
        else { e_was_used = false; tap_code(KC_E); }
      };
      return false;

    case KC_I:
      if (record->event.pressed) {
        i_hold = true; 
      } else {
        i_hold = false;
        if (i_was_used) { i_was_used = false; }
        else { i_was_used = false; tap_code(KC_I); }
      };
      return false;

    case KC_U:
      if (record->event.pressed) { 
        u_hold = true; 
      } else {
        u_hold = false;
        if (u_was_used) { u_was_used = false; }
        else { u_was_used = false; tap_code(KC_U); }
      };
      return false;

    case KC_O:
      if (record->event.pressed) { 
        o_hold = true; 
      } else {
        o_hold = false;
        if (o_was_used) { o_was_used = false; }
        else { o_was_used = false; tap_code(KC_O); }
      };
      return false;

    case KC_C:
      if (record->event.pressed) {
        if (a_hold) { tap_code(KC_H); a_was_used = true; c_was_used = true; }
      } else { if (!c_was_used) { tap_code(KC_C); } c_was_used = false; }
      return false;

    case KC_F:
      if (record->event.pressed) {
        if (a_hold) { tap_code(KC_V); a_was_used = true; f_was_used = true; }
        else if (e_hold) { tap_code(KC_W); e_was_used = true; f_was_used = true; }
      } else { if (!f_was_used) { tap_code(KC_F); } f_was_used = false; }
      return false;

    case KC_P:
      if (record->event.pressed) {
        if (a_hold) { tap_code(KC_B); a_was_used = true; p_was_used = true; }
      } else { if (!p_was_used) { tap_code(KC_P); } p_was_used = false; }
      return false;

    case KC_Y:
      if (record->event.pressed) {
      } else {
        if (y_was_used) { y_was_used = false; }
        else { y_was_used = false; tap_code(KC_Y); }
      };
      return false;

    case KC_L:
      if (record->event.pressed) {
        if (a_hold) { tap_code(KC_R); a_was_used = true; l_was_used = true; }
      } else { if (!l_was_used) { tap_code(KC_L); } l_was_used = false; }
      return false;

    case KC_S:
      if (record->event.pressed) {
        if (a_hold) { tap_code(KC_Z); a_was_used = true; s_was_used = true; }
        else if (e_hold) { tap_code(KC_J); e_was_used = true; s_was_used = true; }
      } else { if (!s_was_used) { tap_code(KC_S); } s_was_used = false; }
      return false;

    case KC_T:
      if (record->event.pressed) {
        if (a_hold) { tap_code(KC_D); a_was_used = true; t_was_used = true; }
      } else { if (!t_was_used) { tap_code(KC_T); } t_was_used = false; }
      return false; 

    case KC_X:
      if (record->event.pressed) {}
      else { tap_code(KC_X); }
      return false;

    case KC_K:
      if (record->event.pressed) {
        if (a_hold) { tap_code(KC_G); a_was_used = true; k_was_used = true; } 
        else if (e_hold) { tap_code(KC_Q); e_was_used = true; k_was_used = true; }
      } else { if (!k_was_used) { tap_code(KC_K); } k_was_used = false; }
      return false;
    
    case KC_N:
      if (record->event.pressed) {
        if (a_hold) { tap_code(KC_M); a_was_used = true; n_was_used = true; }
      } else { 
        if (!n_was_used) { tap_code(KC_N); }
        n_was_used = false;  
      }
      return false;

    // case KC_DOT:
    //   if (record->event.pressed) {
    //     if (get_mods() & MODS_SHIFT_MASK) { tap_code(KC_COMMA); } else { tap_code(KC_DOT); }
    //   }
    //   return false;

    default: return true;
  }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255} },
};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}
