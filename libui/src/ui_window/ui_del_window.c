/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_del_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:40:12 by gsmith            #+#    #+#             */
/*   Updated: 2019/06/06 16:50:11 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libui_tools.h"

void		ui_del_window(t_ui_univers *univers, int win_id)
{
	t_ui_win		*win;
	unsigned int	child;

	if (!univers || !(win = ui_get_window_by_id(univers, win_id)))
		return ;
	child = 0;
	if (win->child)
		child = win->child->id;
	rb_remove(&(univers->windows), (void *)&win_id, &ui_cmp_window_id, \
		&ui_free_window);
	if (child)
		return (ui_del_window(univers, child));
}
