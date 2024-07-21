/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:41:40 by aautin            #+#    #+#             */
/*   Updated: 2024/01/27 14:50:24 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_file(char *mapfile)
{
	int	len;
	int	fd;

	len = ft_strlen(mapfile);
	if (len < 4 || ft_strncmp(mapfile + (len - 4), ".ber", len) != 0)
		do_msg_exit("The extension of the mapfile has to be '.ber'");
	fd = open(mapfile, O_RDONLY);
	if (fd == -1)
		do_msg_exit("Access or rights issue with the mapfile");
	close(fd);
}

static void	check_map_size(char *file_content)
{
	t_coords	size;
	int			i;

	size = get_coords(0, 1);
	while (file_content[size.x] && file_content[size.x] != '\n')
		size.x++;
	if (size.x == 0 || file_content[size.x] == '\0')
	{
		free(file_content);
		if (size.x == 0)
			do_msg_exit("The map starts with a newline");
		else
			do_msg_exit("The map isn't a rectangle");
	}
	i = 0;
	while (file_content[i])
	{
		if (file_content[i] == '\n' && (i != (size.y * (size.x + 1)) - 1))
		{
			free(file_content);
			do_msg_exit("The map isn't a rectangle");
		}
		size.y += file_content[i] == '\n';
		i++;
	}
}

static void	check_game_elements(char *file_content)
{
	int	exits_nb;
	int	players_nb;
	int	coins_nb;
	int	i;

	exits_nb = 0;
	players_nb = 0;
	coins_nb = 0;
	i = -1;
	while (file_content[++i])
	{
		if (file_content[i] == 'E')
			exits_nb++;
		if (file_content[i] == 'P')
			players_nb++;
		if (file_content[i] == 'C')
			coins_nb++;
	}
	if (exits_nb != 1 || players_nb != 1 || coins_nb == 0)
	{
		free(file_content);
		do_msg_exit("The map has to contains: 1 P, 1 E and at least 1 C");
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
		if (ft_strchr("10PCEG\n", file_content[i]) == False)
		{
			free(file_content);
			do_msg_exit("Map contains invalid character: only 10PCEG allowed");
		}
	}
	check_game_elements(file_content);
	map = ft_split(file_content, '\n');
	free(file_content);
	if (map == NULL)
		do_msg_exit("Malloc problem");
	return (map);
}

char	**get_map_from_file(char *mapfile)
{
	char		*file_content;
	char		**map;
	t_coords	size;
	t_coords	i;

	check_file(mapfile);
	file_content = get_file_content(mapfile);
	if (file_content == NULL)
		do_msg_exit("Read file then got nothing: malloc or empty file issue");
	map = get_map(file_content);
	size = get_map_size(map);
	i = get_coords(0, 0);
	while (i.x < (size.x - 1) || i.y < (size.y - 1))
	{
		if (map[0][i.x] != '1' || map[size.y - 1][i.x] != '1'
			|| map[i.y][0] != '1' || map[i.y][size.x - 1] != '1')
		{
			free_stab(map);
			do_msg_exit("Map not closed by a rectangle of 1 characters");
		}
		i.x += i.x < (size.x - 1);
		i.y += i.y < (size.y - 1);
	}
	return (check_map(map), map);
}
