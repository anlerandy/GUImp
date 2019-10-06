/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_free_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 15:14:31 by gsmith            #+#    #+#             */
/*   Updated: 2019/06/13 11:29:40 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui_elem.h"

void			ui_free_elem(void *elem_ptr)
{
	t_ui_elem	*elem;

	elem = (t_ui_elem *)elem_ptr;
	ft_strdel(&elem->text);
	ft_memdel(&elem_ptr);
}
