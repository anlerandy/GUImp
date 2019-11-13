/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_folder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 00:21:01 by alerandy          #+#    #+#             */
/*   Updated: 2019/11/13 17:02:39 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_ls.h"
#include "libft.h"

void					ft_free_folder(t_ls_folder **folder)
{
	int		i;

	i = -1;
	while ((*folder)->files[++i])
		ft_strdel(&((*folder)->files[i]));
	ft_memdel((void**)&(*folder)->files);
	ft_strdel(&((*folder)->path));
	ft_memdel((void**)folder);
}
