/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int snap      = 24;       /* snap pixel */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 0;        /* 0 means bottom bar */
static const char *fonts[]          = { "Pixel NES:size=12" ,"JetBrains Mono:size=18", "Noto Color Emoji:pixelsize=12:antialias=true:autohint=true" };
static const char dmenufont[]       = {"Pixel NES:size=12"};
static const char col_white1[]      = {"#e1dfde"};
static const char col_white2[]      = {"#ccc7b4"};
static const char col_gray1[]       = {"#1e2021"};
static const char col_gray2[]       = {"#33384D"};
static const char col_font_norm[]   = {"#98A9C0"};
static const char col_font_bright[] = {"#BBD1DA"};
static const char col_font_bright2[] ={"#DDDDDD"};

static const char col_accent1[] = {"#775451"};
static const char col_accent2[] = {"#4444DD"};

static const char *colors[][3]      = {
	/*fg               bg           border */
	{ col_font_norm,   col_gray1,   col_gray2 },   // orig
	{ col_font_bright, col_accent1, col_accent1 }, // orig
	{ col_font_norm,   col_gray1,   col_gray2 },
	{ col_font_bright2,col_accent2, col_accent2 },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class     instance  title           tags mask  isfloating  isterminal  noswallow  monitor */
	{ "Gimp",    NULL,     NULL,           0,         1,          0,           0,        -1 },
	{ "Firefox", NULL,     NULL,           1 << 8,    0,          0,          -1,        -1 },
	{ "Alacritty", "Alacritty",NULL,       0,         0,          1,          -1,        -1 },
	{ NULL,      NULL,     "Event Tester", 0,         1,          0,           1,        -1 }, /* xev */
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int moveresizeFPS = 60; /* times windows are updated in a second when moving/resizing them */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "ǁ",      tile },    /* first entry is default */
	{ "~",      NULL },    /* no layout function means floating behavior */
};

/* key definitions */
#include <X11/XF86keysym.h>

#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      comboview,      {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      combotag,       {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

#define STATUSBAR "dwmblocks"

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-b", "-l", "13", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_font_norm, "-sb", col_accent1, "-sf", col_font_bright, NULL };
static const char *termcmd[]  = { "alacritty", NULL };

static Key keys[] = {
	/* modifier            key                      function        argument */
	{ MODKEY,              XK_Print,                spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,    XK_Return,               spawn,          {.v = termcmd } },
	{ MODKEY,              XK_g,                    togglebar,      {0} },
	{ MODKEY,              XK_Page_Up,              focusstack,     {.i = +1 } },
	{ MODKEY,              XK_Page_Down,            focusstack,     {.i = -1 } },
	{ MODKEY,              XK_Left,                 incnmaster,     {.i = +1 } },
	{ MODKEY,              XK_Right,                incnmaster,     {.i = -1 } },
	{ MODKEY,              XK_Down,                 setmfact,       {.f = -0.05} },
	{ MODKEY,              XK_Up,                   setmfact,       {.f = +0.05} },
	{ MODKEY,              XK_Return,               zoom,           {0} },
	{ MODKEY,              XK_Tab,                  view,           {0} },
	{ MODKEY,              XK_Escape,               killclient,     {0} },
	{ MODKEY,              XK_t,                    setlayout,      {.v = &layouts[0]} },
	{ MODKEY,              XK_f,                    setlayout,      {.v = &layouts[1]} },
	{ MODKEY,              XK_space,                setlayout,      {0} },
	{ MODKEY,	           XK_F11,					togglefullscr,	{0} },
	{ MODKEY|ShiftMask,    XK_space,                togglefloating, {0} },
	{ MODKEY,              XK_comma,                focusmon,       {.i = -1 } },
	{ MODKEY,              XK_period,               focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,    XK_comma,                tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,    XK_period,               tagmon,         {.i = +1 } },
	{ MODKEY,              XK_z,                    schemeCycle,         {0} },
	{ 0,                   XF86XK_AudioRaiseVolume,	spawn,		    SHCMD("pamixer --allow-boost -i 1; pkill -RTMIN+2 dwmblocks") },
	{ 0,                   XF86XK_AudioLowerVolume,	spawn,		    SHCMD("pamixer --allow-boost -d 1; pkill -RTMIN+2 dwmblocks") },
	{ 0,                   XK_Print,	            spawn,		    SHCMD("screenshot_clip") },
	TAGKEYS(               XK_q,                    1)
	TAGKEYS(               XK_d,                    2)
	TAGKEYS(               XK_r,                    3)
	TAGKEYS(               XK_w,                    4)
	TAGKEYS(               XK_b,                    5)
	TAGKEYS(               XK_j,                    6)
	{ MODKEY|ShiftMask,    XK_Escape,               quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkWinTitle,          0,              Button2,        togglefloating, {0} },
	{ ClkStatusText,        0,              Button1,        sigstatusbar,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigstatusbar,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigstatusbar,   {.i = 3} },
	{ ClkStatusText,        0,              Button4,        sigstatusbar,   {.i = 4} },
	{ ClkStatusText,        0,              Button5,        sigstatusbar,   {.i = 5} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

