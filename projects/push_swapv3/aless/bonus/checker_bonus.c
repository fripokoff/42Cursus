/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:46:56 by apintus           #+#    #+#             */
/*   Updated: 2024/02/09 16:58:45 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*c1;
	unsigned char	*c2;
	size_t			i;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	i = 0;
	while (c1[i] == c2[i] && c1[i] != '\0' && c2[i] != '\0')
		i++;
	return (c1[i] - c2[i]);
}

int	parse(int argc, char **argv, t_stack_node **a)
{
	char	*one_arg;

	one_arg = concatenate_arg(argv, argc, a);
	argv = ft_split(one_arg, ' ');
	if (!argv)
		return (0);
	free(one_arg);
	init_stack_a(a, argv);
	ft_free(argv);
	return (1);
}

int	check_move(char *line, t_stack_node **a, t_stack_node **b)
{
	if (ft_strcmp(line, "pa\n") == 0)
		return (pa(b, a, false), 0);
	else if (ft_strcmp(line, "pb\n") == 0)
		return (pb(a, b, false), 0);
	else if (ft_strcmp(line, "sa\n") == 0)
		return (sa(a, false), 0);
	else if (ft_strcmp(line, "sb\n") == 0)
		return (sb(b, false), 0);
	else if (ft_strcmp(line, "ss\n") == 0)
		return (ss(a, b, false), 0);
	else if (ft_strcmp(line, "ra\n") == 0)
		return (ra(a, false), 0);
	else if (ft_strcmp(line, "rb\n") == 0)
		return (rb(b, false), 0);
	else if (ft_strcmp(line, "rr\n") == 0)
		return (rr(a, b, false), 0);
	else if (ft_strcmp(line, "rra\n") == 0)
		return (rra(a, false), 0);
	else if (ft_strcmp(line, "rrb\n") == 0)
		return (rrb(b, false), 0);
	else if (ft_strcmp(line, "rrr\n") == 0)
		return (rrr(a, b, false), 0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			*line;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	if (!parse(argc, argv, &a))
		return (free_stack(&a), free_stack(&b), write(2, "Error\n", 6));
	while (1)
	{
		line = get_next_line(0, 0);
		if (!line)
			break ;
		if (check_move(line, &a, &b))
			return (free_stack(&a), free_stack(&b), free(line)
				, get_next_line(0, 1), write(2, "Error\n", 6));
		free (line);
	}
	if (stack_sorted(a) && stack_len(b) == 0)
		return (free_stack(&a), free_stack(&b), ft_printf("OK\n"));
	else
		return (free_stack(&a), free_stack(&b), ft_printf("KO\n"));
}
