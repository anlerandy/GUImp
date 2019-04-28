/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_getbmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 03:54:28 by alerandy          #+#    #+#             */
/*   Updated: 2019/04/28 04:37:06 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp_parser.h"

t_bmp	ui_getbmp(char *path)
{
	int				fd;
	t_bmp_24		*pixels;
	t_bmp			bmpfile;
	int				i;

	ft_bzero(&bmpfile, sizeof(bmpfile));
	if ((fd = open(path, O_RDWR)) == -1)
	{
		ft_putendl_fd("Le fichier n'existe pas.", 2);
		return (bmpfile);
	}
	read(fd, &bmpfile, sizeof(bmpfile));
	ui_putbmp(bmpfile.header, bmpfile.info);
	bmpfile.pixel_count = bmpfile.info.width * bmpfile.info.height;
	pixels = ft_memalloc(sizeof(t_bmp_24) * bmpfile.pixel_count + 1);
	bmpfile.pixels = ft_memalloc(sizeof(unsigned) * bmpfile.pixel_count);
	if (!pixels || !bmpfile.pixels)
		return (bmpfile);
	read(fd, pixels, sizeof(t_bmp_24) * bmpfile.pixel_count);
	close(fd);
	i = -1;
	while (++i < (int)bmpfile.pixel_count)
		bmpfile.pixels[i] = bit24_pixel_to_hex(pixels[i]);
	return (bmpfile);
}
