/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_get_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 16:45:18 by gsmith            #+#    #+#             */
/*   Updated: 2019/06/12 16:47:09 by gsmith           ###   ########.fr       */
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
