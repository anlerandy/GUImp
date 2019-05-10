/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_run_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 14:28:27 by gsmith            #+#    #+#             */
/*   Updated: 2019/05/10 18:44:39 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui_tools.h"

int				ui_wait_event(t_ui_univers **univers)
{
	int				res;
	SDL_Event		eve;
	unsigned int	id[2];
	t_ui_event_data	data;
	t_ui_event		*eve_call;

	if (!univers || !*univers)
		return (0);
	(void)univers;
	if ((res = SDL_PollEvent(&eve)))
	{
		if (ui_generate_event_id(&eve, &id[0], &id[1], &data))
			return (res);
		eve_call = (t_ui_event *)(rb_search_infix((*univers)->events, &id, \
					&ui_cmp_event_id));
		if (!eve_call)
			return (res);
		eve_call->callback(univers, eve_call->config, data);
	}
	return (res);
}

void			ui_watch_events(t_ui_univers **univers)
{
	t_ui_univers	*univ;

	if (!univers || !(univ = *univers))
		return ;
	univ->run_event = 1;
	while (univ->run_event && ui_wait_event(univers))
		continue ;
}
