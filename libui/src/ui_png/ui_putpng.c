/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_putpng.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 03:16:49 by alerandy          #+#    #+#             */
/*   Updated: 2019/05/08 23:58:43 by alerandy         ###   ########.fr       */
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

void	ui_putpng(t_png png)
{
	put_signature(png.signature);
	ft_putstr("Width: ");
	ft_putnbr(png.header.width);
	ft_putstr("\nheight: ");
	ft_putnbr(png.header.height);
	ft_putchar('\n');
}
