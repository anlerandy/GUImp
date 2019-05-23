/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   16bit_filler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 17:13:45 by alerandy          #+#    #+#             */
/*   Updated: 2019/05/23 15:50:14 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp_parser.h"

void	fill_pixels_16(unsigned *bmp_pixels, unsigned short *pixels, \
						int width, int height)
{
	int			x;
	int			y;
	int			i;
	t_bmp_32	converted;
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
