/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   16bit_filler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 17:13:45 by alerandy          #+#    #+#             */
/*   Updated: 2019/05/05 17:51:38 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp_parser.h"

void	fill_pixels_16(unsigned *bmp_pixels, unsigned short *pixels, \
						int width, int height)
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
			bmp_pixels[i++] = pixels[x + (height - y) * width];
	}
}
