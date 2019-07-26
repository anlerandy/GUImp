/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_delbmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 18:20:59 by alerandy          #+#    #+#             */
/*   Updated: 2019/07/26 13:59:26 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp_parser.h"

void	ui_delbmp(t_bmp **bmp)
{
	free((*bmp)->pixels);
	free((*bmp)->palette);
	ft_memdel((void**)bmp);
}
