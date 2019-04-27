/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 13:31:00 by alerandy          #+#    #+#             */
/*   Updated: 2019/04/27 13:13:27 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp_parser.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int		main(void)
{
	t_ui_bmp	bmp;
	int			fd;

	if ((fd = open("/home/woap-unix/GUImp/libui/src/ui_bmp/test.bmp", O_RDWR)) == -1)
		ft_putendl("Le fichier n'existe pas.");
	ft_putnbr(fd);
	ft_bzero(&bmp, sizeof(bmp));
	read(fd, &bmp.header, sizeof(bmp.header));
	read(fd, &bmp.bmp, sizeof(bmp.bmp));
	ft_putstr("FD.\nLa structure BMP fait: ");
	ft_putnbr(sizeof(bmp));
	ft_putendl("bytes.");
	ft_putstr("bfType: ");
	ft_putchar(bmp.header.bfType1);
	ft_putchar(bmp.header.bfType2);
	ft_putstr("\nbfSize: ");
	ft_putnbr(bmp.header.bfSize);
	ft_putstr("\nbfOffBits: ");
	ft_putnbr(bmp.header.bfOffBits);
	ft_putstr("\nwidth: ");
	ft_putnbr(bmp.bmp.width);
	ft_putstr("\nheight: ");
	ft_putnbr(bmp.bmp.height);
	ft_putstr("\nUp to: ");
	ft_putnbr(bmp.bmp.biBitCount);
	ft_putendl("bits per pixel.");
	return (0);
}
