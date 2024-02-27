/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:08:43 by apintus           #+#    #+#             */
/*   Updated: 2023/11/17 13:54:47 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *) &s[i]);
		i--;
	}
	return (NULL);
}

/*#include <stdio.h>
#include <string.h>
int     main(void)
{
        const char s[] = "peche";
        char    c;
        const char *result;

        c = 'e';
        result = ft_strrchr(s, c);
        if (result != NULL)
                printf("'%c' trouver a : %ld\n", c, result - s);
        else
                printf("'%c' pas trouver", c);
}*/
