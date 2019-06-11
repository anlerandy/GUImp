/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_pixtohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 03:31:05 by alerandy          #+#    #+#             */
/*   Updated: 2019/06/11 13:20:28 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp_parser.h"

unsigned	bit24_pixel_to_hex(t_bmp_24 pixel)
{
	unsigned	a;

	a = pixel.r << 16;
	a += pixel.g << 8;
	a += pixel.b;
	return (a);
}

unsigned	bit32_pixel_to_hex(t_bmp_32 pixel)
{
	unsigned	a;

	a = pixel.a << 24;
	a += pixel.r << 16;
	a += pixel.g << 8;
	a += pixel.b;
	return (a);
}
