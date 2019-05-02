/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1bit_filler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 20:24:48 by alerandy          #+#    #+#             */
/*   Updated: 2019/05/02 20:25:24 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp_parser.h"

void	fill_buffer(t_bmp_24 *buff, char c)
{
	char		a;
	t_bmp_24	white;
	t_bmp_24	black;

	white = (t_bmp_24){255, 255, 255};
	black = (t_bmp_24){0, 0, 0};
	a = 1;
	buff[0] = c & a ? black : white;
	buff[1] = c & a << 1 ? black : white;
	buff[2] = c & a << 2 ? black : white;
	buff[3] = c & a << 3 ? black : white;
	buff[4] = c & a << 4 ? black : white;
	buff[5] = c & a << 5 ? black : white;
	buff[6] = c & a << 6 ? black : white;
	buff[7] = c & a << 7 ? black : white;
}

void	fill_pixels_1(unsigned *bmp_pixels, char *pixels, int width, \
						int height)
{
	int			x;
	int			y;
	t_bmp_24	buff[8];
	int			cursor;

	y = -1;
	width /= 8;
	while (++y < height)
	{
		x =-1;
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
