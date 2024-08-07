/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:12:58 by kpires            #+#    #+#             */
/*   Updated: 2024/07/21 14:37:48 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_file_content(char *filename)
{
	int		fd;
	char	*str;
	char	*temp;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	temp = get_next_line(fd);
	str = NULL;
	while (temp)
	{
		if (str)
			str = ft_strjoin(str, temp, 1);
		else
			str = ft_strdup(temp);
		free(temp);
		if (!str)
		{
			close(fd);
			return (NULL);
		}
		temp = get_next_line(fd);
	}
	close(fd);
	return (str);
}
