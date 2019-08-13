/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_previous_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 14:07:51 by alerandy          #+#    #+#             */
/*   Updated: 2019/08/13 14:56:36 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui_shared.h"
#include "libft.h"

char	*get_previous_path(char *path)
{
	char	*tmp;
	char	*previous;

	if (!path)
		return (NULL);
	tmp = get_file_name(path);
	previous = ft_strndup(path, ft_strlen(path) - ft_strlen(tmp));
	return (previous);
}
