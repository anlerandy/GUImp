/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_render_layer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 11:18:03 by alerandy          #+#    #+#             */
/*   Updated: 2019/07/23 14:24:10 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp_parser.h"
#include "libui_layers.h"
#include "libui_tools.h"
#include "vectors.h"
#include "ui_shared.h"

static inline int		pixel_place(t_ui_layer layer, int x, int y)
{
	return (((int)(layer.width_inversed
				* (x - layer.x) / layer.scale.x) + (int)(layer.height_inversed
				* (y - layer.y) / layer.scale.y) * layer.width));
}

static inline t_vec2	calc_scale(t_ui_layer layer)
{
	t_vec2 scale;

	scale.x = (double)layer.rescale_w / (double)layer.width;
	scale.y = (double)layer.rescale_h / (double)layer.height;
	return (scale);
}

static inline void		handle_transparancy(unsigned *dst, unsigned *src)
{
	*dst = merge_pixel(*dst, *src);
}

static void				ui_render_layer_rescale(t_ui_win **win,
	t_ui_layer layer)
{
	t_ui_win	*tmp;
	t_isize		l;
	unsigned	*dst;

	tmp = *win;
	dst = (unsigned *)tmp->surf->pixels;
	layer.scale = calc_scale(layer);
	l.x = (layer.x >= 0) ? layer.x : 0;
	while (l.x < (int)(layer.width * layer.scale.x) + layer.x
		&& l.x < tmp->surf->w && l.x >= 0 && l.x >= layer.x
		- (layer.width * layer.scale.x))
	{
		l.y = (layer.y >= 0) ? layer.y : 0;
		while (l.y < (layer.height * layer.scale.y) + layer.y
			&& l.y < tmp->surf->h && l.y >= 0 && l.y >= layer.y
			- (layer.height * layer.scale.y))
		{
			handle_transparancy(&(dst[l.x + l.y * tmp->surf->w]), \
								&(layer.pixels[pixel_place(layer, \
									l.x, l.y)]));
			l.y += layer.height_inversed;
		}
		l.x += layer.width_inversed;
	}
	SDL_UpdateWindowSurface(tmp->sdl_ptr);
}

void					ui_render_layer(t_ui_win **win, t_ui_layer layer)
{
	unsigned	i;
	int			limit_w;
	unsigned	*src;
	unsigned	*dst;

	src = layer.pixels;
	dst = (*win)->surf->pixels;
	i = 0;
	limit_w = (*win)->surf->w - layer.x < (int)layer.rescale_w \
				? (*win)->surf->w \
				: 2 * (*win)->surf->w - layer.rescale_w - layer.x;
	if (limit_w < 0)
		return ;
	if (layer.width != layer.rescale_w || layer.height != layer.rescale_h)
		return (ui_render_layer_rescale(win, layer));
	while (layer.rescale_h > i && (*win)->surf->h > (int)i)
	{
		convert_color_lines(dst + layer.x, src, limit_w);
		src += layer.width;
		dst += (*win)->surf->w;
		++i;
	}
	SDL_UpdateWindowSurface((*win)->sdl_ptr);
}
