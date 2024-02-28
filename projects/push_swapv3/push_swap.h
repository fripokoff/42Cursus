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
	int length;
	struct s_node *heap;
	struct s_node *tail;
} x_list;

typedef struct s_node
{
	int nbr;
	struct s_node *next;
	struct s_node *prev;
} t_node;

void	error(char *debug, x_list *list);
char	*process_arg(int ac, char **arg);
void	init_node(char *arg_processed, x_list *list);
void	print_node(t_node *node);
void	free_list(x_list *list);
void	free_double_char(char **str);