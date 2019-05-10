/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_new_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 13:15:11 by gsmith            #+#    #+#             */
/*   Updated: 2019/05/10 11:36:11 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include "libui_tools.h"

int				ui_new_event(t_ui_univers *univers, unsigned int event_id[2], \
						void (*callback)(t_ui_univers **, void *, \
							t_ui_event_data), void *config_callback)
{
	t_ui_event	*eve;

	eve = (t_ui_event *)rb_search_infix(univers->events, &event_id, \
			&ui_cmp_event_id);
	if (eve)
	{
		eve->callback = callback;
		eve->config = config_callback;
		return (0);
	}
	if (!(eve = (t_ui_event *)ft_memalloc(sizeof(t_ui_event))))
	{
		ft_putendl_fd(ERR_MALLOC, STDERR_FILENO);
		return (1);
	}
	eve->id[0] = event_id[0];
	eve->id[1] = event_id[1];
	eve->callback = callback;
	eve->config = config_callback;
	rb_insert(&(univers->events), eve, &ui_cmp_event);
	return (0);
}
