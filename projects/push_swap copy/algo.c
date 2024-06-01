/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 22:20:01 by kpires            #+#    #+#             */
/*   Updated: 2024/05/31 22:20:01 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	while_for_norm(t_ht_list *ht_list, int *arr, int length_a, int range)
{
	int		i;
	int		nbr;

	i = 0;
	while (ht_list->head_a)
	{
		nbr = ht_list->head_a->nbr;
		if (range + i >= length_a)
			range = length_a - 1 - i;
		else if ((nbr > arr[i] && nbr <= arr[range + i]) || nbr <= arr[i])
		{
			pb(ht_list);
			if (nbr <= arr[i])
				rotate(ht_list, 'b');
			else
				if (ht_list->length_b >= 2
					&& ht_list->head_b->nbr < ht_list->head_b->next->nbr)
					swap(ht_list, 'b');
			i++;
		}
		else
			is_reversed(ht_list);
	}
}

int	*sort_int_tab(int *tab, int size)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	j = 0;
	if (size <= 1)
		return (0);
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (tab[j] > tab[i])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}
