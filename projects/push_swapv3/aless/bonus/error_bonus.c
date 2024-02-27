/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:17:11 by apintus           #+#    #+#             */
/*   Updated: 2024/02/09 15:44:26 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	error_syntax(char	*str)
{
	if (!((*str == '+') || (*str == '-') || (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+' || *str == '-') && (!(str[1] >= '0' && str[1] <= '9')))
		return (1);
	str++;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
		str++;
	}
	return (0);
}

int	error_duplicate(t_stack_node *a, int nb)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == nb)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_errors_conc(t_stack_node **a, char *combined_arg)
{
	free(combined_arg);
	free_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_errors_init(t_stack_node **a, char **argv)
{
	ft_free(argv);
	free_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}
