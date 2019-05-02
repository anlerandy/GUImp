/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_cmp_window_flag.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:34:15 by gsmith            #+#    #+#             */
/*   Updated: 2019/05/02 18:50:25 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int		ui_cmp_window_flag(void *ptr_win, void *ptr_flag)
{
	t_ui_win	*win;
	Uint32		flag;

	win = (t_ui_win *)ptr_win;
	flag = (Uint32)ptr_flag;
	if (SDL_GetWindowFlags(win->sdl_ptr) & flag)
		return (0);
	return (1);
}
