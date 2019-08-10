/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 20:43:32 by alerandy          #+#    #+#             */
/*   Updated: 2019/08/11 01:18:53 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"
#include "libui_explorer.h"
#include "libui_layers.h"

void	pt_event_param(t_ui_event_data event)
{
	ft_putstr("\nCallback: event data\nid_type: ");
	ft_putnbr(event.event_id[0]);
	ft_putstr("\nid_event: ");
	ft_putnbr(event.event_id[1]);
	ft_putstr("\nwindow id: ");
	ft_putnbr(event.win_id);
	ft_putstr("\ntimestamp: ");
	ft_putnbr(event.timestamp);
	ft_putstr("\nstate: ");
	ft_putnbr(event.state);
	ft_putstr("\nkeycode: ");
	ft_putnbr(event.keycode);
	ft_putstr("\nkeymod: ");
	ft_putnbr(event.keymod);
	ft_putstr("\nx: ");
	ft_putnbr(event.x);
	ft_putstr("\ny: ");
	ft_putnbr(event.y);
	ft_putstr("\nxrel: ");
	ft_putnbr(event.xrel);
	ft_putstr("\nyrel: ");
	ft_putnbr(event.yrel);
	ft_putstr("\nclick: ");
	ft_putnbr(event.click);
	ft_putstr("\npath: ");
	ft_putendl(event.path);
	ft_putchar('\n');
}

void	callback_quit(t_ui_univers **uni, void *dummy, t_ui_event_data event)
{
	(void)dummy;
	pt_event_param(event);
	ui_stop_watch(*uni);
	ft_putendl("thanks for all the fish!");
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

void	button(t_ui_univers **uni, t_ui_elem_used *context)
{
	(void)uni;
	(void)context;
	ft_putendl("a button was clicked.");
}

int		main(int ac, char **av, char **env)
{
	t_ui_univers	*univ;
	t_ui_win_param	param[3];
	t_ui_new_elem	el;
	t_ui_win		*wins[3];
	int				flag;
	unsigned int	event_id[2];
	t_ui_layer		*layer;
	char			*image;
	char			*saved_image;
	t_ui_folder		*explorer;

	(void)ac;
	(void)av;
	if (!(univ = ui_init_univers(env)))
		exit(1);
	image = "./assets/test/sample.bmp";
	saved_image = "./assets/test/test.bmp";
	if (!ui_open_splash(univ, "./assets/splash.bmp", "The GUImp"))
		ui_quit_univers(&univ, 1, "Could not retrieve splash. eoe.");

	param[0] = (t_ui_win_param){0, 500, 500, 500, UI_WINDOW_RESIZABLE};
	param[1] = (t_ui_win_param){600, 500, 500, 500, UI_WINDOW_RESIZABLE};
	param[2] = (t_ui_win_param){1200, 500, 500, 500, UI_WINDOW_RESIZABLE};
	el = (t_ui_new_elem){0, 0, 100, 100, UI_ELEM_TYPE_BUTTON, \
		UI_ELEM_STATE_IDLE, "button", NULL, &button};
	flag = -1;
	while (++flag < 3)
	{
		if (!(wins[flag] = ui_new_window(univ, param[flag], "Hello toast")))
			ui_quit_univers(&univ, 1, "Could not retrieve new window. eoe.");
		if (!ui_new_elem(wins[flag], el))
			ui_quit_univers(&univ, 1, "Could not add new elem. eoe.");
	}
	if ((layer = ui_image_to_layer(image)))
		ui_render_layer(&(wins[1]), layer);
	event_id[0] = UI_EVENT_KEYUP;
	event_id[1] = UIK_ESCAPE;
	if (ui_new_event(univ, event_id, &callback_quit, NULL))
		ui_quit_univers(&univ, 1, "Error while setting up event. eoe.");
	event_id[1] = UIK_RETURN;
	if (ui_new_event(univ, event_id, &callback_enter, NULL))
		ui_quit_univers(&univ, 1, "Error while setting up event. eoe.");
	event_id[0] = UI_EVENT_QUIT;
	event_id[1] = 0;
	if (ui_new_event(univ, event_id, &callback_quit, NULL))
		ui_quit_univers(&univ, 1, "Error while setting up event. eoe.");
	event_id[0] = UI_EVENT_WINDOW;
	event_id[1] = UI_WINDOWEVENT_CLOSE;
	if (ui_new_event(univ, event_id, &callback_close, NULL))
		ui_quit_univers(&univ, 1, "Error while setting up event. eoe.");
	// sleep(2); // Test the new system of the Splash.
	explorer = ui_open_folder(univ, NULL, NULL);
	ui_close_splash(univ);
	ui_watch_events(&univ);
	ui_quit_univers(&univ, 0, NULL);
}
