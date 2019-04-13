/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_fix_black_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:38:25 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/13 21:48:59 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_btree_rb.h"

static int			sibling_intern(t_rb_node **root, t_rb_node *sibling[2], \
						t_rb_node *brother, t_rb_node *father)
{
	int		res;

	res = 0;
	if (brother == father->right \
			&& sibling[0] && sibling[0]->color == RB_BLACK \
			&& sibling[1] && sibling[1]->color == RB_RED)
	{
		rb_rotation_right(root, brother);
		sibling[1]->color = RB_BLACK;
		rb_rotation_left(root, father);
		res = 1;
	}
	else if (brother == father->left \
				&& sibling[1] && sibling[1]->color == RB_BLACK \
				&& sibling[0] && sibling[0]->color == RB_RED)
	{
		rb_rotation_left(root, brother);
		sibling[0]->color = RB_BLACK;
		rb_rotation_right(root, father);
		res = 1;
	}
	return (res);
}

static int			sibling_extern(t_rb_node **root, t_rb_node *sibling[2], \
						t_rb_node *brother, t_rb_node *father)
{
	int		res;

	res = 0;
	if (brother == father->right && sibling[0] && sibling[0]->color == RB_RED)
	{
		rb_rotation_left(root, father);
		brother->color = father->color;
		father->color = RB_BLACK;
		sibling[0]->color = RB_BLACK;
		res = 1;
	}
	else if (brother == father->left && sibling[1] \
				&& sibling[1]->color == RB_RED)
	{
		rb_rotation_right(root, father);
		brother->color = father->color;
		father->color = RB_BLACK;
		sibling[1]->color = RB_BLACK;
		res = 1;
	}
	return (res);
}

static void			fix_black_brother(t_rb_node **root, t_rb_node *old_node, \
						t_rb_node *brother)
{
	t_rb_node	*father;
	t_rb_node	*siblings[2];

	father = brother->parent;
	siblings[0] = brother->right;
	siblings[1] = brother->left;
	if (sibling_extern(root, siblings, brother, father))
		return ;
	if (sibling_intern(root, siblings, brother, father))
		return ;
	brother->color = RB_RED;
	if (father->color == RB_RED)
	{
		father->color = RB_BLACK;
		return ;
	}
	rb_fix_black_node(root, father);
}

void				rb_fix_black_node(t_rb_node **root, t_rb_node *old_node)
{
	t_rb_node	*father;
	t_rb_node	*brother;

	if (!(father = old_node->parent))
		return ;
	if ((brother = rb_brother(old_node)) && brother->color == RB_RED)
	{
		if (brother == father->left)
			rb_rotation_left(root, father);
		else
			rb_rotation_right(root, father);
		father->color = RB_RED;
		brother->color = RB_BLACK;
		brother = rb_brother(old_node);
	}
	if (!(brother && brother->color == RB_BLACK))
		return ;
	fix_black_brother(root, old_node, brother);
}
