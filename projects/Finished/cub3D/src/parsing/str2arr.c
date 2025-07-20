/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str2arr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:08:31 by redrouic          #+#    #+#             */
/*   Updated: 2025/06/24 17:10:30 by redrouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dst || !src)
		return (0);
	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

bool	is_separator(char c, const char *sep)
{
	if (!sep)
		return (false);
	while (*sep)
	{
		if (c == *sep)
			return (true);
		sep++;
	}
	return (false);
}

int	count_words(const char *str, const char *sep)
{
	int		count;
	bool	in_word;

	count = 0;
	in_word = false;
	if (!str || !sep)
		return (0);
	while (*str)
	{
		if (!is_separator(*str, sep))
		{
			if (!in_word)
			{
				count++;
				in_word = true;
			}
		}
		else
			in_word = false;
		str++;
	}
	return (count);
}

bool	fill_arr(char **arr, char **str, const char *sep, int i)
{
	const char	*start;
	int			len;

	start = *str;
	while (**str && !is_separator(**str, sep))
		(*str)++;
	len = *str - start;
	arr[i] = malloc(sizeof(char) * (len + 1));
	if (!arr[i])
	{
		while (--i >= 0)
			free(arr[i]);
		return (free(arr), false);
	}
	ft_strlcpy(arr[i], start, len + 1);
	return (true);
}

char	**str2arr(char *str, const char *sep)
{
	char	**arr;
	int		word_count;
	int		i;

	i = 0;
	word_count = count_words(str, sep);
	arr = malloc(sizeof(char *) * (word_count + 1));
	if (!arr)
		return (NULL);
	while (*str)
	{
		while (*str && is_separator(*str, sep))
			str++;
		if (!*str)
			break ;
		if (!fill_arr(arr, &str, sep, i++))
			return (NULL);
	}
	arr[i] = NULL;
	return (arr);
}
