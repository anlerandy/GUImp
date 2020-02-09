/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brackdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 01:02:11 by alerandy          #+#    #+#             */
/*   Updated: 2020/02/09 18:31:53 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_brackdel(t_brack **bracket)
{
	t_brack		*tmp;
	unsigned	i;

	if (!bracket || !(tmp = *bracket))
		return ;
	i = 0;
	if (tmp->type == BRACKET)
		while (i < tmp->size)
			ft_brackdel(&((tmp->data)[i]));
	if (tmp->data)
		ft_memdel((void**)&(tmp->data));
	if (tmp->id)
		ft_strdel(&(tmp->id));
	ft_memdel((void**)bracket);
}