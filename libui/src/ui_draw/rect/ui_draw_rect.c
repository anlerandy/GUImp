/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_draw_rect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 21:18:26 by alerandy          #+#    #+#             */
/*   Updated: 2019/08/08 18:39:02 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui_layers.h"
#include "libui_tools.h"
#include "SDL_surface.h"
#include "ui_shared.h"
#include "libui_draw.h"

t_ui_layer		*ui_rect_to_layer(t_ui_draw_param param)
{
	t_ui_layer	*layer;

	if (!param.width || !param.height \
			|| !(layer = ft_memalloc(sizeof(t_ui_layer))))
		return (NULL);
	if (!(layer->pixels = ft_memalloc(sizeof(unsigned) \
										* param.width * param.height)))
	{
		ft_memdel((void**)&layer);
		return (NULL);
	}
	ui_memuset(layer->pixels, param.color, param.width * param.height);
	layer->width = param.width;
	layer->rescale_w = param.width;
	layer->height = param.height;
	layer->rescale_h = param.height;
	layer->x = param.x;
	layer->y = param.y;
	return (layer);
}

void			ui_rect_in_win(t_ui_win *win, t_ui_draw_param param)
{
	SDL_Surface	*surface;
	int			w_limit;
	int			i;
	unsigned	*pixels;
	unsigned	*line;

	if (!param.width || !param.height || !win || !(surface = win->surf))
		return ;
	w_limit = param.width > surface->w - param.x \
				? 2 * surface->w - param.width - param.x : surface->w;
	i = 0;
	if (!(line = ft_memalloc(sizeof(unsigned) * w_limit)))
		return ;
	ui_memuset(line, param.color, w_limit);
	while ((int)param.height > i && surface->h - (int)param.y > i)
	{
		pixels = ((unsigned *)surface->pixels) + ((param.y + i) * surface->w);
		convert_color_lines(pixels, line, w_limit);
		++i;
	}
	free(line);
}
