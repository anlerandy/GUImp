/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 13:51:11 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/07 15:02:52 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void				rb_insert(t_rb_node **root, void *data, \
						int (*cmpf)(void *, void *))
{
	t_rb_node	*new_n;

	new_n = rb_insert_data(root, data, cmpf);
}
