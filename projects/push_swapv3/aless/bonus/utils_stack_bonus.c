/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:43:20 by apintus           #+#    #+#             */
/*   Updated: 2024/02/02 13:13:28 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	stack_len(t_stack_node *stack)
{
	int	len;

	if (!stack)
		return (0);
	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

t_stack_node	*find_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

bool	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack_node	*find_max(t_stack_node *stack)
{
	int				max;
	int				temp;
	t_stack_node	*higher;

	if (!stack)
		return (NULL);
	max = stack->nbr;
	higher = stack;
	stack = stack->next;
	while (stack)
	{
		temp = stack->nbr;
		if (temp > max)
		{
			max = temp;
			higher = stack;
		}
		stack = stack->next;
	}
	return (higher);
}

t_stack_node	*find_min(t_stack_node *stack)
{
	int				min;
	int				temp;
	t_stack_node	*lower;

	if (!stack)
		return (NULL);
	min = stack->nbr;
	lower = stack;
	stack = stack->next;
	while (stack)
	{
		temp = stack->nbr;
		if (temp < min)
		{
			min = temp;
			lower = stack;
		}
		stack = stack->next;
	}
	return (lower);
}
