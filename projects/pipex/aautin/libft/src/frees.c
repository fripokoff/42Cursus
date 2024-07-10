/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:26:06 by aautin            #+#    #+#             */
/*   Updated: 2023/12/29 16:06:00 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdarg.h>

static void	free_it(char type, va_list args)
{
	char	*p_s;
	char	**pp_s;
	int		*p_d;
	int		**pp_d;

	if (type == 's')
	{
		p_s = va_arg(args, char *);
		free(p_s);
	}
	if (type == 'S')
	{
		pp_s = va_arg(args, char **);
		free_stab(pp_s);
	}
	if (type == 'd')
	{
		p_d = va_arg(args, int *);
		free(p_d);
	}
	if (type == 'D')
	{
		pp_d = va_arg(args, int **);
		free_db_dtab(pp_d, va_arg(args, int));
	}
}

void	frees(int frees_nb, ...)
{
	int		i;
	va_list	args;

	va_start(args, frees_nb);
	i = 0;
	while (i < frees_nb)
	{
		free_it(va_arg(args, int), args);
		i++;
	}
	va_end(args);
}
