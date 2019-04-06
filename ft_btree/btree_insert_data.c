/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 18:46:55 by gsmith            #+#    #+#             */
/*   Updated: 2019/04/06 19:01:32 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

/*
** Insert un item dans l'arbre binaire root en creant un nouveau noeud.
** 		Si l'arbre est null, le nouvel element prend sa place.
** 		Les elements inferieurs a la racine sont places a gauche.
** 		Les elements superieurs ou egal a la racine sont places a droite.
*/

void	btree_insert_data(t_btree **root, void *item, \
			int (*cmp_funct)(void *, void *))
{
	if (!root)
		return ;
	if (!(*root))
		*root = btree_new_node(item);
	else if (cmp_funct((*root)->data, item) > 0)
		btree_insert_data(&((*root)->left), item, cmp_funct);
	else
		btree_insert_data(&((*root)->right), item, cmp_funct);
}
