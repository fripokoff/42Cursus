/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:25:56 by kpires            #+#    #+#             */
/*   Updated: 2024/01/16 15:42:06 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_read_bytes(int fd, char *buffer)
{
	if (buffer[0] != '\0')
		return (1);
	if (read(fd, buffer, BUFFER_SIZE) > 0)
		return (1);
	return (0);
}

int	ft_is_new_line(char *line)
{
	int	i;

	i = -1;
	if (!line)
		return (0);
	while (line[++i])
		if (line[i] == '\n')
			return (i + 1);
	return (0);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[BUFFER_SIZE];
	int			new_line_i;
	int			i;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while ((!ft_is_new_line(line)) && ft_read_bytes(fd, (char *)buffer) > 0) 
	{
		new_line_i = ft_is_new_line(buffer);
		line = ft_strjoin(line, buffer, new_line_i);
		if (!line)
			return (NULL);
		i = -1;
		while (++i < BUFFER_SIZE)
		{
			if (new_line_i && new_line_i + i < BUFFER_SIZE)
				buffer[i] = buffer[i + new_line_i];
			else
				buffer[i] = '\0';
		}
	}
	return (line);
}

