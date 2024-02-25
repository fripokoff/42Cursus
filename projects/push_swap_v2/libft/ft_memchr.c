/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:59:14 by kpires            #+#    #+#             */
/*   Updated: 2023/11/29 17:32:33 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}

/*
** #include <stdio.h>
** #include <string.h>
** 
** int	main(void)
** {
** 	char tableau[] = "Bonjour, monde !";
** 	char c = 'o';
** 	char *p = memchr(tableau, c, sizeof(tableau));
** 	if (p == NULL)
** 	{
** 		printf("Le caractère %c n'a pas été trouvé.\n", c);
** 	}
** 	else
** 	{
** 		printf("Le caractère %c a été trouvé à l'adresse %p.\n", c, p);
** 	}
** 
** 	int tableau_entiers[] = {1, 2, 3, 4, 5};
** 	int i = 3;
** 	int *p_entiers = memchr(tableau_entiers, i, sizeof(tableau_entiers));
** 	if (p_entiers == NULL)
** 	{
** 		printf("L'entier %d n'a pas été trouvé.\n", i);
** 	}
** 	else
** 	{
** 		printf("L'entier %d a été trouvé à l'adresse %p.\n", i, p_entiers);
** 	}
** 
** 	return (0);
** }
*/