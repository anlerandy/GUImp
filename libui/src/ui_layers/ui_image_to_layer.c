/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_image_to_layer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 10:47:50 by alerandy          #+#    #+#             */
/*   Updated: 2019/07/26 13:48:17 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp_parser_tools.h"
#include "bmp_parser.h"
#include "libui_layers.h"

t_ui_layer		*ui_image_to_layer(char *path)
{
	t_bmp		*bmp;
	t_ui_layer	*layer;

	if (!(layer = ft_memalloc(sizeof(t_ui_layer))))
		return (NULL);
	bmp = ui_getbmp(path);
	if (!bmp || !(layer->pixels = ft_memalloc(sizeof(unsigned) \
														* bmp->pixel_count)))
	{
		ft_putendl_fd(!bmp ? "BMP Failed." : "Layer allocation failed.", 2);
		ft_memdel((void**)&layer);
		return (layer);
	}
	ft_memcpy(layer->pixels, bmp->pixels, sizeof(unsigned) * bmp->pixel_count);
	layer->width = bmp->info.width;
	layer->height = bmp->info.height;
	layer->rescale_w = bmp->info.width;
	layer->rescale_h = bmp->info.height;
	layer->width_inversed = 1;
	layer->height_inversed = 1;
	ui_delbmp(&bmp);
	return (layer);
}
