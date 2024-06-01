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
		rotate(ht_list, 'a');
	else if (ht_list->head_a->next == ht_list->higher_a)
		reverse_rotate(ht_list, 'a');
	if (ht_list->head_a->nbr > ht_list->head_a->next->nbr)
		swap(ht_list, 'a');
}

static void	sort_big(t_ht_list *ht_list)
{
	int	*arr;
	int	range;

	arr = sort_int_tab(copy_arr(ht_list), ht_list->length_a);
	range = get_range(ht_list);
	while_for_norm(ht_list, arr, ht_list->length_a, range);
	free(arr);
	while (ht_list->head_b)
		push_max(ht_list);
}

static void	push_target(t_ht_list *ht_list, int target)
{
	int		index;
	t_node	*current;

	index = 0;
	current = ht_list->head_a;
	while (current->nbr != target)
	{
		index++;
		current = current->next;
	}
	if (index < ht_list->length_a / 2)
		while (ht_list->head_a->nbr != target)
			rotate(ht_list, 'a');
	else
		while (ht_list->head_a->nbr != target)
			reverse_rotate(ht_list, 'a');
	pb(ht_list);
}

static void	sort_four_five(t_ht_list *ht_list)
{
	push_target(ht_list, ht_list->lower_a->nbr);
	push_target(ht_list, ht_list->lower_a->nbr);
	if (ht_list->head_b->next
		&& ht_list->head_b->nbr < ht_list->head_b->next->nbr)
	{
		swap(ht_list, 'b');
	}
	sort_three(ht_list);
	while (ht_list->head_b)
	{
		pa(ht_list);
	}
}

void	sort(t_ht_list *ht_list)
{
	if (ht_list->length_a == 2)
		swap(ht_list, 'a');
	else if (ht_list->length_a == 3)
		sort_three(ht_list);
	else if (ht_list->length_a == 5 || ht_list->length_a == 4)
		sort_four_five(ht_list);
	else
		sort_big(ht_list);
}
