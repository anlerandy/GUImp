/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_folder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 11:35:10 by alerandy          #+#    #+#             */
/*   Updated: 2019/07/25 13:56:21 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_ls.h"
#include "libft.h"

static inline int		count_file(char *path)
{
	_DIRENT			*fold;
	int				i;
	DIR				*dir;

	dir = NULL;
	fold = NULL;
	i = 0;
	if (!path || !(dir = opendir(path)))
		return (0);
	while ((fold = readdir(dir)))
		++i;
	closedir(dir);
	return (i);
}

void					ft_free_folder(t_ls_folder **folder)
{
	int		i;

	i = -1;
	while ((*folder)->files[++i])
		ft_strdel(&((*folder)->files[i]));
	ft_memdel((void**)&(*folder)->files);
	ft_memdel((void**)folder);
}

void					ft_refresh_folder(t_ls_folder **folder)
{
	char	*path;

	if (!folder || !*folder)
		return ;
	path = ft_strdup((*folder)->path);
	ft_free_folder(folder);
	*folder = ft_get_folder(path);
	ft_strdel(&path);
}

t_ls_folder				*ft_get_folder(char *path)
{
	int				i;
	DIR				*dir;
	_DIRENT			*fold;
	t_ls_folder		*folder;

	folder = NULL;
	if (!path || !(folder = ft_memalloc(sizeof(t_ls_folder))))
		return (folder);
	i = 0;
	folder->files_amount = count_file(path);
	if (!folder->files_amount || !(dir = opendir(path)))
	{
		ft_putendl_fd("This folder doesn't exist, or need authorisation", 2);
		return (folder);
	}
	if (!(folder->files = ft_memalloc(sizeof(char*) \
			* (folder->files_amount + 1))))
		return (folder);
	while ((fold = readdir(dir)))
		(folder->files)[i++] = ft_strdup(fold->d_name);
	closedir(dir);
	return (folder);
}
