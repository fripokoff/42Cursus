/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:58:20 by kpires            #+#    #+#             */
/*   Updated: 2024/02/25 14:58:20 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct	s_node
{
	struct s_node		*previous;
	struct s_node		*next;
	int					nbr;
}   t_node;

typedef struct	linked_list
{
	int					length;
	t_node				*head;
	t_node				*tail;

} t_linked_list;

int	*flatten_str_to_int(char **strings, int ac);

//ERROR
void    error();
int print_array_int(int  *arr);
//TABLE | PARSING
void free_table_int(int **table);
void free_table_str(char **table);
void     display_table_int(int **arr);
int count_table_total_int(int **table);
int count_table_rows_str(char **table);

t_linked_list    *initialize_list(int *values);

void    print_list(t_linked_list *list);
void    print_node(t_node *a);