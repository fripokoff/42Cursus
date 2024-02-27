/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:43:26 by apintus           #+#    #+#             */
/*   Updated: 2024/02/01 14:15:51 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_both_above_median(t_stack_node **a, t_stack_node **b,
			t_stack_node *cheapest)
{
	while ((cheapest->index != 0 && cheapest->target->index != 0))
	{
		rr(a, b, true);
		refresh_index(*a);
		refresh_index(*b);
	}
	if (cheapest->index != 0)
	{
		while (cheapest->index != 0)
		{
			rb(b, true);
			refresh_index(*b);
		}
	}
	else
	{
		while (cheapest->target->index != 0)
		{
			ra(a, true);
			refresh_index(*a);
		}
	}
}

void	move_both_under_median(t_stack_node **a, t_stack_node **b,
			t_stack_node *cheapest)
{
	while ((cheapest->index != 0 && cheapest->target->index != 0))
	{
		rrr(a, b, true);
		refresh_index(*a);
		refresh_index(*b);
	}
	if (cheapest->index != 0)
	{
		while (cheapest->index != 0)
		{
			rrb(b, true);
			refresh_index(*b);
		}
	}
	else
	{
		while (cheapest->target->index != 0)
		{
			rra(a, true);
			refresh_index(*a);
		}
	}
}

void	move_a_above_and_b_below_median(t_stack_node **a, t_stack_node **b,
			t_stack_node *cheapest)
{
	while (cheapest->index != 0)
	{
		rb(b, true);
		refresh_index(*b);
	}
	while (cheapest->target->index != 0)
	{
		rra(a, true);
		refresh_index(*a);
	}
}

void	move_a_below_and_b_above_median(t_stack_node **a, t_stack_node **b,
			t_stack_node *cheapest)
{
	while (cheapest->index != 0)
	{
		rrb(b, true);
		refresh_index(*b);
	}
	while (cheapest->target->index != 0)
	{
		ra(a, true);
		refresh_index(*a);
	}
}
