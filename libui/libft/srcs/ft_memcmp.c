/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:14:54 by alerandy          #+#    #+#             */
/*   Updated: 2019/04/11 15:09:33 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned long int	*ptr1;
	unsigned long int	*ptr2;
	unsigned long int	src;
	unsigned long int	dst;
	size_t				len;
	unsigned char		*tmp1;
	unsigned char		*tmp2;

	len = n / 8 + 1;
	n -= (len - 1) * 8;
	ptr1 = (unsigned long int*)s1;
	ptr2 = (unsigned long int*)s2;
	while (--len)
	{
		src = *ptr1++;
		dst = *ptr2++;
		if (src != dst)
		{
			tmp1 = (unsigned char*)(src);
			tmp2 = (unsigned char*)(dst);
			if (*tmp1 != *tmp2)
				return (*tmp1 - *tmp2);
			if (tmp1[1] != tmp2[1])
				return (tmp1[1] - tmp2[1]);
			if (tmp1[2] != tmp2[2])
				return (tmp1[2] - tmp2[2]);
			if (tmp1[3] != tmp2[3])
				return (tmp1[3] - tmp2[3]);
			if (tmp1[4] != tmp2[4])
				return (tmp1[4] - tmp2[4]);
			if (tmp1[5] != tmp2[5])
				return (tmp1[5] - tmp2[5]);
			if (tmp1[6] != tmp2[6])
				return (tmp1[6] - tmp2[6]);
			if (tmp1[7] != tmp2[7])
				return (tmp1[7] - tmp2[7]);
		}
	}
	tmp1 = (unsigned char*)ptr1;
	tmp2 = (unsigned char*)ptr2;
	while (--n && *tmp1 == *tmp2)
	{
		++tmp1;
		++tmp2;
	}
	return (tmp1 - tmp2);
}
