/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   png_rgba.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:42:20 by alerandy          #+#    #+#             */
/*   Updated: 2019/11/13 09:14:49 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui_png_tools.h"
#include "vectors.h"

unsigned char each_byte_compare(unsigned char a, unsigned char b, \
															unsigned char c)
{
	int		p;
	int		pa;
	int		pb;
	int		pc;

	p = (int)a + (int)b - (int)c;
	pa = abs(p - (int)a);
	pb = abs(p - (int)b);
	pc = abs(p - (int)c);
	if (pa <= pb && pa <= pc)
		return (a);
	if (pb <= pc)
		return (b);
	return (c);
}

t_argb		color_filter_4(t_png *png, t_isize pos)
{
	t_argb		a;
	t_argb		b;
	t_argb		c;
	t_argb		res;

	a = ui_hex_to_argb(!pos.x ? 0 : png->pixels[(pos.x - 1) \
											+ pos.y * png->header.width]);
	b = ui_hex_to_argb(!pos.y ? 0 : png->pixels[pos.x + (pos.y - 1) \
													* png->header.width]);
	c = ui_hex_to_argb(!pos.x || !pos.y ? 0 : png->pixels[(pos.x - 1) \
										+ (pos.y - 1) * png->header.width]);
	res.a = each_byte_compare(a.a, b.a, c.a);
	res.r = each_byte_compare(a.r, b.r, c.r);
	res.g = each_byte_compare(a.g, b.g, c.g);
	res.b = each_byte_compare(a.b, b.b, c.b);
	return (res);
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
		return (ui_argb_addition(color, color_filter_4(png, pos)));
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
			color = ui_hex_to_abgr(*(unsigned *)(data + (pos.x * alpha + 1) \
							+ (png->header.width * alpha + 1) * pos.y));
			color.a = alpha == 3 ? 255 : color.a;
			color = eight_bit_get_color(png, color, pos, filter);
			color.a = alpha == 3 ? 255 : color.a;
			png->pixels[cursor++] = ui_argb_to_hex(color);
			i += alpha;
			++pos.x;
		}
}
