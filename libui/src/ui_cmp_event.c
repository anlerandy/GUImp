/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_cmp_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 13:45:25 by gsmith            #+#    #+#             */
/*   Updated: 2019/05/06 13:49:55 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int			ui_cmp_event(void *ptr_a, void *ptr_b)
{
	t_ui_event	*eve_a;
	t_ui_event	*eve_b;

	if (!ptr_a && !ptr_b)
		return (0);
	if (!ptr_a)
		return (-1);
	if (!ptr_b)
		return (1);
	eve_a = (t_ui_event *)ptr_a;
	eve_b = (t_ui_event *)ptr_b;
	return (eve_a->id - eve_b->id);
}
