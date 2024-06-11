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

# include <stdbool.h>
# include "libft.h"

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
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

/* errors.c */
void	error(t_ht_list *ht_list);
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
t_node	*get_head(t_ht_list *ht_list, char list);
t_node	*get_tail(t_ht_list *ht_list, char list);
void	update_headtail(t_ht_list *ht_list, t_node *head,
			t_node *tail, char list);

/* utils.c*/
void	update_highest_lowest(t_ht_list *ht_list);

/* sort.c */
void	sort(t_ht_list *ht_list);

/* rules.c */
void	swap(t_ht_list *ht_list, char list);
void	rotate(t_ht_list *ht_list, char list);
void	reverse_rotate(t_ht_list *ht_list, char list);
void	pa(t_ht_list *ht_list);
void	pb(t_ht_list *ht_list);

/* algo.c*/
int		*sort_int_tab(int *tab, int size);
void	while_for_norm(t_ht_list *ht_list, int *arr, int length_a);

/* algo_utils.c*/
void	is_reversed(t_ht_list *ht_list);
bool	check_is_sort(t_node *a);
int		get_range(t_ht_list *ht_list);
int		*copy_arr(t_ht_list *ht_list);

#endif