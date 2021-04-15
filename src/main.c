/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 20:43:32 by alerandy          #+#    #+#             */
/*   Updated: 2021/04/16 04:35:04 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"
#include "libui_explorer.h"
#include "libui_layers.h"
#include "libui_draw.h"

void __attribute__((destructor))	end(void)
{
	int		i;

	i = 3;
	ft_putendl("Quitting.\nPlease check leaks.\nQuit with CTRL + C when done.");
	while (i)
	{
		ft_putstr("\r\033[KAutomatically closing in ");
		ft_putnbr(i--);
		ft_putstr("sec.");
		sleep(1);
	}
	ft_putendl("\r\033[K");
}

void	print_text(t_ui_univers **uni, t_ui_elem_used *context)
{
	(void)uni;
	ft_putendl(context->text);
}

int		main(int ac, char **av, char **env)
{
	t_ui_univers	*univ;
	t_ui_win		*win;

	(void)ac;
	(void)av;
	if (!(univ = ui_init_univers(env)))
		exit(1);
	if (!ui_open_splash(univ, "./assets/splash.bmp", "The GUImp"))
		ui_quit_univers(&univ, 1, "Could not retrieve splash. eoe.");
	win = ui_new_window(univ, (t_ui_win_param){500, 500, 1000, 1000, 0}, NULL);
	if (!(ui_new_elem(win, (t_ui_new_elem){125, 300, 200, 100, 1, \
							UI_ELEM_STATE_ACTIVE, "Test", NULL, &print_text})))
		ft_putendl("Failed to create element.");
	ui_close_splash(univ);
	ui_watch_events(&univ);
	ui_quit_univers(&univ, 0, NULL);
}
