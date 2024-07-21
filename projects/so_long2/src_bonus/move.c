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

static char	*get_font_key(int moves_nb)
{
	if (moves_nb % 10 == 1)
		return ("fonts/1");
	if (moves_nb % 10 == 2)
		return ("fonts/2");
	if (moves_nb % 10 == 3)
		return ("fonts/3");
	if (moves_nb % 10 == 4)
		return ("fonts/4");
	if (moves_nb % 10 == 5)
		return ("fonts/5");
	if (moves_nb % 10 == 6)
		return ("fonts/6");
	if (moves_nb % 10 == 7)
		return ("fonts/7");
	if (moves_nb % 10 == 8)
		return ("fonts/8");
	if (moves_nb % 10 == 9)
		return ("fonts/9");
	else
		return ("fonts/0");
}

void	put_move(t_game *game, int moves_nb, int x_pad)
{
	if (moves_nb > 9)
		put_move(game, moves_nb / 10, x_pad + 1);
	mlx_put_image_to_window(game->mlxvar, game->win,
		get_img_obj(game, get_font_key(moves_nb)),
		game->win_size.x - 16 * (x_pad + 1), game->win_size.y - 16);
}

static char	*get_pacman_key(t_coords mv)
{
	if (mv.x == -1)
		return ("semi_left");
	if (mv.x == 1)
		return ("semi_right");
	if (mv.y == -1)
		return ("semi_up");
	else
		return ("semi_down");
}

static void	do_move(t_coords mv, t_game *game)
{
	if (game->map[game->player_i.y + mv.y][game->player_i.x + mv.x] == 'C')
		game->coins_nb--;
	game->map[game->player_i.y + mv.y][game->player_i.x + mv.x] = 'P';
	game->map[game->player_i.y][game->player_i.x] = '0';
	mlx_put_image_to_window(game->mlxvar, game->win,
		get_img_obj(game, "sprites/empty"), game->player_i.x * 32,
		game->player_i.y * 32);
	mlx_put_image_to_window(game->mlxvar, game->win,
		get_img_obj(game, get_pacman_key(mv)),
		(game->player_i.x + mv.x) * 32, (game->player_i.y + mv.y) * 32);
	game->player_i = get_coords(game->player_i.x + mv.x,
			game->player_i.y + mv.y);
	put_move(game, game->moves_nb, 0);
	try_move_ghosts(game);
}

void	do_try_move(t_coords mv, t_game *game)
{
	if (ft_strchr("C0",
			game->map[game->player_i.y + mv.y][game->player_i.x + mv.x]))
	{
		game->moves_nb++;
		do_move(mv, game);
	}
	else
	{
		if (game->map[game->player_i.y + mv.y][game->player_i.x + mv.x] == 'G')
		{
			ft_printf("GAME OVER !\nYou touched a ghost.\n");
			do_free_game(game, TRUE, TRUE, TRUE);
			exit(EXIT_SUCCESS);
		}
		if (game->map[game->player_i.y + mv.y][game->player_i.x + mv.x] == 'E')
		{
			if (game->coins_nb == 0)
			{
				game->moves_nb++;
				ft_printf("Party finished in %d moves!\n", game->moves_nb);
				do_free_game(game, TRUE, TRUE, TRUE);
				exit(EXIT_SUCCESS);
			}	
		}	
	}
}
