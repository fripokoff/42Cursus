/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:48:56 by kpires            #+#    #+#             */
/*   Updated: 2024/06/14 16:48:56 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void parent_process(t_conf *config)
{
	ft_printf("parent process\n");
	close(config->fds.pipe[1]);
	dup2(config->fds.pipe[0], STDIN_FILENO);
	close(config->fds.pipe[0]);
}

void pipex(t_conf *config)
{
	int		i;
	pid_t	pid;

	i = config->first_cmd;
	while (i <= config->last_cmd)
	{
		printf("Executing command: %s\n", config->av[i]);
		if(pipe(config->fds.pipe) == -1)
			perror_exit("pipe");
		pid = fork();
		if (pid == -1)
			perror_exit("fork");
		else if (pid == 0)
			child_process(config, i);
		else
			parent_process(config);
		i++;
	}
}

int	main(int ac, char **av, char **ep)
{
	t_conf	config;

	if (ac == 5)
	{
		init_config(&config, ac, av, ep);
		pipex(&config);
		while (waitpid(-1, NULL, 0) > 0)
			;
	}
	else
		ft_printf("Wrong number of arguments\n");
	return (0);
}
