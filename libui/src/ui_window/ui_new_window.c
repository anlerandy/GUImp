/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_new_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 12:02:48 by gsmith            #+#    #+#             */
/*   Updated: 2019/05/06 16:26:19 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include "libui.h"
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

	if (!(win = ft_memalloc(sizeof(t_ui_win))))
		return (abort_new_window(ERR_MALLOC, NULL, NULL));
	if (!(win->sdl_ptr = \
				SDL_CreateWindow(title, param.coord[0], param.coord[1], \
					param.dim[0], param.dim[1], param.options)))
		return (abort_new_window(ERR_SDL_WIN, (void **)&win, NULL));
	if (!(win->surf = SDL_GetWindowSurface(win->sdl_ptr)))
		return (abort_new_window(ERR_SDL_SURF, (void **)&win, win->sdl_ptr));
	win->id = SDL_GetWindowID(win->sdl_ptr);
	ft_memset(win->surf->pixels, 0, sizeof(int) * win->surf->h * win->surf->w);
	SDL_UpdateWindowSurface(win->sdl_ptr);
	rb_insert(&(univers->windows), (void *)win, &ui_cmp_window);
	return (win);
}
