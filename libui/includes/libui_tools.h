/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui_tools.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 15:27:55 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/27 15:42:23 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUI_TOOLS_H
# define LIBUI_TOOLS_H

# include "libui.h"

int				ui_cmp_window(void *ptr_a, void *ptr_b);
int				ui_cmp_window_id(void *ptr_win, void *ptr_id);

void			ui_free_elem(void *elem_ptr);
void			ui_free_window(void *win_ptr);

#endif
