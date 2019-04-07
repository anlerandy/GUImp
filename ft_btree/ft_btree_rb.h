/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_rb.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 13:30:40 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/07 13:37:21 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_RB_H
# define FT_BTREE_RB_H

typedef enum	e_rb_color
{
	RB_BLACK,
	RB_RED
}				t_rb_color;

typedef struct	s_rb_node
{
	struct s_rb_node	*parent;
	struct s_rb_node	*left;
	struct s_rb_node	*right;
	void				*data;
	t_rb_color			color;
}				t_rb_node;

void			rb_insert(t_rb_node **root, void *data, \
					int (*cmpf)(void *, void *));
void			rb_remove(t_rb_node **root, void *data, \
					int (*cmpf)(void *, void *), void (*freef)(void *));

#endif
