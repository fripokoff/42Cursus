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

void	rotate(t_HTlist *list, char list_name)
{
	t_node	**head;
	t_node	**tail;

	head = get_head(list, list_name);
	tail = get_tail(list, list_name);
	if (!*head || !(*head)->next || !*tail)
		return ;
	(*tail)->next = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	(*tail)->next->prev = *tail;
	(*tail)->next->next = NULL;
}

void	ra(t_HTlist *list, bool print)
{
	rotate(list, 'a');
	if (print)
		printf("ra\n");
}

void	rb(t_HTlist *list, bool print)
{
	rotate(list, 'b');
	if (print)
		printf("rb\n");
}

void	rr(t_HTlist *list, bool print)
{
	rotate(list, 'a');
	rotate(list, 'b');
	if (print)
		printf("rr\n");
}