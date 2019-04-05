#include <stdio.h>
#include <stdlib.h>
#include "ft_btree.h"

int		main(void)
{
	t_btree		*toast;
	int			data;

	data = 5;
	toast = btree_new_node(&data);
	if (!toast)
	{
		printf("malloc error\n");
		return (1);
	}
	btree_print_infix(toast);
	free(toast);
	return (0);
}
