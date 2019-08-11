/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_del_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 14:06:27 by gsmith            #+#    #+#             */
/*   Updated: 2019/08/11 15:20:50 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui_tools.h"

void			ui_del_event(t_ui_univers *univers, t_ui_new_event event)
{
	rb_remove(&(univers->events), \
				(unsigned *)((unsigned[2]){event.type, event.event}), \
					&ui_cmp_event_id, &ui_free_event);
}

void			ui_clear_events(t_ui_univers *univers)
{
	rb_clear_tree(&(univers->events), &ui_free_event);
}
