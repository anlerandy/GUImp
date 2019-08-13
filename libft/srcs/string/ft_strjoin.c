/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 19:51:59 by alerandy          #+#    #+#             */
/*   Updated: 2019/08/13 17:34:28 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		size1;
	size_t		size2;
	char		*ptr;

	i = 0;
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	if (!(ptr = ft_memalloc(sizeof(char) * (size1 + size2 + 1))))
		return (NULL);
	ft_strcpy(ptr, s1);
	ft_strcpy(ptr + size1, s2);
	return (ptr);
}
