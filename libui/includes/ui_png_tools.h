/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_png_tools.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:33:47 by alerandy          #+#    #+#             */
/*   Updated: 2019/05/09 02:04:47 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_PNG_TOOLS_H
# define UI_PNG_TOOLS_H

# include "ui_png.h"

typedef	struct __attribute__((__packed__))	s_png_chunk
{
	unsigned int	length;
	unsigned int	type;
	void			*data;
	unsigned int	crc;
}											t_png_chunk;

typedef struct								s_png_funcs
{
	unsigned	type;
	void		(*func)(t_png *png, t_png_chunk chunk);
}											t_png_funcs;


void										read_png(int fd, t_png *png);
void										put_chunk(t_png *png, \
												t_png_chunk chunk);
int                                         validate_png(t_png png);

void										write_header(t_png *png, \
												t_png_chunk chunk);
void										write_data(t_png *png, \
												t_png_chunk chunk);
void										finalise_reading(t_png *png, \
												t_png_chunk chunk);

#endif
