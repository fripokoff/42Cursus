/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:41:40 by aautin            #+#    #+#             */
/*   Updated: 2024/01/23 21:40:32 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_coords	get_map_size(char **map)
{
	t_coords	size;

	size = get_coords(0, 0);
	while (map[size.y])
		size.y++;
	while (map[0][size.x])
		size.x++;
	return (size);
}

t_coords	get_coords(int x, int y)
{
	t_coords	i;

	i.x = x;
	i.y = y;
	return (i);
}
