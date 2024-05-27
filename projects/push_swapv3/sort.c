/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:26:57 by kpires            #+#    #+#             */
/*   Updated: 2024/04/30 13:26:57 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_ht_list *ht_list)
{
	if (ht_list->higher_a == ht_list->head_a)
		ra(ht_list, true);
	else if (ht_list->head_a->next == ht_list->higher_a)
		rra(ht_list, true);
	if (ht_list->head_a->nbr > ht_list->head_a->next->nbr)
		sa(ht_list, true);
}

bool	check_is_sort(t_node *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->nbr > a->next->nbr)
			return (false);
		a = a->next;
	}
	return (true);
}

static void	sort_big(t_ht_list *ht_list)
{
	int	len_a;
	int	median;

	len_a = ht_list->length_a;
	median = ((ht_list->lower_a->nbr + ht_list->higher_a->nbr) / 2);
	printf("median %d \n", median);
	printf("len %d \n", len_a);
	while (len_a-- > 3 && !check_is_sort(ht_list->head_a))
		push_a_to_b(ht_list, median);
	sort_three(ht_list);
	int max = ht_list->length_b + ht_list->length_a;
	int i = 0;
	while (ht_list->head_b && i < max)
	{
		refresh(ht_list);
		// push_b_to_a(ht_list);
		i++;
	}
	// refresh_index(*a);
	// to_the_top(a);
}


void	sort(t_ht_list *ht_list)
{
	if (ht_list->length_a == 2)
		sa(ht_list, true);
	else if (ht_list->length_a == 3)
		sort_three(ht_list);
	else
		sort_big(ht_list);
}
