/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_del_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:40:12 by gsmith            #+#    #+#             */
/*   Updated: 2019/08/15 10:31:20 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libui_tools.h"

static void	clear_child(t_ui_univers *univers, int win_id)
{
	t_ui_win		**childs;
	unsigned int	child_id;
	unsigned int	i;

	if (!(childs = (t_ui_win **)rb_search_all(univers->windows, \
			(void *)&win_id, &ui_cmp_mother)))
		return ;
	i = -1;
	while (childs[++i])
	{
		child_id = childs[i]->id;
		rb_remove(&(univers->windows), (void *)&child_id, \
			&ui_cmp_window_id, &ui_free_window);
	}
	ft_memdel((void **)&childs);
}

static void	clear_block(t_ui_univers *univers, int win_id)
{
	t_ui_win		**blocked;
	unsigned int	i;

	if (!(blocked = (t_ui_win **)rb_search_all(univers->windows, \
			(void *)&win_id, &ui_cmp_blocker)))
		return ;
	i = -1;
	while (blocked[++i])
		blocked[i]->blocked = 0;
	ft_memdel((void **)&blocked);
}

void		ui_del_window(t_ui_univers *univers, int win_id)
{
	t_ui_win		*win;

	if (!(win = rb_search_infix(univers->windows, (void *)&win_id, \
				&ui_cmp_window_id)) || win->blocked != 0)
		return ;
	rb_clear_tree(&(win->events), &ui_free_event);
	clear_child(univers, win_id);
	clear_block(univers, win_id);
	rb_remove(&(univers->windows), (void *)&win_id, &ui_cmp_window_id, \
		&ui_free_window);
	if (!univers->windows)
		ui_stop_watch(univers);
}

void		ui_clear_all_windows(t_ui_univers *univers)
{
	rb_clear_tree(&(univers->windows), &ui_free_window);
}
