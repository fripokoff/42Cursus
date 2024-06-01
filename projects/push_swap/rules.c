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
	t_node	*temp;

	head = get_head(ht_list, list);
	tail = get_tail(ht_list, list);
	if (!head || !head->next || !tail)
		return ;
	temp = tail;
	tail = tail->prev;
	if (tail)
		tail->next = NULL;
	temp->next = head;
	head->prev = temp;
	head = temp;
	update_headtail(ht_list, head, tail, list);
	if (list == 'a')
		printf("rra\n");
	else if (list == 'b')
		printf("rrb\n");
}

void	swap(t_ht_list *ht_list, char list)
{
	t_node	*head;
	t_node	*tail;
	int		temp_nbr;

	head = get_head(ht_list, list);
	tail = get_tail(ht_list, list);
	if (!head || !head->next)
		return ;
	temp_nbr = head->nbr;
	head->nbr = head->next->nbr;
	head->next->nbr = temp_nbr;
	update_headtail(ht_list, head, tail, list);
	if (list == 'a')
		printf("sa\n");
	else if (list == 'b')
		printf("sb\n");
}

void	rotate(t_ht_list *ht_list, char list)
{
	t_node	*head;
	t_node	*tail;
	t_node	*temp;

	head = get_head(ht_list, list);
	tail = get_tail(ht_list, list);
	if (!head || !tail || !head->next)
		return ;
	temp = head;
	head = temp->next;
	head->prev = NULL;
	temp->prev = tail;
	temp->next = NULL;
	tail->next = temp;
	tail = temp;
	update_headtail(ht_list, head, tail, list);
	if (list == 'a')
		printf("ra\n");
	else if (list == 'b')
		printf("rb\n");
}

void	pa(t_ht_list *ht_list)
{
	t_node	*temp;

	if (ht_list->head_b == NULL)
		return ;
	temp = ht_list->head_b;
	ht_list->head_b = ht_list->head_b->next;
	if (ht_list->head_b != NULL)
		ht_list->head_b->prev = NULL;
	temp->next = ht_list->head_a;
	if (ht_list->head_a != NULL)
		ht_list->head_a->prev = temp;
	ht_list->head_a = temp;
	temp->prev = NULL;
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
	printf("pa\n");
}

void	pb(t_ht_list *ht_list)
{
	t_node	*temp;

	if (ht_list->head_a == NULL)
		return ;
	temp = ht_list->head_a;
	ht_list->head_a = ht_list->head_a->next;
	if (ht_list->head_a != NULL)
		ht_list->head_a->prev = NULL;
	temp->next = ht_list->head_b;
	if (ht_list->head_b != NULL)
		ht_list->head_b->prev = temp;
	ht_list->head_b = temp;
	temp->prev = NULL;
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
	printf("pb\n");
}
