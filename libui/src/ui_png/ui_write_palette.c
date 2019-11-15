/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_write_palette.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 13:56:00 by alerandy          #+#    #+#             */
/*   Updated: 2019/07/01 14:33:33 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui_png_tools.h"

void		png_write_transparency(t_png *png, t_png_chunk chunk)
{
	png->opacity = ft_memalloc(chunk.length);
	ft_memcpy(png->opacity, chunk.data, chunk.length);
	free(chunk.data);
	chunk.data = NULL;
}

void		png_write_palette(t_png *png, t_png_chunk chunk)
{
	int		size;

	size = chunk.length / sizeof(t_bgr);
	png->palette = ft_memalloc(size * sizeof(t_bgr));
	ft_memcpy(png->palette, chunk.data, chunk.length);
	free(chunk.data);
	chunk.data = NULL;
}
