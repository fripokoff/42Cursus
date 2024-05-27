/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:37:43 by kpires            #+#    #+#             */
/*   Updated: 2024/05/27 17:25:03 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	refresh_index(t_node *list, int len_list)
{
	int	i;
	int	median;

	i = 0;
	median = len_list / 2;
	while (list)
	{
		list->index = i;
		if (i < median)
			list->above_median = true;
		else
			list->above_median = false;
		list = list->next;
		i++;
	}
}

void	refresh_target(t_ht_list *list)
{
    t_node	*current_a;
    t_node	*target;
    long	best_match;
    t_node	*temp_b = list->head_b;

    while (temp_b)
    {
        best_match = LONG_MAX;
        current_a = list->head_a;
        while (current_a)
        {
            if (current_a->nbr > temp_b->nbr && current_a->nbr < best_match)
            {
                best_match = current_a->nbr;
                target = current_a;
            }
            current_a = current_a->next;
        }
        if (best_match == LONG_MAX)
            temp_b->target = list->lower_a;
        else
            temp_b->target = target;
        temp_b = temp_b->next;
    }
}


static void	cost_b(t_ht_list *list)
{
	t_node	*current_b;

	current_b = list->head_b;
	while (current_b)
	{
		current_b->cost = current_b->index;
		if (!(current_b->above_median))
			current_b->cost = list->length_b - current_b->index;
		if (current_b->target->above_median)
			current_b->cost += current_b->target->index;
		else
			current_b->cost += list->length_a - current_b->target->index;
		current_b = current_b->next;
	}
}
void	refresh(t_ht_list *ht_list)
{
	refresh_index(ht_list->head_a, ht_list->length_a);
	refresh_index(ht_list->head_b, ht_list->length_b);
	refresh_target(ht_list);
	cost_b(ht_list);
}
