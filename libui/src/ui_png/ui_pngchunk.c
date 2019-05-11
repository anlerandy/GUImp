/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_pngchunk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:32:45 by alerandy          #+#    #+#             */
/*   Updated: 2019/05/11 21:11:46 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui_png_tools.h"

t_png_funcs		*get_functions(void)
{
	t_png_funcs		*array;

	array = ft_memalloc(sizeof(t_png_funcs) * 5);
	array[0] = (t_png_funcs){PNGIHDR, &write_header};
	array[1] = (t_png_funcs){PNGIDAT, &write_data};
	array[2] = (t_png_funcs){PNGPLTE, &write_palette};
	array[3] = (t_png_funcs){PNGTRNS, &write_transparency};
	array[4] = (t_png_funcs){0, &put_chunk};
	return (array);
}

t_png_chunk		get_chunk(int fd)
{
	t_png_chunk		chunk;

	ft_bzero(&chunk, sizeof(t_png_chunk));
	if (!read(fd, &chunk, sizeof(unsigned) * 2))
		return (chunk);
	chunk.length = swap_integer(chunk.length);
	chunk.data = ft_memalloc(chunk.length);
	read(fd, chunk.data, chunk.length);
	read(fd, &chunk.crc, sizeof(unsigned));
	chunk.crc = swap_integer(chunk.crc);
	return (chunk);
}

void			read_png(int fd, t_png *png)
{
	t_png_funcs		*array;
	t_png_chunk		chunk;
	int				i;

	array = get_functions();
	chunk = get_chunk(fd);
	while (chunk.type != PNGIEND)
	{
		i = 0;
		while (array[i].type && array[i].type != chunk.type)
			++i;
		if (array[i].func)
			array[i].func(png, chunk);
		chunk = get_chunk(fd);
	}
	if (chunk.type == PNGIEND)
		finalise_reading(png, chunk);
	free(array);
	array = NULL;
}
