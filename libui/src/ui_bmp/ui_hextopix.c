/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_hextopix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 13:06:52 by alerandy          #+#    #+#             */
/*   Updated: 2019/06/11 13:19:01 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp_parser.h"

t_bmp_24	hex_to_bit24_pixel(unsigned color)
{
	t_bmp_24	pixel;

	pixel.r = color >> 16 & 0x000000FF;
	pixel.g = color >> 8 & 0x000000FF;
	pixel.b = color & 0x000000FF;
	return (pixel);
}

t_bmp_32	hex_to_bit32_pixel(unsigned color)
{
	t_bmp_32		pixel;

	pixel.a = color >> 24;
	pixel.r = color >> 16 & 0x000000FF;
	pixel.g = color >> 8 & 0x000000FF;
	pixel.b = color & 0x000000FF;
	return (pixel);
}