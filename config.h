#ifdef INCLUDE_WINDOW_CONFIG

/* default window dimensions (overwritten via -g option): */
static const int WIN_WIDTH  = 800;
static const int WIN_HEIGHT = 600;

/* colors and font can be overwritten via X resource properties.
 * See nsxiv(1), X(7) section Resources and xrdb(1) for more information.
 *                                      X resource            value (NULL == default) */
static const char *WIN_BG[]   = { "Nsxiv.window.background",   "white" };
static const char *WIN_FG[]   = { "Nsxiv.window.foreground",   "black" };
static const char *MARK_FG[]  = { "Nsxiv.mark.foreground",      NULL };
#if HAVE_LIBFONTS
static const char *BAR_BG[]   = { "Nsxiv.bar.background",       NULL };
static const char *BAR_FG[]   = { "Nsxiv.bar.foreground",       NULL };
static const char *BAR_FONT[] = { "Nsxiv.bar.font",            "monospace-8" };

/* if true, statusbar appears on top of the window */
static const bool TOP_STATUSBAR = false;
#endif /* HAVE_LIBFONTS */

#endif
#ifdef INCLUDE_IMAGE_CONFIG

/* levels (in percent) to use when zooming via '-' and '+':
 * (first/last value is used as min/max zoom level)
 */
static const float zoom_levels[] = {
    0.31003926796253845, 0.3480073117735695, 0.3906249999999994, 0.43846173762084817,
    0.49215666011518416, 0.5524271728019894, 0.620078535925077, 0.696014623547139,
    0.781249999999999, 0.8769234752416964, 0.9843133202303684, 1.1048543456039792,
    1.2401570718501544, 1.3920292470942786, 1.5624999999999982, 1.7538469504833933,
    1.9686266404607373, 2.209708691207959, 2.480314143700309, 2.7840584941885576,
    3.124999999999997, 3.507693900966787, 3.937253280921475, 4.419417382415918,
    4.96062828740062, 5.568116988377116, 6.249999999999996, 7.015387801933576,
    7.874506561842952, 8.838834764831837, 9.921256574801241, 11.136233976754234,
    12.499999999999993, 14.030775603867154, 15.749013123685906, 17.67766952966368,
    19.842513149602485, 22.272467953508475, 24.999999999999993, 28.061551207734315,
    31.49802624737182, 35.35533905932737, 39.68502629920498, 44.54493590701695,
    49.999999999999986, 56.12310241546864, 62.99605249474365, 70.71067811865474,
    79.37005259840997, 89.08987181403393, 100.0, 112.2462048309373,
    125.99210498948732, 141.4213562373095, 158.74010519681997, 178.1797436280679,
    200.00000000000006, 224.49240966187466, 251.9842099789747, 282.8427124746191,
    317.48021039364, 356.3594872561358, 400.00000000000017, 448.9848193237494,
    503.96841995794944, 565.6854249492383, 634.9604207872801, 712.7189745122719,
    800.0000000000006, 897.969638647499, 1007.9368399158992, 1131.3708498984768,
    1269.9208415745607, 1425.437949024544, 1600.0000000000011, 1795.9392772949982,
    2015.8736798317989, 2262.741699796954, 2539.8416831491213, 2850.8758980490884,
    3200.0000000000027, 3591.8785545899973, 4031.7473596635987, 4525.483399593909,
    5079.6833662982435, 5701.751796098178, 6400.000000000007, 7183.7571091799955,
    8063.494719327198, 9050.96679918782, 10159.36673259649, 11403.503592196359,
    12800.000000000016, 14367.514218359995, 16126.9894386544, 18101.933598375643,
    20318.73346519298, 22807.007184392718, 25600.00000000004, 28735.028436719993,
};

/* default slideshow delay (in sec, overwritten via -S option): */
static const int SLIDESHOW_DELAY = 5;

/* color correction: the user-visible ranges [-CC_STEPS, 0] and
 * (0, CC_STEPS] are mapped to the ranges [0, 1], and (1, *_MAX].
 * Higher step count will have higher granulairy.
 */
static const int    CC_STEPS        = 32;
static const double GAMMA_MAX       = 10.0;
static const double BRIGHTNESS_MAX  = 2.0;
static const double CONTRAST_MAX    = 4.0;

/* command i_scroll pans image 1/PAN_FRACTION of screen width/height */
static const int PAN_FRACTION = 5;

/* percentage of memory to use for imlib2's cache size.
 *   3 means use 3% of total memory which is about 245MiB on 8GiB machine.
 *   0 or less means disable cache.
 * 100 means use all available memory (but not above CACHE_SIZE_LIMIT).
 *
 * NOTE: higher cache size means better image reloading performance, but also
 * higher memory usage.
 */
static const int CACHE_SIZE_MEM_PERCENTAGE = 3;          /* use 3% of total memory for cache */
static const int CACHE_SIZE_LIMIT = 256 * 1024 * 1024;   /* but not above 256MiB */
static const int CACHE_SIZE_FALLBACK = 32 * 1024 * 1024; /* fallback to 32MiB if we can't determine total memory */

#endif
#ifdef INCLUDE_OPTIONS_CONFIG

/* if false, pixelate images at zoom level != 100%,
 * toggled with 'a' key binding (overwritten via `--anti-alias` option)
 */
static const bool ANTI_ALIAS = true;

/* if true, use a checkerboard background for alpha layer,
 * toggled with 'A' key binding (overwritten via `--alpha-layer` option)
 */
static const bool ALPHA_LAYER = false;

#endif
#ifdef INCLUDE_THUMBS_CONFIG

/* thumbnail sizes in pixels (width == height): */
static const int thumb_sizes[] = { 32, 64, 96, 128, 160, 192, 224, 256, 384, 512 };

/* thumbnail size at startup, index into thumb_sizes[]: */
static const int THUMB_SIZE = 4;

#endif
#ifdef INCLUDE_MAPPINGS_CONFIG

/* these modifiers will be used when processing keybindings */
static const unsigned int USED_MODMASK = ShiftMask | ControlMask | Mod1Mask;

/* abort the keyhandler */
static const KeySym KEYHANDLER_ABORT = XK_Escape;

/* keyboard mappings for image and thumbnail mode: */
static const keymap_t keys[] = {
    /* modifiers    key               function              argument */
    { 0,            24, /*XK_q,*/             g_quit,               None },
    { 0,            36, /*XK_Return,*/        g_switch_mode,        None },
    { 0,            65, /*XK_space,*/         g_switch_mode,        None },
    { 0,            41, /*XK_f,*/             g_toggle_fullscreen,  None },
    { 0,            56, /*XK_b,*/             g_toggle_bar,         None },
    { ControlMask,  53, /*XK_x,*/             g_prefix_external,    None },

    { 0,            39, /*XK_s,*/             i_slideshow,          None },

    { ShiftMask,    40, /*XK_D,*/             g_remove_image,       None },
    { 0,            27, /*XK_r,*/             g_reload_image,       None },
    { ShiftMask,    27, /*XK_R,*/             t_reload_all,         None },
    { ControlMask,  15, /*XK_6,*/             i_alternate,          None },

    { ShiftMask,    34, /*XK_braceleft,*/     g_change_gamma,       -1 },
    { ShiftMask,    35, /*XK_braceright,*/    g_change_gamma,       +1 },
    { ControlMask,  42, /*XK_g,*/             g_change_gamma,        0 },
    { 0,            34, /* XK_bracketright,*/ g_change_brightness,  +1 },
    { 0,            35, /* XK_bracketleft,*/  g_change_brightness,  -1 },
    { ShiftMask,    18, /* XK_parenleft,*/    g_change_contrast,    -1 },
    { ShiftMask,    19, /* XK_parenright,*/   g_change_contrast,    +1 },
    { 0,            38, /*XK_a,*/             i_toggle_antialias,   None },
    { ShiftMask,    38, /*XK_A,*/             i_toggle_alpha,       None },

    { ControlMask,  65, /*XK_space,*/         i_toggle_animation,   None },
    { ControlMask,  57, /*XK_n,*/             i_navigate_frame,     +1 },
    { ControlMask,  33, /*XK_p,*/             i_navigate_frame,     -1 },

    { 0,            58, /*XK_m,*/             g_toggle_image_mark,  None },
    { ShiftMask,    58, /*XK_M,*/             g_reverse_marks,      None },
    { ControlMask,  58, /*XK_m,*/             g_unmark_all,         None },
    { ControlMask|ShiftMask,  58, /*XK_M,*/   g_mark_range,         None },

    { 0,            42, /*XK_g,*/             g_first,              None },
    { ShiftMask,    42, /*XK_G,*/             g_n_or_last,          None },
    { 0,            43, /*XK_h,*/             t_move_sel,           DIR_LEFT },
    { 0,            113, /*XK_Left,*/         t_move_sel,           DIR_LEFT },
    { 0,            44, /*XK_j,*/             t_move_sel,           DIR_DOWN },
    { 0,            116, /*XK_Down,*/         t_move_sel,           DIR_DOWN },
    { 0,            45, /*XK_k,*/             t_move_sel,           DIR_UP },
    { 0,            111, /*XK_Up,*/           t_move_sel,           DIR_UP },
    { 0,            46, /*XK_l,*/             t_move_sel,           DIR_RIGHT },
    { 0,            114, /*XK_Right,*/        t_move_sel,           DIR_RIGHT },
    { 0,            57, /*XK_n,*/             i_navigate,           +1 },
    { 0,            33, /*XK_p,*/             i_navigate,           -1 },
    { 0,            35, /*XK_bracketright,*/  i_navigate,           +10 },
    { 0,            34, /*XK_bracketleft,*/   i_navigate,           -10 },
    { ShiftMask,    57, /*XK_N,*/             g_navigate_marked,    +1 },
    { ShiftMask,    33, /*XK_P,*/             g_navigate_marked,    -1 },
    { ControlMask,  43, /*XK_h,*/             g_scroll_screen,      DIR_LEFT },
    { ControlMask,  113, /*XK_Left,*/         g_scroll_screen,      DIR_LEFT },
    { ControlMask,  44, /*XK_j,*/             g_scroll_screen,      DIR_DOWN },
    { ControlMask,  116, /*XK_Down,*/         g_scroll_screen,      DIR_DOWN },
    { ControlMask,  45, /*XK_k,*/             g_scroll_screen,      DIR_UP },
    { ControlMask,  111, /*XK_Up,*/           g_scroll_screen,      DIR_UP },
    { ControlMask,  46, /*XK_l,*/             g_scroll_screen,      DIR_RIGHT },
    { ControlMask,  114, /*XK_Right,*/        g_scroll_screen,      DIR_RIGHT },

    { ShiftMask,    21, /*XK_plus,*/          g_zoom,               +1 },
    { 0,            86, /*XK_KP_Add,*/        g_zoom,               +1 },
    { 0,            20, /*XK_minus,*/         g_zoom,               -1 },
    { 0,            82, /*XK_KP_Subtract,*/   g_zoom,               -1 },

    { 0,            21, /*XK_equal,*/         i_set_zoom,           100 },
    { 0,            25, /*XK_w,*/             i_fit_to_win,         SCALE_DOWN },
    { ShiftMask,    25, /*XK_W,*/             i_fit_to_win,         SCALE_FIT },
    { 0,            26, /*XK_e,*/             i_fit_to_win,         SCALE_WIDTH },
    { ShiftMask,    26, /*XK_E,*/             i_fit_to_win,         SCALE_HEIGHT },
    { ShiftMask,    59, /*XK_less,*/          i_rotate,             DEGREE_270 },
    { ShiftMask,    60, /*XK_greater,*/       i_rotate,             DEGREE_90 },
    { ShiftMask,    61, /*XK_question,*/      i_rotate,             DEGREE_180 },
    { ShiftMask,    51, /*XK_bar,*/           i_flip,               FLIP_HORIZONTAL },
    { ShiftMask,    20, /*XK_underscore,*/    i_flip,               FLIP_VERTICAL },

    { 0,            43, /*XK_h,*/             i_scroll,             DIR_LEFT },
    { 0,            113, /*XK_Left,*/         i_scroll,             DIR_LEFT },
    { 0,            44, /*XK_j,*/             i_scroll,             DIR_DOWN },
    { 0,            116, /*XK_Down,*/         i_scroll,             DIR_DOWN },
    { 0,            45, /*XK_k,*/             i_scroll,             DIR_UP },
    { 0,            111, /*XK_Up,*/           i_scroll,             DIR_UP },
    { 0,            46, /*XK_l,*/             i_scroll,             DIR_RIGHT },
    { 0,            114, /*XK_Right,*/        i_scroll,             DIR_RIGHT },
    { ShiftMask,    43, /*XK_H,*/             i_scroll_to_edge,     DIR_LEFT },
    { ShiftMask,    44, /*XK_J,*/             i_scroll_to_edge,     DIR_DOWN },
    { ShiftMask,    45, /*XK_K,*/             i_scroll_to_edge,     DIR_UP },
    { ShiftMask,    46, /*XK_L,*/             i_scroll_to_edge,     DIR_RIGHT },
    { 0,            52, /*XK_z,*/             i_scroll_to_center,   None },
};

/* mouse button mappings for image mode: */
static const button_t buttons_img[] = {
    /* modifiers    button            function              argument */
    { 0,            1,                i_drag,               DRAG_RELATIVE },
    { ControlMask,  1,                i_drag,               DRAG_ABSOLUTE },
    { 0,            2,                g_switch_mode,        None },
    { 0,            3,                i_cursor_navigate,    None },
    { 0,            4,                g_zoom,               +1 },
    { 0,            5,                g_zoom,               -1 },
    { ControlMask,  4,                g_zoom,               +3 },
    { ControlMask,  5,                g_zoom,               -3 },
};

/* mouse button mappings for thumbnail mode: */
static const button_t buttons_tns[] = {
    /* modifiers    button            function              argument */
    { 0,            1,                t_select,             None },
    { 0,            3,                t_drag_mark_image,    None },
    { 0,            4,                t_scroll,             DIR_UP },
    { 0,            5,                t_scroll,             DIR_DOWN },
    { ControlMask,  4,                g_scroll_screen,      DIR_UP },
    { ControlMask,  5,                g_scroll_screen,      DIR_DOWN },
};

/* true means NAV_WIDTH is relative (33%), false means absolute (33 pixels) */
static const bool NAV_IS_REL = true;
/* width of navigation area, 0 disables cursor navigation, */
static const unsigned int NAV_WIDTH = 33;

/* mouse cursor on left, middle and right part of the window */
static const cursor_t imgcursor[3] = {
    CURSOR_LEFT, CURSOR_ARROW, CURSOR_RIGHT
};

#endif
