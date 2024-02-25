/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 21:37:43 by kpires            #+#    #+#             */
/*   Updated: 2024/02/25 21:37:43 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_table_int(int **table)
{
	int i = 0;

	while (table[i])
	{
		free(table[i]);
		i++;
	}
	free(table);
}

void free_table_str(char **table)
{
	int i = 0;

	while (table[i])
	{
		free(table[i]);
		i++;
	}
	free(table);
}

void     display_table_int(int **arr)
{
    int     i = 0;
    int     j = 0;

    printf("display table:\n[\n");
    while (arr[i])
    {
        printf("[ ");
		j = 0;
        while (arr[i][j])
        {
            printf("%i, ", arr[i][j]);
            j++;
        }
        i++;
        printf(" ]\n");
    }
    printf("]\n");
}

int count_table_total_int(int **table)
{
    int     i = 0;
    int     j = 0;
    int     sum = 0;

    while (table[i])
    {
		j = 0;
        while (table[i][j])
        {
            sum++;
            j++;
        }
        i++;
    }
    return sum;
}

int count_table_rows_str(char **table)
{
    int i = 0;
    
    while (table[i])
        i++;
    return i;
}

int print_array_int(int  *arr)
{
    int i = 0;

    printf("print array int \n [");
    while (i < 20)
    {
        printf("%d, ", arr[i]);
        i++;
    }
    printf("]\n");
}