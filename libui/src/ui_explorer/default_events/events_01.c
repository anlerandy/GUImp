/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 16:15:26 by alerandy          #+#    #+#             */
/*   Updated: 2019/08/11 17:13:22 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"
#include "libui_events.h"
#include "libui_explorer.h"
#include "mini_ls.h"

// UIK_DOWN
// UIK_UP
// UIK_KP_ENTER
// UIK_RETURN

void	move_selector(t_ui_univers **univers, void *data, t_ui_event_data event)
{
	t_ui_folder		*folder;

	folder = (t_ui_folder *)data;
	folder->selected += event.keycode == UIK_DOWN ? 1 : -1;
	if ((int)folder->selected > folder->ls->files_amount)
		folder->selected = 1;
	if ((int)folder->selected == 0)
		folder->selected = folder->ls->files_amount;
	ui_render_folder(folder);
	(void)univers;
}

void	set_explorer_event(t_ui_univers *univers, t_ui_folder *folder)
{
	t_ui_new_event	eve_param;
	unsigned		id;
	t_ui_win		*win;

	if (!(win = folder->win))
		return ;
	id = ui_get_window_id(win);
	eve_param = (t_ui_new_event){UI_EVENT_KEYUP, UIK_UP, win};
	if (ui_new_event(univers, eve_param, &move_selector, folder))
		return (ui_del_window(univers, id));
	eve_param.event = UIK_DOWN;
	if (ui_new_event(univers, eve_param, &move_selector, folder))
		return (ui_del_window(univers, id));
}
