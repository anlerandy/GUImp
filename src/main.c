/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 20:43:32 by alerandy          #+#    #+#             */
/*   Updated: 2019/12/14 00:47:12 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"
#include "libui_explorer.h"
#include "libui_layers.h"
#include "libui_draw.h"

int		main(int ac, char **av, char **env)
{
	t_ui_univers	*univ;

	(void)ac;
	(void)av;
	if (!(univ = ui_init_univers(env)))
		exit(1);
	if (!ui_open_splash(univ, "./assets/splash.bmp", "The GUImp"))
		ui_quit_univers(&univ, 1, "Could not retrieve splash. eoe.");
	// ui_open_folder(univ, NULL, NULL);
	ui_close_splash(univ);
	char * path = "./test.json";
	ft_bracket(path);
	ui_watch_events(&univ);
	ui_quit_univers(&univ, 0, NULL);
}
