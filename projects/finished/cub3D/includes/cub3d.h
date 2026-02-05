/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:43:53 by kpires            #+#    #+#             */
/*   Updated: 2025/07/15 20:07:46 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define PI 3.14159265359

# include "./mlx/mlx.h"
# include "./mlx/mlx_int.h"
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>

# define ALLOC	"Allocation memory"
# define USAGE	"Usage -> ./cub3d [path/to/map.cub]"
# define NOID	"No ID content is provided"
# define CEIL	"Invalid ceiling RGB"
# define FLOOR	"Invalid floor RGB"

typedef enum e_game_settings
{
	WIDTH = 1280,
	HEIGHT = 720,
	GRID_SIZE = 64,
	PLAYER_SPEED = 5,
	PLAYER_ROT_SPEED = 4,
	FOV = 60,
	FOCUS_OUT = 10
}	t_game_settings;

typedef enum e_texture_id
{
	TEX_NORTH = 0,
	TEX_SOUTH = 1,
	TEX_EAST = 2,
	TEX_WEST = 3,
	TEX_COUNT = 4
}	t_texture_id;

typedef enum e_keyboard
{
	W = 119,
	A = 97,
	S = 115,
	D = 100,
	LEFT = 65361,
	RIGHT = 65363,
	ESC = 65307
}	t_keyboard;

typedef enum e_moves
{
	MOVE_UP = 0,
	MOVE_DOWN = 1,
	MOVE_LEFT = 2,
	MOVE_RIGHT = 3,
	ROTATE_LEFT = 4,
	ROTATE_RIGHT = 5,
	TOTAL_MOVES = 6
}	t_moves;

typedef struct s_player
{
	float			x;
	float			y;
	float			angle;
	int				moves[TOTAL_MOVES];
}	t_player;

typedef struct s_ray_data
{
	float	ray_dir[2];
	float	delta_dist[2];
	float	side_dist[2];
	int		map[2];
	int		step[2];
}	t_ray_data;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	char	*path;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_texture;

typedef struct s_map
{
	int			width;
	int			height;
	char		**map;
	char		**arr_start;
	int			floor_color[3];
	int			fill_elem;
	int			ceiling_color[3];
	t_texture	textures[TEX_COUNT];
}	t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	t_player	player;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
	t_map		map;
}	t_game;

typedef struct s_wall_column
{
	int		screen_x;
	double	wall_x;
	int		tex_id;
	float	wall_height;
	int		draw_start;
	int		draw_end;
}	t_wall_column;

/* INIT */
int		check_fov_and_init(t_game *game);

/* PLAYER & MOVEMENTS */
int		key_release(int keycode, t_game *game);
int		key_press(int keycode, t_game *game);
void	move_player(t_player *player);

/* RENDER */
int		render_game_frame(t_game *game);

/* RAY */
void	render_wall_column(t_player *player, t_game *game,
			float start_x, int i);

/* DDA*/
int		cast_ray_to_wall(t_player *player, t_game *game, float *angles,
			float *ray_coords);
int		is_wall_or_boundary(t_game *game, int map_x, int map_y);

/* MLX UTILS */
int		exit_game(t_game *game, size_t is_error);
int		setup_hooks(t_game *game);
void	put_pixel(int x, int y, int color, t_game *game);

/* CLEAN */
void	free_map(char **map);
void	clear_image(t_game *game);

/* PARSING */
char	**str2arr(char *str, const char *sep);
bool	valid_id(char **arr, int line, t_game *game, int y);
bool	is_error(char *file, t_game *game);
char	*get_buff(int fd, char *file);
int		open_file(const char *path);
bool	is_wall(char *str, int size);
size_t	ret_map_line(char **arr);
size_t	ret_map_index(char *file);
bool	check_valid_line(char *str);
int		parsing(char **av, t_game *game);
int		fill_colors(t_game *game, char **tab);
bool	fill_textures(t_game *game, char **tab);
bool	is_double_id(char **arr, int line, char *id, int index);
bool	gest_space(char **map, int y);
void	ft_perror(const char *msg, const char *file);
bool	validate_and_fill_color(int *dest, char *color_str);

/* LIB */
void	*ft_memset(void *p, int i, size_t len);
void	fd_putstr(const char *str, int fd);
size_t	ft_strlen(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_strdup(char *src, char **dest);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *str, int c);
#endif
