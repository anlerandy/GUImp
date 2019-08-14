/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_open_folder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:50:04 by alerandy          #+#    #+#             */
/*   Updated: 2019/08/14 11:59:19 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_ls.h"
#include "libui.h"
#include "libui_ttf.h"
#include "libui_explorer.h"
#include <fcntl.h>
#include "libui_tools.h"
#include "libui_explorer_tools.h"
#include "libui_layers.h"

static inline t_ui_layer	*get_text_layer(char *file, char *path)
{
	unsigned	color;
	int			fd;
	DIR			*dir;
	char		*tmp;
	t_ui_layer	*layer;

	if (!file || !path)
		return (NULL);
	tmp = ft_strjoin(path, file);
	if ((dir = opendir(tmp)) && !closedir(dir))
		color = 0xff00ff00;
	else if ((fd = open(tmp, O_RDONLY)) > 0 && !close(fd))
		color = 0xff00eaff;
	else
		color = 0xffff0000;
	ft_strdel(&tmp);
	if (!(layer = ui_ttf_to_layer(NULL, file, \
								(t_ui_ttf_param){0, 0, 0, 30, 0, 0, color})))
		return (NULL);
	if (color == 0xff00eaff || color == 0xff00ff00)
		layer->index = color == 0xff00eaff ? 2 : 1;
	else
		layer->index = 3;
	return (layer);
}

t_ui_folder					*ui_get_folder(char *path, t_ui_win *win)
{
	int				i;
	t_ui_folder		*folder;

	i = -1;
	if (!path || !(folder = ft_memalloc(sizeof(t_ui_folder))))
		return (NULL);
	if (!(folder->ls = ft_get_folder(path)))
	{
		ui_free_folder(&folder);
		return (NULL);
	}
	if (!(folder->layers = ft_memalloc((folder->ls->files_amount + 2) \
											* sizeof(t_ui_layer *))))
	{
		ui_free_folder(&folder);
		return (NULL);
	}
	folder->layers[0] = ui_ttf_to_layer(NULL, folder->ls->path, \
			(t_ui_ttf_param){0, 0, 0, 30, 0, 0, 0xffa1a1a1});
	while (folder->ls->files[++i])
		folder->layers[i + 1] = get_text_layer(folder->ls->files[i], \
														folder->ls->path);
	if (win)
		folder->win = NULL;
	return (folder);
}

t_ui_folder					*ui_open_folder(t_ui_univers *univers, char *path, \
																t_ui_win *win)
{
	t_ui_folder		*folder;

	if (!univers)
		return (NULL);
	if (!(folder = ui_get_folder(path ? path : univers->pwd, NULL)))
		return (NULL);
	if (win)
	{
		if (win->surf->w <= 300 || win->surf->h <= 80)
			win = NULL;
		else
			folder->background = ui_layer_from_window(win);
	}
	if (!win && !(win = ui_new_window(univers, \
							(t_ui_win_param){0, 0, 800, 600, UI_WINDOW_SHOWN}, \
								"LIBUI Explorer")))
		return (NULL);
	else
		folder->win = win;
	ui_render_folder(folder);
	set_explorer_event(univers, folder);
	return (folder);
}
