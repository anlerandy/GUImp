/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_render_layer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 11:18:03 by alerandy          #+#    #+#             */
/*   Updated: 2019/05/31 14:21:07 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "bmp_parser.h"
#include "libui_layers.h"
#include "libui_tools.h"
#include "vectors.h"

static void		ui_render_layer_rescale(t_ui_win **win, t_ui_layer layer)
{
	t_ui_win	*tmp;
	t_isize		l;
	unsigned	*dst;
	unsigned	*src;
	t_vec2		scale;

	tmp = *win;
	dst = (unsigned *)tmp->surf->pixels;
	src = (unsigned *)layer.pixels;
	scale.x = (double)layer.rescale_w / (double)layer.width;
	scale.y = (double)layer.rescale_h / (double)layer.height;
	l.x = (layer.y >= 0) ? layer.y : 0;
	while (l.x < layer.height * scale.y + layer.y && l.x <= tmp->surf->h)
	{
		l.y = (layer.x >= 0) ? layer.x : 0;
		while (l.y < (layer.width * scale.x) + layer.x && l.y <= tmp->surf->w)
		{
			dst[l.y + l.x * tmp->surf->w] = src[((int)((l.y - layer.x)
				/ scale.x) + (int)((l.x - layer.y) / scale.y) * tmp->surf->w)];
			l.y++;
		}
		l.x++;
	}
	SDL_UpdateWindowSurface(tmp->sdl_ptr);
}

void			ui_render_layer(t_ui_win **win, t_ui_layer layer)
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
	limit_w = tmp->surf->w - layer.x < (int)layer.rescale_w
				? tmp->surf->w : 2 * tmp->surf->w - layer.rescale_w - layer.x;
	if (limit_w < 0)
		return ;
	if (layer.width != layer.rescale_w || layer.height != layer.rescale_h)
		return (ui_render_layer_rescale(win, layer));
	while (layer.rescale_h > i && tmp->surf->h > (int)i)
	{
		ft_memcpy(dst + layer.x, src, limit_w * sizeof(unsigned));
		src += layer.width;
		dst += tmp->surf->w;
		++i;
	}
	SDL_UpdateWindowSurface(tmp->sdl_ptr);
}
