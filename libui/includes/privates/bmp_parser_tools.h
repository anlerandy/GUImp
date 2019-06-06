/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_parser_tools.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 16:48:19 by alerandy          #+#    #+#             */
/*   Updated: 2019/06/03 14:22:38 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_PARSER_TOOLS_H
# define BMP_PARSER_TOOLS_H

# include "bmp_parser.h"

t_bmp	print_parse_error(int error, t_bmp bmp, char *path);
void	ui_putbmp(t_bmp_header header, t_bmp_file bmp);
int		validate_bmp(t_bmp bmp);

void	fill_pixels_32(unsigned *bmp_pixels, t_bmp_32 *pixels, \
						int width, int height);
void	fill_pixels_24(unsigned *bmp_pixels, t_bmp_24 *pixels, \
						int width, int height);
void	fill_pixels_16(unsigned *bmp_pixels, unsigned short *pixels, \
						int width, int height);
void	fill_pixels_index(t_bmp *bmp, char *pixels, int width, \
						int height);
void	fill_pixels_1(unsigned *bmp_pixels, char *pixels, \
						int width, int height);

#endif
