/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 20:43:32 by alerandy          #+#    #+#             */
/*   Updated: 2019/05/02 21:06:35 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"
#include <stdio.h>

int main()
{
<<<<<<< HEAD
	t_ui_univers	*univ;
	t_ui_win_param	param[3];
	t_ui_win		*win;
	t_ui_win		*old;
	int				flag;
	SDL_Event		e;

	param[0].coord[0] = 0;
	param[0].coord[1] = 500;
	param[0].dim[0] = 500;
	param[0].dim[1] = 500;
	param[0].options = SDL_WINDOW_RESIZABLE;
	param[1].coord[0] = 500;
	param[1].coord[1] = 500;
	param[1].dim[0] = 500;
	param[1].dim[1] = 500;
	param[2].options = SDL_WINDOW_RESIZABLE;
	param[2].coord[0] = 1000;
	param[2].coord[1] = 500;
	param[2].dim[0] = 500;
	param[2].dim[1] = 500;
	param[2].options = SDL_WINDOW_RESIZABLE;
	if (!(univ = ui_init_univers()))
		exit(1);
	flag = -1;
	while (++flag < 3)
	{
		if (!(win = ui_new_window(univ, param[flag], "Hello toast")))
			ui_quit_univers(&univ, 1, "Could not retrieve new window. eoe.");
		printf("win: %d, %p, %p\n", win->id, win, win->sdl_ptr);
	}
	flag = -1;
	old = ui_get_focused_window(univ);
=======
	t_win		*win;
	SDL_Event	e;
	int 		flag;
	t_bmp		bmpfile;

	bmpfile = ui_getbmp("/home/woap-unix/GUImp/libui/src/ui_bmp/24bit.bmp");
	win = ui_new_window(bmpfile.info.width, bmpfile.info.height);
>>>>>>> Updated: Main.c uses bmpParser.
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
			if (!(win = ui_get_focused_window(univ)))
				ft_putendl("Window introuvable.");
			else if (win != old)
			{
				printf("\nfocus: %d, %p\n", win->id, win);
				old = win;
			}
		}
<<<<<<< HEAD
=======
		ft_memcpy(win->s->pixels, bmpfile.pixels,
				(sizeof(int) * win->s->w * win->s->h));
		SDL_UpdateWindowSurface(win->w);
>>>>>>> Updated: Main.c uses bmpParser.
	}
}
