/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:26:06 by aautin            #+#    #+#             */
/*   Updated: 2023/11/27 16:40:41 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	ft_count_elements(char const *s, char c)
{
	size_t	elements_nb;
	size_t	i;

	i = 0;
	elements_nb = 0;
	while (s[i])
	{
		if (s[i++] != c)
		{
			elements_nb++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (elements_nb);
}

static char	*ft_strdup_sep(const char *s, size_t *pos, char sep)
{
	char	*str;
	int		temp;

	temp = *pos;
	while (s[*pos] && s[*pos] != sep)
		(*pos)++;
	str = (char *)malloc((*pos - temp + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[*pos - temp] = '\0';
	*pos = temp;
	temp = 0;
	while (s[*pos] && s[*pos] != sep)
	{
		str[temp] = s[(*pos)];
		temp++;
		(*pos)++;
	}
	return (str);
}

static char	**ft_free_db_array(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	size;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	size = ft_count_elements(s, c);
	tab = (char **)malloc((size + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (i < size)
	{
		while (s[j] && s[j] == c)
			j++;
		tab[i] = ft_strdup_sep(s, &j, c);
		if (!tab[i])
			return (ft_free_db_array(tab));
		i++;
	}
	tab[size] = NULL;
	return (tab);
}
