/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 18:05:21 by alerandy          #+#    #+#             */
/*   Updated: 2019/05/26 21:16:42 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp_parser.h"
#include "libui.h"
#include "libui_tools.h"
#include "ui_shared.h"

t_ui_win	*ui_open_image(t_ui_univers *univers, char *path)
{
	t_ui_win		*win;
	t_ui_win_param	param;
	t_bmp			bmp;

	bmp = ui_getbmp(path);
	param = (t_ui_win_param){0, 0, bmp.info.width, bmp.info.height, \
		UI_WINDOW_SHOWN};
	if (!bmp.pixels)
	{
		ft_putstr("Something went wrong when opening image file ");
		ft_putendl(path);
		return (NULL);
	}
	if (!(win = ui_new_window(univers, param, get_file_name(path))))
		return (NULL);
	ft_memcpy(win->surf->pixels, bmp.pixels, (sizeof(unsigned) \
				* bmp.pixel_count));
	SDL_UpdateWindowSurface(win->sdl_ptr);
	ui_delbmp(&bmp);
	return (win);
}
