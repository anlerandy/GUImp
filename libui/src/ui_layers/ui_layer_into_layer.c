/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_layer_into_layer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 12:52:23 by alerandy          #+#    #+#             */
/*   Updated: 2019/07/01 14:32:58 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui_layers.h"
#include "bmp_parser.h"
#include "ui_shared.h"

static inline unsigned	merge_pixel(unsigned dst, unsigned src)
{
	double		alpha;
	t_bgra		merge;
	t_bgra		source;

	merge = hex_to_bit32_pixel(dst);
	source = hex_to_bit32_pixel(src);
	alpha = (255 - source.a) / 255.;
	merge.r = merge.r * alpha + source.r * (1 - alpha);
	merge.g = merge.g * alpha + source.g * (1 - alpha);
	merge.b = merge.b * alpha + source.b * (1 - alpha);
	dst = bit32_pixel_to_hex(merge);
	return (dst);
}

static inline void		convert_color_lines(unsigned *dst, unsigned *src, \
												unsigned width)
{
	unsigned	i;

	i = 0;
	while (i < width)
	{
		*(dst + i) = merge_pixel(*(dst + i), *(src + i));
		++i;
	}
}

void					ui_layer_into_layer(t_ui_layer *dst, t_ui_layer *src)
{
	unsigned	i;
	unsigned	*psrc;
	unsigned	*pdst;
	unsigned	limit_w;

	i = 0;
	psrc = src->pixels;
	pdst = dst->pixels;
	limit_w = dst->width - src->x < src->rescale_w \
				? dst->width : src->rescale_w;
	while (src->rescale_h > i || dst->height > i)
	{
		convert_color_lines(pdst + src->x, psrc, limit_w);
		psrc += src->width;
		pdst += dst->width;
		++i;
	}
}
