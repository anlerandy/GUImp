/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 20:43:32 by alerandy          #+#    #+#             */
/*   Updated: 2019/08/11 16:01:11 by alerandy         ###   ########.fr       */
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

void	button(t_ui_univers **uni, t_ui_elem_used *context)
{
	(void)uni;
	(void)context;
	ft_putendl("a button was clicked.");
}

int		main(int ac, char **av, char **env)
{
	t_ui_univers	*univ;
	t_ui_win_param	param;
	t_ui_new_elem	el;
	t_ui_win		*win;
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

	param = (t_ui_win_param){0, 500, 500, 500, UI_WINDOW_RESIZABLE};
	explorer = ui_open_folder(univ, NULL, NULL);
	win = ui_new_blocking_win(univ, "The Blocker", param, \
							ui_get_window_id(explorer->win));
	el = (t_ui_new_elem){0, 0, 100, 100, UI_ELEM_TYPE_BUTTON, \
		UI_ELEM_STATE_IDLE, "button", NULL, &button};
	if (!ui_new_elem(win, el))
		ui_quit_univers(&univ, 1, "Could not add new elem. eoe.");
	if ((layer = ui_image_to_layer(image)))
		ui_render_layer(&(win), layer);
	ui_open_image(univ, saved_image);
	ui_close_splash(univ);
	ui_watch_events(&univ);
	ui_quit_univers(&univ, 0, NULL);
}
