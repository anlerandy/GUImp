/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_putpngchunk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 23:33:09 by alerandy          #+#    #+#             */
/*   Updated: 2019/05/08 23:59:22 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui_png_tools.h"

void		put_chunktype(unsigned type)
{
	char	*str;

	if (type == PNGIHDR)
		ft_putendl("IHDR");
	else if (type == PNGZTXT)
		ft_putendl("zTXT");
	else if (type == PNGICCP)
		ft_putendl("iCCP");
	else if (type == PNGIDAT)
		ft_putendl("IDAT");
	else if (type == PNGIEND)
		ft_putendl("IEND");
	else if (type == PNGPHYS)
		ft_putendl("pHYS");
	else if (type == PNGTIME)
		ft_putendl("tIME");
	else {
		ft_putstr("Unknown type: ");
		str = (char*)&type;
		ft_putnstr(str, 4);
		ft_putstr(". Integer value= ");
		ft_putnbr(type);
		ft_putchar('\n');
	}
}

void	put_chunk(t_png *png, t_png_chunk chunk)
{
	(void)png;
	ft_putstr("Ignored chunk: ");
	put_chunktype(chunk.type);
}
