/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortarray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 23:44:23 by alerandy          #+#    #+#             */
/*   Updated: 2019/08/11 00:33:00 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sortarray(void **array, int size, int (*cmp)(void *, void *))
{
	int		j;
	int		i;
	void	*tmp;

	if (size <= 0)
		return ;
	i = -1;
	while (++i + 1 < size)
		if (cmp(array[i], array[i + 1]) > 0)
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			j = i + 1;
			while (--j - 1 >= 0 && cmp(array[j - 1], array[j]) > 0)
			{
				tmp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = tmp;
			}
		}
}
