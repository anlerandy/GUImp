/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_png.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:23:59 by alerandy          #+#    #+#             */
/*   Updated: 2019/05/10 20:34:53 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_PNG_H
# define UI_PNG_H

# include "libui.h"
# include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/* Chunk Types */
# define PNGIHDR 1380206665
# define PNGPLTE 1163152464
# define PNGPHYS 1935231088
# define PNGTIME 1162692980
# define PNGIDAT 1413563465
# define PNGIEND 1145980233
# define PNGICCP 1346585449
# define PNGZTXT 1951945850
# define PNGITXT 1951945833

# define PNGGRAY 0
# define PNGRGB 2
# define PNGINDEX 3
# define PNGGRAYA 4
# define PNGAGRAY 5
# define PNGRGBA 6
# define PNGARGB 7

typedef struct __attribute__((__packed__))	s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}											t_rgb;

typedef struct __attribute__((__packed__))	s_rgba
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}											t_rgba;

typedef struct __attribute__((__packed__))	s_png_header
{
	unsigned		width;
	unsigned		height;
	unsigned char	bit;
	unsigned char	color;
	unsigned char	compression;
	unsigned char	filter;
	unsigned char	interlace;
}											t_png_header;

typedef struct __attribute__((__packed__))	s_png
{
	unsigned char	signature[9];
	t_png_header	header;
	t_rgb			*palette;
	unsigned		*pixels;
	unsigned		pixel_count;
	void			*raw_data;
	unsigned		raw_size;
}											t_png;

t_png										ui_getpng(char *path);
void										ui_putpng(t_png png);

unsigned									bit24_pixel_to_hex(t_rgb pixel);
unsigned									bit32_pixel_to_hex(t_rgba pixel);
unsigned									bit8_pixel_to_hex(t_rgb pixel);

#endif
