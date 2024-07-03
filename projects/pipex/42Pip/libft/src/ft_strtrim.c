/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:26:06 by aautin            #+#    #+#             */
/*   Updated: 2023/12/29 15:56:11 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_is_in_str(char a, char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == a)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_str_is_set(char *str, char *set)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_is_in_str(str[i], set))
			return (0);
	}
	return (1);
}

static int	ft_str_start(char *s, char *set)
{
	int	i;

	i = 0;
	while (s[i] && ft_is_in_str(s[i], (char *) set))
		i++;
	return (i);
}

static int	ft_str_end(char *s, char *set, int start)
{
	int	end;

	end = start;
	while (s[start])
	{
		if (!ft_is_in_str(s[start], (char *) set))
			end = start;
		start++;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*str;

	if (!s1 || !set || ft_str_is_set((char *) s1, (char *) set))
	{
		str = malloc(sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	start = ft_str_start((char *) s1, (char *) set);
	end = ft_str_end((char *) s1, (char *) set, start);
	str = (char *)malloc((end - start + 2) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (start <= end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
