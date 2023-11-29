/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:09:06 by kpires            #+#    #+#             */
/*   Updated: 2023/11/29 18:14:40 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		s_len;
	char	*str;

	i = 0;
	s_len = ft_strlen(s);
	str = malloc(sizeof(char) * (s_len) + 1);
	if (!str)
		return (NULL);
	while (i < s_len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}
/*
** #include <stdio.h>
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
** char to_uppercase(unsigned int i, char c) {
**   if (c >= 'a' && c <= 'z') {
**     c -= 32 + i;
**   }
**   return c;
** }
** 
** int main() {
**   char *str = "Bonjour, monde !";
**   char *mapped_str = ft_strmapi(str, to_uppercase);
** 
**   if (mapped_str != NULL) {
**     printf("The mapped string is: %s\n", mapped_str);
**   } else {
**     printf("Error: The mapped string is NULL.\n");
**   }
** 
**   return 0;
** }
*/