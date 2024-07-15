/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:33:34 by kpires            #+#    #+#             */
/*   Updated: 2024/07/10 12:33:34 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_find_path(char **split_path, char *cmd)
{
	int		i;
	char	*path;
	char	*tmp_free;

	i = 0;
	while (split_path[i])
	{
		path = ft_strjoin(split_path[i], "/");
		tmp_free = path;
		path = ft_strjoin(path, cmd);
		free(tmp_free);
		if (access(path, F_OK | X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

static char	*ft_get_path(char *cmd, char **env_vars)
{
	int		i;
	char	**split_path;
	char	*path;

	i = -1;
	if (ft_strchr(cmd, '/'))
		return (cmd);
	while (env_vars[++i])
		if (ft_strncmp(env_vars[i], "PATH=", 5) == 0)
			break ;
	if (!env_vars[i])
	{
		ft_putstr_fd("Error: Path not found\n", 2);
		exit(1);
	}
	split_path = ft_split(env_vars[i] + 5, ':');
	if (!split_path)
	{
		ft_putstr_fd("Error: Split failed\n", 2);
		exit(1);
	}
	path = ft_find_path(split_path, cmd);
	ft_free(split_path);
	return (path);
}

static void	do_exec(char *cmd, char **split_cmds, t_pipex *pipex)
{
	if (execve(cmd, split_cmds, pipex->env_vars) != -1)
	{
		ft_free(split_cmds);
		return ;
	}
	perror("Error");
	strerror(errno);
	free(pipex->pid);
	ft_free(split_cmds);
	exit(errno);
}

void	ft_execve(char *cmd, t_pipex *pipex)
{
	char	**split_cmds;

	split_cmds = ft_split(cmd, ' ');
	if (!split_cmds)
	{
		ft_putstr_fd("Error: Split failed\n", 2);
		exit(127);
	}
	if (split_cmds[0] == NULL)
	{
		ft_putstr_fd("Error: Command not found\n", 2);
		ft_free(split_cmds);
		free(pipex->pid);
		exit(127);
	}
	cmd = ft_get_path(split_cmds[0], pipex->env_vars);
	if (cmd == NULL)
	{
		ft_putstr_fd("Error: Command not found\n", 2);
		ft_free(split_cmds);
		free(pipex->pid);
		exit(127);
	}
	do_exec(cmd, split_cmds, pipex);
}
