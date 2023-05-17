//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
  /*Icon*/  /*Command*/  /*Update Interval*/  /*Update Signal*/
  {"",       "s_cmus",             1,               11},
  {"",       "s_upd",           3600,                8},
  {"",       "s_mic",              0,                9},
  {"",       "~/.config/suckless/dwmblocks/scripts/battery",      20,            10},
  {"",       "s_vol",              0,                7},
  {"",       "s_date",            60,               10},
  {"",       "s_net",             60,               15},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
