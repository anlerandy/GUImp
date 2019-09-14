/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui_elem.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 11:43:25 by gsmith            #+#    #+#             */
/*   Updated: 2019/09/09 18:00:37 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUI_ELEM_H
# define LIBUI_ELEM_H

# include "libui.h"

typedef struct	s_ui_elem
{
	unsigned int	id;
	unsigned int	x;
	unsigned int	y;
	unsigned int	w;
	unsigned int	h;
	unsigned int	type;
	unsigned int	state;
	char			*text;
	void			*value;
	void			(*callback)(t_ui_univers **uni, t_ui_elem_used *context);
}				t_ui_elem;

int				ui_cmp_elem(void *ptr_a, void *ptr_b);
int				ui_cmp_elem_id(void *ptr_elem, void *ptr_id);
int				ui_cmp_elem_type(void *ptr_elem, void *ptr_type);
int				ui_cmp_elem_pos(void *ptr_elem, void *ptr_pos);

void			ui_free_elem(void *elem_ptr);

void			elem_draw_button(t_ui_win *win, t_ui_elem *elem);

#endif
