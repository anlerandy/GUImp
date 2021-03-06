/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_write_pixels.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 02:01:37 by alerandy          #+#    #+#             */
/*   Updated: 2019/11/18 14:35:51 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui_png_tools.h"
#include <zlib.h>
#include <stdio.h>
#include "vectors.h"
#include <math.h>

void		uncompress_data(void *dst, void *src, unsigned in_size, \
							unsigned out_size)
{
	z_stream	infstream;

	infstream.zalloc = Z_NULL;
	infstream.zfree = Z_NULL;
	infstream.opaque = Z_NULL;
	infstream.avail_in = (uInt)in_size;
	infstream.next_in = (Bytef *)src;
	infstream.avail_out = (uInt)out_size;
	infstream.next_out = (Bytef *)dst;
	inflateInit(&infstream);
	inflate(&infstream, Z_NO_FLUSH);
	inflateEnd(&infstream);
}

void		png_finalise_reading(t_png *png, t_png_chunk chunk)
{
	int			i;
	void		*data;
	unsigned	size;

	ft_memdel(&(chunk.data));
	size = png->header.width * png->header.height * 8 + png->header.height;
	if (!(data = ft_memalloc(size)))
		return ;
	uncompress_data(data, png->raw_data, png->raw_size, size);
	png->pixel_count = png->header.width * png->header.height;
	if (!(png->pixels = ft_memalloc(sizeof(unsigned) * png->pixel_count)))
	{
		ft_putendl_fd("Echec d'allocations de memoire.", 2);
		return (ft_memdel(&data));
	}
	if (png->header.color == PNGRGB || png->header.color == PNGRGBA)
		png_write_rgba(png, data, png->header.color == PNGRGBA);
	if (png->header.color == PNGINDEX && (i = -1))
		while (png->pixel_count - ++i - 1)
			png->pixels[i] = ui_bgr_to_hex(png->palette[((unsigned char *)\
				(data + (int)(i / png->header.width)))[i]]) + (!png->opacity \
				? 0 : png->opacity[((unsigned char *)data)[i]]) * 16777216;
	if (png->header.color == PNGGRAY || png->header.color == PNGGRAYA)
		ft_putendl_fd("PNG might be empty due to unsupported color format.", 2);
	ft_memdel(&data);
}
