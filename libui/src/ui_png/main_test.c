/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 13:31:00 by alerandy          #+#    #+#             */
/*   Updated: 2019/06/30 17:56:54 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui_png.h"

int		main(void)
{
	t_png	png;

	png = ui_getpng("/Users/alerandy/Desktop/8bit.png");
	ft_putendl("\n");
	// png = ui_getpng("/home/woap-unix/GUImp/libui/src/ui_png/test/02.png");
	// ft_putendl("\n");
	// png = ui_getpng("/home/woap-unix/GUImp/libui/src/ui_png/test/03.png");
	// ft_putendl("\n");
	// png = ui_getpng("/home/woap-unix/GUImp/libui/src/ui_png/test/04.png");
	// ft_putendl("\n");
	// png = ui_getpng("/home/woap-unix/GUImp/libui/src/ui_png/test/chess.png");
	ft_putendl("\n");
	return (0);
}
