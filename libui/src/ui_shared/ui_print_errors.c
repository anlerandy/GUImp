/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_print_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 18:41:16 by alerandy          #+#    #+#             */
/*   Updated: 2019/07/24 18:45:34 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui_layers.h"

t_ui_layer	ttf_print_error(char *error, const char *detail)
{
	t_ui_layer	layer;

	ft_bzero(&layer, sizeof(t_ui_layer));
	ft_putstr_fd(error, 2);
	if (detail)
		ft_putendl_fd(detail, 2);
	else
		ft_putchar('\n');
	return (layer);
}
