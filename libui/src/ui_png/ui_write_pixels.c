/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_write_pixels.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 02:01:37 by alerandy          #+#    #+#             */
/*   Updated: 2019/10/11 13:28:40 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui_png_tools.h"
#include <zlib.h>
#include <stdio.h>
#include "vectors.h"
#include <math.h>

void		uncompress_data(void *dst, void *src, unsigned in_size, \
							unsigned out_size)
{
	z_stream	infstream;

	infstream.zalloc = Z_NULL;
	infstream.zfree = Z_NULL;
	infstream.opaque = Z_NULL;
	infstream.avail_in = (uInt)in_size;
	infstream.next_in = (Bytef *)src;
	infstream.avail_out = (uInt)out_size;
	infstream.next_out = (Bytef *)dst;
	inflateInit(&infstream);
	inflate(&infstream, Z_NO_FLUSH);
	inflateEnd(&infstream);
}

// static inline unsigned	multiply_self(t_argb a)
// {
// 	unsigned	result;

// 	result = a.a + a.r + a.g + a.b;
// 	return (result);
// }

t_argb	png_get_color(t_png *png, unsigned char *data, t_isize pos, int filter)
{
	t_argb		color;
	unsigned	width;
	t_argb		helper[3];
	unsigned	predic[3];
	long		p;

	width = png->header.width;
	color.r = *(data + (pos.x * 4 + 1) + (width * 4 + 1) * pos.y);
	color.g = *(data + (pos.x * 4 + 1) + (width * 4 + 1) * pos.y + 1);
	color.b = *(data + (pos.x * 4 + 1) + (width * 4 + 1) * pos.y + 2);
	color.a = *(data + (pos.x * 4 + 1) + (width * 4 + 1) * pos.y + 3);
	if (filter == 1 && pos.x != 0)
		color = ui_argb_addition(color, \
				png_hex_to_bit32_pixel(png->pixels[pos.x - 1 + pos.y * width]));
	if (filter == 2 && pos.y != 0)
		color = ui_argb_addition(color, \
			png_hex_to_bit32_pixel(png->pixels[pos.x + (pos.y - 1) * width]));
	if (filter == 3 || filter == 4)
	{
		if (pos.x != 0)
			helper[0] = png_hex_to_bit32_pixel(png->pixels[pos.x - 1 \
															+ pos.y * width]);
		else
			helper[0] = (t_argb){0, 0, 0, 0};
		if (pos.y != 0)
			helper[1] = png_hex_to_bit32_pixel(png->pixels[pos.x \
														+ (pos.y - 1) * width]);
		else
			helper[1] = (t_argb){0, 0, 0, 0};
		if (filter == 3)
			color = ui_argb_addition(color, \
										ui_argb_average(helper[0], helper[1]));
		else
		{
			if (pos.x != 0 && pos.y != 0)
				helper[2] = png_hex_to_bit32_pixel(png->pixels[pos.x - 1 \
														+ (pos.y - 1) * width]);
			else
				helper[2] = (t_argb){0, 0, 0, 0};
			predic[0] = png_bit32_pixel_to_hex(helper[0]);
			predic[1] = png_bit32_pixel_to_hex(helper[1]);
			predic[2] = png_bit32_pixel_to_hex(helper[2]);
			p = predic[0] + predic[1] - predic[2];
			predic[0] = labs(p - (long)predic[0]);
			predic[1] = labs(p - (long)predic[1]);
			predic[2] = labs(p - (long)predic[2]);
			if (predic[0] <= predic[1] && predic[0] <= predic[2])
				return (ui_argb_addition(color, helper[0]));
			if (predic[1] <= predic[2])
				return (ui_argb_addition(color, helper[1]));
			return (ui_argb_addition(color, helper[2]));
		}
	}
	return (color);
}

void		png_write_rgba(t_png *png, void *data)
{
	int			i;
	t_isize		pos;
	int			filter;
	t_argb		color;
	int			cursor;

	i = 0;
	pos.y = 0;
	cursor = 0;
	if (png->header.bit == 8)
	{
		while ((unsigned)i < (png->header.width * 4 + 1) * png->header.height)
		{
			if (i % (png->header.width * 4 + 1) == 0)
			{
				filter = (int)*((unsigned char*)data + i++);
				i == 1 ? 0 : ++pos.y;
				pos.x = 0;
				// ft_putchar('\n');
				// ft_putnbr(filter);
				// ft_putchar(' ');
			}
			color = png_get_color(png, (unsigned char*)data, pos, filter);
			// ft_putnbr(color.r);
			// ft_putchar('-');
			// ft_putnbr(color.g);
			// ft_putchar('-');
			// ft_putnbr(color.b);
			// ft_putchar('-');
			// ft_putnbr(color.a);
			// ft_putstr("    ");
			png->pixels[cursor++] = png_bit32_pixel_to_hex(color);
			i += 4;
			++pos.x;
		}
		ft_putchar('\n');
	}
}

void		png_finalise_reading(t_png *png, t_png_chunk chunk)
{
	int		i;
	void	*data;

	i = -1;
	free(chunk.data);
	chunk.data = NULL;
	data = ft_memalloc(png->header.width * png->header.height * 4);
	uncompress_data(data, png->raw_data, png->raw_size, \
				png->header.width * png->header.height * 4);
	png->pixel_count = png->header.width * png->header.height;
	if (!(png->pixels = ft_memalloc(sizeof(t_argb) * png->pixel_count)))
	{
		ft_putendl_fd("Echec d'allocations de memoire.", 2);
		return ;
	}
	if (png->header.color == PNGRGB)
		ui_scanline_to_rgb(png, data);
	if (png->header.color == PNGRGBA)
		png_write_rgba(png, data);
	if (png->header.color == PNGINDEX)
		while (png->pixel_count - ++i - 1)
			png->pixels[i] = bit24_pixel_to_hex(png->palette[((unsigned char*)\
				(data + (int)(i / png->header.width)))[i]]) \
					+ png->opacity[((unsigned char*)data)[i]] * 256 * 256 * 256;
	ft_memdel(&data);
}
