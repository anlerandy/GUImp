/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   32bit_filler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 14:46:11 by alerandy          #+#    #+#             */
/*   Updated: 2019/05/05 21:00:22 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp_parser.h"

void	fill_pixels_32(unsigned *bmp_pixels, t_bmp_32 *pixels, int width, \
						int height)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (++y <= height)
	{
		x =-1;
		while (++x < width)
			bmp_pixels[i++] \
				= bit32_pixel_to_hex(pixels[x + (height - y) * width]);
	}
}
