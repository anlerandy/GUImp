#include "guimp.h"

int main()
{
	int			coord[2];
	int			dim[2];
	t_ui_win	*win;
	SDL_Event	e;
	int			flag;

	coord[0] = 500;
	coord[1] = 500;
	dim[0] = 720;
	dim[1] = 480;
	if (!ui_init())
		ui_quit(1);
	if (!(win = ui_new_window("hello toast", coord, dim, SDL_WINDOW_RESIZABLE)))
		ui_quit(1);
	//ui_del_window(&win);
	while(1)
	{
		flag = 1;
		while (flag || SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT || (e.type == SDL_KEYDOWN &&
						e.key.keysym.sym == SDLK_ESCAPE))
				ui_quit(0);
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN)
				ui_quit(0);
			flag = 0;
		}
	}
}
