/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:19:05 by kpires            #+#    #+#             */
/*   Updated: 2024/04/30 13:19:05 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	**get_head(t_ht_list *ht_list, char list)
{
	t_node	**head;

	if (list == 'a')
		head = &(ht_list->head_a);
	else if (list == 'b')
		head = &(ht_list->head_b);
	else
		return (NULL);
	return (head);
}

t_node	**get_tail(t_ht_list *ht_list, char list)
{
	t_node	**tail;

	if (list == 'a')
		tail = &(ht_list->tail_a);
	else if (list == 'b')
		tail = &(ht_list->tail_b);
	else
		return (NULL);
	return (tail);
}

// static int	get_length(t_ht_list *ht_list, char list)
// {
// 	if (list == 'a')
// 		return (ht_list->length_a);
// 	else if (list == 'b')
// 		return (ht_list->length_b);
// 	return (0);
// }

void	update_headtail(t_ht_list *ht_list, t_node **head
		, t_node **tail, char list)
{
	if (list == 'a')
	{
		if ((*head))
			ht_list->head_a = *head;
		if ((*tail))
			ht_list->tail_a = *tail;
	}
	else if (list == 'b')
	{
		if ((*head))
			ht_list->head_b = *head;
		if ((*tail))
			ht_list->tail_b = *tail;
	}
}

void update_highest_lowest(t_ht_list *ht_list, char list)
{
	if(list == '2')
	{
		find_highest(ht_list, 'a');
		find_lowest(ht_list, 'a');
		find_highest(ht_list, 'b');
		find_lowest(ht_list, 'b');
	}
	else
	{
		find_highest(ht_list, list);
		find_lowest(ht_list, list);
	
	}
}

void	find_highest(t_ht_list *ht_list, char list)
{
	t_node	*current;
	int		highest;

	if (list == 'a')
    {
        current = ht_list->head_a;
        highest = (ht_list->higher_a) ? ht_list->higher_a->nbr : INT_MIN;
    }
    else if (list == 'b')
    {
        current = ht_list->head_b;
        highest = (ht_list->higher_b) ? ht_list->higher_b->nbr : INT_MIN;
    }
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

void	find_lowest(t_ht_list *ht_list, char list)
{
	t_node	*current;
	int		lowest;

	if (list == 'a')
    {
        current = ht_list->head_a;
        lowest = (ht_list->higher_a) ? ht_list->higher_a->nbr : INT_MAX;
    }
    else if (list == 'b')
    {
        current = ht_list->head_b;
        lowest = (ht_list->higher_b) ? ht_list->higher_b->nbr : INT_MAX;
    }
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
