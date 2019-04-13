/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_remove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 21:35:32 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/13 22:00:04 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_btree_rb.h"

static void			free_node(t_rb_node **root, t_rb_node *old_node)
{
	t_rb_node	*new_node;

	new_node = old_node->left ? old_node->left : old_node->right;
	if (old_node->color == RB_BLACK)
	{
		if (new_node && new_node->color == RB_RED)
			new_node->color = RB_BLACK;
		else
			rb_fix_black_node(root, old_node);
	}
	*rb_rot_node(root, old_node) = new_node;
	if (new_node)
	{
		new_node->parent = old_node->parent;
		*rb_rot_node(root, new_node) = NULL;
	}
	free(old_node);
}

static t_rb_node	*swap_node_data(t_rb_node *node, void **data, int with_max)
{
	t_rb_node	*node_next;

	node_next = with_max ? node->right : node->left;
	if (!node_next)
	{
		*data = node->data;
		return (node);
	}
	return (swap_node_data(node_next, data, with_max));
}

static t_rb_node	*locate_node(t_rb_node *node, void *data, \
						int (*cmpf)(void *, void *))
{
	int			cmp;
	t_rb_node	*next_node;

	if (!node)
		return (NULL);
	cmp = cmpf(node->data, data);
	if (!cmp)
		return (node);
	next_node = node->right;
	if (cmp > 0)
		next_node = node->left;
	return (locate_node(next_node, data, cmpf));
}

void				rb_remove(t_rb_node **root, void *data, \
						int (*cmpf)(void *, void *), void (*freef)(void *))
{
	int			cmp;
	t_rb_node	*node;
	t_rb_node	**next_node;

	if (!root || !(*root))
		return ;
	if (!(node = locate_node(*root, data, cmpf)))
		return ;
	freef(node->data);
	if (node->left)
		node = swap_node_data(node->left, &(node->data), 1);
	else if (node->right)
		node = swap_node_data(node->right, &(node->data), 0);
	free_node(root, node);
}
