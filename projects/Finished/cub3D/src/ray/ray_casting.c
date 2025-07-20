/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:22:35 by kpires            #+#    #+#             */
/*   Updated: 2025/07/12 17:56:32 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
** Retrieves a pixel color from a texture at given coordinates.
** Handles boundary checking to prevent out-of-bounds access.
** ----------------------------------------------------------------------------
** @param texture: The texture to get the pixel from
** @param x: X coordinate in the texture
** @param y: Y coordinate in the texture
** @return: The color value at the specified coordinates
*/

static int	get_texture_pixel(t_texture *texture, int x, int y)
{
	char	*pixel;

	if (x < 0 || x >= texture->width || y < 0 || y >= texture->height)
		return (0);
	pixel = texture->addr + (y * texture->line_length
			+ x * (texture->bits_per_pixel / 8));
	return (*(unsigned int *)pixel);
}

/*
** Renders a textured vertical stripe of a wall.
** Maps texture coordinates to screen coordinates and applies texture pixels.
** ----------------------------------------------------------------------------
** @param game: The game state containing texture information
** @param wall: Wall column data including texture ID and dimensions
*/

static void	render_textured_wall_column(t_game *game, t_wall_column *wall)
{
	float	step;
	float	tex_pos;
	int		tex_y;
	int		y;
	int		color;

	step = 1.0 * game->map.textures[wall->tex_id].height / wall->wall_height;
	tex_pos = (wall->draw_start - HEIGHT / 2 + wall->wall_height / 2) * step;
	y = wall->draw_start;
	while (y <= wall->draw_end)
	{
		tex_y = (int)tex_pos & (game->map.textures[wall->tex_id].height - 1);
		tex_pos += step;
		color = get_texture_pixel(&game->map.textures[wall->tex_id],
				(int)(wall->wall_x * game->map.textures[wall->tex_id].width),
				tex_y);
		put_pixel(wall->screen_x, y, color, game);
		y++;
	}
}

/*
** Determines which texture to use based on the ray's impact coordinates.
** Calculates the exact x-coordinate within the texture for proper mapping.
** ----------------------------------------------------------------------------
** @param ray_coords: The coordinates where the ray hit the wall
** @param angles: The direction angles of the ray
** @param hit_vertical: Whether the ray hit a vertical wall face
** @param wall: Output structure to store texture information
*/

static void	select_wall_texture(float ray_coords[2], float angles[2],
	int hit_vertical, t_wall_column *wall)
{
	if (hit_vertical)
	{
		wall->wall_x = fmod(ray_coords[1], GRID_SIZE) / GRID_SIZE;
		wall->tex_id = TEX_WEST;
		if (angles[0] > 0)
			wall->tex_id = TEX_EAST;
		else
			wall->wall_x = 1.0 - wall->wall_x;
	}
	else
	{
		wall->wall_x = fmod(ray_coords[0], GRID_SIZE) / GRID_SIZE;
		if (angles[1] > 0)
		{
			wall->tex_id = TEX_SOUTH;
			wall->wall_x = 1.0 - wall->wall_x;
		}
		else
			wall->tex_id = TEX_NORTH;
	}
}

/*
** Calculates corrected distance to prevent fish-eye effect.
** Applies the cosine correction based on the angle,
** between ray and player direction.
** ----------------------------------------------------------------------------
** @param player: Player data (position, direction)
** @param ray: Coordinates of the ray hit
** @return: The corrected distance value
*/

static float	fixed_dist(t_player *player, float ray[2])
{
	float	delta_x;
	float	delta_y;
	float	angle_diff;
	float	dist;

	delta_x = ray[0] - player->x;
	delta_y = ray[1] - player->y;
	angle_diff = atan2(delta_y, delta_x) - player->angle;
	while (angle_diff < -PI)
		angle_diff += 2 * PI;
	while (angle_diff > PI)
		angle_diff -= 2 * PI;
	dist = sqrt(delta_x * delta_x + delta_y * delta_y) * cos(angle_diff);
	return (dist);
}

/*
** Main ray casting function for a single vertical column of the screen.
** Casts a ray, calculates wall hit, selects texture, and renders the wall.
** ----------------------------------------------------------------------------
** @param player: Player data (position, direction)
** @param game: Game state including map and textures
** @param start_x: Angle of the ray to cast
** @param i: Screen column to render
*/

void	render_wall_column(t_player *player, t_game *game, float start_x, int i)
{
	float			angles[2];
	float			ray_coords[2];
	float			dist;
	t_wall_column	wall;
	int				hit_ver;

	angles[0] = cos(start_x);
	angles[1] = sin(start_x);
	cast_ray_to_wall(player, game, angles, ray_coords);
	dist = fixed_dist(player, ray_coords);
	hit_ver = fabs(fmod(ray_coords[0], GRID_SIZE)) < 0.0001f;
	if (!hit_ver)
		hit_ver = fabs(fmod(ray_coords[0], GRID_SIZE) - GRID_SIZE) < 0.0001f;
	wall.screen_x = i;
	select_wall_texture(ray_coords, angles,
		hit_ver, &wall);
	wall.wall_height = (GRID_SIZE * HEIGHT) / dist;
	wall.draw_start = -wall.wall_height / 2 + HEIGHT / 2;
	if (wall.draw_start < 0)
		wall.draw_start = 0;
	wall.draw_end = wall.wall_height / 2 + HEIGHT / 2;
	if (wall.draw_end >= HEIGHT)
		wall.draw_end = HEIGHT - 1;
	render_textured_wall_column(game, &wall);
}
