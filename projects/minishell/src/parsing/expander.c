/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:27:02 by redrouic          #+#    #+#             */
/*   Updated: 2025/01/13 03:40:43 by redrouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	copy_non_quotes(char *res, char *str, int *i, int *j)
{
	char	quote;

	quote = str[*i];
	(*i)++;
	while (str[*i] && str[*i] != quote)
		res[(*j)++] = str[(*i)++];
	if (str[*i] == quote)
		(*i)++;
}

char	*remq(char *str)
{
	char	*res;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(str);
	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	res = malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	while (str[i])
	{
		if ((str[i] == '"' || str[i] == '\''))
		{
			copy_non_quotes(res, str, &i, &j);
			continue ;
		}
		res[j++] = str[i++];
	}
	res[j] = '\0';
	return (free(str), res);
}

char	*ret_venv(t_env *lenv, char *src, int *i)
{
	char	*str;
	char	*res;
	int		len;

	len = 0;
	while (src[len] && (ft_isalnum(src[len]) || src[len] == '_'))
		len++;
	if (len == 0)
		return (NULL);
	*i += len;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (ft_perror(EALL, 0), NULL);
	ft_strncpy(str, src, len);
	res = plist(lenv, str);
	free(str);
	if (!res)
		return (NULL);
	return (res);
}

static char	*process_dollar(t_global *g, char *str, int *i, char *buf)
{
	char	*res;
	int		y;

	y = 0;
	(*i)++;
	if (str[*i] == '\0' || is_chr(" \t\"", str[*i]))
	{
		buf[y++] = '$';
		return (buf + y);
	}
	if (str[*i] == '?')
	{
		res = ft_itoa(g->exit_val);
		while (*res)
			buf[y++] = *res++;
		(*i)++;
		return (free(res - y), buf + y);
	}
	res = ret_venv(g->lenv, &str[*i], i);
	if (res)
	{
		while (*res)
			buf[y++] = *res++;
	}
	return (free(res - y), buf + y);
}

char	*gest_expand(t_global *g, char *str)
{
	char	*buf;
	char	*buf_pos;
	int		i;

	buf = ft_calloc(sizeof(char), BUFSIZ);
	if (!buf)
		return (ft_perror(EALL, 0), NULL);
	buf_pos = buf;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$' && !inq(str, i, '\''))
			buf_pos = process_dollar(g, str, &i, buf_pos);
		else
		{
			*buf_pos = str[i];
			buf_pos++;
			i++;
		}
	}
	*buf_pos = '\0';
	return (buf);
}
