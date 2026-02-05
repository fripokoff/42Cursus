/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:32:43 by kpires            #+#    #+#             */
/*   Updated: 2023/11/29 17:10:05 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*
** #include <stdio.h>
** #include <stdlib.h>
** int		main(int argc, const char *argv[])
** {
** 	if (argc == 1)
** 		return (0);
** 	printf( " result : %d" ,ft_isascii(atoi(argv[1])));
** 	return (0);
** }
*/