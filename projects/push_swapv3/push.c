/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:57:15 by kpires            #+#    #+#             */
/*   Updated: 2024/05/07 10:00:45 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_ht_list	*ht_list, bool	print)
{
	t_node	*temp;

	if (ht_list->head_b == NULL)
        return;
	temp = ht_list->head_b;
	ht_list->head_b = ht_list->head_b->next;
	temp->next = ht_list->head_a;
	ht_list->head_a = temp;
	if (ht_list->tail_a == NULL)
		ht_list->tail_a = ht_list->head_a;
	if (ht_list->head_b == NULL)
		ht_list->tail_b = NULL;
	find_highest(ht_list, 'a');
	find_highest(ht_list, 'b');
	find_lowest(ht_list, 'a');
	find_lowest(ht_list, 'b');
	ht_list->length_a++;
	ht_list->length_b--;
	if (print)
		printf("pa\n");
}

void	pb(t_ht_list *ht_list, bool	print)
{
	t_node	*temp;

	if (ht_list->head_a == NULL)
			return;
	temp = ht_list->head_a;
	ht_list->head_a = ht_list->head_a->next;
	temp->next = ht_list->head_b;
	ht_list->head_b = temp;
	if (ht_list->tail_b == NULL)
		ht_list->tail_b = ht_list->head_b;
	if (ht_list->head_a == NULL)
		ht_list->tail_a = NULL;
	find_highest(ht_list, 'a');
	find_highest(ht_list, 'b');
	find_lowest(ht_list, 'a');
	find_lowest(ht_list, 'b');
	ht_list->length_b++;
	ht_list->length_a--;
	if (print)
		printf("pb\n");
}
