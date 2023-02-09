/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 18:05:21 by alerandy          #+#    #+#             */
/*   Updated: 2019/11/04 07:23:50 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp_parser.h"
#include "libui.h"
#include "libui_tools.h"
#include "ui_shared.h"
#include "ui_png_tools.h"
#include "libui_layers.h"
#include "vectors.h"

t_ui_win	*ui_layer_to_window(t_ui_univers *univers, char *path)
{
	t_ui_win		*win;
	t_ui_win_param	param;
	t_ui_layer		*layer;
	t_pos			size;

	if (!(layer = ui_image_to_layer(path)))
	{
		ft_putstr("Something went wrong when opening image file: ");
		ft_putendl(path);
		return (NULL);
	}
	size = get_adaptative_size(layer->width, layer->height);
	param = (t_ui_win_param){0, 0, (unsigned)size.x, (unsigned)size.y, \
		UI_WINDOW_SHOWN};
	layer->rescale_w = (unsigned)size.x;
	layer->rescale_h = (unsigned)size.y;
	if (!(win = ui_new_window(univers, param, get_file_name(path))))
	{
		ui_free_layer(&layer);
		return (NULL);
	}
	ui_render_layer(&win, layer);
	ui_free_layer(&layer);
	return (win);
}

t_ui_win	*ui_open_image(t_ui_univers *univers, char *path)
{
	char	*file_type;

	if ((file_type = ft_strrchr(path, '.')))
	{
		if (!ft_strncmp(file_type + 1, "bmp", 3) \
				|| !ft_strncmp(file_type + 1, "png", 3))
			return (ui_layer_to_window(univers, path));
	}
	ft_putstr_fd("Unknown file type. ", 2);
	ft_putendl_fd(file_type ? file_type + 1 : path, 2);
	return (NULL);
}
