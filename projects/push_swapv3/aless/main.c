/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:42:49 by apintus           #+#    #+#             */
/*   Updated: 2024/05/01 15:11:01 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static	void print_node(t_stack_node *node)
{
	while (node)
	{
		printf("node:[%d]", node->nbr);
		node = node->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			*one_arg;
	int				i;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	one_arg = concatenate_arg(argv, argc, &a);
	argv = ft_split(one_arg, ' ');
	i = 0;
	while (argv[i])
	{
		printf("[%s]", argv[i]);
		i++;
	}
	if (!argv)
		return (0);
	free(one_arg);
	init_stack_a(&a, argv);
	ft_free(argv);
	if (!stack_sorted(a))
		sort(&a, &b);
	sa(&a,true);
	// printf("\n");
	// print_node(b);
	printf("\n");
	print_node(a);
	free_stack(&a);
}
