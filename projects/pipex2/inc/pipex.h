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

# include "libft.h"
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
void	handle_error(int errnum, t_pipex *pipex, int code, char *msg);
#endif