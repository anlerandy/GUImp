/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_shared.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 18:03:13 by alerandy          #+#    #+#             */
/*   Updated: 2019/11/13 14:32:06 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_SHARED_H
# define UI_SHARED_H

# include <stddef.h>

typedef struct s_ui_layer	t_ui_layer;
typedef struct s_vec2		t_pos;

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
unsigned			ui_bgr_to_hex(t_bgr pixel);
unsigned			ui_bgra_to_hex(t_bgra pixel);
unsigned			ui_rgb_to_hex(t_rgb pixel);
unsigned			ui_argb_to_hex(t_argb pixel);
t_bgr				ui_hex_to_bgr(unsigned color);
t_bgra				ui_hex_to_bgra(unsigned color);
t_rgb				ui_hex_to_rgb(unsigned color);
t_argb				ui_hex_to_argb(unsigned color);
t_argb				ui_hex_to_abgr(unsigned color);

t_argb				ui_argb_addition(t_argb a, t_argb b);
t_argb				ui_argb_substract(t_argb a, t_argb b);
t_argb				ui_argb_average(t_argb a, t_argb b);
t_bgra				ui_bgra_addition(t_bgra a, t_bgra b);
t_bgra				ui_bgra_substract(t_bgra a, t_bgra b);

t_pos				get_adaptative_size(unsigned width, unsigned height);

char				*get_file_name(char *path);
void				close_fd(int fd, char *error);
void				convert_color_lines(unsigned *dst, unsigned *src, \
																unsigned width);
unsigned			merge_pixel(unsigned dst, unsigned src);
void				ui_memuset(void *b, unsigned c, size_t len);
t_ui_layer			*ttf_print_error(char *error, const char *detail);
char				*get_previous_path(char *path);

#endif
