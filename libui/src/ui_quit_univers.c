/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_quit_univers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:09:27 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/13 14:09:23 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libui_tools.h"

/*
** TODO
** 	ui_clear_all_themes(todie);
*/

void	ui_quit_univers(t_ui_univers **univers, int exit_code, char *msg)
{
	t_ui_univers	*todie;

	if (!univers)
		return ;
	todie = *univers;
	ui_clear_events(todie);
	ui_clear_all_windows(todie);
	ft_strdel(&todie->pwd);
	ft_memdel((void**)univers);
	SDL_Quit();
	if (msg)
		ft_putendl_fd(msg, (exit_code > 0 ? STDERR_FILENO : STDOUT_FILENO));
	if (exit_code >= 0)
		exit(exit_code);
}
