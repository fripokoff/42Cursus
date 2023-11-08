/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:06:11 by kpires            #+#    #+#             */
/*   Updated: 2023/11/07 15:22:45 by kpires           ###   ########.fr       */
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
			return ((char *)s + i);
	return (0);
}

/*
#include <unistd.h>
int	main()
{
	char	*str;
	char	*i;

	str = "abcdefafdp";
	i = ft_strrchr(str , 'a');
	write(1, i, 1);
	write(1, "\n", 1);
	return (0);
}
*/
