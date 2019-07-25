/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_open_folder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:50:04 by alerandy          #+#    #+#             */
/*   Updated: 2019/07/25 13:53:50 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_ls.h"
#include "libui.h"
#include "libui_ttf.h"

t_ui_win	*ui_open_folder(t_ui_univers *univers, char *path)
{
	t_ls_folder		*folder;
	t_ui_win		*win;
	t_ui_layer		text;
	int				i;

	i = -1;
	if (!univers || !path)
		return (NULL);
	if (!(folder = ft_get_folder(path)))
		return (NULL);
	if (!(win = ui_new_window(univers, \
							(t_ui_win_param){0, 0, 800, 600, UI_WINDOW_SHOWN}, \
								"LIBUI Explorer")))
		return (NULL);
	while (folder->files[++i])
	{
		text = ui_ttf_to_layer(NULL, folder->files[i], \
			(t_ui_ttf_param){15, i * 35, 0, 30, 0, 0, 0xffffffff});
		ui_render_layer(&win, text);
		ui_free_layer(&text);
	}
	ft_free_folder(&folder);
	return (win);
}
