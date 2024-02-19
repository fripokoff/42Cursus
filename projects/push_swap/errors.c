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

void	free_list(t_stack_node **stack)
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

void	free_errors_init(t_stack_node **a, char **argv)
{
	ft_free(argv);
	free_list(a);
	error();
	exit(1);
}

int	error_duplicate(t_stack_node *a, int nb)
{
	if (!a)
		return (0);
	while (a)
	{
		printf("a->nbr : %d\n", a->nbr);
		if (a->nbr == nb)
			return (1);
		a = a->next;
	}
	return (0);
}
