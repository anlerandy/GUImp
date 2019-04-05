#include "guimp.h"

int main()
{
	t_win     *win;
	SDL_Event e;
	int       flag;

  win = ui_new_window();
  while(1)
	{
		flag = 1;
		while (flag || SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT || (e.type == SDL_KEYDOWN &&
				e.key.keysym.sym == SDLK_ESCAPE))
				exit(1);
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN)
				exit(1);
			flag = 0;
		}
		ft_memset(win->s->pixels, 0xfff,
			(sizeof(int) * win->s->w * win->s->h));
		SDL_UpdateWindowSurface(win->w);
	}
}