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

static	void	ft_redirect(t_pipex *pipex, int i)
{
	if (i == 0)
	{
		close(pipex->fd[0]);
		dup2(pipex->fd[1], 1);
		close(pipex->fd[1]);
	}
	else if(i == pipex->cmds_count -1)
	{
		close(pipex->fd[1]);
		dup2(pipex->prev_fd, 0);
		close(pipex->fd[0]);
	}
	else
	{
		dup2(pipex->prev_fd, 0);
		dup2(pipex->fd[1], 1);
		close(pipex->fd[0]);
	}
}

static void	ft_child_process(t_pipex *pipex, int i)
{
	ft_redirect(pipex, i);
}

static void	ft_parent_process(t_pipex *pipex, int i)
{
	close(pipex->fd[1]);
	if(pipex->prev_fd != -1)
		close(pipex->prev_fd);
	pipex->prev_fd = pipex->fd[0];
	if(i == pipex->cmds_count - 1)
	{
		close(pipex->fd[0]);
		close(pipex->prev_fd);
	}
}

int	ft_pipex(t_pipex *pipex)
{
	int	i;
	int	code;

	i = 0;
	code = 0;
	pipex->prev_fd = -1;
	printf("ft pipex\n");
	while(i < pipex->cmds_count)
	{
		pipe(pipex->fd);
		pipex->pid[i] = fork();
		if(pipex->pid[i] == -1)
		{
			ft_putstr_fd("Error: Fork failed\n", 2);
			return(1);
		}
		if(pipex->pid[i] == 0)
		{
			printf("im child with %d \n", pipex->pid[i]);
			ft_child_process(pipex, i);
		}
		else
		{
			printf("im father with %d \n", pipex->pid[i]);
			ft_parent_process(pipex, i);
		}
		i++;
	}
	return (code);
}