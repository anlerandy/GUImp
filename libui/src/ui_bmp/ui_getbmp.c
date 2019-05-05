/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_getbmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 03:54:28 by alerandy          #+#    #+#             */
/*   Updated: 2019/05/05 21:24:13 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp_parser.h"
#include <stdio.h>

int		get_read_offset(unsigned short bit)
{
	if (bit == (unsigned short)1)
		return (sizeof(char));
	if (bit == (unsigned short)16)
		return (sizeof(unsigned short));
	if (bit == (unsigned short)32)
		return (sizeof(t_bmp_32));
	return (sizeof(t_bmp_24));
}

void	read_bmp(int fd, t_bmp *bmpfile)
{
	void			*pixels;
	int				offset;
	int				width;
	int				height;
	unsigned short	bit;

	bit = bmpfile->info.biBitCount;
	offset = get_read_offset(bit);
	width = bmpfile->info.width;
	height = bmpfile->info.height;
	pixels = ft_memalloc(offset * bmpfile->pixel_count);
	if (!read(fd, pixels, offset * bmpfile->pixel_count))
	{
		ft_putendl_fd("Une erreur est survenue lors de la lecture.", 2);
		return ;
	}
	if (bit == 1)
		return fill_pixels_1(bmpfile->pixels, (char*)pixels, width, height);
	if (bit == 16)
		return fill_pixels_16(bmpfile->pixels, (unsigned short*)pixels, \
				width, height);
	if (bit == 32)
		return fill_pixels_32(bmpfile->pixels, (t_bmp_32*)pixels, width, \
				height);
	return (fill_pixels_24(bmpfile->pixels, (t_bmp_24*)pixels, width, height));
}

t_bmp	ui_getbmp(char *path)
{
	int			fd;
	t_bmp		bmpfile;
	int			skip;
	unsigned	sizeHeader;

	ft_bzero(&bmpfile, sizeof(bmpfile));
	if ((fd = open(path, O_RDWR)) == -1)
	{
		ft_putendl_fd("Le fichier n'existe pas.", 2);
		return (bmpfile);
	}
	sizeHeader = sizeof(t_bmp_header) + sizeof(t_bmp_file);
	read(fd, &bmpfile, sizeHeader);
	skip = bmpfile.header.bfOffBits - sizeHeader;
	if ((bmpfile.palette = ft_memalloc(skip)))
		read(fd, bmpfile.palette, skip);
	ui_putbmp(bmpfile.header, bmpfile.info);
	bmpfile.pixel_count = bmpfile.info.width * bmpfile.info.height;
	if (!(bmpfile.pixels = ft_memalloc(sizeof(unsigned) * bmpfile.pixel_count)))
		return (bmpfile);
	read_bmp(fd, &bmpfile);
	close(fd);
	return (bmpfile);
}
