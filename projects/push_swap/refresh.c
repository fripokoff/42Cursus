/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:37:43 by kpires            #+#    #+#             */
/*   Updated: 2024/05/30 14:42:39 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	refresh_index(t_ht_list *ht_list, char list)
{
	int	i;
	int	median;
	int len_list;
	t_node	*temp;

	if(list == 'a')
	{
		temp = ht_list->head_a;
		len_list = ht_list->length_a;
	}
	else
	{
		temp = ht_list->head_b;
		len_list = ht_list->length_b;

	}
	i = 0;
	median = len_list / 2;
	while (temp)
	{
		temp->index = i;
		if (i < median)
			temp->above_median = true;
		else
			temp->above_median = false;
		temp = temp->next;
		i++;
	}
}

void	refresh_target(t_ht_list *list)
{
    t_node	*current_a;
    t_node	*target;
    long	best_match;
    t_node	*temp_b = list->head_b;

    while (temp_b)
    {
        best_match = LONG_MAX;
        current_a = list->head_a;
        while (current_a)
        {
            if (current_a->nbr > temp_b->nbr && current_a->nbr < best_match)
            {
                best_match = current_a->nbr;
                target = current_a;
            }
            current_a = current_a->next;
        }
        if (best_match == LONG_MAX)
            temp_b->target = list->lower_a;
        else
            temp_b->target = target;
        temp_b = temp_b->next;
    }
}


static void	cost_b(t_ht_list *list)
{
	t_node	*current_b;

	current_b = list->head_b;
	while (current_b)
	{
		current_b->cost = current_b->index;
		if (!(current_b->above_median))
			current_b->cost = list->length_b - current_b->index;
		if (current_b->target->above_median)
			current_b->cost += current_b->target->index;
		else
			current_b->cost += list->length_a - current_b->target->index;
		current_b = current_b->next;
	}
}

static void	set_cheapest(t_ht_list *ht_list)
{
    int				cheap;
    t_node	*current_cheap;
    t_node  *current_node;  // variable temporaire pour parcourir la liste

    cheap = ht_list->head_b->cost;
    current_cheap = ht_list->head_b;
    current_cheap->cheapest = true;
    current_node = ht_list->head_b->next;  // commencez à parcourir à partir du deuxième nœud
    while (current_node)
    {
        current_node->cheapest = false;
        if (current_node->cost < cheap)
        {
            current_cheap->cheapest = false;
            current_cheap = current_node;
            cheap = current_node->cost;
            current_cheap->cheapest = true;
        }
        current_node = current_node->next;  // passez au nœud suivant
    }
}

void	refresh(t_ht_list *ht_list)
{
	refresh_index(ht_list, 'a');
	refresh_index(ht_list, 'b');
	refresh_target(ht_list);
	cost_b(ht_list);
	set_cheapest(ht_list);
}
