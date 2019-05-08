/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_png_tools.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:33:47 by alerandy          #+#    #+#             */
/*   Updated: 2019/05/08 18:20:31 by alerandy         ###   ########.fr       */
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

t_png_chunk									getChunk(int fd, t_png *png);

#endif
