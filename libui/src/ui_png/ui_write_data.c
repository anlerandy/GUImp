/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_write_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 01:34:34 by alerandy          #+#    #+#             */
/*   Updated: 2019/05/10 15:58:43 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui_png_tools.h"

void	write_data(t_png *png, t_png_chunk chunk)
{
	void	*tmp;

	if (!png->raw_data)
	{
		if (!(png->raw_data = ft_memalloc(chunk.length)))
		{
			ft_putendl_fd("Echec d'allocations de memoire.", 2);
			return ;
		}
		ft_memcpy(png->raw_data, chunk.data, chunk.length);
		png->raw_size = chunk.length;
		free(chunk.data);
		chunk.data = NULL;
		return ;
	}
	tmp = png->raw_data;
	if (!(png->raw_data = ft_memalloc(chunk.length + png->raw_size)))
	{
		ft_putendl_fd("Echec d'allocations de memoire.", 2);
		return ;
	}
	ft_memcpy(png->raw_data, tmp, png->raw_size);
	ft_memcpy(png->raw_data + png->raw_size, chunk.data, chunk.length);
	png->raw_size += chunk.length;
	free(chunk.data);
	chunk.data = NULL;
	ft_memdel(&tmp);
}
