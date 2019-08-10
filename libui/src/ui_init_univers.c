/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_init_univers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:45:39 by gsmith            #+#    #+#             */
/*   Updated: 2019/08/10 15:48:51 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui_error.h"
#include "libft.h"
#include "libui_tools.h"

t_ui_univers	*ui_init_univers(char **env)
{
	t_ui_univers	*univers;
	int				i;

	i = -1;
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
	{
		ft_putendl_fd(ERR_SDL_INIT, STDERR_FILENO);
		return (NULL);
	}
	if (!(univers = ft_memalloc(sizeof(t_ui_univers))))
	{
		SDL_Quit();
		ft_putendl_fd(ERR_MALLOC, STDERR_FILENO);
		return (NULL);
	}
	while(env[++i])
		if (!ft_strcmp(env[i], "PWD="))
			univers->pwd = ft_strdup(env[i] + 4);
	ft_putendl(univers->pwd);
	return (univers);
}
