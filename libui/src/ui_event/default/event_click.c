/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_click.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:42:44 by alerandy          #+#    #+#             */
/*   Updated: 2019/09/19 18:18:28 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"
#include "libui_elem.h"

void	callback_click(t_ui_univers **uni, void *data, t_ui_event_data event)
{
	t_ui_elem		*elem;
	t_ui_elem_used	context;

	(void)data;
	if (!(elem = ui_get_elem_by_position(
			ui_get_window_by_id(*uni, event.win_id), event.x, event.y)))
		return ;
	context = ui_get_elem_context(elem, event);
	if (!elem->callback)
		return ;
	elem->callback(uni, &context);
}
