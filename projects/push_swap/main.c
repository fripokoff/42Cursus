/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:25:14 by kpires            #+#    #+#             */
/*   Updated: 2024/02/12 09:25:14 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	char			*arg_to_one_string;
	int				test;

	a = NULL;
	if (argc == 1)
		return (1);
	arg_to_one_string = concat_arg(argv, argc, &a);
	argv = ft_split(arg_to_one_string, ' ');
	if (!argv)
		return (0);
	free(arg_to_one_string);
	test = 0;
	while (argv[test])
		printf("%s ", argv[test++]);
	ft_free(argv);
	return (0);
}
