/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brackdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 01:02:11 by alerandy          #+#    #+#             */
/*   Updated: 2019/12/14 01:35:57 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_brackdel(t_brack **bracket)
{
	t_brack		*tmp;
	if (!bracket || !(tmp = *bracket))
		return ;
	if (tmp->id)
		ft_strdel(&(tmp->id));
	if (tmp->data)
		ft_memdel((void**)&(tmp->data));
	ft_memdel((void**)bracket);
}