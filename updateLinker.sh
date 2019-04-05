#!/bin/sh
if [ $(uname -s) = "Darwin" ]
then
	install_name_tool -change /usr/local/lib/libSDL2-2.0.0.dylib @executable_path/libui/SDL/build/.libs/libSDL2-2.0.0.dylib guimp
fi
