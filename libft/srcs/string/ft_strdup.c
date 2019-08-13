/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:58:41 by alerandy          #+#    #+#             */
/*   Updated: 2019/08/13 17:34:04 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	i;

	i = ft_strlen((char*)s1);
	if (!(ptr = (char*)malloc(sizeof(char) * i + 1)))
		return (ptr);
	ft_memcpy(ptr, s1, i + 1);
	return (ptr);
}
