/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/02/26 09:12:39 by kpires            #+#    #+#             */
/*   Updated: 2024/02/26 09:12:39 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	free_list(t_HTlist *list)
{
	t_node	*current;
	t_node	*next;

	current = list->head_a;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	list->head_a = NULL;
	list->tail_a = NULL;
	list->length_a = 0;
	free(list);
}

void	error(char *debug, t_HTlist *list)
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
	if (list)
		free_list(list);
	exit(1);
}
