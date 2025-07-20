/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:57:54 by redrouic          #+#    #+#             */
/*   Updated: 2025/07/15 20:12:01 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_valid_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (false);
	while (str[i])
	{
		if (str[i] == '1' || str[i] == '0' || str[i] == 'N' || str[i] == 'S'
			|| str[i] == 'E' || str[i] == 'W' || str[i] == 9 || str[i] == 32)
			i++;
		else
			break ;
	}
	if ((size_t)i == ft_strlen(str))
		return (true);
	return (false);
}

bool	map_closed(char **arr, int y)
{
	int	i;
	int	x;

	while (arr[y + 1] != NULL)
	{
		i = 0;
		x = ft_strlen(arr[y]) - 1;
		while (arr[y][i] == 32)
			i++;
		while (arr[y][x] == 32)
			x--;
		if (arr[y][x] != '1' || arr[y][i] != '1')
			return (false);
		y++;
	}
	if (!is_wall(arr[y], ft_strlen(arr[y])))
		return (false);
	return (true);
}

bool	is_double_player(char *str)
{
	int		i;
	int		check;

	i = ret_map_index(str);
	check = 0;
	while (str[i])
	{
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
			check++;
		else if (check > 1)
			return (ft_perror("Double player found!", NULL), true);
		i++;
	}
	if (check == 0)
		return (ft_perror("No player found", NULL), true);
	return (false);
}

bool	is_mult_lines(char *file)
{
	int		i;

	i = ret_map_index(file);
	if (i == 0)
		return (ft_perror("The map is missing or invalid", NULL), true);
	while (file[i])
	{
		if (file[i] == '\n')
		{
			i++;
			while (file[i] == 32)
				i++;
			if (file[i] != '\n')
				continue ;
			else
				return (ft_perror("Multiples lines in map", NULL), true);
		}
		i++;
	}
	return (false);
}

bool	is_error(char *file, t_game *game)
{
	char	**arr;
	int		y;

	if (is_mult_lines(file))
		return (true);
	arr = str2arr(file, "\n");
	if (!arr)
		return (free(file), true);
	y = ret_map_line(arr);
	if (y <= 0)
		return (free_map(arr), ft_perror("Invalid map placement", NULL), true);
	if (!valid_id(arr, y, game, 0))
		return (free_map(arr), true);
	if (game->map.fill_elem != 2)
		return (free_map(arr), ft_perror("Missing map elements", NULL), true);
	if (!map_closed(arr, y))
		return (free_map(arr), ft_perror("The map is not closed", NULL), true);
	if (!gest_space(arr, y))
		return (free_map(arr), ft_perror("Invalid map space", NULL), true);
	if (is_double_player(file))
		return (free_map(arr), true);
	game->map.map = &arr[y];
	game->map.arr_start = arr;
	return (free(file), false);
}
