/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_write_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 01:34:34 by alerandy          #+#    #+#             */
/*   Updated: 2019/06/30 21:19:58 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui_png_tools.h"

unsigned char	get_compression(unsigned short compression)
{
	if (compression == 0x78DA)
		return (40);
	if (compression == 0x789C)
		return (30);
	if (compression == 0x785E)
		return (20);
	if (compression == 0x7801)
		return (10);
	if (compression == 0x1F8B)
		return (50);
	return (0);
}

void			png_write_data(t_png *png, t_png_chunk chunk)
{
	void			*tmp;
	unsigned short	cmp;

	if (!png->raw_data)
	{
		cmp = *(unsigned short*)chunk.data;
		cmp = ft_swap_integer(((unsigned)cmp) << 16);
		png->header.compression += get_compression(cmp);
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
