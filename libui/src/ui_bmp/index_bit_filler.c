/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_bit_filler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 15:50:06 by alerandy          #+#    #+#             */
/*   Updated: 2019/05/26 21:17:15 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp_parser.h"

void	fill_pixels_index(t_bmp *bmp, char *pixels, int width, \
						int height)
{
	int			x;
	int			y;
	int			i;
	t_bmp_32	*palette;

	y = -1;
	i = 0;
	palette = bmp->palette;
	if (!palette)
		return (ft_putendl_fd("Palette is NULL", 2));
	while (++y < height)
	{
		x = -1;
		while (++x < width)
			bmp->pixels[i++] = \
				bit32_pixel_to_hex(((t_bmp_32*)palette)[(unsigned)(pixels[x \
									+ (height - y - 1) * width]) % 256]);
	}
}
