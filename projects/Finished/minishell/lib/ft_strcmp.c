/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 00:23:00 by redrouic          #+#    #+#             */
/*   Updated: 2025/01/11 17:20:21 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

bool	ft_strcmp(char *s1, char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (false);
	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (false);
		i++;
	}
	return (s1[i] == s2[i]);
}
