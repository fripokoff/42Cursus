/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 07:34:35 by kpires            #+#    #+#             */
/*   Updated: 2024/02/26 07:34:35 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char		*arg_processed;
	t_node		*a;

	if (ac == 1)
		return (1);
	a = NULL;
	arg_processed = process_arg(ac, av);
	init_node(a, arg_processed);
	free(arg_processed);
	return (0);
}
