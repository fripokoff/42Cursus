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

static char	*ft_get_path(char *cmd, char **cmds, char **env, t_pipex *pipex)
{
	int		i;
	char	**split_path;
	char	*path;

	i = -1;
	if (ft_strchr(cmd, '/'))
		return (cmd);
	while (env[++i])
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			break ;
	if (!env[i])
	{
		ft_free(cmds);
		handle_error(errno, pipex, 127, "Error: Path not found\n");
	}
	split_path = ft_split(env[i] + 5, ':');
	if (!split_path)
	{
		ft_free(cmds);
		handle_error(errno, pipex, 1, "Error: Split failed\n");
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
		if (cmd != split_cmds[0])
			free(cmd);
		return ;
	}
	if (cmd != split_cmds[0])
		free(cmd);
	if (errno == ENOENT || errno == EACCES)
		ft_free(split_cmds);
	if (errno == EACCES)
		handle_error(errno, pipex, 126, NULL);
	else if (errno == ENOENT)
		handle_error(errno, pipex, 127, NULL);
	else
	{
		ft_free(split_cmds);
		perror("Error");
		handle_error(0, pipex, errno, NULL);
	}
}

void	ft_execve(char *cmd, t_pipex *pipex)
{
	char	**split_cmds;

	split_cmds = ft_split(cmd, ' ');
	if (split_cmds == NULL)
		handle_error(0, pipex, 127, "Error: Command not found\n");
	if (split_cmds[0] == NULL)
	{
		ft_free(split_cmds);
		handle_error(0, pipex, 127, "Error: Command not found\n");
	}
	cmd = ft_get_path(split_cmds[0], split_cmds, pipex->env_vars, pipex);
	if (cmd == NULL)
	{
		ft_free(split_cmds);
		handle_error(0, pipex, 127, "Error: Command not found\n");
	}
	do_exec(cmd, split_cmds, pipex);
}
