/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 11:53:26 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/15 14:54:00 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"
#include "error.h"

int		ui_init(void)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
	{
		ft_putendl_fd(ERR_SDL_INIT, STDERR_FILENO);
		return (0);
	}
	return (1);
}
