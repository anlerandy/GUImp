/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_clear_all_windows.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 19:15:13 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/27 19:22:06 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui_tools.h"

void		ui_clear_all_windows(t_ui_univers *univers)
{
	rb_clear_tree(&(univers->windows), &ui_free_window);
}
