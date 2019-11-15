/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_bit_filler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 15:50:06 by alerandy          #+#    #+#             */
/*   Updated: 2019/10/12 02:36:41 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp_parser.h"
#include "ui_shared.h"

void	fill_pixels_index(t_bmp *bmp, char *pixels, int width, \
						int height)
{
	int			x;
	int			y;
	int			i;
	t_bgra		*palette;

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
				ui_bgra_to_hex(((t_bgra*)palette)[(unsigned)(pixels[x \
									+ (height - y - 1) * width]) % 256]);
	}
}
