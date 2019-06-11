/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_putbmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 03:16:49 by alerandy          #+#    #+#             */
/*   Updated: 2019/06/06 14:29:12 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp_parser.h"

void	put_compression(unsigned compression)
{
	ft_putstr("Compression: ");
	if (compression == 0)
		ft_putendl("Uncompressed");
	if (compression == 1)
		ft_putendl("RLE-8");
	if (compression == 2)
		ft_putendl("RLE-4");
	if (compression == 3)
		ft_putendl("Bitfields");
}

void	ui_putbmp(t_bmp_header header, t_bmp_file bmp)
{
	ft_putstr("Taille du Header: ");
	ft_putnbr(bmp.header_size);
	ft_putstr("\nType de fichier: ");
	ft_putnstr((char*)header.type, 2);
	ft_putstr("\nTaille du fichier: ");
	ft_putnbr(header.size / 1000000);
	ft_putstr(" Mb\noffset: ");
	ft_putnbr(header.offset);
	ft_putstr("\nwidth: ");
	ft_putnbr(bmp.width);
	ft_putstr("px\nheight: ");
	ft_putnbr(bmp.height);
	ft_putstr("px\n");
	ft_putnbr(bmp.color_depth);
	ft_putendl("bits");
	ft_putnbr(bmp.width * bmp.height);
	ft_putendl(" Pixels");
	put_compression(bmp.compression);
	ft_putstr("Used color: ");
	ft_putnbr(bmp.used_color);
	ft_putstr("\n");
}

void	put_bmpinfo(char *path)
{
	t_bmp	bmp;

	bmp = ui_getbmp(path);
	if (!bmp.pixels)
		return (ft_putendl_fd("Failed to open and read BMP Info.", 2));
	ui_putbmp(bmp.header, bmp.info);
	ui_delbmp(&bmp);
}
