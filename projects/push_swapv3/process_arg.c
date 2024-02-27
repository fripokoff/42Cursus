/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:13:15 by kpires            #+#    #+#             */
/*   Updated: 2024/02/27 10:13:15 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	len_check_allowed_char(char	*str)
{
	int	i;
	int	only_space;

	i = 0;
	only_space = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9')
			&& str[i] != ' ' && str[i] != '+'
			&& str[i] != '-')
			error("[process_arg.c:27]Error: Invalid character detected."
				"Only digits, '+', '-', ' ' and '0' are allowed.");
		if (str[i] == ' ')
			only_space++;
		i++;
	}
	if (i == only_space)
		error("[process_arg.c:33]Error: Only spaces detected."
			"At least one digit is required.");
	return (i);
}

static int	len_and_check_arg(int ac, char **arg)
{
	int		len;
	int		i;

	len = 0;
	i = 1;
	while (i < ac)
	{
		len += len_check_allowed_char(arg[i]);
		i++;
	}
	return (len);
}

char	*process_arg(int ac, char **arg)
{
	char	*clean;
	int		len;
	int		i;
	int		j;

	len = len_and_check_arg(ac, arg);
	clean = malloc(sizeof(char) * (len + ac));
	if (!clean)
		return (NULL);
	i = 1;
	j = 0;
	while (i < ac)
	{
		while (*arg[i])
			clean[j++] = *arg[i]++;
		clean[j++] = ' ';
		i++;
	}
	clean[j] = '\0';
	return (clean);
}
