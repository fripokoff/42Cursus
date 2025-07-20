/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:50:29 by fripok            #+#    #+#             */
/*   Updated: 2025/07/12 17:59:56 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
** Calculates the exact coordinates where the ray hits the wall.
** Uses the side of impact to determine the precise hit position.
** ----------------------------------------------------------------------------
** @param player: Player data (position)
** @param data: Ray data after DDA execution
** @param ray_coords: Output array to store the hit coordinates
** @param side: Which side of the wall was hit (0=vertical, 1=horizontal)
*/

static void	calculate_wall_hit(t_player *player, t_ray_data *data,
	float *ray_coords, int side)
{
	if (side == 0)
	{
		ray_coords[0] = data->map[0] * GRID_SIZE;
		ray_coords[1] = player->y;
		if (data->step[0] < 0)
			ray_coords[0] += GRID_SIZE;
		if (fabs(data->ray_dir[0]) > 1e-10)
			ray_coords[1] = player->y + data->ray_dir[1]
				* (ray_coords[0] - player->x) / data->ray_dir[0];
	}
	else
	{
		ray_coords[1] = data->map[1] * GRID_SIZE;
		ray_coords[0] = player->x;
		if (data->step[1] < 0)
			ray_coords[1] += GRID_SIZE;
		if (fabs(data->ray_dir[1]) > 1e-10)
			ray_coords[0] = player->x + data->ray_dir[0]
				* (ray_coords[1] - player->y) / data->ray_dir[1];
	}
}

/*
** Executes the DDA algorithm to find where the ray hits a wall.
** Incrementally steps through the grid cells until a wall is hit.
** ----------------------------------------------------------------------------
** @param game: Game state containing the map
** @param data: Ray data for traversal
** @return: 0 if a vertical wall face was hit, 1 if horizontal
*/

static int	perform_dda(t_game *game, t_ray_data *data)
{
	int		hit;
	int		side;

	hit = 0;
	side = 0;
	while (!hit)
	{
		if (data->side_dist[0] < data->side_dist[1])
		{
			data->side_dist[0] += data->delta_dist[0];
			data->map[0] += data->step[0];
			side = 0;
		}
		else
		{
			data->side_dist[1] += data->delta_dist[1];
			data->map[1] += data->step[1];
			side = 1;
		}
		hit = is_wall_or_boundary(game, data->map[0], data->map[1]);
	}
	return (side);
}

/*
** Configures the step direction and initial side distances
** for the DDA algorithm.
** These values determine how to traverse the grid during ray casting.
** ----------------------------------------------------------------------------
** @param player: Player data (position)
** @param data: Ray data to configure
*/

static void	setup_dda_steps(t_player *player, t_ray_data *data)
{
	if (data->ray_dir[0] < 0)
	{
		data->step[0] = -1;
		data->side_dist[0] = (player->x / GRID_SIZE - data->map[0])
			* data->delta_dist[0];
	}
	else
	{
		data->step[0] = 1;
		data->side_dist[0] = (data->map[0] + 1.0 - player->x / GRID_SIZE)
			* data->delta_dist[0];
	}
	if (data->ray_dir[1] < 0)
	{
		data->step[1] = -1;
		data->side_dist[1] = (player->y / GRID_SIZE - data->map[1])
			* data->delta_dist[1];
	}
	else
	{
		data->step[1] = 1;
		data->side_dist[1] = (data->map[1] + 1.0 - player->y / GRID_SIZE)
			* data->delta_dist[1];
	}
}

/*
** Initializes ray data for the DDA algorithm.
** Sets up ray direction and calculates delta distances.
** ----------------------------------------------------------------------------
** @param player: Player data (position)
** @param angles: Direction angles of the ray
** @param data: Output structure to store ray data
*/

static void	init_ray_data(t_player *player, float *angles, t_ray_data *data)
{
	int	map_x;
	int	map_y;

	data->ray_dir[0] = angles[0];
	data->ray_dir[1] = angles[1];
	map_x = (int)(player->x / GRID_SIZE);
	map_y = (int)(player->y / GRID_SIZE);
	data->map[0] = map_x;
	data->map[1] = map_y;
	if (fabs(data->ray_dir[0]) < 1e-10)
		data->delta_dist[0] = 1e6;
	else
		data->delta_dist[0] = fabs(1.0 / data->ray_dir[0]);
	if (fabs(data->ray_dir[1]) < 1e-10)
		data->delta_dist[1] = 1e6;
	else
		data->delta_dist[1] = fabs(1.0 / data->ray_dir[1]);
}

/*
** Main DDA ray casting function that combines all steps to find wall hits.
** 1. Initializes ray data
** 2. Sets up step directions
** 3. Performs DDA to find a wall
** 4. Calculates exact hit coordinates
** ----------------------------------------------------------------------------
** @param player: Player data
** @param game: Game state
** @param angles: Direction angles of the ray
** @param ray_coords: Output array to store hit coordinates
** @return: The side of the wall that was hit
*/

int	cast_ray_to_wall(t_player *player, t_game *game, float *angles,
	float *ray_coords)
{
	t_ray_data	data;
	int			side;

	init_ray_data(player, angles, &data);
	setup_dda_steps(player, &data);
	side = perform_dda(game, &data);
	calculate_wall_hit(player, &data, ray_coords, side);
	return (side);
}
