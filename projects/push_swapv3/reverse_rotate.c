/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:39:10 by kpires            #+#    #+#             */
/*   Updated: 2024/04/30 15:39:10 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	reverse_rotate(t_HTlist *list, char list_name)
{
	t_node	**head;
	t_node	**tail;
	t_node	*temp;

	head = get_head(list, list_name);
	tail = get_tail(list, list_name);

	if( !(*head) || !(*head)->next || !(*tail))
		return ;
	temp = *head;

	*head = *tail;
	(*head)->next = temp->next;
	(*head)->next->prev = (*head);
	(*head)->prev = NULL;
	temp->next = NULL;
	temp->prev = (*tail)->prev;
	*tail = temp;
}

// 1 2 3 4 5
// 5 2 3 4 1

void	rra(t_HTlist *list, bool print)
{
	reverse_rotate(list, 'a');
	if (print)
		printf("rra\n");
}

void	rrb(t_HTlist *list, bool print)
{
	reverse_rotate(list, 'b');
	if (print)
		printf("rrb\n");
}

void	rrr(t_HTlist *list, bool print)
{
	reverse_rotate(list, 'a');
	reverse_rotate(list, 'b');
	if (print)
		printf("rrr\n");
}
