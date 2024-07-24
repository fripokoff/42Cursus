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

static void	check_map_size(char *file_content)
{
	t_pos	size;
	int		i;

	size = get_pos(0, 1);
	while (file_content[size.x] && file_content[size.x] != '\n')
		size.x++;
	if (size.x == 0 || file_content[size.x] == '\0')
	{
		free(file_content);
		if (size.x == 0)
			exit_error("Map starts with newline");
		else
			exit_error("Map isn't a rectangle");
	}
	i = 0;
	while (file_content[i])
	{
		if (file_content[i] == '\n' && (i != (size.y * (size.x + 1)) - 1))
		{
			free(file_content);
			exit_error("Map isn't a rectangle");
		}
		size.y += file_content[i] == '\n';
		i++;
	}
}

static void	check_game_elements(char *file_content)
{
	int	exit;
	int	player;
	int	potions;
	int	i;

	exit = 0;
	player = 0;
	potions = 0;
	i = -1;
	while (file_content[++i])
	{
		if (file_content[i] == 'E')
			exit++;
		if (file_content[i] == 'P')
			player++;
		if (file_content[i] == 'C')
			potions++;
	}
	if (exit != 1 || player != 1 || potions == 0)
	{
		free(file_content);
		exit_error("The map has to contains: 1 P, 1 E and at least 1 C");
	}
}

static char	**get_map(char *file_content)
{
	char	**map;
	int		i;

	check_map_size(file_content);
	i = -1;
	while (file_content[++i])
	{
		if (ft_strchr("10PCE\n", file_content[i]) == false)
		{
			free(file_content);
			exit_error("Invalid character detected : only 10PCE");
		}
	}
	check_game_elements(file_content);
	map = ft_split(file_content, '\n');
	free(file_content);
	if (map == NULL)
		exit_error("Malloc issue");
	return (map);
}

static void	check_file(char *map_file)
{
	int	len;
	int	fd;

	len = ft_strlen(map_file);
	if (!ft_strnstr(map_file, ".ber", len) || len < 4)
		exit_error("The extension of the mapfile has to be '.ber'");
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		exit_error("Access or rights issue with the mapfile");
	close(fd);
}

char	**get_map_by_file(char *file_name)
{
	char	**map;
	char	*file_content;
	t_pos	size;
	t_pos	i;

	check_file(file_name);
	file_content = get_file_content(file_name);
	if (file_content == NULL)
		exit_error("Reading the mapfile");
	map = get_map(file_content);
	size = get_map_size(map);
	i = get_pos(0, 0);
	while (i.x < size.x || i.y < size.y - 1)
	{
		if ((map[0][i.x] != '1' && map[0][i.x] != 0)
			|| (map[size.y - 1][i.x] != '1' && map[size.y - 1][i.x] != 0)
			|| (map[i.y][0] != '1' && map[i.y][0] != 0)
			|| (map[i.y][size.x - 1] != '1' && map[i.y][size.x -1] != 0))
		{
			ft_free(map);
			exit_error("Map not closed by a rectangle of 1 characters");
		}
		i = get_pos(i.x + (i.x < size.x), i.y + (i.y < size.y -1));
	}
	return (check_map(map), map);
}
