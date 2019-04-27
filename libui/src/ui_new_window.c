/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_new_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 12:02:48 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/27 15:36:45 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include "libui.h"
#include "libui_tools.h"

t_ui_win	*ui_new_window(t_ui_univers *univers, t_ui_win_param param, \
				char *title)
{
	t_ui_win	*win;

	if (!(win = ft_memalloc(sizeof(t_ui_win))))
	{
		ft_putendl_fd(ERR_MALLOC, STDERR_FILENO);
		return (NULL);
	}
	if (!(win->sdl_ptr = \
				SDL_CreateWindow(title, param.coord[0], param.coord[1], \
					param.dim[0], param.dim[1], param.options)))
	{
		ft_putendl_fd(ERR_SDL_WIN, STDERR_FILENO);
		ft_memdel((void **)(&win));
		return (NULL);
	}
	if (!(win->surf = SDL_GetWindowSurface(win->sdl_ptr)))
	{
		ft_putendl_fd(ERR_SDL_SURF, STDERR_FILENO);
		SDL_DestroyWindow(win->sdl_ptr);
		ft_memdel((void **)(&win));
		return (NULL);
	}
	ft_memset(win->surf->pixels, 0, sizeof(int) * win->surf->h * win->surf->h);
	rb_insert(&(univers->windows), (void *)win, &ui_cmp_window);
	return (win);
}
