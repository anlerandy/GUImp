/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_layer_from_window.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 11:47:52 by alerandy          #+#    #+#             */
/*   Updated: 2019/11/15 10:30:25 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui_layers.h"
#include "libui_tools.h"

t_ui_layer	*ui_layer_from_window(t_ui_win *win)
{
	SDL_Surface	*surf;
	t_ui_layer	*layer;

	if (!win || !(layer = ft_memalloc(sizeof(t_ui_layer))))
		return (NULL);
	surf = win->surf;
	if (!(layer->pixels = ft_memdup(surf->pixels, surf->w * surf->h \
									* sizeof(unsigned))))
	{
		free(layer);
		return (NULL);
	}
	*layer = (t_ui_layer){surf->w, surf->h, 0, 0, 0, surf->w, 1, surf->h, 1, \
							(t_vec2){0, 0}, layer->pixels};
	return (layer);
}
