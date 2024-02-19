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

void	init_stack_a(t_stack_node **a, char **av)
{
	int		i;
	long	nb;

	i = 0;
	while (av[i])
	{
		nb = check_syntax_and_atoi(av[i]);
		if (!nb)
			free_errors_init(a, av);
		if (nb > INT_MAX || nb < INT_MIN)
			free_errors_init(a, av);
		if (error_duplicate(*a, (int)nb))
			free_errors_init(a, av);
		i++;
	}
}
