/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 22:03:46 by kpires            #+#    #+#             */
/*   Updated: 2024/02/25 22:03:46 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_node(t_node *a)
{
    printf("NODE [%d],\n", a->nbr);
}

void    print_list(t_linked_list *list)
{
    t_node *cur_node;

    cur_node = list->head;
    while (cur_node)
    {
        if (cur_node == list->head)
            printf("Head:");
        else if (cur_node == list->tail)
            printf("Tail:");
        print_node(cur_node);
        cur_node = cur_node->next;
    }
    printf("Length: %d\n", list->length);
}
