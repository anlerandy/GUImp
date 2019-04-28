/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_putbmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 03:16:49 by alerandy          #+#    #+#             */
/*   Updated: 2019/04/28 04:11:58 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp_parser.h"

void	ui_putbmp( t_bmp_header header, t_bmp_file bmp)
{
	ft_putstr("bfType: ");
	ft_putchar(header.bfType[0]);
	ft_putchar(header.bfType[1]);
	ft_putstr("\nbfSize: ");
	ft_putnbr(header.bfSize);
	ft_putstr("\nbfOffBits: ");
	ft_putnbr(header.bfOffBits);
	ft_putstr("\nwidth: ");
	ft_putnbr(bmp.width);
	ft_putstr("\nheight: ");
	ft_putnbr(bmp.height);
	ft_putstr("\n");
	ft_putnbr(bmp.biBitCount);
	ft_putendl("bits.");
	ft_putnbr(bmp.width * bmp.height);
	ft_putendl(" Pixels.");
}
