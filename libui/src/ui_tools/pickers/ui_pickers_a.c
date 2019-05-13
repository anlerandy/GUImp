/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_pickers_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:47:50 by gsmith            #+#    #+#             */
/*   Updated: 2019/05/13 16:11:25 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libui_events.h"
#include "libui_tools.h"

int					ui_pick_key(SDL_Event *eve, unsigned int *id_type, \
							unsigned int *id_event, t_ui_event_data *ev_data)
{
	*id_type = eve->type;
	*id_event = eve->key.keysym.sym;
	ft_bzero(ev_data, sizeof(t_ui_event_data));
	ev_data->event_id[0] = *id_type;
	ev_data->event_id[1] = *id_event;
	ev_data->timestamp = eve->key.timestamp;
	ev_data->win_id = eve->key.windowID;
	ev_data->state = eve->key.state;
	ev_data->keycode = eve->key.keysym.sym;
	ev_data->keymod = eve->key.keysym.mod;
	return (0);
}

int					ui_pick_mouse_moti(SDL_Event *eve, unsigned int *id_type, \
							unsigned int *id_event, t_ui_event_data *ev_data)
{
	*id_type = eve->type;
	*id_event = UIM_MOTION;
	ft_bzero(ev_data, sizeof(t_ui_event_data));
	ev_data->event_id[0] = *id_type;
	ev_data->event_id[1] = *id_event;
	ev_data->timestamp = eve->motion.timestamp;
	ev_data->win_id = eve->motion.windowID;
	ev_data->state = eve->motion.state;
	ev_data->x = eve->motion.x;
	ev_data->y = eve->motion.y;
	ev_data->xrel = eve->motion.xrel;
	ev_data->yrel = eve->motion.yrel;
	return (0);
}

int					ui_pick_mouse_butt(SDL_Event *eve, unsigned int *id_type, \
							unsigned int *id_event, t_ui_event_data *ev_data)
{
	*id_type = eve->type;
	*id_event = eve->button.button;
	ft_bzero(ev_data, sizeof(t_ui_event_data));
	ev_data->event_id[0] = *id_type;
	ev_data->event_id[1] = *id_event;
	ev_data->timestamp = eve->button.timestamp;
	ev_data->win_id = eve->button.windowID;
	ev_data->state = eve->button.state;
	ev_data->x = eve->button.x;
	ev_data->y = eve->button.y;
	ev_data->click = eve->button.clicks;
	return (0);
}

int					ui_pick_quit(SDL_Event *eve, unsigned int *id_type, \
							unsigned int *id_event, t_ui_event_data *ev_data)
{
	*id_type = eve->type;
	*id_event = UIQ_QUIT_EVENT;
	ft_bzero(ev_data, sizeof(t_ui_event_data));
	ev_data->event_id[0] = *id_type;
	ev_data->event_id[1] = *id_event;
	ev_data->timestamp = eve->quit.timestamp;
	return (0);
}
