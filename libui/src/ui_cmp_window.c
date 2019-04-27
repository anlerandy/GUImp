/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_cmp_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 17:15:36 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/26 17:22:16 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int		ui_cmp_window(void *ptr_a, void *ptr_b)
{
	t_ui_win	*win_a;
	t_ui_win	*win_b;

	if (!ptr_a && !ptr_b)
		return (0);
	if (!ptr_a)
		return (-1);
	if (!ptr_b)
		return (1);
	win_a = (t_ui_win *)ptr_a;
	win_b = (t_ui_win *)ptr_b;
	return (win_a->id - win_b->id);
}
