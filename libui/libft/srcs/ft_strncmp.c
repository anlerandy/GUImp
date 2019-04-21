/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:04:24 by alerandy          #+#    #+#             */
/*   Updated: 2019/04/21 17:01:49 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	unsigned char	*str1;
	unsigned char	*str2;
	int				len1;
	int				len2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	if (n > (len2 = ft_strlen(s2)) || n > (len1 = ft_strlen(s1)))
		n = len1 < len2 ? len1 : len2;
	i = 0;
	while (((unsigned long int)(str1 + i) & \
			(sizeof(unsigned long int) - 1)) != 0 && \
			((unsigned long int)(str2 + i) & \
			(sizeof(unsigned long int) - 1)) != 0 && \
			--n)
	{
		if (str1[i] != str2[i] || (!str1[i] || !str2[i]))
			return (str1[i] - str2[i]);
		++i;
	}
	return (ft_memcmp((void *)(str1 + i), (void *)(str2 + i), n));
}
