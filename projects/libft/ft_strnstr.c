/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:21:25 by kpires            #+#    #+#             */
/*   Updated: 2023/11/09 13:09:43 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	unsigned int	i;
	int				j;

	if (!*s2)
		return ((char *)s1);
	i = 0;
	j = 0;
	while (s1[i])
	{
		if (s1[i] == s2[j] && s1[i] && i < len)
		{
			i++;
			j++;
		}
		if (!s2[j])
			return ((char *)&s1[i - j]);
		i = i - j + 1;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>
int main () {
  const char s1[20] = "TutorialsPoint";
   const char s2[10] = "";
  char *result;
  char *result2;

   result2 = ft_strnstr(s1, s2, 4);
   printf("The substring is: %s\n", result2);
   result = strnstr(s1, s2, 4);
   printf("The substring is: %s\n", result);
   return(0);
 }
 */