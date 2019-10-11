/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_validatepng.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 19:18:53 by alerandy          #+#    #+#             */
/*   Updated: 2019/10/11 23:52:52 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui_png.h"

int		validate_signature(unsigned char *signature)
{
	return (signature[0] == 137 \
	&& signature[1] == 'P' \
	&& signature[2] == 'N' \
	&& signature[3] == 'G' \
	&& signature[4] == 13 \
	&& signature[5] == 10 \
	&& signature[6] == 26 \
	&& signature[7] == 10);
}

int		validate_png(t_png *png)
{
	return (validate_signature(png->signature));
}
