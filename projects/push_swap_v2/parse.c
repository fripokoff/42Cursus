/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:08:56 by kpires            #+#    #+#             */
/*   Updated: 2024/02/25 15:08:56 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*flatten_array(int **table_int)
{
	int	*arr;
	int	i;
	int	j;
	int	k;
	int	len;

	len = count_table_total_int(table_int);
	arr = malloc(sizeof(int) * (len));
	if (!arr)
		return (NULL);
	i = 0;
	k = 0;
	while (table_int[i])
	{
		j = 0;
		while (table_int[i][j])
		{
			arr[k] = table_int[i][j];
			j++;
			k++;
		}
		i++;
	}
	arr[len] = '\0';
	display_table_int(arr);
	return (arr);
}

int	*flatten_str_to_int(char **strings, int ac)
{
	int		**table_int;
	char	**split_values;
	int		i;
	int		j;
	int		check_limits;

	i = 0;
	j = 0;
	check_limits = 0;
	table_int = malloc(sizeof(int *) * (ac));
	while (strings[i + 1])
	{
		split_values = ft_split(strings[i+1], ' ');
		const int size_of_split_values = count_table_rows_str(split_values);
		table_int[i] = malloc(sizeof(int) * (size_of_split_values + 1));
		j = 0;
		while (split_values[j])
		{
			table_int[i][j] = ft_atoi(split_values[j], &check_limits);
			if (check_limits)
			{
				// free_table_str(split_values);
				// free_table_int(table_int);
				error();
			}
			j++;
		}
		table_int[i][j] = '\0';
		// free_table_str(split_values);
		i++;
	}
	table_int[i] = '\0';
	return (flatten_array(table_int));
}
