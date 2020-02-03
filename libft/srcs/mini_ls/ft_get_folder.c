/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_folder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 11:35:10 by alerandy          #+#    #+#             */
/*   Updated: 2020/02/03 13:35:43 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_ls.h"
#include "libft.h"

static inline int		count_file(char *path)
{
	struct dirent	*fold;
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

static inline int		voidcmp(void *s1, void *s2)
{
	int				i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (!str1 || !str2)
		return (-1);
	i = 0;
	while (!(str1[i] ^ str2[i]))
		if (str1[i++] == '\0')
			return (0);
	return (str1[i] - str2[i]);
}

static inline void		fill_folder(t_ls_folder *folder, DIR *dir, char *path)
{
	struct dirent	*fold;
	int				i;

	i = 0;
	folder->path = path[ft_strlen(path) - 1] != '/' \
					? ft_strjoin(path, "/") : ft_strdup(path);
	while ((fold = readdir(dir)))
		(folder->files)[i++] = ft_strdup(fold->d_name);
	ft_sortarray((void**)folder->files, folder->files_amount, &voidcmp);
	closedir(dir);
}

t_ls_folder				*ft_get_folder(char *path)
{
	DIR				*dir;
	t_ls_folder		*folder;

	folder = NULL;
	if (!path || !(folder = ft_memalloc(sizeof(t_ls_folder))))
		return (folder);
	folder->files_amount = count_file(path);
	if (!folder->files_amount || !(dir = opendir(path)))
	{
		ft_memdel((void**)&folder);
		return (folder);
	}
	if (!(folder->files = ft_memalloc(sizeof(char**) \
			* (folder->files_amount + 1))))
	{
		closedir(dir);
		ft_memdel((void**)&folder);
		return (folder);
	}
	fill_folder(folder, dir, path);
	return (folder);
}
