/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:15:18 by kpires            #+#    #+#             */
/*   Updated: 2024/02/28 13:15:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static	void print_list(x_list *list)
// {
// 	while (list->heap)
// 	{
// 		printf("list:[%d]\n", list->heap->nbr);
// 		list->heap = list->heap->next;
// 	}
// }

void	print_node(t_node *node)
{
	while (node)
	{
		printf("node:[%d]\n", node->nbr);
		node = node->next;
	}
}

static t_node	*append_node(int value, x_list *list)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->nbr = value;
	new->next = NULL;
	new->prev = list->tail;
	if (list->heap == NULL)
	{
		list->heap = new;
		list->tail = new;
	}
	else
	{
		list->tail->next = new;
		list->tail = new;
	}
	return (new);
}

void	init_node(char *arg_processed, x_list *list)
{
	char	**arg_split;
	int		i;
	int		check_limits;
	int		nbr;

	arg_split = ft_split(arg_processed, ' ');
	free(arg_processed);
	i = 0;
	check_limits = 0;
	while (arg_split[i])
	{
		nbr = ft_atoi(arg_split[i], &check_limits);
		if (list->tail)
			if (nbr == list->tail->nbr)
			{
				free_double_char(arg_split);
				error("[init_node.c:86]Error: Duplicate value"
					" found during phase 1 of 2.", list);
			}
		append_node(nbr, list);
		if (check_limits)
		{
			free_double_char(arg_split);
			error("[init_node.c:90]Error: Numeric value"
				" is out of range or contains invalid characters.", list);
		}
		i++;
	}
	free_double_char(arg_split);
}
