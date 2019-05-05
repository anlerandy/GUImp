/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_get_focused_window.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 18:57:57 by gsmith            #+#    #+#             */
/*   Updated: 2019/05/02 21:05:19 by alerandy         ###   ########.fr       */
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
