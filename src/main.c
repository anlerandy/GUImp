/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 20:43:32 by alerandy          #+#    #+#             */
/*   Updated: 2019/05/10 18:24:02 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	pt_event_param(t_ui_event_data event)
{
	ft_putendl("\nCallback: event data");
	ft_putstr("id_type: ");
	ft_putnbr(event.event_id[0]);
	ft_putchar('\n');
	ft_putstr("id_event: ");
	ft_putnbr(event.event_id[1]);
	ft_putchar('\n');
	ft_putstr("window id: ");
	ft_putnbr(event.win_id);
	ft_putchar('\n');
	ft_putstr("timestamp: ");
	ft_putnbr(event.timestamp);
	ft_putchar('\n');
	ft_putstr("state: ");
	ft_putnbr(event.state);
	ft_putchar('\n');
	ft_putstr("keycode: ");
	ft_putnbr(event.keycode);
	ft_putchar('\n');
	ft_putstr("keymod: ");
	ft_putnbr(event.keymod);
	ft_putchar('\n');
	ft_putstr("x: ");
	ft_putnbr(event.x);
	ft_putchar('\n');
	ft_putstr("y: ");
	ft_putnbr(event.y);
	ft_putchar('\n');
	ft_putstr("xrel: ");
	ft_putnbr(event.xrel);
	ft_putchar('\n');
	ft_putstr("yrel: ");
	ft_putnbr(event.yrel);
	ft_putchar('\n');
	ft_putstr("click: ");
	ft_putnbr(event.click);
	ft_putchar('\n');
	ft_putstr("path: ");
	ft_putstr(event.path);
	ft_putchar('\n');
}

void	callback_quit(t_ui_univers **uni, void *dummy, t_ui_event_data event)
{
	(void)dummy;
	pt_event_param(event);
	ui_quit_univers(uni, 0, "thanks for the fish !");
}

void	callback_close(t_ui_univers **uni, void *dummy, t_ui_event_data event)
{
	(void)dummy;
	pt_event_param(event);
	ui_del_window(*uni, event.win_id);
	ft_putendl("Closed a window.");
}

void	callback_enter(t_ui_univers **uni, void *dummy, t_ui_event_data event)
{
	(void)dummy;
	(void)uni;
	pt_event_param(event);
}

int		main()
{
	t_ui_univers	*univ;
	t_ui_win_param	param[3];
	t_ui_win		*win;
	t_ui_win		*old;
	int				flag;
	unsigned int	event_id[2];

	param[0].coord[0] = 0;
	param[0].coord[1] = 500;
	param[0].dim[0] = 500;
	param[0].dim[1] = 500;
	param[0].options = SDL_WINDOW_RESIZABLE;
	param[1].coord[0] = 500;
	param[1].coord[1] = 500;
	param[1].dim[0] = 500;
	param[1].dim[1] = 500;
	param[2].options = SDL_WINDOW_RESIZABLE;
	param[2].coord[0] = 1000;
	param[2].coord[1] = 500;
	param[2].dim[0] = 500;
	param[2].dim[1] = 500;
	param[2].options = SDL_WINDOW_RESIZABLE;
	if (!(univ = ui_init_univers()))
		exit(1);
	flag = -1;
	while (++flag < 3)
	{
		if (!(win = ui_new_window(univ, param[flag], "Hello toast")))
			ui_quit_univers(&univ, 1, "Could not retrieve new window. eoe.");
	}
	event_id[0] = SDL_KEYUP;
	event_id[1] = SDLK_ESCAPE;
	if (ui_new_event(univ, event_id, &callback_quit, NULL))
		ui_quit_univers(&univ, 1, "Error while setting up event. eoe.");
	event_id[1] = SDLK_RETURN;
	if (ui_new_event(univ, event_id, &callback_enter, NULL))
		ui_quit_univers(&univ, 1, "Error while setting up event. eoe.");
	event_id[0] = SDL_QUIT;
	event_id[1] = 0;
	if (ui_new_event(univ, event_id, &callback_quit, NULL))
		ui_quit_univers(&univ, 1, "Error while setting up event. eoe.");
	event_id[0] = SDL_WINDOWEVENT;
	event_id[1] = SDL_WINDOWEVENT_CLOSE;
	if (ui_new_event(univ, event_id, &callback_close, NULL))
		ui_quit_univers(&univ, 1, "Error while setting up event. eoe.");
	flag = -1;
	old = ui_get_focused_window(univ);
	while(1)
	{
		ui_watch_events(&univ);
	}
}
