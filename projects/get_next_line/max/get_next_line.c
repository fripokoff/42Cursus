/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:46:50 by kdaumont          #+#    #+#             */
/*   Updated: 2023/11/23 13:36:14 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_new_line(char *new)
{
	int	i;

	i = -1;
	if (!new)
		return (0);
	while (new[++i])
		if (new[i] == '\n')
			return (i + 1);
	return (0);
}

int	read_buffer(int fd, char *buffer)
{
	if (buffer[0] != '\0')
		return (1);
	if (read(fd, buffer, BUFFER_SIZE) > 0)
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	char		*line;
	int			new_line;
	int			i;
	static char	buffer[BUFFER_SIZE];

	line = NULL;
	while ((!is_new_line(line)) && read_buffer(fd, (char *)buffer) > 0)
	{
		new_line = is_new_line(buffer);
		line = ft_strjoin(line, buffer, new_line);
		if (!line)
			return (NULL);
		i = -1;
		while (++i < BUFFER_SIZE)
		{
			if (new_line && new_line + i < BUFFER_SIZE)
				buffer[i] = buffer[i + new_line];
			else
				buffer[i] = '\0';
		}
	}
	return (line);
}
