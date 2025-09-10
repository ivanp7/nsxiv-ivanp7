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
    0.1953125, 0.20692638561704996, 0.21923086881042433, 0.23226701464896896,
    0.2460783300575925, 0.26071090901758476, 0.27621358640099514, 0.292638100952477,
    0.31003926796253883, 0.3284751622084822, 0.3480073117735702, 0.36870090339128636,
    0.390625, 0.41385277123409964, 0.43846173762084895, 0.4645340292979379,
    0.4921566601151848, 0.5214218180351697, 0.5524271728019903, 0.5852762019049537,
    0.620078535925078, 0.6569503244169644, 0.6960146235471399, 0.7374018067825732,
    0.78125, 0.8277055424681993, 0.8769234752416979, 0.9290680585958758,
    0.9843133202303695, 1.0428436360703395, 1.1048543456039805, 1.1705524038099073,
    1.240157071850156, 1.3139006488339289, 1.3920292470942799, 1.4748036135651463,
    1.5625, 1.6554110849363985, 1.7538469504833958, 1.8581361171917516,
    1.968626640460739, 2.085687272140679, 2.209708691207961, 2.3411048076198147,
    2.480314143700312, 2.6278012976678577, 2.7840584941885598, 2.9496072271302927,
    3.125, 3.310822169872797, 3.5076939009667916, 3.7162722343835033,
    3.937253280921478, 4.171374544281358, 4.419417382415922, 4.682209615239629,
    4.960628287400624, 5.2556025953357155, 5.5681169883771195, 5.899214454260585,
    6.25, 6.621644339745596, 7.01538780193358, 7.432544468767007,
    7.874506561842957, 8.342749088562714, 8.838834764831844, 9.36441923047926,
    9.921256574801246, 10.511205190671431, 11.136233976754243, 11.798428908521167,
    12.5, 13.243288679491192, 14.03077560386716, 14.865088937534013,
    15.749013123685915, 16.685498177125428, 17.67766952966369, 18.72883846095852,
    19.842513149602492, 21.022410381342862, 22.272467953508485, 23.596857817042334,
    25.0, 26.486577358982384, 28.061551207734325, 29.730177875068026,
    31.49802624737183, 33.370996354250856, 35.35533905932738, 37.45767692191704,
    39.68502629920499, 42.044820762685724, 44.54493590701696, 47.193715634084676,
    50.0, 52.97315471796477, 56.12310241546865, 59.46035575013605,
    62.99605249474366, 66.74199270850171, 70.71067811865476, 74.91535384383408,
    79.37005259840998, 84.08964152537145, 89.08987181403393, 94.38743126816935,

    100.0, 105.94630943592954, 112.2462048309373, 118.9207115002721,
    125.99210498948732, 133.48398541700342, 141.4213562373095, 149.83070768766817,
    158.74010519681994, 168.1792830507429, 178.17974362806785, 188.77486253633867,
    200.0, 211.89261887185907, 224.4924096618746, 237.8414230005442,
    251.98420997897463, 266.96797083400685, 282.842712474619, 299.66141537533633,
    317.48021039363994, 336.3585661014858, 356.3594872561357, 377.5497250726774,
    400.0, 423.78523774371814, 448.9848193237491, 475.6828460010884,
    503.96841995794927, 533.9359416680137, 565.685424949238, 599.3228307506727,
    634.9604207872798, 672.7171322029716, 712.7189745122715, 755.0994501453547,
    800.0, 847.5704754874363, 897.9696386474982, 951.3656920021768,
    1007.9368399158985, 1067.8718833360274, 1131.370849898476, 1198.6456615013453,
    1269.9208415745595, 1345.4342644059432, 1425.437949024543, 1510.1989002907094,
    1600.0, 1695.140950974872, 1795.9392772949973, 1902.7313840043537,
    2015.8736798317968, 2135.7437666720552, 2262.741699796952, 2397.29132300269,
    2539.8416831491195, 2690.8685288118863, 2850.875898049085, 3020.3978005814197,
    3200.0, 3390.281901949744, 3591.8785545899946, 3805.4627680087074,
    4031.7473596635937, 4271.4875333441105, 4525.483399593904, 4794.58264600538,
    5079.683366298239, 5381.737057623773, 5701.75179609817, 6040.795601162839,
    6400.0, 6780.563803899488, 7183.757109179989, 7610.925536017415,
    8063.494719327187, 8542.975066688221, 9050.966799187809, 9589.16529201076,
    10159.366732596478, 10763.474115247545, 11403.50359219634, 12081.591202325679,
    12800.0, 13561.127607798977, 14367.514218359978, 15221.85107203483,
    16126.989438654375, 17085.950133376442, 18101.933598375617, 19178.33058402152,
    20318.733465192956, 21526.94823049509, 22807.00718439268, 24163.182404651358,
    25600.0, 27122.255215597972, 28735.02843671994, 30443.70214406966,
    32253.978877308764, 34171.90026675287, 36203.867196751235, 38356.661168043065,
    40637.46693038589, 43053.89646099018, 45614.01436878539, 48326.364809302686, 51200.0,
};

/* default slideshow delay (in sec, overwritten via -S option): */
static const int SLIDESHOW_DELAY = 3;

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

/* list of whitelisted/blacklisted directory for thumbnail cache
 * (overwritten via --cache-{allow,deny} option).
 * see THUMBNAIL CACHING section in nsxiv(1) manpage for more details.
 */
static const char TNS_FILTERS[] = "";
/* set to true to treat `TNS_FILTERS` as a blacklist instead */
static const bool TNS_FILTERS_IS_BLACKLIST = false;

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
    { ShiftMask,    24, /*XK_Q,*/             g_pick_quit,          None },
    { 0,            36, /*XK_Return,*/        g_switch_mode,        None },
    { 0,            65, /*XK_space,*/         g_switch_mode,        None },
    { 0,            41, /*XK_f,*/             g_toggle_fullscreen,  None },
    { 0,            56, /*XK_b,*/             g_toggle_bar,         None },
    { ControlMask,  53, /*XK_x,*/             g_prefix_external,    None },

    { 0,            27, /*XK_r,*/             g_reload_image,       None },
    { ShiftMask,    27, /*XK_R,*/             t_reload_all,         None },

    { ControlMask,  15, /*XK_6,*/             i_alternate,          None },
    { 0,            42, /*XK_g,*/             g_first,              None },
    { ShiftMask,    42, /*XK_G,*/             g_n_or_last,          None },
    { ShiftMask,    40, /*XK_D,*/             g_remove_image,       None },

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

    { 0,            58, /*XK_m,*/             g_toggle_image_mark,  None },
    { ShiftMask,    58, /*XK_M,*/             g_reverse_marks,      None },
    { ControlMask,  58, /*XK_m,*/             g_unmark_all,         None },
    { ControlMask|ShiftMask,  58, /*XK_M,*/   g_mark_range,         None },

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
    { ControlMask,  43, /*XK_h,*/             g_scroll_screen,      DIR_LEFT },
    { ControlMask,  113, /*XK_Left,*/         g_scroll_screen,      DIR_LEFT },
    { ControlMask,  44, /*XK_j,*/             g_scroll_screen,      DIR_DOWN },
    { ControlMask,  116, /*XK_Down,*/         g_scroll_screen,      DIR_DOWN },
    { ControlMask,  45, /*XK_k,*/             g_scroll_screen,      DIR_UP },
    { ControlMask,  111, /*XK_Up,*/           g_scroll_screen,      DIR_UP },
    { ControlMask,  46, /*XK_l,*/             g_scroll_screen,      DIR_RIGHT },
    { ControlMask,  114, /*XK_Right,*/        g_scroll_screen,      DIR_RIGHT },

    { ControlMask,  65, /*XK_space,*/         i_toggle_animation,   None },
    { ControlMask,  57, /*XK_n,*/             i_navigate_frame,     +1 },
    { ControlMask,  33, /*XK_p,*/             i_navigate_frame,     -1 },

    { ShiftMask,    34, /*XK_braceleft,*/     g_change_gamma,       -1 },
    { ShiftMask,    35, /*XK_braceright,*/    g_change_gamma,       +1 },
    { ControlMask,  42, /*XK_g,*/             g_change_gamma,        0 },
    { 0,            34, /* XK_bracketright,*/ g_change_brightness,  +1 },
    { 0,            35, /* XK_bracketleft,*/  g_change_brightness,  -1 },
    { ShiftMask,    18, /* XK_parenleft,*/    g_change_contrast,    -1 },
    { ShiftMask,    19, /* XK_parenright,*/   g_change_contrast,    +1 },
    { 0,            38, /*XK_a,*/             i_toggle_antialias,   None },
    { ShiftMask,    38, /*XK_A,*/             i_toggle_alpha,       None },

    { 0,            39, /*XK_s,*/             i_slideshow,          None },
};

/* mouse button mappings for image mode: */
static const button_t buttons_img[] = {
    /* modifiers    button            function              argument */
    { 0,            1,                i_drag,               DRAG_RELATIVE },
    { ControlMask,  1,                i_drag,               DRAG_ABSOLUTE },
    { 0,            3,                i_toggle_animation,   None },

    { 0,            2,                i_cursor_navigate,    None },
    { ControlMask,  2,                g_switch_mode,        None },
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
