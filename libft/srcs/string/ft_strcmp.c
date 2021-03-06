/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:55:54 by alerandy          #+#    #+#             */
/*   Updated: 2019/08/10 23:34:24 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*str1;
	unsigned char	*str2;
	int				n;

	str1 = (unsigned char *)ft_strdup(s1);
	str2 = (unsigned char *)ft_strdup(s2);
	n = ft_strlen(s1);
	i = ft_strlen(s2);
	n = n > i ? i : n;
	i = 0;
	while (((long int)(str1 + i) & (sizeof(long int) - 1)) != 0 && \
			((long int)(str2 + i) & (sizeof(long int) - 1)) != 0 && --n)
	{
		if (str1[i] != str2[i] || (!str1[i] || !str2[i]))
			return (str1[i] - str2[i]);
		++i;
	}
	i = ft_memcmp((void *)(str1 + i), (void *)(str2 + i), n);
	ft_strdel((char**)&str1);
	ft_strdel((char**)&str2);
	return (i);
}
