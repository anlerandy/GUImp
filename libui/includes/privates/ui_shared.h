/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_shared.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 18:03:13 by alerandy          #+#    #+#             */
/*   Updated: 2019/07/01 14:36:47 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_SHARED_H
# define UI_SHARED_H

typedef struct		s_bgr
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
}					t_bgr;

typedef struct		s_bgra
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
}					t_bgra;

typedef struct		s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_rgb;

typedef struct		s_argb
{
	unsigned char	a;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_argb;

char				*get_file_name(char *path);
void				close_fd(int fd, char *error);
unsigned			bit24_pixel_to_hex(t_bgr pixel);
unsigned			bit32_pixel_to_hex(t_bgra pixel);
unsigned			png_bit24_pixel_to_hex(t_rgb pixel);
unsigned			png_bit32_pixel_to_hex(t_argb pixel);
t_bgr				hex_to_bit24_pixel(unsigned color);
t_bgra				hex_to_bit32_pixel(unsigned color);

#endif
