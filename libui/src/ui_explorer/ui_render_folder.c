/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_render_folder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 16:45:05 by alerandy          #+#    #+#             */
/*   Updated: 2019/07/25 19:32:58 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"
#include "libui_tools.h"
#include "libui_explorer.h"
#include "ui_shared.h"
#include "mini_ls.h"
#include "libui_layers.h"

void	ui_render_folder(t_ui_folder *folder)
{
	unsigned	pixels;
	int			i;

	i = -1;
	if (!folder || !folder->win || !folder->layers || !folder->ls)
		return ;
	pixels = folder->win->surf->w * folder->win->surf->h;
	// ui_memuset(folder->win->surf, 0xff01003b, pixels);
	// ui_memuset(folder->win->surf, 0xff001aff, folder->win->surf->w * 50 \
	// 											* sizeof(unsigned));
	while (++i < folder->ls->files_amount + 1)
		ui_render_layer(&folder->win, folder->layers[i]);
}