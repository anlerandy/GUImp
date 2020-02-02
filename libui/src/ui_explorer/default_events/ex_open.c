/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 13:09:21 by alerandy          #+#    #+#             */
/*   Updated: 2020/02/02 16:54:09 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"
#include "libui_tools.h"
#include "libui_explorer.h"
#include "libui_layers.h"
#include "mini_ls.h"
#include "ui_shared.h"

void	open_folder(t_ui_univers *univers, t_ui_folder **folder, char *path)
{
	t_ui_folder	*tmp;

	ui_render_layer(&(*folder)->win, (*folder)->background);
	tmp = ui_open_folder(univers, path, (*folder)->win);
	ui_free_folder(folder);
	*folder = tmp;
}

void	open_element(t_ui_univers *univers, t_ui_folder *folder, char *path)
{
	t_ui_win	*image;

	if (!(image = ui_open_image(univers, path)))
		return ;
	ui_block_daughter(univers, folder->win->id, image->id);
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
	if (!folder || !(selected = folder->selected))
		return ;
	ls = folder->ls;
	if (!!(path = NULL) || folder->layers[selected]->index == 3)
		return ;
	file = ls->files[selected - 1];
	if (!ft_strcmp(file, "..") && ft_strlen(file) == 2)
		path = get_previous_path(ls->path);
	else if (!ft_strcmp(file, ".") && ft_strlen(file) == 1)
		path = ft_strdup(ls->path);
	else
		path = ft_strjoin(ls->path, file);
	if (folder->layers[selected]->index == 1)
		open_folder(*univers, &folder, path);
	else if (folder->layers[selected]->index == 2)
		open_element(*univers, folder, path);
	ft_strdel(&path);
}
