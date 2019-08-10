/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_free_folder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 16:06:38 by alerandy          #+#    #+#             */
/*   Updated: 2019/08/10 15:48:15 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui_explorer.h"
#include "mini_ls.h"
#include "libft.h"

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
		i = tmp->ls->files_amount;
		while (i >= 0)
			ft_strdel(&(tmp->ls->files[i--]));
		ft_strdel(&(tmp->ls->path));
		i = tmp->ls->files_amount + 1;
		ft_memdel((void**)&tmp->ls);
	}
	tmp->win = NULL;
	while (i > 0)
		ft_memdel((void**)&(tmp->layers[i--]));
	ft_memdel((void**)&tmp->layers);
	ft_memdel((void**)folder);
}
