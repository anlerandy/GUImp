/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 11:53:34 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/27 15:28:45 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUI_H
# define LIBUI_H

# include "ft_btree_rb.h"
# include "SDL.h"

typedef struct	s_ui_win_param
{
	int				coord[2];
	int				dim[2];
	Uint32			options;
}				t_ui_win_param;

typedef struct	s_ui_input
{
	int				id;
}				t_ui_input;

typedef struct	s_ui_theme
{
	int				id;
}				t_ui_theme;

typedef struct	s_ui_win
{
	int				id;
	SDL_Surface		*surf;
	SDL_Window		*sdl_ptr;
	t_rb_node		*elem;
	t_ui_theme		*theme;
}				t_ui_win;

typedef struct	s_ui_univers
{
	t_rb_node		*windows;
	t_rb_node		*themes;
	t_ui_theme		*default_theme;
	t_rb_node		*input_callback;
	long			input_flag;
}				t_ui_univers;

t_ui_univers	*ui_init_univers(void);
void			ui_quit_univers(t_ui_univers **univers, int exit_code, \
					char *msg);

t_ui_win		*ui_new_window(t_ui_univers *univers, t_ui_win_param param, \
					char *title);
t_ui_win		*ui_get_window_by_id(t_ui_univers *univers, int win_id);
t_ui_win		*ui_get_focused_window(t_ui_univers *univers);
void			ui_del_window(t_ui_univers *univers, int win_id);
int				ui_clear_all_windows(t_ui_univers *univers);

t_ui_theme		*ui_new_theme(t_ui_univers *univers, char *file_path);
t_ui_theme		*ui_get_theme_by_id(t_ui_univers *univers, int theme_id);
t_ui_theme		*ui_get_theme_by_win_id(t_ui_univers *univers, int win_id);
int				ui_import_themes(t_ui_univers *univers, char *rep_path);
int				ui_set_default_theme(t_ui_univers *univers, int theme_id);
int				ui_del_theme(t_ui_univers *univers, int theme_id);
int				ui_clear_all_themes(t_ui_univers *univers);

#endif
