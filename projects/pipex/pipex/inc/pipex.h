/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:03:16 by kpires            #+#    #+#             */
/*   Updated: 2024/06/12 18:03:16 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define RD O_RDONLY
# define WR O_WRONLY
# define CR O_CREAT
# define TR O_TRUNC

# include "ft_printf.h"
# include "libft.h"
# include "get_next_line.h"
# include <errno.h>
# include <fcntl.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex
{
	char	**cmds;
	char	*in;
	char	*out;
	char	**env_vars;
	int		prev_fd;
	int		in_fd;
	int		out_fd;
	int		fd[2];
	int		*pid;
	int		cmds_count;

}			t_pipex;

int		ft_pipex(t_pipex *pipex);
int		ft_waitpid(t_pipex *pipex);
void	ft_execve(char *cmd, t_pipex *pipex);
void	ft_open_file(t_pipex	*pipex, int i);
void	ft_redirect(t_pipex *pipex, int i);
void	ft_child_process(t_pipex *pipex, int i);
void	ft_parent_process(t_pipex *pipex, int i);
void	do_exec(char *cmd, char **split_cmds, t_pipex *pipex);
char	*ft_get_path(char *cmd, char **env_vars);
char	*ft_find_path(char **split_path, char *cmd);
void	init_pipex(t_pipex *pipex, int ac, char **av, char **env);
#endif