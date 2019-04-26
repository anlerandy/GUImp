/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_init_univers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:45:39 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/26 16:08:37 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include "libui.h"
#include "SDL.h"

t_ui_univers	*ui_init(void)
{
	t_ui_univers	*univers;

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
	return (univers);
}
