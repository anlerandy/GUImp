/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_duplicate_layer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 10:54:49 by alerandy          #+#    #+#             */
/*   Updated: 2019/11/15 11:00:42 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui_layers.h"
#include "libft.h"

t_ui_layer		*ui_duplicate_layer(t_ui_layer *src)
{
	t_ui_layer	*dst;

	if(!(dst = ft_memdup(src, sizeof(t_ui_layer))))
		return (NULL);
	if (!(dst->pixels = ft_memdup(src->pixels, sizeof(unsigned) \
												* (src->width * src->height))))
	{
		ft_memdel((void **)&dst);
		return (NULL);
	}
	return (dst);
}