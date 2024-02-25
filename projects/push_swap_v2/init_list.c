/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 22:02:52 by kpires            #+#    #+#             */
/*   Updated: 2024/02/25 22:02:52 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_linked_list	*create_linked_list()
{
	t_linked_list *list;

	list = malloc(sizeof(t_linked_list));
	if (!list)
		return (NULL);
	list->length = 0;
	list->head = NULL;
	list->tail = NULL;
	return list;
}

static t_node	*create_node(int nbr, t_node *previous, t_node *next)
{
	t_node *node;
	
	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->nbr = nbr;
	node->previous = previous;
	node->next = next;
	return node;
}

static t_node	*append_to_list(t_linked_list *list, int nbr)
{
	t_node *new_node;

	new_node = create_node(nbr, list->tail, NULL);
	if (!new_node)
		return (NULL);
	if (!list->head)
		list->head = new_node;
	if (list->tail)
		list->tail->next = new_node;
	list->tail = new_node;
	list->length++;
	return (new_node);
}

t_linked_list	*initialize_list(int *values)
{
	int i = 0;
	t_linked_list *list;
	
	list = create_linked_list();
	while (values[i])
	{
		if (!append_to_list(list, values[i]))
		 	return (NULL);
		i++;
	}
	return list;
}
