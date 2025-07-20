/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:52:04 by kpires            #+#    #+#             */
/*   Updated: 2025/01/13 11:19:51 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static char	*init_hd(char *line, t_env *lenv, int i, size_t total_size)
{
	char	*v_name;
	char	*v_content;

	while (i < ft_strlen(line) && line[i])
	{
		if (line[i] == '$')
		{
			i = extract_varlen(line, ++i, &v_name, true);
			if (i == -1)
				return (NULL);
			v_content = plist(lenv, v_name);
			free(v_name);
			if (v_content)
			{
				total_size += ft_strlen(v_content);
				free(v_content);
			}
			else
				total_size++;
		}
		else
			total_size++;
		i++;
	}
	return (ft_calloc(total_size + 1, sizeof(char)));
}

static char	*fill_hd(char *line, t_env *lenv, char *hd, int i)
{
	char	*v_name;
	char	*v_content;
	int		v_size;

	v_size = 0;
	while (line[i])
	{
		if (line[i] == '$')
		{
			i = extract_varlen(line, ++i, &v_name, false);
			if (i == -1)
				return (NULL);
			v_content = plist(lenv, v_name);
			free(v_name);
			if (!v_content)
				continue ;
			ft_strlcat(hd + v_size, v_content, ft_strlen(v_content) + 1);
			v_size += ft_strlen(v_content);
			free(v_content);
		}
		else
			hd[v_size++] = line[i++];
	}
	hd[v_size] = 0;
	return (hd);
}

static char	*ft_here_parse(char *line, t_env *lenv)
{
	char	*hd;

	hd = init_hd(line, lenv, 0, 0);
	if (!hd)
		return (ft_perror(ERR_ALLOC, 0), NULL);
	hd = fill_hd(line, lenv, hd, 0);
	if (!hd)
		return (line);
	return (hd);
}

int	ft_hd_q(t_cmd *cmd, int *fd, char *del, void (*old_handler)(int))
{
	char	*hd;

	while (g_signal != SIGINT)
	{
		hd = readline("( ͡ಥ ͜ʖ ͡ಥ) heredoc(not parsed)> ");
		if (!hd || g_signal == SIGINT)
		{
			if (g_signal == SIGINT)
			{
				(close(fd[0]), fd[0] = -2);
				break ;
			}
			ft_perror(ERR_HD_EOF, 0);
			break ;
		}
		if ((ft_strncmp(hd, del, ft_strlen(del)) == 0
				&& hd[ft_strlen(del)] == 0))
			break ;
		(write_here(hd, fd[1], ft_strlen(hd)), free(hd));
	}
	(signal(SIGINT, old_handler), free(hd), close(fd[1]));
	cmd->infile = fd[0];
	if (fd[0] == -2)
		return (-1);
	return (0);
}

int	ft_hd_nq(t_global *g, int *fd, char *del, void (*old_handler)(int))
{
	char	*hd;

	while (g_signal != SIGINT)
	{
		hd = readline("( ͡ಥ ͜ʖ ͡ಥ) heredoc> ");
		if (g_signal == SIGINT)
		{
			(close(fd[0]), fd[0] = -2);
			break ;
		}
		if (!hd)
		{
			ft_perror(ERR_HD_EOF, 0);
			break ;
		}
		if ((ft_strncmp(hd, del, ft_strlen(del)) == 0
				&& hd[ft_strlen(del)] == 0))
			break ;
		hd = ft_here_parse(hd, g->lenv);
		(write_here(hd, fd[1], ft_strlen(hd)), free(hd));
	}
	(signal(SIGINT, old_handler), free(hd), close(fd[1]));
	if (fd[0] == -2)
		return (g->cmds[fd[2]]->infile = fd[0], -1);
	return (g->cmds[fd[2]]->infile = fd[0], 0);
}
