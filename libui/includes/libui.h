/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 11:53:34 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/15 14:53:01 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUI_H
# define LIBUI_H

# include "SDL.h"
# include "libft.h"

typedef struct	s_ui_win
{
	int				id;
	char			*title;
	Uint32			options;
	SDL_Surface		*surf;
	SDL_Window		*handle;
}				t_ui_win;

int				ui_init(void);
void			ui_quit(int exit_code);
t_ui_win		*ui_new_window(char *title, int coord[2], int dim[2], \
					Uint32 options);
void			ui_del_window(t_ui_win **win_ptr);

#endif
