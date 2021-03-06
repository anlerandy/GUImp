/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splash.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 21:36:27 by alerandy          #+#    #+#             */
/*   Updated: 2019/08/12 16:50:33 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp_parser.h"
#include "libui.h"
#include "libui_tools.h"
#include "ui_shared.h"
#include "SDL.h"
#include "ft_btree_rb.h"

int			ui_open_splash(t_ui_univers *univers, char *path, char *name)
{
	t_ui_win		*win;
	t_ui_win_param	param;
	t_bmp			*bmp;
	SDL_DisplayMode	dm;

	if (!(bmp = ui_getbmp(path)) || SDL_GetDesktopDisplayMode(0, &dm))
		return (0);
	name = !name ? get_file_name(path) : name;
	param = (t_ui_win_param){dm.w / 2 - bmp->info.width / 2, \
		dm.h / 2 - bmp->info.height / 2, bmp->info.width, bmp->info.height, \
		UI_WINDOW_SHOWN | UI_WINDOW_BORDERLESS | UI_WINDOW_ALWAYS_ON_TOP};
	if (!(win = ui_new_window(univers, param, name)))
		return (0);
	ft_memcpy(win->surf->pixels, bmp->pixels, (sizeof(unsigned) \
				* bmp->pixel_count));
	SDL_UpdateWindowSurface(win->sdl_ptr);
	ui_wait_event(&univers);
	ui_delbmp(&bmp);
	ui_wait_event(&univers);
	univers->splash = win;
	return (1);
}

void		ui_show_windows(void *void_win)
{
	t_ui_win	*win;
	int			flags;

	win = (t_ui_win*)void_win;
	flags = SDL_GetWindowFlags(win->sdl_ptr);
	if (!(flags & SDL_WINDOW_SHOWN))
		SDL_ShowWindow(win->sdl_ptr);
	SDL_UpdateWindowSurface(win->sdl_ptr);
}

void		ui_close_splash(t_ui_univers *univers)
{
	if (!univers->splash)
		return ;
	ui_del_window(univers, univers->splash->id);
	univers->splash = NULL;
	rb_apply_infix(univers->windows, &ui_show_windows);
}
