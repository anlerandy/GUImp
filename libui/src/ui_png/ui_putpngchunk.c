/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_putpngchunk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 23:33:09 by alerandy          #+#    #+#             */
/*   Updated: 2019/05/10 15:53:28 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui_png_tools.h"

void	put_chunktype(unsigned type)
{
	ft_putnstr((char*)&type, 4);
	ft_putstr(" ID: ");
	ft_putnbr(type);
	ft_putstr("");
}

void	put_chunk(t_png *png, t_png_chunk chunk)
{
	(void)png;
	ft_putstr("Ignored chunk: ");
	put_chunktype(chunk.type);
	ft_putstr(" \033[32m(");
	ft_putnbr(chunk.length);
	ft_putstr(" octects)\033[0m\n");
	free(chunk.data);
	chunk.data = NULL;
}
