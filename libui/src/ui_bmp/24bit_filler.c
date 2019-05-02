/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   24bit_filler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 20:25:53 by alerandy          #+#    #+#             */
/*   Updated: 2019/05/02 20:26:04 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bmp_parser.h>

void	fill_pixels_24(unsigned *bmp_pixels, t_bmp_24 *pixels, int width, \
						int height)
{
	int		x;
	int		y;
	int		i;

	y = -1;
	i = 0;
	while (++y < height)
	{
		x =-1;
		while (++x < width)
			bmp_pixels[i++] = bit24_pixel_to_hex(pixels[x + (height - y - 1) \
													* width]);
	}
}
