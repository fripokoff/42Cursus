/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:42:16 by aautin            #+#    #+#             */
/*   Updated: 2024/01/30 04:00:14 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft_extended.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"

# ifndef SCR_LEN
#  define SCR_LEN 500
# endif
# ifndef SCR_WID
#  define SCR_WID 500
# endif
# ifndef IMGS
#  define IMGS "Error\n"
# endif

# define ESC_KEY 65307
# define A_KEY 97
# define W_KEY 119
# define S_KEY 115
# define D_KEY 100

# define TRUE 1
# define FALSE 0
# define SUCCESS 1
# define FAIL 0
# define EOT 3

/*
* @brief A two-dimensional index

* @note
* int x;	int y;
*/
typedef struct s_coords
{
	int	x;
	int	y;
}	t_coords;

/*
* @brief An image object with its name (its relative path to find it).

* @note
* t_img *obj;	char *name;
*/
typedef struct s_image
{
	t_img	*obj;
	char	*name;
}	t_image;

/*
* @brief The main typedef struct of the program (all the game needs)

* @note
* t_coords scr_size; t_coords	map_size; char **map;
* int imgs_nb; t_image *imgs; t_xvar *mlxvar;
* void *win; int moves_nb; int coins_nb;
* t_coords player_i;
*/
typedef struct s_game
{
	t_coords	scr_size;
	t_coords	map_size;
	t_coords	win_size;
	char		**map;
	int			imgs_nb;
	t_image		*imgs;
	t_xvar		*mlxvar;
	void		*win;
	int			moves_nb;
	int			coins_nb;
	t_coords	player_i;
}	t_game;

/*
* @brief Takes a file name, reads and turns its content in a char **
* (split on \\n as a separator).
* Apply a strong parsing based on the map format's rules. 

* @param mapfile Relative path of a file to read (the map).

* @return The content as a char **, exit earlier if an error happens
* (or parsing redflag).
*/
char		**get_map_from_file(char *mapfile);

/*
* @brief Check all the path finding points the map has to respect.

* @param map Content composed of 1, 0, E, C, and P.
* Respecting the so_long's subject.

* @return Nothing but free the map and exit(EXIT_FAILURE)
* the program if a test results in a redflag.
*/
void		check_map(char **map);

/*
* @brief Provides a char ** size (x and y) whose content is shape
* as a rectangle.

* @param map Content composed as a rectangle of 1, 0, E, C, and P.
* Respecting the so_long's subject.

* @return A typedef struct which contains int y (number of char *)
* and int x (number of char in the first char *).
*/
t_coords	get_map_size(char **map);

/*
* @brief Provides a t_coords whose two integers are respectively
* equal to the parameters x and y.

* @return A t_coords which contains : int x, int y.
*/
t_coords	get_coords(int x, int y);

/*
* @brief Prints "Error\\n" and a message followed by a newline.

* @param msg A string which specify the error case.

* @return Nothing : it exits with the EXIT_FAILURE status (equal to 1).
*/
void		do_msg_exit(char *msg);

/*
* @brief Sets the game->mlxvar and game->win variables. 

* @param game The main typedef struct of this program.

* @return Nothing but it might exit earlier (by the do_msg_exit function)
* if an sys-error happens.
*/
void		set_window(t_game *game);

/*
* @brief Allocates game->imgs and set a name (char *) and an obj (t_img)
* for each element of the game->imgs array

* @param game The main typedef struct of this program.

* @return Nothing but it might exit earlier (by the do_msg_exit function)
* if an sys-error happens.
*/
void		set_imgs(t_game *game);

/*
* @brief Used to free the content of t_game typedef before to left the program.

* @param freemlx Flag conditionning the free and/or destruction of mlxvar
* and win.
* @param freemap Flag conditionning the free and/or destruction of map.
* @param freeimgs Flag conditionning the free and/or destruction of imgs.
*/
void		do_free_game(t_game *game, char freemlx,
				char freeimgs, char freemap);

/*
* @brief Browse into the imgs array and select the img containing
* the keyword in its name.

* @param game The main typedef struct of this program.
* @param keyword A meaningfull part of the relative path of an img.

* @returns The actual img->obj, but free the game structure
* and do_msg_and_exit if no picture has been found.
*/
void		*get_img_obj(t_game *game, char *keyword);

/*
* @brief Uses the imgs created and browse in a map to print every char
* as its img equivalent in the game->window. 

* @param game The main typedef struct of this program.
*/
void		put_map(t_game *game);

/*
* @brief Set the hooks of the game->mlx which causes something in
* the program (as a keypress or a buttonclicked).

* @param game The main typedef struct of this program.

* @note AWSD as gameplay events. Top-right window's corner cross and ESC_key
* as closing program buttons.
*/
void		set_events(t_game *game);

/*
* @brief If a key_event is trigger, this function verifies if this event
* can happens depending on the player position (can he moves on this way ?).

* @param move The double-dimension direction the player try to go on.
* @param game The main typedef struct of this program.
*/
void		do_try_move(t_coords move, t_game *game);

/*
* @brief Print the game->moves_nb in the right-down corner. The number printed
* is made of images putting on the window.

* @param game The main typedef struct of this program.
* @param moves_nb The number of player moves.
* @param x_pad The padding between the window's right edge and the moves_nb.
*/
void		put_move(t_game *game, int moves_nb, int x_pad);

/*
* @brief A bonus function.
*/
void		try_move_ghosts(t_game *game);

#endif