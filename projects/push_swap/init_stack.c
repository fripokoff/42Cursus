/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:01:34 by kpires            #+#    #+#             */
/*   Updated: 2024/02/19 11:01:34 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	append_node(t_stack_node **stack, int value)
{
	t_stack_node	*new;
	t_stack_node	*last;

	if (!stack)
		return ;
	new = malloc(sizeof(t_stack_node));
	if (!new)
		return ;
	new->nbr = value;
	new->next = NULL;
	if (!*stack)
	{
		*stack = new;
	}
	else
	{
		last = find_last(*stack);
		last->next = new;
		new->previous = last;
	}

}

void	init_stack_a(t_stack_node **a, char **av)
{
	int		i;
	long	nb;
	int		check_limits;

	i = 0;
	check_limits = 0;
	while (av[i])
	{
		if (error_syntax(av[i]))
			free_errors_init(a, av);
		nb = ft_atoi(av[i], &check_limits);
		if (check_limits)
			free_errors_init(a, av);
		if (error_duplicate(*a, (int)nb))
			free_errors_init(a, av);
		append_node(a, (int)nb);
		i++;
	}
}
