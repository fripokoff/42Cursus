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

void	print_head_list(t_HTlist *list)
{
	while (list->head_a)
	{
		printf("list:[%d]\n", list->head_a->nbr);
		list->head_a = list->head_a->next;
	}
}

void	print_list(t_HTlist *list, char list_name)
{
	t_node	**head;
	t_node	*current;

	head = get_head(list, list_name);
	current = *head;
	printf("\nList %c: ", list_name);
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
