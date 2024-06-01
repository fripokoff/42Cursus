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

void	free_list(t_ht_list *ht_list)
{
	t_node	*current;
	t_node	*next;

	current = ht_list->head_a;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	ht_list->head_a = NULL;
	ht_list->tail_a = NULL;
	ht_list->length_a = 0;
	free(ht_list);
}

void	error(t_ht_list *ht_list)
{
	ft_putstr_fd("Error\n", 2);
	if (ht_list)
		free_list(ht_list);
	exit(1);
}
