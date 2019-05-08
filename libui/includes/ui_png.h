/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_png.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:23:59 by alerandy          #+#    #+#             */
/*   Updated: 2019/05/08 22:23:21 by alerandy         ###   ########.fr       */
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
# define IHDR 1380206665
// # define PLTE
# define IDAT 1413563465
# define IEND 1145980233
# define ICCP 1346585449
# define ZTXT 1951945850

typedef enum                                e_cformat
{
	GRAY,
    NONE1,
    RGB,
    INDEX,
    GRAYA,
    AGRAY,
    RGBA,
	ARGB
}                                           t_cformat;

typedef struct __attribute__((__packed__))	s_png_header
{
	unsigned	width;
	unsigned	height;
	char		bit;
	char		color;
	char		compression;
	char		filter;
	char		interlace;
}											t_png_header;

typedef struct __attribute__((__packed__))  s_png
{
    unsigned char	signature[9];
	t_png_header	header;
    unsigned		*pixels;
}                                           t_png;

t_png                                       ui_getpng(char *path);
void                                       	ui_putpng(t_png png);
int                                         validate_png(t_png png);

#endif
