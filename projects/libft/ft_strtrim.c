/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:27:01 by kpires            #+#    #+#             */
/*   Updated: 2023/11/27 17:44:03 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static int	ft_check(int s, char const *set)
{
	while (*set)
	{
		if (*set == s)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	i = 0;
	while (ft_check(s1[i], set))
		i++;
	if (!s1[i])
		return (ft_strdup(""));
	while (ft_check(s1[len - 1], set))
		len--;
	len = len - i;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, &s1[i], len);
	str[len] = '\0';
	return (str);
}
