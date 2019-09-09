/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_cmp_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 15:20:34 by gsmith            #+#    #+#             */
/*   Updated: 2019/09/09 14:02:04 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui_tools.h"

int				ui_cmp_elem(void *ptr_a, void *ptr_b)
{
	t_ui_elem	*elem_a;
	t_ui_elem	*elem_b;
	unsigned	position_a;
	unsigned	position_b;

	if (!ptr_a && !ptr_b)
		return (0);
	if (!ptr_a)
		return (-1);
	if (!ptr_b)
		return (1);
	elem_a = (t_ui_elem *)ptr_a;
	elem_b = (t_ui_elem *)ptr_b;
	position_a = elem_a->x * elem_a->y;
	position_b = elem_b->x * elem_b->y;
	return (position_a - position_b);
}

int				ui_cmp_elem_id(void *ptr_elem, void *ptr_id)
{
	int			id;
	t_ui_elem	*elem;

	if (!ptr_elem && !ptr_id)
		return (0);
	if (!ptr_elem)
		return (-1);
	if (!ptr_id)
		return (1);
	elem = (t_ui_elem *)ptr_elem;
	id = *(int *)ptr_id;
	return (elem->id - id);
}

int				ui_cmp_elem_pos(void *ptr_elem, void *ptr_pos)
{
	t_ui_elem	*elem;
	unsigned	x;
	unsigned	y;

	if (!ptr_elem && !ptr_pos)
		return (0);
	if (!ptr_elem)
		return (-1);
	if (!ptr_pos)
		return (1);
	elem = (t_ui_elem *)ptr_elem;
	x = ((unsigned *)ptr_pos)[0];
	y = ((unsigned *)ptr_pos)[1];
	return (!(elem->w + elem->x >= x && elem->x <= x \
				&& elem->h + elem->y >= y && elem->y <= y));
}
