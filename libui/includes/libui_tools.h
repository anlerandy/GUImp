/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui_tools.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 15:27:55 by gsmith            #+#    #+#             */
/*   Updated: 2019/05/10 15:40:20 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUI_TOOLS_H
# define LIBUI_TOOLS_H

# include "libui.h"

int				ui_cmp_window(void *ptr_a, void *ptr_b);
int				ui_cmp_window_id(void *ptr_win, void *ptr_id);
int				ui_cmp_window_flag(void *ptr_win, void *ptr_flag);

int				ui_cmp_event(void *ptr_a, void *ptr_b);
int				ui_cmp_event_id(void *ptr_eve, void *ptr_id);

void			ui_free_elem(void *elem_ptr);
void			ui_free_window(void *win_ptr);
void			ui_free_event(void *ptr_eve);

int				ui_generate_event_id(SDL_Event *eve, unsigned int *id_type, \
						unsigned int *id_event, t_ui_event_data *ev_data);

#endif
