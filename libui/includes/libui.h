#ifndef LIBUI_H
# define LIBUI_H

#include "SDL.h"
#include "libft.h"

typedef struct	s_win
{
	SDL_Surface   *s;
	SDL_Window	  *w;
}               t_win;

t_win           *ui_new_window();

#endif