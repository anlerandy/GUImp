/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_generate_event_id.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:39:07 by gsmith            #+#    #+#             */
/*   Updated: 2019/05/10 17:52:06 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "callback.h"

static void		ui_gen_picker(t_ui_type_picker *picker)
{
	picker[0] = (t_ui_type_picker){SDL_KEYDOWN, &ui_pick_key};
	picker[1] = (t_ui_type_picker){SDL_KEYUP, &ui_pick_key};
	picker[2] = (t_ui_type_picker){SDL_MOUSEMOTION, &ui_pick_mouse_moti};
	picker[3] = (t_ui_type_picker){SDL_MOUSEBUTTONDOWN, &ui_pick_mouse_butt};
	picker[4] = (t_ui_type_picker){SDL_MOUSEBUTTONUP, &ui_pick_mouse_butt};
	picker[5] = (t_ui_type_picker){SDL_MOUSEWHEEL, &ui_pick_mouse_whee};
	picker[6] = (t_ui_type_picker){SDL_WINDOWEVENT, &ui_pick_window};
	picker[7] = (t_ui_type_picker){SDL_DROPFILE, &ui_pick_drop};
	picker[8] = (t_ui_type_picker){SDL_DROPTEXT, &ui_pick_drop};
	picker[9] = (t_ui_type_picker){SDL_DROPBEGIN, &ui_pick_drop};
	picker[10] = (t_ui_type_picker){SDL_DROPCOMPLETE, &ui_pick_drop};
	picker[11] = (t_ui_type_picker){SDL_QUIT, &ui_pick_quit};
}

int				ui_generate_event_id(SDL_Event *eve, unsigned int *id_type, \
						unsigned int *id_event, t_ui_event_data *ev_data)
{
	static t_ui_type_picker	picker[UI_NB_EVENT] = {(t_ui_type_picker){0, NULL}};
	int						i;

	if (picker[0].type_selector == 0)
		ui_gen_picker(picker);
	i = -1;
	while (++i < UI_NB_EVENT)
	{
		if (eve->type == picker[i].sdl_event_type)
			return (picker[i].type_selector(eve, id_type, id_event, ev_data));
	}
	return (1);
}
