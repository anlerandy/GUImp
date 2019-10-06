/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_ls.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:22:11 by alerandy          #+#    #+#             */
/*   Updated: 2019/07/25 13:49:12 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_LS_H
# define MINI_LS_H

# include <dirent.h>
# include <sys/types.h>
# include <sys/dir.h>
# include <sys/stat.h>

# define _DIRENT struct dirent

typedef struct	s_ls_folder
{
	char	*path;
	char	**files;
	int		files_amount;
}				t_ls_folder;

t_ls_folder		*ft_get_folder(char *path);
void			ft_free_folder(t_ls_folder **folder);
void			ft_refresh_folder(t_ls_folder **folder);

#endif
