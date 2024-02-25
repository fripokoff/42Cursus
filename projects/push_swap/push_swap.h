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

typedef struct s_my_list
{
  struct s_stack_node *head;
  struct s_stack_node *tail;
} t_my_list;

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
void	error(char *debug);
int		error_duplicate(t_stack_node *a, int nb);
int		error_syntax(char	*str);
//MEMORY
void	free_list(t_stack_node **stack);
void	free_errors_init(t_stack_node **a, char **argv);

//UTILS
char	*clean_split(char **av, int ac, t_stack_node **a);
bool	is_sorted(t_stack_node **stack);

//LIST
t_stack_node	*find_last(t_stack_node *stack);
void    		lets_sort(t_stack_node **a, t_stack_node **b);
#endif