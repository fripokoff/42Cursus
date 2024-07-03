/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:50:06 by aautin            #+#    #+#             */
/*   Updated: 2024/01/18 16:32:13 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	cut_cmd(t_conf *conf, char *cmd)
{
	conf->cut_i = 0;
	while (cmd[conf->cut_i] && cmd[conf->cut_i] != ' ')
		conf->cut_i++;
	conf->previous_letter = cmd[conf->cut_i];
	cmd[conf->cut_i] = '\0';
}

static void	glue_cmd(t_conf *conf, char *cmd)
{
	cmd[conf->cut_i] = conf->previous_letter;
}

void	close_fds(int fds_nb, ...)
{
	int		i;
	va_list	arg;

	va_start(arg, fds_nb);
	i = 0;
	while (i < fds_nb)
	{
		close(va_arg(arg, int));
		i++;
	}
	va_end(arg);
	return ;
}

void	init_conf(t_conf *conf, int argc, char *argv[], char *envp[])
{
	if (conf->is_here_doc == 1)
	{
		conf->first_cmd = 3;
		conf->last_cmd = 4;
	}
	else
	{
		conf->first_cmd = 2;
		conf->last_cmd = argc - 2;
	}
	conf->argc = argc;
	conf->argv = argv;
	conf->envp = envp;
	conf->fds.outfile = conf->argv[conf->argc - 1];
	conf->fds.infile = conf->argv[1];
}

char	*get_cmd_path(t_conf *conf, char *cmd)
{
	char	**paths;
	char	*cmd_w_path;
	int		i;

	cut_cmd(conf, cmd);
	if (access(cmd, F_OK | X_OK) != -1)
		return (cmd_w_path = ft_strdup(cmd), glue_cmd(conf, cmd), cmd_w_path);
	i = -1;
	while (conf->envp[++i] && ft_strncmp(conf->envp[i], "PATH=", 5))
		;
	if (conf->envp[i] == NULL)
		command_not_found(cmd);
	paths = ft_split(conf->envp[i] + 5, ':');
	if (paths == NULL)
		perror_exit("malloc");
	i = -1;
	while (paths[++i])
	{
		cmd_w_path = ft_strjoin(ft_strjoin(paths[i], "/", 0), cmd, 1);
		if (access(cmd_w_path, F_OK | X_OK) != -1)
			return (glue_cmd(conf, cmd), free_stab(paths), cmd_w_path);
		free(cmd_w_path);
	}
	return (free_stab(paths), command_not_found(cmd), NULL);
}
