/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 00:30:48 by redrouic          #+#    #+#             */
/*   Updated: 2025/01/12 17:10:08 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_exit(t_global *g, t_cmd *cmd, bool print)
{
	int	nb;

	if (print)
		printf("exit\n");
	if (!cmd->args[1] || cmd->args[1] == NULL)
		(free_g(g, NULL), exit(g->exit_val));
	if ((ft_is_nb(cmd->args[1]) || ft_strlen(cmd->args[1]) >= 19)
		&& ((ft_strncmp("9223372036854775807", cmd->args[1], 19) < 0
				&& cmd->args[1][0] != '-')
		|| (ft_strncmp("-9223372036854775808", cmd->args[1], 20) < 0
			&& cmd->args[1][0] == '-')))
	{
		(ft_perror("exit: ", 0), ft_perror(cmd->args[1], 0));
		ft_perror(": numeric argument required\n", 0);
		(free_g(g, NULL), exit(2));
	}
	if (ft_is_nb(cmd->args[1]) == 0 && cmd->args[1] && cmd->args[2] == NULL)
	{
		nb = ft_atoi(cmd->args[1]);
		(free_g(g, NULL), exit(nb % 256));
	}
	ft_perror("exit: too many arguments\n", 0);
	g->exit_val = 1;
	return (1);
}

static t_state	ft_echo(t_global *g, t_cmd *cmd)
{
	int	i;

	i = 1;
	if (cmd->args[1] && ft_strcmp(cmd->args[1], "-n"))
		i++;
	while (cmd->args[i] != NULL)
	{
		write(1, cmd->args[i], ft_strlen(cmd->args[i]));
		if (cmd->args[i + 1] != NULL)
			write(1, " ", 1);
		i++;
	}
	if (cmd->args[1] && ft_strcmp(cmd->args[1], "-n"))
		return (g->exit_val = 0, VALID);
	return (write(1, "\n", 1), g->exit_val = 0, VALID);
}

static t_state	gest_env(t_global *g, char **arr)
{
	char	*result;

	if (ft_strcmp(arr[0], "env"))
	{
		if (arr[1])
		{
			(ft_perror("env: '", 0), ft_perror(arr[1], 0));
			ft_perror("': No such file or directory\n", 0);
			return (g->exit_val = 1, ERROR);
		}
		return (plist(g->lenv, NULL), VALID);
	}
	if (ft_strcmp(arr[0], "pwd"))
	{
		result = plist(g->lenv, "PWD");
		if (result)
			return (printf("%s\n", result), free(result), VALID);
		g->exit_val = 1;
		return (ERROR);
	}
	if (ft_strcmp(arr[0], "unset"))
		return (ft_unset(g, &arr[1]), VALID);
	if (ft_strcmp(arr[0], "cd"))
		return (ft_cd(g, arr), VALID);
	return (NONE);
}

t_state	gest_builtins(t_global *g, t_cmd *cmd)
{
	int	i;

	i = 0;
	if (ft_strcmp(cmd->args[0], "export"))
	{
		while (cmd->args[i])
			i++;
		if (i > 1)
			return (ft_export(g, &cmd->args[1], true), VALID);
		return (ft_export(g, &cmd->args[1], false), VALID);
	}
	i = 0;
	while (cmd->args[i])
	{
		cmd->args[i] = remq(cmd->args[i]);
		i++;
	}
	i = 0;
	if (ft_strcmp(cmd->args[0], "exit"))
		return (ft_exit(g, cmd, true));
	if (ft_strcmp(cmd->args[0], "echo"))
		return (ft_echo(g, cmd));
	return (gest_env(g, cmd->args));
}
