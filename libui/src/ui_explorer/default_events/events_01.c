/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 16:15:26 by alerandy          #+#    #+#             */
/*   Updated: 2019/08/15 10:25:30 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"
#include "libui_events.h"
#include "libui_explorer.h"
#include "libui_explorer_tools.h"
#include "mini_ls.h"
#include "ui_shared.h"

void	move_selector(t_ui_univers **univers, void *data, t_ui_event_data event)
{
	t_ui_folder		*folder;

	if (!(folder = (t_ui_folder *)data))
		return ;
	folder->selected += event.keycode == UIK_DOWN ? 1 : -1;
	if ((int)folder->selected > folder->ls->files_amount)
		folder->selected = 1;
	if ((int)folder->selected <= 0)
		folder->selected = folder->ls->files_amount;
	ui_render_folder(folder);
	(void)univers;
}

void	close_explorer(t_ui_univers **univers, void *data, \
								t_ui_event_data event)
{
	t_ui_folder		*folder;

	if ((folder = (t_ui_folder *)data))
		ui_free_folder(&folder);
	ui_del_window(*univers, event.win_id);
}

void	set_explorer_event(t_ui_univers *univers, t_ui_folder *folder)
{
	t_ui_new_event	eve_param;
	t_ui_win		*win;

	if (!(win = folder->win))
		return ;
	eve_param = (t_ui_new_event){UI_EVENT_KEYDOWN, UIK_UP, win};
	ui_new_event(univers, eve_param, &move_selector, folder);
	eve_param.event = UIK_DOWN;
	ui_new_event(univers, eve_param, &move_selector, folder);
	eve_param.event = UIK_RETURN;
	eve_param.type = UI_EVENT_KEYUP;
	ui_new_event(univers, eve_param, &open_selection, folder);
	eve_param.event = UIK_ESCAPE;
	ui_new_event(univers, eve_param, &close_explorer, folder);
	eve_param.type = UI_EVENT_QUIT;
	eve_param.event = 0;
	ui_new_event(univers, eve_param, &close_explorer, folder);
}

void	close_and_stop(t_ui_univers **univers, void *data, \
								t_ui_event_data event)
{
	t_ui_folder		*folder;

	folder = *(t_ui_folder **)data;
	free(folder->ls->path);
	folder->ls->path = NULL;
	ui_del_window(*univers, event.win_id);
	ui_stop_watch(*univers);
}
