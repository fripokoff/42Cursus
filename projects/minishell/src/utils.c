/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 06:04:27 by redrouic          #+#    #+#             */
/*   Updated: 2025/01/13 03:35:50 by redrouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*pwrapper(char *name, char *content, char sep)
{
	char	*dest;
	int		len;
	int		i;

	len = ft_strlen(name) + ft_strlen(content) + 1;
	i = 0;
	dest = ft_calloc(sizeof(char), (len + 1));
	if (!dest)
		return (NULL);
	while (*name)
		dest[i++] = *name++;
	dest[i++] = sep;
	while (*content)
		dest[i++] = *content++;
	dest[i] = '\0';
	return (dest);
}

int	skip_chars(char *str, char *dels)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && (is_chr(dels, str[i])))
		i++;
	return (i);
}

char	*plist(t_env *lenv, char *name)
{
	t_env	*tmp;
	char	*res;

	tmp = lenv;
	while (tmp != NULL)
	{
		if (name && ft_strcmp(name, tmp->name))
		{
			res = ft_strdup(tmp->content);
			return (res);
		}
		else if (!name)
		{
			res = remq(ft_strdup(tmp->content));
			printf("%s=%s\n", tmp->name, res);
			free(res);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

bool	inq(char *str, int index, char quote)
{
	int		i;
	char	current;

	i = 0;
	current = '\0';
	if (!str || index < 0 || index >= (int)ft_strlen(str))
		return (false);
	while (i <= index)
	{
		if (current == '\0')
		{
			if ((quote == '\0' && (str[i] == 34 || str[i] == 39))
				|| str[i] == quote)
				current = str[i];
		}
		else if (str[i] == current)
			current = '\0';
		i++;
	}
	return (current != '\0');
}

int	gest_msg(char *str, int idx)
{
	if (str[idx] && str[idx] == '>' && str[idx + 1] && str[idx + 1] == '>')
		return (ft_perror(UTOK, ">>"), -1);
	else if (str[idx] && str[idx] == '>')
		return (ft_perror(UTOK, ">"), -1);
	else if (str[idx] && str[idx] == '<' && str[idx + 1] && str[idx + 1] == '<')
		return (ft_perror(UTOK, "<<"), -1);
	else if (str[idx] && str[idx] == '<')
		return (ft_perror(UTOK, "<"), -1);
	else if (str[idx] && str[idx] == '|' && str[idx + 1] && str[idx + 1] != '|')
		return (ft_perror(UTOK, "|"), -1);
	else if (str[idx] && str[idx] == '|')
		return (ft_perror(UTOK, "|"), -1);
	return (-1);
}
