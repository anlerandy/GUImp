/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:57:45 by gsmith            #+#    #+#             */
/*   Updated: 2019/05/10 17:52:05 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALLBACK_H
# define CALLBACK_H

# include "libui.h"

# define UI_NB_EVENT 12

typedef struct		s_ui_type_picker
{
	unsigned int	sdl_event_type;
	int				(*type_selector)(SDL_Event *eve, unsigned int *id_type, \
							unsigned int *id_event, t_ui_event_data *ev_data);
}					t_ui_type_picker;

int					ui_pick_key(SDL_Event *eve, unsigned int *id_type, \
							unsigned int *id_event, t_ui_event_data *ev_data);
int					ui_pick_mouse_moti(SDL_Event *eve, unsigned int *id_type, \
							unsigned int *id_event, t_ui_event_data *ev_data);
int					ui_pick_mouse_butt(SDL_Event *eve, unsigned int *id_type, \
							unsigned int *id_event, t_ui_event_data *ev_data);
int					ui_pick_mouse_whee(SDL_Event *eve, unsigned int *id_type, \
							unsigned int *id_event, t_ui_event_data *ev_data);
int					ui_pick_window(SDL_Event *eve, unsigned int *id_type, \
							unsigned int *id_event, t_ui_event_data *ev_data);
int					ui_pick_drop(SDL_Event *eve, unsigned int *id_type, \
							unsigned int *id_event, t_ui_event_data *ev_data);
int					ui_pick_quit(SDL_Event *eve, unsigned int *id_type, \
							unsigned int *id_event, t_ui_event_data *ev_data);

#endif
