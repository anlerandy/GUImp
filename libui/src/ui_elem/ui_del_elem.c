/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_del_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 15:23:38 by gsmith            #+#    #+#             */
/*   Updated: 2019/06/11 15:36:15 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui_tools.h"

void	ui_del_elem(t_ui_win *win, unsigned int id)
{
	if (!win)
		return ;
	rb_remove(&(win->elements), (void *)&id, &ui_cmp_elem_id, \
		&ui_free_elem);
}
