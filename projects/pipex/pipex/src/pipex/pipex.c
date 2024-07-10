/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:29:19 by kpires            #+#    #+#             */
/*   Updated: 2024/07/03 12:29:19 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_waitpid(t_pipex *pipex)
{
	int	i;
	int	status;
	int	exit_status;
	int	pid;

	i = 0;
	while (i < pipex->cmds_count)
	{
		pid = waitpid(-1, &status, 0);
		if (WIFEXITED(status))
			if (pid == pipex->pid[pipex->cmds_count - 1])
				exit_status = WEXITSTATUS(status);
		i++;
	}
	return (exit_status);
}

void	init_pipex(t_pipex *pipex, int ac, char **av, char **env)
{
	pipex->cmds = &av[2];
	pipex->in = av[1];
	pipex->out = av[ac - 1];
	pipex->env_vars = env;
	pipex->cmds_count = ac - 3;
	pipex->pid = malloc(sizeof(int) * (pipex->cmds_count));
	if (!pipex->pid)
	{
		ft_putstr_fd("Error: malloc failed\n", 2);
		exit(1);
	}
}

int	main(int ac, char **av, char **env)
{
	int		code;
	t_pipex	pipex;

	if (ac != 5)
	{
		ft_putstr_fd("Usage: ./pipex filein cmd1 cmd2 fileout\n", 2);
		exit(1);
	}
	init_pipex(&pipex, ac, av, env);
	code = ft_pipex(&pipex);
	free(pipex.pid);
	close(pipex.fd[0]);
	close(pipex.fd[1]);
	return (code);
}
