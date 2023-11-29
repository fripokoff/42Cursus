/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:21:25 by kpires            #+#    #+#             */
/*   Updated: 2023/11/29 18:08:29 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*s1, const char	*s2, size_t	n)
{
	size_t	j;

	if (!s1 && !n)
		return (NULL);
	if (!*s2)
		return ((char *)s1);
	while (*s1 && n--)
	{
		j = 0;
		while (*(s1 + j) == *(s2 + j) && *(s2 + j) && j <= n)
		{
			if (!*(s2 + j + 1))
				return ((char *)s1);
			j++;
		}
		s1++;
	}
	return (NULL);
}
/*
** #include <stdio.h>
** #include <string.h>
** int main () {
**   const char s1[20] = "TutorialsPoint";
**    const char s2[10] = "";
**   char *result;
**   char *result2;
** 
**    result2 = ft_strnstr(s1, s2, 4);
**    printf("The substring is: %s\n", result2);
**    result = strnstr(s1, s2, 4);
**    printf("The substring is: %s\n", result);
**    return(0);
**  }
*/