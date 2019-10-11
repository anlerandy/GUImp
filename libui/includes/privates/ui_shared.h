/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_shared.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 18:03:13 by alerandy          #+#    #+#             */
/*   Updated: 2019/10/11 17:40:52 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_SHARED_H
# define UI_SHARED_H

# include <stddef.h>

typedef struct s_ui_layer	t_ui_layer;

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
t_rgb				png_hex_to_bit24_pixel(unsigned color);
t_argb				png_hex_to_bit32_pixel(unsigned color);

t_argb				ui_argb_addition(t_argb a, t_argb b);
t_argb				ui_argb_substract(t_argb a, t_argb b);
t_argb				ui_argb_average(t_argb a, t_argb b);
t_bgra				ui_bgra_addition(t_bgra a, t_bgra b);
t_bgra				ui_bgra_substract(t_bgra a, t_bgra b);

char				*get_file_name(char *path);
void				close_fd(int fd, char *error);
void				convert_color_lines(unsigned *dst, unsigned *src, \
																unsigned width);
unsigned			merge_pixel(unsigned dst, unsigned src);
void				ui_memuset(void *b, unsigned c, size_t len);
t_ui_layer			*ttf_print_error(char *error, const char *detail);
char				*get_previous_path(char *path);

#endif
