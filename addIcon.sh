#!/bin/sh
if [ $(uname -s) = "Darwin" ]
then
	sips -i assets/ico.png
	Derez -only icns assets/ico.png > tmpico.rsrc
	Rez -append tmpico.rsrc -o guimp
	SetFile -a C guimp
	rm -rf tmpico.rsrc
	printf "\033[1A\r\033[K\033[1A\r\033[K"
fi
if [ $(uname -s) = "Linux" ]
then
	echo "#!/usr/bin/env xdg-open
[Desktop Entry]
Encoding=UTF-8
Terminal=false
Exec="$(pwd)"/guimp
Path="$(pwd)"
Icon="$(pwd)"/assets/ico.png
Type=Application
Categories=Graphics;
StartupNotify=true
Name=Guimp
GenericName=Graphic User Interface 'MP'" > ~/.local/share/applications/Guimp.desktop && \
	chmod +x ~/.local/share/applications/Guimp.desktop
fi