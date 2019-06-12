/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_del_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:40:12 by gsmith            #+#    #+#             */
/*   Updated: 2019/06/12 16:18:19 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libui_tools.h"
#include "libui_tools.h"

void		ui_del_window(t_ui_univers *univers, int win_id)
{
	if (!univers)
		return ;
	rb_remove(&(univers->windows), (void *)&win_id, &ui_cmp_window_id, \
		&ui_free_window);
}

void		ui_clear_all_windows(t_ui_univers *univers)
{
	rb_clear_tree(&(univers->windows), &ui_free_window);
}
