/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_getpng.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:23:03 by alerandy          #+#    #+#             */
/*   Updated: 2019/05/08 22:22:36 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui_png.h"
#include "ui_png_tools.h"

t_png		ui_getpng(char *path)
{
	int				fd;
	t_png			png;
	t_png_chunk		looper;

	ft_bzero(&png, sizeof(png));
	if ((fd = open(path, O_RDWR)) == -1)
	{
		ft_putendl_fd("Le fichier n'existe pas.", 2);
		return (png);
	}
	read(fd, &png, 8);
	if (!validate_png(png))
	{
		ft_putendl_fd("Ceci n'est pas un fichier PNG.", 2);
		return (png);
	}
	ui_putpng(png);
	looper = getChunk(fd, &png);
	free(looper.data);
	while (looper.crc)
	{
		looper = getChunk(fd, &png);
		free(looper.data);
	}
	close(fd);
	return (png);
}
