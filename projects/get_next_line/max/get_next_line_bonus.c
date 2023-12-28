/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:46:50 by kdaumont          #+#    #+#             */
/*   Updated: 2023/11/23 11:33:03 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	buffer[FD_MAX][BUFFER_SIZE];

	line = NULL;
	if (fd < 0 && fd > FD_MAX)
		return (NULL);
	while ((!is_new_line(line)) && read_buffer(fd, (char *)buffer[fd]) > 0)
	{
		new_line = is_new_line(buffer[fd]);
		line = ft_strjoin(line, buffer[fd], new_line);
		if (!line)
			return (NULL);
		i = -1;
		while (++i < BUFFER_SIZE)
		{
			if (new_line && new_line + i < BUFFER_SIZE)
				buffer[fd][i] = buffer[fd][i + new_line];
			else
				buffer[fd][i] = '\0';
		}
	}
	return (line);
}
