/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui_ttf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:50:22 by alerandy          #+#    #+#             */
/*   Updated: 2019/07/23 16:19:27 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUI_TTF_H
# define LIBUI_TTF_H

# include "libui_layers.h"

typedef struct	s_ui_ttf_param
{
	unsigned	x;
	unsigned	y;
	unsigned	width;
	unsigned	height;
	int			inversed_w;
	int			inversed_h;
	unsigned	color;
}				t_ui_ttf_param;

t_ui_layer		ui_ttf_to_layer(char *path, char *txt, t_ui_ttf_param param);

#endif
