#! /bin/sh

while true
do
  xsetroot -name "`getStatusBar`"
  sleep 1
done &
#update-wallpaper-how-to
set-background $HDD_HOME/Documents/blenderProjects/un/UN_vienna5_noise.png

[ -f ~/.xprofile ] && . ~/.xprofile

dunst -config ~/.config/dunst/dunstrc &

exec dwm
