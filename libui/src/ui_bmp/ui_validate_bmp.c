/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_validate_bmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 16:46:47 by alerandy          #+#    #+#             */
/*   Updated: 2019/05/23 17:11:42 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp_parser.h"

t_bmp	print_parse_error(int error, t_bmp bmp, char *path)
{
	ft_putstr("Error while parsing ");
	ft_putendl(path);
	if (error == 1)
		ft_putendl("The file is not a BMP File.");
	if (error == 2)
		ft_putendl("The file has a wrong size.");
	if (error == 3)
		ft_putendl("The size of the file is incorrect.");
	if (error == 4)
		ft_putendl("Incompatible color depth. Allowed: 1, 16, 24 & 32bit.");
	ft_bzero(&bmp, sizeof(t_bmp));
	return (bmp);
}

int		validate_bmp(t_bmp bmp)
{
	t_bmp_header	header;
	t_bmp_file		info;

	header = bmp.header;
	info = bmp.info;
	if (header.bfType[0] != 'B' || header.bfType[1] != 'M')
		return (1);
	if (info.biSize < 40)
		return (3);
	if (header.bfSize <= 0)
		return (2);
	if (info.biBitCount != 1 && info.biBitCount != 24 && info.biBitCount != 32 \
		&& info.biBitCount != 16 &&  info.biBitCount != 8)
		return (4);
	return (0);
}
