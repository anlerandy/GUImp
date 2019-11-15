/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_hexconv16.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 18:56:48 by alerandy          #+#    #+#             */
/*   Updated: 2019/11/15 18:57:03 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui_shared.h"

t_argb	ui_hex_to_abgr_16(unsigned long color)
{
	t_argb		pixel;

	pixel.a = ((color >> 32) >> 16);
	pixel.b = (color >> 32 & 0x000000000000FFFF);
	pixel.g = (color >> 16 & 0x000000000000FFFF);
	pixel.r = (color & 0x000000000000FFFF);
	return (pixel);
}