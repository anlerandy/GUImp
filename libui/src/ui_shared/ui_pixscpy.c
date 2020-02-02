/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_pixscpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 12:58:02 by alerandy          #+#    #+#             */
/*   Updated: 2019/10/12 02:39:41 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui_shared.h"

unsigned	merge_pixel(unsigned dst, unsigned src)
{
	double		alpha;
	t_bgra		merge;
	t_bgra		source;

	merge = ui_hex_to_bgra(dst);
	source = ui_hex_to_bgra(src);
	alpha = (255 - source.a) / 255.;
	merge.r = merge.r * alpha + source.r * (1 - alpha);
	merge.g = merge.g * alpha + source.g * (1 - alpha);
	merge.b = merge.b * alpha + source.b * (1 - alpha);
	dst = ui_bgra_to_hex(merge);
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
