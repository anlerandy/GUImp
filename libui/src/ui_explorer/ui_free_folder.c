/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_free_folder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 16:06:38 by alerandy          #+#    #+#             */
/*   Updated: 2019/09/14 12:58:10 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui_explorer.h"
#include "mini_ls.h"
#include "libft.h"
#include "libui.h"

void	ui_free_folder(t_ui_folder **folder)
{
	t_ui_folder	*tmp;
	int			i;

	if (!folder || !*folder)
		return ;
	tmp = *folder;
	i = 0;
	if (tmp->ls)
	{
		i = tmp->ls->files_amount + 1;
		ft_free_folder(&tmp->ls);
		ft_memdel((void**)&tmp->ls);
	}
	tmp->win = NULL;
	while (i >= 0)
		ft_memdel((void**)&(tmp->layers[i--]));
	ft_memdel((void**)&(tmp->layers));
	ft_memdel((void**)&(tmp->background));
	ft_memdel((void**)folder);
}

void	ui_close_folder(t_ui_univers **univers, t_ui_folder **folder)
{
	t_ui_win	*win;

	win = (*folder)->win;
	if (win)
		ui_del_window(*univers, ui_get_window_id(win));
	ui_free_folder(folder);
}
