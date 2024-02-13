/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:44:28 by apintus           #+#    #+#             */
/*   Updated: 2023/11/22 12:55:44 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static int	count_strings(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (count);
}

static int	ft_strlen_sep(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static char	*ft_word(char const *s, char c)
{
	char	*word;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen_sep(s, c);
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (word == NULL)
		return (NULL);
	while (i < len)
	{
		word[i] = s [i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	size_t	i;

	if (!s)
		return (NULL);
	strings = (char **)malloc(sizeof(char *) * (count_strings(s, c) + 1));
	if (!strings)
		return (ft_free(strings, 0));
	i = 0;
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s != '\0')
		{
			strings[i] = ft_word(s, c);
			if (!strings[i])
				return (ft_free(strings, i));
			i++;
		}
		while (*s != '\0' && *s != c)
			s++;
	}
	strings[i] = 0;
	return (strings);
}

/*#include <stdio.h>

int	main(void)
{
	int	i;
	char	**split;
	char	s[] = "abricot peche raisin ananas";
	char	sep;

	sep = ' ';
	split = ft_split(s, sep);
	i = 0;
	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}

}*/
