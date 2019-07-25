/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_free_layer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:58:08 by alerandy          #+#    #+#             */
/*   Updated: 2019/07/25 13:46:52 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui_layers.h"

void	ui_free_layer(t_ui_layer *layer)
{
	if (!layer)
		return ;
	ft_memdel((void**)&(layer->pixels));
	ft_bzero(layer, sizeof(t_ui_layer));
}
