/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 13:31:11 by alerandy          #+#    #+#             */
/*   Updated: 2019/07/26 13:43:37 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_PARSER_H
# define BMP_PARSER_H

# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct		s_bmp_header
{
	unsigned char	type[2];
	unsigned int	size;
	unsigned short	reserved1;
	unsigned short	reserved2;
	unsigned int	offset;
}					t_bmp_header;

typedef struct		s_bmp_file
{
	unsigned int	header_size;
	int				width;
	int				height;
	unsigned short	planes;
	unsigned short	color_depth;
	unsigned int	compression;
	unsigned int	image_size;
	int				width_meter;
	int				height_meter;
	unsigned int	used_color;
	unsigned int	important_color;
}					t_bmp_file;

typedef struct		s_bmp_24
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
}					t_bmp_24;

typedef struct		s_bmp_32
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
}					t_bmp_32;

typedef struct		s_bmp
{
	t_bmp_header	header;
	t_bmp_file		info;
	void			*palette;
	unsigned		*pixels;
	unsigned		pixel_count;
}					t_bmp;

void				ui_putbmp(t_bmp_header *header, t_bmp_file *bmp);
unsigned			bit24_pixel_to_hex(t_bmp_24 pixel);
unsigned			bit32_pixel_to_hex(t_bmp_32 pixel);
t_bmp_24			hex_to_bit24_pixel(unsigned color);
t_bmp_32			hex_to_bit32_pixel(unsigned color);
t_bmp				*ui_getbmp(char *path);
void				ui_delbmp(t_bmp **bmp);

#endif
