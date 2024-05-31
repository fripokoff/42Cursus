/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:57:15 by kpires            #+#    #+#             */
/*   Updated: 2024/05/30 18:31:12 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(t_ht_list *ht_list, bool print)
{
    t_node *temp;

    if (ht_list->head_b == NULL)
        return;
    temp = ht_list->head_b;
    ht_list->head_b = ht_list->head_b->next;
    if (ht_list->head_b != NULL)
        ht_list->head_b->prev = NULL;
    temp->next = ht_list->head_a;
    if (ht_list->head_a != NULL)
        ht_list->head_a->prev = temp;
    ht_list->head_a = temp;
    temp->prev = NULL;
    if (ht_list->tail_a == NULL) {
        ht_list->tail_a = ht_list->head_a;
        if (ht_list->tail_a->next != NULL) // Check if there is a node after tail_a
            ht_list->tail_a->next->prev = ht_list->tail_a; // Update the prev pointer of the node after tail_a
    }
    if (ht_list->head_b == NULL)
        ht_list->tail_b = NULL;
    update_highest_lowest(ht_list, '2');
    ht_list->length_a++;
    ht_list->length_b--;
    if (print)
        printf("pa\n");
}

void pb(t_ht_list *ht_list, bool print)
{
    t_node *temp;

    if (ht_list->head_a == NULL)
        return;
    temp = ht_list->head_a;
    ht_list->head_a = ht_list->head_a->next;
    if (ht_list->head_a != NULL)
        ht_list->head_a->prev = NULL;
    temp->next = ht_list->head_b;
    if (ht_list->head_b != NULL)
        ht_list->head_b->prev = temp;
    ht_list->head_b = temp;
    temp->prev = NULL;
    if (ht_list->tail_b == NULL) {
        ht_list->tail_b = ht_list->head_b;
        if (ht_list->tail_b->next != NULL) // Check if there is a node after tail_b
            ht_list->tail_b->next->prev = ht_list->tail_b; // Update the prev pointer of the node after tail_b
    }
    if (ht_list->head_a == NULL)
        ht_list->tail_a = NULL;
    update_highest_lowest(ht_list, '2');
    ht_list->length_b++;
    ht_list->length_a--;
    if (print)
        printf("pb\n");
}
