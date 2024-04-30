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

void	swap(t_HTlist *list, char list_name)
{
	t_node	**head;
	t_node	*first;
	t_node	*second;

	head = get_head(list, list_name);
	if (!*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*head = second;
}

void	sa(t_HTlist	*list, bool	print)
{
	swap(list, 'a');
	if (print)
		printf("sa\n");
}

void	sb(t_HTlist	*list, bool	print)
{
	swap(list, 'b');
	if (print)
		printf("sb\n");
}

void	ss(t_HTlist *list, bool print)
{
	sa(list, false);
	sb(list, false);
	if (print)
		printf("ss\n");
}
