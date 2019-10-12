/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_hextopix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 13:06:52 by alerandy          #+#    #+#             */
/*   Updated: 2019/10/12 02:39:57 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui_shared.h"

t_bgr	ui_hex_to_bgr(unsigned color)
{
	t_bgr	pixel;

	pixel.r = color >> 16 & 0x000000FF;
	pixel.g = color >> 8 & 0x000000FF;
	pixel.b = color & 0x000000FF;
	return (pixel);
}

t_bgra	ui_hex_to_bgra(unsigned color)
{
	t_bgra		pixel;

	pixel.a = color >> 24;
	pixel.r = color >> 16 & 0x000000FF;
	pixel.g = color >> 8 & 0x000000FF;
	pixel.b = color & 0x000000FF;
	return (pixel);
}

t_rgb	ui_hex_to_rgb(unsigned color)
{
	t_rgb	pixel;

	pixel.r = color >> 16 & 0x000000FF;
	pixel.g = color >> 8 & 0x000000FF;
	pixel.b = color & 0x000000FF;
	return (pixel);
}

t_argb	ui_hex_to_argb(unsigned color)
{
	t_argb		pixel;

	pixel.a = color >> 24;
	pixel.r = color >> 16 & 0x000000FF;
	pixel.g = color >> 8 & 0x000000FF;
	pixel.b = color & 0x000000FF;
	return (pixel);
}
