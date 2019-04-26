/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 13:31:11 by alerandy          #+#    #+#             */
/*   Updated: 2019/04/26 15:23:36 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_PARSER
# define BMP_PARSER

#include "libft.h"

typedef struct	s_ui_bmp {
	short	bfType;
	int		bfSize;
	short	bfReserved1;
	short	bfReserved2;
	int		bfOffBits;
}				t_ui_bmp;

#endif
