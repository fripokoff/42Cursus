/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:09:41 by kpires            #+#    #+#             */
/*   Updated: 2024/07/20 11:09:41 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_game_stats(char **map, int *mv, int *potions, t_pos *player)
{
	t_pos	i;

	*potions = 0;
	i.y = 0;
	*mv = 0;
	while (map[i.y])
	{
		i.x = 0;
		while (map[i.y][i.x])
		{
			if (map[i.y][i.x] == 'P')
				*player = get_pos(i.x, i.y);
			else if (map[i.y][i.x] == 'C')
				*potions += 1;
			i.x++;
		}
		i.y++;
	}
}

static void	check_screen(t_settings *settings)
{
	bool	check;

	check = true;
	if (settings->screen_size.x < (settings->map_size.x * SPRITES_SIZE))
	{
		check = false;
		ft_printf("Error\nThe map width is bigger than the screen width\n");
	}
	if (settings->screen_size.y < (settings->map_size.y * SPRITES_SIZE))
	{
		check = false;
		ft_printf("Error\nThe map height is bigger than the screen height\n");
	}
	if (!check)
	{
		ft_free(settings->map);
		exit(EXIT_FAILURE);
	}
}

int	main(int ac, char **av)
{
	t_settings	settings;

	if (ac == 2)
	{
		settings.map = get_map_by_file(av[1]);
		settings.map_size = get_map_size(settings.map);
		settings.screen_size = get_pos(SCREEN_WIDTH, SCREEN_HEIGHT);
		check_screen(&settings);
		init_game_stats(settings.map, &(settings.moves),
			&(settings.potions), &(settings.player));
		init_window(&settings);
		init_hooks(&settings);
		init_images(&settings);
		build_map(&settings);
		mlx_loop(settings.mlx_var);
		free_game(&settings, true, true, true);
	}
	else
		ft_printf("Error\nWrong number of arguments\n");
	return (0);
}
