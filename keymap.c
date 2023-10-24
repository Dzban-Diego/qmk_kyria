#include QMK_KEYBOARD_H
#include <stdio.h>
char wpm_str[10];

// Zdefiniowanie warstw
#define _COL 0
#define _SYS_NAV 1
#define _MED 2
#define _NAV 3
#define _NUM 4
#define _SPEC 5
#define _num 6

// Tap Dance declarations
enum {
    TD_P1,
    TD_P2,
    TD_P3,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_P1] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
    [TD_P2] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
    [TD_P3] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Domyślna warswa colemak_dh
    [_COL] = LAYOUT(
        KC_ESC       , KC_Q         , KC_W         , KC_F         , KC_P         , KC_B         , /*===========, =============, =============, ============*/ KC_J         , KC_L         , KC_U        , KC_Y          , KC_SCLN      , KC_DEL       ,
        KC_TAB       , KC_A         , KC_R         , KC_S         , KC_T         , KC_G         , /*===========, =============, =============, ============*/ KC_M         , KC_N         , KC_E        , KC_I          , KC_O         , KC_BSPC      ,
        OSM(MOD_LSFT), KC_X         , KC_C         , KC_D         , KC_Z         , KC_V         , KC_ESC       , TG(1)        , MO(4)        , TG(3)        , KC_K         , KC_H         , KC_COMM     , KC_DOT        , KC_SLSH      , KC_ENT       ,
        /*===========, =============, =========== */ OSM(MOD_RALT), KC_LGUI      , OSM(MOD_RALT), MO(1)        , KC_LCTL      , TG(4)        , MO(3)        , LT(6, KC_SPC), MO(5)        , MO(2)
    ),

    // Systemowa nawigacja
	[_SYS_NAV] = LAYOUT(
	    KC_TRNS      , SGUI(KC_1)   , SGUI(KC_2)   , SGUI(KC_3)   , SGUI(KC_4)   , SGUI(KC_5)   , /*===========, =============, =============, ============*/ KC_PGUP      , KC_HOME      , KC_UP       , KC_END        , LGUI(KC_PGUP), KC_DEL       ,
	    KC_TRNS      , RGUI(KC_1)   , RGUI(KC_2)   , RGUI(KC_3)   , RGUI(KC_4)   , RGUI(KC_5)   , /*===========, =============, =============, ============*/ KC_PGDN      , LSFT(KC_8)   , LSFT(KC_2)  , KC_RABK       , KC_MINUS     , KC_BSPC      ,
        KC_NO        , KC_LGUI      , KC_LSFT      , KC_LCTL      , KC_LALT      , KC_NO        , KC_TRNS      , KC_TRNS      , KC_TRNS      , KC_NO        , KC_NO        , KC_NO        , KC_NO       , KC_NO         , KC_LSFT      , KC_F12       ,
        /*===========, =============, =========== */ TG(0)        , KC_NO        , KC_NO        , KC_TRNS      , KC_TRNS      , KC_NO        , KC_TRNS      , KC_NO        , KC_NO        , KC_NO
    ),

    // Media
	[_MED] = LAYOUT(
	    KC_NO        , KC_NO        , KC_NO        , KC_NO        , KC_NO        , KC_NO        , /*===========, =============, =============, ============*/ KC_NO        , KC_NO        , KC_NO       , KC_NO         , KC_NO        , KC_NO        ,
	    KC_NO        , KC_NO        , KC_NO        , KC_NO        , KC_NO        , KC_NO        , /*===========, =============, =============, ============*/ KC_NO        , KC_MUTE      , KC_VOLD     , KC_VOLU       , KC_BRIU      , KC_NO        ,
	    KC_NO        , KC_NO        , KC_NO        , KC_NO        , KC_NO        , KC_NO        , KC_NO        , KC_NO        , KC_NO        , KC_NO        , KC_NO        , KC_MPRV      , KC_MPLY     , KC_MNXT       , KC_BRID      , KC_PSCR      ,
        /*===========, =============, =========== */ KC_NO        , KC_NO        , KC_NO        , KC_TRNS      , KC_TRNS      , KC_TRNS      , KC_TRNS      , KC_TRNS      , KC_NO        , KC_TRNS
    ),

    // Nawigacja
    [_NAV] = LAYOUT(
        KC_ESC       , LALT(KC_TAB) , LCTL(KC_X)   , LCTL(KC_C)   , LCTL(KC_V)   , LALT(KC_ENT) , /*===========, =============, =============, ============*/ KC_PGUP      , KC_HOME      , KC_UP       , KC_END        , KC_NO        , KC_DEL       ,
        KC_TAB       , KC_LGUI      , KC_LALT      , KC_LSFT      , KC_LCTL      , KC_APP       , /*===========, =============, =============, ============*/ KC_PGDN      , KC_LEFT      , KC_DOWN     , KC_RGHT       , LCTL(KC_SLSH), KC_BSPC      ,
        TG(0)        , KC_F12       , OSM(MOD_RALT), KC_WBAK      , KC_WFWD      , LCA(KC_B)    , TG(0)        , KC_NO        , KC_NO        , KC_TRNS      , LCTL(KC_B)   , LCTL(KC_H)   , KC_TRNS     , MO(10)        , LCTL(KC_DOT) , KC_ENT       ,
        /*===========, =============, =========== */ KC_NO        , KC_NO        , KC_NO        , MO(1)        , KC_NO        , KC_NO        , KC_TRNS      , KC_TRNS      , KC_NO        , KC_NO
    ),

    // Numpad
	[_NUM] = LAYOUT(
	    KC_ESC       , KC_NO        , KC_NO        , KC_NO        , KC_NO        , KC_NO        , /*===========, =============, =============, ============*/ KC_NO        , KC_7         , KC_8         , KC_9         , KC_NO        , KC_DEL       ,
	    KC_TAB       , KC_PPLS      , KC_PAST      , KC_PMNS      , KC_PSLS      , KC_NO        , /*===========, =============, =============, ============*/ KC_0         , KC_4         , KC_5         , KC_6         , KC_NO        , KC_BSPC      ,
	    KC_NO        , KC_NO        , KC_PCMM      , KC_PDOT      , KC_PEQL      , KC_NO        , KC_NO        , KC_TRNS      , KC_NO        , KC_NO        , KC_NO        , KC_1         , KC_2         , KC_3         , KC_NO        , KC_ENT       ,
        /*===========, =============, =========== */ KC_NO        , KC_NO        , KC_NO        , KC_NO        , KC_NO        , KC_TRNS      , MO(3)        , KC_SPC       , KC_0         , KC_PDOT
    ),

    // Specjalne
	[_SPEC] = LAYOUT(
        KC_GRV       , KC_1         , KC_2         , KC_3         , KC_4         , KC_5         , /*===========, =============, =============, ============*/ KC_6         , KC_7         , KC_8         , KC_9         , KC_0         , KC_PSCR      ,
	    KC_SLSH      , KC_BSLS      , KC_COLN      , KC_LT        , KC_GT        , KC_NO        , /*===========, =============, =============, ============*/ LSFT(KC_8)   , TD(TD_P1)    , TD(TD_P2)    , TD(TD_P3)    , KC_MINS      , KC_BSPC      ,
	    KC_LSFT      , KC_NO        , KC_QUOT      , KC_DQUO      , LSFT(KC_BSLS), KC_AMPR      , TG(0)        , KC_NO        , KC_NO        , KC_NO        , LSFT(KC_2)   , KC_RPRN      , KC_RCBR      , KC_RBRC      , KC_EQL       , KC_ENT       ,
	    /*===========, =============, =========== */ KC_NO        , KC_NO        , KC_LALT      , KC_NO        , KC_NO        , KC_NO        , KC_TRNS      , KC_TRNS      , KC_NO        , KC_NO
    ),

    // numerki
    [_num] = LAYOUT(
        KC_TRNS     , SGUI(KC_1)    , SGUI(KC_2)   , SGUI(KC_3)   , SGUI(KC_4)   , SGUI(KC_5)   , /*===========, =============, =============, ============*/ KC_PGUP      , KC_HOME      , KC_UP        , KC_END       , LGUI(KC_PGUP), KC_DEL       ,
        KC_0        , KC_1          , KC_2         , KC_3         , KC_4         , KC_5         , /*===========, =============, =============, ============*/ KC_6         , KC_7         , KC_8         , KC_9         , KC_0         , KC_BSPC      ,
        KC_NO       , RSFT(KC_MINS) , RSFT(KC_4)   , KC_LCTL      , KC_LALT      , KC_NO        , KC_TRNS      , KC_TRNS      , KC_TRNS      , KC_NO        , KC_NO        ,   MO(2)      , MO(3)        , MO(4)        , KC_LSFT      , KC_F12       ,
        /*===========, =============, =========== */ TG(0)        , KC_NO        , KC_NO        , KC_TRNS      , KC_TRNS      , KC_NO        , KC_TRNS      , KC_NO        , KC_NO        , KC_NO
    ),
};


// logo to second side
static void render_logo(void) {
    // 'IMG_8853', 1251x1119px
    static const char PROGMEM my_logo[] = {
        // 'IMG_8853', 128x64px
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x80, 0xf8, 0x3e, 0x1c, 0x3c, 0xf8, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xe0, 0xfe, 0x3f, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02,
        0x06, 0x06, 0x06, 0x06, 0x0e, 0x0c, 0x0c, 0x1c, 0x1c, 0x1c, 0x18, 0x18, 0x38, 0x30, 0x30, 0x60,
        0x60, 0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xf8, 0xf8, 0x1f,
        0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x01, 0x01, 0x03, 0x07, 0x06, 0x6c, 0x78, 0x70, 0x78, 0x3c, 0x1e, 0x1e, 0x0e, 0xfe,
        0xfe, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x20, 0x20, 0x70, 0x60, 0x60, 0x60, 0x40, 0x40, 0x80, 0x00, 0xff, 0xff, 0x63, 0x21, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x1f, 0x1f, 0x0f, 0x06, 0x60, 0xf0, 0xe0, 0xe0, 0xe0,
        0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0xe0, 0xe0, 0xe0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0xfc, 0xbf, 0x3f,
        0x3f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x60, 0x60, 0xb0, 0x58, 0x5c,
        0xd6, 0xbe, 0x2e, 0x3c, 0x50, 0xec, 0xbc, 0x24, 0xf6, 0xff, 0x07, 0x01, 0x00, 0x00, 0x00, 0x80,
        0x80, 0xc0, 0xc0, 0xe0, 0xf0, 0xf8, 0x9c, 0x0c, 0x20, 0x60, 0x60, 0x40, 0xc0, 0xc0, 0x80, 0x81,
        0x81, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x07, 0x1f,
        0x7c, 0xf8, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x06, 0x07, 0x0c, 0x0e,
        0x1f, 0x19, 0x1e, 0x3f, 0x3f, 0x7e, 0x67, 0x7b, 0xdf, 0xff, 0xff, 0xde, 0xc6, 0x4f, 0x6f, 0x3f,
        0x3f, 0x1f, 0x1f, 0x27, 0x57, 0x7f, 0xfd, 0xfe, 0x7e, 0x3e, 0x3e, 0x1e, 0x0c, 0x00, 0x00, 0x00,
        0x81, 0x81, 0xe1, 0xf2, 0x02, 0xe2, 0x62, 0xc6, 0xc4, 0xe4, 0xfc, 0x9c, 0x8e, 0x87, 0x03, 0x80,
        0x80, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 0x60, 0x70, 0x30, 0x38, 0x18, 0x40, 0x40, 0x40, 0xc0, 0x80,
        0x80, 0x87, 0x9f, 0xfe, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x02, 0x12, 0x5a, 0x5e, 0xce, 0xee, 0xff,
        0xdb, 0xcb, 0x79, 0x37, 0x0f, 0x0f, 0x4f, 0x43, 0xd3, 0xb7, 0x27, 0x7f, 0x9f, 0xff, 0x67, 0xc3,
        0xff, 0x7f, 0x7f, 0x77, 0x07, 0xfe, 0xf0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x01, 0x01, 0x01, 0x03, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01,
        0x05, 0x0f, 0x0b, 0x0f, 0x1f, 0x1f, 0x1f, 0x3a, 0x3b, 0x39, 0x3c, 0x7e, 0x7d, 0xfd, 0x7b, 0xf9,
        0xfd, 0x7e, 0x3f, 0x3f, 0x1f, 0x0c, 0x06, 0x07, 0x07, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    oled_write_raw_P(my_logo, sizeof(my_logo));
}

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // master side
    if (is_keyboard_master()) {
        // Host Keyboard Layer Status
        oled_write_P(PSTR("Najlepsza klawka \n"), false);
        oled_write_P(PSTR(" \n"), false);
        oled_write_P(PSTR("Warstwa: "), false);

        switch (get_highest_layer(layer_state)) {
            case _COL:
                oled_write_P(PSTR("Colemak_dh \n"), false);
                break;
            case _SYS_NAV:
                oled_write_P(PSTR("Navigacja systemu \n"), false);
                break;
            case _MED:
                oled_write_P(PSTR("Media \n"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("Navigacja \n"), false);
                break;
            case _NUM:
                oled_write_P(PSTR("123451242 \n"), false);
                break;
            case _SPEC:
                oled_write_P(PSTR("Specjalny jesteś \n"), false);
                break;
            default:
                // Or use the write_ln shortcut over adding '\n' to the end of your string
                oled_write_ln_P(PSTR("Teraz to coś popsułeś"), false);
        }

        // Host Keyboard LED Status
        led_t led_state = host_keyboard_led_state();
        oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
        oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
        oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
        oled_write_P(PSTR("\n"), false);
        oled_write_P(PSTR("Dzban_Diego \n"), false);
        return false;
        // second side
    }else{
        render_logo();
        return false;
    }

}
#endif
