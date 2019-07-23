/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_pixscpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 12:58:02 by alerandy          #+#    #+#             */
/*   Updated: 2019/07/23 14:20:11 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp_parser.h"

unsigned	merge_pixel(unsigned dst, unsigned src)
{
	double			alpha;
	t_bmp_32		merge;
	t_bmp_32		source;

	merge = hex_to_bit32_pixel(dst);
	source = hex_to_bit32_pixel(src);
	alpha = (255 - source.a) / 255.;
	merge.r = merge.r * alpha + source.r * (1 - alpha);
	merge.g = merge.g * alpha + source.g * (1 - alpha);
	merge.b = merge.b * alpha + source.b * (1 - alpha);
	dst = bit32_pixel_to_hex(merge);
	return (dst);
}

void		convert_color_lines(unsigned *dst, unsigned *src, \
												unsigned width)
{
	unsigned	i;

	i = 0;
	while (i < width)
	{
		*(dst + i) = merge_pixel(*(dst + i), *(src + i));
		++i;
	}
}
