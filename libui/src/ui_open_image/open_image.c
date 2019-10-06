/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 18:05:21 by alerandy          #+#    #+#             */
/*   Updated: 2019/10/06 12:57:58 by alerandy         ###   ########.fr       */
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

	ft_bzero(&png, sizeof(png));
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
	ui_delpng(&png);
	return (win);
}

t_ui_win	*ui_bmp_to_window(t_ui_univers *univers, char *path)
{
	t_ui_win		*win;
	t_ui_win_param	param;
	t_bmp			*bmp;

	if (!(bmp = ui_getbmp(path)))
	{
		ft_putstr("Something went wrong when opening image file: ");
		ft_putendl(path);
		return (NULL);
	}
	param = (t_ui_win_param){0, 0, bmp->info.width, bmp->info.height, \
		UI_WINDOW_SHOWN};
	if (!(win = ui_new_window(univers, param, get_file_name(path))))
		return (NULL);
	ft_memcpy(win->surf->pixels, bmp->pixels, (sizeof(unsigned) \
				* bmp->pixel_count));
	SDL_UpdateWindowSurface(win->sdl_ptr);
	ui_delbmp(&bmp);
	return (win);
}

t_ui_win	*ui_open_image(t_ui_univers *univers, char *path)
{
	int		len;
	char	*file_type;

	len = ft_strlen(path);
	if ((file_type = ft_strrchr(path, '.')))
	{
		if (!ft_strncmp(file_type + 1, "bmp", 3))
			return (ui_bmp_to_window(univers, path));
		if (!ft_strncmp(file_type + 1, "png", 3))
			return (ui_png_to_window(univers, path));
	}
	ft_putstr_fd("Unknown file type. ", 2);
	ft_putendl_fd(file_type ? file_type + 1 : path, 2);
	return (NULL);
}
