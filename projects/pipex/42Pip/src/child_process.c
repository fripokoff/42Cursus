/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:55:34 by aautin            #+#    #+#             */
/*   Updated: 2024/01/18 17:13:26 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	init_input(t_conf *conf, int i)
{
	if (i == conf->first_cmd)
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
