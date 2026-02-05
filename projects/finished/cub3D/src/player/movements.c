/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fripok <fripok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:03:13 by kpires            #+#    #+#             */
/*   Updated: 2025/04/07 14:05:10 by fripok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
** Simulates a time function with a fixed frame rate.
** This function provides a deterministic time value by incrementing
** a frame counter and using a fixed time step per frame.
** ----------------------------------------------------------------------------
** @return: The simulated time in seconds (based on 60 FPS)
*/

static double	get_time(void)
{
	static double	last_time = 0.0;
	static int		frame_count = 0;
	double			frame_time;

	frame_count++;
	frame_time = 0.016667;
	last_time = frame_count * frame_time;
	return (last_time);
}

/*
** Calculates the time elapsed since the last frame.
** This function is essential for frame-rate independent movement,
** ensuring consistent game speed regardless of performance.
** ----------------------------------------------------------------------------
** @return: Time delta in seconds, capped at 0.1 seconds to prevent large jumps
*/

static double	get_delta_time(void)
{
	static double	last_time = 0.0;
	double			current_time;
	double			delta_time;

	current_time = get_time();
	delta_time = current_time - last_time;
	last_time = current_time;
	if (delta_time > 0.1)
		delta_time = 0.1;
	return (delta_time);
}

/*
** Handles player rotation based on keyboard input.
** Updates the player's viewing angle when rotation keys are pressed.
** Normalizes the angle to stay within [0, 2 PI] range.
** ----------------------------------------------------------------------------
** @param player: The player structure to update
** @param delta_time: Time elapsed since last frame for smooth rotation
*/

static void	player_rotate(t_player *player)
{
	double	player_rot_speed;
	double	rot_speed;
	double	delta_time;

	delta_time = get_delta_time();
	player_rot_speed = (double)PLAYER_ROT_SPEED / 3;
	rot_speed = player_rot_speed * delta_time;
	if (player->moves[ROTATE_LEFT])
		player->angle -= rot_speed;
	if (player->moves[ROTATE_RIGHT])
		player->angle += rot_speed;
	while (player->angle < 0)
		player->angle += 2 * PI;
	while (player->angle >= 2 * PI)
		player->angle -= 2 * PI;
}

/*
** Calculates the player's new position based on current input state.
** Handles WASD keys for forward/backward and strafing movements.
** Adjusts movement speed based on elapsed time for consistent motion.
** ----------------------------------------------------------------------------
** @param player: The player structure to update
** @param delta_time: Time elapsed since last frame for smooth movement
*/

static void	player_movements(t_player *player, double *dx, double *dy,
		double delta_time)
{
	double	cos_angle;
	double	sin_angle;

	cos_angle = cos(player->angle);
	sin_angle = sin(player->angle);
	if (player->moves[MOVE_UP])
	{
		*dx += cos_angle * PLAYER_SPEED * delta_time * 20 * 1.5;
		*dy += sin_angle * PLAYER_SPEED * delta_time * 20 * 1.5;
	}
	if (player->moves[MOVE_DOWN])
	{
		*dx -= cos_angle * PLAYER_SPEED * delta_time * 20 * 1.5;
		*dy -= sin_angle * PLAYER_SPEED * delta_time * 20 * 1.5;
	}
	if (player->moves[MOVE_LEFT])
	{
		*dx += sin_angle * PLAYER_SPEED * delta_time * 20;
		*dy -= cos_angle * PLAYER_SPEED * delta_time * 20;
	}
	if (player->moves[MOVE_RIGHT])
	{
		*dx -= sin_angle * PLAYER_SPEED * delta_time * 20;
		*dy += cos_angle * PLAYER_SPEED * delta_time * 20;
	}
}

/*
** Main function for updating player position based on key inputs.
** Processes rotation and movement requests from keyboard state.
** ----------------------------------------------------------------------------
** @param player: The player structure containing position and input state
*/

void	move_player(t_player *player)
{
	double	dx;
	double	dy;
	double	delta_time;

	dx = 0;
	dy = 0;
	delta_time = get_delta_time();
	player_rotate(player);
	player_movements(player, &dx, &dy, delta_time);
	player->x += dx;
	player->y += dy;
}
