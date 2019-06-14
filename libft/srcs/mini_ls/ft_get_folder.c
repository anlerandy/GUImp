/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_folder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 11:35:10 by alerandy          #+#    #+#             */
/*   Updated: 2019/06/14 10:40:58 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_ls.h"

char	**ft_get_folder(char *path)
{
	DIR		*dir;
	_DIRENT	*fold;
	int		count;
	int		i;
	char	**files;

	i = 0;
	files = NULL;
	fold = NULL;
	dir = NULL;
}