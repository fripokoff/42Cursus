/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:19:21 by kpires            #+#    #+#             */
/*   Updated: 2024/01/18 17:19:21 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_new_line(char *save_line)
{
	int	i;

	if (!save_line)
		return (0);
	i = -1;
	while (save_line[++i])
		if (save_line[i] == '\n')
			return (i + 1);
	return (0);
}

int	ft_read_buffer(int fd, char *save_line)
{
	if (save_line[0] != '\0')
		return (1);
	if (read(fd, save_line, BUFFER_SIZE) > 0)
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	save_line[BUFFER_SIZE];
	int			new_line_i;
	char		*line;
	int			i;

	line = NULL;
	while ((!is_new_line(line)) && ft_read_buffer(fd, (char *)save_line) > 0)
	{
		new_line_i = is_new_line(save_line);
		line = ft_strjoin(line, save_line, new_line_i);
		if (!line)
			return (NULL);
		i = -1;
		while (++i < BUFFER_SIZE)
		{
			if (new_line_i && new_line_i + i < BUFFER_SIZE)
				save_line[i] = save_line[i + new_line_i];
			else
				save_line[i] = '\0';
		}
	}
	return (line);
}
