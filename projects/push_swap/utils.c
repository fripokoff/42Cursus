/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:19:58 by kpires            #+#    #+#             */
/*   Updated: 2024/02/19 11:19:58 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(const char *d)
{
	while (*d)
	{
		if (*d != ' ' || *d != '\t' || *d != '\n'
			|| *d != '\v' || *d != '\f' || *d != '\r')
			return (0);
		d++;
	}
	return (1);
}

char	*clean_split(char **av, int ac, t_stack_node **a)
{
	size_t			len;
	size_t			current_index;
	int				i;
	char			*arg_to_one_string;

	i = 0;
	len = 0;
	while (++i < ac)
		len += ft_strlen(av[i]) + 1;
	arg_to_one_string = (char *)malloc(sizeof(char) * (len + 1));
	if (!arg_to_one_string)
		return (NULL);
	current_index = 0;
	i = 0;
	while (++i < ac)
	{
		if (ft_isspace(av[i]))
			return (free_errors_init(a, &arg_to_one_string), NULL);
		ft_strcpy(&arg_to_one_string[current_index], av[i], ' ');
		current_index += (ft_strlen(av[i]) + 1);
	}
	arg_to_one_string[current_index] = '\0';
	return (arg_to_one_string);
}


t_stack_node	*find_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	append_node(t_stack_node **stack, int value)
{
	t_stack_node	*new_node;
	t_stack_node	*current;

	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
	new_node->nbr = value;
	new_node->next = NULL;
	if (*stack == NULL)
		*stack = new_node;
	else
	{
		current = *stack;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
}