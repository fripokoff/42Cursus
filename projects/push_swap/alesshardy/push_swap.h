/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:12:57 by apintus           #+#    #+#             */
/*   Updated: 2024/02/09 15:39:20 by apintus          ###   ########.fr       */
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

//PARSSING
char			*concatenate_arg(char **argv, int argc, t_stack_node **a);
char			*ft_strcpy(char *dest, char *src);
int				ft_strlen_p(char *str);
bool			ft_check_looong(char *str);

char			**ft_split(char const *s, char c);
char			*ft_word(char const *s, char c);
int				ft_strlen_sep(char const *s, char c);
int				count_strings(char const *s, char c);
void			*ft_free(char **strs);

//init_stack
void			init_stack_a(t_stack_node **a, char **argv);
void			append_node(t_stack_node **stack, int nb);
long			ft_atol(char *str);

//error
void			free_errors_conc(t_stack_node **a, char *combined_arg);
void			free_errors_init(t_stack_node **a, char **argv);
void			free_stack(t_stack_node **stack);
int				error_duplicate(t_stack_node *a, int nb);
int				error_syntax(char	*str);

//utils
t_stack_node	*find_last(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);
int				stack_len(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *stack);

//commands
void			swap(t_stack_node **stack);
void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);

void			rotate(t_stack_node **stack);
void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);

void			reverse_rotate(t_stack_node **stack);
void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);

void			push(t_stack_node **src, t_stack_node **dest);
void			pa(t_stack_node **b, t_stack_node**a, bool print);
void			pb(t_stack_node **a, t_stack_node**b, bool print);

//refresh
void			refresh(t_stack_node *a, t_stack_node *b);
void			cost_b(t_stack_node *a, t_stack_node *b);
void			refresh_target(t_stack_node *a, t_stack_node *b);
void			refresh_index(t_stack_node *stack);
void			set_cheapest(t_stack_node *a);

//algo
void			sort(t_stack_node **a, t_stack_node **b);
void			sort_three(t_stack_node **a);
void			sort_big(t_stack_node **a, t_stack_node **b);
void			to_the_top(t_stack_node **a);
void			push_a_to_b(t_stack_node **a, t_stack_node **b, int median);
void			push_b_to_a(t_stack_node **a, t_stack_node **b);
void			move_both_above_median(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest);
void			move_both_under_median(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest);
void			move_a_above_and_b_below_median(t_stack_node **a,
					t_stack_node **b, t_stack_node *cheapest);
void			move_a_below_and_b_above_median(t_stack_node **a,
					t_stack_node **b, t_stack_node *cheapest);

#endif
