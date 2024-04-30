/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:12:21 by kpires            #+#    #+#             */
/*   Updated: 2024/02/28 13:12:21 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdbool.h>
#include <stdio.h>

typedef struct y_list
{
	struct s_node	*higher_a;
	struct s_node	*higher_b;
	int				length_a;
	int				length_b;
	struct s_node	*head_a;
	struct s_node	*head_b;
	struct s_node	*tail_a;
	struct s_node	*tail_b;
}	t_HTlist;

typedef struct s_node
{
	int				nbr;
	int				index;
	int				cost;
	bool			above_median;
	bool			cheadest;
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

void	error(char *debug, t_HTlist *list);
char	*process_arg(int ac, char **arg);
void	init_node(char *arg_processed, t_HTlist *list);
void	print_node(t_node *node);
void	free_list(t_HTlist *list);
void	free_double_char(char **str);

void	print_node(t_node *node);
void	print_list(t_HTlist *list, char list_name);

bool	check_is_sort(t_node *a);

void	sort(t_HTlist *list);

void	sa(t_HTlist *list, bool print);
void	sb(t_HTlist *list, bool print);

void	ra(t_HTlist *list, bool print);
void	rb(t_HTlist *list, bool print);
void	rr(t_HTlist *list, bool print);

void	rra(t_HTlist *list, bool print);
void	rrb(t_HTlist *list, bool print);
void	rrr(t_HTlist *list, bool print);

t_node	**get_head(t_HTlist *list, char list_name);
t_node	**get_tail(t_HTlist *list, char list_name);