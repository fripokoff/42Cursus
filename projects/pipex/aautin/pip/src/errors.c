/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:47:25 by kpires            #+#    #+#             */
/*   Updated: 2024/06/18 12:47:25 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	command_not_found(char *cmd)
{
	ft_putstr_fd("command not found: ", 2);
	ft_putendl_fd(cmd, 2);
	exit(EXIT_FAILURE);
}

void	perror_exit(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}