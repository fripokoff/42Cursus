/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:16:03 by kpires            #+#    #+#             */
/*   Updated: 2024/07/22 13:16:03 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_pos	get_map_size(char **map)
{
	t_pos	size;

	size = get_pos(0, 0);
	while (map[size.y])
		size.y++;
	while (map[0][size.x])
		size.x++;
	return (size);
}

t_pos	get_pos(int x, int y)
{
	t_pos	p;

	p.x = x;
	p.y = y;
	return (p);
}
