/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars_to_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 04:24:46 by alerandy          #+#    #+#             */
/*   Updated: 2019/05/09 04:27:13 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"
#include "ui_png.h"

unsigned	bit24_pixel_to_hex(t_rgb pixel)
{
	unsigned	a;

	a = pixel.r * 256 * 256;
	a += pixel.g * 256;
	a += pixel.b;
	return (a);
}

unsigned	bit32_pixel_to_hex(t_rgba pixel)
{
	unsigned	a;

	a = pixel.r * 256 * 256 * 256;
	a += pixel.g * 256 * 256;
	a += pixel.b * 256;
	a += pixel.a;
	return (a);
}
