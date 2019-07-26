/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_render_folder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 16:45:05 by alerandy          #+#    #+#             */
/*   Updated: 2019/07/26 17:08:26 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"
#include "libui_tools.h"
#include "libui_explorer.h"
#include "ui_shared.h"
#include "mini_ls.h"
#include "libui_layers.h"

void	ui_render_folder(t_ui_folder *folder)
{
	unsigned	pixels;
	int			i;
	t_ui_layer	*layer;

	i = -1;
	if (!folder || !folder->win || !folder->layers || !folder->ls)
		return (ft_putendl_fd("Echec de rendu Folder.", 2));
	pixels = folder->win->surf->w * folder->win->surf->h;
	while (++i < folder->ls->files_amount + 1)
	{
		layer = folder->layers[i];
		layer->x = (!i ? 35 : 15) + (i && i == (int)folder->selected) * 20;
		layer->y = !i ? 10 : i * 35 + 10;
		ui_render_layer(&folder->win, layer);
	}
}
