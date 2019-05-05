/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_cmp_window_id.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 15:17:50 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/27 15:31:53 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int		ui_cmp_window_id(void *ptr_win, void *ptr_id)
{
	int			id;
	t_ui_win	*win;

	if (!ptr_win && !ptr_id)
		return (0);
	if (!ptr_win)
		return (-1);
	if (!ptr_id)
		return (1);
	win = (t_ui_win *)ptr_win;
	id = *(int *)ptr_id;
	return (win->id - id);
}
