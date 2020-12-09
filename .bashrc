#! /bin/sh
# If not running interactively, don't do anything
[[ $- != *i* ]] && return

alias ls='ls --color=auto'
alias ll='ls -al'
alias cal='cal -m'

teal="\[\e[36m\]"
purple="\[\e[35m\]"
blue="\[\e[34m\]"
nocolor="\[\e[m\]"

PS1="$teal\u$nocolor$purple@\h $blue\w$nocolor ⫸ "

# >>> Added by cnchi installer
BROWSER=/usr/bin/firefox
EDITOR=/usr/bin/vim

[ -s "$HOME/.bashInit" ] && source "$HOME/.bashInit"
[ -s "$HOME/.gitShortcuts" ] &&  source "$HOME/.gitShortcuts"
[ -s "$HOME/.lfcd" ] && source "$HOME/.lfcd"
