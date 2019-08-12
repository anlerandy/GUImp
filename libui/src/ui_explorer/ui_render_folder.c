/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_render_folder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 16:45:05 by alerandy          #+#    #+#             */
/*   Updated: 2019/08/12 16:25:57 by alerandy         ###   ########.fr       */
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

static inline void	render_text(t_ui_folder *folder, t_ui_layer *layer, \
									unsigned width)
{
	t_ui_layer		*tmp;
	int				i;
	t_ui_draw_param	param;

	i = -1;
	param = (t_ui_draw_param){width, 35, 0, 0, 0x80ff0000, 0, 0};
	while (++i < folder->ls->files_amount + 1)
	{
		tmp = folder->layers[i];
		tmp->x = (!i ? 35 : 15) + (i && i == (int)folder->selected) * 20;
		tmp->y = !i ? 10 : i * 35 + 10;
		param.y = tmp->y - 3;
		if (i && i == (int)folder->selected)
		{
			tmp = ui_rect_to_layer(param);
			ui_layer_into_layer(layer, tmp);
			ui_free_layer(&tmp);
		}
		tmp = folder->layers[i];
		ui_layer_into_layer(layer, tmp);
	}
}

void				ui_render_folder(t_ui_folder *folder)
{
	t_ui_layer		*layer;
	t_ui_layer		*tmp;
	SDL_Surface		*surface;
	t_ui_draw_param	param;

	if (!folder || !folder->win || !folder->layers || !folder->ls)
		return (ft_putendl_fd("Echec de rendu Folder.", 2));
	ft_bzero(&param, sizeof(t_ui_draw_param));
	surface = folder->win->surf;
	param = (t_ui_draw_param){surface->w, surface->h, 0, 0, 0xff01003b, 0, 0};
	if (!(layer = ui_rect_to_layer(param)))
		return ;
	param = (t_ui_draw_param){surface->w, 42, 0, 0, 0xff001aff, 0, 0};
	if (!(tmp = ui_rect_to_layer(param)))
		return ;
	ui_layer_into_layer(layer, tmp);
	ui_free_layer(&tmp);
	render_text(folder, layer, surface->w);
	ui_render_layer(&folder->win, layer);
	ui_free_layer(&layer);
}
