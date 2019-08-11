/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_new_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 13:15:11 by gsmith            #+#    #+#             */
/*   Updated: 2019/08/11 15:42:15 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui_error.h"
#include "libft.h"
#include "libui_tools.h"

int				ui_new_event(t_ui_univers *univers, t_ui_new_event event, \
						void (*callback)(t_ui_univers **, void *, \
							t_ui_event_data), void *config_callback)
{
	t_ui_event	*eve;
	t_rb_node	*events;

	events = event.win ? event.win->events : univers->events;
	eve = (t_ui_event *)rb_search_infix(events, \
					(unsigned *)((unsigned[2]){event.type, event.event}), \
						&ui_cmp_event_id);
	if (!eve)
		if (!(eve = (t_ui_event *)ft_memalloc(sizeof(t_ui_event))))
		{
			ft_putendl_fd(ERR_MALLOC, STDERR_FILENO);
			return (1);
		}
	eve->id[0] = event.type;
	eve->id[1] = event.event;
	eve->callback = callback;
	eve->config = config_callback;
	rb_insert(&(univers->events), eve, &ui_cmp_event);
	return (0);
}
