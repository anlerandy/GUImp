/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 13:31:00 by alerandy          #+#    #+#             */
/*   Updated: 2019/06/30 21:11:56 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui_png.h"

int		main(void)
{
	t_png	png;

	png = ui_getpng("/Users/alerandy/Desktop/8bit.png");
	ft_putendl("\n");
	return (0);
}
