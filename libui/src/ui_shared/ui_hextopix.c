/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_hextopix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 13:06:52 by alerandy          #+#    #+#             */
/*   Updated: 2019/10/08 18:29:49 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui_shared.h"

t_bgr	hex_to_bit24_pixel(unsigned color)
{
	t_bgr	pixel;

	pixel.r = color >> 16 & 0x000000FF;
	pixel.g = color >> 8 & 0x000000FF;
	pixel.b = color & 0x000000FF;
	return (pixel);
}

t_bgra	hex_to_bit32_pixel(unsigned color)
{
	t_bgra		pixel;

	pixel.a = color >> 24;
	pixel.r = color >> 16 & 0x000000FF;
	pixel.g = color >> 8 & 0x000000FF;
	pixel.b = color & 0x000000FF;
	return (pixel);
}

t_rgb	png_hex_to_bit24_pixel(unsigned color)
{
	t_rgb	pixel;

	pixel.r = color >> 16 & 0x000000FF;
	pixel.g = color >> 8 & 0x000000FF;
	pixel.b = color & 0x000000FF;
	return (pixel);
}

t_argb	png_hex_to_bit32_pixel(unsigned color)
{
	t_argb		pixel;

	pixel.a = color >> 24;
	pixel.r = color >> 16 & 0x000000FF;
	pixel.g = color >> 8 & 0x000000FF;
	pixel.b = color & 0x000000FF;
	return (pixel);
}
