/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_write_header.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 23:37:19 by alerandy          #+#    #+#             */
/*   Updated: 2019/05/09 06:56:53 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui_png_tools.h"

void	write_header(t_png *png, t_png_chunk chunk)
{
	t_png_header	*header;

	header = &png->header;
	ft_memcpy((void *)header, (const void *)chunk.data, sizeof(t_png_header));
	header->width = swap_integer(header->width);
	header->height = swap_integer(header->height);
	free(chunk.data);
	chunk.data = NULL;
}
