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
	t_node	**head;
	t_node	*current;

	head = get_head(ht_list, list);
	current = *head;
	printf("\nList %c:\n", list);
	while (current != NULL)
	{
		printf("%d ", current->nbr);
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
