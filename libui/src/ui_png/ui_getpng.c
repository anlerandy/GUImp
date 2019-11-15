/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_getpng.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:23:03 by alerandy          #+#    #+#             */
/*   Updated: 2019/11/15 19:47:08 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui_png.h"
#include "ui_png_tools.h"

t_png		*ui_getpng(char *path)
{
	int				fd;
	t_png			*png;

	if (!(png = ft_memalloc(sizeof(t_png))))
	{
		ft_putendl_fd("getPNG Impossible d'allouer la memoire.", 2);
		return (png);
	}
	if ((fd = open(path, O_RDWR)) == -1)
	{
		ft_memdel((void**)&png);
		ft_putendl_fd("Le fichier n'existe pas.", 2);
		return (png);
	}
	read(fd, png, 8);
	if (!validate_png(png))
	{
		ft_memdel((void**)&png);
		ft_putendl_fd("Ceci n'est pas un fichier PNG.", 2);
		return (png);
	}
	read_png(fd, png);
	close(fd);
	return (png);
}
