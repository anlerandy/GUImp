/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_putpng.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 03:16:49 by alerandy          #+#    #+#             */
/*   Updated: 2019/05/10 20:38:37 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui_png.h"

void	put_signature(unsigned char *signature)
{
	ft_putstr("Signature: ");
	ft_putnbr(signature[0]);
	ft_putstr(" ");
	ft_putnbr(signature[1]);
	ft_putstr(" ");
	ft_putnbr(signature[2]);
	ft_putstr(" ");
	ft_putnbr(signature[3]);
	ft_putstr(" ");
	ft_putnbr(signature[4]);
	ft_putstr(" ");
	ft_putnbr(signature[5]);
	ft_putstr(" ");
	ft_putnbr(signature[6]);
	ft_putstr(" ");
	ft_putnbr(signature[7]);
	ft_putendl("");
}

void	put_color(unsigned char color)
{
	ft_putstr("Color format: ");
	if (color == PNGGRAY)
		ft_putendl("GRAY");
	else if (color == PNGRGB)
		ft_putendl("RGB");
	else if (color == PNGINDEX)
		ft_putendl("INDEX");
	else if (color == PNGGRAYA)
		ft_putendl("GRAYA");
	else if (color == PNGAGRAY)
		ft_putendl("AGRAY");
	else if (color == PNGRGBA)
		ft_putendl("RGBA");
	else if (color == PNGARGB)
		ft_putendl("ARGB");
}

void	put_filter(unsigned char filter)
{
	ft_putstr("Filter: ");
	if (!filter)
		ft_putendl("None");
	else if (filter == 1)
		ft_putendl("Sub");
	else if (filter == 2)
		ft_putendl("Up");
	else if (filter == 3)
		ft_putendl("Average");
	else if (filter == 4)
		ft_putendl("Paeth");
}

void	put_compression(unsigned char compression)
{
	int		idat;
	int		ihdr;

	idat = compression / 10;
	ihdr = compression % 10;
	ft_putstr("Compression: ");
	ft_putendl(ihdr ? "Compressed" : "None");
	ft_putstr("Pixels compression: ");
	if (idat == 1)
		ft_putendl("None");
	if (idat == 2)
		ft_putendl("Low");
	if (idat == 3)
		ft_putendl("Medium");
	if (idat == 4)
		ft_putendl("Strong");
	if (idat == 5)
		ft_putendl("gZIP");
}

void	ui_putpng(t_png png)
{
	put_signature(png.signature);
	ft_putstr("Width: ");
	ft_putnbr(png.header.width);
	ft_putstr("\nHeight: ");
	ft_putnbr(png.header.height);
	ft_putstr("\nBit depth: ");
	ft_putnbr(png.header.bit);
	ft_putchar('\n');
	put_color(png.header.color);
	put_compression(png.header.compression);
	put_filter(png.header.filter);
	ft_putstr("Interlace: ");
	ft_putendl(png.header.interlace ? "Adam7" : "None");
}
