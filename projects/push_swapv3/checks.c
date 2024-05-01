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

t_node	**get_head(t_HTlist *list, char list_name)
{
	t_node	**head;

	if (list_name == 'a')
		head = &(list->head_a);
	else if (list_name == 'b')
		head = &(list->head_b);
	else
		return (NULL);
	return (head);
}

t_node	**get_tail(t_HTlist *list, char list_name)
{
	t_node	**tail;

	if (list_name == 'a')
		tail = &(list->tail_a);
	else if (list_name == 'b')
		tail = &(list->tail_b);
	else
		return (NULL);
	return (tail);
}

int get_length(t_HTlist *list, char list_name)
{
	if (list_name == 'a')
		return (list->length_a);
	else if (list_name == 'b')
		return (list->length_b);
	return (0);
}