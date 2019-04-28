/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 13:31:11 by alerandy          #+#    #+#             */
/*   Updated: 2019/04/28 04:18:05 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_PARSER
# define BMP_PARSER

#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct __attribute__((__packed__))	s_bmp_header {
	unsigned char	bfType[2];
	unsigned int	bfSize;
	unsigned short	bfReserved1;
	unsigned short	bfReserved2;
	unsigned int	bfOffBits;
}											t_bmp_header;

typedef struct __attribute__((__packed__))	s_bmp_file {
	unsigned int	biSize;
	int				width;
	int				height;
	unsigned short	biPlanes;
	unsigned short	biBitCount;
	unsigned int	biCompression;
	unsigned int	biSizeImage;
	int				biXPelsPerMeter;
	int				biYPelsPerMeter;
	unsigned int	biClrUsed;
	unsigned int	biClrImportant;
}											t_bmp_file;

typedef struct __attribute__((__packed__))	s_bmp {
	t_bmp_header	header;
	t_bmp_file		info;
	unsigned		*pixels;
	unsigned		pixel_count;
}											t_bmp;

typedef struct __attribute__((__packed__))	s_bmp_24 {
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}											t_bmp_24;

void		ui_putbmp(t_bmp_header header, t_bmp_file bmp);
unsigned	bit24_pixel_to_hex(t_bmp_24 pixel);
t_bmp		ui_getbmp(char *path);

#endif
