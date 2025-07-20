/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 18:02:03 by redrouic          #+#    #+#             */
/*   Updated: 2025/01/13 13:43:54 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void	init_cmd(t_cmd *cmd)
{
	cmd->args = NULL;
	cmd->redir = NULL;
	cmd->infile = -1;
	cmd->outfile = -1;
	cmd->prev_fd = -1;
	cmd->pipe[0] = -1;
	cmd->pipe[1] = -1;
}

static void	cat_quot_str(char *dest, char *line, int *i, int *j)
{
	char	quote_char;
	int		len;

	len = ft_strlen(line);
	while (*j < len)
	{
		if (line[*j] == '"' || line[*j] == '\'')
		{
			quote_char = line[*j];
			dest[(*i)++] = line[(*j)++];
			while (*j < len && line[*j] != quote_char)
				dest[(*i)++] = line[(*j)++];
			if (*j < len)
				dest[(*i)++] = line[(*j)++];
		}
		else if (!is_chr(" \t><", line[*j]))
			dest[(*i)++] = line[(*j)++];
		else
			break ;
	}
}

static int	fill_redir(t_global *g, int i, char **li, int l)
{
	int		j[2];

	if (l < (int)ft_strlen(li[i]))
	{
		g->cmds[i]->redir = ft_calloc(sizeof(char), (ft_strlen(li[i]) - l + 2));
		if (!g->cmds[i]->redir)
			return (ft_perror(EALL, 0), free_g(g, li), exit(1), (int)-1);
		j[0] = 0;
		j[1] = l;
		while (j[1] < (int)ft_strlen(li[i]))
		{
			if (is_chr("><", li[i][j[1]]))
			{
				while (j[1] < ft_strlen(li[i]) && (is_chr("><", li[i][j[1]])
					|| is_chr(" \t", li[i][j[1]])))
					g->cmds[i]->redir[j[0]++] = li[i][j[1]++];
				cat_quot_str(g->cmds[i]->redir, li[i], &j[0], &j[1]);
			}
			else
				j[1]++;
		}
		return (g->cmds[i]->redir[j[0]] = '\0', (int)j[0] - 1);
	}
	return (l);
}

static void	fill_s_cmd(t_global *g, int id, char **arr, int t[3])
{
	char	*cmd_line;
	char	*tmp;

	cmd_line = ft_calloc(sizeof(char), (ft_strlen(arr[id]) + 1));
	if (!cmd_line)
		return (ft_perror(EALL, 0), free_g(g, arr), exit(1), (void)0);
	while (arr[id][++t[0]])
		if (is_chr("><", arr[id][t[0]]) && !inq(arr[id], t[0], 0))
			break ;
	(init_cmd(g->cmds[id]), t[2] = fill_redir(g, id, arr, t[0]));
	(ft_strncpy(cmd_line, arr[id], t[0]), t[1] = t[0]);
	while (t[0] < (int)ft_strlen(arr[id]) && arr[id][t[0]])
	{
		if (t[0] < t[2])
			t[0] = t[2];
		if (arr[id][t[0]] && arr[id][t[0]] == ' '
				&& !is_chr(">< \t", arr[id][t[0] - 1]))
			while (arr[id][t[0]] && !is_chr("><", arr[id][t[0]]))
				cmd_line[t[1]++] = arr[id][t[0]++];
		t[0]++;
	}
	cmd_line[t[1]] = '\0';
	tmp = gest_expand(g, cmd_line);
	g->cmds[id]->args = str2arr(tmp, " \t", true);
	(free(cmd_line), free(tmp));
}

void	init_s_cmd(t_global *g, char *line)
{
	char	**arr;
	int		i;
	int		t[3];

	g->cnt = count_rows("|", line, true);
	g->cmds = ft_calloc(sizeof(t_cmd *), (g->cnt + 1));
	if (!g->cmds)
		return (ft_perror(EALL, 0), free(line), exit(1), (void)0);
	arr = str2arr(line, "|", true);
	if (!arr)
		return (ft_perror(EALL, 0), free_g(g, 0), free(line), exit(1), (void)0);
	i = 0;
	while (i < g->cnt)
	{
		g->cmds[i] = ft_calloc(sizeof(t_cmd), 1);
		if (!g->cmds[i])
			return (ft_perror(EALL, 0), (void)0);
		t[0] = -1;
		fill_s_cmd(g, i, arr, t);
		if (!g->cmds[i]->args)
			return (ft_perror(EALL, 0), free_g(g, arr), exit(1), (void)0);
		i++;
	}
	g->cmds[i] = NULL;
	free_arr(arr);
}
