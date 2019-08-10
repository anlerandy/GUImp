/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_getbmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 03:54:28 by alerandy          #+#    #+#             */
/*   Updated: 2019/08/08 17:19:29 by alerandy         ###   ########.fr       */
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
	int				w;
	int				h;

	offset = get_read_offset(bmpfile->info.color_depth);
	w = bmpfile->info.width;
	h = bmpfile->info.height;
	pixels = ft_memalloc(offset * bmpfile->pixel_count);
	read(fd, pixels, offset * bmpfile->pixel_count);
	if (bmpfile->info.color_depth == 1)
		fill_pixels_1(bmpfile->pixels, (char*)pixels, w, h);
	if (bmpfile->info.color_depth == 8 || bmpfile->info.color_depth == 4)
		fill_pixels_index(bmpfile, (char*)pixels, w, h);
	if (bmpfile->info.color_depth == 16)
		fill_pixels_16(bmpfile->pixels, (unsigned short*)pixels, w, h);
	if (bmpfile->info.color_depth == 32)
		fill_pixels_32(bmpfile->pixels, (t_bmp_32*)pixels, w, h);
	if (bmpfile->info.color_depth == 24)
		fill_pixels_24(bmpfile->pixels, (t_bmp_24*)pixels, w, h);
	free(pixels);
}

void	read_header(int fd, t_bmp *bmp)
{
	read(fd, &bmp->header.type, sizeof(bmp->header.type));
	read(fd, &bmp->header.size, sizeof(bmp->header.size));
	read(fd, &bmp->header.reserved1, sizeof(bmp->header.reserved1));
	read(fd, &bmp->header.reserved2, sizeof(bmp->header.reserved2));
	read(fd, &bmp->header.offset, sizeof(bmp->header.offset));
}

void	read_info(int fd, t_bmp *bmp)
{
	char	*tmp;

	read(fd, &bmp->info.header_size, sizeof(bmp->info.header_size));
	read(fd, &bmp->info.width, sizeof(bmp->info.width));
	read(fd, &bmp->info.height, sizeof(bmp->info.height));
	read(fd, &bmp->info.planes, sizeof(bmp->info.planes));
	read(fd, &bmp->info.color_depth, sizeof(bmp->info.color_depth));
	read(fd, &bmp->info.compression, sizeof(bmp->info.compression));
	read(fd, &bmp->info.image_size, sizeof(bmp->info.image_size));
	read(fd, &bmp->info.width_meter, sizeof(bmp->info.width_meter));
	read(fd, &bmp->info.height_meter, sizeof(bmp->info.height_meter));
	read(fd, &bmp->info.used_color, sizeof(bmp->info.used_color));
	read(fd, &bmp->info.important_color, sizeof(bmp->info.important_color));
	if ((tmp = ft_memalloc(bmp->info.header_size - sizeof(bmp->info))))
		read(fd, tmp, bmp->info.header_size - sizeof(bmp->info));
	free(tmp);
}

t_bmp	*ui_getbmp(char *path)
{
	int			fd;
	t_bmp		*bmp;
	int			skip;
	int			error;

	if ((fd = open(path, O_RDWR)) == -1)
	{
		close(fd);
		return (NULL);
	}
	if (!(bmp = ft_memalloc(sizeof(t_bmp))))
		return (NULL);
	read_header(fd, bmp);
	read_info(fd, bmp);
	if ((error = validate_bmp(bmp)))
		return (print_parse_error(error, bmp, path));
	skip = bmp->header.offset - bmp->info.header_size - sizeof(t_bmp_header);
	if ((bmp->palette = ft_memalloc(skip)))
		read(fd, bmp->palette, skip);
	bmp->pixel_count = bmp->info.width * bmp->info.height;
	if ((bmp->pixels = ft_memalloc(sizeof(unsigned) * bmp->pixel_count)))
		read_bmp(fd, bmp);
	close(fd);
	return (bmp);
}
