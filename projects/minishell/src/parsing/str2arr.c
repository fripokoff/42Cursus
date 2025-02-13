/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str2arr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:25:21 by redrouic          #+#    #+#             */
/*   Updated: 2025/01/10 15:59:21 by redrouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

bool	is_chr(const char *chr, char c)
{
	while (*chr)
	{
		if (c == *chr)
			return (true);
		chr++;
	}
	return (false);
}

int	count_rows(const char *chr, char *str, bool quote)
{
	int	rows;
	int	i;

	rows = 0;
	i = 0;
	while (str[i] && is_chr(chr, str[i]))
		i++;
	while (str[i])
	{
		if ((!quote && str[i + 1] && is_chr(chr, str[i])
				&& !is_chr(chr, str[i + 1])) || (quote && str[i + 1]
				&& is_chr(chr, str[i]) && !is_chr(chr, str[i + 1])
				&& !inq(str, i, 0)))
			rows++;
		i++;
	}
	return (rows + 1);
}

static int	*count_cols(const char *chr, char *str, int rows, bool quote)
{
	int	*cols;
	int	vec[2];
	int	i;

	cols = malloc(sizeof(int) * (rows + 1));
	if (!cols)
		return (0);
	vec[0] = 0;
	vec[1] = 0;
	i = 0;
	while (str[i])
	{
		if ((!is_chr(chr, str[i]) && str[i])
			|| (quote && is_chr(chr, str[i]) && inq(str, i, 0)))
			vec[0]++;
		if ((!quote && vec[0] > 0 && is_chr(chr, str[i])) || (quote
				&& vec[0] > 0 && is_chr(chr, str[i]) && !inq(str, i, 0)))
		{
			cols[vec[1]++] = vec[0];
			vec[0] = 0;
		}
		i++;
	}
	cols[vec[1]] = vec[0];
	return (cols);
}

static char	**init_arr(const char *chr, char *str, bool quote)
{
	char	**arr;
	int		*cols;
	int		rows;
	int		y;

	rows = count_rows(chr, str, quote);
	cols = count_cols(chr, str, rows, quote);
	if (!cols)
		return (NULL);
	arr = malloc(sizeof(char *) * (rows + 1));
	if (!arr)
		return (free(cols), NULL);
	y = 0;
	while (y < rows)
	{
		arr[y] = ft_calloc(sizeof(char), (cols[y] + 1));
		if (!arr[y])
			return (free_arr(arr), free(cols), NULL);
		y++;
	}
	arr[y] = NULL;
	return (free(cols), arr);
}

char	**str2arr(char *str, const char *chr, bool quote)
{
	char	**arr;
	int		vec[2];
	int		i;

	arr = init_arr(chr, str, quote);
	if (!arr)
		return (NULL);
	vec[0] = 0;
	vec[1] = 0;
	i = 0;
	while (str[i])
	{
		if ((!is_chr(chr, str[i]) && str[i])
			|| (quote && is_chr(chr, str[i]) && inq(str, i, 0)))
			arr[vec[1]][vec[0]++] = str[i];
		if ((!quote && vec[0] > 0 && is_chr(chr, str[i])) || (quote
				&& vec[0] > 0 && is_chr(chr, str[i]) && !inq(str, i, 0)))
		{
			arr[vec[1]++][vec[0]] = '\0';
			vec[0] = 0;
		}
		i++;
	}
	return (arr);
}
