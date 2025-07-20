/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:57:38 by fripok            #+#    #+#             */
/*   Updated: 2025/07/15 19:21:40 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	focus_out(t_player *player)
{
	player->moves[MOVE_UP] = 0;
	player->moves[MOVE_DOWN] = 0;
	player->moves[MOVE_LEFT] = 0;
	player->moves[MOVE_RIGHT] = 0;
	player->moves[ROTATE_LEFT] = 0;
	player->moves[ROTATE_RIGHT] = 0;
	return (0);
}

int	setup_hooks(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_loop_hook(game->mlx, render_game_frame, game);
	mlx_hook(game->win, FOCUS_OUT, 1L << 21, focus_out, &game->player);
	mlx_hook(game->win, 17, 0, exit_game, game);
	return (0);
}

void	put_pixel(int x, int y, int color, t_game *game)
{
	int	index;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = y * game->size_line + x * game->bpp / 8;
	game->data[index] = color & 0xFF;
	game->data[index + 1] = (color >> 8) & 0xFF;
	game->data[index + 2] = (color >> 16) & 0xFF;
}

int	exit_game(t_game *game, size_t is_error)
{
	int	i;

	i = 0;
	while (i < TEX_COUNT)
	{
		if (game->map.textures[i].img)
			mlx_destroy_image(game->mlx, game->map.textures[i].img);
		if (game->map.textures[i].path)
			free(game->map.textures[i].path);
		i++;
	}
	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->map.map)
		free_map(game->map.arr_start);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (is_error > 1 || is_error < 0)
		is_error = 0;
	return (exit(is_error), is_error);
}
