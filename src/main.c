#include "guimp.h"

int main()
{
	t_ui_univers	*univ;
	t_ui_win_param	param;
	t_ui_win		*win;
	int				flag;
	SDL_Event		e;

	param.coord[0] = 500;
	param.coord[1] = 500;
	param.dim[0] = 720;
	param.dim[1] = 480;
	param.options = SDL_WINDOW_RESIZABLE;
	if (!(univ = ui_init_univers()))
		exit(1);
	if (!(win = ui_new_window(univ, param, "Hello toast")))
		ui_quit_univers(&univ, 1, "Could not retrieve new window. eoe.");
	//ui_del_window(&win);
	while(1)
	{
		flag = 1;
		while (flag || SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT || (e.type == SDL_KEYDOWN && \
						e.key.keysym.sym == SDLK_ESCAPE))
				ui_quit_univers(&univ, 0, "bye");
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN)
				ui_quit_univers(&univ, 0, "bye bye");
			flag = 0;
		}
	}
}
