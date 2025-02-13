/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_one.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:20:05 by kpires            #+#    #+#             */
/*   Updated: 2025/01/12 20:15:37 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_waitall(t_global *g)
{
	int	pid;
	int	exit_status;

	while (42)
	{
		pid = wait(&exit_status);
		if (pid == g->last_pid)
		{
			if (WIFEXITED(exit_status))
				g->exit_val = WEXITSTATUS(exit_status);
		}
		if (g_signal != 0)
			g->exit_val = 128 + g_signal;
		if (pid == -1)
			break ;
	}
}

int	close_fd(t_global *g, int *std_save, bool is_error)
{
	if (g->cmds[std_save[2]]->infile != -1)
	{
		if (dup2(std_save[0], 0) == -1 || is_error)
		{
			close(std_save[0]);
			if (g->cmds[std_save[2]]->outfile != -1)
				close(std_save[1]);
			if (is_error)
				(free_g(g, NULL), exit(1));
		}
		close(std_save[0]);
	}
	if (g->cmds[std_save[2]]->outfile != -1)
	{
		if (dup2(std_save[1], 1) == -1 || is_error)
		{
			close(std_save[1]);
			if (is_error)
				(free_g(g, NULL), exit(1));
		}
		close(std_save[1]);
	}
	return (1);
}

static int	dup_inf_out(t_global *g, int *std_save)
{
	if (g->cmds[std_save[2]]->infile != -1)
	{
		std_save[0] = dup(0);
		if (std_save[0] == -1)
			return (1);
		if (dup2(g->cmds[std_save[2]]->infile, 0) == -1)
		{
			close(std_save[0]);
			return (1);
		}
	}
	if (g->cmds[std_save[2]]->outfile != -1)
	{
		std_save[1] = dup(1);
		if (std_save[1] == -1)
			return (close_fd(g, std_save, true));
		if (dup2(g->cmds[std_save[2]]->outfile, 1) == -1)
			return (close_fd(g, std_save, true));
	}
	return (0);
}

static void	gest_shell(t_global *g, int id, int *std_save)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (ft_perror("Error :Fork failed\n", 0),
			free_g(g, NULL), exit(0), (void)0);
	else if (pid == 0)
	{
		if (g->cmds[id]->infile != -1)
			(close(std_save[0]), close(g->cmds[id]->infile));
		if (g->cmds[id]->outfile != -1)
			(close(std_save[1]), close(g->cmds[id]->outfile));
		execve_cmd(g, id);
	}
	g->last_pid = pid;
	ft_waitall(g);
}

int	exec_cmd(t_global *g, int id)
{
	int		std_save[3];

	if (set_check_cmd(g, 0))
		return (1);
	std_save[2] = id;
	if (dup_inf_out(g, std_save) == 1)
	{
		ft_perror("Exec: error with dup\n", 0);
		g->exit_val = 1;
		return (g->exit_val);
	}
	if (gest_builtins(g, g->cmds[id]) == NONE)
		gest_shell(g, id, std_save);
	close_fd(g, std_save, false);
	return (g->exit_val);
}
