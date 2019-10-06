/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui_draw.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 21:29:20 by alerandy          #+#    #+#             */
/*   Updated: 2019/08/08 18:27:53 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUI_DRAW_H
# define LIBUI_DRAW_H

typedef struct s_ui_layer	t_ui_layer;
typedef struct s_ui_win		t_ui_win;
typedef struct	s_ui_draw_param
{
	unsigned	width;
	unsigned	height;
	unsigned	x;
	unsigned	y;
	unsigned	color;
	unsigned	radius;
	unsigned	angle;
}				t_ui_draw_param;

t_ui_layer		*ui_rect_to_layer(t_ui_draw_param param);
void			ui_rect_in_win(t_ui_win *win, t_ui_draw_param param);

#endif
