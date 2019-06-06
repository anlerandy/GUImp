/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_image_to_layer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 10:47:50 by alerandy          #+#    #+#             */
/*   Updated: 2019/06/03 14:26:32 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp_parser_tools.h"
#include "bmp_parser.h"
#include "libui_layers.h"

t_ui_layer		ui_image_to_layer(char *path)
{
	t_bmp		bmp;
	t_ui_layer	layer;

	ft_bzero(&layer, sizeof(t_ui_layer));
	bmp = ui_getbmp(path);
	if (!bmp.pixels)
	{
		ft_putendl_fd("You layer failed and is empty.", 2);
		return (layer);
	}
	if (!(layer.pixels = ft_memalloc(sizeof(unsigned) * bmp.pixel_count)))
	{
		ft_putendl_fd("You layer failed and is empty.", 2);
		return (layer);
	}
	ft_memcpy(layer.pixels, bmp.pixels, sizeof(unsigned) * bmp.pixel_count);
	layer.width = bmp.info.width;
	layer.height = bmp.info.height;
	layer.rescale_w = bmp.info.width;
	layer.rescale_h = bmp.info.height;
	ui_delbmp(&bmp);
	return (layer);
}
