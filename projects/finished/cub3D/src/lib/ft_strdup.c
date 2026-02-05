/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:55:40 by kpires            #+#    #+#             */
/*   Updated: 2025/07/11 11:45:06 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_strdup(char *src, char **dest)
{
	size_t	len;
	size_t	i;

	if (!src || !dest)
		return ;
	len = ft_strlen(src);
	*dest = malloc(len + 1);
	if (!*dest)
		return ;
	i = 0;
	while (i < len)
	{
		(*dest)[i] = src[i];
		i++;
	}
	(*dest)[i] = '\0';
}
