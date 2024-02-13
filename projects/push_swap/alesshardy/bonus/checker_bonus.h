/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:17:37 by apintus           #+#    #+#             */
/*   Updated: 2024/02/09 15:49:59 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../libft/libft.h"

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

int				ft_strcmp(const char *s1, const char *s2);
int				parse(int argc, char **argv, t_stack_node **a);
int				check_move(char *line, t_stack_node **a, t_stack_node **b);
bool			only_space(char *str);
int				ft_strlen_p(char *str);
char			*ft_strcpy(char *dest, char *src);
char			*concatenate_arg(char **argv, int argc, t_stack_node **a);
int				error_syntax(char	*str);
int				error_duplicate(t_stack_node *a, int nb);
void			free_stack(t_stack_node **stack);
void			free_errors_conc(t_stack_node **a, char *combined_arg);
void			free_errors_init(t_stack_node **a, char **argv);
bool			ft_check_looong(char *str);
long			ft_atol(char *str);
void			append_node(t_stack_node **stack, int nb);
void			init_stack_a(t_stack_node **a, char **argv);
void			push(t_stack_node **src, t_stack_node **dest);
void			pa(t_stack_node **b, t_stack_node**a, bool print);
void			pb(t_stack_node **a, t_stack_node**b, bool print);
void			reverse_rotate(t_stack_node **stack);
void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);
void			rotate(t_stack_node **stack);
void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);
void			swap(t_stack_node **stack);
void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);
int				stack_len(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
void			*ft_free(char **strs);

#endif
