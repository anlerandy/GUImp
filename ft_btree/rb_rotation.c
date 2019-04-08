/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:44:24 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/08 19:53:16 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree_rb.h"

void			rb_rotation_left(t_rb_node *node_a)
{
	t_rb_node	*node_b;
	t_rb_node	*father;

	node_b = node_a->right;
	father = node_a->parent;
	node_a->right = node_b->left;
	node_b->left = node_a;
	node_a->parent = node_b;
	if (node_a->right)
		node_a->right->parent = node_a;
	if (father)
	{
		if (node_a == father->left)
			father->left = node_b;
		else
			father->right = node_b;
	}
	node_b->parent = father;
}

void			rb_rotation_right(t_rb_node *node_a)
{
	t_rb_node	*node_b;
	t_rb_node	*father;

	node_b = node_a->left;
	father = node_a->parent;
	node_a->left = node_b->right;
	node_b->right = node_a;
	node_a->parent = node_b;
	if (node_a->left)
		node_a->left->parent = node_a;
	if (father)
	{
		if (node_a == father->left)
			father->left = node_b;
		else
			father->right = node_b;
	}
	node_b->parent = father;
}
