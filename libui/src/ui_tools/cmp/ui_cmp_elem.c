/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_cmp_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 15:20:34 by gsmith            #+#    #+#             */
/*   Updated: 2019/06/11 15:30:26 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui_tools.h"

int				ui_cmp_elem(void *ptr_a, void *ptr_b)
{
	t_ui_elem	*elem_a;
	t_ui_elem	*elem_b;

	if (!ptr_a && !ptr_b)
		return (0);
	if (!ptr_a)
		return (-1);
	if (!ptr_b)
		return (1);
	elem_a = (t_ui_elem *)ptr_a;
	elem_b = (t_ui_elem *)ptr_b;
	return (elem_a->id - elem_b->id);
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
