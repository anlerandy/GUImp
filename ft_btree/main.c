#include <stdio.h>
#include <stdlib.h>
#include "ft_btree.h"

void	btree_print_node(void *data)
{
	if (!data)
		return ;
	printf("node:\t%c\n", *(char *)data);
}

int		cmp_char(void *char_a, void *char_b)
{
	return (*(char *)char_a - *(char *)char_b);
}

int		search_char(void *char_a, void *char_b)
{
	return (*(char *)char_a > *(char *)char_b);
}

int		main(void)
{
	t_btree		*tree;
	char		*dataset;

	if (!(dataset = (char *)malloc(sizeof(char) * 4)))
		return (1);
	dataset[0] = 'A';
	dataset[1] = 'B';
	dataset[2] = 'C';
	dataset[3] = 0;
	tree = NULL;
	btree_insert_data(&tree, dataset, &cmp_char);
	btree_insert_data(&tree, dataset + 1, &cmp_char);
	btree_insert_data(&tree, dataset + 2, &cmp_char);
	btree_insert_data(&tree, dataset, &cmp_char);
	btree_insert_data(&tree, dataset + 1, &cmp_char);
	btree_insert_data(&tree, dataset + 2, &cmp_char);
	printf("Parcours prefix:\n");
	btree_apply_prefix(tree, btree_print_node);
	printf("\nParcours suffix:\n");
	btree_apply_suffix(tree, btree_print_node);
	printf("\nParcours infix:\n");
	btree_apply_infix(tree, btree_print_node);
	printf("node found:\t%c\n", *(char *)btree_search_infix(tree, dataset + 1, &search_char));
	free(dataset);
	free(tree->right);
	free(tree->left);
	free(tree);
	return (0);
}
