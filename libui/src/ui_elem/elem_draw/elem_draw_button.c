/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_draw_button.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:57:07 by alerandy          #+#    #+#             */
/*   Updated: 2019/09/14 12:56:20 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui_layers.h"
#include "libui.h"
#include "libui_draw.h"
#include "libui_elem.h"
#include "libui_ttf.h"

void	elem_draw_button(t_ui_win *win, t_ui_elem *elem)
{
	t_ui_layer		*layer;
	t_ui_draw_param	param;
	t_ui_layer		*text;

	param = (t_ui_draw_param){elem->w, elem->h, elem->x, elem->y, \
															0x800000FF, 1, 1};
	text = ui_ttf_to_layer(NULL, elem->text, (t_ui_ttf_param){ 8, 8, \
											elem->w - 16, 0, 0, 0, 0xFFFFFF });
	layer = ui_rect_to_layer(param);
	ui_render_layer(&win, layer);
	ui_render_layer(&win, text);
	ui_free_layer(&layer);
	ui_free_layer(&text);
}