/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:11:09 by kpires            #+#    #+#             */
/*   Updated: 2024/07/20 11:11:09 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "fcntl.h"
# include "libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include "stdio.h"
# include "stdlib.h"
# include "unistd.h"
# include <stdbool.h>

# ifndef IMGS
#  define IMGS "Error\n"
# endif

# ifndef SCREEN_WIDTH
#  define SCREEN_WIDTH 500
# endif

# ifndef SCREEN_HEIGHT
#  define SCREEN_HEIGHT 500
# endif

# define GAME_NAME "Wizard Adventure"
# define SPRITES_SIZE 32

# define EOT 3
# define KEYS_EVENT 2
# define EXIT_EVENT 17

# define EXIT_GAME 65307
# define LEFT 97
# define UP 119
# define DOWN 115
# define RIGHT 100

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;	

typedef struct s_image
{
	t_img	*obj;
	char	*name;
}	t_image;	

typedef struct s_settings
{
	t_pos	map_size;
	t_pos	screen_size;
	char	**map;
	int		moves;
	int		potions;
	t_pos	player;
	t_xvar	*mlx_var;
	void	*window;
	int		imgs_count;
	t_pos	exit_pos;
	t_image	*imgs;
}	t_settings;

char	**get_map_by_file(char *file_name);
void	exit_error(char *msg);
t_pos	get_pos(int x, int y);
t_pos	get_map_size(char **map);
void	check_map(char **map);
void	init_window(t_settings *settings);
void	init_hooks(t_settings *settings);
void	try_move_player(t_pos pos, t_settings *settings);
void	free_game(t_settings *settings, bool f_mlx, bool f_imgs, bool f_map);
void	*get_img_obj(t_settings *settings, char *keyword);
void	init_images(t_settings *settings);
void	build_map(t_settings *game);
#endif