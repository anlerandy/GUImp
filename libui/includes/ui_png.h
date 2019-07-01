/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_png.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:23:59 by alerandy          #+#    #+#             */
/*   Updated: 2019/07/01 14:33:33 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_PNG_H
# define UI_PNG_H

# include "libui.h"
# include "libft.h"
# include "ui_shared.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define PNGIHDR 1380206665
# define PNGPLTE 1163152464
# define PNGPHYS 1935231088
# define PNGTIME 1162692980
# define PNGIDAT 1413563465
# define PNGIEND 1145980233
# define PNGICCP 1346585449
# define PNGZTXT 1951945850
# define PNGITXT 1951945833
# define PNGTRNS 1397641844

# define PNGGRAY 0
# define PNGRGB 2
# define PNGINDEX 3
# define PNGGRAYA 4
# define PNGAGRAY 5
# define PNGRGBA 6
# define PNGARGB 7

typedef struct			s_png_header
{
	unsigned		width;
	unsigned		height;
	unsigned char	bit;
	unsigned char	color;
	unsigned char	compression;
	unsigned char	filter;
	unsigned char	interlace;
}						t_png_header;

typedef struct			s_png
{
	unsigned char	signature[9];
	t_png_header	header;
	t_bgr			*palette;
	unsigned char	*opacity;
	unsigned		*pixels;
	unsigned		pixel_count;
	void			*raw_data;
	unsigned		raw_size;
}						t_png;

t_png					ui_getpng(char *path);
void					ui_delpng(t_png *png);
void					ui_putpng(t_png png);

#endif
