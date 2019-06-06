/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui_elem.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 11:43:25 by gsmith            #+#    #+#             */
/*   Updated: 2019/06/06 11:31:43 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUI_ELEM_H
# define LIBUI_ELEM_H

# include "libui.h"

typedef struct	s_ui_elem
{
	unsigned int	id;
	unsigned int	type;
	unsigned int	state;
	char			*text;
	void			*value;
	void			(*callback)(t_ui_univers **uni, t_ui_elem_used *context);
}				t_ui_elem;

int				ui_cmp_elem(void *ptr_a, void *ptr_b);
int				ui_cmp_elem_id(void *ptr_win, void *ptr_id);
int				ui_cmp_elem_type(void *ptr_win, void *ptr_type);

void			ui_free_elem(void *elem_ptr);

#endif
