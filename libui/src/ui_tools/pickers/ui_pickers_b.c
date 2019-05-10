/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_pickers_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:49:23 by gsmith            #+#    #+#             */
/*   Updated: 2019/05/10 18:17:47 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libui.h"

int					ui_pick_mouse_whee(SDL_Event *eve, unsigned int *id_type, \
							unsigned int *id_event, t_ui_event_data *ev_data)
{
	*id_type = eve->type;
	*id_event = eve->wheel.direction;
	ft_bzero(ev_data, sizeof(t_ui_event_data));
	ev_data->event_id[0] = *id_type;
	ev_data->event_id[1] = *id_event;
	ev_data->timestamp = eve->wheel.timestamp;
	ev_data->win_id = eve->wheel.windowID;
	ev_data->x = eve->wheel.x;
	ev_data->y = eve->wheel.y;
	return (0);
}

int					ui_pick_window(SDL_Event *eve, unsigned int *id_type, \
							unsigned int *id_event, t_ui_event_data *ev_data)
{
	*id_type = eve->type;
	*id_event = eve->window.event;
	ft_bzero(ev_data, sizeof(t_ui_event_data));
	ev_data->event_id[0] = *id_type;
	ev_data->event_id[1] = *id_event;
	ev_data->timestamp = eve->window.timestamp;
	ev_data->win_id = eve->window.windowID;
	ev_data->x = eve->window.data1;
	ev_data->y = eve->window.data2;
	return (0);
}

int					ui_pick_drop(SDL_Event *eve, unsigned int *id_type, \
							unsigned int *id_event, t_ui_event_data *ev_data)
{
	*id_type = eve->type;
	*id_event = 0;
	ft_bzero(ev_data, sizeof(t_ui_event_data));
	ev_data->event_id[0] = *id_type;
	ev_data->event_id[1] = *id_event;
	ev_data->timestamp = eve->drop.timestamp;
	ev_data->path = eve->drop.file;
	ev_data->win_id = eve->drop.windowID;
	return (0);
}
