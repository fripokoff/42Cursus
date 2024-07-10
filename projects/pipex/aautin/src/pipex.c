/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:50:03 by aautin            #+#    #+#             */
/*   Updated: 2024/06/18 16:04:19 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	parent_process(t_conf *conf)
{
	close(conf->fds.pipe[1]);
	dup2(conf->fds.pipe[0], STDIN_FILENO);
	close(conf->fds.pipe[0]);
}

void	pipex(t_conf *conf)
{
	int		i;
	pid_t	pid;

	i = conf->first_cmd;
	while (i <= conf->last_cmd)
	{
		
		if (pipe(conf->fds.pipe) == -1)
			perror_exit("pipe");
		pid = fork();
		if (pid == -1)
			perror_exit("fork");
		else if (pid == 0)
			child_process(conf, i);
		else
			parent_process(conf);
		i++;
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_conf	conf;

	conf.is_here_doc = 0;
	if (argc == 5)
	{
		init_conf(&conf, argc, argv, envp);
		pipex(&conf);
		while (waitpid(-1, NULL, 0) > 0)
			;
	}
	else
		ft_printf("Wrong number of arguments\n");
	return (0);
}
