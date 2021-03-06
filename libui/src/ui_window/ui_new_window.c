/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_new_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 12:02:48 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/15 10:43:58 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui_error.h"
#include "libft.h"
#include "libui_tools.h"
#include <limits.h>
#include "ui_shared.h"

static t_ui_win	*abort_new_window(char *err_msg, void **win_ptr, \
					SDL_Window *sdl_ptr)
{
	ft_putendl_fd(err_msg, STDERR_FILENO);
	if (sdl_ptr)
		SDL_DestroyWindow(sdl_ptr);
	if (win_ptr)
		ft_memdel(win_ptr);
	return (NULL);
}

t_ui_win		*ui_new_window(t_ui_univers *univers, t_ui_win_param param, \
					char *title)
{
	t_ui_win	*win;

	if (param.w < 90 || param.h < 90)
		return (abort_new_window("Min width & height size: 90.", NULL, NULL));
	if (!(win = ft_memalloc(sizeof(t_ui_win))))
		return (abort_new_window(ERR_MALLOC, NULL, NULL));
	if (univers->splash)
		param.options = param.options | SDL_WINDOW_HIDDEN;
	if (!(win->sdl_ptr = SDL_CreateWindow(title, param.x, param.y, param.w, \
				param.h, param.options)))
		return (abort_new_window(ERR_SDL_WIN, (void **)&win, NULL));
	if (!(win->surf = SDL_GetWindowSurface(win->sdl_ptr)))
		return (abort_new_window(ERR_SDL_SURF, (void **)&win, win->sdl_ptr));
	if (!(win->id = SDL_GetWindowID(win->sdl_ptr)))
		return (abort_new_window(ERR_SDL_WIN_ID, (void **)&win, win->sdl_ptr));
	ui_memuset(win->surf->pixels, 0x00000000, win->surf->h * win->surf->w);
	SDL_UpdateWindowSurface(win->sdl_ptr);
	rb_insert(&(univers->windows), (void *)win, &ui_cmp_window);
	win->id_next_elem = 1;
	win->mother = 0;
	win->blocked = 0;
	return (win);
}

t_ui_win		*ui_new_daughter_win(t_ui_univers *univers, char *title, \
					t_ui_win_param param, unsigned int mother_id)
{
	t_ui_win	*win;

	if (!(win = ui_new_window(univers, param, title)))
		return (NULL);
	win->mother = mother_id;
	return (win);
}

t_ui_win		*ui_new_blocking_win(t_ui_univers *univers, char *title, \
					t_ui_win_param param, unsigned int blocked)
{
	t_ui_win		*win;
	t_ui_win		*blocked_win;
	t_ui_win		**blocked_wins;
	unsigned int	i;

	if (!(win = ui_new_window(univers, param, title)))
		return (NULL);
	if (!(blocked_win = ui_get_window_by_id(univers, blocked)))
	{
		i = 0;
		if (!(blocked_wins = (t_ui_win **)rb_search_all(univers->windows, \
				(void *)&i, &ui_cmp_blocker)))
			return (win);
		while (blocked_wins[i])
			blocked_wins[i++]->blocked = win->id;
		win->blocked = 0;
		ft_memdel((void **)&blocked_wins);
		return (win);
	}
	blocked_win->blocked = win->id;
	ui_block_daughter(univers, blocked_win->id, win->id);
	win->blocked = 0;
	return (win);
}
