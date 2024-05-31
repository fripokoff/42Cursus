/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:35:19 by kpires            #+#    #+#             */
/*   Updated: 2024/04/30 14:35:19 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_ht_list *ht_list, char list)
{
	t_node	**head;
	t_node	**tail;
	t_node	*temp;

	head = get_head(ht_list, list);
	tail = get_tail(ht_list, list);
	if (!*head || !*tail || !(*head)->next)
		return ;
	temp = *head;
	(*head) = temp->next;
	(*head)->prev = NULL;
	temp->prev = (*tail);
	temp->next = NULL;
	(*tail)->next = temp;
	*tail = temp;
	update_headtail(ht_list, head, tail, list);
}

void	ra(t_ht_list *ht_list, bool print)
{
	rotate(ht_list, 'a');
	if (print)
		printf("ra\n");
}

void	rb(t_ht_list *ht_list, bool print)
{
	rotate(ht_list, 'b');
	if (print)
		printf("rb\n");
}

void	rr(t_ht_list *ht_list, bool print)
{
	rotate(ht_list, 'a');
	rotate(ht_list, 'b');
	if (print)
		printf("rr\n");
}
