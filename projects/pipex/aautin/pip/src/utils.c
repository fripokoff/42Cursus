/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:51:56 by kpires            #+#    #+#             */
/*   Updated: 2024/06/14 16:51:56 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_config(t_conf *config, int ac, char **av, char **ep)
{
	config->first_cmd = 2;
	config->last_cmd = ac - 2;
	config->ac = ac;
	config->av = av;
	config->ep = ep;
	config->fds.outfile =  config->av[ac - 1];
	config->fds.infile = config->av[1];
	ft_printf("configured \n");
}

static void	glue_cmd(t_conf *config, char *cmd)
{
	cmd[config->cut_i] = config->previous_letter;
}

static void	cut_cmd(t_conf *config, char *cmd)
{
	config->cut_i = 0;
	while (cmd[config->cut_i] && cmd[config->cut_i] != ' ')
		config->cut_i++;
	config->previous_letter = cmd[config->cut_i];
	cmd[config->cut_i] = '\0';
}

char	*get_cmd_path(t_conf *config, char *cmd)
{
	char	**paths;
	char	*cmd_w_path;
	int		i;

	cut_cmd(config, cmd);
	if (access(cmd, F_OK | X_OK) != -1)
		return (cmd_w_path = ft_strdup(cmd), glue_cmd(config, cmd), cmd_w_path);
	i = -1;
	while (config->ep[++i] && ft_strncmp(config->ep[i], "PATH=", 5))
		;
	if (config->ep[i] == NULL)
		command_not_found(cmd);
	paths = ft_split(config->ep[i] + 5, ':');
	if (paths == NULL)
		perror_exit("malloc");
	i = -1;
	while (paths[++i])
	{
		cmd_w_path = ft_strjoin(ft_strjoin(paths[i], "/", 0), cmd, 1);
		if (access(cmd_w_path, F_OK | X_OK) != -1)
			return (glue_cmd(config, cmd), free_stab(paths), cmd_w_path);
		free(cmd_w_path);
	}
	return (free_stab(paths), command_not_found(cmd), NULL);
}
