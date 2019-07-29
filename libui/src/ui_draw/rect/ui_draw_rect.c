/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_draw_rect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 21:18:26 by alerandy          #+#    #+#             */
/*   Updated: 2019/07/30 00:26:26 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui_layers.h"
#include "libui_tools.h"
#include "SDL_surface.h"
#include "ui_shared.h"

t_ui_layer		*ui_rect_to_layer(unsigned width, unsigned height, \
										int x, int y, unsigned color)
{
	t_ui_layer	*layer;

	if (!width || !height || !(layer = ft_memalloc(sizeof(t_ui_layer))))
		return (NULL);
	if (!(layer->pixels = ft_memalloc(sizeof(unsigned) * width * height)))
	{
		ft_memdel((void**)&layer);
		return (NULL);
	}
	ui_memuset(layer->pixels, color, width * height);
	layer->width = width;
	layer->rescale_w = width;
	layer->height = height;
	layer->rescale_h = height;
	layer->x = x;
	layer->y = y;
	return (layer);
}

void			ui_rect_in_win(t_ui_win *win, int width, int height, \
										int x, int y, unsigned color)
{
	SDL_Surface	*surface;
	int			w_limit;
	int			i;
	unsigned	*pixels;
	unsigned	*line;

	if (!width || !height || !win || !(surface = win->surf))
		return ;
	w_limit = width > surface->w - x ? 2 * surface->w - width - x : surface->w;
	i = 0;
	if (!(line = ft_memalloc(sizeof(unsigned) * w_limit)))
		return ;
	ui_memuset(line, color, w_limit);
	while (height > i && surface->h - y > i)
	{
		pixels = ((unsigned *)surface->pixels) + ((y + i) * surface->w);
		convert_color_lines(pixels, line, w_limit);
		++i;
	}
	free(line);
}
