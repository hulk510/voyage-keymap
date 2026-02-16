#include QMK_KEYBOARD_H

// =====================================================================
// Layer 0 - Base (QWERTY + Home Row Mods GACS)
// Layer 1 - Symbols + Numpad (Space hold)
// Layer 2 - Navigation + F-keys + Media (Bspc hold)
// Layer 3 - System (MO(3) hold)
// =====================================================================

// Custom ripple effect: purple base + orange ripple on keypress
#define RIPPLE_COUNT 8
#define RIPPLE_DURATION 400

static struct { uint8_t x, y; uint16_t time; } ripples[RIPPLE_COUNT];
static uint8_t ripple_idx;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        uint8_t led = g_led_config.matrix_co[record->event.key.row][record->event.key.col];
        if (led != NO_LED) {
            ripples[ripple_idx].x = g_led_config.point[led].x;
            ripples[ripple_idx].y = g_led_config.point[led].y;
            ripples[ripple_idx].time = timer_read();
            ripple_idx = (ripple_idx + 1) % RIPPLE_COUNT;
        }
    }
    return true;
}

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
    // |      |      |      | LED- | LED+ |      |  |      | Scr- | Scr+ |      |      |      |
    // |------+------+------+------+------+------|  |------+------+------+------+------+------|
    // |      |      |      |SS(4) |SS(5) |      |  |      |      |      |      |      | Lock |
    // |------+------+------+------+------+------|  |------+------+------+------+------+------|
    // |(hold)|      |      |      |      |      |  |      |      |      |      |      |CW_TG |
    // `------+------+------+------+------+------'  `------+------+------+------+------+------'
    //                       |      |      |        |      |      |
    //                       `------+------'        `------+------'
    [3] = LAYOUT_voyager(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, RGB_VAD,    RGB_VAI,    KC_TRNS,            KC_TRNS, KC_BRID, KC_BRIU, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, SGUI(KC_4), SGUI(KC_5), KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LCTL(LGUI(KC_Q)),
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, CW_TOGG,
                                    KC_TRNS,    KC_TRNS,                         KC_TRNS, KC_TRNS
    ),
};

// =====================================================================
// RGB Matrix - Per-layer lighting
// Layer 0: purple base + orange ripple on keypress (custom)
// Layer 1-3: active keys only with layer color (yellow/cyan/green)
// =====================================================================

void keyboard_post_init_user(void) {
    rgb_matrix_enable_noeeprom();
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(200, 120, 140); // Purple base
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgb_matrix_enable_noeeprom();
    if (get_highest_layer(state) == 0) {
        rgb_matrix_sethsv_noeeprom(200, 120, rgb_matrix_get_val()); // Restore purple, keep brightness
    }
    return state;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t layer = get_highest_layer(layer_state | default_layer_state);
    uint8_t gv = rgb_matrix_get_val();

    if (layer == 0) {
        // Layer 0: overlay orange ripples on purple base
        // SOLID_COLOR mode renders the purple base; we only override ripple-affected LEDs
        for (uint8_t i = led_min; i < led_max; i++) {
            uint8_t best_v = 0;

            for (uint8_t r = 0; r < RIPPLE_COUNT; r++) {
                if (ripples[r].time == 0) continue;
                uint16_t elapsed = timer_elapsed(ripples[r].time);
                if (elapsed >= RIPPLE_DURATION) { ripples[r].time = 0; continue; }

                int16_t dx = (int16_t)g_led_config.point[i].x - (int16_t)ripples[r].x;
                int16_t dy = (int16_t)g_led_config.point[i].y - (int16_t)ripples[r].y;
                // Octagonal distance approximation (no sqrt needed)
                uint16_t adx = (dx >= 0) ? dx : -dx;
                uint16_t ady = (dy >= 0) ? dy : -dy;
                uint16_t dist = (adx > ady) ? adx + ady * 3 / 8 : ady + adx * 3 / 8;

                // Expanding ring: wavefront moves outward
                uint16_t wave_pos = (uint32_t)elapsed * 70 / RIPPLE_DURATION;
                int16_t from_wave = (int16_t)dist - (int16_t)wave_pos;
                if (from_wave > 15 || from_wave < -25) continue;

                // Ring shape: sharp leading edge (15px), softer trail behind (25px)
                uint8_t proximity;
                if (from_wave >= 0) {
                    proximity = 255 - (uint16_t)from_wave * 255 / 15;
                } else {
                    proximity = 255 - (uint16_t)(-from_wave) * 255 / 25;
                }
                uint8_t time_fade = 255 - (uint16_t)elapsed * 255 / RIPPLE_DURATION;
                uint8_t v = (uint16_t)proximity * time_fade / 255;
                if (v > best_v) best_v = v;
            }

            if (best_v > 20) {
                uint8_t v = (uint16_t)best_v * gv / 255;
                HSV hsv = {30, 220, v};
                RGB rgb = hsv_to_rgb(hsv);
                rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
            }
            // else: keep purple base from SOLID_COLOR mode
        }
        return false;
    }

    // Layer 1-3: active keys only
    uint8_t h, s;
    switch (layer) {
        case 1: h = 40;  s = 200; break; // Yellow/Gold
        case 2: h = 140; s = 200; break; // Cyan
        case 3: h = 85;  s = 180; break; // Green
        default: return false;
    }
    // Use global brightness directly (slightly boosted so indicators are visible over base)
    uint8_t v = (gv <= 215) ? gv + 40 : 255;
    HSV hsv = {h, s, v};
    RGB rgb = hsv_to_rgb(hsv);

    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            uint8_t led_index = g_led_config.matrix_co[row][col];
            if (led_index == NO_LED || led_index < led_min || led_index >= led_max) continue;

            uint16_t keycode = keymaps[layer][row][col];
            if (keycode == KC_TRANSPARENT || keycode == KC_NO) {
                rgb_matrix_set_color(led_index, 0, 0, 0);
            } else {
                rgb_matrix_set_color(led_index, rgb.r, rgb.g, rgb.b);
            }
        }
    }
    return true;
}
