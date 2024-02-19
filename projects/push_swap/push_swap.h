/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:16:45 by kpires            #+#    #+#             */
/*   Updated: 2024/02/13 10:16:45 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target;
	struct s_stack_node	*next;
	struct s_stack_node	*previous;

}	t_stack_node;

//INIT
void	init_stack_a(t_stack_node **a, char **av);

//ERRORS
void	error(void);
int		error_duplicate(t_stack_node *a, int nb);

//MEMORY
void	free_list(t_stack_node **stack);
void	free_errors_init(t_stack_node **a, char **argv);

//UTILS
int		ft_isspace(char c, const char *d);
long	check_syntax_and_atoi(char *str);

#endif