/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:32:36 by kpires            #+#    #+#             */
/*   Updated: 2024/02/27 14:32:36 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_double_char(char **str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		free(str[j]);
		j++;
	}
	free(str);
}

// static	void print_list(x_list *list)
// {
// 	while (list->heap)
// 	{
// 		printf("list:[%d]\n", list->heap->nbr);
// 		list->heap = list->heap->next;
// 	}
// }

void print_node(t_node *node)
{
	while (node)
	{
		printf("node:[%d]\n", node->nbr);
		node = node->next;
	}
}



static t_node *append_node(int value, x_list *list)
{
	t_node		*new;

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
	char	**splitted;
	int		i;
	int		check_limits;

	splitted = ft_split(arg_processed, ' ');
	i = 0;
	check_limits = 0;
	while (splitted[i])
	{
		append_node(ft_atoi(splitted[i], &check_limits), list);
		if (check_limits)
			error("[init_node.c:29]Error: Numeric value"
				" is out of range or contains invalid characters.");
		i++;
	}
	free_double_char(splitted);
}
