/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:27:26 by kpires            #+#    #+#             */
/*   Updated: 2025/07/15 16:43:40 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
** Finds the player's starting position and the map dimensions.
** Scans the map grid to locate the player character ('N', 'S', 'E', 'W').
** Updates player coordinates and calculates the map width and height.
** ----------------------------------------------------------------------------
** @param game: The game state containing the map and player info
** @param i: Initial row index (usually 0)
** @param j: Initial column index (usually 0)
** @param max: Tracks the maximum width found in the map
*/

static void	init_map_player(t_game *game, int i, int j, int max)
{
	char	map_cell;

	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			map_cell = game->map.map[i][j];
			if (map_cell == 'N' || map_cell == 'S'
				|| map_cell == 'W' || map_cell == 'E')
			{
				game->player.x = j;
				game->player.y = i;
			}
			if (max == 0)
				max = j;
			else if (j > max)
				max = j;
			game->map.width = max;
			j++;
		}
		i++;
	}
	game->map.height = i;
	return ;
}

/*
** Initializes the player's state based on the starting position in the map.
** Sets the initial angle based on the direction character (N, S, E, W).
** Converts map grid coordinates to actual pixel coordinates.
** Initializes all movement state flags to false.
** ----------------------------------------------------------------------------
** @param game: The game state containing player and map information
*/

static void	init_player(t_game *game)
{
	int	player_x;
	int	player_y;

	init_map_player(game, 0, 0, 0);
	player_x = game->player.x;
	player_y = game->player.y;
	if (game->map.map[player_y][player_x] == 'N')
		game->player.angle = 3 * PI / 2;
	else if (game->map.map[player_y][player_x] == 'S')
		game->player.angle = PI / 2;
	else if (game->map.map[player_y][player_x] == 'E')
		game->player.angle = 0;
	else if (game->map.map[player_y][player_x] == 'W')
		game->player.angle = PI;
	game->player.x = player_x * GRID_SIZE + GRID_SIZE / 2;
	game->player.y = player_y * GRID_SIZE + GRID_SIZE / 2;
	game->player.moves[MOVE_UP] = 0;
	game->player.moves[MOVE_DOWN] = 0;
	game->player.moves[MOVE_LEFT] = 0;
	game->player.moves[MOVE_RIGHT] = 0;
	game->player.moves[ROTATE_LEFT] = 0;
	game->player.moves[ROTATE_RIGHT] = 0;
}

/*
** Loads a texture from an XPM file into the MLX image system.
** ----------------------------------------------------------------------------
** @param game: The game state containing MLX pointers
** @param texture: Pointer to the texture structure to fill
** @param path: Path to the XPM file to load
** @return: 0 on success, 1 on failure
*/

static int	load_texture(t_game *game, t_texture *texture)
{
	if (!texture->path)
		return (1);
	texture->img = mlx_xpm_file_to_image(game->mlx, texture->path,
			&texture->width, &texture->height);
	if (!texture->img)
		return (1);
	if (texture->width > 1024 || texture->height > 1024)
	{
		ft_perror("Texture too large", NULL);
		mlx_destroy_image(game->mlx, texture->img);
		texture->img = NULL;
		return (1);
	}
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel,
			&texture->line_length, &texture->endian);
	return (0);
}

static int	init_mlx_components(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (ft_perror("Mlx initialization failed", NULL), 1);
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Cub3D");
	if (!game->win)
		return (ft_perror("Window creation failed", NULL), 1);
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img)
		return (ft_perror("Image creation failed", NULL), 1);
	game->data = mlx_get_data_addr(game->img, &game->bpp,
			&game->size_line, &game->endian);
	if (!game->data)
		return (ft_perror("Getting image data failed", NULL), 1);
	return (0);
}

/*
** Validates the field of view (FOV) and initializes the game environment.
** This function performs the following steps:
**  - Checks that the FOV is between 45 and 90 degrees for proper rendering.
**  - Ensures the resolution does not exceed 4096x2160.
**  - Initializes MLX components.
**  - Verifies that the map is loaded correctly.
**  - Loads all required wall textures.
**  - Initializes the player's position and state on the map.
**  - Displays the initial image in the window.
**  - Prints a success message if everything is initialized correctly.
**
** @param game: Structure containing the game state to initialize.
** @return: 0 on success, 1 on failure.
*/

int	check_fov_and_init(t_game *game)
{
	if (FOV > 90 || FOV < 45)
		return (ft_perror("FOV must be between 45 and 90 degrees", NULL),
			1);
	if (WIDTH > 4096 || HEIGHT > 2160)
		return (ft_perror("WIDTH/HEIGHT too big max is 4096x2160", NULL), 1);
	if (init_mlx_components(game))
		return (1);
	if (!game->map.map)
		return (ft_perror("Map initialization failed", NULL), 1);
	if (load_texture(game, &game->map.textures[TEX_NORTH])
		|| load_texture(game, &game->map.textures[TEX_SOUTH])
		|| load_texture(game, &game->map.textures[TEX_EAST])
		|| load_texture(game, &game->map.textures[TEX_WEST]))
	{
		return (ft_perror("Loading textures failed", NULL), 1);
	}
	init_player(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	fd_putstr("Game initialized successfully\n", 1);
	return (0);
}
