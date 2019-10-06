/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_block_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 13:23:56 by alerandy          #+#    #+#             */
/*   Updated: 2019/08/14 13:30:06 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"
#include "libui_tools.h"

void		ui_block_daughter(t_ui_univers *univers, unsigned int mother, \
						unsigned int blocker)
{
	t_ui_win		**blocked_wins;
	unsigned int	i;

	if (!(blocked_wins = (t_ui_win **)rb_search_all(univers->windows, \
			(void*)&mother, &ui_cmp_mother)))
		return ;
	i = -1;
	while (blocked_wins[++i])
	{
		if (blocked_wins[i]->blocked)
			continue ;
		blocked_wins[i]->blocked = blocker;
		ui_block_daughter(univers, blocked_wins[i]->id, blocker);
	}
	ft_memdel((void **)&blocked_wins);
}
