/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 09:21:04 by kpires            #+#    #+#             */
/*   Updated: 2024/02/13 09:21:04 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
}

void	*ft_free(char **strs)
{
	char **temp = strs;

	while (*temp != NULL)
		free(*temp++);
	free(strs);
	return (NULL);
}

static void	free_list(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	error_concat(t_stack_node **a, char *comb_arg)
{
	free(comb_arg);
	free_list(a);
	error();
	exit(1);
}
