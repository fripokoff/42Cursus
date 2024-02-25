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

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*tmp;
	
	char			*cleaned_str;

	a = NULL;
	if (ac == 1)
		return (1);
	cleaned_str = clean_split(av, ac, &a);
	av = ft_split(cleaned_str, ' ');
	if (!av)
		return (0);
	free(cleaned_str);
	init_stack_a(&a, av);
	tmp = a;
	printf("STACK A\n");
	while(tmp)
	{
		printf("[%d]", tmp->nbr);
		tmp = tmp->next;
	}
	if (!(is_sorted(&a)))
	{
		printf("[NOT SORTED]\n");
	}
	free_list(&a);
	ft_free(av);
	return (0);
}
	