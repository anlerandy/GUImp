/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse_motion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:16:29 by alerandy          #+#    #+#             */
/*   Updated: 2020/02/08 18:33:20 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"
#include "libui_tools.h"

void	callback_mouse_motion(t_ui_univers **uni, void *data, \
														t_ui_event_data event)
{
	t_ui_elem		*elem;
	t_ui_win		*win;

	(void)data;
	if (!(win = ui_get_window_by_id(*uni, event.win_id)))
		return ;
	if (win->current_elem && win->current_elem->state == UI_ELEM_STATE_HOVER)
		win->current_elem->state = UI_ELEM_STATE_ACTIVE;
	if (!(elem = ui_get_elem_by_position(win, event.x, event.y)))
		return (ui_draw_elem(win, win->current_elem));
	win->current_elem = elem;
	if (elem->state != UI_ELEM_STATE_DISABLED)
		elem->state = UI_ELEM_STATE_HOVER;
	ui_draw_elem(win, elem);
}
