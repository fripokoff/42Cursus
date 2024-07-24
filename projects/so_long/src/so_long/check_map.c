/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:40:43 by kpires            #+#    #+#             */
/*   Updated: 2024/07/22 17:40:43 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	check_map_playable(char **map)
{
	t_pos	i;

	i = get_pos(0, 0);
	while (map[++i.y])
	{
		i.x = 0;
		while (map[i.y][++i.x])
		{
			if (map[i.y][i.x] == 'C')
				return (ft_printf("Error\nA coin not accessible\n"), false);
			if (map[i.y][i.x] == 'E')
			{
				if (ft_strchr("SP", map[i.y][i.x + 1]) == 0
				&& ft_strchr("SP", map[i.y][i.x - 1]) == 0
				&& ft_strchr("SP", map[i.y + 1][i.x]) == 0
				&& ft_strchr("SP", map[i.y - 1][i.x]) == 0)
					return (ft_printf("Error\nExit not accessible\n"), false);
			}
		}
	}
	return (true);
}

static bool	spread_from_position(char **map, t_pos i, t_pos size)
{
	bool	has_spread;

	has_spread = false;
	if (map[i.y -1][i.x] == '0' || map[i.y -1][i.x] == 'C')
	{
		map[i.y -1][i.x] = 'S';
		has_spread = true;
	}
	if (map[i.y][i.x - 1] == '0' || map[i.y][i.x - 1] == 'C')
	{
		map[i.y][i.x - 1] = 'S';
		has_spread = true;
	}
	if (i.y + 2 != size.y && ft_strchr("0C", map[i.y + 1][i.x]) != NULL)
	{
		map[i.y + 1][i.x] = 'S';
		has_spread = true;
	}
	if (i.x + 2 != size.x && ft_strchr("0C", map[i.y][i.x + 1]) != NULL)
	{
		map[i.y][i.x + 1] = 'S';
		has_spread = true;
	}
	return (has_spread);
}

static void	path_finding(char **map)
{
	bool	has_spread;
	t_pos	i;
	t_pos	size;

	size = get_map_size(map);
	has_spread = true;
	while (has_spread)
	{
		has_spread = false;
		i = get_pos(0, 0);
		while (map[++i.y])
		{
			i.x = 0;
			while (map[i.y][++i.x])
			{
				if (map[i.y][i.x] == 'P' || map[i.y][i.x] == 'S')
				{
					if (spread_from_position(map, i, size))
						has_spread = true;
				}
			}
		}
	}
}

static char	**duplicate_map(char **map)
{
	t_pos	size;
	char	**map_duplicated;
	int		i;

	size = get_map_size(map);
	map_duplicated = malloc(sizeof(char *) * (size.y + 1));
	if (map_duplicated == NULL)
	{
		ft_free(map);
		exit_error("Malloc issue");
	}
	i = -1;
	while (map[++i])
	{
		map_duplicated[i] = ft_strdup(map[i]);
		if (map_duplicated == NULL)
		{
			ft_free(map);
			ft_free(map_duplicated);
			exit_error("Malloc issue");
		}
	}
	map_duplicated[i] = NULL;
	return (map_duplicated);
}

void	check_map(char **map)
{
	char	**map_duplicated;

	map_duplicated = duplicate_map(map);
	path_finding(map_duplicated);
	if (!check_map_playable(map_duplicated))
	{
		ft_free(map_duplicated);
		ft_free(map);
		exit(EXIT_FAILURE);
	}
	else
		ft_free(map_duplicated);
}
