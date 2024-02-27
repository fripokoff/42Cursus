/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:12:39 by kpires            #+#    #+#             */
/*   Updated: 2024/02/26 09:12:39 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(char *debug)
{
	bool	enable_debug;

	enable_debug = true;
	if (enable_debug)
	{
		printf("\033[1;31m");
		printf("%s\n", debug);
		printf("\033[0m");
	}
	else
		printf("Error\n");
	exit(1);
}

void	free_double_char(char **str)
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
