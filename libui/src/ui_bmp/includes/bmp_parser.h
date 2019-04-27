/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 13:31:11 by alerandy          #+#    #+#             */
/*   Updated: 2019/04/27 13:18:53 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_PARSER
# define BMP_PARSER

#include "libft.h"

typedef struct __attribute__((__packed__))	s_bmp_file {
	unsigned char	bfType1;
	unsigned char	bfType2;
	unsigned int	bfSize;
	unsigned short	bfReserved1;
	unsigned short	bfReserved2;
	unsigned int	bfOffBits;
}											t_bmp_file;

typedef struct __attribute__((__packed__))	s_bmp_image {
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
}											t_bmp_image;



typedef struct								s_ui_bmp {
	t_bmp_file	header;
	t_bmp_image	bmp;
}											t_ui_bmp;

#endif
