/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_write_pixels.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 02:01:37 by alerandy          #+#    #+#             */
/*   Updated: 2019/05/09 02:03:44 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui_png_tools.h"

void		finalise_reading(t_png *png, t_png_chunk chunk)
{
	ft_memdel(&chunk.data);
	ft_putstr("Size of all IDAT Chunks: ");
	ft_putnbr(png->raw_size);
	ft_putchar('\n');
}
