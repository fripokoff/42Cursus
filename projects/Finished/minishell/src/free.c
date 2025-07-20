/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:54:11 by kpires            #+#    #+#             */
/*   Updated: 2025/01/12 16:14:34 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	free_list(t_env *list)
{
	t_env	*tmp;

	while (list != NULL)
	{
		tmp = list;
		list = list->next;
		ft_free_node(tmp);
	}
}

void	free_g(t_global *g, char **arr)
{
	if (!g)
		return ;
	if (g->cmds)
		free_cmds(g);
	if (g->lenv)
		free_list(g->lenv);
	if (arr)
		free_arr(arr);
}

void	free_cmd(t_cmd *cmd)
{
	if (!cmd)
		return ;
	if (cmd->args)
	{
		free_arr(cmd->args);
		cmd->args = NULL;
	}
	if (cmd->redir)
	{
		free(cmd->redir);
		cmd->redir = NULL;
	}
	if (cmd->infile > 2)
		close(cmd->infile);
	if (cmd->outfile > 2)
		close(cmd->outfile);
	free(cmd);
}

void	free_cmds(t_global *g)
{
	int	i;

	if (!g || !g->cmds)
		return ;
	close_all_fd_child(g);
	i = 0;
	while (i < g->cnt && g->cmds[i])
	{
		free_cmd(g->cmds[i]);
		g->cmds[i] = NULL;
		i++;
	}
	free(g->cmds);
	g->cmds = NULL;
}
