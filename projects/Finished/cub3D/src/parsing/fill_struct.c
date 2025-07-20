/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 10:32:50 by kpires            #+#    #+#             */
/*   Updated: 2025/07/15 19:17:15 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	fill_colors(t_game *game, char **tab)
{
	if (!tab || !tab[0] || !tab[1])
		return (-1);
	if (ft_strcmp(tab[0], "F") == 0)
	{
		if (!validate_and_fill_color(game->map.floor_color, tab[1]))
			return (ft_perror(FLOOR, NULL), -1);
		game->map.fill_elem++;
		return (0);
	}
	else if (ft_strcmp(tab[0], "C") == 0)
	{
		if (!validate_and_fill_color(game->map.ceiling_color, tab[1]))
			return (ft_perror(CEIL, NULL), -1);
		game->map.fill_elem++;
		return (0);
	}
	return (1);
}

bool	validate_texture_file(const char *path)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		if (errno == EACCES)
			return (fd_putstr("Error\nPermission denied: ", 2),
				fd_putstr(path, 2), fd_putstr("\n", 2), false);
		else if (errno == ENOENT)
			return (fd_putstr("Error\nFile not found: ", 2),
				fd_putstr(path, 2), fd_putstr("\n", 2), false);
		else
			return (fd_putstr("Error\nCannot open file: ", 2),
				fd_putstr(path, 2), fd_putstr("\n", 2), false);
	}
	close(fd);
	return (true);
}

bool	fill_textures(t_game *game, char **tab)
{
	const char	*ids[] = {"NO", "SO", "EA", "WE", NULL};
	int			i;

	if (!validate_texture_file(tab[1]))
		return (false);
	i = 0;
	while (ids[i] != NULL)
	{
		if (ft_strcmp(tab[0], ids[i]) == 0)
		{
			if (game->map.textures[i].path)
				free(game->map.textures[i].path);
			ft_strdup(tab[1], &game->map.textures[i].path);
			break ;
		}
		i++;
	}
	return (true);
}
