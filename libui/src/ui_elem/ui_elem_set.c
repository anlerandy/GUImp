/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_elem_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 16:49:09 by gsmith            #+#    #+#             */
/*   Updated: 2019/06/13 10:57:31 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui_tools.h"

void	ui_elem_set_state(t_ui_elem *elem, unsigned int new_state)
{
	if (!elem || new_state > UI_ELEM_STATE_NB)
		return ;
	elem->state = new_state;
}

void	ui_elem_set_text(t_ui_elem *elem, char *new_text)
{
	if (!elem || !new_text)
		return ;
	elem->text = new_text;
}

void	ui_elem_set_value(t_ui_elem *elem, void *new_value)
{
	if (!elem || !new_value)
		return ;
	elem->value = new_value;
}

void	ui_elem_set_callback(t_ui_elem *elem, void (*callback) \
			(t_ui_univers **uni, t_ui_elem_used *context))
{
	if (!elem || !callback)
		return ;
	elem->callback = callback;
}
