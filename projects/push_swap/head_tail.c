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

t_node	*get_head(t_ht_list *ht_list, char list)
{
	t_node	*head;

	if (list == 'a')
		head = ht_list->head_a;
	else if (list == 'b')
		head = ht_list->head_b;
	else
		return (NULL);
	return (head);
}

t_node	*get_tail(t_ht_list *ht_list, char list)
{
	t_node	*tail;

	if (list == 'a')
		tail = ht_list->tail_a;
	else if (list == 'b')
		tail = ht_list->tail_b;
	else
		return (NULL);
	return (tail);
}

void	update_headtail(t_ht_list *ht_list, t_node *head
		, t_node *tail, char list)
{
	if (list == 'a')
	{
		if (head)
			ht_list->head_a = head;
		if (tail)
			ht_list->tail_a = tail;
	}
	else if (list == 'b')
	{
		if (head)
			ht_list->head_b = head;
		if (tail)
			ht_list->tail_b = tail;
	}
}

int	get_highest(t_ht_list *ht_list, char list)
{
	int	highest;

	highest = INT_MIN;
	if (list == 'a')
	{
		if ((ht_list->higher_a))
			highest = ht_list->higher_a->nbr;
	}
	else if (list == 'b')
	{
		if ((ht_list->higher_b))
			highest = ht_list->higher_b->nbr;
	}
	return (highest);
}

int get_lowest(t_ht_list *ht_list, char list)
{
	int	lowest;

	lowest = INT_MAX;
	if (list == 'a')
	{
		if ((ht_list->lower_a))
			lowest = ht_list->lower_a->nbr;
	}
	else if (list == 'b')
	{
		if ((ht_list->lower_b))
			lowest = ht_list->lower_b->nbr;
	}
	return (lowest);
}