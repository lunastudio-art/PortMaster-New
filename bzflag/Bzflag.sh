#!/bin/bash

if [ -d "/opt/system/Tools/PortMaster/" ]; then
  controlfolder="/opt/system/Tools/PortMaster"
elif [ -d "/opt/tools/PortMaster/" ]; then
  controlfolder="/opt/tools/PortMaster"
else
  controlfolder="/roms/ports/PortMaster"
fi

source $controlfolder/control.txt

get_controls

GAMEDIR=/$directory/ports/bzflag

## Game does not adhere to XDG Standard, so manually link
## Make sure to create the /conf/.bzf folders 
$ESUDO rm -rf ~/.bzf
ln -sfv $GAMEDIR/conf/.bzf ~/


export TEXTINPUTINTERACTIVE="Y"

cd $GAMEDIR

$ESUDO chmod 666 /dev/uinput
$GPTOKEYB "bzflag" -c "./bzflag.gptk" &

LD_LIBRARY_PATH="$PWD/libs" SDL_GAMECONTROLLERCONFIG="$sdl_controllerconfig" ./bzflag 2>&1 | tee ./log.txt

$ESUDO kill -9 $(pidof gptokeyb)
$ESUDO systemctl restart oga_events &
printf "\033c" > /dev/tty0