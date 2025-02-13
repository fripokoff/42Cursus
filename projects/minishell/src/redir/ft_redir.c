/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 21:56:02 by kpires            #+#    #+#             */
/*   Updated: 2025/01/11 23:44:45 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

ssize_t	write_here(const void *buffer, int fd, size_t count)
{
	const char	*buf;
	size_t		total;
	ssize_t		bytes;

	buf = buffer;
	total = 0;
	while (total < count)
	{
		bytes = write(fd, buf + total, count - total);
		if (bytes > 0)
			total += bytes;
		else if (bytes == -1)
		{
			if (errno == EAGAIN || errno == EWOULDBLOCK)
				continue ;
			else
				return (-1);
		}
	}
	write(fd, "\n", 1);
	return (total);
}

int	extract_varlen(char *line, int len, char **v_name, bool del_sign)
{
	int	start;
	int	var_len;

	start = len;
	while (line[len] && (ft_isalnum(line[len]) || line[len] == '_'))
		len++;
	var_len = len - start;
	if (line[len] && del_sign)
		len--;
	*v_name = ft_calloc(sizeof(char), (var_len + 1));
	if (!*v_name)
		return (-1);
	ft_strncpy(*v_name, line + start, var_len);
	(*v_name)[var_len] = '\0';
	return (len);
}

static int	skip_nonredir(char *redir, int i)
{
	int	count;
	int	rlen;

	count = 0;
	if (!redir)
		return (0);
	rlen = ft_strlen(redir);
	if (i > rlen || count > rlen || i + count > rlen)
		return (0);
	while (i + count < ft_strlen(redir) && !is_chr("><|", redir[i + count]))
	{
		if (!is_chr("'\"", redir[i + count]))
			count++;
		if (i + count < ft_strlen(redir))
		{
			count += skip_chars(redir + i + count, "\"");
			count += skip_chars(redir + i + count, "'");
		}
	}
	return (count);
}

static int	skip_cmd(char *redir)
{
	int	i;

	i = 0;
	while (redir[i] && redir[i] != '|')
		i++;
	return (i);
}

int	ft_redir(t_global *g, int i, int tmp)
{
	int	j;

	while (++i < g->cnt && g->cmds[i])
	{
		if (!g->cmds[i]->redir)
			continue ;
		j = 0;
		while (j < ft_strlen(g->cmds[i]->redir) && g->cmds[i]->redir[j])
		{
			if (ft_strncmp(g->cmds[i]->redir + j, ">>", 2) == 0)
				tmp = ft_append(g, g->cmds[i], g->cmds[i]->redir + j + 2);
			else if (g->cmds[i]->redir[j] == '>')
				tmp = ft_overwrite(g, g->cmds[i], g->cmds[i]->redir + j + 1);
			if (ft_strncmp(g->cmds[i]->redir + j, "<<", 2) == 0)
				tmp = ft_heredoc(g, i, g->cmds[i]->redir + j + 2);
			else if (g->cmds[i]->redir[j] == '<')
				tmp = ft_redir_input(g, g->cmds[i], g->cmds[i]->redir + j + 1);
			if (tmp < 0)
				j += skip_cmd(g->cmds[i]->redir + j);
			if (!g->cmds[i]->redir[j])
				break ;
			j += tmp + skip_nonredir(g->cmds[i]->redir, (j + tmp));
		}
	}
	return (1);
}
