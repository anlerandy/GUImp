/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 18:00:11 by alerandy          #+#    #+#             */
/*   Updated: 2019/08/13 17:36:50 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_file_name(char *path)
{
	int		i;
	int		witness;

	if (!(i = ft_strlen(path)))
		return (NULL);
	witness = i;
	while (i > 0 && (path[i] != '/' || witness - i <= 1))
		--i;
	return (path + i + 1);
}
