/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:06:11 by kpires            #+#    #+#             */
/*   Updated: 2023/11/07 15:22:32 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while(s[i] != (char)c)
		if (!s[i++])
			return (0);
	return ((char *)&s[i]);
}

/*
#include <unistd.h>

int	main()
{
	char	*str;
	char	*i;

	str = "abcdef";
	i = ft_strchr(str , 'a');
	write(1, i, 1);
	write(1, "\n", 1);
	return (0);
}
*/