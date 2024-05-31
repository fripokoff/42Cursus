/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:39:10 by kpires            #+#    #+#             */
/*   Updated: 2024/04/30 15:39:10 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_ht_list *ht_list, char list)
{
    t_node	**head;
    t_node	**tail;
    t_node	*temp;

    head = get_head(ht_list, list);
    tail = get_tail(ht_list, list);
    if (!(*head) || !(*head)->next || !(*tail))
        return ;
    temp = *tail;
    (*tail) = (*tail)->prev;
    if (*tail)
        (*tail)->next = NULL;
    temp->next = (*head);
    (*head)->prev = temp;
    *head = temp;
    update_headtail(ht_list, head, tail, list);
	if(list == 'a')
		printf("rra\n");
	else if (list == 'b')
		printf("rrb\n");
	else
		printf("rrr\n");
}

// void	rra(t_ht_list *ht_list, bool print)
// {
// 	reverse_rotate(ht_list, 'a');
// 	if (print)
// 		printf("rra\n");
// }

// void	rrb(t_ht_list *ht_list, bool print)
// {
// 	reverse_rotate(ht_list, 'b');
// 	if (print)
// 		printf("rrb\n");
// }

// void	rrr(t_ht_list *ht_list, bool print)
// {
// 	reverse_rotate(ht_list, 'a');
// 	reverse_rotate(ht_list, 'b');
// 	if (print)
// 		printf("rrr\n");
// }
