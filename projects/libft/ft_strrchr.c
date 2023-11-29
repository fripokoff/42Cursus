/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:06:11 by kpires            #+#    #+#             */
/*   Updated: 2023/11/29 18:07:50 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (s[i] != (char) c)
		if (!i--)
			return (0);
	return ((char *)&s[i]);
}
/*
** #include <string.h>
** #include <stdlib.h>
** #include <stdio.h>
** int				main()
** {
** 	char *str;
** 	str = ft_strrchr("bonjourno", 'o');
** 	printf("%s", str);
** 	return (0);
** }
*/