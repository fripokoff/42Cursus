/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:09:06 by kpires            #+#    #+#             */
/*   Updated: 2023/11/30 15:16:15 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	if (!s || !f)
		return (NULL);
	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	while (s[i])
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
