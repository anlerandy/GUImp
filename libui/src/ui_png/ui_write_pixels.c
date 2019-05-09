/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_write_pixels.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 02:01:37 by alerandy          #+#    #+#             */
/*   Updated: 2019/05/09 05:32:31 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui_png_tools.h"

void		finalise_reading(t_png *png, t_png_chunk chunk)
{
	int		i;

	i = -1;
	ft_memdel(&chunk.data);
	ft_putstr("Size of all IDAT Chunks: ");
	ft_putnbr(png->raw_size);
	ft_putchar('\n');
	if (png->header.color == PNGRGB)
	{
		png->pixels = ft_memalloc(sizeof(unsigned) \
						* (png->raw_size / sizeof(t_rgb)));
		while (png->raw_size - ++i * sizeof(t_rgb) >= sizeof(t_rgb))
			png->pixels[i] = bit24_pixel_to_hex(*(t_rgb*)(png->raw_data \
							+ i * sizeof(t_rgb)));
	}
}
