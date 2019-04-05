#include "libui.h"

int init_window(size_t w, size_t h, char *title, t_win *win)
{
	if (SDL_Init(SDL_INIT_VIDEO) || !(win->w = SDL_CreateWindow(title,
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h,
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE)))
		return (-1);
	win->s = SDL_GetWindowSurface(win->w);
	return (0);
}

t_win *ui_new_window()
{
	t_win     *win;

  win = ft_memalloc(sizeof(t_win));
	if (init_window(500, 500, "coucou", win))
		return(win);
	ft_memset(win->s->pixels, 0xfff,
		(sizeof(int) * win->s->w * win->s->h));
	SDL_UpdateWindowSurface(win->w);
  return(win);
}