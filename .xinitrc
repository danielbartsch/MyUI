#! /bin/sh

set-background $HDD_HOME/Documents/Media/blenderProjects/un/UN_vienna7_noise.png

[ -f ~/.xprofile ] && . ~/.xprofile

dunst -config ~/.config/dunst/dunstrc &

dwmblocks &

exec dwm
