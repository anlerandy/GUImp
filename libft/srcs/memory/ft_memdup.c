/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 17:18:23 by alerandy          #+#    #+#             */
/*   Updated: 2019/07/23 18:04:05 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(void *src, size_t size)
{
	void	*dst;

	if (!(dst = ft_memalloc(size)))
		return (NULL);
	ft_memcpy(dst, src, size);
	return (dst);
}
