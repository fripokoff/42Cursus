/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:39:09 by kpires            #+#    #+#             */
/*   Updated: 2024/01/24 12:52:17 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#include "../include/pipex.h"
#include "../libft/libft.h"

int	main(void)
{
	char	*hello = "hello";
	ft_printf("il a dis : %s", hello);
	return (0);
}
