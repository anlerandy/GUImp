/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_cmp_event_id.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 13:52:45 by gsmith            #+#    #+#             */
/*   Updated: 2019/05/06 14:11:23 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int				ui_cmp_event_id(void *ptr_eve, void *ptr_id)
{
	unsigned int	id;
	t_ui_event		*eve;

	if (!ptr_eve && !ptr_id)
		return (0);
	if (!ptr_eve)
		return (-1);
	if (!ptr_id)
		return (1);
	eve = (t_ui_event *)ptr_eve;
	id = *(int *)ptr_id;
	return (eve->id - id);
}
