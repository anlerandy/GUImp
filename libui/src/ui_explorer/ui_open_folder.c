/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_open_folder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:50:04 by alerandy          #+#    #+#             */
/*   Updated: 2020/02/08 17:14:45 by alerandy         ###   ########.fr       */
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
#include "libui_events.h"
#include "ui_shared.h"
#include "libui_draw.h"

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
	t_ui_layer		*layer;

	if (!univers || !(folder = ui_get_folder(path ? path : univers->pwd, NULL)))
		return (NULL);
	if ((!win || (win->surf->w <= 300 || win->surf->h <= 80)) \
			&& !(win = ui_new_window(univers, \
				(t_ui_win_param){0, 0, 800, 600, UI_WINDOW_SHOWN}, "Explorer")))
		return (NULL);
	folder->background = ui_rect_to_layer((t_ui_draw_param){win->surf->w, \
										win->surf->h, 0, 0, 0xff01003b, 0, 0});
	layer = ui_layer_from_window(win);
	ui_layer_into_layer(folder->background, layer);
	ui_free_layer(&layer);
	folder->win = win;
	ui_render_folder(folder);
	set_explorer_event(univers, folder);
	return (folder);
}

void						enter_it(t_ui_univers **univers, void *data, \
								t_ui_event_data event)
{
	t_ui_folder		**fld;
	char			*path;
	int				slc;
	char			*f;

	(void)event;
	fld = (t_ui_folder **)data;
	slc = (*fld)->selected;
	if (!!(path = NULL) || !slc || (*fld)->layers[slc]->index == 3)
		return ;
	if (!ft_strcmp((f = (*fld)->ls->files[slc - 1]), "..") && ft_strlen(f) == 2)
		path = get_previous_path((*fld)->ls->path);
	else if (!ft_strcmp(f, ".") && ft_strlen(f) == 1)
		path = ft_strdup((*fld)->ls->path);
	else
		path = ft_strjoin((*fld)->ls->path, f);
	if ((*fld)->layers[slc]->index == 1)
		open_folder(*univers, fld, path);
	else
	{
		ft_strdel(&((*fld)->ls->path));
		(*fld)->ls->path = ft_strdup(path);
		ui_stop_watch(*univers);
	}
	ft_strdel(&path);
}

char						*ui_path_from_folder(t_ui_univers *univ, \
													char *path, t_ui_win *win)
{
	t_ui_folder		*fld;
	t_ui_win		*w;
	char			*target;

	fld = ui_open_folder(univ, path, win);
	w = fld->win;
	ui_new_event(univ, (t_ui_new_event){0x300, '\r', w}, &enter_it, &fld);
	ui_new_event(univ, (t_ui_new_event){0x300, '\033', w}, &close_n_stop, &fld);
	ui_new_event(univ, (t_ui_new_event){0x200, 14, w}, &close_n_stop, &fld);
	if (univ->splash)
	{
		SDL_HideWindow(univ->splash->sdl_ptr);
		SDL_ShowWindow(w->sdl_ptr);
		SDL_UpdateWindowSurface(w->sdl_ptr);
	}
	ui_watch_events(&univ);
	target = fld->ls->path ? ft_strdup(fld->ls->path) : NULL;
	if (univ->splash)
	{
		SDL_ShowWindow(univ->splash->sdl_ptr);
		SDL_UpdateWindowSurface(univ->splash->sdl_ptr);
	}
	ui_del_window(univ, ui_get_window_id(w));
	ui_free_folder(&fld);
	return (target);
}
