/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_open_folder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:50:04 by alerandy          #+#    #+#             */
/*   Updated: 2019/07/30 23:55:24 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_ls.h"
#include "libui.h"
#include "libui_ttf.h"
#include "libui_explorer.h"
#include <fcntl.h>

static inline t_ui_layer	*get_text_layer(char *file, char *path)
{
	unsigned	color;
	int			fd;
	DIR			*dir;
	char		*tmp;

	if (!file || !path)
		return NULL;
	tmp = ft_strjoin(path, file);
	if ((dir = opendir(tmp)))
	{
		color = 0xff00ff00;
		closedir(dir);
	}
	else if ((fd = open(tmp, O_RDONLY)) > 0)
	{
		color = 0xff00eaff;
		close(fd);
	}
	else
		color = 0xffff0000;
	ft_strdel(&tmp);
	return (ui_ttf_to_layer(NULL, file, \
			(t_ui_ttf_param){0, 0, 0, 30, 0, 0, color}));
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
