/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_get_focused_window.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 18:57:57 by gsmith            #+#    #+#             */
/*   Updated: 2019/05/02 18:51:43 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui_tools.h"

t_ui_win		*ui_get_focused_window(t_ui_univers *univers)
{
	return (rb_search_infix(univers->windows, (void *)SDL_WINDOW_INPUT_FOCUS, \
			&ui_cmp_window_flag));
}
