/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_pngchunk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:32:45 by alerandy          #+#    #+#             */
/*   Updated: 2019/05/08 22:39:07 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui_png_tools.h"
#include <stdio.h>

void		put_chunktype(unsigned type)
{
	char	*str;

	if (type == IHDR)
		ft_putendl("IHDR");
	else if (type == ZTXT)
		ft_putendl("zTXT");
	else if (type == ICCP)
		ft_putendl("iCCP");
	else if (type == IDAT)
		ft_putendl("IDAT");
	else if (type == IEND)
		ft_putendl("IEND");
	else {
		ft_putstr("Unknown type: ");
		str = (char*)&type;
		ft_putnstr(str, 4);
		ft_putstr(". Integer value= ");
		ft_putnbr(type);
		ft_putchar('\n');
	}
}

void		swap_integer(unsigned *nbr)
{
	unsigned short	nb[4];

	nb[0] = (*nbr >> 0) & 0xFF;
	nb[1] = (*nbr >> 8) & 0xFF;
	nb[2] = (*nbr >> 16) & 0xFF;
	nb[3] = (*nbr >> 24) & 0xFF;
	*nbr = (nb[0] << 24) | (nb[1] << 16) | (nb[2] << 8) | (nb[3] << 0);
}

t_png_chunk	getChunk(int fd, t_png *png)
{
	t_png_chunk		chunk;
	unsigned int	size;

	ft_bzero(&chunk, sizeof(t_png_chunk));
	if (!read(fd, &chunk, sizeof(unsigned) * 2))
		return (chunk);
	swap_integer(&chunk.length);
	put_chunktype(chunk.type);
	chunk.data = ft_memalloc(chunk.length);
	read(fd, chunk.data, chunk.length);
	read(fd, &chunk.crc, sizeof(unsigned));
	return (chunk);
}
