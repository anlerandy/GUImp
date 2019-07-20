/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_filler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 18:09:24 by alerandy          #+#    #+#             */
/*   Updated: 2019/07/01 14:33:33 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp_parser.h"
#include "ui_shared.h"

void	fill_buffer(t_bgr *buff, char c)
{
	char	a;
	t_bgr	white;
	t_bgr	black;
	int		i;

	white = (t_bgr){255, 255, 255};
	black = (t_bgr){0, 0, 0};
	a = 1;
	i = -1;
	while (++i <= 7)
		buff[i] = c & a << (7 - i) ? black : white;
}

void	fill_pixels_1(unsigned *bmp_pixels, char *pixels, int width, \
						int height)
{
	int		x;
	int		y;
	t_bgr	buff[8];
	int		cursor;

	y = -1;
	width /= 8;
	while (++y < height)
	{
		x = -1;
		while (++x < width)
		{
			cursor = x + (height - y - 1) * width;
			fill_buffer(buff, pixels[cursor]);
			*bmp_pixels++ = bit24_pixel_to_hex(buff[0]);
			*bmp_pixels++ = bit24_pixel_to_hex(buff[1]);
			*bmp_pixels++ = bit24_pixel_to_hex(buff[2]);
			*bmp_pixels++ = bit24_pixel_to_hex(buff[3]);
			*bmp_pixels++ = bit24_pixel_to_hex(buff[4]);
			*bmp_pixels++ = bit24_pixel_to_hex(buff[5]);
			*bmp_pixels++ = bit24_pixel_to_hex(buff[6]);
			*bmp_pixels++ = bit24_pixel_to_hex(buff[7]);
		}
	}
}

void	fill_pixels_16(unsigned *bmp_pixels, unsigned short *pixels, \
						int width, int height)
{
	int			x;
	int			y;
	int			i;
	t_bgra		converted;
	int			pix;

	y = 0;
	i = 0;
	while (++y <= height)
	{
		x = -1;
		while (++x < width)
		{
			pix = pixels[x + (height - y) * width];
			converted.r = ((pix & 0b0111110000000000) / 0b010000000000) \
				/ 31.0 * 255;
			converted.g = (pix & 0b01111100000) / 0b0100000 / 31.0 * 255;
			converted.b = (pix & 0b011111) / 0b01 / 31.0 * 255;
			converted.a = (pix & 0b100000000000000) / 0b100000000000000 == 1 \
				? 255 : 0;
			bmp_pixels[i++] = bit32_pixel_to_hex(converted);
		}
	}
}

void	fill_pixels_24(unsigned *bmp_pixels, t_bgr *pixels, int width, \
						int height)
{
	int		x;
	int		y;
	int		i;

	y = -1;
	i = 0;
	while (++y < height)
	{
		x = -1;
		while (++x < width)
			bmp_pixels[i++] = bit24_pixel_to_hex(pixels[x + (height - y - 1) \
													* width]);
	}
}

void	fill_pixels_32(unsigned *bmp_pixels, t_bgra *pixels, int width, \
						int height)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (++y <= height)
	{
		x = -1;
		while (++x < width)
			bmp_pixels[i++] = bit32_pixel_to_hex(pixels[x \
													+ (height - y) * width]);
	}
}
