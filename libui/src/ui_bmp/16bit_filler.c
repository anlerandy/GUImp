/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   16bit_filler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 17:13:45 by alerandy          #+#    #+#             */
/*   Updated: 2019/05/05 21:21:42 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp_parser.h"

void	fill_pixels_16(unsigned *bmp_pixels, unsigned short *pixels, \
						int width, int height)
{
	int			x;
	int			y;
	int			i;
	t_bmp_24	converted;
	int			pix;

	y = 0;
	i = 0;
	while (++y <= height)
	{
		x = -1;
		while (++x < width)
		{
			pix = pixels[x + (height - y) * width];
			converted.r = pix & 0xF800;
			converted.g = pix & 0x03C0;
			converted.b = pix & 0x003E;
			bmp_pixels[i++] = bit24_pixel_to_hex(converted);
		}
	}
}
