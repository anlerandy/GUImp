#include "guimp.h"

int main()
{
	t_ui_univers	*univ;
	t_ui_win_param	param[3];
	t_ui_win		*win;
	int				flag;
	SDL_Event		e;

	param[0].coord[0] = 500;
	param[0].coord[1] = 500;
	param[0].dim[0] = 720;
	param[0].dim[1] = 480;
	param[0].options = SDL_WINDOW_RESIZABLE;
	param[1].coord[0] = 0;
	param[1].coord[1] = 0;
	param[1].dim[0] = 500;
	param[1].dim[1] = 500;
	param[2].options = SDL_WINDOW_RESIZABLE;
	param[2].coord[0] = 1220;
	param[2].coord[1] = 500;
	param[2].dim[0] = 720;
	param[2].dim[1] = 480;
	param[2].options = SDL_WINDOW_RESIZABLE;
	if (!(univ = ui_init_univers()))
		exit(1);
	flag = -1;
	while (++flag < 3)
	{
		if (!(win = ui_new_window(univ, param[flag], "Hello toast")))
			ui_quit_univers(&univ, 1, "Could not retrieve new window. eoe.");
		printf("win: %d, %p\n", win->id, win);
	}
	flag = -1;
	while (++flag < 3)
	{
		win = ui_get_window_by_id(univ, flag);
		printf("win: %d, %p\n", flag, win);
	}
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
