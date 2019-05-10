/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_get_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 10:09:20 by gsmith            #+#    #+#             */
/*   Updated: 2019/05/10 19:09:09 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui_tools.h"

t_ui_win		*ui_get_focused_window(t_ui_univers *univers)
{
	int		flag;

	flag = SDL_WINDOW_INPUT_FOCUS;
	return (rb_search_infix(univers->windows, (void *)&flag, \
			&ui_cmp_window_flag));
}

t_ui_win	*ui_get_window_by_id(t_ui_univers *univers, int win_id)
{
	void	*search_res;

	if (!univers)
		return (NULL);
	search_res = rb_search_infix(univers->windows, (void *)&win_id, \
			&ui_cmp_window_id);
	if (!search_res)
		return (NULL);
	return ((t_ui_win *)search_res);
}
