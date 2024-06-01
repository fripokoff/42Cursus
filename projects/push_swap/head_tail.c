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
	update_highest_lowest(ht_list);
}
