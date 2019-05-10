/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_cmp_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 17:15:36 by gsmith            #+#    #+#             */
/*   Updated: 2019/05/10 19:06:22 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int		ui_cmp_window_id(void *ptr_win, void *ptr_id)
{
	int			id;
	t_ui_win	*win;

	if (!ptr_win && !ptr_id)
		return (0);
	if (!ptr_win)
		return (-1);
	if (!ptr_id)
		return (1);
	win = (t_ui_win *)ptr_win;
	id = *(int *)ptr_id;
	return (win->id - id);
}

int		ui_cmp_window_flag(void *ptr_win, void *ptr_flag)
{
	t_ui_win	*win;
	unsigned	*flag;

	win = (t_ui_win *)ptr_win;
	flag = ((unsigned *)ptr_flag);
	if (SDL_GetWindowFlags(win->sdl_ptr) & *flag)
		return (0);
	return (1);
}

int		ui_cmp_window(void *ptr_a, void *ptr_b)
{
	t_ui_win	*win_a;
	t_ui_win	*win_b;

	if (!ptr_a && !ptr_b)
		return (0);
	if (!ptr_a)
		return (-1);
	if (!ptr_b)
		return (1);
	win_a = (t_ui_win *)ptr_a;
	win_b = (t_ui_win *)ptr_b;
	return (win_a->id - win_b->id);
}
