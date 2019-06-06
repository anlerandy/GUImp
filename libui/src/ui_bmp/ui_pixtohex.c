/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_pixtohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 03:31:05 by alerandy          #+#    #+#             */
/*   Updated: 2019/05/05 21:46:57 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp_parser.h"

unsigned	bit24_pixel_to_hex(t_bmp_24 pixel)
{
	unsigned	a;

	a = pixel.r * 256 * 256;
	a += pixel.g * 256;
	a += pixel.b;
	return (a);
}

unsigned	bit32_pixel_to_hex(t_bmp_32 pixel)
{
	unsigned	a;

	a = pixel.a * 256 * 256 * 256;
	a += pixel.r * 256 * 256;
	a += pixel.g * 256;
	a += pixel.b;
	return (a);
}
