/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_getbmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 03:54:28 by alerandy          #+#    #+#             */
/*   Updated: 2019/05/23 17:46:07 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp_parser.h"
#include "bmp_parser_tools.h"

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
	if (bit == 8)
		return fill_pixels_index(bmpfile, (char*)pixels, width, height);
	if (bit == 16)
		return fill_pixels_16(bmpfile->pixels, (unsigned short*)pixels, \
				width, height);
	if (bit == 32)
		return fill_pixels_32(bmpfile->pixels, (t_bmp_32*)pixels, width, \
				height);
	return (fill_pixels_24(bmpfile->pixels, (t_bmp_24*)pixels, width, height));
}

void	read_info(int fd, t_bmp *bmp)
{
	char	tmp[2048];

	read(fd, &bmp->info.biSize, sizeof(bmp->info.biSize));
	read(fd, &bmp->info.width, sizeof(bmp->info.width));
	read(fd, &bmp->info.height, sizeof(bmp->info.height));
	read(fd, &bmp->info.biPlanes, sizeof(bmp->info.biPlanes));
	read(fd, &bmp->info.biBitCount, sizeof(bmp->info.biBitCount));
	read(fd, &bmp->info.biCompression, sizeof(bmp->info.biCompression));
	read(fd, &bmp->info.biSizeImage, sizeof(bmp->info.biSizeImage));
	read(fd, &bmp->info.biXPelsPerMeter, sizeof(bmp->info.biXPelsPerMeter));
	read(fd, &bmp->info.biYPelsPerMeter, sizeof(bmp->info.biYPelsPerMeter));
	read(fd, &bmp->info.biClrUsed, sizeof(bmp->info.biClrUsed));
	read(fd, &bmp->info.biClrImportant, sizeof(bmp->info.biClrImportant));
	read(fd, tmp, bmp->info.biSize - sizeof(bmp->info));
}

t_bmp	ui_getbmp(char *path)
{
	int			fd;
	t_bmp		bmp;
	int			skip;
	int			error;

	ft_bzero(&bmp, sizeof(bmp));
	if ((fd = open(path, O_RDWR)) == -1)
	{
		ft_putendl_fd("Le fichier n'existe pas.", 2);
		close(fd);
		return (bmp);
	}
	read(fd, &bmp.header, sizeof(t_bmp_header));
	read_info(fd, &bmp);
	if ((error = validate_bmp(bmp)))
		return print_parse_error(error, bmp, path);
	skip = bmp.header.bfOffBits - bmp.info.biSize - sizeof(t_bmp_header);
	if ((bmp.palette = ft_memalloc(skip)))
		read(fd, bmp.palette, skip);
	ui_putbmp(bmp.header, bmp.info);
	bmp.pixel_count = bmp.info.width * bmp.info.height;
	if ((bmp.pixels = ft_memalloc(sizeof(unsigned) * bmp.pixel_count)))
		read_bmp(fd, &bmp);
	close(fd);
	return (bmp);
}
