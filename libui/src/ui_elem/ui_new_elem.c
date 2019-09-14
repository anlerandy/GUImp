/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_new_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 14:59:44 by gsmith            #+#    #+#             */
/*   Updated: 2019/09/14 12:33:07 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libui_tools.h"

void			ui_draw_elem(t_ui_win *win, t_ui_elem *elem)
{
	if (elem->type == UI_ELEM_TYPE_BUTTON)
		elem_draw_button(win, elem);
}

unsigned int	ui_new_elem(t_ui_win *win, t_ui_new_elem param)
{
	t_ui_elem		*new_elem;

	if (win->id_next_elem == UINT_MAX || param.state > UI_ELEM_STATE_NB \
										|| param.elem_type > UI_ELEM_TYPE_NB)
		return (0);
	new_elem = (t_ui_elem *)ft_memalloc(sizeof(t_ui_elem));
	if (!new_elem || !(new_elem->text = ft_strdup(param.text)))
	{
		ft_memdel((void**)&new_elem);
		return (0);
	}
	new_elem->value = param.value;
	new_elem->x = param.x;
	new_elem->y = param.y;
	new_elem->w = param.w;
	new_elem->h = param.h;
	new_elem->type = param.elem_type;
	new_elem->state = param.state;
	new_elem->id = win->id_next_elem++;
	new_elem->callback = param.callback;
	rb_insert(&(win->elements), new_elem, &ui_cmp_elem);
	ui_draw_elem(win, new_elem);
	return (new_elem->id);
}
