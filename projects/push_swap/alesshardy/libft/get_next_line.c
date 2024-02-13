/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:15:22 by apintus           #+#    #+#             */
/*   Updated: 2024/02/09 16:57:12 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_update_data(char *old_data)
{
	char	*new_data;
	int		i;
	int		j;

	i = 0;
	while (old_data[i] != '\n' && old_data[i] != '\0')
		i++;
	if (old_data[i] == '\0')
	{
		free (old_data);
		return (NULL);
	}
	new_data = (char *)malloc(sizeof(char)
			* ((ft_strlen_gnl(old_data) - i) + 1));
	if (new_data == NULL)
		return (NULL);
	j = 0;
	i++;
	while (old_data[i] != '\0')
	{
		new_data[j++] = old_data[i++];
	}
	new_data[j] = '\0';
	free (old_data);
	return (new_data);
}

char	*ft_extract_line(char *data)
{
	char	*line;
	int		i;
	int		j;

	if (data[0] == '\0')
		return (NULL);
	i = 0;
	while (data[i] != '\0' && data[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + (data[i] == '\n') + 1));
	if (line == NULL)
		return (NULL);
	j = 0;
	while (data[j] != '\0')
	{
		line[j] = data[j];
		if (data[j] == '\n')
		{
			j++;
			break ;
		}
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*ft_fill(int fd, char *data)
{
	int		bytes_read;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	bytes_read = 1;
	while (!ft_strcontains(data, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			if (data != NULL)
				free(data);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		data = ft_strjoin_gnl(data, buffer);
	}
	free(buffer);
	return (data);
}

char	*get_next_line(int fd, int error)
{
	static char	*data;
	char		*line;

	if (error == 1)
		return (free(data), NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	data = ft_fill(fd, data);
	if (data == NULL)
		return (NULL);
	line = ft_extract_line(data);
	data = ft_update_data(data);
	return (line);
}
