/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_shared.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 18:03:13 by alerandy          #+#    #+#             */
/*   Updated: 2019/06/30 18:34:03 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_SHARED_H
# define UI_SHARED_H

typedef struct		s_rgb
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
}					t_rgb;

typedef struct		s_rgba
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
}					t_rgba;

char				*get_file_name(char *path);
void				close_fd(int fd, char *error);
unsigned			bit24_pixel_to_hex(t_rgb pixel);
unsigned			bit32_pixel_to_hex(t_rgba pixel);
t_rgb				hex_to_bit24_pixel(unsigned color);
t_rgba				hex_to_bit32_pixel(unsigned color);

#endif
