/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:06:29 by redrouic          #+#    #+#             */
/*   Updated: 2025/07/15 15:00:50 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_wall(char *str, int size)
{
	int	x;
	int	i;

	x = size - 1;
	i = 0;
	while (str[i] && i < x)
	{
		if (ft_strchr("1 ", str[i]) == NULL)
			return (false);
		i++;
	}
	return (true);
}

size_t	ret_map_line(char **arr)
{
	int	ret;
	int	y;

	y = 0;
	ret = -1;
	while (arr[y])
	{
		if (check_valid_line(arr[y])
			&& ret == -1 && is_wall(arr[y], ft_strlen(arr[y])))
			ret = y;
		if (ret != -1)
		{
			if (!check_valid_line(arr[y]))
				return (-1);
		}
		y++;
	}
	return (ret);
}

size_t	ret_map_index(char *file)
{
	int		i;
	int		first;
	int		last;

	i = 0;
	first = 0;
	last = 0;
	while (file[i])
	{
		if (file[i] == '\n')
		{
			i++;
			first = i;
			while (file[i] && file[i] != '\n')
				i++;
			if (i == first)
				continue ;
			last = i - 1;
			if (is_wall(&file[first], (last - first + 1)))
				return (i);
		}
		i++;
	}
	return (0);
}

void	ft_perror(const char *msg, const char *file)
{
	fd_putstr("Error\n", 2);
	if (msg && !file)
		fd_putstr(msg, 2);
	else if (msg && file)
	{
		fd_putstr(msg, 2);
		fd_putstr(file, 2);
	}
	fd_putstr("\n", 2);
	return ;
}
