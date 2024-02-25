/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:58:22 by kpires            #+#    #+#             */
/*   Updated: 2024/02/25 14:58:22 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 1) parse arguments
// 2) initialize list(s)
// 3) run algorithm & output at the same time

int	main(int ac, char **av)
{
	int	*arr;
	t_linked_list	*list;

	if (ac == 1)
		return (0);
	arr = flatten_str_to_int(av,ac);
	print_array_int(arr);
	list = initialize_list(arr);
	// if (!list)
	// 	error();
	// print_list(list);
	return (0);
}
