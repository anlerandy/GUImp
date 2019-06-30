/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_render_layer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 11:18:03 by alerandy          #+#    #+#             */
/*   Updated: 2019/06/30 21:00:50 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp_parser.h"
#include "libui_layers.h"
#include "libui_tools.h"
#include "vectors.h"

static void	ui_render_layer_rescale(t_ui_win **win, t_ui_layer layer)
{
	t_ui_win	*tmp;
	int			i;
	int			j;
	unsigned	*dst;
	unsigned	*src;
	t_vec2		scale;

	tmp = *win;
	dst = (unsigned *)tmp->surf->pixels;
	src = (unsigned *)layer.pixels;
	scale.x = layer.rescale_w / layer.width;
	scale.y = layer.rescale_h / layer.height;
	j = (layer.y >= 0) ? layer.y : 0;
	while (j < layer.height * scale.y + layer.y && j <= tmp->surf->h)
	{
		i = (layer.x >= 0) ? layer.x : 0;
		while (i < (layer.width * scale.x) + layer.x && i <= tmp->surf->w)
		{
			dst[i + j * tmp->surf->w] = src[((int)((i - layer.x) / scale.x) \
											+ (int)((j - layer.y) / scale.y) \
											* tmp->surf->w)];
			i++;
		}
		j++;
	}
	SDL_UpdateWindowSurface(tmp->sdl_ptr);
}

void		ui_render_layer(t_ui_win **win, t_ui_layer layer)
{
	t_ui_win	*tmp;
	unsigned	i;
	int			limit_w;
	unsigned	*src;
	unsigned	*dst;

	tmp = *win;
	src = layer.pixels;
	dst = (unsigned *)tmp->surf->pixels;
	i = 0;
	limit_w = tmp->surf->w - layer.x < (int)layer.rescale_w \
				? tmp->surf->w : 2 * tmp->surf->w - layer.rescale_w - layer.x;
	if (limit_w < 0)
		return ;
	if (layer.width != layer.rescale_w || layer.height != layer.rescale_h)
	{
		ui_render_layer_rescale(win, layer);
		return ;
	}
	while (layer.rescale_h > i && tmp->surf->h > (int)i)
	{
		ft_memcpy(dst + layer.x, src, limit_w * sizeof(unsigned));
		src += layer.width;
		dst += tmp->surf->w;
		++i;
	}
	SDL_UpdateWindowSurface(tmp->sdl_ptr);
}
