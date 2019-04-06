/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 20:26:03 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/06 20:32:47 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int		btree_level_count(t_btree *root)
{
	int		left_size;
	int		right_size;

	if (!root)
		return (0);
	left_size = btree_level_count(root->left);
	right_size = btree_level_count(root->right);
	if (left_size > right_size)
		return (1 + left_size);
	return (1 + right_size);
}
