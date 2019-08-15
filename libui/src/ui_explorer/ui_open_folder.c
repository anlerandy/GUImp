/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_open_folder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:50:04 by alerandy          #+#    #+#             */
/*   Updated: 2019/08/15 10:58:52 by alerandy         ###   ########.fr       */
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

void						enter_it(t_ui_univers **univers, void *data, \
								t_ui_event_data event)
{
	t_ui_folder		**folder;
	char			*path;
	int				selected;
	char			*file;

	(void)event;
	folder = (t_ui_folder **)data;
	selected = (*folder)->selected;
	if (!selected || (*folder)->layers[selected]->index == 3)
		return ;
	path = NULL;
	file = (*folder)->ls->files[selected - 1];
	if (!ft_strcmp(file, "..") && ft_strlen(file) == 2)
		path = get_previous_path((*folder)->ls->path);
	else if (!ft_strcmp(file, ".") && ft_strlen(file) == 1)
		path = ft_strdup((*folder)->ls->path);
	else
		path = ft_strjoin((*folder)->ls->path, file);
	if ((*folder)->layers[selected]->index == 1)
		open_folder(*univers, folder, path);
	else
	{
		ft_strdel(&((*folder)->ls->path));
		(*folder)->ls->path = ft_strdup(path);
		ui_stop_watch(*univers);
	}
	ft_strdel(&path);
}

char						*ui_path_from_folder(t_ui_univers *univers, \
													char *path, t_ui_win *win)
{
	t_ui_folder		*folder;
	t_ui_new_event	event;
	char			*target;

	folder = ui_open_folder(univers, path, win);
	event = (t_ui_new_event){UI_EVENT_KEYDOWN, UIK_RETURN, folder->win};
	ui_new_event(univers, event, &enter_it, &folder);
	event.event = UIK_ESCAPE;
	ui_new_event(univers, event, &close_and_stop, &folder);
	event.type = UI_EVENT_WINDOW;
	event.event = UI_WINDOWEVENT_CLOSE;
	ui_new_event(univers, event, &close_and_stop, &folder);
	if (univers->splash)
	{
		SDL_HideWindow(univers->splash->sdl_ptr);
		SDL_ShowWindow(folder->win->sdl_ptr);
		SDL_UpdateWindowSurface(folder->win->sdl_ptr);
	}
	ui_watch_events(&univers);
	target = folder->ls->path ? ft_strdup(folder->ls->path) : NULL;
	if (univers->splash)
	{
		SDL_ShowWindow(univers->splash->sdl_ptr);
		SDL_UpdateWindowSurface(univers->splash->sdl_ptr);
	}
	ui_del_window(univers, ui_get_window_id(folder->win));
	ui_free_folder(&folder);
	return (target);
}
