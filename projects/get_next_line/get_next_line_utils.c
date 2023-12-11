/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 10:12:58 by ajordan-          #+#    #+#             */
/*   Updated: 2023/12/11 15:29:17 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

char	*ft_strjoin(const char *str1, *str2)
{
	size_t	len;
	int		i;
	char	*str;

	if (!str1 || !str2)
		return (NULL);
	i = 0;
	len = ft_strlen(str1) + ft_strlen(str2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (*str1)
	{
		str[i] = *str1;
		i++;
		str1++;
	}
	while (*str2)
	{
		str[i] = *str2;
		i++;
		str2++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_strchr(const char *str, int set)
{
	while (*s != (char)c)
		if (!*s++)
			return (0);
	return ((char *)s);
}