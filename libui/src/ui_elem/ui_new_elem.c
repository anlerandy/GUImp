/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_new_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 14:59:44 by gsmith            #+#    #+#             */
/*   Updated: 2019/06/13 11:35:33 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libui_tools.h"

unsigned int	ui_new_elem(t_ui_win *win, t_ui_new_elem param)
{
	t_ui_elem		*new_elem;

	if (win->id_next_elem == UINT_MAX)
		return (0);
	if (param.state > UI_ELEM_STATE_NB || param.elem_type > UI_ELEM_TYPE_NB)
		return (0);
	if (!(new_elem = (t_ui_elem *)ft_memalloc(sizeof(t_ui_elem))))
		return (0);
	if (!(new_elem->text = ft_strdup(param.text)))
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
	rb_insert(&(win->elements), new_elem, &ui_cmp_elem);
	new_elem->id = win->id_next_elem++;
	return (new_elem->id);
}
