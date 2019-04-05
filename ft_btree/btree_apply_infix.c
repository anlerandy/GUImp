/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_infix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 22:27:47 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/05 22:43:52 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_infix(t_btree *root, void (*node_funct)(void *))
{
	if (!root)
		return ;
	if (root->left)
		btree_apply_infix(root->left, node_funct);
	node_funct(root->data);
	if (!(root->right))
		return ;
	btree_apply_infix(root->right, node_funct);
}
