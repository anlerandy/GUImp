/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_cmp_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 13:45:25 by gsmith            #+#    #+#             */
/*   Updated: 2019/05/10 19:44:42 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui_tools.h"

int			ui_cmp_event_id(void *ptr_eve, void *ptr_id)
{
	unsigned int	*id_eve;
	unsigned int	*id_ref;

	if (!ptr_eve && !ptr_id)
		return (0);
	if (!ptr_eve)
		return (-1);
	if (!ptr_id)
		return (1);
	id_eve = ((t_ui_event *)ptr_eve)->id;
	id_ref = (unsigned int *)ptr_id;
	if (id_eve[0] == id_ref[0])
		return (id_eve[1] - id_ref[1]);
	return (id_eve[0] - id_ref[0]);
}

int			ui_cmp_event(void *ptr_a, void *ptr_b)
{
	unsigned int	*id_a;
	unsigned int	*id_b;

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
