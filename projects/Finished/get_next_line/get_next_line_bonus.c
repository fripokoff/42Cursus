/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:04:34 by kpires            #+#    #+#             */
/*   Updated: 2024/01/19 14:02:58 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	is_new_line(char *save_line)
{
	int	i;

	i = -1;
	if (!save_line)
		return (0);
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
	char		*line;
	int			new_line_i;
	int			i;
	static char	save_line[FD_MAX][BUFFER_SIZE];

	line = NULL;
	if (fd < 0 && fd > FD_MAX)
		return (NULL);
	while ((!is_new_line(line)) && ft_read_buffer
		(fd, (char *)save_line[fd]) > 0)
	{
		new_line_i = is_new_line(save_line[fd]);
		line = ft_strjoin(line, save_line[fd], new_line_i);
		if (!line)
			return (NULL);
		i = -1;
		while (++i < BUFFER_SIZE)
		{
			if (new_line_i && new_line_i + i < BUFFER_SIZE)
				save_line[fd][i] = save_line[fd][i + new_line_i];
			else
				save_line[fd][i] = '\0';
		}
	}
	return (line);
}
