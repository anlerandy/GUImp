/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_hextopix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 13:06:52 by alerandy          #+#    #+#             */
/*   Updated: 2019/06/06 13:12:10 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp_parser.h"

t_bmp_24	hex_to_bit24_pixel(unsigned color)
{
	t_bmp_24	pixel;

	pixel.r = (color / 256 / 256) & 0x0000FF;
	pixel.g += (color / 256) & 0x0000FF;
	pixel.b += color & 0x0000FF;
	return (pixel);
}

t_bmp_32	hex_to_bit32_pixel(unsigned color)
{
	t_bmp_32		pixel;
	unsigned char	*char_clr;

	char_clr = (unsigned char*)&color;
	pixel.a = char_clr[0];
	pixel.r += char_clr[1];
	pixel.g += char_clr[2];
	pixel.b += char_clr[3];
	return (pixel);
}
