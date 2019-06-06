/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_layer_to_bmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 20:27:10 by alerandy          #+#    #+#             */
/*   Updated: 2019/06/06 13:22:55 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp_parser.h"
#include "bmp_parser_tools.h"
#include "libui_layers.h"
#include "ui_shared.h"

void	layer_to_bmp_header(t_bmp *bmp, t_ui_layer layer)
{
	bmp->header.type[0] = 'B';
	bmp->header.type[1] = 'M';
	bmp->header.size = 54 + ((layer.rescale_w * layer.rescale_h) \
						* sizeof(t_bmp_32));
	bmp->header.offset = 54;
	bmp->info.header_size = 40;
	bmp->info.width = layer.rescale_w;
	bmp->info.height = layer.rescale_h;
	bmp->info.planes = 1;
	bmp->info.color_depth = 32;
}

void	write_header(int fd, t_bmp *bmp)
{
	write(fd, &bmp->header.type, sizeof(bmp->header.type));
	write(fd, &bmp->header.size, sizeof(bmp->header.size));
	write(fd, &bmp->header.reserved1, sizeof(bmp->header.reserved1));
	write(fd, &bmp->header.reserved2, sizeof(bmp->header.reserved2));
	write(fd, &bmp->header.offset, sizeof(bmp->header.offset));
	ft_putstr("header size: ");
	ft_putnbr(sizeof(bmp->header.type) + sizeof(bmp->header.size) + sizeof(bmp->header.reserved1) + sizeof(bmp->header.reserved2) + sizeof(bmp->header.offset));
	ft_putstr(" + ");
}

void	write_info(int fd, t_bmp *bmp)
{
	write(fd, &bmp->info.header_size, sizeof(bmp->info.header_size));
	write(fd, &bmp->info.width, sizeof(bmp->info.width));
	write(fd, &bmp->info.height, sizeof(bmp->info.height));
	write(fd, &bmp->info.planes, sizeof(bmp->info.planes));
	write(fd, &bmp->info.color_depth, sizeof(bmp->info.color_depth));
	write(fd, &bmp->info.compression, sizeof(bmp->info.compression));
	write(fd, &bmp->info.image_size, sizeof(bmp->info.image_size));
	write(fd, &bmp->info.width_meter, sizeof(bmp->info.width_meter));
	write(fd, &bmp->info.height_meter, sizeof(bmp->info.height_meter));
	write(fd, &bmp->info.used_color, sizeof(bmp->info.used_color));
	write(fd, &bmp->info.important_color, sizeof(bmp->info.important_color));
	ft_putnbr(sizeof(bmp->info));
	ft_putchar('\n');
}

void	write_pixels(int fd, t_ui_layer layer)
{
	unsigned	*pixels;
	unsigned	length;
	unsigned	x;
	unsigned	y;

	length = layer.rescale_h * layer.rescale_w;
	if (!(pixels = ft_memalloc(sizeof(unsigned) * length)))
		return (close_fd(fd, "Allocation failed. Unable to save."));
	y = 0;
	while (++y <= layer.rescale_h)
	{
		x = 0;
		while (x < layer.rescale_w)
			*(pixels + x++ + (layer.rescale_h - y) * layer.rescale_w) \
										= *(layer.pixels++);
	}
	write(fd, pixels, length * sizeof(t_bmp_32));
	free(pixels);
}

void	ui_layer_to_bmp(t_ui_layer layer, char *path)
{
	t_bmp		bmp;
	int			fd;

	if (!layer.pixels)
		return (ft_putendl_fd("Your layer is empty. Unable to save.", 2));
	ft_bzero(&bmp, sizeof(t_bmp));
	if (!(fd = open(path, O_RDWR | O_APPEND | O_CREAT | O_TRUNC, 0666)))
		return (close_fd(fd, "Unable to open/create a the file."));
	layer_to_bmp_header(&bmp, layer);
	write_header(fd, &bmp);
	write_info(fd, &bmp);
	write_pixels(fd, layer);
	close(fd);
}
