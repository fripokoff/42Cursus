/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 01:34:17 by redrouic          #+#    #+#             */
/*   Updated: 2025/01/13 13:45:24 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static char	*check_access(t_env *lenv, char **arr)
{
	char	**tab;
	char	*path;
	int		i;

	i = 0;
	path = plist(lenv, "PATH");
	if (!path)
		return (NULL);
	tab = str2arr(path, ":", false);
	free(path);
	if (!tab)
		return (NULL);
	path = NULL;
	while (tab[i] != NULL)
	{	
		path = pwrapper(tab[i++], arr[0], '/');
		if (!path)
			return (free_arr(tab), NULL);
		if (access(path, X_OK) == 0)
			return (free_arr(tab), path);
		free(path);
		path = NULL;
	}
	return (free_arr(tab), NULL);
}

void	execve_absolute_path(t_global *g, int id)
{
	char	**lenv;

	lenv = list2arr(g->lenv);
	if (execve(g->cmds[id]->args[0], g->cmds[id]->args, lenv) == -1)
	{
		if (access(g->cmds[id]->args[0], F_OK) == 0)
		{
			if (access(g->cmds[id]->args[0], X_OK) != 0)
			{
				ft_perror(g->cmds[id]->args[0], 0);
				ft_perror(": Permission denied\n", 0);
			}
			else
			{
				ft_perror(g->cmds[id]->args[0], 0);
				ft_perror(": Is a directory\n", 0);
			}
			(free_g(g, lenv), exit(126));
		}
		else
			perror(g->cmds[id]->args[0]);
		(free_g(g, lenv), exit(127));
	}
}

void	execve_cmd_path(t_global *g, int id)
{
	char	*path;
	char	**lenv;
	int		i;

	i = 0;
	while (g->cmds[id]->args[0][i] && is_chr(".'\"", g->cmds[id]->args[0][i]))
		i++;
	if (g->cmds[id]->args[0][i] == '\0')
		path = NULL;
	else
		path = check_access(g->lenv, g->cmds[id]->args);
	lenv = list2arr(g->lenv);
	if (!path)
	{
		ft_perror(g->cmds[id]->args[0], 0);
		ft_perror(": command not found\n", 0);
		(free_g(g, lenv), exit(127));
	}
	if (execve(path, g->cmds[id]->args, lenv) == -1)
	{
		perror("execve");
		(free_g(g, lenv), free(path), exit(1));
	}
}

void	execve_cmd(t_global *g, int id)
{
	int		i;

	if (g->cmds[id] == NULL)
	{
		if (g->cmds[id + 1])
			execve_cmd(g, id + 1);
		return ;
	}
	i = 0;
	while (g->cmds[id]->args[0][i])
	{
		if (g->cmds[id]->args[0][i] == '/')
		{
			execve_absolute_path(g, id);
			return ;
		}
		i++;
	}
	execve_cmd_path(g, id);
}
