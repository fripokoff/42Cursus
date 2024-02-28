/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 07:34:35 by kpires            #+#    #+#             */
/*   Updated: 2024/02/26 07:34:35 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static x_list *init_list(x_list *list)
{
	list = malloc(sizeof(x_list));
	list->heap = NULL;
	list->tail = NULL;
	return (list);
}

int	main(int ac, char **av)
{
	char		*arg_processed;
	t_node		*a;
	x_list		*list;

	if (ac == 1)
		return (1);
	a = NULL;
	list = NULL;
	arg_processed = process_arg(ac, av);
	list = init_list(list);
	init_node(arg_processed, list);
	a = list->heap;
	print_node(a);
	free_list(list);
	printf("ac[%d]", ac);
	return (0);
}
