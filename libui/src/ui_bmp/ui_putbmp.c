/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_putbmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 03:16:49 by alerandy          #+#    #+#             */
/*   Updated: 2019/05/05 17:11:14 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp_parser.h"

void	putCompression(unsigned compression)
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
	ft_putnbr(sizeof(t_bmp_header) + sizeof(t_bmp_file));
	ft_putstr("\nType de fichier: ");
	ft_putchar(header.bfType[0]);
	ft_putchar(header.bfType[1]);
	ft_putstr("\nTaille du fichier: ");
	ft_putnbr(header.bfSize / 1000000);
	ft_putstr(" Mb\nbfOffBits: ");
	ft_putnbr(header.bfOffBits);
	ft_putstr("\nwidth: ");
	ft_putnbr(bmp.width);
	ft_putstr("px\nheight: ");
	ft_putnbr(bmp.height);
	ft_putstr("px\n");
	ft_putnbr(bmp.biBitCount);
	ft_putendl("bits");
	ft_putnbr(bmp.width * bmp.height);
	ft_putendl(" Pixels");
	putCompression(bmp.biCompression);
	ft_putstr("Used color: ");
	ft_putnbr(bmp.biClrUsed);
	ft_putstr("\n");
}
