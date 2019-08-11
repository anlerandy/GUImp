/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_run_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 14:28:27 by gsmith            #+#    #+#             */
/*   Updated: 2019/08/11 16:02:37 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui_tools.h"

// static void			redirect_blocker(t_ui_univers *univers, t_ui_event_data *data)
// {
// 	t_ui_win	*win;

// 	if (!(win = ui_get_window_by_id(univers, data->win_id)) || !win->blocked)
// 		return ;
// 	while (win->blocked)
// 		win = ui_get_window_by_id(univers, win->blocked);
// 	data->win_id = win->id;
// }

static inline int	ui_block_event(t_ui_univers **uni, unsigned win_id)
{
	t_ui_win	*win;
	t_ui_win	*blocked;

	if (!(win = ui_get_window_by_id(*uni, win_id)))
		return (0);
	if (win->blocked)
	{
		blocked = ui_get_window_by_id(*uni, win->blocked);
		SDL_RestoreWindow(blocked->sdl_ptr);
		SDL_RaiseWindow(blocked->sdl_ptr);
		return (1);
	}
	return (0);
}

int					ui_wait_event(t_ui_univers **univers)
{
	int				res;
	SDL_Event		eve;
	t_ui_new_event	tmp;
	t_ui_event_data	data;
	t_ui_event		*eve_call;

	if (!univers || !*univers)
		return (0);
	eve_call = NULL;
	if ((res = SDL_PollEvent(&eve)))
	{
		if (ui_generate_event_id(&eve, &tmp.type, &tmp.event, &data))
			return (res);
		if (ui_block_event(univers, data.win_id))
			return (res);
		tmp.win = ui_get_focused_window(*univers);
		if (!tmp.win \
			|| !(eve_call = (t_ui_event *)(rb_search_infix((tmp.win)->events, \
				&(unsigned[2]){tmp.type, tmp.event}, &ui_cmp_event_id))))
			if (!(eve_call = (t_ui_event*)(rb_search_infix((*univers)->events, \
					&(unsigned[2]){tmp.type, tmp.event}, &ui_cmp_event_id))))
				return (res);
		eve_call->callback(univers, eve_call->config, data);
	}
	return (res);
}

void				ui_watch_events(t_ui_univers **univers)
{
	t_ui_univers	*univ;

	if (!univers || !(univ = *univers))
		return ;
	univ->run_event = 1;
	while (univ->run_event)
		while (ui_wait_event(univers))
			continue ;
}

void			ui_stop_watch(t_ui_univers *univers)
{
	univers->run_event = 0;
}
