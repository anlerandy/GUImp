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

void	ui_render_layer(t_ui_win **win, t_ui_layer layer)
{
	t_ui_win	*tmp;
	unsigned	i;
	unsigned	limit_w;
	unsigned	*src;
	unsigned	*dst;

	tmp = *win;
	src = layer.pixels;
	dst = (unsigned *)tmp->surf->pixels;
	i = 0;
	limit_w = tmp->surf->w - layer.x < (int)layer.rescale_w \
				? tmp->surf->w : layer.rescale_w;
	while (layer.rescale_h > i || tmp->surf->h > (int)i)
	{
		ft_memcpy(dst + layer.x, src, limit_w * sizeof(unsigned));
		src += layer.width;
		dst += tmp->surf->w;
		++i;
	}
	SDL_UpdateWindowSurface(tmp->sdl_ptr);
}
