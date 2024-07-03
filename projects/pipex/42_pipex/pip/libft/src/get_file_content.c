/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:26:06 by aautin            #+#    #+#             */
/*   Updated: 2024/01/05 18:54:23 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/get_next_line.h"

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
