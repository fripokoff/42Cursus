/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:59:54 by apintus           #+#    #+#             */
/*   Updated: 2024/02/01 14:14:47 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	while (stack)
	{
		if (stack->cheapest == true)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	push_a_to_b(t_stack_node **a, t_stack_node **b, int median)
{
	if ((*a)->nbr < median)
		pb(a, b, true);
	else
	{
		pb(a, b, true);
		rb(b, true);
	}
}

void	push_b_to_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	cheapest = get_cheapest(*b);
	while (cheapest->index != 0 || cheapest->target->index != 0)
	{
		if (cheapest->above_median == true
			&& cheapest->target->above_median == true)
			move_both_above_median(a, b, cheapest);
		else if ((cheapest->above_median == false
				&& cheapest->target->above_median == false))
			move_both_under_median(a, b, cheapest);
		else if (((cheapest->above_median == true
					&& cheapest->target->above_median == false)))
			move_a_above_and_b_below_median(a, b, cheapest);
		else
			move_a_below_and_b_above_median(a, b, cheapest);
	}
	pa(b, a, true);
}

void	to_the_top(t_stack_node **a)
{
	t_stack_node	*min;

	min = find_min(*a);
	while (min->index != 0)
	{
		if (min->above_median == true)
		{
			ra(a, true);
			refresh_index(*a);
		}
		else
		{
			rra(a, true);
			refresh_index(*a);
		}
	}
}

void	sort_big(t_stack_node **a, t_stack_node **b)
{
	int	len_a;
	int	median;

	len_a = stack_len(*a);
	median = ((find_min(*a)->nbr + find_max(*a)->nbr) / 2);
	while (len_a-- > 3 && !stack_sorted(*a))
		push_a_to_b(a, b, median);
	sort_three(a);
	while (*b)
	{
		refresh(*a, *b);
		push_b_to_a(a, b);
	}
	refresh_index(*a);
	to_the_top(a);
}
