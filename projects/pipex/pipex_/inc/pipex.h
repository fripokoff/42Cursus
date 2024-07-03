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

# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include "ft_printf.h"
# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>

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

int	ft_pipex(t_pipex *pipex);

#endif