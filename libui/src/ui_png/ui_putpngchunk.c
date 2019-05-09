/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_putpngchunk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 23:33:09 by alerandy          #+#    #+#             */
/*   Updated: 2019/05/09 02:25:48 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui_png_tools.h"

void		put_chunktype(unsigned type)
{
	char	*str;

	if (type == PNGIHDR)
		ft_putstr("IHDR");
	else if (type == PNGZTXT)
		ft_putstr("zTXT");
	else if (type == PNGICCP)
		ft_putstr("iCCP");
	else if (type == PNGIDAT)
		ft_putstr("IDAT");
	else if (type == PNGIEND)
		ft_putstr("IEND");
	else if (type == PNGPHYS)
		ft_putstr("pHYS");
	else if (type == PNGTIME)
		ft_putstr("tIME");
	else {
		ft_putstr("Unknown type: ");
		str = (char*)&type;
		ft_putnstr(str, 4);
		ft_putstr(". Integer value= ");
		ft_putnbr(type);
	}
}

void	put_chunk(t_png *png, t_png_chunk chunk)
{
	(void)png;
	ft_putstr("Ignored chunk: ");
	put_chunktype(chunk.type);
	ft_putstr(" \033[32m(");
	ft_putnbr(chunk.length);
	ft_putstr(" octects)\033[0m\n");
	ft_memdel(&chunk.data);
}
