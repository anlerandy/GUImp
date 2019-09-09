/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_init_univers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:45:39 by gsmith            #+#    #+#             */
/*   Updated: 2019/09/09 14:08:11 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui_error.h"
#include "libft.h"
#include "libui_tools.h"
#include "libui_events.h"
#include "event_default.h"

static inline void	set_default_event(t_ui_univers *univers)
{
	t_ui_new_event	eve_param;

	eve_param = (t_ui_new_event){UI_EVENT_KEYUP, UIK_ESCAPE, NULL};
	if (ui_new_event(univers, eve_param, &callback_quit, NULL))
		ui_quit_univers(&univers, 1, "Error while setting up event. eoe.");
	eve_param.type = UI_EVENT_QUIT;
	eve_param.event = 0;
	if (ui_new_event(univers, eve_param, &callback_quit, NULL))
		ui_quit_univers(&univers, 1, "Error while setting up event. eoe.");
	eve_param.type = UI_EVENT_WINDOW;
	eve_param.event = UI_WINDOWEVENT_CLOSE;
	if (ui_new_event(univers, eve_param, &callback_close, NULL))
		ui_quit_univers(&univers, 1, "Error while setting up event. eoe.");
	eve_param.type = UI_EVENT_MOUSEBUTTONDOWN;
	eve_param.event = UIM_BUTTON_LEFT;
	if (ui_new_event(univers, eve_param, &callback_click, NULL))
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
