/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:49:46 by kpires            #+#    #+#             */
/*   Updated: 2024/06/18 12:49:46 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	init_infile(t_conf *config, int i)
{
	if (i == config->first_cmd)
	{
		config->fds.infl_fd = open(config->fds.infile, O_RDONLY);
		if(config->fds.infl_fd == -1)
			perror_exit(config->fds.infile);
		dup2(config->fds.infl_fd, STDIN_FILENO);
		close(config->fds.infl_fd);
		close(config->fds.pipe[0]);
	}
	else
		close(config->fds.pipe[0]);
}

static void init_outfile(t_conf *config, int i)
{
	if (i == config->last_cmd)
	{
		config->fds.outfl_fd = open(config->fds.outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if(config->fds.outfl_fd == -1)
			perror_exit(config->fds.outfile);
		dup2(config->fds.outfl_fd, STDIN_FILENO);
		close(config->fds.outfl_fd);
		close(config->fds.pipe[1]);
	}
	else
	{
		dup2(config->fds.pipe[1], STDOUT_FILENO);
		close(config->fds.pipe[1]);
	}
}

void	child_process(t_conf *config, int i)
{
	char	*cmd_path;
	char	**cmd_w_options;

	init_infile(config, i);
	init_outfile(config, i);
	cmd_path = get_cmd_path(config, config->av[i]);
	ft_printf("cmd path [%s]\n", cmd_path);
	cmd_w_options = ft_split(config->av[i], ' ');
	if (cmd_w_options == NULL)
		perror_exit("malloc");
	printf("Executing command: %s\n", config->av[i]);
	int j = 0;
	while (cmd_w_options[j])
	{
		ft_printf("cmd_w_options[%d] = %s\n", j, cmd_w_options[j]);
		j++;
	}
}