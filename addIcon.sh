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