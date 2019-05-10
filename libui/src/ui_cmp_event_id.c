/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_cmp_event_id.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 13:52:45 by gsmith            #+#    #+#             */
/*   Updated: 2019/05/10 11:38:32 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int				ui_cmp_event_id(void *ptr_eve, void *ptr_id)
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
