/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 22:20:29 by kpires            #+#    #+#             */
/*   Updated: 2024/05/31 22:20:29 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_reverse(t_ht_list *ht_list)
{
	t_node	*tmp;
	int		i;
	int		size;

	tmp = ht_list->head_a;
	i = 1;
	size = ht_list->length_a;
	while (tmp && i != size)
	{
		if (tmp->nbr > tmp->next->nbr)
			i++;
		tmp = tmp->next;
		if (!tmp->next)
			break ;
	}
	if (i == size)
		return (1);
	return (0);
}

void	is_reversed(t_ht_list *ht_list)
{
	if (check_reverse(ht_list) == 1)
		reverse_rotate(ht_list, 'a');
	else
		rotate(ht_list, 'a');
}

bool	check_is_sort(t_node *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->nbr > a->next->nbr)
			return (false);
		a = a->next;
	}
	return (true);
}

int	get_range(t_ht_list *ht_list)
{
	int	length_a;

	length_a = ht_list->length_a;
	if (length_a >= 6 && length_a <= 16)
		return (3);
	else if (length_a <= 100)
		return (13);
	else if (length_a <= 500)
		return (30);
	else
		return (45);
}

int	*copy_arr(t_ht_list *ht_list)
{
	t_node	*tmp;
	int		*arr;
	int		i;

	i = 0;
	arr = malloc(sizeof(int) * ht_list->length_a);
	tmp = ht_list->head_a;
	while (tmp)
	{
		arr[i] = tmp->nbr;
		tmp = tmp->next;
		i++;
	}
	return (arr);
}
