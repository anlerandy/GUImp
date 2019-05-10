/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_write_palette.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 13:56:00 by alerandy          #+#    #+#             */
/*   Updated: 2019/05/10 15:51:05 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui_png_tools.h"

void		write_palette(t_png *png, t_png_chunk chunk)
{
	int		size;

	size = chunk.length / sizeof(t_rgb);
	png->palette = ft_memalloc(size * sizeof(t_rgb));
	ft_memcpy(png->palette, chunk.data, chunk.length);
	free(chunk.data);
	chunk.data = NULL;
}
