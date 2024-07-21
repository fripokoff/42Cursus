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

static char	*string_chr(char *str, char letter)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == letter)
			return (&str[i]);
	}
	return (NULL);
}

static char	*string_join(char *s1, char *s2, char flag)
{
	char	*new_str;
	int		i;
	int		j;

	j = 0;
	i = -1;
	while (s1[++i])
		j++;
	i = -1;
	while (s2[++i])
		j++;
	new_str = (char *)malloc((j + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		new_str[++j] = s1[i];
	i = -1;
	while (s2[++i])
		new_str[++j] = s2[i];
	new_str[++j] = '\0';
	if (flag == 1)
		free(s1);
	return (new_str);
}

static void	set_string_after_newline(char *buffer)
{
	int	i;
	int	j;

	i = -1;
	while (buffer[++i] != '\n')
	{
		if (buffer[i] == '\0')
		{
			buffer[0] = '\0';
			return ;
		}
	}
	j = 0;
	while (buffer[++i])
	{
		buffer[j] = buffer[i];
		j++;
	}
	buffer[j] = '\0';
}

static char	*turn_string_into_firstline(char *temp)
{
	char	*new_str;
	int		i;

	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	i += temp[i] == '\n';
	new_str = (char *)malloc((i + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (temp[i] && temp[i] != '\n')
	{
		new_str[i] = temp[i];
		i++;
	}
	if (temp[i] == '\n')
		new_str[i++] = '\n';
	new_str[i] = '\0';
	free(temp);
	return (new_str);
}

char	*get_next_line(int fd)
{
	static char	buffer[FDS_NUMBER][BUFFER_SIZE + 1];
	char		*temp;
	int			read_nb;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = string_join(buffer[fd], "", 0);
	if (temp == NULL)
		return (NULL);
	while (string_chr(temp, '\n') == 0)
	{
		read_nb = read(fd, buffer[fd], BUFFER_SIZE);
		if (read_nb == -1 || (read_nb == 0 && temp[0] == '\0'))
			return (free(temp), NULL);
		buffer[fd][read_nb] = '\0';
		if (read_nb == 0)
			return (temp);
		temp = string_join(temp, buffer[fd], 1);
		if (temp == NULL)
			return (NULL);
	}
	set_string_after_newline(buffer[fd]);
	return (turn_string_into_firstline(temp));
}
