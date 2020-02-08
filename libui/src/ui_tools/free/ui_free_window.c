/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_free_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 15:38:38 by gsmith            #+#    #+#             */
/*   Updated: 2020/02/02 18:16:43 by alerandy         ###   ########.fr       */
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
	SDL_FreeSurface(win->surf);
	SDL_DestroyWindow(win->sdl_ptr);
	rb_clear_tree(&(win->elements), &ui_free_elem);
	ft_memdel(&win_ptr);
}
