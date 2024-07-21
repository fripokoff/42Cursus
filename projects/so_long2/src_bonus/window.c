/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:12:44 by aautin            #+#    #+#             */
/*   Updated: 2024/01/27 17:12:32 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_window(t_game *game)
{
	game->mlxvar = mlx_init();
	if (game->mlxvar == NULL)
	{
		free_stab(game->map);
		do_msg_exit("Mlx's set issue");
	}
	game->win_size = get_coords(game->map_size.x * 32,
			game->map_size.y * 32 + 32);
	game->win = mlx_new_window(game->mlxvar, game->win_size.x,
			game->win_size.y, "WIN");
	if (game->win == NULL)
	{
		mlx_destroy_display(game->mlxvar);
		free(game->mlxvar);
		free_stab(game->map);
		do_msg_exit("Window's set issue");
	}
}
