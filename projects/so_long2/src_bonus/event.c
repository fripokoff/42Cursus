/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:41:38 by aautin            #+#    #+#             */
/*   Updated: 2024/01/30 02:06:03 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	do_key_pressed_event(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		do_free_game(game, TRUE, TRUE, TRUE);
		exit(EXIT_SUCCESS);
	}
	if (keycode == A_KEY)
		do_try_move(get_coords(-1, 0), game);
	else if (keycode == W_KEY)
		do_try_move(get_coords(0, -1), game);
	else if (keycode == S_KEY)
		do_try_move(get_coords(0, 1), game);
	else if (keycode == D_KEY)
		do_try_move(get_coords(1, 0), game);
	return (0);
}

static int	do_close_prgm(t_game *game)
{
	do_free_game(game, TRUE, TRUE, TRUE);
	exit(EXIT_SUCCESS);
}

void	set_events(t_game *game)
{
	mlx_hook(game->win, 2, (1L << 0), do_key_pressed_event, game);
	mlx_hook(game->win, 17, 0, do_close_prgm, game);
}
