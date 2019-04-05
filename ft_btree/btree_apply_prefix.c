/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 22:10:36 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/05 22:43:17 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_prefix(t_btree *root, void (*node_funct)(void *))
{
	if (!root)
		return ;
	node_funct(root->data);
	if (root->left)
		btree_apply_prefix(root->left, node_funct);
	if (!(root->right))
		return ;
	btree_apply_prefix(root->right, node_funct);
}
