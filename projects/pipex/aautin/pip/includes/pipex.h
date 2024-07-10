/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:04:47 by aautin            #+#    #+#             */
/*   Updated: 2024/06/18 14:04:29 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define WR O_WRONLY
# define CR O_CREAT
# define TR O_TRUNC

# include "../libft/includes/libft_extended.h"
# include <stdarg.h>
# include <errno.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>

typedef struct s_fds
{
	int		pipe[2];
	int		infl_fd;
	int		outfl_fd;
	char	*infile;
	char	*outfile;
}	t_fds;

typedef struct s_conf
{
	t_fds	fds;
	int		cut_i;
	char	previous_letter;
	char	is_here_doc;
	int		first_cmd;
	int		last_cmd;
	int		ac;
	char	**av;
	char	**ep;
}	t_conf;


void	init_config(t_conf *config, int ac, char **av, char **ep);
void	perror_exit(char *msg);
void	child_process(t_conf *config, int i);
char	*get_cmd_path(t_conf *config, char *cmd);
void	command_not_found(char *cmd);
void	pipex(t_conf *config);

#endif