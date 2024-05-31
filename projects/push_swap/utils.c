/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:35:20 by kpires            #+#    #+#             */
/*   Updated: 2024/05/31 12:35:20 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_set_highest(t_ht_list *ht_list, char list)
{
	t_node	*current;
	int		highest;

	current = get_head(ht_list, list);
	highest = get_highest(ht_list, list);
	while (current)
	{
		if (current->nbr > highest)
		{
			highest = current->nbr;
			if (list == 'a')
				ht_list->higher_a = current;
			else if (list == 'b')
				ht_list->higher_b = current;
		}
		current = current->next;
	}
}

static void	find_set_lowest(t_ht_list *ht_list, char list)
{
	t_node	*current;
	int		lowest;

	current = get_head(ht_list, list);
	lowest = get_lowest(ht_list, list);
	while (current)
	{
		if (current->nbr < lowest)
		{
			lowest = current->nbr;
			if (list == 'a')
				ht_list->lower_a = current;
			else if (list == 'b')
				ht_list->lower_b = current;
		}
		current = current->next;
	}
}

void	update_highest_lowest(t_ht_list *ht_list)
{
	find_set_highest(ht_list, 'a');
	find_set_lowest(ht_list, 'a');
	find_set_highest(ht_list, 'b');
	find_set_lowest(ht_list, 'b');
}
