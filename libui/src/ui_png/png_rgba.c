/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   png_rgba.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:42:20 by alerandy          #+#    #+#             */
/*   Updated: 2019/11/05 16:00:21 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui_png_tools.h"
#include "vectors.h"

unsigned		color_filter_4(t_png *png, t_isize pos)
{
	unsigned		a;
	unsigned		b;
	unsigned		c;
	long		pn[3];
	long		p;

	a = pos.x == 0 ? 0 : png->pixels[(pos.x - 1) + pos.y * png->header.width];
	b = pos.y == 0 ? 0 : png->pixels[pos.x + (pos.y - 1) * png->header.width];
	c = pos.x == 0 || pos.y == 0 ? 0 \
			: png->pixels[(pos.x - 1) + (pos.y - 1) * png->header.width];
	// a = (a & 0b00000000111111111111111111111111);
	// b = (b & 0b00000000111111111111111111111111);
	// c = (c & 0b00000000111111111111111111111111);
	p = a + b - c;
	pn[0] = labs(p - a);
	pn[1] = labs(p - b);
	pn[2] = labs(p - c);
	if (pn[0] <= pn[1] && pn[0] <= pn[2])
		return (a);
	if (pn[1] <= pn[2])
		return (b);
	return (c);
}

t_argb	eight_bit_get_color(t_png *png, t_argb color, t_isize pos, int filter)
{
	unsigned	width;
	t_argb		before;
	t_argb		prior;

	width = png->header.width;
	before = pos.x <= 0 ? (t_argb){0, 0, 0, 0}
				: ui_hex_to_argb(png->pixels[pos.x - 1 + pos.y * width]);
	prior = pos.y <= 0 ? (t_argb){0, 0, 0, 0}
				: ui_hex_to_argb(png->pixels[pos.x + (pos.y - 1) * width]);
	if (filter == 1)
		return (ui_argb_addition(color, before));
	if (filter == 2)
		return (ui_argb_addition(color, prior));
	if (filter == 3 || filter == 4)
	{
		if (filter == 3)
			return (ui_argb_addition(color, ui_argb_average(before, prior)));
		return (ui_argb_addition(color, \
					ui_hex_to_argb(color_filter_4(png, pos))));
	}
	return (color);
}

void	png_write_rgba(t_png *png, void *data, int alpha)
{
	int		i;
	t_isize	pos;
	int		filter;
	t_argb	color;
	int		cursor;

	i = 0;
	pos.y = 0;
	cursor = 0;
	alpha = alpha ? 4 : 3;
	if (png->header.bit == 8)
		while (i < (int)((png->header.width * alpha + 1) * png->header.height))
		{
			if (i % (png->header.width * alpha + 1) == 0)
			{
				filter = (int)*((unsigned char *)data + i++);
				i == 1 ? 0 : ++pos.y;
				pos.x = 0;
			}
			color.r = *(unsigned char *)(data + (pos.x * alpha + 1) \
							+ (png->header.width * alpha + 1) * pos.y);
			color.g = *(unsigned char *)(data + (pos.x * alpha + 1) \
							+ (png->header.width * alpha + 1) * pos.y + 1);
			color.b = *(unsigned char *)(data + (pos.x * alpha + 1) \
							+ (png->header.width * alpha + 1) * pos.y + 2);
			color.a = alpha == 3 ? 255 \
				: *(unsigned char *)(data + (pos.x * alpha + 1) \
					+ (png->header.width * alpha + 1) * pos.y + 3);
			color = eight_bit_get_color(png, color, pos, filter);
			color.a = alpha == 3 ? 255 : color.a;
			png->pixels[cursor++] = ui_argb_to_hex(color);
			i += alpha;
			++pos.x;
		}
}
