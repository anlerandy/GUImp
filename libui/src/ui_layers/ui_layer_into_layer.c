/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_layer_into_layer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 12:52:23 by alerandy          #+#    #+#             */
/*   Updated: 2019/10/06 12:57:03 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui_layers.h"
#include "bmp_parser.h"
#include "ui_shared.h"

static inline int		pixel_place(t_ui_layer *layer, int x, int y)
{
	return (((int)(layer->width_inversed
				* (x - layer->x) / layer->scale.x) \
				+ (int)(layer->height_inversed \
				* (y - layer->y) / layer->scale.y) * layer->width));
}

static inline t_vec2	calc_scale(t_ui_layer *layer)
{
	t_vec2 scale;

	scale.x = (double)layer->rescale_w / (double)layer->width;
	scale.y = (double)layer->rescale_h / (double)layer->height;
	return (scale);
}

static inline void		handle_transparancy(unsigned *dst, unsigned *src)
{
	*dst = merge_pixel(*dst, *src);
}

static inline void		ui_render_layer_rescale(t_ui_layer *dst, \
													t_ui_layer *src)
{
	t_isize		l;

	src->scale = calc_scale(src);
	l.x = (src->x >= 0) ? src->x : 0;
	while (l.x < (int)(src->width * src->scale.x) + src->x
		&& l.x < (int)dst->width && l.x >= 0 && l.x >= src->x
		- (src->width * src->scale.x))
	{
		l.y = (src->y >= 0) ? src->y : 0;
		while (l.y < (int)(src->height * src->scale.y) + src->y
			&& l.y < (int)dst->height && l.y >= 0 && l.y >= src->y
			- (src->height * src->scale.y))
		{
			handle_transparancy(&(dst->pixels[l.x + l.y * dst->width]), \
								&(src->pixels[pixel_place(src, \
									l.x, l.y)]));
			l.y += src->height_inversed;
		}
		l.x += src->width_inversed;
	}
}

void					ui_layer_into_layer(t_ui_layer *dst, t_ui_layer *src)
{
	unsigned	i;
	int			limit_w;

	if (!src || !src->pixels || !dst || !dst->pixels)
		return ;
	limit_w = dst->width - src->x < src->rescale_w \
		? dst->width : 2 * dst->width - src->rescale_w - src->x;
	limit_w = limit_w > (int)src->rescale_w ? (int)src->rescale_w : limit_w;
	src->height_inversed = src->height_inversed >= 0 ? 1 : -1;
	src->width_inversed = src->width_inversed >= 0 ? 1 : -1;
	if (limit_w < 0)
		return ;
	if (src->width != src->rescale_w || src->height != src->rescale_h)
		return (ui_render_layer_rescale(dst, src));
	i = 0;
	while (src->rescale_h > i && dst->height > i + src->y)
	{
		convert_color_lines(((dst->pixels + src->y * dst->width) \
								+ (i * dst->width)) + src->x, \
									src->pixels + (i * src->width), limit_w);
		++i;
	}
}
