/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:59:17 by alerandy          #+#    #+#             */
/*   Updated: 2020/09/09 20:16:29 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list			*nlst;

	if (!(nlst = ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (content == 0)
	{
		nlst->content = NULL;
		nlst->content_size = 0;
	}
	else
	{
		if (!(nlst->content = ft_memdup((void *)content, content_size)))
		{
			free(nlst);
			return (NULL);
		}
		nlst->content_size = content_size;
	}
	nlst->next = NULL;
	return (nlst);
}
