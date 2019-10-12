/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_scanline_to_rgb.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 13:21:48 by alerandy          #+#    #+#             */
/*   Updated: 2019/10/12 02:37:10 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui_png_tools.h"

void	ui_scanline_to_rgb(t_png *png, void *data)
{
	unsigned		x;
	unsigned		y;
	unsigned		i;
	unsigned		raw;
	unsigned char	filter;

	x = 0;
	y = 0;
	raw = 0;
	i = 0;
	(void)filter;
	(void)data;
	// while (png->pixel_count - ++i * sizeof(t_bgr) >= sizeof(t_bgr))
	// 	png->pixels[i] = ui_bgr_to_hex(*(t_bgr*)((unsigned char*)data \
	// 					+ i * sizeof(t_bgr)));
	while (y < png->header.height)
	{
		while (x < png->header.width)
		{
			// ++i;
			ft_putnbr(*(unsigned char*)(data + i));
			ft_putchar(' ');
			ft_putnbr(*(unsigned char*)(data + i + 1));
			ft_putchar(' ');
			ft_putnbr(*(unsigned char*)(data + i + 2));
			ft_putchar(' ');
			ft_putnbr(*(unsigned char*)(data + i + 3));
			ft_putchar(' ');
			i += 4;
			++x;
		}
		ft_putchar('\n');
		++y;
		x = 0;
	}
}
