/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:01:05 by alerandy          #+#    #+#             */
/*   Updated: 2020/09/09 20:08:23 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*ptrs;
	unsigned char	*ptrd;

	if (!dst || !src) return NULL;
	ptrs = ((unsigned char*)src);
	ptrd = ((unsigned char*)dst);
	i = 0;
	if (ptrd < ptrs || ptrd == ptrs)
		while (i < len)
		{
			ptrd[i] = ptrs[i];
			i++;
		}
	else
		while (len > 0)
		{
			ptrd[len - 1] = ptrs[len - 1];
			len--;
		}
	return (dst);
}
