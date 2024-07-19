/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:54:55 by kpires            #+#    #+#             */
/*   Updated: 2024/07/03 12:54:55 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_redirect(t_pipex *pipex, int i)
{
	if (i == 0)
	{
		close(pipex->fd[0]);
		dup2(pipex->fd[1], 1);
		close(pipex->fd[1]);
	}
	else if (i == pipex->cmds_count - 1)
	{
		close(pipex->fd[1]);
		dup2(pipex->prev_fd, 0);
		close(pipex->prev_fd);
		close(pipex->fd[0]);
	}
}

static void	ft_open_file(t_pipex	*pipex, int i)
{
	if (i == 0)
	{
		pipex->in_fd = open(pipex->in, RD);
		if (pipex->in_fd == -1)
			handle_error(errno, pipex, 1);
		dup2(pipex->in_fd, 0);
		close(pipex->in_fd);
	}
	else if (i >= pipex->cmds_count -1)
	{
		pipex->out_fd = open(pipex->out, WR | CR | TR, 0644);
		if (pipex->out_fd == -1)
			handle_error(errno, pipex, 1);
		dup2(pipex->out_fd, 1);
		close(pipex->out_fd);
	}
}

static void	ft_child_process(t_pipex *pipex, int i)
{
	ft_redirect(pipex, i);
	if (i == 0 || i == pipex->cmds_count -1)
		ft_open_file(pipex, i);
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	ft_execve(pipex->cmds[i], pipex);
}

static void	ft_parent_process(t_pipex *pipex, int i)
{
	close(pipex->fd[1]);
	if (pipex->prev_fd != -1)
	{
		close(pipex->prev_fd);
		pipex->prev_fd = -1;
	}
	pipex->prev_fd = pipex->fd[0];
	if (i == pipex->cmds_count - 1)
	{
		close(pipex->fd[0]);
		pipex->fd[0] = -1;
	}
}

int	ft_pipex(t_pipex *pipex)
{
	int	i;
	int	ret;

	i = 0;
	pipex->prev_fd = -1;
	while (i < pipex->cmds_count)
	{
		pipe(pipex->fd);
		pipex->pid[i] = fork();
		if (pipex->pid[i] == -1)
		{
			ft_putstr_fd("Error: Fork failed\n", 2);
			return (1);
		}
		if (pipex->pid[i] == 0)
			ft_child_process(pipex, i);
		else
			ft_parent_process(pipex, i);
		i++;
	}
	ret = ft_waitpid(pipex);
	return (ret);
}
