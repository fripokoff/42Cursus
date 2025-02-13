/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:48:41 by redrouic          #+#    #+#             */
/*   Updated: 2025/01/12 16:08:48 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_putchar(char c)
{
	write(2, &c, 1);
}

void	ft_perror(const char *str, char *tok)
{
	while (*str)
		ft_putchar(*str++);
	if (tok)
	{
		ft_putchar('`');
		while (*tok)
			ft_putchar(*tok++);
		ft_putchar('\'');
		ft_putchar('\n');
	}
}
