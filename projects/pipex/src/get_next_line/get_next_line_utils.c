/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:12:58 by kpires            #+#    #+#             */
/*   Updated: 2024/07/15 15:08:16 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
