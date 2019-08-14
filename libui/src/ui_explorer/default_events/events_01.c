/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 16:15:26 by alerandy          #+#    #+#             */
/*   Updated: 2019/08/14 10:38:45 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"
#include "libui_events.h"
#include "libui_explorer.h"
#include "mini_ls.h"
#include "libui_layers.h"
#include "ui_shared.h"

void	move_selector(t_ui_univers **univers, void *data, t_ui_event_data event)
{
	t_ui_folder		*folder;

	folder = (t_ui_folder *)data;
	folder->selected += event.keycode == UIK_DOWN ? 1 : -1;
	if ((int)folder->selected > folder->ls->files_amount)
		folder->selected = 1;
	if ((int)folder->selected <= 0)
		folder->selected = folder->ls->files_amount;
	ui_render_folder(folder);
	(void)univers;
}

void	open_folder(t_ui_univers *univers, t_ui_folder **folder, char *path)
{
	t_ui_folder	*tmp;

	tmp = *folder;
	ui_open_folder(univers, path, (*folder)->win);
	ui_free_folder(folder);
	folder = &tmp;
}

void	open_selection(t_ui_univers **univers, void *data, \
								t_ui_event_data event)
{
	t_ui_folder		*folder;
	char			*path;
	t_ls_folder		*ls;
	int				selected;
	char			*file;

	(void)event;
	folder = (t_ui_folder *)data;
	if (!(selected = folder->selected))
		return ;
	ls = folder->ls;
	if (folder->layers[selected]->index == 3)
		return ;
	path = NULL;
	file = ls->files[selected - 1];
	if (!ft_strcmp(file, "..") && ft_strlen(file) == 2)
		path = get_previous_path(ls->path);
	else if (!ft_strcmp(file, ".") && ft_strlen(file) == 1)
		path = ft_strdup(ls->path);
	else
		path = ft_strjoin(ls->path, file);
	if (folder->layers[selected]->index == 1)
		open_folder(*univers, &folder, path);
	ft_strdel(&path);
}

void	set_explorer_event(t_ui_univers *univers, t_ui_folder *folder)
{
	t_ui_new_event	eve_param;
	unsigned		id;
	t_ui_win		*win;

	if (!(win = folder->win))
		return ;
	id = ui_get_window_id(win);
	eve_param = (t_ui_new_event){UI_EVENT_KEYDOWN, UIK_UP, win};
	if (ui_new_event(univers, eve_param, &move_selector, folder))
		return (ui_del_window(univers, id));
	eve_param.event = UIK_DOWN;
	if (ui_new_event(univers, eve_param, &move_selector, folder))
		return (ui_del_window(univers, id));
	eve_param.event = UIK_RETURN;
	eve_param.type = UI_EVENT_KEYUP;
	if (ui_new_event(univers, eve_param, &open_selection, folder))
		return (ui_del_window(univers, id));
}
