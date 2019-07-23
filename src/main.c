/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 20:43:32 by alerandy          #+#    #+#             */
/*   Updated: 2019/07/23 17:07:51 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

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

int		main()
{
	t_ui_univers	*univ;
	t_ui_win_param	param[4];
	t_ui_new_elem	el[3];
	t_ui_win		*win;
	t_ui_win		*win2;
	t_ui_win		*wins[3];
	int				flag;
	int				flog;
	unsigned int	event_id[2];
	t_ui_win		*splash;
	t_ui_layer		layer;
	t_ui_layer		alpha_layer;
	t_ui_layer		alpha_layer2;
	char			*image;
	char			*saved_image;
	char			*alpha;
	char			*alpha2;
	t_ui_layer		text;
	t_ui_ttf_param	txt_param;

	if (!(univ = ui_init_univers()))
		exit(1);
	image = "/home/woap-unix/Downloads/sample.bmp";
	saved_image = "/home/woap-unix/Downloads/test.bmp";
	alpha2 = "/home/woap-unix/Downloads/alpha2.bmp";
	alpha = "/home/woap-unix/Downloads/alpha.bmp";
	splash = ui_open_splash(univ, "./assets/splash.bmp", "The GUImp");

	ft_bzero(param, sizeof(param));
	param[0] = (t_ui_win_param){0, 500, 500, 500, UI_WINDOW_RESIZABLE};
	param[1] = (t_ui_win_param){600, 500, 500, 500, UI_WINDOW_RESIZABLE};
	param[2] = (t_ui_win_param){1200, 500, 500, 500, UI_WINDOW_RESIZABLE};
	param[3] = (t_ui_win_param){1800, 500, 500, 500, UI_WINDOW_RESIZABLE};
	if (!(win = ui_new_window(univ, param[0], "mother of window")))
		ui_quit_univers(&univ, 1, "Could not retrieve new window. eoe.");
	if (!(win2 = ui_new_daughter_win(univ, "daughter window 1", param[1], 2)))
		ui_quit_univers(&univ, 1, "Could not retrieve new window. eoe.");
	if (!(win = ui_new_daughter_win(univ, "daughter window 2", param[2], 2)))
		ui_quit_univers(&univ, 1, "Could not retrieve new window. eoe.");

	if (!(win = ui_new_blocking_win(univ, "blocking mother", param[3], 2)))
		ui_quit_univers(&univ, 1, "Could not retrieve new window. eoe.");

	param[1] = (t_ui_win_param){500, 500, 500, 500, UI_WINDOW_RESIZABLE};
	param[2] = (t_ui_win_param){1000, 500, 500, 500, UI_WINDOW_RESIZABLE};
	el[0] = (t_ui_new_elem){0, 0, 100, 100, UI_ELEM_TYPE_BUTTON, \
		UI_ELEM_STATE_IDLE, "button", NULL, &button};
	el[1] = (t_ui_new_elem){100, 100, 200, 200, UI_ELEM_TYPE_BUTTON, \
		UI_ELEM_STATE_IDLE, "button", NULL, &button};
	el[2] = (t_ui_new_elem){200, 200, 300, 300, UI_ELEM_TYPE_BUTTON, \
		UI_ELEM_STATE_IDLE, "button", NULL, &button};
	flag = -1;
	while (++flag < 3)
	{
		if (!(wins[flag] = ui_new_window(univ, param[flag], "Hello toast")))
			ui_quit_univers(&univ, 1, "Could not retrieve new window. eoe.");
		flog = -1;
		while (++flog < 3)
			if (!ui_new_elem(wins[flag], el[flag]))
				ui_quit_univers(&univ, 1, "Could not add new elem. eoe.");
	}
	layer = ui_image_to_layer(image);
	alpha_layer = ui_image_to_layer(alpha);
	alpha_layer2 = ui_image_to_layer(alpha2);
	ui_layer_into_layer(&layer, &alpha_layer);
	ui_layer_into_layer(&layer, &alpha_layer2);
	ui_render_layer(&win2, layer);
	ui_layer_to_bmp(layer, saved_image);
	layer.rescale_w = 0.3 * layer.width;
	layer.x = 200;
	layer.y = 200;
	layer.width_inversed = -1;
	ui_render_layer(&(wins[2]), layer);
	layer.rescale_w = 1.2 * layer.width;
	layer.x = 0;
	layer.y = 400;
	layer.width_inversed = 1;
	layer.height_inversed = -1;
	ui_render_layer(&(wins[1]), layer);
	if (!(wins[0] = ui_open_image(univ, saved_image)))
		ui_quit_univers(&univ, 1, "Could not retrieve new window. eoe.");
	txt_param = (t_ui_ttf_param){800, 100, 500, 100, -1, 1, 0x9cff0000};
	text = ui_ttf_to_layer("./assets/8bit.ttf", "Test de texte!", txt_param);
	ui_render_layer(&(wins[0]), text);
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
//	sleep(2); // Test the new system of the Splash.
	ui_close_splash(univ, &splash);
	ui_watch_events(&univ);
	ui_quit_univers(&univ, 0, NULL);
}
