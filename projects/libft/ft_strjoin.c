/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:57:27 by kpires            #+#    #+#             */
/*   Updated: 2023/11/29 18:16:44 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	size_t	len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (*s1)
	{
		str[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		str[i] = *s2;
		s2++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
** #include <stdio.h>
** #include <stdlib.h>
** #include <string.h>
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
** int main() {
**     char *str1 = "";
**     char *str2 = "";
**     char *joined_str = ft_strjoin(str1, str2);
**     printf("Joined string (empty + empty): %s\n", joined_str);
**     free(joined_str);
** 
**     str1 = "";
**     str2 = "Hello";
**     joined_str = ft_strjoin(str1, str2);
**     printf("Joined string (empty + Hello): %s\n", joined_str);
**     free(joined_str);
** 
**     str1 = "Bonjour";
**     str2 = "monde";
**     joined_str = ft_strjoin(str1, str2);
**     printf("Joined string (Bonjour + monde): %s\n", joined_str);
**     free(joined_str);
** 
**     joined_str = ft_strjoin(NULL, NULL);
**     printf("Joined string (NULL + NULL): %s\n", joined_str);
** 
**     return 0;
** }
*/