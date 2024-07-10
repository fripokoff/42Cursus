/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:12:58 by kpires            #+#    #+#             */
/*   Updated: 2024/06/13 10:58:55 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s1)
{
	int	i;

	i = 0;
	if (!s1)
		return (0);
	while (s1[i])
		i++;
	return (i);
}

char	*ft_strjoin_printf(char *s1, char *s2, size_t new_line_i)
{
	size_t	i;
	size_t	j;
	char	*line;

	if (!new_line_i)
		new_line_i = ft_strlen(s2);
	line = malloc(sizeof(char) * (ft_strlen(s1) + new_line_i) + 1);
	if (!line)
		return (free(s1), NULL);
	i = -1;
	j = -1;
	if (s1)
		while (s1[++i])
			line[i] = s1[i];
	else
		i++;
	while (++j < new_line_i)
		line[i + j] = s2[j];
	line[i + j] = '\0';
	return (free(s1), line);
}
