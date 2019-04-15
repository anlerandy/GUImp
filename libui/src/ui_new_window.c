/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_new_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 12:02:48 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/15 14:28:01 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"
#include "error.h"

t_ui_win		*ui_new_window(char *title, int coord[2], int dim[2], \
					Uint32 options)
{
	t_ui_win	*win;

	if (!(win = ft_memalloc(sizeof(t_ui_win))))
	{
		ft_putendl_fd(ERR_MALLOC, STDERR_FILENO);
		return (NULL);
	}
	if (!(win->handle = SDL_CreateWindow(title, coord[0], coord[1], \
						dim[0], dim[1], options)))
	{
		ft_putendl_fd(ERR_SDL_WIN, STDERR_FILENO);
		ft_memdel((void **)(&win));
		return (NULL);
	}
	win->options = options;
	if (!(win->surf = SDL_GetWindowSurface(win->handle)))
	{
		ft_putendl_fd(ERR_SDL_SURF, STDERR_FILENO);
		SDL_DestroyWindow(win->handle);
		ft_memdel((void **)(&win));
		return (NULL);
	}
	return (win);
}
