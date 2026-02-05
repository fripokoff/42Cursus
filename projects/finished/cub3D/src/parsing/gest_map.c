/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 18:37:32 by redrouic          #+#    #+#             */
/*   Updated: 2025/07/15 19:27:07 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_double_id(char **arr, int line, char *id, int index)
{
	int		y;
	char	**tab;

	y = 0;
	while (y < line)
	{
		tab = str2arr(arr[y], " \t");
		if (!tab)
			return (ft_perror(ALLOC, NULL), free_map(tab), true);
		if (y != index && ft_strcmp(id, tab[0]) == 0)
			return (ft_perror("Double ID", NULL), free_map(tab), true);
		free_map(tab);
		y++;
	}
	return (false);
}

bool	valid_area(char **map, int x, int y, char *chr)
{
	const int		dx[] = {1, -1, 0, 0};
	const int		dy[] = {0, 0, 1, -1};
	int				nx;
	int				ny;
	int				i;

	i = 0;
	while (i < 4)
	{
		nx = x + dx[i];
		ny = y + dy[i];
		i++;
		if (nx < 0 || ny < y)
			continue ;
		if (chr[0] == ' ')
			if (map[ny] == NULL || nx > (int)ft_strlen(map[ny]))
				continue ;
		if (nx > (int)ft_strlen(map[y - 1]))
			return (false);
		if (map[ny] == NULL || map[ny][nx] == '\0')
			return (false);
		if (ft_strchr(chr, map[ny][nx]) == NULL)
			return (false);
	}
	return (true);
}

bool	gest_space(char **map, int y)
{
	int	x;

	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 32 && !valid_area(map, x, y, " 1"))
				return (false);
			if ((ft_strchr("0NSEW", map[y][x]) != NULL)
				&& !valid_area(map, x, y, "01NSEW"))
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}
