/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 20:43:32 by alerandy          #+#    #+#             */
/*   Updated: 2019/09/09 14:08:42 by alerandy         ###   ########.fr       */
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

void __attribute__((destructor)) end(void)
{
	ft_putendl("Quitting.\nplease check leaks.\nQuit with CTRL + C when done.");
	while (1)
		sleep(200);
}

void	print_text(t_ui_univers **uni, t_ui_elem_used *context)
{
	(void)uni;
	ft_putendl(context->text);
}

int		main(int ac, char **av, char **env)
{
	t_ui_univers	*univ;
	char			*image;
	char			*saved_image;
	t_ui_win		*win;

	(void)ac;
	(void)av;
	if (!(univ = ui_init_univers(env)))
		exit(1);
	image = "./assets/test/sample.bmp";
	saved_image = "./assets/test/test.bmp";
	if (!ui_open_splash(univ, "./assets/splash.bmp", "The GUImp"))
		ui_quit_univers(&univ, 1, "Could not retrieve splash. eoe.");
	win = ui_new_window(univ, (t_ui_win_param){500, 500, 1000, 1000, 0}, NULL);
	if (!(ui_new_elem(win, (t_ui_new_elem){0, 0, 500, 200, 1, 0, "Test", NULL, &print_text})))
		ft_putendl("Failed to create element.");
	ui_close_splash(univ);
	ui_watch_events(&univ);
	ui_quit_univers(&univ, 0, NULL);
}
