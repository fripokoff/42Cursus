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

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	int				j;

	if (!*needle)
		return ((char *)haystack);
	i = 0;
	j = 0;
	while (haystack[i])
	{
		if (haystack[i] == needle[j] && haystack[i] && i < len)
		{
			i++;
			j++;
		}
		if (!needle[j])
			return ((char *)&haystack[i - j]);
		i = i - j + 1;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>
int main () {
  const char haystack[20] = "TutorialsPoint";
   const char needle[10] = "";
  char *result;
  char *result2;

   result2 = ft_strnstr(haystack, needle, 4);
   printf("The substring is: %s\n", result2);
   result = strnstr(haystack, needle, 4);
   printf("The substring is: %s\n", result);
   return(0);
 }
 */