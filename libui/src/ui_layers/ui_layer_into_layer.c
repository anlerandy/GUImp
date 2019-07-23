/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_layer_into_layer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 12:52:23 by alerandy          #+#    #+#             */
/*   Updated: 2019/07/23 13:01:04 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui_layers.h"
#include "bmp_parser.h"
#include "ui_shared.h"

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
