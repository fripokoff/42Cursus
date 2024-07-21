/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:03:10 by kpires            #+#    #+#             */
/*   Updated: 2024/07/21 13:03:10 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_file(char *map_file)
{
	int	len;
	int	fd;

	len = ft_strlen(map_file);
	if(!ft_strnstr(map_file, ".ber", len) || len < 4)
		exit_error("The extension of the mapfile has to be '.ber'");
	fd = open(map_file, O_RDONLY);
	if(fd == -1)
		exit_error("Access or rights issue with the mapfile");
	close(fd);
}

char	**get_map_by_file(char *file_name)
{
	char	**map = NULL;
	char	*file_content;

	check_file(file_name);
	file_content = get_file_content(file_name);
	if(file_content == NULL)
		exit_error("Reading the mapfile");
	printf("file_content: %s\n", file_content);
	return map;
}