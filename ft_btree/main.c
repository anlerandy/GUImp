#include <stdio.h>
#include <stdlib.h>
#include "ft_btree.h"

void	btree_print_node(void *data)
{
	if (!data)
		return ;
	printf("node:\t%c\n", *(char *)data);
}

int		main(void)
{
	t_btree		*tree;
	char		*dataset;

	if (!(dataset = (char *)malloc(sizeof(char) * 4)))
		return (1);
	dataset[0] = 'B';
	dataset[1] = 'A';
	dataset[2] = 'C';
	dataset[3] = 0;
	if (!(tree = btree_new_node(dataset)))
	{
		free(dataset);
		return (1);
	}
	tree->left = btree_new_node(dataset + 1);
	tree->right = btree_new_node(dataset + 2);
	printf("Parcours prefix:\n");
	btree_apply_prefix(tree, btree_print_node);
	printf("\nParcours suffix:\n");
	btree_apply_suffix(tree, btree_print_node);
	printf("\nParcours infix:\n");
	btree_apply_infix(tree, btree_print_node);
	free(dataset);
	free(tree->right);
	free(tree->left);
	free(tree);
	return (0);
}
