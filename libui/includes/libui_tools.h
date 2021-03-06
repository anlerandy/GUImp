/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui_tools.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 15:27:55 by gsmith            #+#    #+#             */
/*   Updated: 2019/08/14 13:32:10 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUI_TOOLS_H
# define LIBUI_TOOLS_H

# include "libui.h"
# include "libui_elem.h"
# include "ft_btree_rb.h"
# include "SDL.h"

typedef struct	s_ui_theme
{
	unsigned int	id;
}				t_ui_theme;

typedef struct	s_ui_win
{
	unsigned int	id;
	unsigned int	id_next_elem;
	SDL_Surface		*surf;
	SDL_Window		*sdl_ptr;
	t_rb_node		*elements;
	t_ui_theme		*theme;
	t_rb_node		*events;
	unsigned int	mother;
	unsigned int	blocked;
}				t_ui_win;

typedef struct	s_ui_univers
{
	t_rb_node		*windows;
	t_rb_node		*themes;
	t_ui_theme		*default_theme;
	t_rb_node		*events;
	t_ui_win		*splash;
	char			*pwd;
	unsigned int	run_event;
}				t_ui_univers;

typedef struct	s_ui_event
{
	unsigned int	id[2];
	void			(*callback)(t_ui_univers **, void *, t_ui_event_data);
	void			*config;
}				t_ui_event;

int				ui_cmp_window(void *ptr_a, void *ptr_b);
int				ui_cmp_window_id(void *ptr_win, void *ptr_id);
int				ui_cmp_window_flag(void *ptr_win, void *ptr_flag);
int				ui_cmp_mother(void *ptr_win, void *ptr_mother_id);
int				ui_cmp_blocker(void *ptr_win, void *ptr_blocker_id);
void			ui_block_daughter(t_ui_univers *univers, unsigned int mother, \
									unsigned int blocker);

int				ui_cmp_event(void *ptr_a, void *ptr_b);
int				ui_cmp_event_id(void *ptr_eve, void *ptr_id);

void			ui_free_window(void *win_ptr);
void			ui_free_event(void *ptr_eve);

int				ui_generate_event_id(SDL_Event *eve, unsigned int *id_type, \
						unsigned int *id_event, t_ui_event_data *ev_data);

#endif
