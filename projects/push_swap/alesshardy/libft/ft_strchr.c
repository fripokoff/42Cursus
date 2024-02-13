/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:42:56 by apintus           #+#    #+#             */
/*   Updated: 2023/11/17 13:54:38 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *) &s[i]);
	return (NULL);
}

/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	const char s[] = "peche";
	char	c;
	const char *result;

	c = 'e';
	result = ft_strchr(s, c);
	if (result != NULL)
		printf("'%c' trouver a : %ld\n", c, result - s);
	else
		printf("'%c' pas trouver", c);
}*/
