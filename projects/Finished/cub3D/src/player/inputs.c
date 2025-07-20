/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:03:20 by kpires            #+#    #+#             */
/*   Updated: 2025/07/14 11:17:02 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
** Handles key press events for player movement and game control.
** Updates the player's state flags for movement processing in the next frame.
** Supports:
**  - WASD keys for movement
**  - Left/Right arrow keys for rotation
**  - ESC key to exit the game
** ----------------------------------------------------------------------------
** @param keycode: The key code of the pressed key
** @param player: Pointer to the player structure to update
** @return: Always returns 0 (success)
*/

int	key_press(int keycode, t_game *game)
{
	if (keycode == ESC)
		exit_game(game, 0);
	if (keycode == W)
		game->player.moves[MOVE_UP] = 1;
	if (keycode == S)
		game->player.moves[MOVE_DOWN] = 1;
	if (keycode == A)
		game->player.moves[MOVE_LEFT] = 1;
	if (keycode == D)
		game->player.moves[MOVE_RIGHT] = 1;
	if (keycode == LEFT)
		game->player.moves[ROTATE_LEFT] = 1;
	if (keycode == RIGHT)
		game->player.moves[ROTATE_RIGHT] = 1;
	return (0);
}

/*
** Handles key release events for player movement.
** Resets the player's state flags when keys are released.
** ----------------------------------------------------------------------------
** @param keycode: The key code of the released key
** @param player: Pointer to the player structure to update
** @return: Always returns 0 (success)
*/

int	key_release(int keycode, t_game *game)
{
	if (keycode == W)
		game->player.moves[MOVE_UP] = 0;
	if (keycode == S)
		game->player.moves[MOVE_DOWN] = 0;
	if (keycode == A)
		game->player.moves[MOVE_LEFT] = 0;
	if (keycode == D)
		game->player.moves[MOVE_RIGHT] = 0;
	if (keycode == LEFT)
		game->player.moves[ROTATE_LEFT] = 0;
	if (keycode == RIGHT)
		game->player.moves[ROTATE_RIGHT] = 0;
	return (0);
}
