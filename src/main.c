#include "guimp.h"

int init_window(size_t w, size_t h, char *title, t_win *win)
{
	if (SDL_Init(SDL_INIT_VIDEO) || !(win->w = SDL_CreateWindow(title,
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h,
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE)))
		return (-1);
	win->s = SDL_GetWindowSurface(win->w);
	return (0);
}

int main()
{
	t_win win;
	SDL_Event e;
	int flag;

	if (init_window(500, 500, "coucou", &win))
		return(-1);

	while(1)
	{
		flag = 1;
		while (flag || SDL_PollEvent(&e))
		{
			state = (Uint8*)SDL_GetKeyboardState(NULL);
			if (e.type == SDL_QUIT || (e.type == SDL_KEYDOWN &&
				e.key.keysym.sym == SDLK_ESCAPE))
				exit(1);
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN && win->ed)
				exit(1);
			flag = 0;
		}
		ft_memset(win->s->pixels, 0xb0,
			(sizeof(int) * win->s->w * win->s->h) / 2);
		ft_memset(&(win->s->pixels[(sizeof(int) * win->s->w * win->s->h)
			/ 2]), 0x00, (sizeof(int) * win->s->w * win->s->h) / 2);
		SDL_UpdateWindowSurface(win->w);
	}
}