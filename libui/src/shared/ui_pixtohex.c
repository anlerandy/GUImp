/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_pixtohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 03:31:05 by alerandy          #+#    #+#             */
/*   Updated: 2019/06/30 18:24:55 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui_shared.h"

unsigned	bit24_pixel_to_hex(t_rgb pixel)
{
	unsigned	a;

	a = pixel.r << 16;
	a += pixel.g << 8;
	a += pixel.b;
	return (a);
}

unsigned	bit32_pixel_to_hex(t_rgba pixel)
{
	unsigned	a;

	a = pixel.a << 24;
	a += pixel.r << 16;
	a += pixel.g << 8;
	a += pixel.b;
	return (a);
}
