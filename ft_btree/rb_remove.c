/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_remove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 21:35:32 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/10 19:27:36 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_btree_rb.h"

static void		free_node(t_rb_node **node_pt, t_rb_node *new_node)
{
	t_rb_node	*old_node;

	old_node = *node_pt;
	*node_pt = new_node;
	if (new_node)
		new_node->parent = old_node->parent;
	if (old_node->color == RB_BLACK)
	{
		if (new_node && new_node->color == RB_RED)
			new_node->color = RB_BLACK;
		else
		{
			rb_fix_removal(new_node);
			return ;
		}
	}
	free(old_node);
}

static void		swap_node_data(t_rb_node **node_pt, void **data, int with_max)
{
	t_rb_node	*node;
	t_rb_node	**node_next;

	node = *node_pt;
	node_next = with_max ? &(node->right) : &(node->left);
	if (*node_next)
	{
		swap_node_data(node_next, data, with_max);
		return ;
	}
	*data = node->data;
	free_node(node_pt, with_max ? node->left : node->right);
}

static void		remove_node(t_rb_node **node_pt, void (*freef)(void *))
{
	t_rb_node	*node;

	node = *node_pt;
	freef(node->data);
	if (node->left)
		swap_node_data(&(node->left), &(node->data), 1);
	else if (node->right)
		swap_node_data(&(node->right), &(node->data), 0);
	else
		free_node(node_pt, NULL);
}

void			rb_remove(t_rb_node **root, void *data, \
					int (*cmpf)(void *, void *), void (*freef)(void *))
{
	int		cmp;

	if (!root || !(*root))
		return ;
	cmp = cmpf((*root)->data, data);
	if (cmp < 0)
		rb_remove(&((*root)->right), data, cmpf, freef);
	else if (cmp > 0)
		rb_remove(&((*root)->left), data, cmpf, freef);
	else
		remove_node(root, freef);
}
