#! /bin/sh

while true
do
  xsetroot -name "`getStatusBar`"
  sleep 3
done &
#update-wallpaper-how-to
set-background $HDD_HOME/Documents/Media/blenderProjects/un/UN_vienna7_noise.png

[ -f ~/.xprofile ] && . ~/.xprofile

dunst -config ~/.config/dunst/dunstrc &

exec dwm
