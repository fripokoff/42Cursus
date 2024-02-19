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

static char	*concat_arg(char **av, int ac, t_stack_node **a)
{
	size_t			len;
	size_t			current_index;
	int				i;
	char			*arg_to_one_string;

	i = 0;
	len = 0;
	while (++i < ac)
		len += ft_strlen(av[i]) + 1;
	arg_to_one_string = (char *)malloc(sizeof(char) * (len + 1));
	if (!arg_to_one_string)
		return (NULL);
	current_index = 0;
	i = 0;
	while (++i < ac)
	{
		if (ft_isspace('\0', av[i]))
			return (free_errors_init(a, &arg_to_one_string), NULL);
		ft_strcpy(&arg_to_one_string[current_index], av[i], ' ');
		current_index += (ft_strlen(av[i]) + 1);
	}
	arg_to_one_string[current_index] = '\0';
	return (arg_to_one_string);
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	char			*arg_to_one_string;

	a = NULL;
	if (ac == 1)
		return (1);
	arg_to_one_string = concat_arg(av, ac, &a);
	av = ft_split(arg_to_one_string, ' ');
	if (!av)
		return (0);
	free(arg_to_one_string);
	init_stack_a(&a, av);
	while (a)
	{
		printf("%d ", a->nbr);
		a = a->next;
	}
	ft_free(av);
	return (0);
}
