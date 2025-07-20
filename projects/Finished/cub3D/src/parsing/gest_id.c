/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_id.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 07:35:29 by redrouic          #+#    #+#             */
/*   Updated: 2025/07/15 20:10:29 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_id(char *str)
{
	if (ft_strcmp(str, "NO") != 0 && ft_strcmp(str, "SO") != 0
		&& ft_strcmp(str, "WE") != 0 && ft_strcmp(str, "EA") != 0
		&& ft_strcmp(str, "F") != 0 && ft_strcmp(str, "C") != 0)
	{
		if (check_valid_line(str) && !is_wall(str, ft_strlen(str)))
			return (ft_perror("The map is not closed", NULL), false);
		return (ft_perror("Invalid ID", NULL), false);
	}
	return (true);
}

bool	is_valid_rgb_component(char *s)
{
	int	i;
	int	len;
	int	value;

	i = 0;
	len = 0;
	if (!s)
		return (false);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (false);
		i++;
		len++;
	}
	if (len == 0 || len > 3)
		return (false);
	value = atoi(s);
	if (value < 0 || value > 255)
		return (false);
	return (true);
}

bool	double_sep(char *str, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == sep)
		{
			i++;
			while (str[i] && str[i] == sep)
			{
				count++;
				i++;
			}
		}
		else
			i++;
	}
	if (count >= 1)
		return (true);
	return (false);
}

bool	validate_and_fill_color(int *dest, char *color_str)
{
	char	**components;
	int		i;

	if (color_str[0] == ',' || color_str[ft_strlen(color_str) - 1] == ',')
		return (false);
	if (double_sep(color_str, ','))
		return (false);
	components = str2arr(color_str, ",");
	if (!components)
		return (false);
	if (!components[0] || !components[1] || !components[2] || components[3])
		return (free_map(components), false);
	i = 0;
	while (i < 3)
	{
		if (!is_valid_rgb_component(components[i]))
			return (free_map(components), false);
		i++;
	}
	dest[0] = atoi(components[0]);
	dest[1] = atoi(components[1]);
	dest[2] = atoi(components[2]);
	free_map(components);
	return (true);
}

bool	valid_id(char **arr, int line, t_game *game, int y)
{
	char	**tab;
	int		err;

	tab = NULL;
	while (y < line)
	{
		tab = str2arr(arr[y], " \t");
		if (!tab)
			return (ft_perror(ALLOC, NULL), false);
		if (tab[2])
			return (free_map(tab), ft_perror("Too much content", NULL), false);
		if (!is_id(tab[0]) || is_double_id(arr, line, tab[0], y))
			return (free_map(tab), false);
		if (!tab[1])
			return (free_map(tab), ft_perror(NOID, NULL), false);
		err = fill_colors(game, tab);
		if (err == -1)
			return (free_map(tab), false);
		else if (err == 1 && !fill_textures(game, tab))
			return (free_map(tab), false);
		free_map(tab);
		y++;
	}
	return (true);
}
