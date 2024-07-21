/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 00:58:20 by aautin            #+#    #+#             */
/*   Updated: 2024/01/30 04:00:21 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	do_move(t_coords mv, t_game *game)
{
	if (game->map[game->player_i.y + mv.y][game->player_i.x + mv.x] == 'C')
		game->coins_nb--;
	game->map[game->player_i.y + mv.y][game->player_i.x + mv.x] = 'P';
	game->map[game->player_i.y][game->player_i.x] = '0';
	mlx_put_image_to_window(game->mlxvar, game->win,
		get_img_obj(game, "sprites/empty"), game->player_i.x * 32,
		game->player_i.y * 32);
	mlx_put_image_to_window(game->mlxvar, game->win, get_img_obj(game, "close"),
		(game->player_i.x + mv.x) * 32, (game->player_i.y + mv.y) * 32);
	game->player_i = get_coords(game->player_i.x + mv.x,
			game->player_i.y + mv.y);
}

void	do_try_move(t_coords mv, t_game *game)
{
	if (ft_strchr("C0",
			game->map[game->player_i.y + mv.y][game->player_i.x + mv.x]))
	{
		do_move(mv, game);
		ft_printf("%d\n", ++game->moves_nb);
	}
	else
	{
		if (game->map[game->player_i.y + mv.y][game->player_i.x + mv.x] == 'E')
		{
			if (game->coins_nb == 0)
			{
				game->moves_nb++;
				ft_printf("%d\nParty finished in %d moves!\n", game->moves_nb,
					game->moves_nb);
				do_free_game(game, TRUE, TRUE, TRUE);
				exit(EXIT_SUCCESS);
			}	
		}	
	}
}
