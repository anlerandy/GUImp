/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_del_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 14:06:27 by gsmith            #+#    #+#             */
/*   Updated: 2019/06/12 16:22:58 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui_tools.h"

void			ui_del_event(t_ui_univers *univers, unsigned int event_id[2])
{
	rb_remove(&(univers->events), &event_id, &ui_cmp_event_id, &ui_free_event);
}

void			ui_clear_events(t_ui_univers *univers)
{
	rb_clear_tree(&(univers->events), &ui_free_event);
}
