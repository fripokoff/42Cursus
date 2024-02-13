/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:52:57 by kpires            #+#    #+#             */
/*   Updated: 2024/02/13 11:52:57 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	find_space(char const *str)
{
	if (!str)
		return (false);
	while (*str++)
		if (*str != ' ')
			return (false);
	return (true);
}

char	*concat_arg(char **av, int ac, t_stack_node **a)
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
		if (find_space(av[i]))
			return (error_concat(a, arg_to_one_string), NULL);
		ft_strcpy(&arg_to_one_string[current_index], av[i], ' ');
		current_index += (ft_strlen(av[i]) + 1);
	}
	arg_to_one_string[current_index] = '\0';
	return (arg_to_one_string);
}
