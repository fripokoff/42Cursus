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

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "./libft/libft.h"
#include <stdbool.h>
#include <stdio.h>

typedef struct ht_list
{
	struct s_node	*higher_a;
	struct s_node	*higher_b;
	struct s_node	*lower_a;
	struct s_node	*lower_b;
	int				length_a;
	int				length_b;
	struct s_node	*head_a;
	struct s_node	*head_b;
	struct s_node	*tail_a;
	struct s_node	*tail_b;
}	t_ht_list;

typedef struct s_node
{
	int				nbr;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

/* error.c */
void	error(char *debug, t_ht_list *ht_list);
void	free_list(t_ht_list *ht_list);
void	free_double_char(char **str);

/* process_arg.c */
char	*process_arg(int ac, char **arg);

/* help_nodes.c */
void	print_node(t_node *node);
void	print_list(t_ht_list *ht_list, char list);
void	print_head_list(t_ht_list *ht_list);

/* init_node.c */
void	init_node(char *arg_processed, t_ht_list *ht_list);

/* head_tail.c */
t_node	**get_head(t_ht_list *ht_list, char list);
t_node	**get_tail(t_ht_list *ht_list, char list);
void	update_headtail(t_ht_list *ht_list, t_node **head,
			t_node **tail, char list);
void	find_highest(t_ht_list *ht_list, char list);
void	find_lowest(t_ht_list *ht_list, char list);
void update_highest_lowest(t_ht_list *ht_list, char list);

/* sort.c */
void	sort(t_ht_list *ht_list);
bool	check_is_sort(t_node *a);

/* swap.c */
void	sa(t_ht_list *ht_list, bool print);
void	sb(t_ht_list *ht_list, bool print);

/* rotate.c */
void	ra(t_ht_list *ht_list, bool print);
void	rb(t_ht_list *ht_list, bool print);
void	rr(t_ht_list *ht_list, bool print);

/* reverse_rotate.c */
void	reverse_rotate(t_ht_list *ht_list, char list);
// void	rra(t_ht_list *ht_list, bool print);
// void	rrb(t_ht_list *ht_list, bool print);
// void	rrr(t_ht_list *ht_list, bool print);

/* push.c */
void	pa(t_ht_list *ht_list, bool	print);
void	pb(t_ht_list *ht_list, bool	print);

#endif