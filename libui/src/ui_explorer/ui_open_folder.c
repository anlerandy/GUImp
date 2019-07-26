/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_open_folder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:50:04 by alerandy          #+#    #+#             */
/*   Updated: 2019/07/26 16:56:13 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_ls.h"
#include "libui.h"
#include "libui_ttf.h"
#include "libui_explorer.h"

t_ui_folder	*ui_get_folder(char *path, t_ui_win *win)
{
	int				i;
	t_ui_folder		*folder;

	i = -1;
	if (!path || !(folder = ft_memalloc(sizeof(t_ui_folder))))
		return (NULL);
	if (!(folder->ls = ft_get_folder(path)))
	{
		ft_memdel((void**)&folder);
		return (NULL);
	}
	if (!(folder->layers = ft_memalloc((folder->ls->files_amount + 2) \
											* sizeof(t_ui_layer *))))
	{
		ft_memdel((void**)&folder);
		ft_free_folder(&folder->ls);
		return (NULL);
	}
	folder->layers[0] = ui_ttf_to_layer(NULL, folder->ls->path, \
			(t_ui_ttf_param){0, 0, 0, 30, 0, 0, 0xffa1a1a1});
	while (folder->ls->files[++i])
		folder->layers[i + 1] = ui_ttf_to_layer(NULL, folder->ls->files[i], \
			(t_ui_ttf_param){0, 0, 0, 30, 0, 0, 0xffffffff});
	if (win)
		folder->win = NULL;
	return (folder);
}

t_ui_folder	*ui_open_folder(t_ui_univers *univers, char *path, t_ui_win *win)
{
	t_ui_folder		*folder;

	if (!univers || !path)
		return (NULL);
	if (!(folder = ui_get_folder(path, NULL)))
		return (NULL);
	if (!win && !(win = ui_new_window(univers, \
							(t_ui_win_param){0, 0, 800, 600, UI_WINDOW_SHOWN}, \
								"LIBUI Explorer")))
		return (NULL);
	else
		folder->win = win;
	ui_render_folder(folder);
	return (folder);
}
