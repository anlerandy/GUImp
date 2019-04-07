/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:44:24 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/07 16:32:14 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree_rb.h"

void	rb_rotation_left(t_rb_node **node)
{
	t_rb_node	*node_a;
	t_rb_node	*node_b;

	node_a = *node;
	node_b = node_a->right;
	node_a->right = node_b->left;
	if (node_b->left)
		node_b->left->parent = node_a;
	node_b->parent = node_a->parent;
	if (!(node_a->parent))
		*node = node_b;
	else if (node_a == node_a->parent->left)
		node_a->parent->left = node_b;
	else
		node_a->parent->right = node_b;
	node_b->left = node_a;
	node_a->parent = node_b;
}

void	rb_rotation_right(t_rb_node **node)
{
	t_rb_node	*node_a;
	t_rb_node	*node_b;

	node_a = *node;
	node_b = node_a->left;
	node_a->left = node_b->right;
	if (node_b->right)
		node_b->right->parent = node_a;
	node_b->parent = node_a->parent;
	if (!(node_a->parent))
		*node = node_b;
	else if (node_a == node_a->parent->left)
		node_a->parent->left = node_b;
	else
		node_a->parent->right = node_b;
	node_b->right = node_a;
	node_a->parent = node_b;
}
