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

int	main(int ac, char **av)
{
	char		*arg_processed;
	t_ht_list	*ht_list;

	if (ac == 1)
		return (1);
	ht_list = NULL;
	arg_processed = process_arg(ac, av);
	ht_list = init_list(ht_list);
	init_node(arg_processed, ht_list);
	if (!check_is_sort(ht_list->head_a))
		sort(ht_list);
	free_list(ht_list);
	return (0);
}
