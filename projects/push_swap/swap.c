/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:09:43 by kpires            #+#    #+#             */
/*   Updated: 2024/04/30 14:09:43 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_ht_list *ht_list, char list)
{
	t_node	**head;
	int		temp_nbr;

	head = get_head(ht_list, list);
	if (!(*head) || !(*head)->next)
		return ;
	temp_nbr = (*head)->nbr;
	(*head)->nbr = (*head)->next->nbr;
	(*head)->next->nbr = temp_nbr;
}

void	sa(t_ht_list	*ht_list, bool	print)
{
	swap(ht_list, 'a');
	if (print)
		printf("sa\n");
}

void	sb(t_ht_list	*ht_list, bool	print)
{
	swap(ht_list, 'b');
	if (print)
		printf("sb\n");
}

void	ss(t_ht_list *ht_list, bool print)
{
	sa(ht_list, false);
	sb(ht_list, false);
	if (print)
		printf("ss\n");
}
