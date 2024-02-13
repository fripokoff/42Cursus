/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:34:38 by apintus           #+#    #+#             */
/*   Updated: 2024/02/02 12:08:00 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	push(t_stack_node **src, t_stack_node **dest)
{
	t_stack_node	*push_node;

	if (!src)
		return ;
	push_node = (*src);
	(*src) = (*src)->next;
	if (*src)
		(*src)->previous = NULL;
	if (!*dest)
	{
		*dest = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dest;
		push_node->next->previous = push_node;
		*dest = push_node;
	}
}

void	pa(t_stack_node **b, t_stack_node**a, bool print)
{
	push(b, a);
	if (print)
		ft_printf("pa\n");
}

void	pb(t_stack_node **a, t_stack_node**b, bool print)
{
	push(a, b);
	if (print)
		ft_printf("pb\n");
}
