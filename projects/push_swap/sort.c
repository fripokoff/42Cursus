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

static void	sort_three(t_ht_list *ht_list)
{
	if (ht_list->higher_a == ht_list->head_a)
		ra(ht_list, true);
	else if (ht_list->head_a->next == ht_list->higher_a)
		reverse_rotate(ht_list, 'a');
	if (ht_list->head_a->nbr > ht_list->head_a->next->nbr)
		sa(ht_list, true);
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

static void	max_util(t_ht_list *ht_list, int temp, int nb)
{
	if (temp != 0)
	{
		if (temp <= (ht_list->length_b / 2))
		{
			while (ht_list->head_b->nbr != nb)
				rb(ht_list, true);
		}
		else
		{
			while (ht_list->head_b->nbr != nb)
				reverse_rotate(ht_list, 'b');
		}
	}
}

static void	push_max(t_ht_list *ht_list)
{
	t_node	*tmp;
	int		temp;
	int		nb;
	int		i;

	tmp = ht_list->head_b;
	i = 0;
	nb = tmp->nbr;
	temp = 0;
	while (tmp)
	{
		if (nb < tmp->nbr)
		{
			nb = tmp->nbr;
			temp = i;
		}
		i++;
		tmp = tmp->next;
	}
	max_util(ht_list, temp, nb);
	pa(ht_list, true);
}


static int	get_range(t_ht_list *ht_list)
{
	int	range;

	range = ht_list->length_a;
	if (6 <= range && range <= 16)
		return (3);
	else if (range <= 100)
		return (13);
	else if (range <= 500)
		return (30);
	else
		return (45);
}

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

static void	is_reversed(t_ht_list *ht_list)
{
	if (check_reverse(ht_list) == 1)
		reverse_rotate(ht_list, 'a');
	else
		ra(ht_list, true);
}

static void	while_for_norm(t_ht_list *ht_list, int *arr, int num)
{
	int	i;
	int	range;

	i = 0;
	range = get_range(ht_list);
	while (ht_list->head_a)
	{
		if (range + i >= num)
			range = num - 1 - i;
		else if (ht_list->head_a->nbr > arr[i] && ht_list->head_a->nbr <= arr[range + i])
		{
			pb(ht_list, true);
			if (ht_list->length_b >= 2 && ht_list->head_b->nbr < ht_list->head_b->next->nbr)
				sb(ht_list, true);
			i++;
		}
		else if (ht_list->head_a->nbr <= arr[i])
		{
			pb(ht_list, true);
			rb(ht_list, true);
			i++;
		}
		else
			is_reversed(ht_list);
	}
}

/* bubble sort*/
static int	*sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	if (size <= 1)
		return (0);
	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

static int	*copy_arr(t_ht_list *ht_list)
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


static void	sort_big(t_ht_list *ht_list)
{
	int	*arr;

	arr = sort_int_tab(copy_arr(ht_list), ht_list->length_a);
	arr = arr;
	while_for_norm(ht_list, arr, ht_list->length_a);
	free(arr);
	while (ht_list->head_b)
		push_max(ht_list);
}


void	sort(t_ht_list *ht_list)
{
	if (ht_list->length_a == 2)
		sa(ht_list, true);
	else if (ht_list->length_a == 3)
		sort_three(ht_list);
	else
		sort_big(ht_list);
}
