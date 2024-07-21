/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ghosts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:44:57 by aautin            #+#    #+#             */
/*   Updated: 2024/02/04 16:45:14 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_ghost(t_game *game, t_coords i, int move)
{
	mlx_put_image_to_window(game->mlxvar, game->win, get_img_obj(game, "ghost"),
		32 * (i.x + move), 32 * i.y);
	mlx_put_image_to_window(game->mlxvar, game->win,
		get_img_obj(game, "sprites/empty"), 32 * i.x, 32 * i.y);
	game->map[i.y][i.x] = '0';
	game->map[i.y][i.x + move] = 'G';
}

void	try_move_ghosts(t_game *game)
{
	t_coords	i;

	i.y = -1;
	while (game->map[++i.y])
	{
		i.x = -1;
		while (game->map[i.y][++i.x])
		{
			if (game->map[i.y][i.x] == 'G')
			{
				if (game->map[i.y][i.x - 1] == '0')
					move_ghost(game, i, -1);
				else if (game->map[i.y][i.x + 1] == '0')
				{
					move_ghost(game, i, 1);
					i.x++;
				}
			}
		}
	}
}
