/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 11:53:34 by gsmith            #+#    #+#             */
/*   Updated: 2019/06/11 14:49:53 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUI_H
# define LIBUI_H

# include "libft.h"

# define UI_WINDOW_OPENGL              0x00000002
# define UI_WINDOW_SHOWN               0x00000004
# define UI_WINDOW_HIDDEN              0x00000008
# define UI_WINDOW_BORDERLESS          0x00000010
# define UI_WINDOW_RESIZABLE           0x00000020
# define UI_WINDOW_MINIMIZED           0x00000040
# define UI_WINDOW_MAXIMIZED           0x00000080
# define UI_WINDOW_INPUT_GRABBED       0x00000100
# define UI_WINDOW_INPUT_FOCUS         0x00000200
# define UI_WINDOW_MOUSE_FOCUS         0x00000400
# define UI_WINDOW_FULLSCREEN_DESKTOP  0x00001001
# define UI_WINDOW_FOREIGN             0x00000800
# define UI_WINDOW_ALLOW_HIGHDPI       0x00002000
# define UI_WINDOW_MOUSE_CAPTURE       0x00004000
# define UI_WINDOW_ALWAYS_ON_TOP       0x00008000
# define UI_WINDOW_SKIP_TASKBAR        0x00010000
# define UI_WINDOW_UTILITY             0x00020000
# define UI_WINDOW_TOOLTIP             0x00040000
# define UI_WINDOW_POPUP_MENU          0x00080000
# define UI_WINDOW_VULKAN              0x10000000

# define UI_ELEM_TYPE_CANVAS           0
# define UI_ELEM_TYPE_BUTTON           1
# define UI_ELEM_TYPE_INPUT            2
# define UI_ELEM_TYPE_TEXT             3
# define UI_ELEM_TYPE_DROPDOWN         4

# define UI_ELEM_STATE_IDLE            0
# define UI_ELEM_STATE_ACTIVE          1
# define UI_ELEM_STATE_HOVER           2
# define UI_ELEM_STATE_DISABLED        3

# define UI_SUBPART_WINDOW 0
# define UI_SUBPART_ELEM   1

typedef struct s_ui_elem	t_ui_elem;
typedef struct s_ui_theme	t_ui_theme;
typedef struct s_ui_win		t_ui_win;
typedef struct s_ui_univers	t_ui_univers;
typedef struct s_ui_event	t_ui_event;

typedef struct	s_ui_win_param
{
	int				x;
	int				y;
	int				w;
	int				h;
	unsigned int	options;
}				t_ui_win_param;

typedef struct	s_ui_event_data
{
	unsigned int	event_id[2];
	unsigned int	timestamp;
	unsigned int	win_id;
	unsigned int	state;
	unsigned int	keycode;
	unsigned int	keymod;
	int				x;
	int				y;
	int				xrel;
	int				yrel;
	unsigned int	click;
	char			*path;
}				t_ui_event_data;

typedef struct	s_ui_elem_used
{
	unsigned int	elem_id;
	unsigned int	previous_state;
	unsigned int	new_state;
	char			*text;
	void			*value;
	t_ui_event_data	event;
}				t_ui_elem_used;

typedef struct	s_ui_new_elem
{
	t_ui_win		*win_ptr;
	unsigned int	elem_type;
	unsigned int	state;
	char			*text;
	void			*value;
	void			(*callback)(t_ui_univers **uni, t_ui_elem_used *context);
}				t_ui_new_elem;

t_ui_univers	*ui_init_univers(void);
void			ui_quit_univers(t_ui_univers **univers, int exit_code, \
					char *msg);

t_ui_win		*ui_new_window(t_ui_univers *univers, t_ui_win_param param, \
					char *title);
t_ui_win		*ui_get_window_by_id(t_ui_univers *univers, int win_id);
t_ui_win		*ui_get_focused_window(t_ui_univers *univers);
void			ui_del_window(t_ui_univers *univers, int win_id);
void			ui_clear_all_windows(t_ui_univers *univers);

int				ui_new_event(t_ui_univers *univers, unsigned int event_id[2], \
					void (*callback)(t_ui_univers **, void *, \
						t_ui_event_data), void *config_callback);
void			ui_del_event(t_ui_univers *univers, unsigned int event_id[2]);
void			ui_clear_events(t_ui_univers *univers);
void			ui_watch_events(t_ui_univers **univers);
int				ui_wait_event(t_ui_univers **univers);
void			ui_stop_watch(t_ui_univers *univers);

int				ui_new_elem(t_ui_win *win, t_ui_new_elem param);
void			ui_del_elem(t_ui_win *win, unsigned int type, \
					unsigned int id);
void			ui_clear_elems(t_ui_win *win);
t_ui_elem		*ui_get_elem_by_id(t_ui_win *win, unsigned int id);
void			ui_elem_new_state(t_ui_elem *elem, unsigned int new_state);
void			ui_elem_new_text(t_ui_elem *elem, char *new_text);
void			ui_elem_new_value(t_ui_elem *elem, void *new_value);
void			ui_elem_new_callback(t_ui_elem *elem, void (*callback) \
					(t_ui_univers **uni, t_ui_elem_used *context));

t_ui_theme		*ui_new_theme(t_ui_univers *univers, char *file_path);
t_ui_theme		*ui_get_theme_by_id(t_ui_univers *univers, int theme_id);
t_ui_theme		*ui_get_theme_by_win_id(t_ui_univers *univers, int win_id);
int				ui_import_themes(t_ui_univers *univers, char *rep_path);
int				ui_set_default_theme(t_ui_univers *univers, int theme_id);
int				ui_del_theme(t_ui_univers *univers, int theme_id);
int				ui_clear_all_themes(t_ui_univers *univers);

t_ui_win		*ui_open_image(t_ui_univers *univers, char *path);
t_ui_win		*ui_open_splash(t_ui_univers *univers, char *path, char *name);
void			ui_close_splash(t_ui_univers *univers, t_ui_win **win);
void			put_bmpinfo(char *path);

#endif
