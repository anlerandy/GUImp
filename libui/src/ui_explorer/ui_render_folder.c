/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_render_folder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 16:45:05 by alerandy          #+#    #+#             */
/*   Updated: 2019/07/30 00:35:30 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"
#include "libui_tools.h"
#include "libui_explorer.h"
#include "ui_shared.h"
#include "mini_ls.h"
#include "libui_layers.h"
#include "SDL_surface.h"
#include "libui_draw.h"

void	ui_render_folder(t_ui_folder *folder)
{
	unsigned	pixels;
	int			i;
	t_ui_layer	*layer;
	SDL_Surface	*surface;

	i = -1;
	if (!folder || !folder->win || !folder->layers || !folder->ls)
		return (ft_putendl_fd("Echec de rendu Folder.", 2));
	surface = folder->win->surf;
	pixels = surface->w * surface->h;
	ui_rect_in_win(folder->win, surface->w, surface->h, 0, 42, 0xff01003b);
	ui_rect_in_win(folder->win, surface->w, 42, 0, 0, 0xff001aff);
	while (++i < folder->ls->files_amount + 1)
	{
		layer = folder->layers[i];
		layer->x = (!i ? 35 : 15) + (i && i == (int)folder->selected) * 20;
		layer->y = !i ? 10 : i * 35 + 10;
		if (i && i == (int)folder->selected)
			ui_rect_in_win(folder->win, surface->w, 35, 0, layer->y - 3, 0x80ff0000);
		ui_render_layer(&folder->win, layer);
	}
}
