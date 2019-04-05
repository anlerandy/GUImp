/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_suffix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 22:16:52 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/05 22:43:42 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_suffix(t_btree *root, void (*node_funct)(void *))
{
	if (!root)
		return ;
	if (root->left)
		btree_apply_suffix(root->left, node_funct);
	if (root->right)
		btree_apply_suffix(root->right, node_funct);
	node_funct(root->data);
}
