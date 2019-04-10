/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_fix_removal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:16:49 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/10 19:27:09 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree_rb.h"

static void		fix_case_4(t_rb_node *node)
{
	t_rb_node	*sibling;

	sibling = rb_brother(node);
	sibling->color = node->parent->color;
	node->parent->color = RB_BLACK;
	if (node == node->parent->left)
	{
		sibling->right->color = RB_BLACK;
		rb_rotation_left(node->parent);
	}
	else
	{
		sibling->left->color = RB_BLACK;
		rb_rotation_right(node->parent);
	}
}

static void		fix_case_3(t_rb_node *node)
{
	t_rb_node	*sibling;

	sibling = rb_brother(node);
	if (sibling->color == RB_BLACK)
	{
		if (node == node->parent->left \
				&& (!(sibling->right) || sibling->right->color == RB_BLACK) \
				&& (sibling->left && sibling->left->color == RB_RED))
		{
			sibling->color = RB_RED;
			sibling->left->color = RB_BLACK;
			rb_rotation_right(sibling);
		}
		else if (node == node->parent->right \
				&& (!(sibling->left) || sibling->left->color == RB_BLACK) \
				&& (sibling->right && sibling->right->color == RB_RED))
		{
			sibling->color = RB_RED;
			sibling->right->color = RB_BLACK;
			rb_rotation_left(sibling);
		}
	}
	fix_case_4(node);
}

static void		fix_case_2(t_rb_node *node)
{
	t_rb_node	*sibling;

	sibling = rb_brother(node);
	if (node->parent->color == RB_RED && sibling->color == RB_BLACK \
			&& (!(sibling->left) || sibling->left->color == RB_BLACK) \
			&& (!(sibling->right) || sibling->right->color == RB_BLACK))
	{
		sibling->color = RB_RED;
		node->parent->color = RB_BLACK;
	}
	else
		fix_case_3(node);
}

static void		fix_case_1(t_rb_node *node)
{
	t_rb_node	*sibling;

	sibling = rb_brother(node);
	if (node->parent->color == RB_BLACK && sibling->color == RB_BLACK \
			&& (!(sibling->left) || sibling->left->color == RB_BLACK) \
			&& (!(sibling->right) || sibling->right->color == RB_BLACK))
	{
		sibling->color = RB_RED;
		rb_fix_removal(node->parent);
	}
	else
		fix_case_2(node);
}

void			rb_fix_removal(t_rb_node *node)
{
	t_rb_node	*sibling;

	if (!node)
		return ;
	sibling = rb_brother(node);
	if (sibling->color != RB_RED)
		return ;
	sibling->color = RB_BLACK;
	sibling->parent->color = RB_RED;
	if (node == node->parent->left)
		rb_rotation_left(node->parent);
	else
		rb_rotation_right(node->parent);
	fix_case_1(node);
}
