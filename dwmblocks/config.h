//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon		Command					Update Interval		Update Signal*/
	{"",        "echo \"\"", 			0,					0},
	{"",		"sb_network_traffic",	1,					0},
	{"",		"sb_connection_status",	300,				0},
	{"",		"sb_updates",			1800,				0},
	{"",		"sb_controller_battery",60,					0},
	{"",		"sb_ram_usage",			60,					0},
	{"",		"sb_weather",			300,				0},
	{"",		"sb_temperature",		60,					0},
	{"",		"sb_volume",			0,					2},
	{"",		"sb_datum",				60,					0},
	{"",		"sb_up_time",			60,					0},
};

//Sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char *delim = " │ ";

// Have dwmblocks automatically recompile and run when you edit this file in
// vim with the following line in your vimrc/init.vim:

// autocmd BufWritePost ~/.local/src/dwmblocks/config.h !cd ~/.local/src/dwmblocks/; sudo make install && { killall -q dwmblocks;setsid dwmblocks & }
