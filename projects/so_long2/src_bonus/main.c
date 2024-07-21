/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:41:40 by aautin            #+#    #+#             */
/*   Updated: 2024/01/30 02:07:13 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_scr_map_compatibility(t_game *game)
{
	int	check;

	check = SUCCESS;
	if (game->scr_size.x < (game->map_size.x * 32))
	{
		check = FAIL;
		ft_printf("Error\nThe map length is bigger than the screen length\n");
	}
	if (game->scr_size.y < (game->map_size.y * 32))
	{
		check = FAIL;
		ft_printf("Error\nThe map width is bigger than the screen width\n");
	}
	if (check == FAIL)
	{
		free_stab(game->map);
		exit(EXIT_FAILURE);
	}
}

static void	set_remaining_vars(char **map, int *mv_nb, int *c_nb, t_coords *p_i)
{
	t_coords	i;

	*c_nb = 0;
	i.y = 0;
	while (map[i.y])
	{
		i.x = 0;
		while (map[i.y][i.x])
		{
			if (map[i.y][i.x] == 'P')
				*p_i = get_coords(i.x, i.y);
			else if (map[i.y][i.x] == 'C')
				*c_nb += 1;
			i.x++;
		}
		i.y++;
	}
	*mv_nb = 0;
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc == 2)
	{
		game.map = get_map_from_file(argv[1]);
		game.map_size = get_map_size(game.map);
		game.scr_size = get_coords(SCR_LEN, SCR_WID);
		check_scr_map_compatibility(&game);
		set_remaining_vars(game.map, &(game.moves_nb),
			&(game.coins_nb), &(game.player_i));
		set_window(&game);
		set_events(&game);
		set_imgs(&game);
		put_map(&game);
		mlx_loop(game.mlxvar);
		do_free_game(&game, TRUE, TRUE, TRUE);
	}
	else
		ft_printf("Error\nWrong number of arguments\n");
	return (0);
}
