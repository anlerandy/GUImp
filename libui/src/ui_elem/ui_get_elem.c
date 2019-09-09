/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_get_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 16:45:18 by gsmith            #+#    #+#             */
/*   Updated: 2019/09/09 14:07:43 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui_tools.h"

t_ui_elem		*ui_get_elem_by_id(t_ui_win *win, unsigned int elem_id)
{
	void	*search_res;

	if (!win)
		return (NULL);
	search_res = rb_search_infix(win->elements, (void *)&elem_id, \
			&ui_cmp_elem_id);
	if (!search_res)
		return (NULL);
	return ((t_ui_elem *)search_res);
}

t_ui_elem		*ui_get_elem_by_position(t_ui_win *win, unsigned x, unsigned y)
{
	void	*search_res;

	if (!win)
		return (NULL);
	search_res = rb_search_infix(win->elements, (int *)(unsigned[2]){x, y}, \
			&ui_cmp_elem_pos);
	if (!search_res)
		return (NULL);
	return ((t_ui_elem *)search_res);
}

t_ui_elem_used	ui_get_elem_context(t_ui_elem *elem, t_ui_event_data event)
{
	return ((t_ui_elem_used){elem->id, elem->state, 2,
			elem->text, elem->value, event});
}
