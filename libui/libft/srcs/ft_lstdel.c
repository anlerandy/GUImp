/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 13:46:01 by alerandy          #+#    #+#             */
/*   Updated: 2019/04/07 11:04:27 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *ptr;
	if (!*alst)
		return ;
	ptr = (*alst)->next;
	ft_lstdelone(alst, del);
	return ft_lstdel(&ptr, del);
}
