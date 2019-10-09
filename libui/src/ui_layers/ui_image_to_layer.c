/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_image_to_layer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 10:47:50 by alerandy          #+#    #+#             */
/*   Updated: 2019/10/08 22:02:57 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp_parser_tools.h"
#include "bmp_parser.h"
#include "ui_png.h"
#include "ui_png_tools.h"
#include "libui_layers.h"

t_ui_layer		*ui_bmp_to_layer(char *path)
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
		ui_free_layer(&layer);
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

t_ui_layer		*ui_png_to_layer(char *path)
{
	t_png		png;
	t_ui_layer	*layer;

	if (!(layer = ft_memalloc(sizeof(t_ui_layer))))
		return (NULL);
	png = ui_getpng(path);
	if (!png.pixels || !(layer->pixels = ft_memalloc(sizeof(unsigned) \
														* png.pixel_count)))
	{
		ft_putendl_fd(!png.pixels ? "PNG Failed." : "Layer allocation failed.", 2);
		ui_free_layer(&layer);
		return (layer);
	}
	ft_memcpy(layer->pixels, png.pixels, sizeof(unsigned) * png.pixel_count);
	layer->width = png.header.width;
	layer->height = png.header.height;
	layer->rescale_w = png.header.width;
	layer->rescale_h = png.header.height;
	layer->width_inversed = 1;
	layer->height_inversed = 1;
	return (layer);
}

t_ui_layer		*ui_image_to_layer(char *path)
{
	int		len;
	char	*file_type;

	len = ft_strlen(path);
	if ((file_type = ft_strrchr(path, '.')))
	{
		if (!ft_strncmp(file_type + 1, "bmp", 3))
			return (ui_bmp_to_layer(path));
		if (!ft_strncmp(file_type + 1, "png", 3))
			return (ui_png_to_layer(path));
	}
	ft_putstr_fd("Unknown file type. ", 2);
	ft_putendl_fd(file_type ? file_type + 1 : path, 2);
	return (NULL);
}


