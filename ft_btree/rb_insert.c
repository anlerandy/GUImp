/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 13:51:11 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/08 20:59:22 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_btree_rb.h"

static t_rb_node	*rb_new_node(void *data, t_rb_node *parent, t_rb_color col)
{
	t_rb_node	*new_node;

	if (!(new_node = (t_rb_node *)malloc(sizeof(t_rb_node))))
		return (NULL);
	new_node->parent = parent;
	new_node->right = NULL;
	new_node->left = NULL;
	new_node->data = data;
	new_node->color = col;
	return (new_node);
}

static t_rb_node	*rb_insert_data(t_rb_node **root, void *item, \
						int (*cmp_funct)(void *, void *))
{
	if (!root)
		return (NULL);
	if (!(*root))
		return ((*root = rb_new_node(item, NULL, RB_BLACK)));
	else if (cmp_funct((*root)->data, item) > 0)
	{
		if ((*root)->left)
			return (rb_insert_data(&((*root)->left), item, cmp_funct));
		else
			return (((*root)->left = rb_new_node(item, *root, RB_RED)));
	}
	else
	{
		if ((*root)->right)
			return (rb_insert_data(&((*root)->right), item, cmp_funct));
		else
			return (((*root)->right = rb_new_node(item, *root, RB_RED)));
	}
}

static t_rb_node	*rotate_parents(t_rb_node *node)
{
	t_rb_node	*father;
	t_rb_node	*grand_father;

	father = node->parent;
	grand_father = rb_grand_father(node);
	if (grand_father->left && node == grand_father->left->right)
	{
		rb_rotation_left(father);
		node = node->left;
	}
	else if (grand_father->right && node == grand_father->right->left)
	{
		rb_rotation_right(father);
		node = node->right;
	}
	father = node->parent;
	grand_father = rb_grand_father(node);
	if (node == node->parent->left)
		rb_rotation_right(grand_father);
	else
		rb_rotation_left(grand_father);
	father->color = RB_BLACK;
	grand_father->color = RB_RED;
	return (rb_get_root(node));
}

static t_rb_node	*fix_tree(t_rb_node *node)
{
	t_rb_node	*father;
	t_rb_node	*uncle;
	t_rb_node	*grand_father;

	if (!node)
		return (NULL);
	if (!(node->parent))
	{
		node->color = RB_BLACK;
		return (rb_get_root(node));
	}
	if (node->parent->color == RB_BLACK)
		return (rb_get_root(node));
	grand_father = rb_grand_father(node);
	father = node->parent;
	uncle = rb_uncle(node);
	if (uncle && uncle->color == RB_RED)
	{
		father->color = RB_BLACK;
		uncle->color = RB_BLACK;
		grand_father->color = RB_RED;
		return (fix_tree(grand_father));
	}
	else
		return (rotate_parents(node));
}

void				rb_insert(t_rb_node **root, void *data, \
						int (*cmpf)(void *, void *))
{
	t_rb_node	*new_n;

	if (!root)
		return ;
	new_n = rb_insert_data(root, data, cmpf);
	*root = fix_tree(new_n);
}
