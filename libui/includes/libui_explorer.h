/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui_explorer.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 13:10:19 by alerandy          #+#    #+#             */
/*   Updated: 2019/08/13 13:57:18 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUI_EXPLORER_H
# define LIBUI_EXPLORER_H

typedef struct s_ls_folder	t_ls_folder;
typedef struct s_ui_layer	t_ui_layer;
typedef struct s_ui_win		t_ui_win;
typedef struct s_ui_univers	t_ui_univers;

typedef struct	s_ui_folder
{
	t_ls_folder	*ls;
	t_ui_layer	**layers;
	t_ui_win	*win;
	unsigned	selected;
}				t_ui_folder;

t_ui_folder		*ui_get_folder(char *path, t_ui_win *win);
t_ui_folder		*ui_open_folder(t_ui_univers *univers, char *path, \
									t_ui_win *win);
void			ui_render_folder(t_ui_folder *folder);
void			ui_free_folder(t_ui_folder **folder);
void			ui_close_folder(t_ui_univers **univers, t_ui_folder **folder);

#endif
