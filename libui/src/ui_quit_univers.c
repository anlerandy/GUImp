/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_quit_univers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:09:27 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/26 16:54:43 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libui.h"

void	ui_quit_univers(t_ui_univers **univers, int exit_code, char *msg)
{
	t_ui_univers	*todie;

	if (!univers)
		return ;
	todie = *univers;
/*
** TODO
** 	ui_clear_all_event(todie);
*/
	ui_clear_all_windows(todie);
	ui_clear_all_themes(todie);
	ft_memdel((void**)univers);
	if (msg)
		ft_putendl_fd(msg, (exit_code > 0 ? STDERR_FILENO : STDOUT_FILENO));
	if (exit_code >= 0)
		exit(exit_code);
}
