/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_del_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:40:12 by gsmith            #+#    #+#             */
/*   Updated: 2019/06/13 15:32:49 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libui_tools.h"

void		ui_del_window(t_ui_univers *univers, int win_id)
{
	t_ui_win		*win;
	void			**childs;
	unsigned int	child_id;
	unsigned int	i;

	if (!(win = rb_search_infix(univers->windows, (void *)&win_id, \
			&ui_cmp_window_id)) || win->blocked != 0)
		return ;
	childs = rb_search_all(univers->windows, (void *)&win_id, &ui_cmp_mother);
	if (childs)
	{
		i = -1;
		while (childs[++i])
		{
			child_id = ((t_ui_win *)childs[i])->id;
			rb_remove(&(univers->windows), (void *)&child_id, \
				&ui_cmp_window_id, &ui_free_window);
		}
	}
	rb_remove(&(univers->windows), (void *)&win_id, &ui_cmp_window_id, \
		&ui_free_window);
}
