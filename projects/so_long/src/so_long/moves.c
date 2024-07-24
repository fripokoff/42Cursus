/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:20:47 by kpires            #+#    #+#             */
/*   Updated: 2024/07/23 18:20:47 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_player_position(t_pos pos, t_settings *settings)
{
	settings->map
	[settings->player.y + pos.y]
	[settings->player.x + pos.x] = 'P';
	mlx_put_image_to_window(
		settings->mlx_var,
		settings->window,
		get_img_obj(settings, "player"),
		(settings->player.x + pos.x) * SPRITES_SIZE,
		(settings->player.y + pos.y) * SPRITES_SIZE
		);
	settings->player = get_pos(settings->player.x + pos.x,
			settings->player.y + pos.y);
}

static void	update_last_player_position(t_settings *settings)
{
	settings->map
	[settings->player.y]
	[settings->player.x] = '0';
	mlx_put_image_to_window(
		settings->mlx_var,
		settings->window,
		get_img_obj(settings, "sprites/floor"),
		settings->player.x * SPRITES_SIZE,
		settings->player.y * SPRITES_SIZE
		);
}

static void	move_player(t_pos pos, t_settings *settings)
{
	char	target;

	target = settings->map[settings->player.y + pos.y]
	[settings->player.x + pos.x];
	if (target == 'C')
		settings->potions--;
	update_last_player_position(settings);
	update_player_position(pos, settings);
}

void	try_move_player(t_pos pos, t_settings *settings)
{
	char	target;

	target = settings->map[settings->player.y + pos.y]
	[settings->player.x + pos.x];
	if (ft_strchr("C0", target))
	{
		move_player(pos, settings);
		ft_printf("%d\n", ++settings->moves);
	}
	else
	{
		if (target == 'E' && settings->potions == 0)
		{
			settings->moves++;
			ft_printf("%d\nGame finished in %d moves!\n", settings->moves,
				settings->moves);
			free_game(settings, true, true, true);
			exit(EXIT_SUCCESS);
		}
	}
	if (settings->potions == 0)
		mlx_put_image_to_window(settings->mlx_var, settings->window,
			get_img_obj(settings, "exit_open"), settings->exit_pos.x
			* SPRITES_SIZE, settings->exit_pos.y * SPRITES_SIZE);
}
