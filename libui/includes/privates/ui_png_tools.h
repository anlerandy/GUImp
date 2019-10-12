/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_png_tools.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:33:47 by alerandy          #+#    #+#             */
/*   Updated: 2019/10/12 16:49:26 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_PNG_TOOLS_H
# define UI_PNG_TOOLS_H

# include "ui_png.h"

typedef	struct		s_png_chunk
{
	unsigned int	length;
	unsigned int	type;
	void			*data;
	unsigned int	crc;
}					t_png_chunk;

typedef struct		s_png_funcs
{
	unsigned		type;
	void			(*func)(t_png *png, t_png_chunk chunk);
}					t_png_funcs;

void				read_png(int fd, t_png *png);
void				put_chunk(t_png *png, t_png_chunk chunk);
int					validate_png(t_png *png);

void				png_write_header(t_png *png, t_png_chunk chunk);
void				png_write_data(t_png *png, t_png_chunk chunk);
void				png_write_palette(t_png *png, t_png_chunk chunk);
void				png_write_transparency(t_png *png, t_png_chunk chunk);
void				png_finalise_reading(t_png *png, t_png_chunk chunk);

void				ui_scanline_to_rgb(t_png *png, void *data);

void				png_write_rgba(t_png *png, void *data, int alpha);

#endif
