/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 13:31:11 by alerandy          #+#    #+#             */
/*   Updated: 2019/10/06 13:01:02 by alerandy         ###   ########.fr       */
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

typedef struct		s_bmp
{
	t_bmp_header	header;
	t_bmp_file		info;
	void			*palette;
	unsigned		*pixels;
	unsigned		pixel_count;
}					t_bmp;

void				ui_putbmp(t_bmp_header *header, t_bmp_file *bmp);
t_bmp				*ui_getbmp(char *path);
void				ui_delbmp(t_bmp **bmp);

#endif
