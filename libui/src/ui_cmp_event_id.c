/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_cmp_event_id.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 13:52:45 by gsmith            #+#    #+#             */
/*   Updated: 2019/05/07 18:21:20 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int				ui_cmp_event_id(void *ptr_eve, void *ptr_id)
{
	unsigned int	id_eve[2];
	unsigned int	id_ref[2];

	if (!ptr_eve && !ptr_id)
		return (0);
	if (!ptr_eve)
		return (-1);
	if (!ptr_id)
		return (1);
	id_eve = ((t_ui_event *)ptr_eve)->id;
	id_ref = (int [2])ptr_id;
	if (id_eve[0] == id_ref[0])
		return (id_eve[1] - id_ref[1]);
	return (id_eve[0] - id_ref[0]);
}
