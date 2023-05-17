/* mbp-mappings */
#define XF86MonBrightnessDown   0x1008ff03
#define XF86MonBrightnessUp     0x1008ff02
#define XF86LauncherKB1         0x1008ff4a
#define XF86LauncherKB2         0x1008ff4b
#define XF86KbdBrightnessDown   0x1008ff06
#define XF86KbdBrightnessUp     0x1008ff05
#define XF86AudioPrev           0x1008ff16
#define XF86AudioPlay           0x1008ff14
#define XF86AudioNext           0x1008ff17
#define XF86AudioMute           0x1008ff12
#define XF86AudioLowerVolume    0x1008ff11
#define XF86AudioRaiseVolume    0x1008ff13

/* appearance */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;     /* 0 means no systray */
static unsigned int borderpx              = 2;   /* border pixel of windows */
static unsigned int snap                  = 0;   /* snap pixel */
static const unsigned int gappih          = 5;  /* horiz inner gap between windows */
static const unsigned int gappiv          = 5;  /* vert inner gap between windows */
static const unsigned int gappoh          = 5;  /* horiz outer gap between windows and screen edge */
static const unsigned int gappov          = 5;  /* vert outer gap between windows and screen edge */
static const unsigned int vertpad= 10;
static const unsigned int sidepad=10;
static int smartgaps                      = 0;   /* 1 means no outer gap when there is only one window */
static const int swallowfloating          = 0;   /* 1 means swallow floating windows by default */
static int showbar                        = 1;   /* 0 means no bar */
static int topbar                         = 1;   /* 0 means bottom bar */
static const int riodraw_borders          = 0;   /* 0 or 1, indicates whether the area drawn using slop includes the window borders */
static const int riodraw_matchpid         = 1;   /* 0 or 1, indicates whether to match the PID of the client that was spawned with riospawn */
static const int riodraw_spawnasync       = 0;   /* 0 the application is spawned after a selection while / 1 the application is being initialised in the background while the selection is made */
static const char slopspawnstyle[]        = "-t 0 -c 0.92,0.85,0.69,0.3 -o";  /* do NOT define -f (format) here */
static const char buttonbar[]             = " |";
static char font[]                        = "JetBrainsMono Nerd Font:style=Bold:size=17:pixelsize=17:antialias=true:autohint=true";
static char dmenufont[]                   = "JetBrainsMono Nerd Font:style=Bold:size=17:pixelsize=17:antialias=true:autohint=true";
static const char *fonts[]                = { font };
static char normbgcolor[]                 = "#222222";
static char normbordercolor[]             = "#444444";
static char normfgcolor[]                 = "#bbbbbb";
static char selfgcolor[]                  = "#eeeeee";
static char selbordercolor[]              = "#005577";
static char selbgcolor[]                  = "#005577";
static const unsigned int baralpha        = 0xd0;
static const unsigned int borderalpha     = OPAQUE;

static const char *colors[][3] = {
  /*                       fg           bg           border      */
  [SchemeNorm]     = { normfgcolor, normbgcolor, normbordercolor },
  [SchemeSel]      = { selfgcolor,  selbgcolor,  selbordercolor  },
  [SchemeStatus]   = { normfgcolor, normbgcolor, normbordercolor },
  [SchemeTagsSel]  = { selfgcolor,  selbgcolor,  normbordercolor },
  [SchemeTagsNorm] = { normfgcolor, normbgcolor, normbordercolor },
  [SchemeInfoSel]  = { normfgcolor, normbgcolor, normbordercolor },
  [SchemeInfoNorm] = { normfgcolor, normbgcolor, normbordercolor },
};

static const unsigned int alphas[][3]      = {
  /*                     fg       bg        border   */
  [SchemeNorm]     = { OPAQUE, baralpha, borderalpha },
  [SchemeSel]      = { OPAQUE, baralpha, borderalpha },
  [SchemeStatus]   = { OPAQUE, baralpha, borderalpha },
  [SchemeTagsSel]  = { OPAQUE, baralpha, borderalpha },
  [SchemeTagsNorm] = { OPAQUE, baralpha, borderalpha },
  [SchemeInfoSel]  = { OPAQUE, baralpha, borderalpha },
  [SchemeInfoNorm] = { OPAQUE, baralpha, borderalpha },
};

typedef struct {
	const char *name;
	const void *cmd;
} Sp;
const char *spcmd1[] = {"st", "-n", "spterm", "-g", "120x34", NULL };
const char *spcmd2[] = {"st", "-n", "spfiles", "-g", "170x40", "-e", "ranger", NULL };
const char *spcmd3[] = {"st", "-n", "spmusic", "-g", "120x40", "-e", "cmus", NULL };
const char *spcmd4[] = {"st", "-n", "spvol", "-g", "144x41", "-e", "pulsemixer", NULL };
const char *spcmd5[] = {"obs", NULL };
const char *spcmd6[] = {"qalculate-gtk", NULL };
static Sp scratchpads[] = {
  /* name          cmd  */
  {"spterm",      spcmd1},
  {"spfiles",     spcmd2},
  {"spmusic",     spcmd3},
  {"spvol",       spcmd4},
  {"obs",         spcmd5},
  {"qalc",        spcmd6},
};

/* tagging */
static const char *tags[] = {"1", "2", "3", "4", "5", "6", "7"};

static const unsigned int ulinepad	= 3;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke	= 1;	/* thickness / height of the underline */
static const unsigned int ulinevoffset	= 0;	/* how far above the bottom of the bar the line should appear */
static const int ulineall 		= 0;	/* 1 to show underline on all tags, 0 for just the active ones */

static const Rule rules[] = {
 /* xprop(1):
  * WM_CLASS(STRING) = instance, class
  * WM_NAME(STRING) = title
  */
  /* class                instance       title        tags mask   isfloating  isterminal  noswallow  monitor */
  { "Emacs",                NULL,         NULL,          1<<0,        0,          0,         -1,        -1 },
  { "firefox",              NULL,         NULL,          1<<1,        0,          0,         -1,        -1 },
  { "qutebrowser",          NULL,         NULL,          1<<1,        0,          0,         -1,        -1 },
  { "Steam",                NULL,         NULL,          1<<2,        0,          0,         -1,        -1 },
  { "TelegramDesktop",      NULL,         NULL,          1<<3,        0,          0,         -1,        -1 },
  { "St",                   NULL,         NULL,             0,        0,          1,          0,        -1 },
  { "Qalculate-gtk",        NULL,         NULL,             0,        1,          0,          1,        -1 },
  { NULL,               "spterm",         NULL,      SPTAG(0),        1,          1,          1,        -1 },
  { NULL,              "spfiles",         NULL,      SPTAG(1),        1,          1,          1,        -1 },
  { NULL,              "spmusic",         NULL,      SPTAG(2),        1,          1,          1,        -1 },
  { NULL,                "spvol",         NULL,      SPTAG(3),        1,          1,          1,        -1 },
  { NULL,                  "obs",         NULL,      SPTAG(4),        1,          0,          1,        -1 },
  { NULL,                 "qalc",         NULL,      SPTAG(5),        1,          0,          1,        -1 },
};

/* layout(s) */
static float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static int nmaster     = 1;    /* number of clients in master area */
static int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
  /* symbol     arrange function */
  { "[]=",      tile },    /* first entry is default */
  { "[@]",      spiral },
  { "[\\]",     dwindle },
  { NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
  { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
  { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
  { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
  { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

#define STATUSBAR "dwmblocks"

/* app commands */
static char dmenumon[2]         =   "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[]   =   { "dmenu_run", "-l", "20", NULL };
static const char *termcmd[]    =   { "st", NULL };
static const char *screenshot[] =   { "screenshot", NULL };
static const char *fullshot[]   =   { "flameshot", "full", NULL };
static const char *browser[]    =   { "brave", NULL };
static const char *telegram[]   =   { "telegram-desktop", "-l", NULL };
static const char *emoji[]      =   { "emoji", NULL };
static const char *clip[]       =   { "clipmenu", NULL };
static const char *vim[]      	=   { "nvim", NULL };
static const char *inclight[]   =   { "xbacklight", "-inc", "9", NULL };
static const char *declight[]   =   { "xbacklight", "-dec", "9", NULL };
static const char *night[]      =   { "nightmode", NULL };

/* shell scripts */
static const char *eww[]	=   { "/.local/bin/toogle_eww.sh", NULL };

/* kb commands */
static const char *kb_audio_prev[] = { "cmus-remote", "-r", NULL };
static const char *kb_audio_play[] = { "cmus-remote", "-u", NULL };
static const char *kb_audio_next[] = { "cmus-remote", "-n", NULL };

/* Xresources preferences to load at startup */
ResourcePref resources[] = {
  { "color4",             STRING,   &normbordercolor},
  { "color14",            STRING,   &selbordercolor},
  { "color0",             STRING,   &normbgcolor},
  { "color12",            STRING,   &normfgcolor},
  { "color7",             STRING,   &selfgcolor},
  { "color0",             STRING,   &selbgcolor},
  { "font",               STRING,   &font },
  { "dmenufont",          STRING,   &dmenufont },
  { "normbgcolor",        STRING,   &normbgcolor },
  { "normbordercolor",    STRING,   &normbordercolor },
  { "normfgcolor",        STRING,   &normfgcolor },
  { "selbgcolor",         STRING,   &selbgcolor },
  { "selbordercolor",     STRING,   &selbordercolor },
  { "selfgcolor",         STRING,   &selfgcolor },
  { "borderpx",           INTEGER,  &borderpx },
  { "snap",               INTEGER,  &snap },
  { "showbar",            INTEGER,  &showbar },
  { "topbar",             INTEGER,  &topbar },
  { "nmaster",            INTEGER,  &nmaster },
  { "resizehints",        INTEGER,  &resizehints },
  { "mfact",              FLOAT,    &mfact },
};

#include "movestack.c"
#include "exitdwm.c"

static const Key keys[] = {
  /* modifier                     key            function           argument */

  /* Commands */
  { MODKEY,                       XK_p,          spawn,             {.v = dmenucmd } },
  { MODKEY,                       XK_Return,     spawn,             {.v = termcmd } },
  { MODKEY|ControlMask,           XK_Return,     riospawn,          {.v = termcmd } },
  { 0,                            XK_Print,      spawn,             {.v = screenshot } },
  { MODKEY,                       XK_Print,      spawn,             {.v = fullshot } },
  { MODKEY,                       XK_f,          spawn,             {.v = browser } },
  { MODKEY,                       XK_t,          spawn,             {.v = telegram } },
  { MODKEY,                       XK_v,          spawn,             {.v = vim } },
  { MODKEY|ShiftMask,             XK_n,          spawn,             {.v = night} },
  { MODKEY|ShiftMask,             XK_y,          spawn,             {.v = clip} },
  { MODKEY|ControlMask,           XK_e,          spawn,             {.v = emoji} },
  { MODKEY,			  XK_d,		 spawn,		    SHCMD(".local/bin/toggle_eww") },
  { MODKEY,		   	  XK_r,     	 spawn,             SHCMD("rofi -show run -theme ~/.config/rofi/style-7.rasi") },
  /* MBP Mappings */ 
  /*{ 0, XF86AudioPrev,                   spawn,          {.v = kb_audio_prev } },
  { 0, XF86AudioPlay,                   spawn,          {.v = kb_audio_play } },
  { 0, XF86AudioNext,                   spawn,          {.v = kb_audio_next } },*/

  /* Media Keys */
  { 0, 			XF86AudioRaiseVolume,    spawn,             SHCMD("pulseaudio-ctl up; 	      kill -41 $(pidof dwmblocks)") },
  { 0,                  XF86AudioLowerVolume,    spawn,             SHCMD("pulseaudio-ctl down;       kill -41 $(pidof dwmblocks)") },
  { 0,                  XF86AudioMute,		 spawn,             SHCMD("pulseaudio-ctl mute;       kill -41 $(pidof dwmblocks)") },
  { Mod1Mask,           XK_m,          		 spawn,             SHCMD("pulseaudio-ctl mute-input; kill -43 $(pidof dwmblocks)") },
  { 0,                  XF86MonBrightnessUp,	 spawn,             {.v = inclight } },
  { 0,                  XF86MonBrightnessDown,	 spawn,             {.v = declight } },
  
  /* Dwm Commands */
  { MODKEY,                       XK_b,          togglebar,         {0} },
  { MODKEY,                       XK_Left,       focusstack,        {.i = +1 } },
  { MODKEY,                       XK_Right,      focusstack,        {.i = -1 } },
  { MODKEY,                       XK_i,          incnmaster,        {.i = +1 } },
  { MODKEY,                       XK_d,          incnmaster,        {.i = -1 } },
  { MODKEY,                       XK_h,          setmfact,          {.f = -0.05} },
  { MODKEY,                       XK_l,          setmfact,          {.f = +0.05} },
  { MODKEY,                       XK_j,          setcfact,          {.f = +0.25} },
  { MODKEY,                       XK_k,          setcfact,          {.f = -0.25} },
  { MODKEY|ShiftMask,             XK_o,          setcfact,          {.f =  0.00} },
  { MODKEY,                       XK_equal,      incrogaps,         {.i = +1 } },
  { MODKEY,                       XK_minus,      incrogaps,         {.i = -1 } },
  { MODKEY|ShiftMask,             XK_equal,      incrohgaps,        {.i = +1 } },
  { MODKEY|ShiftMask,             XK_minus,      incrohgaps,        {.i = -1 } },
  { MODKEY|ControlMask,           XK_equal,      incrovgaps,        {.i = +1 } },
  { MODKEY|ControlMask,           XK_minus,      incrovgaps,        {.i = -1 } },
  { MODKEY|Mod1Mask,              XK_equal,      incrigaps,         {.i = +1 } },
  { MODKEY|Mod1Mask,              XK_minus,      incrigaps,         {.i = -1 } },
  { MODKEY|Mod1Mask|ShiftMask,    XK_equal,      incrgaps,          {.i = +1 } },
  { MODKEY|Mod1Mask|ShiftMask,    XK_minus,      incrgaps,          {.i = -1 } },
  { MODKEY|Mod1Mask,              XK_8,          incrihgaps,        {.i = +1 } },
  { MODKEY|Mod1Mask|ShiftMask,    XK_8,          incrihgaps,        {.i = -1 } },
  { MODKEY|Mod1Mask,              XK_9,          incrivgaps,        {.i = +1 } },
  { MODKEY|Mod1Mask|ShiftMask,    XK_9,          incrivgaps,        {.i = -1 } },
  { MODKEY|Mod1Mask,              XK_0,          togglegaps,        {0} },
  { MODKEY|Mod1Mask|ShiftMask,    XK_0,          defaultgaps,       {0} },
  { MODKEY|ShiftMask,             XK_Right,      movestack,         {.i = +1 } },
  { MODKEY|ShiftMask,             XK_Left,       movestack,         {.i = -1 } },
  { MODKEY|ShiftMask,             XK_Return,     zoom,              {0} },
  { MODKEY,                       XK_Tab,        view,              {0} },
  { MODKEY,		          XK_q,          killclient,        {0} },

  /* Layouts */
  { MODKEY,                       XK_F1,         setlayout,         {.v = &layouts[0]} },
  { MODKEY,                       XK_F2,         setlayout,         {.v = &layouts[1]} },
  { MODKEY,                       XK_F3,         setlayout,         {.v = &layouts[2]} },
  
  /* General */
  { MODKEY,                       XK_4,          view,              {.ui = ~0 } },
  { MODKEY|ShiftMask,             XK_4,          tag,               {.ui = ~0 } },
  { MODKEY,                       XK_comma,      focusmon,          {.i = -1 } },
  { MODKEY,                       XK_period,     focusmon,          {.i = +1 } },
  { MODKEY|ShiftMask,             XK_comma,      tagmon,            {.i = -1 } },
  { MODKEY|ShiftMask,             XK_period,     tagmon,            {.i = +1 } },
  { MODKEY|ShiftMask,             XK_F3,         togglescratch,     {.ui = 0 } },
  { MODKEY,                       XK_F4,         togglescratch,     {.ui = 1 } },
  { MODKEY,                       XK_F5,         togglescratch,     {.ui = 2 } },
  { MODKEY,                       XK_F6,         togglescratch,     {.ui = 3 } },
  { MODKEY,                       XK_F7,         togglescratch,     {.ui = 4 } },
  { MODKEY,                       XK_F8,         togglescratch,     {.ui = 5 } },

  /* Tags */
  TAGKEYS(                        XK_1,                             0)
  TAGKEYS(                        XK_2,                             1)
  TAGKEYS(                        XK_3,                             2)
  TAGKEYS(                        XK_4,                             3)
  TAGKEYS(                        XK_5,                             4)
  TAGKEYS(                        XK_6,                             5)
  TAGKEYS(                        XK_7,                             6)
  
  /* Forever alone, quits. */
  { MODKEY|ShiftMask,		  XK_e,		spawn,       SHCMD(".local/bin/powermenu") },
  { MODKEY|ShiftMask,             XK_r,          quit,      	    {0} },
  { MODKEY,				  XK_Caps_Lock,	spawn,	     SHCMD("kill -36 dwmblocks") },
  { MODKEY|ShiftMask,             XK_p,          exitdwm,      	    {0} },



};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
  { ClkButton,            0,              Button1,        spawn,          {.v = termcmd } },
  { ClkButton,            0,              Button3,        spawn,          {.v = dmenucmd } },
  { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
  { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
  { ClkWinTitle,          0,              Button2,        zoom,           {0} },
  { ClkStatusText,        0,              Button1,        sigstatusbar,   {.i = 1} },
  { ClkStatusText,        0,              Button2,        sigstatusbar,   {.i = 2} },
  { ClkStatusText,        0,              Button3,        sigstatusbar,   {.i = 3} },
  { ClkStatusText,        0,              Button4,        sigstatusbar,   {.i = 4} },
  { ClkStatusText,        0,              Button5,        sigstatusbar,   {.i = 5} },
  { ClkStatusText,        ShiftMask,      Button1,        sigstatusbar,   {.i = 6} },
  { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
  { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
  { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
  { ClkTagBar,            0,              Button1,        view,           {0} },
  { ClkTagBar,            0,              Button3,        toggleview,     {0} },
  { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
  { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
