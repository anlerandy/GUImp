/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_write_pixels.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 02:01:37 by alerandy          #+#    #+#             */
/*   Updated: 2019/07/05 16:50:10 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui_png_tools.h"
#include <zlib.h>
#include <stdio.h>

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

unsigned	char_to_hex(unsigned char c)
{
	unsigned	pixel;

	pixel = c / 3 / 3 / 3;
	pixel += (c & 0x00110000) / 3 / 3;
	pixel += (c & 0x00001100) / 3;
	pixel += (c & 0x00000011);
	return (pixel);
}

void		png_write_rgba(t_png *png, void *data)
{
	int			i;
	unsigned	x;
	unsigned	y;
	int			filter;

	i = 0;
	x = 0;
	y = 0;
	if (png->header.bit == 8)
	{
		while (y < png->header.height)
		{
			while (x < png->header.width)
			{
				if (x == 0) {
					filter = *((unsigned char*)data + x + y * png->header.height + y);
					printf("Filter = %d => ", filter);
				}
				// if (x == 0 && y == 0)
					printf("%x - ", *((unsigned char*)data + ((i % png->header.width) + 1) + x + y * png->header.width));
				png->pixels[i] = char_to_hex(*((unsigned char*)data + ((i % png->header.width) + 1) + x++ + y * png->header.width));
				++i;
			}
			printf("\n");
			x = 0;
			++y;
		}
	}
}

void		png_finalise_reading(t_png *png, t_png_chunk chunk)
{
	int		i;
	void	*data;

	i = -1;
	free(chunk.data);
	chunk.data = NULL;
	data = ft_memalloc(png->header.width * png->header.height * 4);
	uncompress_data(data, png->raw_data, png->raw_size, \
				png->header.width * png->header.height * 4);
	png->pixel_count = png->header.width * png->header.height;
	if (!(png->pixels = ft_memalloc(sizeof(t_rgba) * png->pixel_count)))
	{
		ft_putendl_fd("Echec d'allocations de memoire.", 2);
		return ;
	}
	if (png->header.color == PNGRGB)
		while (png->raw_size - ++i * sizeof(t_rgb) >= sizeof(t_rgb))
			png->pixels[i] = bit24_pixel_to_hex(*(t_rgb*)(png->raw_data \
							+ i * sizeof(t_rgb)));
	if (png->header.color == PNGRGBA)
		png_write_rgba(png, data);
		// while (png->pixel_count - ++i)
		// 	png->pixels[i] = bit32_pixel_to_hex(*(t_rgba*)(data + i * sizeof(t_rgba)));
	if (png->header.color == PNGINDEX)
		while (png->pixel_count - ++i - 1)
			png->pixels[i] = bit24_pixel_to_hex(png->palette[((unsigned char*)data)[i]]) \
							+ png->opacity[((unsigned char*)data)[i]] * 256 * 256 * 256;
	ft_memdel(&data);
}
