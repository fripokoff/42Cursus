/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:13:58 by kpires            #+#    #+#             */
/*   Updated: 2024/02/25 14:13:58 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool    is_sorted(t_stack_node **stack)
{
    t_stack_node *curr;

    curr = *stack;
    while (curr->next != NULL)
    {
        if (curr->nbr > curr->next->nbr)
            return (false);
        curr = curr->next;
    }
    return (true);
}

// void    lets_sort(t_stack_node **a, t_stack_node **b)
// {

// }