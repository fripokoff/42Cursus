/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:15:56 by redrouic          #+#    #+#             */
/*   Updated: 2025/01/12 15:57:57 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	g_signal = 0;

static void	handl_int(int sig)
{
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	if (wait(NULL) == -1)
		rl_redisplay();
	g_signal = sig;
}

static void	handl_quit(int sig)
{
	rl_on_new_line();
	if (wait(NULL) == -1)
	{
		printf("\e[2K\r");
		rl_redisplay();
	}
	else
		ft_perror("Quit (core dumped)\n", 0);
	g_signal = sig;
}

void	signal_ctrd(t_global *g)
{
	printf("exit\n");
	if (g)
		free_cmds(g);
	free_list(g->lenv);
	clear_history();
	rl_clear_history();
	exit(g->exit_val);
}

static void	init_g(t_global *g, char **env)
{
	g->lenv = arr2list(env);
	g->exit_val = 0;
	g->cmds = NULL;
	g->cnt = 0;
	g->last_pid = -1;
}

int	main(int ac, char **av, char **env)
{
	t_global	g;
	char		*line;

	init_g(&g, env);
	while (ac && av)
	{
		g_signal = 0;
		(signal(SIGINT, handl_int), signal(SIGQUIT, handl_quit));
		line = readline("( ͡° ͜ʖ ͡°) $> ");
		if (!is_syntax_valid(&g, line))
		{
			free(line);
			continue ;
		}
		init_s_cmd(&g, line);
		if (ft_redir(&g, -1, 0))
			ft_exec(&g);
		else
			g.exit_val = 2;
		(free(line), free_cmds(&g));
	}
	(clear_history(), rl_clear_history());
	return (free_g(&g, NULL), 0);
}
