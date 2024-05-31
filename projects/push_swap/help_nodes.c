/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 09:49:11 by kpires            #+#    #+#             */
/*   Updated: 2024/04/29 09:49:11 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_head_list(t_ht_list *ht_list)
{
	while (ht_list->head_a)
	{
		printf("ht_list:[%d]\n", ht_list->head_a->nbr);
		ht_list->head_a = ht_list->head_a->next;
	}
}

void	print_list(t_ht_list *ht_list, char list)
{
	t_node	*head;
	t_node	*current;

	head = get_head(ht_list, list);
	current = head;
	printf("\nList %c:\n", list);
	while (current != NULL)
	{
		printf("%d \n", current->nbr);
		current = current->next;
	}
	printf("\n");
}

void	print_node(t_node *node)
{
	while (node)
	{
		printf("node:[%d]\n", node->nbr);
		node = node->next;
	}
}

void	print_for_test(t_ht_list *ht_list)
{
	if (ht_list->head_a)
		print_list(ht_list, 'a');
	// if (ht_list->length_a)
	// 	printf("[LENGTH A]: %d\n", ht_list->length_a);
	// if (ht_list->higher_a)
	// 	printf("[HIGHER A]: %d\n", ht_list->higher_a->nbr);
	// if (ht_list->lower_a)
	// 	printf("[LOWER A]: %d\n", ht_list->lower_a->nbr);
	if (ht_list->head_b)
		print_list(ht_list, 'b');
	// if (ht_list->length_b)
	// 	printf("[LENGTH B]: %d\n", ht_list->length_b);
	// if (ht_list->higher_b)
	// 	printf("[HIGHER B]: %d\n", ht_list->higher_b->nbr);
	// if (ht_list->lower_b)
	// 	printf("[LOWER B]: %d\n", ht_list->lower_b->nbr);
}