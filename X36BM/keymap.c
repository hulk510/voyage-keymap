#include QMK_KEYBOARD_H

// =====================================================================
// Layer 0 - Base (QWERTY + Home Row Mods GACS)
// Layer 1 - Symbols + Numpad (Space hold)
// Layer 2 - Navigation + F-keys + Media (Bspc hold)
// Layer 3 - System (MO(3) hold)
// =====================================================================

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // Layer 0 - Base
    // ,------+------+------+------+------+------.  ,------+------+------+------+------+------.
    // |  =   |  1   |  2   |  3   |  4   |  5   |  |  6   |  7   |  8   |  9   |  0   | Del  |
    // |------+------+------+------+------+------|  |------+------+------+------+------+------|
    // |  `   |  Q   |  W   |  E   |  R   |  T   |  |  Y   |  U   |  I   |  O   |  P   |  \   |
    // |------+------+------+------+------+------|  |------+------+------+------+------+------|
    // | Esc  |A/Gui |S/Alt |D/Ctl |F/Sft |  G   |  |  H   |J/Sft |K/Ctl |L/Alt |;/Gui |  -   |
    // |------+------+------+------+------+------|  |------+------+------+------+------+------|
    // | MO(3)|  Z   |  X   |  C   |  V   |  B   |  |  N   |  M   |  ,   |  .   |  /   |  '   |
    // `------+------+------+------+------+------'  `------+------+------+------+------+------'
    //                       | Spc/L1|Tab/Ctl|        |Ent/Sft|Bspc/L2|
    //                       `-------+-------'        `-------+-------'
    [0] = LAYOUT_voyager(
        KC_EQL,   KC_1,          KC_2,          KC_3,          KC_4,          KC_5,              KC_6,    KC_7,          KC_8,          KC_9,          KC_0,             KC_DEL,
        KC_GRV,   KC_Q,          KC_W,          KC_E,          KC_R,          KC_T,              KC_Y,    KC_U,          KC_I,          KC_O,          KC_P,             KC_BSLS,
        KC_ESC,   LGUI_T(KC_A),  LALT_T(KC_S),  LCTL_T(KC_D),  LSFT_T(KC_F),  KC_G,            KC_H,    RSFT_T(KC_J),  RCTL_T(KC_K),  RALT_T(KC_L),  RGUI_T(KC_SCLN),  KC_MINS,
        MO(3),    KC_Z,          KC_X,          KC_C,          KC_V,          KC_B,              KC_N,    KC_M,          KC_COMM,       KC_DOT,        KC_SLSH,          KC_QUOT,
                                                LT(1,KC_SPC),  LCTL_T(KC_TAB),                  RSFT_T(KC_ENT), LT(2,KC_BSPC)
    ),

    // Layer 1 - Symbols + Numpad
    // ,------+------+------+------+------+------.  ,------+------+------+------+------+------.
    // |  ~   |  !   |  @   |  #   |  $   |  %   |  |  =   |  7   |  8   |  9   |  /   |      |
    // |------+------+------+------+------+------|  |------+------+------+------+------+------|
    // |  `   |  [   |  {   |  (   |  <   |  |   |  |  *   |  4   |  5   |  6   |  -   |      |
    // |------+------+------+------+------+------|  |------+------+------+------+------+------|
    // |      |  ]   |  }   |  )   |  >   |  &   |  |  +   |  1   |  2   |  3   |  .   |      |
    // |------+------+------+------+------+------|  |------+------+------+------+------+------|
    // |      |  \   |  ^   |  _   |      |      |  |  0   |  0   |  ,   |      |      |      |
    // `------+------+------+------+------+------'  `------+------+------+------+------+------'
    //                       |(hold)|      |        |      |      |
    //                       `------+------'        `------+------'
    [1] = LAYOUT_voyager(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,      KC_PERC,           KC_EQL,  KC_7,    KC_8,    KC_9,    KC_SLSH, KC_TRNS,
        KC_GRV,  KC_LBRC, KC_LCBR, KC_LPRN, S(KC_COMM),  KC_PIPE,           KC_ASTR, KC_4,    KC_5,    KC_6,    KC_MINS, KC_TRNS,
        KC_TRNS, KC_RBRC, KC_RCBR, KC_RPRN, S(KC_DOT),   KC_AMPR,           KC_PLUS, KC_1,    KC_2,    KC_3,    KC_DOT,  KC_TRNS,
        KC_TRNS, KC_BSLS, KC_CIRC, KC_UNDS, KC_TRNS,     KC_TRNS,           KC_0,    KC_0,    KC_COMM, KC_TRNS, KC_TRNS, KC_TRNS,
                                    KC_TRNS, KC_TRNS,                         KC_TRNS, KC_TRNS
    ),

    // Layer 2 - Navigation + F-keys + Media
    // ,------+------+------+------+------+------.  ,------+------+------+------+------+------.
    // |      |  F1  |  F2  |  F3  |  F4  |  F5  |  |  F6  |  F7  |  F8  |  F9  | F10  |      |
    // |------+------+------+------+------+------|  |------+------+------+------+------+------|
    // |      | F11  | F12  |VolDn |VolUp | Mute |  |      | Home | PgUp | PgDn | End  |      |
    // |------+------+------+------+------+------|  |------+------+------+------+------+------|
    // |      |      |      | Prev | Next | Play |  | Left | Down |  Up  |Right |      |      |
    // |------+------+------+------+------+------|  |------+------+------+------+------+------|
    // |      |      |      |      |      |      |  |      |      |      |      |      |      |
    // `------+------+------+------+------+------'  `------+------+------+------+------+------'
    //                       |      |      |        |(hold)|      |
    //                       `------+------'        `------+------'
    [2] = LAYOUT_voyager(
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
        KC_TRNS, KC_F11,  KC_F12,  KC_VOLD, KC_VOLU, KC_MUTE,            KC_TRNS, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_MPLY,            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                    KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS
    ),

    // Layer 3 - System
    // ,------+------+------+------+------+------.  ,------+------+------+------+------+------.
    // |      |      |      |      |      |      |  |      |      |      |      |      |      |
    // |------+------+------+------+------+------|  |------+------+------+------+------+------|
    // |      |RGB_TG|RGB_MD|RGB_VD|RGB_VI|      |  |      |      |      |      |      |      |
    // |------+------+------+------+------+------|  |------+------+------+------+------+------|
    // |      |RGB_HI|RGB_SI|RGB_SD|RGB_SI|      |  |      |      |      |      |      |      |
    // |------+------+------+------+------+------|  |------+------+------+------+------+------|
    // |(hold)|      |      |      |      |      |  |      |      |      |      |      |CW_TG |
    // `------+------+------+------+------+------'  `------+------+------+------+------+------'
    //                       |      |      |        |      |      |
    //                       `------+------'        `------+------'
    [3] = LAYOUT_voyager(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, RGB_TOG, RGB_MOD, RGB_VAD, RGB_VAI, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, RGB_HUI, RGB_SAI, RGB_SPD, RGB_SPI, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, CW_TOGG,
                                    KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS
    ),
};

// =====================================================================
// RGB Matrix - Per-layer lighting
// All coloring handled in indicators function for reliability
// =====================================================================

void keyboard_post_init_user(void) {
    rgb_matrix_enable_noeeprom();
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t layer = get_highest_layer(layer_state | default_layer_state);

    // Layer colors (HSV)
    uint8_t h, s, v;
    switch (layer) {
        case 0: h = 200; s = 50; v = 120; break; // Lavender
        case 1: h = 0;   s = 0;  v = 140; break; // White
        case 2: h = 140; s = 60; v = 140; break; // Light blue
        case 3: h = 80;  s = 50; v = 100; break; // Light yellow-green
        default: return false;
    }
    HSV hsv = {h, s, v};
    RGB rgb = hsv_to_rgb(hsv);

    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            uint8_t led_index = g_led_config.matrix_co[row][col];
            if (led_index == NO_LED || led_index < led_min || led_index >= led_max) continue;

            if (layer == 0) {
                // Layer 0: all keys lavender
                rgb_matrix_set_color(led_index, rgb.r, rgb.g, rgb.b);
            } else {
                // Layer 1-3: active keys colored, transparent keys off
                uint16_t keycode = keymaps[layer][row][col];
                if (keycode == KC_TRANSPARENT || keycode == KC_NO) {
                    rgb_matrix_set_color(led_index, 0, 0, 0);
                } else {
                    rgb_matrix_set_color(led_index, rgb.r, rgb.g, rgb.b);
                }
            }
        }
    }
    return true; // We handle all LED coloring
}
