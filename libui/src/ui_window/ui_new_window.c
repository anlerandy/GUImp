/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_new_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 12:02:48 by gsmith            #+#    #+#             */
/*   Updated: 2019/06/30 21:04:04 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui_error.h"
#include "libft.h"
#include "libui_tools.h"
#include "libui_tools.h"
#include <limits.h>

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
	win->id = SDL_GetWindowID(win->sdl_ptr);
	ft_memset(win->surf->pixels, 0, sizeof(int) * win->surf->h * win->surf->w);
	SDL_UpdateWindowSurface(win->sdl_ptr);
	rb_insert(&(univers->windows), (void *)win, &ui_cmp_window);
	return (win);
}
