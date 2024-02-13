/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:42:49 by apintus           #+#    #+#             */
/*   Updated: 2024/02/13 11:43:04 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			*one_arg;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	one_arg = concatenate_arg(argv, argc, &a);
	argv = ft_split(one_arg, ' ');
	if (!argv)
		return (0);
	free(one_arg);
	init_stack_a(&a, argv);
	ft_free(argv);
	if (!stack_sorted(a))
		sort(&a, &b);
	free_stack(&a);
}
