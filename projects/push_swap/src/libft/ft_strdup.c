/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:01:49 by kpires            #+#    #+#             */
/*   Updated: 2023/11/30 09:21:07 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char			*c;
	unsigned int	len;
	unsigned int	i;

	i = 0;
	len = ft_strlen(s);
	c = (char *)malloc(sizeof(char) * (len + 1));
	if (!c)
		return (NULL);
	while (i < len)
	{
		c[i] = s[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}
/*
** #include <stdio.h>
** #include <stdlib.h>
** 
** size_t	ft_strlen(const char *c)
** {
** 	size_t	i;
** 
** 	i = 0;
** 	while (c[i])
** 		i++;
** 	return (i);
** }
** 
** int	main(void)
** {
** 	char *str = "";
** 	char *dup_str = ft_strdup(str);
** 	printf("La chaîne de caractères est vide : %s\n",
** 		dup_str == NULL ? "oui" : "non");
** 
** 	str = "a";
** 	dup_str = ft_strdup(str);
** 	printf("La chaîne de caractères ne contient qu'un seul caractère : %s\n",
** 		dup_str != NULL ? "oui" : "non");
** 	printf("La chaîne dupliquée est : %s\n", dup_str);
** 
** 	str = "Bonjour, monde !";
** 	dup_str = ft_strdup(str);
** 	printf("La chaîne de caractères contient plusieurs caractères : %s\n",
** 		dup_str != NULL ? "oui" : "non");
** 	printf("La chaîne dupliquée est : %s\n", dup_str);
** 
** 	return (0);
** }
*/