/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:59:14 by apintus           #+#    #+#             */
/*   Updated: 2023/11/28 18:17:16 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_elem;

	new_elem = malloc(sizeof(t_list));
	if (!new_elem)
		return (0);
	new_elem->content = content;
	new_elem->next = 0;
	return (new_elem);
}

/*#include <stdio.h>
int	main(void)
{
	char	str[] = "abricot";
	t_list	*elem;

	elem = ft_lstnew((void *)str);
	printf("%s\n", (char *)elem->content);
}*/
