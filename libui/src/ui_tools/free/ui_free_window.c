/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_free_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 15:38:38 by gsmith            #+#    #+#             */
/*   Updated: 2019/06/06 16:16:29 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libui_tools.h"

void	ui_free_window(void *win_ptr)
{
	t_ui_win	*win;

	if (!win_ptr)
		return ;
	win = (t_ui_win *)win_ptr;
	SDL_DestroyWindow(win->sdl_ptr);
/*
** TODO
** 	rb_clear_tree(&(win->elem), &ui_free_elem);
*/
	ft_memdel(&win_ptr);
}
