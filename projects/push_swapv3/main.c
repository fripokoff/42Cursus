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

static t_ht_list	*init_list(t_ht_list *ht_list)
{
	ht_list = malloc(sizeof(t_ht_list));
	ht_list->higher_a = NULL;
	ht_list->head_a = NULL;
	ht_list->tail_a = NULL;
	ht_list->length_a = 0;
	ht_list->higher_b = NULL;
	ht_list->head_b = NULL;
	ht_list->tail_b = NULL;
	ht_list->length_b = 0;
	return (ht_list);
}

static void	print_for_test(t_ht_list *ht_list)
{
	if (ht_list->head_a)
		print_list(ht_list, 'a');
	if (ht_list->length_a)
		printf("[LENGTH A]: %d\n", ht_list->length_a);
	if (ht_list->higher_a)
		printf("[HIGHER A]: %d\n", ht_list->higher_a->nbr);
	if (ht_list->lower_a)
		printf("[LOWER A]: %d\n", ht_list->lower_a->nbr);
	if (ht_list->head_b)
		print_list(ht_list, 'b');
	if (ht_list->length_b)
		printf("[LENGTH B]: %d\n", ht_list->length_b);
	if (ht_list->higher_b)
		printf("[HIGHER B]: %d\n", ht_list->higher_b->nbr);
	if (ht_list->lower_b)
		printf("[LOWER B]: %d\n", ht_list->lower_b->nbr);
}

int	main(int ac, char **av)
{
	char		*arg_processed;
	t_node		*a;
	t_ht_list	*ht_list;

	if (ac == 1)
		return (1);
	a = NULL;
	ht_list = NULL;
	arg_processed = process_arg(ac, av);
	ht_list = init_list(ht_list);
	init_node(arg_processed, ht_list);
	a = ht_list->head_a;
	if (!check_is_sort(a))
	{
		printf("\n[stack not sorted]\n");
		sort(ht_list);
	}
	// print_list(ht_list, 'a');
	// print_list(ht_list, 'b');
	print_for_test(ht_list);
	printf("ac[%d]", ac);
	free_list(ht_list);
	return (0);
}
