/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui_layers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 10:43:28 by alerandy          #+#    #+#             */
/*   Updated: 2019/11/15 11:00:49 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUI_LAYERS_H
# define LIBUI_LAYERS_H

# include "libui.h"
# include "vectors.h"

typedef struct	s_ui_layer
{
	unsigned	width;
	unsigned	height;
	int			index;
	int			x;
	int			y;
	unsigned	rescale_w;
	int			width_inversed;
	unsigned	rescale_h;
	int			height_inversed;
	t_vec2		scale;
	unsigned	*pixels;
}				t_ui_layer;

t_ui_layer		*ui_image_to_layer(char *path);
void			ui_render_layer(t_ui_win **win, t_ui_layer *layer);
void			ui_layer_to_bmp(t_ui_layer *layer, char *path);
void			ui_layer_into_layer(t_ui_layer *dst, t_ui_layer *src);
void			ui_free_layer(t_ui_layer **layer);
t_ui_layer		*ui_layer_from_window(t_ui_win *win);
t_ui_layer		*ui_duplicate_layer(t_ui_layer *src);

#endif
