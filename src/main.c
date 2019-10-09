/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 20:43:32 by alerandy          #+#    #+#             */
/*   Updated: 2019/10/08 22:13:22 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"
#include "libui_explorer.h"
#include "libui_layers.h"
#include "libui_draw.h"

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
	char			*pixel;
	char			*ico;
	char			*image;
	char			*image2;
	char			*image3;
	t_ui_layer		*layer;
	// char			*file;
	t_ui_win		*win;

	(void)ac;
	(void)av;
	if (!(univ = ui_init_univers(env)))
		exit(1);
	pixel = "./assets/test/pixels2.png";
	ico = "./assets/ico.png";
	image = "/home/alerandy/Desktop/FIAP19/02index.png";
	image2 = "/home/alerandy/Desktop/FIAP19/02.png";
	image3 = "/home/alerandy/Desktop/FIAP19/02bit16.png";
	if (!ui_open_splash(univ, "./assets/splash.bmp", "The GUImp"))
		ui_quit_univers(&univ, 1, "Could not retrieve splash. eoe.");
	// win = ui_open_image(univ, pixel);
	// win = ui_open_image(univ, ico);
	// win = ui_open_image(univ, image);
	// win = ui_open_image(univ, image2);
	// win = ui_open_image(univ, image3);
	win = ui_new_window(univ, (t_ui_win_param){150, 120, 800, 800, UI_WINDOW_SHOWN}, "Mon teste");
	ui_rect_in_win(win, (t_ui_draw_param){800, 800, 0, 0, 0x999999ff, 0, 0});
	layer = ui_image_to_layer(ico);
	ui_render_layer(&win, layer);
	ui_free_layer(&layer);
	layer = ui_image_to_layer(image);
	ui_render_layer(&win, layer);
	ui_free_layer(&layer);
	layer = ui_image_to_layer(image2);
	layer->x = 500;
	ui_render_layer(&win, layer);
	// file = ui_path_from_folder(univ, NULL, win);
	// if (file)
	// 	ft_putendl(file);
	// else
	// 	ft_putendl("No Path.");
	ui_close_splash(univ);
	ui_watch_events(&univ);
	ui_quit_univers(&univ, 0, NULL);
}
