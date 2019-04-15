/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_del_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:40:12 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/15 13:53:17 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void		ui_del_window(t_ui_win **win_ptr)
{
	t_ui_win	*win;

	if (!win_ptr)
		return ;
	win = *win_ptr;
	SDL_DestroyWindow(win->handle);
	ft_memdel((void **)(win_ptr));
}
