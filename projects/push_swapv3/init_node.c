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

static t_node	*append_node(int value, t_HTlist *list)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->nbr = value;
	new->next = NULL;
	new->prev = list->tail_a;
	if (list->head_a == NULL)
	{
		list->head_a = new;
		list->tail_a = new;
		list->higher_a = new;
		list->length_a++;
	}
	else
	{
		list->tail_a->next = new;
		list->tail_a = new;
		list->length_a++;
	}
	return (new);
}

static char	*_check_duplicates(int nbr, t_HTlist *list, char	**arg_split)
{
	t_node	*current;
	t_node	*next;

	current = list->head_a;
	while (current != NULL)
	{
		next = current->next;
		if (nbr == current->nbr)
		{
			free_double_char(arg_split);
			error("[init_node.c:86]Error: Duplicate value"
				" found during phase 1 of 2.", list);
		}
		current = next;
	}
	return (NULL);
}

static char	*_check_limits(char *str, int err, t_HTlist *list, char	**arg_split)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[0] == '0' && str[1] && str[1] == '0')
			if (str[i] == '0')
				i++;
		i++;
	}
	str += i;
	if (err || ft_strlen(str) > 11)
	{
		free_double_char(arg_split);
		error("[init_node.c:90]Error: Numeric value"
			" is out of range or contains invalid characters.", list);
	}
	return (NULL);
}

// static int check_long_long(char *str)
// {
// 	int	i;
// 	int	count;

// 	count = 0;
// 	i=0;
// 	printf("str %s\n ", str);
// 	while(str[i])
// 	{
// 		if(str[i] == '+' || str[i] == '-')
// 			i++;
// 		else if(str[0] == '0' && str[i] == '0')
// 			printf("0 if ");
// 		else
// 			count++;
// 		i++;
// 	}
// 	return (count > 11);
// }


void	init_node(char *arg_processed, t_HTlist *list)
{
	char	**arg_split;
	int		i;
	int		err;
	int		nbr;

	arg_split = ft_split(arg_processed, ' ');
	free(arg_processed);
	i = 0;
	err = 0;
	while (arg_split[i])
	{
			// if(check_long_long(arg_split[i]))
			// error("[process_arg.c:27]Error: Len check check long.",
			// 	false);
		nbr = ft_atoi(arg_split[i], &err);
		_check_limits(arg_split[i], err, list, arg_split);
		_check_duplicates(nbr, list, arg_split);
		append_node(nbr, list);
		if (list->higher_a && nbr > list->higher_a->nbr)
		{
			list->higher_a = list->tail_a;
		}
		i++;
	}
	free_double_char(arg_split);
}
