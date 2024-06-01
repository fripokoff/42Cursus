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

static t_node	*get_highest(t_ht_list *ht_list, char list)
{
	t_node	*current;
	t_node	*highest;
	int		higher;

	current = get_head(ht_list, list);
	if (current == NULL)
		return (NULL);
	higher = current->nbr;
	highest = current;
	while (current)
	{
		if (current->nbr > higher)
		{
			higher = current->nbr;
			highest = current;
		}
		current = current->next;
	}
	return (highest);
}

static t_node	*get_lowest(t_ht_list *ht_list, char list)
{
	t_node	*current;
	t_node	*lowest;
	int		lower;

	current = get_head(ht_list, list);
	if (current == NULL)
		return (NULL);
	lowest = current;
	lower = current->nbr;
	while (current)
	{
		if (current->nbr < lower)
		{
			lower = current->nbr;
			lowest = current;
		}
		current = current->next;
	}
	return (lowest);
}

void	update_highest_lowest(t_ht_list *ht_list)
{
	t_node	*highest;
	t_node	*lowest;

	highest = get_highest(ht_list, 'a');
	ht_list->higher_a = highest;
	highest = get_highest(ht_list, 'b');
	ht_list->higher_b = highest;
	lowest = get_lowest(ht_list, 'a');
	ht_list->lower_a = lowest;
	lowest = get_lowest(ht_list, 'b');
	ht_list->lower_b = lowest;
}
