/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:55:34 by aautin            #+#    #+#             */
/*   Updated: 2024/01/18 16:37:31 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	here_doc_child_process(t_conf *conf, int pipe[2])
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL && (ft_strlen(line) - 1 != ft_strlen(conf->argv[2])
			|| ft_strncmp(line, conf->argv[2], ft_strlen(conf->argv[2]))))
	{
		write(pipe[1], line, ft_strlen(line));
		free(line);
		line = get_next_line(0);
	}
	if (line)
		free(line);
	close_fds(4, pipe[0], pipe[1], conf->fds.pipe[0], conf->fds.pipe[1]);
	exit(EXIT_SUCCESS);
}

static void	here_doc(t_conf *conf, int pipe[2])
{	
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		perror_exit("fork");
	if (pid == 0)
		here_doc_child_process(conf, pipe);
	close(conf->fds.pipe[0]);
	close(pipe[1]);
	dup2(pipe[0], STDIN_FILENO);
	close(pipe[0]);
	waitpid(pid, NULL, 0);
}

static void	init_input(t_conf *conf, int i)
{
	int		pipe_fd[2];

	if (i == conf->first_cmd && conf->is_here_doc)
	{
		if (pipe(pipe_fd) == -1)
			perror_exit("pipe");
		here_doc(conf, pipe_fd);
	}
	else if (i == conf->first_cmd)
	{
		conf->fds.infl_fd = open(conf->fds.infile, O_RDONLY);
		if (conf->fds.infl_fd == -1)
			perror_exit(conf->fds.infile);
		dup2(conf->fds.infl_fd, STDIN_FILENO);
		close(conf->fds.infl_fd);
		close(conf->fds.pipe[0]);
	}
	else
		close(conf->fds.pipe[0]);
}	

static void	init_output(t_conf *conf, int i)
{
	if (i == conf->last_cmd)
	{
		conf->fds.outfl_fd = open(conf->fds.outfile, WR | CR | TR, 0644);
		if (conf->fds.outfl_fd == -1)
			perror_exit(conf->fds.outfile);
		dup2(conf->fds.outfl_fd, STDOUT_FILENO);
		close(conf->fds.outfl_fd);
		close(conf->fds.pipe[1]);
	}
	else
	{
		dup2(conf->fds.pipe[1], STDOUT_FILENO);
		close(conf->fds.pipe[1]);
	}
}

void	child_process(t_conf *conf, int i)
{
	char	*cmd_path;
	char	**cmd_w_options;

	init_input(conf, i);
	init_output(conf, i);
	cmd_path = get_cmd_path(conf, conf->argv[i]);
	cmd_w_options = ft_split(conf->argv[i], ' ');
	if (cmd_w_options == NULL)
		perror_exit("malloc");
	execve(cmd_path, cmd_w_options, NULL);
	free(cmd_path);
	free_stab(cmd_w_options);
	perror_exit("execve");
}
