/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 20:43:32 by alerandy          #+#    #+#             */
/*   Updated: 2019/05/10 16:48:37 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"
#include <stdio.h>

int main()
{
	t_ui_univers	*univ;
	t_ui_win_param	param[5];
	t_ui_win		*win;
	t_ui_win		*old;
	int				flag;
	SDL_Event		e;
	t_png			png;

	ft_bzero(param, sizeof(param));
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

	png = ui_getpng("/Users/alerandy/GUImp/libui/src/ui_png/test/test5.png");
	param[3].coord[0] = 200;
	param[3].coord[1] = 250;
	param[3].dim[0] = png.header.width;
	param[3].dim[1] = png.header.height;
	param[3].options = SDL_WINDOW_RESIZABLE;
	if (!(univ = ui_init_univers()))
		exit(1);
	flag = -1;
	while (++flag < 4)
	{
		if (!(win = ui_new_window(univ, param[flag], "Hello toast")))
			ui_quit_univers(&univ, 1, "Could not retrieve new window. eoe.");
		printf("win: %d, %p, %p\n", win->id, win, win->sdl_ptr);
		if (flag == 3)
		{
			ft_memcpy(win->surf->pixels, png.pixels, png.pixel_count * sizeof(unsigned));
			SDL_UpdateWindowSurface(win->sdl_ptr);
		}
	}
	old = ui_get_focused_window(univ);
	while(1)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT || (e.type == SDL_KEYDOWN && \
						e.key.keysym.sym == SDLK_ESCAPE))
				ui_quit_univers(&univ, 0, "bye");
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN)
				ui_quit_univers(&univ, 0, "bye bye");
			if (!(win = ui_get_focused_window(univ)))
				ft_putendl("Window introuvable.");
			else if (win != old)
			{
				printf("\nfocus: %d, %p\n", win->id, win);
				old = win;
			}
			if (win)
				SDL_UpdateWindowSurface(win->sdl_ptr);
		}
	}
}
