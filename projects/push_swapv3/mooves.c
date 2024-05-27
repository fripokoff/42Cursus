/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mooves.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 09:35:39 by kpires            #+#    #+#             */
/*   Updated: 2024/05/07 09:35:39 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a_to_b(t_ht_list *ht_list, int median)
{
	if (ht_list->head_a && ht_list->head_a->nbr < median)
	{
		printf("head:%d\n", ht_list->head_a->nbr);
		pb(ht_list, true);
		printf("head:%d\n", ht_list->head_a->nbr);
	}
	else
	{
		pb(ht_list, true);
		rb(ht_list, true);
	}
}
