/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 18:05:21 by alerandy          #+#    #+#             */
/*   Updated: 2019/06/30 18:25:59 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp_parser.h"
#include "libui.h"
#include "libui_tools.h"
#include "ui_shared.h"
#include "ui_png_tools.h"

t_ui_win	*ui_png_to_window(t_ui_univers *univers, char *path)
{
	t_ui_win		*win;
	t_ui_win_param	param;
	t_png			png;

	png = ui_getpng(path);
	if (!png.pixels)
	{
		ft_putstr("Something went wrong when opening image file: ");
		ft_putendl(path);
		return (NULL);
	}
	param = (t_ui_win_param){0, 0, png.header.width, png.header.height, \
		UI_WINDOW_SHOWN};
	if (!(win = ui_new_window(univers, param, get_file_name(path))))
		return (NULL);
	ft_memcpy(win->surf->pixels, png.pixels, (sizeof(unsigned) \
				* png.pixel_count));
	SDL_UpdateWindowSurface(win->sdl_ptr);
	// ui_delpng(&png);
	return (win);

}

t_ui_win	*ui_bmp_to_window(t_ui_univers *univers, char *path)
{
	t_ui_win		*win;
	t_ui_win_param	param;
	t_bmp			bmp;

	bmp = ui_getbmp(path);
	if (!bmp.pixels)
	{
		ft_putstr("Something went wrong when opening image file: ");
		ft_putendl(path);
		return (NULL);
	}
	param = (t_ui_win_param){0, 0, bmp.info.width, bmp.info.height, \
		UI_WINDOW_SHOWN};
	if (!(win = ui_new_window(univers, param, get_file_name(path))))
		return (NULL);
	ft_memcpy(win->surf->pixels, bmp.pixels, (sizeof(unsigned) \
				* bmp.pixel_count));
	SDL_UpdateWindowSurface(win->sdl_ptr);
	ui_delbmp(&bmp);
	return (win);
}

t_ui_win	*ui_open_image(t_ui_univers *univers, char *path)
{
	int		len;
	char	*file_type;

	len = ft_strlen(path);
	while (len >= 0 && path[len + 1] != '.')
		if (path[len--] == '.')
			file_type = path + len + 2;
	if (!ft_strcmp(file_type, "bmp"))
		return (ui_bmp_to_window(univers, path));
	if (!ft_strcmp(file_type, "png"))
		return (ui_png_to_window(univers, path));
	ft_putstr_fd("Unknown file type. ", 2);
	ft_putendl_fd(file_type, 2);
	return (NULL);
}
