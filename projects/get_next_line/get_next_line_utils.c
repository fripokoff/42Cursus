/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:50:45 by kpires            #+#    #+#             */
/*   Updated: 2024/01/16 15:38:43 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2, int new_line_i)
{
	int		i;
	int		j;
	char	*line;

	if (!new_line_i)
		new_line_i = ft_strlen(s2);
	line = malloc(sizeof(char) * (new_line_i + ft_strlen(s1)) + 1);
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
