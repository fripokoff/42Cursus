/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:50:03 by aautin            #+#    #+#             */
/*   Updated: 2024/01/18 17:01:25 by aautin           ###   ########.fr       */
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
	char	is_args_nb_correct;

	if (argc > 1)
	{
		conf.is_here_doc = (ft_strnstr(argv[1], "here_doc",
					ft_strlen(argv[1])) != 0);
		if (conf.is_here_doc)
			is_args_nb_correct = (argc == 6);
		else
			is_args_nb_correct = (argc >= 5);
	}
	else
		is_args_nb_correct = 0;
	if (is_args_nb_correct)
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
