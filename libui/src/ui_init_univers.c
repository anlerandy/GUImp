/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_init_univers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:45:39 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/15 11:18:06 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui_error.h"
#include "libft.h"
#include "libui_tools.h"
#include "libui_events.h"

void				callback_quit(t_ui_univers **uni, void *dummy, \
									t_ui_event_data event)
{
	(void)dummy;
	(void)event;
	ui_stop_watch(*uni);
	ft_putendl("Thanks for all the fish!");
}

void				callback_close(t_ui_univers **uni, void *dummy, \
										t_ui_event_data event)
{
	(void)dummy;
	ui_del_window(*uni, event.win_id);
	ft_putendl("Closed a window.");
}

static inline void	set_default_event(t_ui_univers *univers)
{
	t_ui_new_event	eve_param;

	eve_param = (t_ui_new_event){UI_EVENT_KEYUP, UIK_ESCAPE, NULL};
	if (ui_new_event(univers, eve_param, &callback_close, NULL))
		ui_quit_univers(&univers, 1, "Error while setting up event. eoe.");
	eve_param.type = UI_EVENT_QUIT;
	eve_param.event = 0;
	if (ui_new_event(univers, eve_param, &callback_quit, NULL))
		ui_quit_univers(&univers, 1, "Error while setting up event. eoe.");
	eve_param.type = UI_EVENT_WINDOW;
	eve_param.event = UI_WINDOWEVENT_CLOSE;
	if (ui_new_event(univers, eve_param, &callback_close, NULL))
		ui_quit_univers(&univers, 1, "Error while setting up event. eoe.");
}

t_ui_univers		*ui_init_univers(char **env)
{
	t_ui_univers	*univers;
	int				i;

	i = -1;
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
	{
		ft_putendl_fd(ERR_SDL_INIT, STDERR_FILENO);
		return (NULL);
	}
	if (!(univers = ft_memalloc(sizeof(t_ui_univers))))
	{
		SDL_Quit();
		ft_putendl_fd(ERR_MALLOC, STDERR_FILENO);
		return (NULL);
	}
	while (env && env[++i])
		if (!ft_strcmp(env[i], "PWD="))
			univers->pwd = ft_strdup(env[i] + 4);
	set_default_event(univers);
	return (univers);
}
