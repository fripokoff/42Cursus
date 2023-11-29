/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fripok <fripok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:50:30 by fripok            #+#    #+#             */
/*   Updated: 2023/11/29 13:16:53 by fripok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (lst && *lst)
	{
		current = *lst;
		while (current->next)
		{
			current = current->next;
		}
		current->next = new;
	}
	else if (lst)
		*lst = new;
}
