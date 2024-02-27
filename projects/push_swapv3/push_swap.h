/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 07:37:08 by kpires            #+#    #+#             */
/*   Updated: 2024/02/26 07:37:08 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include "./libft/libft.h"

typedef struct y_list
{
	int				length;
	struct s_node	*heap;
	struct s_node	*tail;
}	x_list;

typedef struct s_node
{
	int				nbr;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

void		error(char *debug);
char		*process_arg(int ac, char **arg);
void		init_node(char *arg_processed, x_list *list);
void		print_node(t_node *node);
void		free_list(x_list *list);