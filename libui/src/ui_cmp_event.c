/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_cmp_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 13:45:25 by gsmith            #+#    #+#             */
/*   Updated: 2019/05/07 18:04:02 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int			ui_cmp_event(void *ptr_a, void *ptr_b)
{
	unsigned int	id_a[2];
	unsigned int	id_b[2];

	if (!ptr_a && !ptr_b)
		return (0);
	if (!ptr_a)
		return (-1);
	if (!ptr_b)
		return (1);
	id_a = ((t_ui_event *)ptr_a)->id;
	id_b = ((t_ui_event *)ptr_b)->id;
	if (id_a[0] == id_b[0])
		return (id_a[1] - id_b[1]);
	return (id_a[0] - id_b[0]);
}
