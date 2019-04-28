/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_getbmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 03:54:28 by alerandy          #+#    #+#             */
/*   Updated: 2019/04/28 14:17:42 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp_parser.h"

void	fill_pixels(unsigned *bmp_pixels, t_bmp_24 *pixels, int width, \
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
		{
			bmp_pixels[i++] = bit24_pixel_to_hex(pixels[x + (height - y - 1) \
													* width]);
		}
	}
}

t_bmp	ui_getbmp(char *path)
{
	int				fd;
	t_bmp_24		*pixels;
	t_bmp			bmpfile;

	ft_bzero(&bmpfile, sizeof(bmpfile));
	if ((fd = open(path, O_RDWR)) == -1)
	{
		ft_putendl_fd("Le fichier n'existe pas.", 2);
		return (bmpfile);
	}
	read(fd, &bmpfile, sizeof(bmpfile));
	ui_putbmp(bmpfile.header, bmpfile.info);
	bmpfile.pixel_count = bmpfile.info.width * bmpfile.info.height;
	pixels = ft_memalloc(sizeof(t_bmp_24) * bmpfile.pixel_count);
	bmpfile.pixels = ft_memalloc(sizeof(unsigned) * bmpfile.pixel_count);
	if (!pixels || !bmpfile.pixels)
		return (bmpfile);
	if (!read(fd, pixels, sizeof(t_bmp_24) * bmpfile.pixel_count))
	{
		ft_putendl_fd("Une erreur est survenue lors de la lecture.", 2);
		return (bmpfile);
	}
	fill_pixels(bmpfile.pixels, pixels, bmpfile.info.width, \
					bmpfile.info.height);
	close(fd);
	return (bmpfile);
}
