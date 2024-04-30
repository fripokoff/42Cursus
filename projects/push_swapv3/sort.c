/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:26:57 by kpires            #+#    #+#             */
/*   Updated: 2024/04/30 13:26:57 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_HTlist *list)
{
	if (list->higher_a == list->head_a)
		ra(list, true);
	else if (list->head_a->next == list->higher_a)
		rra(list, true);
	if (list->head_a->nbr > list->head_a->next->nbr)
		sa(list, true);
}

void	sort(t_HTlist *list)
{
	if (list->length_a == 2)
		sa(list, true);
	else if (list->length_a == 3)
		sort_three(list);
	else
		printf("sort_big\n");
}
