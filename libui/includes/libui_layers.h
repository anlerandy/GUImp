/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui_layers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 10:43:28 by alerandy          #+#    #+#             */
/*   Updated: 2019/06/07 14:18:35 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUI_LAYERS_H
# define LIBUI_LAYERS_H

# include "libui.h"

typedef struct	s_ui_layer
{
	unsigned	*pixels;
	unsigned	width;
	unsigned	height;
	int			index;
	int			x;
	int			y;
	unsigned	rescale_w;
	int			width_inversed;
	unsigned	rescale_h;
	int			height_inversed;
}				t_ui_layer;

t_ui_layer		ui_image_to_layer(char *path);
void			ui_render_layer(t_ui_win **win, t_ui_layer layer);
void			ui_layer_to_bmp(t_ui_layer layer, char *path);
void			ui_layer_into_layer(t_ui_layer *dst, t_ui_layer *src);

#endif
