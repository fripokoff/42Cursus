/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 11:03:36 by kpires            #+#    #+#             */
/*   Updated: 2024/05/31 11:03:36 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_ht_list *ht_list, char list)
{
	t_node	*head;
	t_node	*tail;
	t_node	*temp_tail;

	head = get_head(ht_list, list);
	tail = get_tail(ht_list, list);
	if (!head || !head->next || !tail)
		return ;
	temp_tail = tail;
	tail = tail->prev;
	if (tail)
		tail->next = NULL;
	temp_tail->next = head;
	head->prev = temp_tail;
	head = temp_tail;
	update_headtail(ht_list, head, tail, list);
	if (list == 'a')
		write(1, "rra\n", 4);
	else if (list == 'b')
		write(1, "rrb\n", 4);
}

void	swap(t_ht_list *ht_list, char list)
{
	t_node	*head;
	t_node	*tail;
	int		head_nbr;

	head = get_head(ht_list, list);
	tail = get_tail(ht_list, list);
	if (!head || !head->next || !tail)
		return ;
	head_nbr = head->nbr;
	head->nbr = head->next->nbr;
	head->next->nbr = head_nbr;
	update_headtail(ht_list, head, tail, list);
	if (list == 'a')
		write(1, "sa\n", 3);
	else if (list == 'b')
		write(1, "sb\n", 3);
}

void	rotate(t_ht_list *ht_list, char list)
{
	t_node	*head;
	t_node	*tail;
	t_node	*temp_head;

	head = get_head(ht_list, list);
	tail = get_tail(ht_list, list);
	if (!head || !tail || !head->next)
		return ;
	temp_head = head;
	head = temp_head->next;
	head->prev = NULL;
	temp_head->prev = tail;
	temp_head->next = NULL;
	tail->next = temp_head;
	tail = temp_head;
	update_headtail(ht_list, head, tail, list);
	if (list == 'a')
		write(1, "ra\n", 3);
	else if (list == 'b')
		write(1, "rb\n", 3);
}

void	pa(t_ht_list *ht_list)
{
	t_node	*head_b;

	if (ht_list->head_b == NULL)
		return ;
	head_b = ht_list->head_b;
	ht_list->head_b = ht_list->head_b->next;
	if (ht_list->head_b != NULL)
		ht_list->head_b->prev = NULL;
	head_b->next = ht_list->head_a;
	if (ht_list->head_a != NULL)
		ht_list->head_a->prev = head_b;
	ht_list->head_a = head_b;
	head_b->prev = NULL;
	if (ht_list->tail_a == NULL)
	{
		ht_list->tail_a = ht_list->head_a;
		if (ht_list->tail_a->next != NULL)
			ht_list->tail_a->next->prev = ht_list->tail_a;
	}
	if (ht_list->head_b == NULL)
		ht_list->tail_b = NULL;
	update_highest_lowest(ht_list);
	ht_list->length_a++;
	ht_list->length_b--;
	write(1, "pa\n", 3);
}

void	pb(t_ht_list *ht_list)
{
	t_node	*head_a;

	if (ht_list->head_a == NULL)
		return ;
	head_a = ht_list->head_a;
	ht_list->head_a = ht_list->head_a->next;
	if (ht_list->head_a != NULL)
		ht_list->head_a->prev = NULL;
	head_a->next = ht_list->head_b;
	if (ht_list->head_b != NULL)
		ht_list->head_b->prev = head_a;
	ht_list->head_b = head_a;
	head_a->prev = NULL;
	if (ht_list->tail_b == NULL)
	{
		ht_list->tail_b = ht_list->head_b;
		if (ht_list->tail_b->next != NULL)
			ht_list->tail_b->next->prev = ht_list->tail_b;
	}
	if (ht_list->head_a == NULL)
		ht_list->tail_a = NULL;
	update_highest_lowest(ht_list);
	ht_list->length_b++;
	ht_list->length_a--;
	write(1, "pb\n", 3);
}
