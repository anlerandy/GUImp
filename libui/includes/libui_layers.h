/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui_layers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 10:43:28 by alerandy          #+#    #+#             */
/*   Updated: 2019/05/31 14:20:38 by alerandy         ###   ########.fr       */
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

#endif
