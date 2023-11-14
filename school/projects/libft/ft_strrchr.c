/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:06:11 by kpires            #+#    #+#             */
/*   Updated: 2023/11/09 13:05:14 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (s[--i])
		if (s[i] == c)
			return ((char *)&s[i]);
	return (NULL);
}

/*
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int				main(int argc, char **argv)
{
	int			i;
	char		*str;

	if (argc == 4)
	{
		i = atoi(argv[1]);
		if (i == 0)
		{
			str = ft_strrchr(argv[2], atoi(argv[3]));
			if (str)
				printf("%s", str);
			else
				printf("(null)");
		}
	}
	return (0);
}
*/