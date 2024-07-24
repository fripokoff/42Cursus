/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:11:03 by kpires            #+#    #+#             */
/*   Updated: 2024/07/23 18:11:03 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	close_game(t_settings *settings)
{
	free_game(settings, true, true, true);
	exit(EXIT_FAILURE);
}

static int	keys_event(int keycode, t_settings *settings)
{
	if (keycode == EXIT_GAME)
		close_game(settings);
	if (keycode == LEFT)
		try_move_player(get_pos(-1, 0), settings);
	else if (keycode == UP)
		try_move_player(get_pos(0, -1), settings);
	else if (keycode == DOWN)
		try_move_player(get_pos(0, 1), settings);
	else if (keycode == RIGHT)
		try_move_player(get_pos(1, 0), settings);
	return (0);
}

void	init_hooks(t_settings *settings)
{
	mlx_hook(settings->window, KEYS_EVENT, (1L << 0), keys_event, settings);
	mlx_hook(settings->window, EXIT_EVENT, 0, close_game, settings);
}
