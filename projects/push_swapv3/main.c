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

static t_HTlist	*init_list(t_HTlist *list)
{
	list = malloc(sizeof(t_HTlist));
	list->higher_a = NULL;
	list->head_a = NULL;
	list->tail_a = NULL;
	list->length_a = 0;
	list->higher_b = NULL;
	list->head_b = NULL;
	list->tail_b = NULL;
	list->length_b = 0;
	return (list);
}

int	main(int ac, char **av)
{
	char		*arg_processed;
	t_node		*a;
	t_HTlist	*list;

	if (ac == 1)
		return (1);
	a = NULL;
	list = NULL;
	arg_processed = process_arg(ac, av);
	list = init_list(list);
	init_node(arg_processed, list);
	a = list->head_a;
	print_list(list, 'a');
	if (!check_is_sort(a))
	{
		printf("\n[stack not sorted]\n");
		sort(list);
	}
	print_list(list, 'a');
	printf("\n[LENGTH A]: %d\n", list->length_a);
	printf("[HIGHER]: %d\n", list->higher_a->nbr);
	printf("ac[%d]", ac);
	free_list(list);
	return (0);
}
