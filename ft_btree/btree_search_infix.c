/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_infix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 19:22:49 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/06 20:23:24 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_btree.h"

void	*btree_search_infix(t_btree *root, void *data_ref, \
			int (*cmp_funct)(void *, void *))
{
	t_btree		*left_res;

	if (!root)
		return (NULL);
	if (!cmp_funct(data_ref, root->data))
		return (root->data);
	left_res = btree_search_infix(root->left, data_ref, cmp_funct);
	if (left_res)
		return (left_res);
	return (btree_search_infix(root->right, data_ref, cmp_funct));
}
