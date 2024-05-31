/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:15:18 by kpires            #+#    #+#             */
/*   Updated: 2024/02/28 13:15:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*append_node(int value, t_ht_list *ht_list)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->nbr = value;
	new->next = NULL;
	new->prev = ht_list->tail_a;
	if (ht_list->head_a == NULL)
	{
		ht_list->head_a = new;
		ht_list->tail_a = new;
		ht_list->higher_a = new;
		ht_list->lower_a = new;
		ht_list->length_a++;
	}
	else
	{
		ht_list->tail_a->next = new;
		ht_list->tail_a = new;
		ht_list->length_a++;
	}
	return (new);
}

static char	*_check_duplicates(int nbr, t_ht_list *ht_list, char	**arg_split)
{
	t_node	*current;
	t_node	*next;

	current = ht_list->head_a;
	while (current != NULL)
	{
		next = current->next;
		if (nbr == current->nbr)
		{
			free_double_char(arg_split);
			error("[init_node.c:54]Error: Duplicate value"
				" found during phase 1 of 2.", ht_list);
		}
		current = next;
	}
	return (NULL);
}

static void	_check_limits(int err, t_ht_list *ht_list, char	**arg_split)
{
	int	i;
	int	j;

	i = 0;
	while (arg_split[i])
	{
		j = 0;
		while (arg_split[i][j] == '0' || arg_split[i][j] == '+'
				|| arg_split[i][j] == '-')
			j++;
		if (err || ft_strlen(&arg_split[i][j]) > 11)
		{
			free_double_char(arg_split);
			error("[init_node.c:77]Error: Numeric value"
				" is out of range or contains invalid characters.", ht_list);
		}
		i++;
	}
}

static void	set_higher_lower(t_ht_list *ht_list, int nbr)
{
	if (nbr > ht_list->higher_a->nbr)
	{
		ht_list->higher_a = ht_list->tail_a;
		ht_list->higher_a->nbr = nbr;
	}
	if (nbr < ht_list->lower_a->nbr)
	{
		ht_list->lower_a = ht_list->tail_a;
		ht_list->lower_a->nbr = nbr;
	}
}

void	init_node(char *arg_processed, t_ht_list *ht_list)
{
	char	**arg_split;
	int		i;
	int		err;
	int		nbr;

	arg_split = ft_split(arg_processed, ' ');
	free(arg_processed);
	i = 0;
	err = 0;
	_check_limits(err, ht_list, arg_split);
	while (arg_split[i])
	{
		nbr = ft_atoi(arg_split[i++], &err);
		_check_duplicates(nbr, ht_list, arg_split);
		append_node(nbr, ht_list);
		if (err)
			error("[init_node.c:97]Error: Numeric value", ht_list);
		set_higher_lower(ht_list, nbr);
	}
	free_double_char(arg_split);
}
