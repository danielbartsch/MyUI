export HDD_HOME="/run/media/home/daniel"

PATH=/usr/bin/npm:$PATH
PATH=$HOME/.cargo/bin:$PATH
PATH=$HOME/.fnm:$PATH
PATH=$HOME/bin:$PATH
PATH=$HDD_HOME/Documents/Programming/MyUI/scripts/:$PATH
export PATH

eval "`fnm env --multi`"

startx
