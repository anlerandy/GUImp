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
	t_ui_univers	*univ;
	t_ui_win_param	param[3];
	t_ui_win		*win;
	t_ui_win		*old;
	int				flag;
	SDL_Event		e;
	SDL_Surface		*test;

	test = SDL_CreateRGBSurface(0, 20, 10, 32,
                                   0x000000ff, 0x0000ff00, 0x00ff0000, 0xff000000);
    if (test == NULL) {
        SDL_Log("SDL_CreateRGBSurface() failed: %s", SDL_GetError());
        exit(1);
    }
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
	int i = -1;
	int j = 0;
	int *surf;
	surf = test->pixels;

	while (i++ < 10 && (j = -1))
		while (j++ < 20)
			surf[i * test->w + j] = (0x00050505 * j) & 0x00ffffff;
	test->pixels = surf;
	ui_surf_to_win_scale(test, win, (t_ipos){50, 100}, 2);
	ui_surf_to_win_scale(test, win, (t_ipos){200, 200}, 5);

	ui_surf_to_win_scale(test, win, (t_ipos){200, 100}, 1.5);

	ui_surf_to_window(test, win, (t_ipos){10, 10});
	flag = -1;
	old = ui_get_focused_window(univ);
	SDL_UpdateWindowSurface(win->sdl_ptr);
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
	}
}
