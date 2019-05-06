/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_del_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 14:06:27 by gsmith            #+#    #+#             */
/*   Updated: 2019/05/06 14:19:33 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui_tools.h"

void			ui_del_event(t_ui_univers *univers, unsigned int event_id)
{
	rb_remove(&(univers->events), &event_id, &ui_cmp_event_id, &ui_free_event);
}
