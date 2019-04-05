/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_new_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:53:09 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/04 18:20:54 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

/*
** Create and return a new btree node.
** Its data is initialized with the argument given.
** The parent and childs are set to NULL.
** return NULL if malloc failed.
*/

t_btree			*btree_new_node(void *data)
{
	t_btree		*new_node;

	if (!(new_node = (t_btree *)malloc(sizeof(new_node))))
		return (NULL);
	new_node->parent = NULL;
	new_node->right = NULL;
	new_node->left = NULL;
	new_node->data = data;
	return (new_node);
}
