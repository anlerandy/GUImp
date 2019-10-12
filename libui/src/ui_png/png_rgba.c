/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   png_rgba.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:42:20 by alerandy          #+#    #+#             */
/*   Updated: 2019/10/12 17:23:38 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui_png_tools.h"
#include "vectors.h"

t_argb	eight_bit_get_color(t_png *png, t_argb color, t_isize pos, int filter)
{
	unsigned	width;
	t_argb		helper[3];
	long long	predic[3];
	long long	p;

	width = png->header.width;
	if (filter == 1 && pos.x > 0)
		return (color = ui_argb_addition(color,
					ui_hex_to_argb(png->pixels[pos.x - 1 + pos.y * width])));
	if (filter == 2 && pos.y > 0)
		return (color = ui_argb_addition(color,
					ui_hex_to_argb(png->pixels[pos.x + (pos.y - 1) * width])));
	if (filter == 3 || filter == 4)
	{
		helper[0] = pos.x <= 0 ? (t_argb){0, 0, 0, 0}
					: ui_hex_to_argb(png->pixels[pos.x - 1 + pos.y * width]);
		helper[1] = pos.y <= 0 ? (t_argb){0, 0, 0, 0}
					: ui_hex_to_argb(png->pixels[pos.x + (pos.y - 1) * width]);
		if (filter == 3)
			return (color = ui_argb_average(helper[0], helper[1]));
		else
		{
			helper[2] = pos.x <= 0 || pos.y <= 0 ? (t_argb){0, 0, 0, 0}
				: ui_hex_to_argb(png->pixels[pos.x - 1 + (pos.y - 1) * width]);
			p = (long long)ui_argb_to_hex(helper[0]) \
				+ (long long)ui_argb_to_hex(helper[1]) \
					- (long long)ui_argb_to_hex(helper[2]);
			predic[0] = labs(p - (long long)ui_argb_to_hex(helper[0]));
			predic[1] = labs(p - (long long)ui_argb_to_hex(helper[1]));
			predic[2] = labs(p - (long long)ui_argb_to_hex(helper[2]));
			if (predic[0] <= predic[1] && predic[0] <= predic[2])
				return (ui_argb_addition(color, helper[0]));
			if (predic[1] <= predic[2])
				return (ui_argb_addition(color, helper[1]));
			return (ui_argb_addition(color, helper[2]));
		}
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
			color.a = alpha == 3 ? 0 \
				: *(unsigned char *)(data + (pos.x * alpha + 1) \
					+ (png->header.width * alpha + 1) * pos.y + 3);
			color = eight_bit_get_color(png, color, pos, filter);
			png->pixels[cursor++] = ui_argb_to_hex(color);
			i += alpha;
			++pos.x;
		}
}
