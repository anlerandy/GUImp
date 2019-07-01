/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 18:00:11 by alerandy          #+#    #+#             */
/*   Updated: 2019/05/26 21:18:10 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_file_name(char *path)
{
	int		i;

	i = ft_strlen(path);
	while (i > 0 && path[i] != '/')
		--i;
	return (path + i + 1);
}
