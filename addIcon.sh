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
	echo "[Desktop Entry]
Encoding=UTF-8
Terminal=0
Exec="$(pwd)"/guimp
Path="$(pwd)"
Icon="$(pwd)"/assets/ico.png
Type=Application
Categories=Graphics;
StartupNotify=true
Name=Guimp
GenericName=Graphic User Interface 'MP'" > Guimp.desktop && \
	chmod +x Guimp.desktop
fi