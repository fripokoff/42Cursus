/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:32:36 by kpires            #+#    #+#             */
/*   Updated: 2024/02/27 14:32:36 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_double_char(char **str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		free(str[j]);
		j++;
	}
	free(str);
}

void	init_node(t_node *a, char *arg_processed)
{
	char	**splitted;
	int		i;
	int		check_limits;

	splitted = ft_split(arg_processed, ' ');
	i = 0;
	check_limits = 0;
	while (splitted[i])
	{
		printf("[%d]\n", ft_atoi(splitted[i], &check_limits));
		if (check_limits)
			error("[init_node.c:29]Error: Numeric value"
				" is out of range or contains invalid characters.");
		i++;
	}
	free_double_char(splitted);
	(void)a;
}
