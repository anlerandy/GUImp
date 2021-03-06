/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_delpng.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 18:49:06 by alerandy          #+#    #+#             */
/*   Updated: 2019/11/13 15:37:26 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui_png.h"

void	ui_delpng(t_png **png)
{
	free((*png)->palette);
	free((*png)->opacity);
	free((*png)->pixels);
	free((*png)->raw_data);
	free(*png);
	*png = NULL;
}
